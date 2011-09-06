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
    
    Directory Functions
*/
#ifndef __LIBCPR_DIR_H__
#define __LIBCPR_DIR_H__

#include <stddef.h>
#include <stdbool.h>

/**
* \deprecated
* \defgroup Dir Directory Handling
* @{
*/

typedef struct os_dir os_dir;
typedef struct os_dir_entry os_dir_entry;

/**
* Create new dir object
*/
os_dir* os_dir_new();

/**
* Delete dir object
*/
void os_dir_delete(os_dir* dir);

/**
* Open a dir
*/
bool os_dir_open(os_dir* dir, char* path);

//dir_close

/**
* Get next entry
*/
bool os_dir_next(os_dir* dir, os_dir_entry* entry);


//TODO lesser memory consume new/delete/clean for os_dir_entry

/**
* Get file size
*/
size_t os_get_filesize(char* path);

/**
* Is path a directory
*/
bool os_is_dir(char* path);


//char* os_get_executabledir();
// char *getcwd(char *buf, size_t size);
// int chdir(const char *path);

/** }@ */

#endif