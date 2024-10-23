#include <stdio.h>
#include <stdlib.h>

#include "calculate.h"

#define EPSILON 0.05
#define Y_MAX 1
#define Y_MIN -1
#define X_MAX (4 * M_PI)
#define X_MIN 0
#define Y_STEP ((Y_MAX - Y_MIN) / 24.0)
#define X_STEP ((X_MAX - X_MIN) / 79.0)

#ifndef DRAW
#define DRAW

void draw(char *output);

#endif
