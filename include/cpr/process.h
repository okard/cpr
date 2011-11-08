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
    
    Process Functions
*/
#pragma once
#ifndef __LIBCPR_PROCESS_H__
#define __LIBCPR_PROCESS_H__

#include <cpr/error.h>

/**
* \defgroup Process Process Handling
* @{
*/

/// Platform Specific Process Structure
typedef struct os_process os_process;

/**
* Create a new process object
*/
os_process* os_process_new();

/**
* Delete process object
*/
void os_process_delete(os_process* proc);

/**
* Start a process
*/
void os_process_start(os_process* proc, const char* path, const char* args[]);
//TODO arguments?
//TODO env?

//Flags for stdin/out/err mapping?
//Write to process stdin
//Event Callbacks

/**
* Set error handler
*/
void os_process_set_error_handler(os_process* proc, cpr_error_handler handler, void* ctx);

/**
* Wait until child process finished
*/
void os_process_wait(os_process* proc);


/** }@ */

#endif