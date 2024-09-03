#ifndef S21_STRING_H
#define S21_STRING_H
#define S21_NULL ((void *)0)
#include <ctype.h>
#include <errno.h>  //для ошибки errno = ERANGE в коде;
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>  //для uintptr_t для флага %p
#include <stdlib.h>

typedef unsigned long s21_size_t;

// MARK: PART 1
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
// MARK: PART 2-3
int s21_sprintf(char *buffer, const char *format, ...);
// MARK: PART 4
int s21_sscanf(const char *str, const char *format, ...);
// MARK: PART 5
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *str, const char *substr, s21_size_t index);
void *s21_trim(const char *str, const char *trim);

#endif