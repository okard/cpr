/*
    C Portable Runtime
    
    Copyright (c) 2011  okard

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
    
    POSIX VFS
*/
#include <cpr/vfs.h>

#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

#include <cpr/mem.h>
//#include <cpr/path.h>

//forward declaration
static cpr_vfs_dir* vfs_fs_dir_open(cpr_vfs_handle*, const char*);

//forward declaration
static cpr_vfs_file* vfs_fs_file_open(cpr_vfs_handle*, const char*);

/**
* Posix File System Handler
*/
static cpr_vfs_handler _vfs_fs_handler = {
    .dir_open = &vfs_fs_dir_open,
    .file_open = &vfs_fs_file_open
    
};

/**
* Posix File System Handle
*/
static cpr_vfs_handle _vfs_fs_handle = {
    .handler = &_vfs_fs_handler,
    .type = CPR_VFS_TYPE_HANDLER,
    .ctx = 0
};

/**
* a posix file system handler
*/
cpr_vfs_handle* cpr_vfs_fs_handler()
{
    return &_vfs_fs_handle;
}

/**
* posix dir structure 
*/
typedef struct _vfs_fs_dir
{
    DIR* dir;
} _vfs_fs_dir;

/**
* posix file structure
*/
typedef struct _vfs_fs_file
{
    FILE* file;
} _vfs_fs_file;

/**
* Helper to create a platform structure
*/
static cpr_vfs_dir* cpr_vfs_dir_new(cpr_vfs_handler* handler)
{
    //create dir structure
    cpr_vfs_dir* vdir = cpr_alloc_null(sizeof(cpr_vfs_dir) + sizeof(_vfs_fs_dir));
    vdir->type = CPR_VFS_TYPE_DIRECTORY;
    vdir->handler = handler;
    //platform struct is directly behind vdir
    vdir->ctx = vdir + sizeof(cpr_vfs_dir); 
 
    return vdir;
}

/**
* Helper to create a platform structure
*/
static cpr_vfs_file* cpr_vfs_file_new(cpr_vfs_handler* handler)
{
    //create dir structure
    cpr_vfs_file* vfile = cpr_alloc_null(sizeof(cpr_vfs_file) + sizeof(_vfs_fs_file));
    vfile->type = CPR_VFS_TYPE_FILE;
    vfile->handler = handler;
    //platform struct is directly behind vdir
    vfile->ctx = vfile + sizeof(cpr_vfs_file); 
 
    return vfile;
}


/**
* open dir posix file system
*/
static cpr_vfs_dir* vfs_fs_dir_open(cpr_vfs_handle* handle, const char* path)
{
    //can only open dir from handler or directory
    assert(handle->type == CPR_VFS_TYPE_HANDLER || handle->type == CPR_VFS_TYPE_DIRECTORY);
    //TODO handler should be posix file system handler ???
    assert(handle->handler == cpr_vfs_fs_handler()->handler);
    
    //Create new handler
    cpr_vfs_dir* vdir = cpr_vfs_dir_new(handle->handler);
    _vfs_fs_dir* dir = vdir->ctx;
   
   //if(is posix handler before?)
   // path = path + handle->handler->get_path(handle);
   
   //attach
   dir->dir = opendir(path);
   
   return vdir;
}

/**
* open file posix file system
*/
static cpr_vfs_file* vfs_fs_file_open(cpr_vfs_handle* handle, const char* path)
{
   //can only open dir from handler or directory
   assert(handle->type == CPR_VFS_TYPE_HANDLER || handle->type == CPR_VFS_TYPE_DIRECTORY); 
   //TODO handler should be posix file system handler ???
   assert(handle->handler == cpr_vfs_fs_handler()->handler);
   
   cpr_vfs_file* vfile = cpr_vfs_file_new(handle->handler);
   _vfs_fs_file* file = vfile->ctx;
   
   //TODO fix open mode
   //int open(const char *path, int oflag, ...);
   file->file = fopen(path, "r");
   
   return vfile;
}