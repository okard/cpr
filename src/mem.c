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
    
    Memory Functions
*/
#include <cpr/mem.h>

#include <stdlib.h>
#include <string.h>

//TODO save size of allocated memory? magic bytes for safety?

/**
* Allocate Memory
*/
void* cpr_alloc(size_t size)
{
   return malloc(size); 
}

/**
* Allocate memory and set it to null
*/
void* cpr_alloc_null(size_t size)
{
    void* mem = cpr_alloc(size);
    memset(mem, 0, size);
    return mem;
}

/**
* Reallocate memory
*/
void* cpr_realloc(void* ptr, size_t size)
{
    return realloc(ptr, size);
}

/**
* Freeing memory
*/
void cpr_free(void* mem)
{
    free(mem);
    mem = 0;
}
