#include <stdio.h>
#include "mileage.h"

int getPriority(int A, int B, int C){
    return A / 1000 + B - C;
}