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
    
    Error Functions
*/
#pragma once
#ifndef __LIBCPR_ERROR_H__
#define __LIBCPR_ERROR_H__

/**
* \defgroup Error Error Handling
* @{
*/

/**
* Default error ids
*/
enum cpr_error_id
{
    CPR_ERROR_NO_ERROR = 0,
    CPR_ERROR_UNKOWN = 1,
    
    //Process Module Errors
    OS_ERROR_PROCESS,
    
    CPR_ERROR_MAXID
};

/**
* Error Structure
*/
typedef struct
{
    int id;
    char* msg;
    void* ctx;
} cpr_error;

/**
* CPR Error Callback
*/
typedef void(*cpr_error_handler)(cpr_error* err);


/**
* Create new error object
*/
cpr_error* cpr_error_new(int id, const char* const msg, void* ctx);

/**
* Create new error object by id
*/
cpr_error* cpr_error_new_byid(enum cpr_error_id id, const char* const msg, void* ctx);

/**
* Freeing Error
*/
void cpr_error_free(cpr_error* err);

/** }@ */

#endif
