#include "s21_string.h"
#include <string.h>

void s21_strerrno_test() {
    int error_codes[] = { 0, EPERM, EINTR, EIO, ENOENT, EINVAL, EBADF };

    for (int i = 0; i < sizeof(error_codes) / sizeof(error_codes[0]); i++) {
        int errnum = error_codes[i];

        char* s21_message = s21_strerror(errnum);

        char* std_message = strerror(errnum);

        if (strcmp(s21_message, std_message) == 0) {
            printf("s21_strerrno_test: SUCCESS\n");
        }
        else {
            printf("Test case %d: Failed\n", i);
            printf("  s21_strerror(%d) = \"%s\"\n", errnum, s21_message);
            printf("  strerror(%d) = \"%s\"\n", errnum, std_message);
        }
    }
}


void s21_trim_test_test() {
    const char* __s1 = "  Fight  ";
    const char* __rc = " ";
    const char* __r = (const char*)s21_trim(__s1, __rc);
    if (s21_strncmp(__r, "Fight", 6) == 0) {
        printf("s21_trim_test_test: SUCCESS\n");
    }
    else {
        printf("s21_trim_test_test: FAIL\n%s\n", __r);
    }
}


void s21_insert_test() {
    const char* __src = "I send hello world to everyone";
    const char* __str = "can ";
    s21_size_t __a = 2;
    const char* __r = (const char*)s21_insert(__src, __str, __a);
    if (s21_strncmp(__r, "I can send hello world to everyone", 35) == 0) {
        printf("s21_insert_test: SUCCESS\n");
    }
    else {
        printf("s21_insert_test: FAIL\n%s\n", __r);
    }
}


void s21_to_lower_test() {
    bool __correct_answ = true;
    const char* __s = "I LOVE CODING. I WAS ACTING. OR WAS I?";
    const char* __r = (const char*)s21_to_lower(__s);
    s21_size_t __l = s21_strlen(__r);
    for (s21_size_t i = 0; i < __l; i++) {
        if (__r[i] >= 'A' && __r[i] <= 'Z' && __r[i] != '.' && __r[i] != '?') {
            __correct_answ = false;
            break;
        }
    }
    if (__correct_answ) {
        printf("s21_to_lower_test: SUCCESS\n");
    }
    else {
        printf("s21_to_lower_test: FAIL\n%s\n", __r);
    }
}

void s21_to_upper_test() {
    bool __correct_answ = true;
    const char* __s = "will you take a bag?";
    const char* __r = (const char*)s21_to_upper(__s);
    s21_size_t __l = s21_strlen(__r);
    for (s21_size_t i = 0; i < __l; i++) {
        if (__r[i] >= 'a' && __r[i] <= 'z' && __r[i] != '?') {
            __correct_answ = false;
            break;
        }
    }
    if (__correct_answ) {
        printf("s21_to_upper_test: SUCCESS\n");
    }
    else {
        printf("s21_to_upper_test: FAIL\n%s\n", __r);
    }
}



void s21_strtok_test() {
    bool __correct_answ = false;
    char __s[] = "apple,banana,cherry";
    char __d[] = ",";
    const char* __r1 = strtok(__s, __d);
    const char* __r2 = strtok(__s, __d);
    while (__r1 != NULL && __r2 != NULL) {
        if (__r1 == __r2) {
            __correct_answ = true;
        }
        else {
            __correct_answ = false;
            break;
        }
        __r1 = strtok(NULL, __d);
        __r2 = strtok(NULL, __d);
    }
    if (__correct_answ) {
        printf("s21_strtok_test: SUCCESS\n");
    }
    else {
        printf("s21_strtok_test: FAIL\n");
    }
}


void s21_strstr_test() {
    const char* __s1 = "Hello";
    const char* __s2 = "llo";
    const char* __r1 = strstr(__s1, __s2);
    const char* __r2 = s21_strstr(__s1, __s2);
    s21_size_t __l = s21_strlen(__r1);
    if (s21_strncmp(__r1, __r2, __l) == 0) {
        printf("s21_strrchr_test: SUCCESS\n");
    }
    else {
        printf("s21_strrchr_test: FAIL\n%s\n%s\n", __r1, __r2);
    }
}


void s21_strrchr_test() {
    const char* __s = "Hello";
    char __c = 'l';
    const char* __r1 = strrchr(__s, __c);
    const char* __r2 = s21_strrchr(__s, __c);
    s21_size_t __l = s21_strlen(__r1);
    if (s21_strncmp(__r1, __r2, __l) == 0) {
        printf("s21_strrchr_test: SUCCESS\n");
    }
    else {
        printf("s21_strrchr_test: FAIL\n%s\n%s\n", __r1, __r2);
    }
}


void s21_strpbrk_test() {
    const char* __s1 = "World!";
    const char* __s2 = "bnnloiujas";
    const char* __r1 = strpbrk(__s1, __s2);
    const char* __r2 = s21_strpbrk(__s1, __s2);
    s21_size_t __l = s21_strlen(__r1);
    if (s21_strncmp(__r1, __r2, __l) == 0) {
        printf("s21_strpbrk_test: SUCCESS\n");
    }
    else {
        printf("s21_strpbrk_test: FAIL\n%s\n%s\n", __r1, __r2);
    }
}


void s21_strlen_test() {
    const char* __s = "World!";
    s21_size_t __r1 = strlen(__s);
    s21_size_t __r2 = strlen(__s);
    if (__r1 == __r2) {
        printf("s21_strlen_test: SUCCESS\n");
    }
    else {
        printf("s21_strlen_test: FAIL\n%ul\n%ul\n", __r1, __r2);
    }
}


void s21_strcspn_test() {
    const char* __s1 = "World!";
    const char* __s2 = "Hello!";
    s21_size_t __r1 = s21_strcspn(__s1, __s1);
    s21_size_t __r2 = strcspn(__s1, __s1);
    if (__r1 == __r2) {
        printf("s21_strcspn_test: SUCCESS\n");
    }
    else {
        printf("s21_strcspn_test: FAIL\n%ul\n%ul\n", __r1, __r2);
    }
}


void s21_strncpy_test() {
    char __s1[14] = "Hello, World!";
    const char* __s2 = "Wello!";
    const char* __r1 = strncpy(__s1, __s2, 7);
    const char* __r2 = s21_strncpy(__s1, __s2, 7);
    s21_size_t __l = s21_strlen(__r1);
    if (s21_memcmp(__r1, __r2, __l) == 0) {
        printf("s21_strncpy_test: SUCCESS\n");
    }
    else {
        printf("s21_strncpy_test: FAIL\n%s\n%s\n", __r1, __r2);
    }
}


void s21_strncmp_test() {
    const char* str1 = "Hello, World!";
    const char* str2 = "Wello!";
    s21_size_t len = s21_strlen(str2);
    int __r1 = s21_strncmp(str1, str2, len);
    int __r2 = strncmp(str1, str2, len);

    if (__r1 == __r2) {
        printf("s21_strncmp_test: SUCCESS\n");
    }
    else {
        printf("s21_strncmp_test: FAIL\n%d\n%d\n", __r1, __r2);
    }
}


void s21_strchr_test() {
    const char* __s = "World world";
    char __c = 'l';
    const char* __r1 = s21_strchr(__s, (int)__c);
    const char* __r2 = strchr(__s, (int)__c);
    s21_size_t __l = s21_strlen((const char*)__r2);
    if (s21_memcmp(__r1, __r2, __l) == 0) {
        printf("s21_strchr_test: SUCCESS\n");
    }
    else {
        printf("s21_strchr_test: FAIL\n%s\n%s\n", __r1, __r2);
    }
}


void s21_strncat_test() {
    char __d[9] = "Hello";
    const char* __s = "World";
    int __l = 3;
    const char* __r1 = s21_strncat(__d, __s, __l);
    const char* __r2 = strncat(__d, __s, __l);
    if (s21_memcmp(__r1, __r2, 9) == 0) {
        printf("s21_strncat_test: SUCCESS\n");
    }
    else {
        printf("s21_strncat_test: FAIL\n%s\n%s\n", __r1, __r2);
    }
}


void s21_memset_test() {
    char __s[6] = "Word!";
    int __c = 5;
    s21_size_t __l = s21_strlen((char*)__s);
    const char* __r1 = (const char*)s21_memset(__s, __c, __l);
    const char* __r2 = (const char*)memset(__s, __c, __l);
    if (__r1 == __r2) {
        printf("s21_memset_test: SUCCESS\n");
    }
    else {
        printf("s21_memset_test: FAIL\n%s\n%s\n", (char*)__r1, (char*)__r2);
    }
}


void s21_memcpy_test() {
    const char* src = "World!";
    s21_size_t len = s21_strlen(src);
    char dest[20] = "Hello";

    const char* __r1 = (const char*)s21_memcpy(dest, src, len);
    const char* __r2 = (const char*)memcpy(dest, src, len);

    if (__r1 == __r2) {
        printf("s21_memcpy_test: SUCCESS\n");
    }
    else {
        printf("s21_memcpy_test: FAIL\n%s\n%s\n", (char*)__r1, (char*)__r2);
    }
}


void s21_memcmp_test() {
    const char* str1 = "Hello, World!";
    const char* str2 = "Hello!";
    s21_size_t len = s21_strlen(str2);

    int __r1 = (int)s21_memcmp(str1, str2, len);
    int __r2 = (int)memcmp(str1, str2, len);

    if (__r1 == __r2) {
        printf("s21_memcmp_test: SUCCESS\n");
    }
    else {
        printf("s21_memcmp_test: FAIL\n%d\n%d\n", __r1, __r2);
    }
}


void s21_memchr_test() {
    const char* str = "Hello, World!";
    char search = 'W';
    s21_size_t len = s21_strlen(str);
    int __r1 = (int)s21_memchr(str, search, len);
    int __r2 = (int)memchr(str, search, len);
    if (__r1 == __r2) {
        printf("s21_memchr_test: SUCCESS\n");
    }
    else {
        printf("s21_memchr_test: FAIL\n%d\n%d\n", __r1, __r2);
    }
}


//int main() {
//    s21_trim_test_test();
//    s21_insert_test();
//    s21_to_lower_test();
//    s21_to_upper_test();
//    s21_strtok_test();
//    s21_strstr_test();
//    s21_strrchr_test();
//    s21_strpbrk_test();
//    s21_strlen_test();
//    /*s21_strerrno_test();*/
//    s21_strcspn_test();
//    s21_strncpy_test();
//    s21_strncmp_test();
//    s21_strchr_test();
//    s21_strncat_test();
//    s21_memset_test();
//    s21_memcpy_test();
//    s21_memcmp_test();
//    s21_memchr_test();
//
//    return 0;
//}
