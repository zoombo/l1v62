#include <stdio.h>
#include <complex.h>
#include "../helper_funcs.h"

void msub() {
    double complex acomp, bcomp;
    acomp = getcmp();
    bcomp = getcmp();
    printf("Разность : %lf + %lf", creal(acomp - bcomp), cimag(acomp - bcomp));
}
