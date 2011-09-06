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
#include <cpr/path.h>

#include <cpr/mem.h>

//utf8 path?


/// Posix Path Seperator
static const char PATHSEP = '/';

/**
* posix dir structure
*/
typedef struct os_path
{
  char* pathstr;
  size_t size;
  size_t mem;
  
  //include os_dir and os_file here?
} os_path;


/**
* Create new path object
*/
os_path* os_path_new()
{
    os_path* path = cpr_alloc_null(sizeof(os_path));
    static const size_t default_memsize = 1024;
    path->pathstr = cpr_alloc_null(default_memsize);
    path->mem = default_memsize;
    path->size = 0;
    return path;
}

/**
* Delete path object
*/
void os_path_delete(os_path* path)
{
    cpr_free(path->pathstr);
    cpr_free(path);
}

/**
* Get path seperator
*/
char os_path_seperator()
{
    return PATHSEP;
}