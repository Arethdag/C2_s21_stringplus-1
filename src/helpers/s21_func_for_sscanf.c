#include "s21_func_for_sscanf.h"

int s21_atoi(const char *str) {
  int result = 0;
  int sign = 1;

  while (*str == ' ' || *str == '\t' || *str == '\n') {
    str++;
  }

  if (s21_strlen(str) > 19 && *str == '-') {
    return 0;
  } else if (s21_strlen(str) > 19) {
    return -1;
  }

  if (*str == '-' || *str == '+') {
    if (*str == '-') sign = -1;
    str++;
  }

  while (isdigit((unsigned char)*str) && result <= INT_MAX &&
         s21_strlen(str) < 20) {
    int digit = *str - '0';

    result = result * 10 + digit;
    str++;
  }
  return result * sign;
}

int s21_empty_str(char *str) {
  int found_not_space = 1;
  int i = 0;

  while (str[i]) {
    if (!s21_isspace(str[i])) {
      found_not_space = 0;
    }
    i++;
  }
  return found_not_space;
}

int s21_isupper(char c) { return (c >= 'A' && c <= 'Z'); }

int s21_is_letter(char c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0);
}

int s21_isspace(char c) {
  return (c == ' ' || c == '\n' || c == '\t' ||
          c == '\r');  // вернет true 1 or 0
}

int s21_isdigit(char c) {
  return ((c >= '0' && c <= '9') || c == '-' || c == '+');
}

int s21_ishex(char c) {
  return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
          (c >= 'A' && c <= 'F') || c == 'x' || c == 'X' || c == '-' ||
          c == '+');
}

int s21_isoctal(char c) {
  return ((c >= '0' && c <= '7') || c == '-' || c == '+');
}

void s21_strcpy(char *dest, const char *src) {
  while (*src) {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
}

int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return *(unsigned char *)str1 - *(unsigned char *)str2;
}

size_t s21_strspn(const char *str1, const char *str2) {
  size_t len = 0;
  const char *ptr1 = str1;

  while (*ptr1) {
    const char *ptr2 = str2;
    int found = 0;

    while (*ptr2) {
      if (*ptr1 == *ptr2) {
        found = 1;
        break;
      }
      ptr2++;
    }

    if (!found) {
      break;
    }

    len++;
    ptr1++;
  }

  return len;
}

long s21_strtol(const char *str, int base) {
  int len = s21_strlen(str);
  long long result = 0;
  int power = 0;
  int start = 0;
  int isNegative = 0;
  int error_buf = 0;

  if (str[0] == '-') {
    isNegative = 1;
    start = 1;
  }

  for (int i = len - 1; i >= start; i--) {
    int digit = str[i];

    if (digit >= '0' && digit <= '9') {
      result += (digit - '0') * (long long)pow(base, power);

    } else if (digit >= 'A' && digit <= 'F') {
      result += (digit - 'A' + 10) * (long long)pow(base, power);

    } else if (digit >= 'a' && digit <= 'f') {
      result += (digit - 'a' + 10) * (long long)pow(base, power);

    } else if (digit == ' ') {
      continue;
    } else if (digit == 'x' || digit == 'X') {
      break;
    }

    if (result >= ((long)LONG_MAX / 8) || result <= ((long)LONG_MIN / 8)) {
      error_buf = 1;
      break;
    }
    power++;
  }
  if (error_buf && isNegative) {
    result = LONG_MIN;
  } else if (error_buf && !isNegative) {
    result = LONG_MAX;
  }

  if (isNegative) {
    result = -result;
  }
  return result;
}

unsigned long long s21_strtoull(const char *nptr, char **endptr,
                                register int base) {
  register const char *s = nptr;
  register unsigned long long acc;
  register int c;
  register unsigned long long cutoff;
  register int negativativ_number = 0;
  register int any;
  register int cutlim;

  /*пропуск пробелов в начале*/
  do {
    c = *s++;
  } while (s21_isspace(c));

  /*определение строковое число c - или  +*/
  if (c == '-') {
    negativativ_number = 1;
    c = *s++;
  } else if (c == '+') {
    c = *s++;
  }

  /*определение основания системы счисления*/
  if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
    c = s[1];
    s += 2;
    base = 16;
  }
  if (base == 0) {
    base = (c == '0' ? 8 : 10);
  }

  cutoff = (unsigned long long)ULLONG_MAX / (unsigned long long)base;
  cutlim = (unsigned long long)ULLONG_MAX % (unsigned long long)base;

  for (acc = 0, any = 0;; c = *s++) {
    if (s21_isdigit(c)) {
      c -= '0';
    } else if (s21_is_letter(c)) {
      c -= s21_isupper(c) ? 'A' - 10 : 'a' - 10;
    } else {
      break;
    }

    if (c >= base) {
      break;
    }
    if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
      any = -1;
    else {
      any = 1;
      acc *= base;
      acc += c;
    }
  }

  if (any < 0) {
    acc = ULLONG_MAX;
    errno = ERANGE;
  } else if (negativativ_number) {
    acc = -acc;
  }
  if (endptr != 0) {
    *endptr = (char *)(any ? s - 1 : nptr);
  }
  return (acc);
}

unsigned long s21_strtoul(const char *nptr, char **endptr, register int base) {
  register const char *str_numb = nptr;
  register unsigned long cutoff;
  register unsigned long result_numb;
  register int negativativ_number = 0;
  register int cutlim;
  register int any;
  register int c;

  /*пропуск пробелов в начале*/
  do {
    c = *str_numb++;
  } while (s21_isspace(c));

  if (c == '-') {
    negativativ_number = 1;
    c = *str_numb++;
  } else if (c == '+') {
    c = *str_numb++;
  }

  if ((base == 0 || base == 16) && (*str_numb == 'x' || *str_numb == 'X')) {
    c = str_numb[1];
    str_numb += 2;
    base = 16;
  }
  if (base == 0) {
    base = (c == '0' ? 8 : 10);
  }

  cutoff = (unsigned long)ULONG_MAX /
           (unsigned long)base;  // ULONG_MAX ((unsigned long)(~0L))
  cutlim =
      (unsigned long)ULONG_MAX % (unsigned long)base;  // остаток от деления

  for (result_numb = 0, any = 0;; c = *str_numb++) {
    if (s21_isdigit(c)) {
      c -= '0';

    } else if (s21_is_letter(c)) {
      c -= (s21_isupper(c) ? 'A' - 10 : 'a' - 10);
    } else {
      break;
    }

    if (c >= base) {
      break;
    }

    if (any < 0 || result_numb > cutoff ||
        (result_numb == cutoff && c > cutlim)) {
      any = -1;
    } else {
      any = 1;
      result_numb *= base;
      result_numb += c;
    }
  }

  if (any < 0) {
    result_numb = ULONG_MAX;
    errno = ERANGE;
  } else if (negativativ_number) {
    result_numb = -result_numb;
  }

  if (endptr != 0) {
    *endptr = (char *)(any ? str_numb - 1 : nptr);
  }

  return (result_numb);
}

long double s21_atold(char *str) {
  int sign = 1;
  int i = 0;
  long double inc = 0.1L;
  long double result = 0.L;

  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+') {
    i++;
  }

  while (str[i] != '.') {
    if (!(str[i] >= '0' && str[i] <= '9')) {
      break;
    } else {
      result = result * 10.L + str[i] - '0';
      i++;
    }
  }

  if (str[i] == '.') {
    i++;
  }

  while (str[i]) {
    if (!(str[i] >= '0' && str[i] <= '9')) {
      break;
    } else {
      result = result + (str[i] - '0') * inc;
      inc = inc / 10.L;
      i++;
    }
  }

  inc = 10.L;

  if (str[i] == 'e' || str[i] == 'E') {
    i++;
    if (str[i] == '-') {
      inc = 0.1L;
      i++;
    } else if (str[i] == '+') {
      inc = 10.L;
      i++;
    }

    int count = 0;
    while (str[i] >= '0' && str[i] <= '9') {
      count = count * 10.L + str[i] - '0';
      i++;
    }

    while (count) {
      result = result * inc;
      count--;
    }
  }
  return result * sign;
}

long long s21_atoll(const char *str) { return s21_strtol(str, 10); }

long s21_atol(const char *str) { return (s21_strtol(str, 10)); }