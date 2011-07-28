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
#include <cpr/os/dir.h>

#include <cpr/mem.h>


//temp debug
#include <stdio.h> 

#include <assert.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>


/**
* posix dir structure
*/
typedef struct os_dir
{
    DIR* dir;
} os_dir;

/**
* posix dir entry structure
*/
typedef struct os_dir_entry
{
    struct dirent* entry;
} os_dir_entry;


/**
* Create new dir object
*/
os_dir* os_dir_new()
{
    os_dir* dir = cpr_alloc_null(sizeof(os_dir));
    //TODO Initialize Structure here
    return dir;
}

/**
* Delete dir object
*/
void os_dir_delete(os_dir* dir)
{
    cpr_free(dir);
}

/**
* Open a dir
*/
bool os_dir_open(os_dir* dir, char* path)
{
    return false;
}

/**
* Get next entry
*/
bool os_dir_next(os_dir* dir, os_dir_entry* entry)
{
    assert(dir != NULL);
    assert(entry != NULL);
    
    return false;
}

/**
* Get file size
*/
size_t os_get_filesize(char* path)
{
    struct stat st;
    int result = stat(path, &st);
    if(result == -1)
    {
        fprintf(stderr, "Error getting filesize of %s", path);
        return -1;
    }
    
    return st.st_size;
}

/**
* Is path a directory
*/
bool os_is_dir(char* path)
{
    DIR* dir = opendir(path);
    if(dir == NULL)
        return false;
    
    closedir(dir);
    return true;
}