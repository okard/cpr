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
    
    string class
*/
#pragma once
#ifndef __LIBCPR_STRING_H__
#define __LIBCPR_STRING_H__

#include <stddef.h>

/**
* string encoding
*/
typedef enum cpr_encoding
{
    CPR_ENCODING_ASCII,
    CPR_ENCODING_UTF8,
    CPR_ENCODING_UTF16,
    CPR_ENCODING_UTF32
} cpr_encoding;

/**
* string structure
*/
typedef struct cpr_string
{
    /// Encoding of string
    cpr_encoding encoding;
    
    /// Pointer to string content
    void* str;
    
    /// size of string
    size_t length;
    
    /// size of allocated memory
    size_t mem;
} cpr_string;


/**
* Create new string
*/
cpr_string* cpr_string_new();

/**
* Delete string
*/
void cpr_string_free(cpr_string* str);

//TODO append
//TODO set
//TODO length
//TODO shrink
//TODO space?
//TODO duplicate/copy


#endif /* __LIBCPR_STRING_H__ */