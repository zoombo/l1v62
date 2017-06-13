#include <stdio.h>
#include <complex.h>
#include "../helper_funcs.h"

void madd() {
    double complex acomp, bcomp;
    acomp = getcmp();
    bcomp = getcmp();
    printf("Сумма : %lf + %lf", creal(acomp + bcomp), cimag(acomp + bcomp));
}

