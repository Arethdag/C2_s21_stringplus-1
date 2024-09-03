#ifndef S21_FUNC_FOR_SSCANF_H
#define S21_FUNC_FOR_SSCANF_H
#include "../s21_string.h"

struct specifier {
  char flag[4];
  char width[310];
  char precision[310];
  char length[3];
  char type;
};

int s21_scanf_subfunc(char *string, const char *format, const char *types,
                      struct specifier *spec, va_list *ap, int *success, int *j,
                      int count_successes);
int s21_atoi(const char *str);
long s21_strtol(const char *nptr, register int base);
unsigned long s21_strtoul(const char *nptr, char **endptr, register int base);
unsigned long long s21_strtoull(const char *nptr, char **endptr,
                                register int base);
long double s21_atold(char *str);
long long s21_atoll(const char *str);
long s21_atol(const char *str);

void specifier_parsing(char *str, struct specifier *spec);
void numbers_parsing(char *str, char *buff);
void pointer_shift(char **buff, char *buff1, const char *str);
void vararg_init(char type, va_list *ap);
void specifier_init(struct specifier *spec);
int match_str_and_format(char *str, struct specifier *spec, va_list *ap,
                         int *j);
int check_falid_format(const char *format);
int s21_isspace(char c);

int read_d(char *str, va_list *ap, struct specifier *spec, int *j);
int read_s(char *str, va_list *ap, struct specifier *spec, int *j);
int read_c(char *str, va_list *ap, struct specifier *spec, int *j);
int read_u(char *str, va_list *ap, struct specifier *spec, int *j);
int read_o(char *str, va_list *ap, struct specifier *spec, int *j);
int read_xX(char *str, va_list *ap, struct specifier *spec, int *j);
int read_f(char *str, va_list *ap, struct specifier *spec, int *j);
int read_g(char *str, va_list *ap, struct specifier *spec, int *j);
int read_e(char *str, va_list *ap, struct specifier *spec, int *j);
int read_i(char *str, va_list *ap, struct specifier *spec, int *j);
int s21_isdigit(char c);
int s21_isupper(char c);
int s21_isalpha(char c);
int s21_empty_str(char *str);
int s21_ishex(char c);
int s21_isoctal(char c);
void s21_strcpy(char *dest, const char *src);
int s21_strcmp(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *str1, const char *str2);
void flags_parsing(char *buffer, const char *flags, struct specifier *spec);
void flag_length_parsing(char *buffer, const char *flag_length,
                         struct specifier *spec);

#endif