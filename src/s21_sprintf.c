#include "helpers/s21_sprintf_func.h"
#include "helpers/s21_sprintf_parser.h"
#include "s21_string.h"

int s21_sprintf(char *buffer, const char *format, ...) {
  if (buffer == S21_NULL || format == S21_NULL) return -1;
  if (*format == '\0') return -1;

  s21_memset(buffer, '\0', sizeof(buffer));

  Options options = {.left_justification = false,
                     .show_plus = false,
                     .blank_space = false,
                     .short_opt = false,
                     .long_opt = false,
                     .long_double = false,
                     .alternative_form = false,
                     .zero = false,
                     .width_description = 0,
                     .precision_description = 0,
                     .has_big_E_character = false,
                     .has_error = false,
                     .upper_case = false,
                     .point = false};

  va_list args;
  va_start(args, format);

  while (*format != '\0') {
    if (*format == '%' && is_option(format + 1)) {
      format++;
      format = parse_options(&options, format, args);
      switch_specifier(buffer, format, args, &options);
      set_default(&options);
    } else {
      s21_strncat(buffer, format, 1);
    }
    format++;
  }
  va_end(args);
  return s21_strlen(buffer);
}

void *switch_specifier(char *buffer, const char *format, va_list args,
                       Options *options) {
  switch (*format) {
    case '%':
      s21_strncat(buffer, "%", 1);
      break;
    case 'c':
      process_c_specifier(buffer, args, options);
      break;
    case 'd':
      process_d_specifier(buffer, args, options);
      break;
    case 'f':
      process_f_specifier(buffer, args, options);
      break;
    case 's':
      process_s_specifier(buffer, args, options);
      break;
    case 'u':
      process_u_specifier(buffer, args, options);
      break;
    case 'e':
      process_e_specifier(buffer, args, options);
      break;
    case 'E':
      options->has_big_E_character = true;
      process_e_specifier(buffer, args, options);
      break;
    case 'g':
      process_g_specifier(buffer, args, options);
      break;
    case 'G':
      options->has_big_E_character = true;
      process_g_specifier(buffer, args, options);
      break;
    case 'x':
      process_x_specifier(buffer, args, options);
      break;
    case 'X':
      options->upper_case = true;
      process_x_specifier(buffer, args, options);
      break;
    case 'p':
      process_p_specifier(buffer, args, options);
      break;
    case 'o':
      process_o_specifier(buffer, args, options);
      break;
    case 'i':
      process_d_specifier(buffer, args, options);
      break;
    case 'n':
      process_n_specifier(buffer, args);
      break;
    default:
      break;
  }
  return buffer;
}

void process_c_specifier(char *buffer, va_list args, Options *options) {
  char c = va_arg(args, int);
  char *back_space_str = make_back_space_str(options, 1);

  if (!options->left_justification) {
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
    s21_strncat(buffer, &c, 1);
  }
  if (options->left_justification) {
    s21_strncat(buffer, &c, 1);
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
  }
  if (back_space_str != S21_NULL) {
    free(back_space_str);
  }
}

void process_d_specifier(char *buffer, va_list args, Options *options) {
  long long value = get_int_value(options, args);
  char *prefix = add_prefix(
      (value < 0),
      options);  // возврат prefix[0] или '+', или '-', или ' ', '\0' плюс '\0'
  char *str = int_to_str(llabs(
      value));  // llabs(value) возврат абсолютного значения типа long long int

  char *empty_str = make_empty_str(options, s21_strlen(str));
  char *back_space_str = make_back_space_str(
      options, s21_strlen(empty_str) + s21_strlen(prefix) + s21_strlen(str));

  if (!options->left_justification && (empty_str != S21_NULL)) {
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
    s21_strncat(buffer, prefix, s21_strlen(prefix));
    s21_strncat(buffer, empty_str, s21_strlen(empty_str));
    if (value == 0 && options->point != true) {
      s21_strncat(buffer, "0", 1);
    } else if (value == 0 && options->point == true &&
               options->precision_description == 0) {
      s21_strncat(buffer, "", 0);
    } else {
      s21_strncat(buffer, str, s21_strlen(str));
    }
  }

  if (options->left_justification && (empty_str != S21_NULL)) {
    s21_strncat(buffer, prefix, s21_strlen(prefix));
    s21_strncat(buffer, empty_str, s21_strlen(empty_str));
    if (value == 0 && options->point != true) {
      s21_strncat(buffer, "0", 1);
    } else if (value == 0 && options->point == true &&
               options->precision_description == 0) {
      s21_strncat(buffer, "", 0);
    } else {
      s21_strncat(buffer, str, s21_strlen(str));
    }
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
  }

  if (str != S21_NULL) free(str);
  if (prefix != S21_NULL) free(prefix);
  if (empty_str != S21_NULL) free(empty_str);
  if (back_space_str != S21_NULL) free(back_space_str);
}

void process_f_specifier(char *buffer, va_list args, Options *options) {
  long double value = get_float_value(options, args);

  char *prefix = add_prefix((value < 0 || signbit(value)), options);
  char *str = long_double_to_string_f(fabsl(value), options);
  char *back_space_str =
      make_back_space_str(options, s21_strlen(str) + s21_strlen(prefix));

  if (!options->left_justification && !isnan(value) && !isinf(value) &&
      (str != S21_NULL)) {
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
    s21_strncat(buffer, prefix, s21_strlen(prefix));
    s21_strncat(buffer, str, s21_strlen(str));
  }

  if (options->left_justification && !isnan(value) && !isinf(value) &&
      (str != S21_NULL)) {
    s21_strncat(buffer, prefix, s21_strlen(prefix));
    s21_strncat(buffer, str, s21_strlen(str));
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
  }

  if (isnan(value) &&
      !signbit(value)) {  // так проверяем является ли value значением nan
    s21_strncat(buffer, "nan", 3);
  } else if (isnan(value) && signbit(value)) {
    s21_strncat(buffer, "-nan", 4);
  } else if (isinf(value) && !signbit(value)) {
    s21_strncat(buffer, "inf", 3);
  } else if (isinf(value) && signbit(value)) {
    s21_strncat(buffer, "-inf", 4);
  }

  if (str != S21_NULL) free(str);
  if (prefix != S21_NULL) free(prefix);
  if (back_space_str != S21_NULL) free(back_space_str);
}

void process_s_specifier(char *buffer, va_list args, Options *options) {
  char *str = va_arg(args, char *);
  int leng_str = make_empty_str_str(options, s21_strlen(str));
  char *back_space_str = make_back_space_str(options, leng_str);

  if (!options->left_justification && str != S21_NULL) {
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
    s21_strncat(buffer, str, leng_str);
  }
  if (options->left_justification && str != S21_NULL) {
    s21_strncat(buffer, str, leng_str);
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
  }
  if (str == S21_NULL) {
    s21_strncat(buffer, "(null)", 6);
  }
  if (back_space_str != S21_NULL) {
    free(back_space_str);
  }
}

void process_u_specifier(char *buffer, va_list args, Options *options) {
  unsigned long long value = get_unsigned_int_value(options, args);
  char *str = int_to_str(
      value);  // llabs(value) возврат абсолютного значения типа long long int

  char *empty_str = make_empty_str(options, s21_strlen(str));
  char *back_space_str =
      make_back_space_str(options, s21_strlen(empty_str) + s21_strlen(str));
  if (!options->left_justification && (empty_str != S21_NULL)) {
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
    s21_strncat(buffer, empty_str, s21_strlen(empty_str));
    s21_strncat(buffer, str, s21_strlen(str));
  }
  if (options->left_justification && (empty_str != S21_NULL)) {
    s21_strncat(buffer, empty_str, s21_strlen(empty_str));
    s21_strncat(buffer, str, s21_strlen(str));
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
  }
  if (str != S21_NULL) free(str);
  if (empty_str != S21_NULL) free(empty_str);
  if (back_space_str != S21_NULL) free(back_space_str);
}

void process_e_specifier(char *buffer, va_list args, Options *options) {
  long double value = get_float_value(options, args);
  char *result_str = double_to_enotation(value, options);
  char *empty_str = make_empty_str(options, s21_strlen(result_str));

  if (!options->left_justification && empty_str != S21_NULL)
    s21_strncat(buffer, empty_str, s21_strlen(empty_str));

  s21_strncat(buffer, result_str, s21_strlen(result_str));

  if (options->left_justification && empty_str != S21_NULL)
    s21_strncat(buffer, empty_str, s21_strlen(empty_str));

  if (result_str != S21_NULL) free(result_str);
  if (empty_str != S21_NULL) free(empty_str);
}

void process_g_specifier(char *buffer, va_list args, Options *options) {
  long double value = get_float_value(options, args);
  char *prefix = add_prefix((value < 0), options);
  char *str = long_double_to_string_g_specifier(fabsl(value), options);
  char *back_space_str = make_back_space_str(options, s21_strlen(str));

  if (!options->left_justification && (value == value) && (str != S21_NULL)) {
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
    s21_strncat(buffer, prefix, s21_strlen(prefix));
    if (value != 0) {
      s21_strncat(buffer, str, s21_strlen(str));
    } else {
      s21_strncat(buffer, "0", 1);
    }
  }
  if (options->left_justification && (value == value) && (str != S21_NULL)) {
    s21_strncat(buffer, prefix, s21_strlen(prefix));
    if (value != 0) {
      s21_strncat(buffer, str, s21_strlen(str));
    } else {
      s21_strncat(buffer, "0", 1);
    }
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
  }
  if (value != value) {  // так проверяем является ли value значением nan
    s21_strncat(buffer, "nan", 3);
  }

  if (str != S21_NULL) free(str);
  if (prefix != S21_NULL) free(prefix);
  if (back_space_str != S21_NULL) free(back_space_str);
}

void process_x_specifier(char *buffer, va_list args, Options *options) {
  void *ptr = va_arg(args, void *);
  unsigned long value = (unsigned long)ptr;
  char *back_space_str;

  char *hex_str = uint_to_hex_str(value, options->upper_case, options);
  char *empty_str = make_empty_str(options, s21_strlen(hex_str));

  if (options->alternative_form && value != 0) {
    back_space_str =
        make_back_space_str(options, s21_strlen(empty_str) + s21_strlen("x") +
                                         s21_strlen("0") + s21_strlen(hex_str));
  } else {
    back_space_str = make_back_space_str(
        options, s21_strlen(empty_str) + s21_strlen(hex_str));
  }

  if (!options->left_justification && (empty_str != S21_NULL)) {
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
    if (options->alternative_form && value != 0) {
      if (options->upper_case == false) {
        s21_strncat(buffer, "0", 1);
        s21_strncat(buffer, "x", 1);
      } else {
        s21_strncat(buffer, "0", 1);
        s21_strncat(buffer, "X", 1);
      }
    }
    s21_strncat(buffer, empty_str, s21_strlen(empty_str));
    s21_strncat(buffer, hex_str, s21_strlen(hex_str));
  }

  if (options->left_justification && (empty_str != S21_NULL)) {
    if (options->alternative_form && value != 0) {
      if (options->upper_case == false) {
        s21_strncat(buffer, "0", 1);
        s21_strncat(buffer, "x", 1);
      } else {
        s21_strncat(buffer, "0", 1);
        s21_strncat(buffer, "X", 1);
      }
    }
    s21_strncat(buffer, empty_str, s21_strlen(empty_str));
    s21_strncat(buffer, hex_str, s21_strlen(hex_str));
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
  }

  if (hex_str != S21_NULL) free(hex_str);
  if (empty_str != S21_NULL) free(empty_str);
  if (back_space_str != S21_NULL) free(back_space_str);
}

void process_p_specifier(char *buffer, va_list args, Options *options) {
  void *ptr = va_arg(args, void *);
  long long value = (long long)ptr;
  char *prefix = add_prefix((value < 0), options);

  char *hex_str = uint_to_hex_str(value, options->upper_case, options);

  char *empty_str = make_empty_str(options, s21_strlen(hex_str));

  char *back_space_str = make_back_space_str(
      options, s21_strlen(prefix) + s21_strlen(empty_str) + s21_strlen("x") +
                   s21_strlen("0") + s21_strlen(hex_str));

  if (!options->left_justification && (empty_str != S21_NULL) && (value != 0)) {
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
    s21_strncat(buffer, prefix, s21_strlen(prefix));
    s21_strncat(buffer, "0", 1);
    s21_strncat(buffer, "x", 1);
    s21_strncat(buffer, empty_str, s21_strlen(empty_str));
    s21_strncat(buffer, hex_str, s21_strlen(hex_str));
  }
  if (options->left_justification && (empty_str != S21_NULL) && (value != 0)) {
    s21_strncat(buffer, prefix, s21_strlen(prefix));
    s21_strncat(buffer, "0", 1);
    s21_strncat(buffer, "x", 1);
    s21_strncat(buffer, empty_str, s21_strlen(empty_str));
    s21_strncat(buffer, hex_str, s21_strlen(hex_str));
    s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
  }
  if (value == 0) {
    s21_strncat(buffer, "(nil)", 5);
  }
  if (prefix != S21_NULL) free(prefix);
  if (hex_str != S21_NULL) free(hex_str);
  if (empty_str != S21_NULL) free(empty_str);
  if (back_space_str != S21_NULL) free(back_space_str);
}

void process_o_specifier(char *buffer, va_list args, Options *options) {
  long long int value = va_arg(args, long long int);
  char *int_str;
  char str[100] = {0};
  if (value != 0) {
    while (value != 0) {
      int_str = int_to_str(value % 8);
      s21_strncat(str, int_str, 1);
      value = value / 8;
      if (int_str != S21_NULL) free(int_str);
    }
    reverse_string(str);
  } else {
    s21_strncat(str, "0", 1);
  }
  char *empty_str = make_empty_str(options, s21_strlen(str));
  char *back_space_str =
      make_back_space_str(options, s21_strlen(empty_str) + s21_strlen(str));
  if (!options->left_justification && (empty_str != S21_NULL)) {
    if (options->alternative_form && s21_strlen(empty_str) == 0) {
      if (s21_strlen(back_space_str) != 0) {
        s21_strncat(buffer, back_space_str, s21_strlen(back_space_str) - 1);
      } else {
        s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
      }
      s21_strncat(buffer, "0", 1);
    } else {
      s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
      s21_strncat(buffer, empty_str, s21_strlen(empty_str));
    }
    s21_strncat(buffer, str, s21_strlen(str));
  }
  if (options->left_justification && (empty_str != S21_NULL)) {
    if (options->alternative_form && s21_strlen(empty_str) == 0) {
      s21_strncat(buffer, "0", 1);
      s21_strncat(buffer, str, s21_strlen(str));
      if (s21_strlen(back_space_str) != 0) {
        s21_strncat(buffer, back_space_str, s21_strlen(back_space_str) - 1);
      } else {
        s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
      };
    } else {
      s21_strncat(buffer, empty_str, s21_strlen(empty_str));
      s21_strncat(buffer, str, s21_strlen(str));
      s21_strncat(buffer, back_space_str, s21_strlen(back_space_str));
    }
  }
  if (empty_str != S21_NULL) free(empty_str);
  if (back_space_str != S21_NULL) free(back_space_str);
}

void process_n_specifier(char *buffer, va_list args) {
  s21_strncat(buffer, "\0", 1);
  long long *value = value = va_arg(args, long long int *);
  *value = s21_strlen(buffer);
}