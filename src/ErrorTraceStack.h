#ifndef _CERRORSTACK_ERROR_TRACE_STACK_H_
#define _CERRORSTACK_ERROR_TRACE_STACK_H_

#include <stdbool.h>

typedef struct ErrorNode
{
   //----- Boilerplate stack variables ---------
   ErrorNode* lastNode;
   //----- Node attributes ---------
   char* callingFileName;// the name of the file from which the function has been called
   int callingLineNb;// the line at which the call has been performed
   char* callingLineContent;// the content of the line that was called
   //TODO add values of variables of interest?
} ErrorNode;

/*
 * Returns a new empty stack (actually a pointer to no node = $NULL)
 * The returned variable should be treated as the stack
 */
ErrorNode* newErrorTraceStack();

/*
 * Makes a new $ErrorNode with the calling file name, the calling line index
 * and the line content
 * Returns the node
 * WARNING: this node has to be freed
 */
ErrorNode* newErrorNode(char const* const callingFileName, int const callingLineNb, char const* const callingLineContent);

/*
 * Returns $true if the stack $errorTraceStack is empty, $false otherwise
 */
bool isErrorStackEmpty(ErrorNode const* const errorTraceStack);

/*
 * Adds an $ErrorNode to the stack $errorTraceStack
 * Returns the new stack
 */
ErrorNode* push(ErrorNode* newNode, ErrorNode* errorTraceStack);

/*
 * Pops the last $ErrorNode from the stack $errorTraceStack
 * Returns this node
 */
ErrorNode* pop(ErrorNode const** errorTraceStack);

/*
 * Pops the last $ErrorNode from the stack $errorTraceStack
 * but doesn't return it (frees this pointer)
 */
void remove(ErrorNode** errorTraceStack);

#endif //_CERRORSTACK_ERROR_TRACE_STACK_H_
