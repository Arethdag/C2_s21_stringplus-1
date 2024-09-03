#include "helpers/s21_func_for_sscanf.h"
#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  struct specifier spec = {
      .flag = "", .width = "", .precision = "", .length = "", .type = '\0'};
  int success = 0, count_successes = 0;
  const char *types = "cdieEfgGosuxXpn%%";
  char *string = malloc((s21_strlen(str) + 1) * sizeof(char));
  s21_memset(string, '\0', (s21_strlen(str) + 1) * sizeof(char));
  s21_strcpy(string, str);

  if ((string[0] == '\0' || s21_empty_str(string)) && format[0] != '\0' &&
      s21_strcspn(format, types))
    count_successes = -1;
  int j = 0;
  if (!s21_empty_str(string) && string[0] != '\0') {
    for (size_t index = 0;
         index < s21_strlen(format) && (size_t)j < s21_strlen(string);
         index++, j++) {
      specifier_init(&spec);
      if (s21_isspace(format[index]) || format[index + 1] == '%')
        while (s21_isspace(string[j])) j++;
      while (s21_isspace(format[index])) index++;
      if ((format[index] == '%' && format[index + 1] == '%' &&
           string[j] == '%'))
        index++;
      else if (format[index] == '%' && string[j] == '%')
        continue;
      else if (format[index] == '%' && string[j]) {
        specifier_parsing((char *)(format + index + 1), &spec);
        index += s21_strcspn((format + index + 1), types) + 1;
        while (s21_isspace(string[j]) && format[index] != 'c') j++;
        success = match_str_and_format(string, &spec, &ap, &j);
        if (success) {
          count_successes++;
          if (spec.width[0] == '*') count_successes--;
        } else if (!success &&
                   (spec.type == 'i' || spec.type == 'd' || spec.type == 'u' ||
                    spec.type == 'o' || spec.type == 'x' || spec.type == 'X'))
          break;
        j--;
      }
    }

    if (format[s21_strlen(format) - 1] == 'n') {
      spec.type = 'n';
      match_str_and_format(string, &spec, &ap, &j);
    }
  }
  if (s21_empty_str(string) && s21_strlen(format) != 0) {
    int j = 0;
    for (size_t index = 0; index < s21_strlen(format); index++) {
      specifier_parsing((char *)(format + index + 1), &spec);
      index += s21_strcspn((format + index + 1), types) + 1;
      if (spec.type != 'd') {
        success = match_str_and_format(string, &spec, &ap, &j);
      } else
        success = 0;
      if (success && s21_strlen(string) != 0)
        count_successes++;
      else
        count_successes--;
    }
  }
  va_end(ap);
  free(string);
  return count_successes;
}

void specifier_parsing(char *format, struct specifier *spec) {
  char *format_buff = format;
  char *buffer = malloc(1024);
  s21_memset(buffer, '\0', 1024);
  const char *flags_numbers = "1234567890*";
  const char *flag_length = "hlL";
  const char *specificator = "cdieEfgGosuxXpn%%";

  spec->type = format[s21_strcspn(format, specificator)];
  pointer_shift(&format_buff, buffer, flags_numbers);
  numbers_parsing(spec->width, buffer);

  s21_memcpy(buffer, format_buff,
             s21_strspn((const char *)format_buff, flag_length));

  flag_length_parsing(buffer, flag_length, spec);

  free(buffer);
}

void numbers_parsing(char *str, char *buff) {
  size_t length = s21_strspn((const char *)buff, "1234567890");
  if (*buff == '*' && length == 0) {
    length = 1;
  }
  s21_strcpy(str, buff);
  buff[length + 1] = '\0';
}
// добавляем в buffer из format_buff начальные совп. подстроки с str
void pointer_shift(char **format_buff, char *buffer, const char *flags) {
  size_t length = s21_strspn((const char *)*format_buff, flags);
  s21_strncpy(buffer, *format_buff, length);
  buffer[length] = '\0';
  *format_buff += length;
}
// инициализация элементов struct specifier нолями
void specifier_init(struct specifier *spec) {
  spec->flag[0] = '\0';
  spec->width[0] = '\0';
  spec->precision[0] = '\0';
  spec->length[0] = '\0';
  spec->type = 0;
}
// d Знаковое десятичное целое числоs
int read_d(char *string, va_list *ap, struct specifier *spec, int *j) {
  int success = 0;
  int step = 0;
  while (s21_isdigit(string[*j + step])) {
    if (step > 0 && (string[*j + step] == '-' || string[*j + step] == '+')) {
      break;
    }
    step++;
  }

  if (s21_atoi(spec->width) != 0 && s21_atoi(spec->width) < step) {
    step = s21_atoi(spec->width);
  }

  char *number = malloc(step + 1);
  s21_memset(number, '\0', step + 1);
  s21_strncpy(number, string + *j, step);
  number[step] = '\0';

  if (spec->width[0] != '*') {
    if (s21_strcmp(spec->length, "l") == 0) {
      long int *d = va_arg(*ap, long int *);
      *d = s21_atol(number);

    } else if (s21_strcmp(spec->length, "ll") == 0) {
      long long int *d = va_arg(*ap, long long int *);
      *d = s21_atoll(number);

    } else if (s21_strcmp(spec->length, "h") == 0) {
      short int *d = va_arg(*ap, short int *);
      *d = s21_atoi(number);
    } else {
      int *d = va_arg(*ap, int *);
      *d = s21_atoi(number);
    }

    if (number &&
        (s21_atol(number) || s21_atoll(number) || s21_atoi(number) ||
         ((s21_strcmp(number, "0") == 0 || s21_strcmp(number, "-0") == 0 ||
           s21_strcmp(number, "+0") == 0) &&
          s21_atoi(number) == 0))) {
      success = 1;
    }

  } else if (number) {
    success = 1;
  }
  free(number);
  *j += step;

  return success;
}

// s строка символов
int read_s(char *str, va_list *ap, struct specifier *spec, int *j) {
  int success = 0;
  int step = 0;

  while (str[*j + step] != '\0' && !s21_isspace(str[*j + step])) {
    step++;
  }

  if (s21_atoi(spec->width) != 0 && s21_atoi(spec->width) < step) {
    step = s21_atoi(spec->width);
  }

  if (step > 0 && spec->width[0] != '*') {
    char *string = malloc(step + 1);
    s21_memset(string, '\0', step + 1);
    s21_strncpy(string, str + *j, step);
    string[step] = '\0';

    char *s = va_arg(*ap, char *);
    s21_strcpy(s, string);

    if (s) {
      success++;
    }

    free(string);
  }
  *j += step;
  return success;
}

// с символ
int read_c(char *str, va_list *ap, struct specifier *spec, int *j) {
  int success = 0;
  if (spec->width[0] != '*') {
    char *c = va_arg(*ap, char *);
    *c = str[*j];
    // printf("323..%s\n", c);
    if (c) {
      success = 1;
    }
  }
  (*j)++;

  return success;
}

// u Беззнаковое десятичное целое число
int read_u(char *str, va_list *ap, struct specifier *spec, int *j) {
  char *end = NULL;
  int success = 0;
  int step = 0;

  while (s21_isdigit(str[*j + step])) {
    if (step > 0 && (str[*j + step] == '-' || str[*j + step] == '+')) {
      break;
    }
    step++;
  }

  if (s21_atoi(spec->width) && s21_atoi(spec->width) < step) {
    step = s21_atoi(spec->width);
  }

  if (spec->width[0] != '*') {
    char *number = malloc(step + 1);
    s21_memset(number, '\0', step + 1);
    s21_strncpy(number, str + *j, step);
    number[step] = '\0';

    if (s21_strcmp(spec->length, "l") == 0) {
      unsigned long int *u = va_arg(*ap, unsigned long int *);
      *u = s21_strtoul(number, &end, 10);

    } else if (s21_strcmp(spec->length, "ll") == 0) {
      unsigned long long int *u = va_arg(*ap, unsigned long long int *);
      *u = s21_strtoull(number, &end, 10);

    } else {
      unsigned int *u = va_arg(*ap, unsigned int *);
      *u = s21_strtoul(number, &end, 10);
    }
    if (s21_strtoul(number, &end, 10) || s21_strcmp(number, "0") == 0) {
      success = 1;
    }
    free(number);
  }
  *j += step;
  return success;
}

// o Беззнаковое восьмеричное число
int read_o(char *str, va_list *ap, struct specifier *spec, int *j) {
  // char *end = NULL;
  int success = 0;
  int step = 0;

  while (s21_isoctal(str[*j + step])) {
    if (step > 0 && (str[*j + step] == '-' || str[*j + step] == '+')) {
      break;
    }
    step++;
  }

  if (s21_atoi(spec->width) && s21_atoi(spec->width) < step) {
    step = s21_atoi(spec->width);
  }

  if (spec->width[0] != '*') {
    char *copy = malloc(step + 1);
    s21_memset(copy, '\0', step + 1);
    s21_strncpy(copy, str + *j, step);
    copy[step] = '\0';

    if (s21_strcmp(spec->length, "l") == 0) {
      long int *d = va_arg(*ap, long int *);
      *d = s21_strtol(copy, 8);

    } else if (s21_strcmp(spec->length, "ll") == 0) {
      long long *d = va_arg(*ap, long long *);
      *d = s21_strtol(copy, 8);

    } else if (s21_strcmp(spec->length, "h") == 0) {
      short *d = va_arg(*ap, short *);
      *d = s21_strtol(copy, 8);

    } else {
      int *d = va_arg(*ap, int *);
      *d = s21_strtol(copy, 8);
    }
    if (s21_strtol(copy, 8) || (copy[0] == '0')) {
      success = 1;
    }
    free(copy);
  }
  *j += step;
  return success;
}

// Беззнаковое шестнадцатеричное целое число (любые буквы)
int read_xX(char *str, va_list *ap, struct specifier *spec, int *j) {
  int step = 0;
  int success = 0;

  while (str[*j + step] != '\0' && !s21_isspace(str[*j + step]) &&
         str[*j + step] != '%' && s21_ishex(str[*j + step])) {
    step++;
  }

  if (s21_atoi(spec->width) && s21_atoi(spec->width) < step) {
    step = s21_atoi(spec->width);
  }
  if (spec->width[0] != '*') {
    char *copy = malloc(step + 1);
    s21_memset(copy, '\0', step + 1);
    s21_strncpy(copy, str + *j, step);
    copy[step] = '\0';

    if (s21_strcmp(spec->length, "l") == 0) {
      unsigned long int *x = va_arg(*ap, unsigned long int *);
      *x = s21_strtol(copy, 16);

    } else if (s21_strcmp(spec->length, "ll") == 0) {
      unsigned long long int *x = va_arg(*ap, unsigned long long int *);
      *x = s21_strtol(copy, 16);

    } else {
      unsigned int *x = va_arg(*ap, unsigned int *);
      *x = s21_strtol(copy, 16);
    }

    if (copy[0] != '\0') {
      success = 1;
    }
    free(copy);
  }
  *j += step;
  return success;
}

int read_p(char *str, va_list *ap, struct specifier *spec, int *j) {
  int step = 0;
  int success = 0;

  while (str[*j + step] != '\0' && !s21_isspace(str[*j + step]) &&
         str[*j + step] != '%' && s21_ishex(str[*j + step])) {
    step++;
  }

  if (s21_atoi(spec->width) && s21_atoi(spec->width) < step) {
    step = s21_atoi(spec->width);
  }

  if (spec->width[0] != '*') {
    char *copy = malloc(step + 1);
    s21_memset(copy, '\0', step + 1);
    s21_strncpy(copy, str + *j, step);
    copy[step] = '\0';

    void **p = va_arg(*ap, void **);
    int long result = s21_strtol(copy, 16);
    *p = (void *)result;

    if ((copy[0] != '\0')) {
      success = 1;
    }
    free(copy);
  }
  *j += step;
  return success;
}

int read_f(char *str, va_list *ap, struct specifier *spec, int *j) {
  int step = 0;
  int success = 0;

  while (str[*j + step] != '\0' && !s21_isspace(str[*j + step]) &&
         str[*j + step] != '%') {
    step++;
  }

  if (s21_atoi(spec->width) && s21_atoi(spec->width) < step) {
    step = s21_atoi(spec->width);
  }

  if (spec->width[0] != '*') {
    char *copy = malloc(step + 1);
    s21_memset(copy, '\0', step + 1);
    s21_strncpy(copy, str + *j, step);
    copy[step] = '\0';

    if (s21_strcmp(spec->length, "L") == 0) {
      long double *f = va_arg(*ap, long double *);
      *f = s21_atold(copy);

    } else if (s21_strcmp(spec->length, "l") == 0) {
      double *f = va_arg(*ap, double *);
      *f = s21_atold(copy);

    } else {
      float *f = va_arg(*ap, float *);
      *f = s21_atold(copy);
    }

    if (s21_atold(copy) || (copy[0] == '0')) {
      success = 1;
    }
    free(copy);
  }
  *j += step;
  return success;
}

// Знаковое целое число (может быть десятичным, восьмеричным или
// шестнадцатеричным)
int read_i(char *str, va_list *ap, struct specifier *spec, int *j) {
  int step = 0;
  int success = 0;
  while (str[*j + step] != '\0' && !s21_isspace(str[*j + step]) &&
         str[*j + step] != '%') {
    step++;
  }
  if (s21_atoi(spec->width) && s21_atoi(spec->width) < step) {
    step = s21_atoi(spec->width);
  }
  if (spec->width[0] != '*') {
    char *copy = malloc(step + 1);
    s21_memset(copy, '\0', step + 1);
    s21_strncpy(copy, str + *j, step);
    copy[step] = '\0';
    int sign = 0;
    if (copy[0] == '-') {
      sign = 1;
    }
    if (copy[sign] != '0') {
      success = read_d(str, ap, spec, j);
    } else {
      if (copy[1 + sign] == 'x' || copy[1 + sign] == 'X') {
        success = read_xX(str, ap, spec, j);
      } else {
        success = read_o(str, ap, spec, j);
      }
    }
    if (s21_atoll(copy) || s21_strtol(copy, 16) || s21_strtol(copy, 8) ||
        (copy[0] == '0'))
      success = 1;
    free(copy);
  }
  return success;
}

int match_str_and_format(char *str, struct specifier *spec, va_list *ap,
                         int *j) {
  int success = 0;
  switch (spec->type) {
    case 'd':;
      success = read_d(str, ap, spec, j);
      break;
    case 'c':;
      success = read_c(str, ap, spec, j);
      break;
    case 'i':;
      success = read_i(str, ap, spec, j);
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      success = read_f(str, ap, spec, j);
      break;
    case 'o':
      success = read_o(str, ap, spec, j);
      break;
    case 's':;
      success = read_s(str, ap, spec, j);
      break;
    case 'u':;
      success = read_u(str, ap, spec, j);
      break;
    case 'x':;
      success = read_xX(str, ap, spec, j);
      break;
    case 'X':;
      success = read_xX(str, ap, spec, j);
      break;
    case 'p':;
      success = read_p(str, ap, spec, j);
      break;
    case 'n':;
      int *n = va_arg(*ap, int *);
      *n = *j;
      break;
  }
  return success;
}

void flags_parsing(char *buffer, const char *flags, struct specifier *spec) {
  int k = 0;

  for (int step = 0; step < (int)s21_strlen(flags); step++) {
    if (s21_strchr(buffer, flags[step]) != NULL &&
        ((flags[step] == ' ' && s21_strchr(buffer, '+') == NULL) ||
         (flags[step] == '0' && s21_strchr(buffer, '-') == NULL) ||
         flags[step] == '-' || flags[step] == '+' || flags[step] == '#')) {
      spec->flag[k++] = flags[step];
    }
  }

  spec->flag[k] = '\0';
}

void flag_length_parsing(char *buffer, const char *flag_length,
                         struct specifier *spec) {
  int k = 0;

  for (int step = 0; step < (int)s21_strlen(flag_length); step++) {
    char *c = s21_strchr(buffer, flag_length[step]);
    if (c != NULL) {
      if (flag_length[step] == 'L' ||
          (flag_length[step] == 'h' &&
           (c < s21_strchr(buffer, 'l') || s21_strchr(buffer, 'l') == NULL)) ||
          (flag_length[step] == 'l' &&
           s21_strchr(c + 1, flag_length[step]) == NULL &&
           spec->length[0] != 'h')) {
        spec->length[k++] = flag_length[step];

      } else if (flag_length[step] == 'l' &&
                 s21_strchr(c + 1, flag_length[step]) != NULL &&
                 spec->length[0] != 'h') {
        spec->length[k++] = flag_length[step];
        spec->length[k++] = flag_length[step];
      }
    }
  }
  spec->length[k] = '\0';
}
