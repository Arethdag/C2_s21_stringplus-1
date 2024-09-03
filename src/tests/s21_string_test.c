#include "../s21_string.h"

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

START_TEST(test_memchr_1) {
  char hello_string[] = "Hello, World!";
  void *test1 = memchr(hello_string, 'H', strlen(hello_string));
  void *_test1 = s21_memchr(hello_string, 'H', strlen(hello_string));
  ck_assert_ptr_eq(test1, _test1);
}
END_TEST

START_TEST(test_memchr_2) {
  char hello_string[] = "Hello, World!";

  // передать массив символов, в котором запрашиваемый символ отсутствует
  void *test2 = memchr(hello_string, 'z', strlen(hello_string));
  void *_test2 = s21_memchr(hello_string, 'z', strlen(hello_string));
  ck_assert_ptr_eq(test2, _test2);
}
END_TEST

START_TEST(test_memchr_3) {
  char hello_string[] = "Hello, World!";

  // Поиск символа в середине массива
  void *test3 = memchr(hello_string, 'W', strlen(hello_string));
  void *_test3 = s21_memchr(hello_string, 'W', strlen(hello_string));
  ck_assert_ptr_eq(test3, _test3);
}
END_TEST

START_TEST(test_memchr_4) {
  char hello_string[] = "Hello, World!";

  // Поиск символа в конце массива
  void *test4 = memchr(hello_string, '!', strlen(hello_string));
  void *_test4 = s21_memchr(hello_string, '!', strlen(hello_string));
  ck_assert_ptr_eq(test4, _test4);
}
END_TEST

START_TEST(test_memchr_5) {
  char hello_string[] = "Hello, World!";
  char empty[] = "";
  // Пустой массив
  void *test5 = memchr(empty, '!', strlen(hello_string));
  void *_test5 = s21_memchr(empty, '!', strlen(hello_string));
  ck_assert_ptr_eq(test5, _test5);
}
END_TEST

START_TEST(test_memchr_6) {
  char hello_string[] = "Hello, World!";

  // Поиск символа, повторяющегося несколько раз
  void *test6 = memchr(hello_string, 'o', strlen(hello_string));
  void *_test6 = s21_memchr(hello_string, 'o', strlen(hello_string));
  ck_assert_ptr_eq(test6, _test6);
}
END_TEST

// MEMCMP

START_TEST(test_memcmp_1) {
  char hello_string[] = "Hello, World!";
  // Тестирование на равные массивы
  int test1 = memcmp(hello_string, hello_string, strlen(hello_string));
  int _test1 = s21_memcmp(hello_string, hello_string, strlen(hello_string));
  ck_assert_int_eq(test1, _test1);
}
END_TEST

START_TEST(test_memcmp_2) {
  char hello_string[] = "Hello, World!";
  char neo_string[] = "Wake up, Neo!";
  // Тестирование на различающиеся массивы
  int test2 = memcmp(hello_string, neo_string, strlen(hello_string));
  int _test2 = s21_memcmp(hello_string, neo_string, strlen(hello_string));
  ck_assert_int_eq(test2, _test2);
}
END_TEST

START_TEST(test_memcmp_3) {
  char hello_string[] = "Hello, World!";
  char rabbit_string[] = "Follow for a white rabbit!";
  // Тестирование на разные длины массивов
  int test3 = memcmp(hello_string, rabbit_string, strlen(hello_string));
  int _test3 = s21_memcmp(hello_string, rabbit_string, strlen(hello_string));
  ck_assert_int_eq(test3, _test3);
}
END_TEST

START_TEST(test_memcmp_4) {
  char hello_string[] = "Hello, World!";
  char empty[] = "";
  // Граничные случаи
  int test4 = memcmp(hello_string, empty, strlen(hello_string));
  int _test4 = s21_memcmp(hello_string, empty, strlen(hello_string));
  ck_assert_int_eq(test4, _test4);
}
END_TEST

START_TEST(test_memcmp_5) {
  char hello_string[] = "Hello, World!";
  char special_string[] = "!.<./";
  char special_string_2[] = "#$-&";
  // Сравнение массивов с использованием специальных символов
  int test5 = memcmp(special_string, special_string_2, strlen(hello_string));
  int _test5 =
      s21_memcmp(special_string, special_string_2, strlen(hello_string));
  ck_assert_int_eq(test5, _test5);
}
END_TEST

// MEMCPY

START_TEST(test_memcpy_1) {
  char hello_string[] = "Hello, World!";
  char *goodbuy_string = "Adios, World";
  // Копирование данных из одной области памяти в другую
  void *test1 = memcpy(hello_string, goodbuy_string, strlen(hello_string));
  void *_test1 = s21_memcpy(hello_string, goodbuy_string, strlen(hello_string));
  ck_assert_ptr_eq(test1, _test1);
}
END_TEST

START_TEST(test_memcpy_2) {
  char hello_string[] = "Hello, World!";
  char *goodbuy_string = "Adios, World";
  // Копирование части данных из одной области памяти в другую
  void *test2 = memcpy(hello_string, goodbuy_string, (size_t)5);
  void *_test2 = s21_memcpy(hello_string, goodbuy_string, (s21_size_t)5);
  ck_assert_ptr_eq(test2, _test2);
}
END_TEST

START_TEST(test_memcpy_3) {
  char hello_string[] = "Hello, World!";
  char empty[] = "";
  // Копирование нулевой длины
  void *test3 = memcpy(hello_string, empty, strlen(hello_string));
  void *_test3 = s21_memcpy(hello_string, empty, strlen(hello_string));
  ck_assert_ptr_eq(test3, _test3);
}
END_TEST

START_TEST(test_memcpy_4) {
  char hello_string[] = "Hello, World!";
  char *goodbuy_string = "Adios, World";
  // Копирование данных в область, начинающуюся не с первого байта
  goodbuy_string++;
  void *test4 = memcpy(hello_string, goodbuy_string, strlen(hello_string));
  void *_test4 = s21_memcpy(hello_string, goodbuy_string, strlen(hello_string));
  ck_assert_ptr_eq(test4, _test4);
}
END_TEST

// MEMSET

START_TEST(test_memset_1) {
  int int_arr[10] = {0};

  // Тестирование заполнения нулями массива типа int.
  void *test1 = memset(int_arr, 0, sizeof(int) * 10);
  void *_test1 = s21_memset(int_arr, 0, 10);
  ck_assert_ptr_eq(test1, _test1);
}
END_TEST

START_TEST(test_memset_2) {
  char char_arr[10] = {0};

  // Тестирование заполнения нулями массива типа char.
  void *test2 = memset(char_arr, 0, sizeof(char) * 10);
  void *_test2 = s21_memset(char_arr, 0, 10);
  ck_assert_ptr_eq(test2, _test2);
}
END_TEST

START_TEST(test_memset_3) {
  float float_arr[10] = {0};

  // Тестирование заполнения нулями массива типа float.
  void *test3 = memset(float_arr, 0, sizeof(float) * 10);
  void *_test3 = s21_memset(float_arr, 0, 10);
  ck_assert_ptr_eq(test3, _test3);
}
END_TEST

START_TEST(test_memset_4) {
  double double_arr[10] = {0};

  // Тестирование заполнения нулями массива типа double.
  void *test4 = memset(double_arr, 0, sizeof(double) * 10);
  void *_test4 = s21_memset(double_arr, 0, 10);
  ck_assert_ptr_eq(test4, _test4);
}
END_TEST

START_TEST(test_memset_5) {
  unsigned int unint_arr[10] = {0};

  // Тестирование заполнения нулями массива типа unsigned int.
  void *test5 = memset(unint_arr, 0, sizeof(unsigned int) * 10);
  void *_test5 = s21_memset(unint_arr, 0, 10);
  ck_assert_ptr_eq(test5, _test5);
}
END_TEST

START_TEST(test_memset_6) {
  long int lint_arr[10] = {0};

  // Тестирование заполнения нулями массива типа long.
  void *test6 = memset(lint_arr, 0, sizeof(long int) * 10);
  void *_test6 = s21_memset(lint_arr, 0, 10);
  ck_assert_ptr_eq(test6, _test6);
}
END_TEST

// STRNCAT

START_TEST(test_strncat_1) {
  char hello_string[100] = "Hello, World!";
  char empty[100] = "";

  // Тестирование конкатенации двух строк в пустую целевую строку.
  char *test1 = strncat(hello_string, empty, 10);
  char *_test1 = s21_strncat(hello_string, empty, 10);
  ck_assert_ptr_eq(test1, _test1);
}
END_TEST

START_TEST(test_strncat_2) {
  char hello_string[100] = "Hello, World!";
  char empty[100] = "";

  // Тестирование конкатенации пустой строки в непустую целевую строку.
  char *test2 = strncat(empty, hello_string, 15);
  char *_test2 = s21_strncat(empty, hello_string, 15);
  ck_assert_ptr_eq(test2, _test2);
}
END_TEST

START_TEST(test_strncat_3) {
  char hello_string[100] = "Hello, World!";
  char neo_string[100] = "Wake up, Neo";

  // Тестирование конкатенации разных строк.
  char *test3 = strncat(hello_string, neo_string, 10);
  char *_test3 = s21_strncat(hello_string, neo_string, 10);
  ck_assert_ptr_eq(test3, _test3);
}
END_TEST

// STRCHR

START_TEST(test_strchr_1) {
  char str1[] = "abc";
  int n = 'a';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(test_strchr_2) {
  char str1[] = "abc";
  int n = 'd';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(test_strchr_3) {
  char str1[] = "abc";
  int n = '1';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(test_strchr_4) {
  char str1[] = "abc";
  int n = '\\';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(test_strchr_5) {
  char str1[] = "";
  int n = 'a';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(test_strchr_6) {
  char str1[] = " ";
  int n = 'a';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(test_strchr_7) {
  char str1[] = " ";
  int n = ' ';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(test_strchr_8) {
  char str1[] = " ";
  int n = '\\';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(test_strchr_9) {
  char str1[] = "021";
  int n = '0';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

START_TEST(test_strchr_10) {
  char str1[] = "ab\nc";
  int n = 'a';
  ck_assert_ptr_eq(strchr(str1, n), s21_strchr(str1, n));
}
END_TEST

// STRNCMP

START_TEST(test_strncmp_1) {
  char hello_string[] = "Hello, World!";

  // Тестирование на равные массивы
  int test1 = strncmp(hello_string, hello_string, strlen(hello_string));
  int _test1 = s21_strncmp(hello_string, hello_string, strlen(hello_string));
  ck_assert_int_eq(test1, _test1);
}
END_TEST

START_TEST(test_strncmp_2) {
  char hello_string[] = "Hello, World!";
  char neo_string[] = "Wake up, Neo!";

  // Тестирование на различающиеся массивы
  int test2 = strncmp(hello_string, neo_string, strlen(hello_string));
  int _test2 = s21_strncmp(hello_string, neo_string, strlen(hello_string));
  ck_assert_int_eq(test2, _test2);
}
END_TEST

START_TEST(test_strncmp_3) {
  char hello_string[] = "Hello, World!";
  char rabbit_string[] = "Follow for a white rabbit!";

  // Тестирование на разные длины массивов
  int test3 = strncmp(hello_string, rabbit_string, strlen(hello_string));
  int _test3 = s21_strncmp(hello_string, rabbit_string, strlen(hello_string));
  ck_assert_int_eq(test3, _test3);
}
END_TEST

START_TEST(test_strncmp_4) {
  char hello_string[] = "Hello, World!";
  char empty[] = "";

  // Граничные случаи
  int test4 = strncmp(hello_string, empty, strlen(hello_string));
  int _test4 = s21_strncmp(hello_string, empty, strlen(hello_string));
  ck_assert_int_eq(test4, _test4);
}
END_TEST

START_TEST(test_strncmp_5) {
  char hello_string[] = "Hello, World!";
  char special_string[] = "!.<./";
  char special_string_2[] = "#$-&";

  // Сравнение массивов с использованием специальных символов
  int test5 = strncmp(special_string, special_string_2, strlen(hello_string));
  int _test5 =
      s21_strncmp(special_string, special_string_2, strlen(hello_string));
  ck_assert_int_eq(test5, _test5);
}
END_TEST

// STRNCPY

START_TEST(test_strncpy_1) {
  char hello_string[] = "Hello, World!";
  char *goodbuy_string = "Adios, World";

  // Копирование данных из одной области памяти в другую
  char *test1 = strncpy(hello_string, goodbuy_string, strlen(hello_string));
  char *_test1 =
      s21_strncpy(hello_string, goodbuy_string, strlen(hello_string));
  ck_assert_ptr_eq(test1, _test1);
}
END_TEST

START_TEST(test_strncpy_2) {
  char hello_string[] = "Hello, World!";
  char *goodbuy_string = "Adios, World";

  // Копирование части данных из одной области памяти в другую
  char *test2 = strncpy(hello_string, goodbuy_string, 5);
  char *_test2 = s21_strncpy(hello_string, goodbuy_string, 5);
  ck_assert_ptr_eq(test2, _test2);
}
END_TEST

START_TEST(test_strncpy_3) {
  char hello_string[] = "Hello, World!";
  char empty[] = "";

  // Копирование нулевой длины
  char *test3 = strncpy(hello_string, empty, strlen(hello_string));
  char *_test3 = s21_strncpy(hello_string, empty, strlen(hello_string));
  ck_assert_ptr_eq(test3, _test3);
}
END_TEST

START_TEST(test_strncpy_4) {
  char hello_string[] = "Hello, World!";
  char *goodbuy_string = "Adios, World";

  // Копирование данных в область, начинающуюся не с первого байта
  goodbuy_string++;
  char *test4 = strncpy(hello_string, goodbuy_string, strlen(hello_string));
  char *_test4 =
      s21_strncpy(hello_string, goodbuy_string, strlen(hello_string));
  ck_assert_ptr_eq(test4, _test4);
}
END_TEST

// STRCSPN

START_TEST(test_strcspn_1) {
  char hello_string[] = "Hello, World!";

  // Тестрирование если искомые символы находяться в конце строки
  s21_size_t test1 = strcspn(hello_string, "d!");
  s21_size_t _test1 = s21_strcspn(hello_string, "d!");
  ck_assert_int_eq(test1, _test1);
}
END_TEST

START_TEST(test_strcspn_2) {
  char hello_string[] = "Hello, World!";

  // Тестрирование если искомые символы находяться в начале строки
  s21_size_t test2 = strcspn(hello_string, "He");
  s21_size_t _test2 = s21_strcspn(hello_string, "He");
  ck_assert_int_eq(test2, _test2);
}
END_TEST

START_TEST(test_strcspn_3) {
  char hello_string[] = "Hello, World!";

  // Тестрирование если искомые символы находяться в середине строки
  s21_size_t test3 = strcspn(hello_string, ", ");
  s21_size_t _test3 = s21_strcspn(hello_string, ", ");
  ck_assert_int_eq(test3, _test3);
}
END_TEST

START_TEST(test_strcspn_4) {
  char hello_string[] = "Hello, World!";

  // Тестрирование если искомые символы отсутствуют
  s21_size_t test4 = strcspn(hello_string, "zx");
  s21_size_t _test4 = s21_strcspn(hello_string, "zx");
  ck_assert_int_eq(test4, _test4);
}
END_TEST

START_TEST(test_strcspn_5) {
  char empty[] = "";

  // Тестрирование если массив пустой
  s21_size_t test5 = strcspn(empty, "zx");
  s21_size_t _test5 = s21_strcspn(empty, "zx");
  ck_assert_int_eq(test5, _test5);
}
END_TEST

// STRERROR

START_TEST(strerror_0) {
  int i = 0;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_1) {
  int i = 1;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_2) {
  int i = 2;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_3) {
  int i = 3;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_4) {
  int i = 4;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_5) {
  int i = 5;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_6) {
  int i = 6;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_7) {
  int i = 7;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_8) {
  int i = 8;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_9) {
  int i = 9;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_10) {
  int i = 10;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_11) {
  int i = 11;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_12) {
  int i = 12;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_13) {
  int i = 13;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_14) {
  int i = 14;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_15) {
  int i = 15;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_16) {
  int i = 16;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_17) {
  int i = 17;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_18) {
  int i = 18;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_19) {
  int i = 19;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_20) {
  int i = 20;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_21) {
  int i = 21;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_22) {
  int i = 22;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_23) {
  int i = 23;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_24) {
  int i = 24;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_25) {
  int i = 25;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_26) {
  int i = 26;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_27) {
  int i = 27;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_28) {
  int i = 28;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_29) {
  int i = 29;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_30) {
  int i = 30;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_31) {
  int i = 31;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_32) {
  int i = 32;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_33) {
  int i = 33;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_34) {
  int i = 34;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_35) {
  int i = 35;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_36) {
  int i = 36;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_37) {
  int i = 37;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_38) {
  int i = 38;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_39) {
  int i = 39;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_40) {
  int i = 40;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_41) {
  int i = 41;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_42) {
  int i = 42;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_43) {
  int i = 43;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_44) {
  int i = 44;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_45) {
  int i = 45;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_46) {
  int i = 46;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_47) {
  int i = 47;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_48) {
  int i = 48;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_49) {
  int i = 49;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_50) {
  int i = 50;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_51) {
  int i = 51;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_52) {
  int i = 52;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_53) {
  int i = 53;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_54) {
  int i = 54;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_55) {
  int i = 55;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_56) {
  int i = 56;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_57) {
  int i = 57;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_58) {
  int i = 58;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_59) {
  int i = 59;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_60) {
  int i = 60;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_61) {
  int i = 61;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_62) {
  int i = 62;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_63) {
  int i = 63;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_64) {
  int i = 64;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_65) {
  int i = 65;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_66) {
  int i = 66;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_67) {
  int i = 67;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_68) {
  int i = 68;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_69) {
  int i = 69;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_70) {
  int i = 70;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_71) {
  int i = 71;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_72) {
  int i = 72;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_73) {
  int i = 73;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_74) {
  int i = 74;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_75) {
  int i = 75;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_76) {
  int i = 76;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_77) {
  int i = 77;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_78) {
  int i = 78;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_79) {
  int i = 79;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_80) {
  int i = 80;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_81) {
  int i = 81;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_82) {
  int i = 82;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_83) {
  int i = 83;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_84) {
  int i = 84;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_85) {
  int i = 85;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_86) {
  int i = 86;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_87) {
  int i = 87;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_88) {
  int i = 88;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_89) {
  int i = 89;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_90) {
  int i = 90;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_91) {
  int i = 91;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_92) {
  int i = 92;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_93) {
  int i = 93;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_94) {
  int i = 94;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_95) {
  int i = 95;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_96) {
  int i = 96;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_97) {
  int i = 97;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_98) {
  int i = 98;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_99) {
  int i = 99;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_100) {
  int i = 100;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_101) {
  int i = 101;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_102) {
  int i = 102;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_103) {
  int i = 103;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_104) {
  int i = 104;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_105) {
  int i = 105;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_106) {
  int i = 106;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_107) {
  int i = 107;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_108) {
  int i = 108;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror__1) {
  int i = -1;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_109) {
  int i = 109;
  ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

// STRLEN

START_TEST(test_strlen_1) {
  char hello_string[] = "Hello, World!";

  // Тестрирование непустой строки
  s21_size_t test1 = strlen(hello_string);
  s21_size_t _test1 = s21_strlen(hello_string);
  ck_assert_int_eq(test1, _test1);
}
END_TEST

START_TEST(test_strlen_2) {
  char empty_string[] = "";

  // Тестрирование пустой строки
  s21_size_t test2 = strlen(empty_string);
  s21_size_t _test2 = s21_strlen(empty_string);
  ck_assert_int_eq(test2, _test2);
}
END_TEST

// STRPBRK

START_TEST(test_strpbrk_1) {
  char hello_string[] = "Hello, World!";

  // Тестрирование если искомые символы находяться в конце строки
  char *test1 = strpbrk(hello_string, "d!");
  char *_test1 = s21_strpbrk(hello_string, "d!");

  ck_assert_ptr_eq(test1, _test1);
}
END_TEST

START_TEST(test_strpbrk_2) {
  char hello_string[] = "Hello, World!";

  // Тестрирование если искомые символы находяться в начале строки
  char *test2 = strpbrk(hello_string, "He");
  char *_test2 = s21_strpbrk(hello_string, "He");
  ck_assert_ptr_eq(test2, _test2);
}
END_TEST

START_TEST(test_strpbrk_3) {
  char hello_string[] = "Hello, World!";

  // Тестрирование если искомые символы находяться в середине строки
  char *test3 = strpbrk(hello_string, "Wo");
  char *_test3 = s21_strpbrk(hello_string, "Wo");
  ck_assert_ptr_eq(test3, _test3);
}
END_TEST

START_TEST(test_strpbrk_4) {
  char hello_string[] = "Hello, World!";

  // Тестрирование если искомые символы отсутствуют
  char *test4 = strpbrk(hello_string, "zx");
  char *_test4 = s21_strpbrk(hello_string, "zx");
  ck_assert_ptr_eq(test4, _test4);
}
END_TEST

START_TEST(test_strpbrk_5) {
  char empty_string[] = "";

  // Тестрирование если строка пустая
  char *test5 = strpbrk(empty_string, "d!");
  char *_test5 = s21_strpbrk(empty_string, "d!");
  ck_assert_ptr_eq(test5, _test5);
}
END_TEST

// STRRCHR

START_TEST(test_strrchr_1) {
  char hello_string[] = "Hello, World!";

  // Поиск символа в начале массива
  char *test1 = strrchr(hello_string, 'H');
  char *_test1 = s21_strrchr(hello_string, 'H');
  ck_assert_ptr_eq(test1, _test1);
}
END_TEST

START_TEST(test_strrchr_2) {
  char hello_string[] = "Hello, World!";

  // передать массив символов, в котором запрашиваемый символ отсутствует
  char *test2 = strrchr(hello_string, 'z');
  char *_test2 = s21_strrchr(hello_string, 'z');
  ck_assert_ptr_eq(test2, _test2);
}
END_TEST

START_TEST(test_strrchr_3) {
  char hello_string[] = "Hello, World!";

  // Поиск символа в середине массива
  char *test3 = strrchr(hello_string, 'W');
  char *_test3 = s21_strrchr(hello_string, 'W');
  ck_assert_ptr_eq(test3, _test3);
}
END_TEST

START_TEST(test_strrchr_4) {
  char hello_string[] = "Hello, World!";

  // Поиск символа в конце массива
  char *test4 = strrchr(hello_string, '!');
  char *_test4 = s21_strrchr(hello_string, '!');
  ck_assert_ptr_eq(test4, _test4);
}
END_TEST

START_TEST(test_strrchr_5) {
  char empty[] = "";

  // Пустой массив
  char *test5 = strrchr(empty, '!');
  char *_test5 = s21_strrchr(empty, '!');
  ck_assert_ptr_eq(test5, _test5);
}
END_TEST

START_TEST(test_strrchr_6) {
  char hello_string[] = "Hello, World!";

  // Поиск символа, повторяющегося несколько раз
  char *test6 = strrchr(hello_string, 'o');
  char *_test6 = s21_strrchr(hello_string, 'o');
  ck_assert_ptr_eq(test6, _test6);
}
END_TEST

// STRSTR

START_TEST(test_strstr_1) {
  char neo_string[] = "Wake up, Neo";

  // Поиск символа в начале массива
  char *test1 = strstr(neo_string, "Wake");
  char *_test1 = s21_strstr(neo_string, "Wake");
  ck_assert_ptr_eq(test1, _test1);
}
END_TEST

START_TEST(test_strstr_2) {
  char neo_string[] = "Wake up, Neo";

  // Поиск символа в конце массива
  char *test2 = strstr(neo_string, "Neo");
  char *_test2 = s21_strstr(neo_string, "Neo");
  ck_assert_ptr_eq(test2, _test2);
}
END_TEST

START_TEST(test_strstr_3) {
  char neo_string[] = "Wake up, Neo";

  // Поиск символа, который отсутствует в массиве
  char *test3 = strstr(neo_string, "zx");
  char *_test3 = s21_strstr(neo_string, "zx");
  ck_assert_ptr_eq(test3, _test3);
}
END_TEST

START_TEST(test_strstr_4) {
  char empty[] = "";

  // Поиск символа в пустом массиве
  char *test4 = strstr(empty, "Wake");
  char *_test4 = s21_strstr(empty, "Wake");
  ck_assert_ptr_eq(test4, _test4);
}
END_TEST

// STRTOK

START_TEST(test_strtok_1) {
  char neo_string[] = "Neo/Mr.Anderson/Triniti";

  char *test1 = strtok(neo_string, ":/ ");
  char *_test1 = s21_strtok(neo_string, ":/ ");
  ck_assert_msg(strcmp(test1, _test1) == 0, "test 1 failed\n");
}
END_TEST

START_TEST(test_strtok_2) {
  char neo_string[] = "Neo/Mr.Anderson/Triniti";

  char *test2 = strtok(neo_string, " ");
  char *_test2 = s21_strtok(neo_string, " ");

  ck_assert_msg(strcmp(test2, _test2) == 0, "test 2 failed\n");
}
END_TEST

START_TEST(test_strtok_3) {
  char str1[] = "Hello,World;How are you?";
  char str2[] = "Hello,World;How are you?";

  char *test3;
  char *_test3;

  char *token = strtok(str1, ",;");
  while (token != NULL) {
    token = strtok(NULL, ",;");
    if (token != S21_NULL) test3 = token;
  }
  char *_token = s21_strtok(str2, ",;");
  while (_token != NULL) {
    _token = s21_strtok(NULL, ",;");
    if (_token != S21_NULL) _test3 = _token;
  }
  ck_assert_msg(strcmp(test3, _test3) == 0, "test 2 failed\n");
}
END_TEST

// MARK: PART 5

// TO_UPPER

START_TEST(test_to_upper_1) {
  char string_1[100] = "Hello, world!";
  char *test1 = "HELLO, WORLD!";
  char *_test1 = s21_to_upper(string_1);

  ck_assert_msg(strcmp(test1, _test1) == 0, "test 1 failed\n");
  if (_test1) free(_test1);
}
END_TEST

START_TEST(test_to_upper_2) {
  char string_2[100] = "";

  char *test2 = "";
  char *_test2 = s21_to_upper(string_2);
  ck_assert_msg(strcmp(test2, _test2) == 0, "test 2 failed\n");
  if (_test2) free(_test2);
}
END_TEST

START_TEST(test_to_upper_3) {
  char string_3[100] = "HELLO, WORLD!";

  char *test3 = "HELLO, WORLD!";
  char *_test3 = s21_to_upper(string_3);
  ck_assert_msg(strcmp(test3, _test3) == 0, "test 3 failed\n");
  if (_test3) free(_test3);
}
END_TEST

// TO_LOWER

START_TEST(test_to_lower_1) {
  char string_1[100] = "Hello, world!";

  char *test1 = "hello, world!";
  char *_test1 = s21_to_lower(string_1);
  ck_assert_msg(strcmp(test1, _test1) == 0, "test 1 failed\n");
  if (_test1) free(_test1);
}
END_TEST

START_TEST(test_to_lower_2) {
  char string_2[100] = "";

  char *test2 = "";
  char *_test2 = s21_to_lower(string_2);

  ck_assert_msg(strcmp(test2, _test2) == 0, "test 2 failed\n");
  if (_test2) free(_test2);
}
END_TEST

START_TEST(test_to_lower_3) {
  char string_3[100] = "HELLO, WORLD!";

  char *test3 = "hello, world!";
  char *_test3 = s21_to_lower(string_3);
  ck_assert_msg(strcmp(test3, _test3) == 0, "test 3 failed\n");
  if (_test3) free(_test3);
}
END_TEST

// INSERT

START_TEST(test_insert_1) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abcdef");
  free(str3);
}
END_TEST

START_TEST(test_insert_2) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 2;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abdefc");
  free(str3);
}
END_TEST

START_TEST(test_insert_3) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "adefbc");
  free(str3);
}
END_TEST

// TRIM

START_TEST(test_trim_1) {
  char str1[] = "ABCDEFGHIJK";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIJK");
  free(str3);
}
END_TEST

START_TEST(test_trim_2) {
  char str1[] = "ABCDEFGHIabc";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIabc");
  free(str3);
}
END_TEST

START_TEST(test_trim_3) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZabc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "ABCDEFGHIabcABCPQRSTUVWXYZ");
  free(str3);
}
END_TEST

Suite *string_suite(void) {
  Suite *s1;
  TCase *tc1_1;

  s1 = suite_create("String");
  tc1_1 = tcase_create("Core");
  // MARK: PART 1
  tcase_add_test(tc1_1, test_memchr_1);
  tcase_add_test(tc1_1, test_memchr_2);
  tcase_add_test(tc1_1, test_memchr_3);
  tcase_add_test(tc1_1, test_memchr_4);
  tcase_add_test(tc1_1, test_memchr_5);
  tcase_add_test(tc1_1, test_memchr_6);

  tcase_add_test(tc1_1, test_memcmp_1);
  tcase_add_test(tc1_1, test_memcmp_2);
  tcase_add_test(tc1_1, test_memcmp_3);
  tcase_add_test(tc1_1, test_memcmp_4);
  tcase_add_test(tc1_1, test_memcmp_5);

  tcase_add_test(tc1_1, test_memcpy_1);
  tcase_add_test(tc1_1, test_memcpy_2);
  tcase_add_test(tc1_1, test_memcpy_3);
  tcase_add_test(tc1_1, test_memcpy_4);

  tcase_add_test(tc1_1, test_memset_1);
  tcase_add_test(tc1_1, test_memset_2);
  tcase_add_test(tc1_1, test_memset_3);
  tcase_add_test(tc1_1, test_memset_4);
  tcase_add_test(tc1_1, test_memset_5);
  tcase_add_test(tc1_1, test_memset_6);

  tcase_add_test(tc1_1, test_strncat_1);
  tcase_add_test(tc1_1, test_strncat_2);
  tcase_add_test(tc1_1, test_strncat_3);

  tcase_add_test(tc1_1, test_strchr_1);
  tcase_add_test(tc1_1, test_strchr_2);
  tcase_add_test(tc1_1, test_strchr_3);
  tcase_add_test(tc1_1, test_strchr_4);
  tcase_add_test(tc1_1, test_strchr_5);
  tcase_add_test(tc1_1, test_strchr_6);
  tcase_add_test(tc1_1, test_strchr_7);
  tcase_add_test(tc1_1, test_strchr_8);
  tcase_add_test(tc1_1, test_strchr_9);
  tcase_add_test(tc1_1, test_strchr_10);

  tcase_add_test(tc1_1, test_strncmp_1);
  tcase_add_test(tc1_1, test_strncmp_2);
  tcase_add_test(tc1_1, test_strncmp_3);
  tcase_add_test(tc1_1, test_strncmp_4);
  tcase_add_test(tc1_1, test_strncmp_5);

  tcase_add_test(tc1_1, test_strncpy_1);
  tcase_add_test(tc1_1, test_strncpy_2);
  tcase_add_test(tc1_1, test_strncpy_3);
  tcase_add_test(tc1_1, test_strncpy_4);

  tcase_add_test(tc1_1, test_strcspn_1);
  tcase_add_test(tc1_1, test_strcspn_2);
  tcase_add_test(tc1_1, test_strcspn_3);
  tcase_add_test(tc1_1, test_strcspn_4);
  tcase_add_test(tc1_1, test_strcspn_5);

  tcase_add_test(tc1_1, strerror_0);
  tcase_add_test(tc1_1, strerror_1);
  tcase_add_test(tc1_1, strerror_2);
  tcase_add_test(tc1_1, strerror_3);
  tcase_add_test(tc1_1, strerror_4);
  tcase_add_test(tc1_1, strerror_5);
  tcase_add_test(tc1_1, strerror_6);
  tcase_add_test(tc1_1, strerror_7);
  tcase_add_test(tc1_1, strerror_8);
  tcase_add_test(tc1_1, strerror_9);
  tcase_add_test(tc1_1, strerror_10);
  tcase_add_test(tc1_1, strerror_11);
  tcase_add_test(tc1_1, strerror_12);
  tcase_add_test(tc1_1, strerror_13);
  tcase_add_test(tc1_1, strerror_14);
  tcase_add_test(tc1_1, strerror_15);
  tcase_add_test(tc1_1, strerror_16);
  tcase_add_test(tc1_1, strerror_17);
  tcase_add_test(tc1_1, strerror_18);
  tcase_add_test(tc1_1, strerror_19);
  tcase_add_test(tc1_1, strerror_20);
  tcase_add_test(tc1_1, strerror_21);
  tcase_add_test(tc1_1, strerror_22);
  tcase_add_test(tc1_1, strerror_23);
  tcase_add_test(tc1_1, strerror_24);
  tcase_add_test(tc1_1, strerror_25);
  tcase_add_test(tc1_1, strerror_26);
  tcase_add_test(tc1_1, strerror_27);
  tcase_add_test(tc1_1, strerror_28);
  tcase_add_test(tc1_1, strerror_29);
  tcase_add_test(tc1_1, strerror_30);
  tcase_add_test(tc1_1, strerror_31);
  tcase_add_test(tc1_1, strerror_32);
  tcase_add_test(tc1_1, strerror_33);
  tcase_add_test(tc1_1, strerror_34);
  tcase_add_test(tc1_1, strerror_35);
  tcase_add_test(tc1_1, strerror_36);
  tcase_add_test(tc1_1, strerror_37);
  tcase_add_test(tc1_1, strerror_38);
  tcase_add_test(tc1_1, strerror_39);
  tcase_add_test(tc1_1, strerror_40);
  tcase_add_test(tc1_1, strerror_41);
  tcase_add_test(tc1_1, strerror_42);
  tcase_add_test(tc1_1, strerror_43);
  tcase_add_test(tc1_1, strerror_44);
  tcase_add_test(tc1_1, strerror_45);
  tcase_add_test(tc1_1, strerror_46);
  tcase_add_test(tc1_1, strerror_47);
  tcase_add_test(tc1_1, strerror_48);
  tcase_add_test(tc1_1, strerror_49);
  tcase_add_test(tc1_1, strerror_50);
  tcase_add_test(tc1_1, strerror_51);
  tcase_add_test(tc1_1, strerror_52);
  tcase_add_test(tc1_1, strerror_53);
  tcase_add_test(tc1_1, strerror_54);
  tcase_add_test(tc1_1, strerror_55);
  tcase_add_test(tc1_1, strerror_56);
  tcase_add_test(tc1_1, strerror_57);
  tcase_add_test(tc1_1, strerror_58);
  tcase_add_test(tc1_1, strerror_59);
  tcase_add_test(tc1_1, strerror_60);
  tcase_add_test(tc1_1, strerror_61);
  tcase_add_test(tc1_1, strerror_62);
  tcase_add_test(tc1_1, strerror_63);
  tcase_add_test(tc1_1, strerror_64);
  tcase_add_test(tc1_1, strerror_65);
  tcase_add_test(tc1_1, strerror_66);
  tcase_add_test(tc1_1, strerror_67);
  tcase_add_test(tc1_1, strerror_68);
  tcase_add_test(tc1_1, strerror_69);
  tcase_add_test(tc1_1, strerror_70);
  tcase_add_test(tc1_1, strerror_71);
  tcase_add_test(tc1_1, strerror_72);
  tcase_add_test(tc1_1, strerror_73);
  tcase_add_test(tc1_1, strerror_74);
  tcase_add_test(tc1_1, strerror_75);
  tcase_add_test(tc1_1, strerror_76);
  tcase_add_test(tc1_1, strerror_77);
  tcase_add_test(tc1_1, strerror_78);
  tcase_add_test(tc1_1, strerror_79);
  tcase_add_test(tc1_1, strerror_80);
  tcase_add_test(tc1_1, strerror_81);
  tcase_add_test(tc1_1, strerror_82);
  tcase_add_test(tc1_1, strerror_83);
  tcase_add_test(tc1_1, strerror_84);
  tcase_add_test(tc1_1, strerror_85);
  tcase_add_test(tc1_1, strerror_86);
  tcase_add_test(tc1_1, strerror_87);
  tcase_add_test(tc1_1, strerror_88);
  tcase_add_test(tc1_1, strerror_89);
  tcase_add_test(tc1_1, strerror_90);
  tcase_add_test(tc1_1, strerror_91);
  tcase_add_test(tc1_1, strerror_92);
  tcase_add_test(tc1_1, strerror_93);
  tcase_add_test(tc1_1, strerror_94);
  tcase_add_test(tc1_1, strerror_95);
  tcase_add_test(tc1_1, strerror_96);
  tcase_add_test(tc1_1, strerror_97);
  tcase_add_test(tc1_1, strerror_98);
  tcase_add_test(tc1_1, strerror_99);
  tcase_add_test(tc1_1, strerror_100);
  tcase_add_test(tc1_1, strerror_101);
  tcase_add_test(tc1_1, strerror_102);
  tcase_add_test(tc1_1, strerror_103);
  tcase_add_test(tc1_1, strerror_104);
  tcase_add_test(tc1_1, strerror_105);
  tcase_add_test(tc1_1, strerror_106);
  tcase_add_test(tc1_1, strerror_107);
  tcase_add_test(tc1_1, strerror_108);
  tcase_add_test(tc1_1, strerror__1);
  tcase_add_test(tc1_1, strerror_109);

  tcase_add_test(tc1_1, test_strlen_1);
  tcase_add_test(tc1_1, test_strlen_2);

  tcase_add_test(tc1_1, test_strpbrk_1);
  tcase_add_test(tc1_1, test_strpbrk_2);
  tcase_add_test(tc1_1, test_strpbrk_3);
  tcase_add_test(tc1_1, test_strpbrk_4);
  tcase_add_test(tc1_1, test_strpbrk_5);

  tcase_add_test(tc1_1, test_strrchr_1);
  tcase_add_test(tc1_1, test_strrchr_2);
  tcase_add_test(tc1_1, test_strrchr_3);
  tcase_add_test(tc1_1, test_strrchr_4);
  tcase_add_test(tc1_1, test_strrchr_5);
  tcase_add_test(tc1_1, test_strrchr_6);

  tcase_add_test(tc1_1, test_strstr_1);
  tcase_add_test(tc1_1, test_strstr_2);
  tcase_add_test(tc1_1, test_strstr_3);
  tcase_add_test(tc1_1, test_strstr_4);

  tcase_add_test(tc1_1, test_strtok_1);
  tcase_add_test(tc1_1, test_strtok_2);
  tcase_add_test(tc1_1, test_strtok_3);

  // MARK: PART 5
  tcase_add_test(tc1_1, test_to_upper_1);
  tcase_add_test(tc1_1, test_to_upper_2);
  tcase_add_test(tc1_1, test_to_upper_3);

  tcase_add_test(tc1_1, test_to_lower_1);
  tcase_add_test(tc1_1, test_to_lower_2);
  tcase_add_test(tc1_1, test_to_lower_3);

  tcase_add_test(tc1_1, test_insert_1);
  tcase_add_test(tc1_1, test_insert_2);
  tcase_add_test(tc1_1, test_insert_3);

  tcase_add_test(tc1_1, test_trim_1);
  tcase_add_test(tc1_1, test_trim_2);
  tcase_add_test(tc1_1, test_trim_3);

  suite_add_tcase(s1, tc1_1);

  return s1;
}