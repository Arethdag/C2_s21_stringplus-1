#include "s21_string.h"

#include "stdio.h"

#if defined(__APPLE__)
#define ERRORS_NUMBER 107
#define ERROR "Unknown error: "
static const char *error_messages[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full",
};

#elif defined(__linux__)
#define ERRORS_NUMBER 134
#define ERROR "Unknown error "
static const char *error_messages[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};
#endif

// 1. Поиск первого вхождения указанного символа в массиве.
void *s21_memchr(const void *str, int c, s21_size_t n) {
  bool char_is_found = false;
  const unsigned char *ptr = str;

  s21_size_t index = 0;
  while ((index < n) && !char_is_found) {
    if (ptr[index] == c) {
      char_is_found = true;
      ptr += index;
    }
    index++;
  }

  return char_is_found ? ((void *)ptr) : S21_NULL;
}
// 2. сравнение массивов.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  const unsigned char *_str1 = str1;
  const unsigned char *_str2 = str2;

  s21_size_t index = 0;
  while ((index < n) && result == 0) {
    result = _str1[index] - _str2[index];
    index++;
  }

  return result;
}
// 3. копирование непересекающихся массивов
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *_dest = dest;
  unsigned const char *_src = src;

  for (s21_size_t i = 0; i < n; i++) {
    _dest[i] = _src[i];
  }

  return ((void *)_dest);
}
// 4. заполнение массива указанными символами.
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;

  while (n--) *ptr++ = (unsigned char)c;

  return ((void *)str);
}
// 5. объединение строк c ограничением длины добавляемой строки.
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_index = 0;
  s21_size_t src_index = 0;

  while (dest[dest_index] != '\0') dest_index++;

  for (; src_index < n; src_index++) {
    dest[dest_index + src_index] = src[src_index];
  }

  dest[dest_index + src_index] = '\0';

  return dest;
}
// 6. поиск первого вхождения символа в строку
char *s21_strchr(const char *str, int c) {
  const char *result = S21_NULL;
  int x = s21_strlen(str) + 1;
  for (int i = 0; i < x; i++) {
    if (str[i] == c) {
      result = (str + i);
      break;
    }
  }
  return (char *)result;
}
// 7. сравнение строк с ограничением количества сравниваемых символов.
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;

  s21_size_t index = 0;
  while ((index < n) && result == 0) {
    result = str1[index] - str2[index];
    index++;
  }

  return result;
}
// 8. копирование строк c ограничением длины
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}
// 9. определение длины участка строки не содержащего указанные символы.
size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t index = 0;
  s21_size_t length = s21_strlen(str1);

  bool coincidence_is_found = false;
  while ((index < length) && !coincidence_is_found) {
    if (s21_strchr(str2, str1[index]) != S21_NULL) {
      coincidence_is_found = true;
    } else
      index++;
  }

  return index;
}
// 10. формирование сообщения об ошибке по коду ошибки.
char *s21_strerror(int errnum) {
  static char res[512] = {0};

  if (errnum >= 0 && errnum < ERRORS_NUMBER)
    s21_strncpy(res, error_messages[errnum],
                s21_strlen(error_messages[errnum]));
  else
    // TODO: возникают утечки из-за использования s21_printf
    s21_sprintf(res, "%s%d", ERROR, errnum);
  return res;
}
// 11. определение длины строки.
size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  while (str != NULL && str[length] != '\0') length++;

  return length;
}
// 12. поиск первого вхождения в строку символа из указанного множества.
char *s21_strpbrk(const char *str1, const char *str2) {
  const char *ptr = str1;

  bool coincidence_is_found = false;
  while (*ptr != '\0' && !coincidence_is_found) {
    if (s21_strchr(str2, *ptr) != S21_NULL)
      coincidence_is_found = true;
    else
      ptr++;
  }

  return coincidence_is_found ? (char *)ptr : S21_NULL;
}
// 13. поиск последнего вхождения символа в строку.
char *s21_strrchr(const char *str, int c) {
  int index = s21_strlen(str);
  const char *ptr = S21_NULL;

  bool coincidence_is_found = false;

  while ((index >= 0) && !coincidence_is_found) {
    if (str[index] == c) {
      coincidence_is_found = true;
      ptr = str + index;
    }
    index--;
  }

  return (char *)ptr;
}
// 14. поиск первого вхождения строки А в строку В.
char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t n = s21_strlen(needle);
  const char *ptr = haystack;

  bool coincidence_is_found = false;
  while (*ptr != '\0' && !coincidence_is_found) {
    if (s21_strncmp(ptr, needle, n) == 0)
      coincidence_is_found = true;
    else
      ptr++;
  }

  return coincidence_is_found ? (char *)ptr : S21_NULL;
}
// 15. разбиение строки на части по указанному разделителю.
char *s21_strtok(char *str, const char *delim) {
  static char *current_address;
  static char *str_end;

  char *token_start = S21_NULL;

  if (str) {
    str_end = str + s21_strlen(str);
    current_address = str;
  }

  if (current_address != str_end) {
    for (char *p = current_address; p < str_end; p++) {
      int token_length = s21_strcspn(p, delim);

      if (token_length != 0) {
        token_start = p;
        current_address = p + token_length;
        *current_address = '\0';

        break;
      }
    }
  }

  return token_start;
}
// MARK: PART 5
void *s21_to_upper(const char *str) {
  char *str_res = S21_NULL;

  if (str != S21_NULL) {
    str_res = malloc(sizeof(char) * (s21_strlen(str) + 1));
    s21_size_t str_ind = 0;
    for (str_ind = 0; str[str_ind] != '\0'; str_ind++) {
      if (str[str_ind] >= 'a' && str[str_ind] <= 'z')
        str_res[str_ind] = str[str_ind] - 32;
      else
        str_res[str_ind] = str[str_ind];
    }
    str_res[str_ind] = '\0';
  }
  return str_res;
}

void *s21_to_lower(const char *str) {
  char *str_res = S21_NULL;
  if (str != S21_NULL) {
    str_res = malloc(sizeof(char) * (s21_strlen(str) + 1));
    s21_size_t str_ind = 0;
    for (str_ind = 0; str[str_ind] != '\0'; str_ind++) {
      if (str[str_ind] >= 'A' && str[str_ind] <= 'Z')
        str_res[str_ind] = str[str_ind] + 32;
      else
        str_res[str_ind] = str[str_ind];
    }
    str_res[str_ind] = '\0';
  } else
    str_res = S21_NULL;
  return str_res;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == S21_NULL || str == S21_NULL || (start_index > s21_strlen(src)))
    return S21_NULL;
  s21_size_t srclen = s21_strlen(src);
  s21_size_t strlen = s21_strlen(str);
  s21_size_t newlen = srclen + strlen;

  char *newstr = (char *)malloc(newlen + 1);
  if (newstr == S21_NULL) return S21_NULL;

  s21_strncpy(newstr, src, start_index);
  s21_strncpy(newstr + start_index, str, strlen);
  s21_strncpy(newstr + start_index + strlen, src + start_index,
              srclen - start_index);
  newstr[newlen] = '\0';

  return newstr;
}

void *s21_trim(const char *src, const char *trim) {
  if (src == S21_NULL || trim == S21_NULL) return S21_NULL;

  const char *start = src;
  while (*start && s21_strchr(trim, *start)) start++;

  const char *end = src + s21_strlen(src) - 1;
  while (end > start && s21_strchr(trim, *end)) end--;

  size_t new_len = end - start + 1;

  char *new_str = malloc(new_len + 1);
  if (new_str == S21_NULL) return S21_NULL;

  s21_strncpy(new_str, start, new_len);
  new_str[new_len] = '\0';

  return new_str;
}
