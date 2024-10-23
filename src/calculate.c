#include "calculate.h"
double calculate_x(char *output, double x) {
    double y;
    doub_stack *root = d_init(10);
    char *token = strtok(output, " ");
    while (token != NULL) {
        if (isNumber(token[0])) {
            d_push(root, strtod(token, NULL));
        } else if (strcmp(token, "x") == 0) {
            d_push(root, x);
        } else if (isFunction(token)) {
            if (strcmp(token, "sin") == 0) {
                d_push(root, sin(d_pop(root)));
            } else if (strcmp(token, "cos") == 0) {
                d_push(root, cos(d_pop(root)));
            } else if (strcmp(token, "tan") == 0) {
                d_push(root, tan(d_pop(root)));
            } else if (strcmp(token, "sqrt") == 0) {
                d_push(root, sqrt(d_pop(root)));
            } else if (strcmp(token, "ctg") == 0) {
                d_push(root, 1 / tan(d_pop(root)));
            } else if (strcmp(token, "ln") == 0) {
                d_push(root, log(d_pop(root)));
            } else {
                printf("\nunkn1\n");
            }
        } else if (precedence(token) <= 2 && precedence(token) > 0) {
            if (strcmp(token, "+") == 0) {
                double n1 = d_pop(root);
                double n2 = d_pop(root);
                d_push(root, n1 + n2);
            } else if (strcmp(token, "-") == 0) {
                double n1 = d_pop(root);
                double n2 = d_pop(root);
                d_push(root, n2 - n1);
            } else if (strcmp(token, "/") == 0) {
                double n1 = d_pop(root);
                double n2 = d_pop(root);
                d_push(root, n2 / n1);
            } else if (strcmp(token, "*") == 0) {
                double n1 = d_pop(root);
                double n2 = d_pop(root);
                d_push(root, n1 * n2);
            } else {
                printf("\nunkn2\n");
            }
        } else {
            printf("\nunkn3\n");
        }
        token = strtok(NULL, " ");
    }

    // while(root->size>0){
    //     printf("\nx= %lf ",d_pop(root));
    // }
    // d_pop(root);
    y = d_pop(root);
    // printf("%lf\n",x);
    d_destroy(root);
    return y;
}