#include "stac.h"

stack* init(int cap) {
    if (cap < 1) {
        return NULL;
    }
    stack* root = calloc(1, sizeof(stack));
    root->data = calloc(cap, sizeof(char*));
    root->capac = cap;
    root->size = 0;
    return root;
}

void push(stack* root, char* str) {
    if (root->size == root->capac) {
        root->data = realloc(root->data, root->capac * 2 * sizeof(char*));
        root->capac *= 2;
    }
    root->data[root->size] = str;
    root->size++;
}

char* pop(stack* root) {
    if (root == NULL || root->size == 0) {
        return NULL;
    }
    char* str = root->data[root->size - 1];
    root->size--;
    return str;
}

void destroy(stack* root) {
    free(root->data);
    free(root);
}

int isEmpty(stack* root) { return root->size == 0; }

char* peek(stack* root) {
    if (root == NULL || root->size == 0) {
        return NULL;
    }
    return root->data[root->size - 1];
}