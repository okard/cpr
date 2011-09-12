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
    
    String Handling
*/

#include <cpr/string.h>

#include <cpr/mem.h>

/**
* Create new string
*/
cpr_string* cpr_string_new()
{
    cpr_string* str = cpr_alloc_null(sizeof(cpr_string));
    //allocate 1024 bytes as buffer 
    str->str = cpr_alloc_null(1024);
    str->mem = 1024;
    return str;
}

/**
* Delete string
*/
void cpr_string_free(cpr_string* str)
{
    cpr_free(str->str);
    str->str = 0;
    cpr_free(str);
}