#include <stdio.h>
#include <complex.h>
#include "../helper_funcs.h"

void mdiv() {
    double complex acomp, bcomp;
    acomp = getcmp();
    bcomp = getcmp();
    printf("Частное : %lf + %lf", creal(acomp / bcomp), cimag(acomp / bcomp));
}
