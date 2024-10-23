#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stac.h"

#ifndef TORPN_H
#define TORPN_H

#define MAX_EXPR_SIZE 200

typedef struct {
    char expression[MAX_EXPR_SIZE];
    char output[MAX_EXPR_SIZE];
} RPN;

int precedence(const char* op);
int isFunction(const char* str);
int isNumber(char c);
void toRPN(RPN* rpn);
void inputExpression(RPN* rpn);

#endif
