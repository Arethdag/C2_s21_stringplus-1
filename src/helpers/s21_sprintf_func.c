#include "s21_sprintf_func.h"

char *int_to_str(long long value) {
  if (value == 0) {
    char *zero_str = (char *)malloc(2);
    if (zero_str == S21_NULL) {
      return S21_NULL;
    }
    zero_str[0] = '0';
    zero_str[1] = '\0';
    return zero_str;
  }
  long long temp = value;
  int charecters_number = 0;

  while (temp != 0) {
    charecters_number++;
    temp /= 10;
  }
  char *result = (char *)malloc(sizeof(char) * (charecters_number + 2));
  if (result == S21_NULL) {
    return S21_NULL;
  }
  s21_memset(result, '\0', charecters_number + 2);
  result[charecters_number + 1] = '\0';
  int i = charecters_number - 1;

  while (value != 0) {
    result[i--] = (value % 10) + '0';
    value /= 10;
  }
  return result;
}

char *double_to_enotation(long double value, Options *options) {
  char *result_str;
  char *prefix = add_prefix((value < 0), options);

  long double mantissa = fabsl(value);
  int exponent = 0;
  while (mantissa >= 10) {
    mantissa = mantissa / 10;
    exponent++;
  }
  while (mantissa < 1 && mantissa > 0) {
    mantissa = mantissa * 10;
    exponent--;
  }
  char exponent_sign = (exponent >= 0) ? '+' : '-';
  // полученные значения преобразуем в строки
  char *mantissa_str = long_double_to_string_e(mantissa, options);
  char *exponent_str = exp_int_to_str(exponent);
  // выделяем память для записи в 1 результирующую строку
  s21_size_t result_str_len = s21_strlen(prefix) + s21_strlen(mantissa_str) +
                              s21_strlen(exponent_str) + (sizeof(char) * 4);
  result_str = (char *)malloc(result_str_len);
  if (result_str == S21_NULL) {
    options->has_error = true;
    return S21_NULL;
  }
  s21_memset(result_str, '\0', result_str_len);

  char *result_str_ptr = result_str;

  s21_strncat(result_str_ptr, prefix, s21_strlen(prefix));
  s21_strncat(result_str_ptr, mantissa_str, s21_strlen(mantissa_str));

  while (*result_str_ptr != '\0') {
    result_str_ptr++;
  }
  *result_str_ptr = options->has_big_E_character ? 'E' : 'e';
  result_str_ptr++;
  *result_str_ptr = exponent_sign;
  s21_strncat(result_str_ptr, exponent_str, s21_strlen(exponent_str));

  if (mantissa_str != S21_NULL) free(mantissa_str);
  if (exponent_str != S21_NULL) free(exponent_str);
  if (prefix != S21_NULL) free(prefix);

  return result_str;
}

char *add_prefix(bool is_negative_value, Options *options) {
  char *prefix = (char *)malloc(2 * sizeof(char));
  if (prefix == S21_NULL) return S21_NULL;
  prefix[0] = '\0';
  prefix[1] = '\0';

  if (is_negative_value)
    prefix[0] = '-';
  else if (options->show_plus)
    prefix[0] = '+';
  else if (options->blank_space)
    prefix[0] = ' ';
  return prefix;
}

char *make_empty_str(Options *options, s21_size_t already_filled_length) {
  char empty_zero = '0';
  s21_size_t empty_str_len_zero = 0;
  char *str;

  if (options->precision_description &&
      options->precision_description >= (int)already_filled_length) {
    empty_str_len_zero =
        (s21_size_t)options->precision_description - already_filled_length;
  }
  str = (char *)malloc(empty_str_len_zero + 1);
  if (str == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size_t i = 0; i < empty_str_len_zero; i++) {
    str[i] = empty_zero;
  }
  str[empty_str_len_zero] = '\0';

  return str;
}

int make_empty_str_str(Options *options, s21_size_t already_filled_length) {
  int length_str = 0;

  if (options->precision_description <= (int)already_filled_length &&
      options->precision_description != 0) {
    length_str = options->precision_description;
  } else {
    length_str = already_filled_length;
  }
  return length_str;
}

char *make_back_space_str(Options *options, s21_size_t already_filled_length) {
  char empty_back = ' ';
  s21_size_t empty_back_space = 0;
  char *str;

  if ((options->precision_description <= options->width_description) &&
      options->width_description >= (int)already_filled_length) {
    empty_back_space =
        (s21_size_t)options->width_description - already_filled_length;
  }
  str = (char *)malloc(empty_back_space + 1);
  if (str == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size_t i = 0; i < empty_back_space; i++) {
    str[i] = empty_back;
  }
  str[empty_back_space] = '\0';
  return str;
}

long double get_float_value(Options *options, va_list args) {
  long double value;
  if (options->long_double)
    value = va_arg(args, long double);
  else if (options->long_opt)
    value = va_arg(args, double);
  else if (options->short_opt)
    value = (float)va_arg(args, double);
  else
    value = (float)va_arg(args, double);
  return value;
}

long long get_int_value(Options *options, va_list args) {
  long long value;
  if (options->long_opt) {
    value = va_arg(args, long long int);
  } else if (options->short_opt) {
    value = (short int)va_arg(args, int);
  } else {
    value = va_arg(args, int);
  }
  return value;
}

unsigned long long get_unsigned_int_value(Options *options, va_list args) {
  unsigned long long value;
  if (options->long_opt)
    value = va_arg(args, unsigned long int);
  else if (options->short_opt)
    value = (unsigned short int)va_arg(args, int);
  else
    value = va_arg(args, unsigned int);
  return value;
}

char *exp_int_to_str(int value) {
  if (value < 0) value *= -1;

  char *str = (char *)malloc(sizeof(char) * 3);
  if (str == S21_NULL) return S21_NULL;

  s21_memset(str, '0', 3);
  str[2] = '\0';

  int i = 1;
  while (value != 0) {
    str[i--] = (value % 10) + '0';
    value /= 10;
  }
  return str;
}

char *uint_to_hex_str(long long value, bool uppercase, Options *options) {
  static const char *digits_lower = "0123456789abcdef";
  static const char *digits_upper = "0123456789ABCDEF";
  const char *digits = uppercase ? digits_upper : digits_lower;

  long long temp = value;
  int hex_digits = 0;
  temp = labs(value);
  do {
    temp >>=
        4;  // побитовый сдвиг temp на 4 бита вправото же самое temp = temp / 16
    hex_digits++;
  } while (temp > 0);
  if ((long long)value < 0) {
    hex_digits = hex_digits + 1;
    while (hex_digits % 8 != 0) {
      hex_digits = hex_digits + 1;
    }
  }
  if (options->short_opt == true && hex_digits > 4) {
    hex_digits = hex_digits / 2;
  }
  char *result = (char *)malloc(hex_digits + 1);
  if (result == S21_NULL) {
    return S21_NULL;
  }
  s21_memset(result, '\0', hex_digits + 1);

  for (int i = hex_digits - 1; i >= 0; i--) {
    result[i] = digits[value & 0xF];
    value >>= 4;  // то же самое temp = temp / 16
  }
  return result;
}

void reverse_string(char *str) {
  if (str == NULL) return;

  int length = s21_strlen(str);
  for (int i = 0; i < length / 2; i++) {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
}

char *long_double_to_string_e(long double num, Options *options) {
  long long int_part;
  char *str = (char *)malloc(MAX_DIGITS * sizeof(char));

  if (str == S21_NULL) {
    return S21_NULL;
  }
  s21_memset(str, '\0', MAX_DIGITS);
  if ((options->precision_description == 0 && options->point == true) ||
      (options->precision_description == 1 && options->point == true)) {
    int_part = roundl(num);
  } else {
    int_part = (long long)num;
  }
  // перевод целой части числа в строку
  int i = 0;
  int stop;
  do {
    str[i++] = '0' + (int_part % 10);
    int_part = int_part / 10;
  } while (int_part != 0);

  // обращение строки, чтобы получить правильный порядок символов
  for (int j = 0; j < i / 2; j++) {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }

  // добавление десятичной точки
  str[i++] = '.';
  // перевод дробной части числа в строку
  long double fraction_part = num - (long long)num;
  if ((options->precision_description == 0 && options->point == false) ||
      (options->precision_description > 0 && options->point == false)) {
    stop = 6;
  } else if (options->precision_description == 0 && options->point == true) {
    stop = 0;
  } else {
    stop = options->precision_description;
  }
  long double nult = 1.0;
  for (int j = 0; j < stop; j++) {
    nult = fraction_part / pow(10.1, j);
  }
  for (int j = 0; j < stop; j++) {  // выводим до 6 знаков после запятой
    fraction_part =
        fraction_part * 10.0 + nult;  // для решения проблемы с округлением
    str[i++] = '0' + fmod(fraction_part, 10.0);
  }
  str[i] = '\0';
  if (str[i - 1] == '.' && options->alternative_form == false) {
    str[i - 1] = '\0';
  }
  return str;
}

char *long_double_to_string_g_specifier(long double num, Options *options) {
  char *str = (char *)malloc(MAX_DIGITS * sizeof(char));

  if (str == S21_NULL) {
    return S21_NULL;
  }
  s21_memset(str, '\0', MAX_DIGITS);
  // перевод целой части числа в строку
  long long int_part = (long long)num;
  int i = 0;
  int stop;
  do {
    str[i++] = '0' + (int_part % 10);
    int_part = int_part / 10;
  } while (int_part != 0);
  // обращение строки, чтобы получить правильный порядок символов
  for (int j = 0; j < i / 2; j++) {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }

  // добавление десятичной точки
  str[i++] = '.';
  // перевод дробной части числа в строку
  long double fraction_part = num - (long long)num;

  if ((options->precision_description == 1 && options->point == true) ||
      (options->precision_description == 0 && options->point == false &&
       (int)(s21_strlen(str) - 1) > 6) ||
      num < 0.000001) {
    char *result = double_to_enotation_g_specifier((long double)num, options);
    s21_strncpy(str, result, s21_strlen(result));
    free(result);
    return str;
    // stop = 0;
  } else if (options->precision_description >= (int)(s21_strlen(str) - 1)) {
    stop = options->precision_description - s21_strlen(str);
  } else {
    stop = 7 - s21_strlen(str);
  }

  long double nult = 1.0;
  for (int j = 0; j < stop; j++) {
    nult = fraction_part / pow(10.1, j);
  }

  for (int j = 0; j < stop; j++) {  // выводим до 6 знаков после запятой
    fraction_part =
        fraction_part * 10 + nult;  // для решения проблемы с округлением
    str[i] = '0' + ((long)fraction_part % 10);
    if (str[i] >= '1' && options->precision_description == 0 &&
        options->point == true) {
      i++;
      break;
    }
    i++;
  }

  if (str[i - 1] == '0' && options->precision_description == 0 &&
      options->alternative_form == false) {
    while (str[i - 1] == '0') {
      str[i - 1] = '\0';
      i--;
    }
  }
  str[i] = '\0';
  if (str[i - 1] == '.' && options->alternative_form == false) {
    str[i - 1] = '\0';
  }
  return str;
}

char *double_to_enotation_g_specifier(long double value, Options *options) {
  char *result_str;
  char *prefix = add_prefix((value < 0), options);

  long double mantissa = fabsl(value);
  int exponent = 0;
  // вычисляем значение мантиссы и экспонента
  while (mantissa >= 10) {
    mantissa = mantissa / 10;
    exponent++;
  }
  while (mantissa < 1 && mantissa > 0) {
    mantissa = mantissa * 10;
    exponent--;
  }
  char exponent_sign = (exponent >= 0) ? '+' : '-';
  // полученные значения преобразуем в строки
  char *mantissa_str = long_double_to_string_g(mantissa, options);
  char *exponent_str = exp_int_to_str(exponent);
  // выделяем память для записи в 1 результирующую строку
  s21_size_t result_str_len = s21_strlen(prefix) + s21_strlen(mantissa_str) +
                              s21_strlen(exponent_str) + (sizeof(char) * 4);
  result_str = (char *)malloc(result_str_len);
  if (result_str == S21_NULL) {
    options->has_error = true;
    return S21_NULL;
  }
  s21_memset(result_str, '\0', result_str_len);

  char *result_str_ptr = result_str;

  s21_strncat(result_str_ptr, prefix, s21_strlen(prefix));
  s21_strncat(result_str_ptr, mantissa_str, s21_strlen(mantissa_str));

  while (*result_str_ptr != '\0') {
    result_str_ptr++;
  }
  *result_str_ptr = options->has_big_E_character ? 'E' : 'e';
  result_str_ptr++;
  *result_str_ptr = exponent_sign;
  s21_strncat(result_str_ptr, exponent_str, s21_strlen(exponent_str));

  if (mantissa_str != S21_NULL) free(mantissa_str);
  if (exponent_str != S21_NULL) free(exponent_str);
  if (prefix != S21_NULL) free(prefix);

  return result_str;
}

char *long_double_to_string_g(long double num, Options *options) {
  char *str = (char *)malloc(MAX_DIGITS * sizeof(char));

  if (str == S21_NULL) {
    return S21_NULL;
  }
  s21_memset(str, '\0', MAX_DIGITS);
  // перевод целой части числа в строку
  long long int_part = (long long)(num);
  int i = 0;
  int stop;
  do {
    str[i++] = '0' + (int_part % 10);
    int_part = int_part / 10;
  } while (int_part != 0);
  // обращение строки, чтобы получить правильный порядок символов
  for (int j = 0; j < i / 2; j++) {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }
  // добавление десятичной точки
  str[i++] = '.';
  // перевод дробной части числа в строку
  long double fraction_part = num - (long long)num;
  if (options->precision_description == 1 && options->point == true) {
    stop = 0;
  } else {
    stop = 5;
  }
  long double nult = 1.0;
  for (int j = 0; j < stop; j++) {
    nult = fraction_part / pow(10.1, j);
  }
  for (int j = 0; j < stop; j++) {  // выводим до 6 знаков после запятой
    fraction_part =
        fraction_part * 10 + nult;  // для решения проблемы с округлением
    str[i++] = '0' + ((long)fraction_part % 10);
  }
  str[i] = '\0';
  if (str[i - 1] == '.' && options->alternative_form == false &&
      options->point == true) {
    str[i - 1] = '\0';
  }
  return str;
}

char *long_double_to_string_f(long double num, Options *options) {
  char *str = (char *)malloc(MAX_DIGITS * sizeof(char));

  if (str == S21_NULL) {
    return S21_NULL;
  }
  s21_memset(str, '\0', MAX_DIGITS);
  // перевод целой части числа в строку
  long long int_part = (long long)num;
  int i = 0;
  int stop;
  do {
    str[i++] = '0' + (int_part % 10);
    int_part = int_part / 10;
  } while (int_part != 0);
  // обращение строки, чтобы получить правильный порядок символов
  for (int j = 0; j < i / 2; j++) {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }
  // добавление десятичной точки
  str[i++] = '.';
  // перевод дробной части числа в строку
  long double fraction_part = num - (long long)num;
  if (options->precision_description == 0 && options->point == false) {
    stop = 6;
  } else if (options->point == true && options->precision_description == 0) {
    stop = 1;
  } else if (options->point == true && options->precision_description == 1) {
    stop = 1;
  } else {
    stop = options->precision_description;
  }
  long double nult = 1.0;
  for (int j = 0; j < stop; j++) {
    nult = fraction_part / pow(10.1, j);
  }
  for (int j = 0; j < stop; j++) {  // выводим до 6 знаков после запятой
    fraction_part =
        fraction_part * 10.0 + nult;  // для решения проблемы с округлением
    str[i++] = '0' + fmod(fraction_part, 10.0);
  }

  if (str[i - 1] >= '5' && options->precision_description == 0 &&
      options->point == true) {
    str[i - 3] = str[i - 3] + 1;
    str[i - 2] = '\0';
  } else if ((str[i - 1] < '5' && options->precision_description == 0 &&
              options->point == true)) {
    str[i - 2] = '\0';
  } else {
    str[i] = '\0';
  }
  if (str[i - 1] == '.' && options->alternative_form == false) {
    str[i - 1] = '\0';
  }
  return str;
}