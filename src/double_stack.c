#include "double_stack.h"

doub_stack* d_init(int cap) {
    if (cap < 1) {
        return NULL;
    }
    doub_stack* root = calloc(1, sizeof(doub_stack));
    root->data = calloc(cap, sizeof(double));
    root->capac = cap;
    root->size = 0;
    return root;
}

void d_push(doub_stack* root, double num) {
    if (root->size == root->capac) {
        root->data = realloc(root->data, root->capac * 2 * sizeof(double));
        root->capac *= 2;
    }
    root->data[root->size] = num;
    root->size++;
}

double d_pop(doub_stack* root) {
    double num = root->data[root->size - 1];
    root->size--;
    return num;
}

void d_destroy(doub_stack* root) {
    free(root->data);
    free(root);
}