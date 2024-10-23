#include "graphic.h"

void draw(char *output) {
    double y = Y_MAX;
    double calc_y;
    char s[MAX_EXPR_SIZE];
    while (y > Y_MIN) {
        double x = X_MIN;
        while (x < X_MAX) {
            strcpy(s, output);
            calc_y = calculate_x(s, x);
            if (fabs(calc_y - y) < EPSILON) {
                printf("*");
            } else {
                printf(".");
            }
            x += X_STEP;
        }
        printf("\n");
        y -= Y_STEP;
    }
}
