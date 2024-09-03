#ifndef S21_SPRINTF_FUNC_H
#define S21_SPRINTF_FUNC_H
#include "../s21_string.h"
#include "s21_sprintf_parser.h"

#define MAX_DIGITS 100

char *int_to_str(long long value);
// static char *double_to_str(long double value, Options* options);
char *double_to_enotation(long double value, Options *options);
char *add_prefix(bool is_negative_value, Options *options);
char *make_empty_str(Options *options, s21_size_t already_filled_length);
char *exp_int_to_str(int value);
char *uint_to_hex_str(long long value, bool uppercase, Options *options);

long double get_float_value(Options *options, va_list args);
long long get_int_value(Options *options, va_list args);
unsigned long long get_unsigned_int_value(Options *options, va_list args);
void reverse_string(char *str);

char *make_back_space_str(Options *options, s21_size_t already_filled_length);
// static char *add_prefix_u(bool is_negative_value, Options* options);
int make_empty_str_str(Options *options, s21_size_t already_filled_length);
char *long_double_to_string_e(long double num, Options *options);
char *long_double_to_string_g_specifier(long double num, Options *options);
char *double_to_enotation_g_specifier(long double value, Options *options);
char *long_double_to_string_g(long double num, Options *options);
char *long_double_to_string_f(long double num, Options *options);

// Specifier func
void *switch_specifier(char *buffer, const char *format, va_list args,
                       Options *options);
void process_d_specifier(char *buffer, va_list args, Options *options);
void process_f_specifier(char *buffer, va_list args, Options *options);
void process_c_specifier(char *buffer, va_list args, Options *options);
void process_s_specifier(char *buffer, va_list args, Options *options);
void process_u_specifier(char *buffer, va_list args, Options *options);
void process_e_specifier(char *buffer, va_list args, Options *options);
void process_g_specifier(char *buffer, va_list args, Options *options);
void process_p_specifier(char *buffer, va_list args, Options *options);
void process_o_specifier(char *buffer, va_list args, Options *options);
void process_x_specifier(char *buffer, va_list args, Options *options);
void process_n_specifier(char *buffer, va_list args);

#endif