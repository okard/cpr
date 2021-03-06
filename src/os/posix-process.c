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
#include <cpr/process.h>

#include <cpr/mem.h>
#include <cpr/error.h>

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
* Posix Process Structure
*/
typedef struct os_process
{
     /// Process ID
     pid_t pid;
     //process status?
     int result;
     
     /// Error Handler Callback
     cpr_error_handler error_handler;
     /// Error Context
     void* error_context;
} os_process;




/**
* Create a new process object
*/
os_process* os_process_new()
{
    os_process* proc = cpr_alloc_null(sizeof(os_process));
    //TODO Initialize Structure here
    proc->error_handler = NULL;
    return proc;
}

/**
* Delete process object
*/
void os_process_delete(os_process* proc)
{
    cpr_free(proc);
}

/**
* Set error handler
*/
void os_process_set_error_handler(os_process* proc, cpr_error_handler handler, void* ctx)
{
    proc->error_context = ctx;
    proc->error_handler = handler;
}

/**
* Fire a error
*/
static void os_process_error(os_process* proc, int id, const char* const msg)
{
    if(proc->error_handler != NULL)
    {
        cpr_error* err = cpr_error_new(id, msg, proc->error_context);
        (*proc->error_handler)(err);
        
        //if user accidently delete err
        if(err != 0)
            cpr_error_free(err);
    }   
}

/**
* Start a process
*/
void os_process_start(os_process* proc, const char* path, const char* args[])
{
    //fork (vfork here?), posix_spawn
    proc->pid = fork();
    
    if(proc->pid < 0)
    {
        //Error
        os_process_error(proc, OS_ERROR_PROCESS, "Error calling fork");
        return;
    }
    
    if(proc->pid > 0)
    {
        //Parent
        return;
    }
    
    //save child pid
    proc->pid = getpid();
    
    //Bind input and output to stdin and stdout?
    //Child Process here
    //int execv (__const char *__path, char *__const __argv[])
    //»char * const*« expected but »const char **«

    int result = execv(path, args);
    
    //should never go here?
    if(result == -1)
    {
        //save error message first
        char* msg = strerror(errno);
        os_process_error(proc, OS_ERROR_PROCESS, msg);
        //os_free(msg);
        
        os_process_error(proc, OS_ERROR_PROCESS, "Error executing execl");
    }
    
    //Exit forked process?
    _exit(0); 
}


/**
* Wait until child process finished
*/
void os_process_wait(os_process* proc)
{
     int childExitStatus = 0;
     pid_t r = waitpid( proc->pid, &childExitStatus, 0);   
     
     if(WIFEXITED(childExitStatus))
     {
         //Normally exited
         proc->result = WEXITSTATUS(childExitStatus);
     }
}