#include "s21_sprintf_parser.h"

#include <stdio.h>

bool is_digit(char c);
static bool is_specifier(char c);

bool is_option_light(char c);

const char *parse_options(Options *options, const char *format, va_list args) {
  const char *next_format_ptr;

  if (is_option(format)) {
    while (is_option_light(*format)) {
      switch (*format) {
        case '-':
          options->left_justification = true;
          options->zero = false;
          break;
        case '+':
          options->show_plus = true;
          options->blank_space = false;
          break;
        case ' ':
          if (!options->show_plus) options->blank_space = true;
          break;
        case '.':
          options->point = true;
          format++;
          if (*format == '*') {
            options->precision_description = va_arg(args, int);
          } else {
            format = get_precision(options, format);
          }
          break;
        case '*':
          options->width_description = va_arg(args, int);
          break;
        case '1' ... '9':
          next_format_ptr = format + 1;
          options->width_description = *format - '0';
          while (is_digit(*next_format_ptr)) {
            options->width_description *= 10;
            options->width_description += (*next_format_ptr) - '0';
            next_format_ptr++;
            format++;
          }
          break;
        case 'h':
          options->long_opt = false;
          options->short_opt = true;
          options->long_double = false;
          break;
        case 'l':
          options->long_opt = true;
          options->short_opt = false;
          options->long_double = false;
          break;
        case 'L':
          options->long_opt = false;
          options->short_opt = false;
          options->long_double = true;
          break;
        case '#':
          options->alternative_form = true;
          break;
        case '0':
          if (*(format + 1) != '.') {
            options->zero = true;
            format++;
            if (*format == '+' || *format == '-') {
              format++;
            }
            if (is_digit(*format)) {
              format = get_precision(options, format);
            }
            if (*format == '*') {
              options->precision_description = va_arg(args, int);
            }
            if (*format == '.' && *(format + 1) == '*') {
              options->precision_description = va_arg(args, int);
              format++;
            }
          }
          break;
        default:
          break;
      }
      if (is_option_light(*format)) {
        format++;
      }
    }
  }
  return format;
}

void set_default(Options *options) {
  options->left_justification = false;
  options->show_plus = false;
  options->blank_space = false;
  options->short_opt = false;
  options->long_opt = false;
  options->long_double = false;
  options->alternative_form = false;
  options->zero = false;
  options->width_description = 0;
  options->precision_description = 0;
  options->has_big_E_character = false;
  options->has_error = false;
  options->upper_case = false;
  options->point = false;
}

const char *get_precision(Options *options, const char *format) {
  if (is_digit(*format)) {
    options->precision_description = *format - '0';
    ++format;
  }

  while (is_digit(*format)) {
    options->precision_description *= 10;
    options->precision_description += (*format) - '0';
    ++format;
  }

  if (!is_digit(*format)) {
    --format;
  }
  return format;
}

bool is_option(const char *format) {
  bool result;

  for (int i = 0; i < (int)s21_strlen(format);) {
    if (*format == '[' || *format == '#' || *format == '-' || *format == '+' ||
        *format == ' ' || *format == '0' || *format == '*' ||
        is_digit(*format) || *format == '.' ||
        (*format == '.' && is_digit(*(format + 1))) || *format == 'h' ||
        *format == 'l' || *format == 'L') {
      result = true;
      format++;
    }

    if (is_digit(*format)) {
      while (is_digit(*format)) {
        format++;
      }
      if (*format == '+' || *format == '-' || *format == ' ') {
        result = false;
        break;
      }
    }

    if (*format == ' ') {
      while (*format == ' ') {
        format++;
      }
    }

    if (*format == ' ') {
      format++;
      while (*format == '-' || *format == '+' || *format == '*' ||
             is_digit(*format) || *format == '.' ||
             (*format == '.' && is_digit(*(format + 1))) || *format == 'h' ||
             *format == 'l' || *format == 'L') {
        format++;
      }
    }

    if (is_digit(*format)) {
      while (is_digit(*format)) {
        format++;
      }
    }
    if (*format == '-' || *format == '+' || *format == '*' ||
        is_digit(*format) || *format == '.' ||
        (*format == '.' && is_digit(*(format + 1))) || *format == 'h' ||
        *format == 'l' || *format == 'L') {
      result = true;
      ++format;
    }
    if (is_digit(*format)) {
      while (is_digit(*format)) {
        format++;
      }
    }
    if (*format == '-' ||
        (*format == '*' && (*(format + 1) == 'h' || *(format + 1) == 'l')) ||
        *format == '.' || (*format == '.' && is_digit(*(format + 1))) ||
        *format == 'h' || *format == 'l' || *format == 'L') {
      result = true;
      format++;
    }
    if (is_digit(*format)) {
      while (is_digit(*format)) {
        format++;
      }
    }
    if ((*format == 'h' && is_specifier(*(format + 1))) ||
        (*format == 'l' && is_specifier(*(format + 1))) ||
        (*format == 'L' && is_specifier(*(format + 1)))) {
      result = true;
      break;

    } else if ((*format == 'h' && *(format + 1) == 'h') ||
               (*format == 'l' && *(format + 1) == 'l') ||
               (*format == 'h' && *(format + 1) == 'l')) {
      result = true;
      format = format + 2;
    }

    if (*format == '.' || (*format == '.' && is_digit(*(format + 1)))) {
      result = true;
      format++;
    }
    if (is_digit(*format)) {
      while (is_digit(*format)) {
        format++;
      }
    }

    if ((*format == 'h' && is_specifier(*(format + 1))) ||
        (*format == 'l' && is_specifier(*(format + 1))) ||
        (*format == 'L' && is_specifier(*(format + 1)))) {
      result = true;
      break;

    } else if ((*format == 'h' && *(format + 1) == 'h') ||
               (*format == 'l' && *(format + 1) == 'l') ||
               (*format == 'h' && *(format + 1) == 'l')) {
      result = true;
      format = format + 2;
    }

    if ((*format == '*' && is_specifier(*(format + 1))) ||
        is_specifier(*format)) {
      result = true;
      break;
    } else {
      result = false;
      break;
    }
  }
  return result;
}

bool is_digit(char c) { return ((c >= '0' && c < '9') || c == '9'); }

static bool is_specifier(char c) {
  bool result;
  switch (c) {
    case '%':
    case 'c':
    case 'd':
    case 'f':
    case 's':
    case 'u':
    case 'g':
    case 'G':
    case 'e':
    case 'E':
    case 'x':
    case 'X':
    case 'o':
    case 'p':
    case 'i':
    case 'n':
      result = true;
      break;
    default:
      result = false;
      break;
  }
  return result;
}

bool is_option_light(char c) {
  bool result;
  switch (c) {
    case '-':
    case '+':
    case ' ':
    case '.':
    case '*':
    case '0' ... '9':
    case 'h':
    case 'l':
    case 'L':
    case '#':
      result = true;
      break;
    default:
      result = false;
      break;
  }
  return result;
}