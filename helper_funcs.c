#include <stdio.h>
#include <complex.h>
#include <ctype.h>
#include <dlfcn.h>
/// Для функции getfnc2 .
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

void stolw(char *str, int len) {
    for (int i = 0; i < len; i++)
        str[i] = tolower(str[i]);
}

double complex getcmp() {
    double tmp_a, tmp_b;
    printf("Enter real part: ");
    scanf("%lf", &tmp_a);
    printf("Enter imag part: ");
    scanf("%lf", &tmp_b);
    double complex tcomp = tmp_a + tmp_b * I;
    return tcomp;
}


/// Возвращает указатель на найденную функцию.
/// \param fnc_handl
/// \param lib_name
/// \param fnc_name
/// \return Указатель на функцию или NULL в случае неудачи.

static void *getfnc_s(void **fnc_handl, const char *lib_name, const char *fnc_name) {
    // Переменная для хранения кода ошибки.
    // int err;
    void *fnc_ptr = NULL;

    // Пробуем открыть библиотеку.
    *fnc_handl = dlopen(lib_name, RTLD_LAZY);
    if (*fnc_handl == NULL)
        return NULL;
    
    // Если открыли успешно то ищем в ней функцию.
    fnc_ptr = dlsym(*fnc_handl, fnc_name);
    if (fnc_ptr == NULL) {
        dlclose(*fnc_handl);
        return NULL;
    }

    return fnc_ptr;
}

/// Достает функцию из указанного каталога.
/// Ищет функцию по всем библиотекам в каталоге.
/// \param fnc_handl - адрес указателя, описателя открываемой библиотеки.
/// \param fnc_ptr - адрес указателя принимающего найденную функцию.
/// \param dir_name - име каталога с библиотеками.
/// \param fnc_name - имя искомой функции.

void getfnc2(void **fnc_handl, void (**fnc_ptr)(void), const char *dir_name, const char *fnc_name) {

    // Структура-описатель каталога.
    DIR *ddir;
    // Структура описатель текущего выбранного файла/каталога.
    struct dirent *cdir;
    // Структура с подробными сведениями о файле.
    struct stat cdir_stat;
    // Переменная для хранения пути к библиотеке.
    char mystr[256] = {0};

    ddir = opendir(dir_name);
    //ddir = opendir(".");
    if (!ddir) {
        printf("In getfnc2(1): %d\n", errno);
        return;
    }

    // Проходим по всем файлам в каталоге.
    while ((cdir = readdir(ddir)) != NULL) {
        if (!strcmp(cdir->d_name, "."))
            continue;
        if (!strcmp(cdir->d_name, ".."))
            continue;

        stat(cdir->d_name, &cdir_stat);
        
        // Конкатенация пути и имени библиотеки.
        strcpy(mystr, dir_name);
        strcpy(mystr, cdir->d_name);

        *fnc_ptr = getfnc_s(fnc_handl, mystr, fnc_name);
        if (*fnc_ptr != NULL) {
            printf("\"%s\" found in %s\n", fnc_name, cdir->d_name);
            return;
        }

    }

}

