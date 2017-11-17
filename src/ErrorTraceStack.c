#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ErrorTraceStack.h"
#include "alloc.h"

ErrorNode* newErrorTraceStack()
{
   return NULL;
}

ErrorNode* newErrorNode(char const* const callingFileName, int const callingLineNb, char const* const callingLineContent)
{
   ErrorNode* result = malloc(sizeof(ErrorNode));

   result->callingLineNb = callingLineNb;

   result->callingFileName = malloc(strlen(callingFileName) * sizeof(char));
   for (int i=0; i<strlen(callingFileName); i++)
      result->callingFileName[i] = callingFileName[i];

   result->callingLineContent = malloc(strlen(callingLineContent) *sizeof(char));
   for (int i=0; i<strlen(callingLineContent); i++)
      result->callingLineContent[i] = callingLineContent[i];

   return result;
}

bool isErrorStackEmpty(ErrorNode const* const errorTraceStack)
{
   return (errorTraceStack == NULL);
}

ErrorNode* push(ErrorNode* newNode, ErrorNode* errorTraceStack)
{
   newNode->lastNode = errorTraceStack;
   return newNode;
}

ErrorNode* pop(ErrorNode** errorTraceStack)
{
   if (isErrorStackEmpty(*errorTraceStack))
   {
      fprintf(stderr, "WARNING: %s\n", "Tried to pop an empty stack.");//TODO replace this (remove stdio)
      return NULL;
   }

   ErrorNode* poppedNode = *errorTraceStack;
   *errorTraceStack = poppedNode->lastNode;
   return poppedNode;
}

void removeTail(ErrorNode** errorTraceStack)
{
   ErrorNode* poppedNode = pop(errorTraceStack);
   del(poppedNode);
}
