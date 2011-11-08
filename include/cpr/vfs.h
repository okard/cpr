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
    
    VFS - Virtual File System
*/
#pragma once
#ifndef __LIBCPR_VFS_H__
#define __LIBCPR_VFS_H__

/**
* \defgroup VFS Virtual File System
* @{
*/

//forward declaration
typedef struct cpr_vfs_handler;

/**
* types of vfs handle
*/
typedef enum cpr_vfs_handle_type
{
    CPR_VFS_TYPE_HANDLER = 0,
    CPR_VFS_TYPE_DIRECTORY = 1,
    CPR_VFS_TYPE_FILE = 2,
    CPR_VFS_TYPE_LINK = 3
} cpr_vfs_handle_type;

/**
* a file system handle
* handler, dir or file
*/
typedef struct
{
    /// Provider
    struct cpr_vfs_handler* handler;
    
    /// type 
    cpr_vfs_handle_type type;
    
    /// Context
    void* ctx;
    
} cpr_vfs_handle;

/**
* a vfs directory
*/
typedef cpr_vfs_handle cpr_vfs_dir;

/**
* a vfs file
*/
typedef cpr_vfs_handle cpr_vfs_file;


//file open flags read, readwrite, exclusive, append, create


/**
* a vfs handler
*/
typedef struct cpr_vfs_handler
{
    ///open a dir from cpr_vfs_handle
    cpr_vfs_dir* (*dir_open)(cpr_vfs_handle*, const char*);
    
    ///open a file from cpr_vfs_handle
    cpr_vfs_file* (*file_open)(cpr_vfs_handle*, const char*);
    
    
    //get name
    //get path
    //get mtime, atime, ...
    //get size
    //get position
    
    //close
    //write
    //read
    //iteration
    //mount
    
    //os_path get_path;
    //size_t (*content_size)(cpr_vfs_handle_type);
} cpr_vfs_handler;


/**
* Open a dir
*/
cpr_vfs_dir* cpr_vfs_dir_open(cpr_vfs_handle* handle, const char* path);

/**
* Open a file
*/
cpr_vfs_file* cpr_vfs_file_open(cpr_vfs_handle* handle, const char* path);

/**
* a virtual file system handler
*/
cpr_vfs_handle* cpr_vfs_virt_handler();

/**
* get normal file system handler
* usage: cpr_vfs_dir_open(cpr_vfs_fs_handler(), "/foo/foo.txt");
*/
cpr_vfs_handle* cpr_vfs_fs_handler();


//mount

//check valid handle? size of memory? 
//copy api for handles?


/** }@ */

#endif
