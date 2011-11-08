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
    
    Path Functions
*/
#pragma once
#ifndef __LIBCPR_PATH_H__
#define __LIBCPR_PATH_H__

#include <stdbool.h>

/**
* \defgroup Path Path Handling
* @{
*/

/// os path structure
typedef struct os_path os_path;

/**
* Create new path object
*/
os_path* os_path_new();

/**
* Delete path object
*/
void os_path_delete(os_path* path);

/**
* create new path from a given string
*/
//os_path* os_path_new_from(const char* str);


//void os_path_set(os_path* path, const char* pathstr)
//void os_path_join(os_path* path, const char* pathstr);
//bool os_path_is_file(os_path* path);
//bool os_path_is_dir(os_path* path);
//char* os_path_full(os_path* path);
//char* os_path_basename(os_path* path);
//char* os_path_extname(os_path* path);
//char* os_path_drive(os_path* path); // '/' on posix, 'letter:' on windows
//char* os_path
//os_path_relative
//os_path_absolute
//os_path_is_relative
//os_path_is_absolute


/**
* Get path seperator
*/
char os_path_seperator();

/** }@ */

#endif 