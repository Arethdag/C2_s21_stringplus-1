#ifndef S21_SPRINTF_PARSER_H
#define S21_SPRINTF_PARSER_H
#include "../s21_string.h"

typedef struct Options {
  bool left_justification;  // '-'
  bool show_plus;           // '+'
  bool blank_space;         // ' '
  bool short_opt;           // 'h'
  bool long_opt;            // 'l'
  bool long_double;         // 'L'
  bool alternative_form;    // '#'
  bool zero;                // '0'
  int width_description;
  int precision_description;
  bool has_big_E_character;  // scientific notation with 'e' or 'E'.
  bool has_error;
  bool upper_case;
  bool point;
} Options;

const char *parse_options(Options *options, const char *format, va_list args);
void set_default(Options *options);
const char *get_precision(Options *options, const char *format);
bool is_option(const char *format);
bool is_digit(char c);

#endif