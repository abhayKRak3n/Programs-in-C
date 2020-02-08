#ifndef __INFIX_H__
#define __INFIX_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include<math.h>
#include<stdbool.h>

#include "stack.h"
#include "postfix.h"

double double_stack_peek(struct double_stack * this); //return item at top of stack

bool isEmpty(struct double_stack * this); //check if stack is empty or not

bool precedence(char first, char sec);
double evaluate_infix_expression(char ** expr, int nterms);

#endif
