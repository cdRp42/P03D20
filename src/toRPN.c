#include "toRPN.h"

int precedence(const char* op) {
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) return 2;
    if (isFunction(op)) return 3;
    return 0;
}

int isFunction(const char* str) {
    return strcmp(str, "sin") == 0 || strcmp(str, "cos") == 0 || strcmp(str, "tan") == 0 ||
           strcmp(str, "ctg") == 0 || strcmp(str, "sqrt") == 0 || strcmp(str, "ln") == 0;
}

int isNumber(char c) { return (c >= '0' && c <= '9'); }

void toRPN(RPN* rpn) {
    stack* stack = init(10);
    rpn->output[0] = '\0';

    char* token = strtok(rpn->expression, " ");
    while (token != NULL) {
        if (isNumber(token[0])) {
            strcat(rpn->output, token);
            strcat(rpn->output, " ");
        } else if (strcmp(token, "x") == 0) {
            strcat(rpn->output, token);
            strcat(rpn->output, " ");
        } else if (isFunction(token)) {
            push(stack, token);
        } else if (strcmp(token, "(") == 0) {
            push(stack, token);
        } else if (strcmp(token, ")") == 0) {
            while (!isEmpty(stack) && strcmp(peek(stack), "(") != 0) {
                strcat(rpn->output, pop(stack));
                strcat(rpn->output, " ");
            }
            pop(stack);
            if (!isEmpty(stack) && isFunction(peek(stack))) {
                strcat(rpn->output, pop(stack));
                strcat(rpn->output, " ");
            }
        } else {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(token)) {
                strcat(rpn->output, pop(stack));
                strcat(rpn->output, " ");
            }
            push(stack, token);
        }
        token = strtok(NULL, " ");
    }

    while (!isEmpty(stack)) {
        strcat(rpn->output, pop(stack));
        strcat(rpn->output, " ");
    }

    destroy(stack);
}

void inputExpression(RPN* rpn) {
    printf("функция: ");
    fgets(rpn->expression, sizeof(rpn->expression), stdin);
    rpn->expression[strcspn(rpn->expression, "\n")] = 0;
}