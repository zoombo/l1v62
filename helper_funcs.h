#pragma once
#include <complex.h>

void stolw(char *str, int len);
double complex getcmp();
void getfnc(void **fnc_handl, void (**fnc_ptr)(void), char *lib_name, char *fnc_name);
void getfnc2(void **fnc_handl, void (**fnc_ptr)(void), const char *dir_name, const char *fnc_name);


