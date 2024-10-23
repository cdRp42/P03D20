#include "calculate.h"
#include "graphic.h"
#include "toRPN.h"

int main() {
    RPN rpn;
    inputExpression(&rpn);
    toRPN(&rpn);
    printf("%s\n", rpn.output);
    draw(rpn.output);
    // printf("calc = %lf",calculate_x(rpn.output, 0.159068));
    return 0;
}