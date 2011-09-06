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
    Virtual File System Handler
*/
#include <cpr/vfs.h>


//forward declaration
static cpr_vfs_dir* vfs_virt_dir_open(cpr_vfs_handle*, const char*);

//forward declaration
static cpr_vfs_file* vfs_virt_file_open(cpr_vfs_handle*, const char*);


/**
* Virtual File System Handler
*/
static cpr_vfs_handler _vfs_virt_handler = {
    .dir_open = &vfs_virt_dir_open,
    .file_open = &vfs_virt_file_open
    
};

/**
* Virtual File System Handle
*/
static cpr_vfs_handle _vfs_virt_handle = {
    .handler = &_vfs_virt_handler,
    .type = CPR_VFS_TYPE_HANDLER,
    .ctx = 0
};

/**
* a virtual file system handler
*/
cpr_vfs_handle* cpr_vfs_virt_handler()
{
    return &_vfs_virt_handle;
}

//TODO _vfs_virt_file
//TODO _vfs_virt_dir
//rbtree??? hashmap

/**
* open dir virtual file system
*/
static cpr_vfs_dir* vfs_virt_dir_open(cpr_vfs_handle* handle, const char* path)
{
    return 0;
}

/**
* open file virtual file system
*/
static cpr_vfs_file* vfs_virt_file_open(cpr_vfs_handle* handle, const char* path)
{
    return 0;
}