#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_sprintf_c) {
  char buffer1[100] = {'\0'};
  char buffer2[100] = {'\0'};
  int c_spec_test = sprintf(buffer1, "%c", 'a');
  int _c_spec_test = s21_sprintf(buffer2, "%c", 'a');
  int c_spec_test_2 = sprintf(buffer1, "%-10c", 'T');
  int _c_spec_test_2 = s21_sprintf(buffer2, "%-10c", 'T');
  int c_spec_test_3 = sprintf(buffer1, "%8c", 'g');
  int _c_spec_test_3 = s21_sprintf(buffer2, "%8c", 'g');
  int percent_spec_test = sprintf(buffer1, "%%");
  int _percent_spec_test = s21_sprintf(buffer2, "%%");
  ck_assert_int_eq(c_spec_test, _c_spec_test);
  ck_assert_int_eq(c_spec_test_2, _c_spec_test_2);
  ck_assert_int_eq(c_spec_test_3, _c_spec_test_3);
  ck_assert_int_eq(percent_spec_test, _percent_spec_test);
}
END_TEST;

START_TEST(test_sprintf_d) {
  char buffer1[100] = {'\0'};
  char buffer2[100] = {'\0'};
  int d_spec_test = sprintf(buffer1, "%hd", (short int)123);
  int _d_spec_test = s21_sprintf(buffer2, "%hd", (short int)123);
  int d_spec_test_2 = sprintf(buffer1, "%0+18d", 123);
  int _d_spec_test_2 = s21_sprintf(buffer2, "%0+18d", 123);
  int d_spec_test_3 = sprintf(buffer1, "%- 18d", 123);
  int _d_spec_test_3 = s21_sprintf(buffer2, "%- 18d", 123);
  int d_spec_test_4 = sprintf(buffer1, "%*d", 4, 10);
  int _d_spec_test_4 = s21_sprintf(buffer2, "%*d", 4, 10);
  int d_spec_test_5 = sprintf(buffer1, "%d", 4);
  int _d_spec_test_5 = s21_sprintf(buffer2, "%d", 4);
  int d_spec_test_6 = sprintf(buffer1, "%d", 0);
  int _d_spec_test_6 = s21_sprintf(buffer2, "%d", 0);
  ck_assert_int_eq(d_spec_test, _d_spec_test);
  ck_assert_int_eq(d_spec_test_2, _d_spec_test_2);
  ck_assert_int_eq(d_spec_test_3, _d_spec_test_3);
  ck_assert_int_eq(d_spec_test_4, _d_spec_test_4);
  ck_assert_int_eq(d_spec_test_5, _d_spec_test_5);
  ck_assert_int_eq(d_spec_test_6, _d_spec_test_6);
}
END_TEST;

START_TEST(test_sprintf_f) {
  char buffer1[1000] = {'\0'};
  char buffer2[1000] = {'\0'};
  int f_spec_test = sprintf(buffer1, "%f", (float)12);
  int _f_spec_test = s21_sprintf(buffer2, "%f", (float)12);
  int f_spec_test_2 = sprintf(buffer1, "%.0f", (float)12);
  int _f_spec_test_2 = s21_sprintf(buffer2, "%.0f", (float)12);
  int f_spec_test_3 = sprintf(buffer1, "%#.12f", (float)12);
  int _f_spec_test_3 = s21_sprintf(buffer2, "%#.12f", (float)12);
  int f_spec_test_4 = sprintf(buffer1, "%.*f", 4, 1000000.0);
  int _f_spec_test_4 = s21_sprintf(buffer2, "%.*f", 4, 1000000.0);
  ck_assert_int_eq(f_spec_test, _f_spec_test);
  ck_assert_int_eq(f_spec_test_2, _f_spec_test_2);
  ck_assert_int_eq(f_spec_test_3, _f_spec_test_3);
  ck_assert_int_eq(f_spec_test_4, _f_spec_test_4);
}
END_TEST;

START_TEST(test_sprintf_s) {
  char buffer1[100] = {'\0'};
  char buffer2[100] = {'\0'};
  int s_spec_test = sprintf(buffer1, "%10s", "asd");
  int _s_spec_test = s21_sprintf(buffer2, "%10s", "asd");
  int s_spec_test_2 = sprintf(buffer1, "%5s", "o_o");
  int _s_spec_test_2 = s21_sprintf(buffer2, "%5s", "o_o");
  int s_spec_test_3 = sprintf(buffer1, "%-10s", "  asd");
  int _s_spec_test_3 = s21_sprintf(buffer2, "%-10s", "  asd");
  ck_assert_int_eq(s_spec_test, _s_spec_test);
  ck_assert_int_eq(s_spec_test_2, _s_spec_test_2);
  ck_assert_int_eq(s_spec_test_3, _s_spec_test_3);
}
END_TEST;

START_TEST(test_sprintf_u) {
  char buffer1[100] = {'\0'};
  char buffer2[100] = {'\0'};
  int u_spec_test = sprintf(buffer1, "%10u", 123);
  int _u_spec_test = s21_sprintf(buffer2, "%10u", 123);
  int u_spec_test_2 = sprintf(buffer1, "%-10u", 123);
  int _u_spec_test_2 = s21_sprintf(buffer2, "%-10u", 123);
  int u_spec_test_3 = sprintf(buffer1, "%3u", 123);
  int _u_spec_test_3 = s21_sprintf(buffer2, "%3u", 123);
  ck_assert_int_eq(u_spec_test, _u_spec_test);
  ck_assert_int_eq(u_spec_test_2, _u_spec_test_2);
  ck_assert_int_eq(u_spec_test_3, _u_spec_test_3);
}
END_TEST;

START_TEST(test_sprintf_e) {
  char buffer1[1000] = {'\0'};
  char buffer2[1000] = {'\0'};
  int spec_e_double_test = sprintf(buffer1, "%.0e", -0.0123);
  int _spec_e_double_test = s21_sprintf(buffer2, "%.0e", -0.0123);
  int spec_e_double_test_2 = sprintf(buffer1, "%#.0e", (double)1);
  int _spec_e_double_test_2 = s21_sprintf(buffer2, "%#.0e", (double)1);
  int spec_e_double_test_3 =
      sprintf(buffer1, "%.0e %.2e", (double)1, (-0.0123));
  int _spec_e_double_test_3 =
      s21_sprintf(buffer2, "%.0e %.2e", (double)1, (-0.0123));
  int spec_e_double_test_4 = sprintf(buffer1, "%.0E", -0.0123);
  int _spec_e_double_test_4 = s21_sprintf(buffer2, "%.0E", -0.0123);
  int spec_e_double_test_5 = sprintf(buffer1, "%-.0e", -0.0123);
  int _spec_e_double_test_5 = s21_sprintf(buffer2, "%-.0e", -0.0123);
  int spec_e_double_test_6 = sprintf(buffer1, "%.0e", 1000.10);
  int _spec_e_double_test_6 = s21_sprintf(buffer2, "%.0e", 1000.10);

  ck_assert_int_eq(spec_e_double_test, _spec_e_double_test);
  ck_assert_int_eq(spec_e_double_test_2, _spec_e_double_test_2);
  ck_assert_int_eq(spec_e_double_test_3, _spec_e_double_test_3);
  ck_assert_int_eq(spec_e_double_test_4, _spec_e_double_test_4);
  ck_assert_int_eq(spec_e_double_test_5, _spec_e_double_test_5);
  ck_assert_int_eq(spec_e_double_test_6, _spec_e_double_test_6);
}
END_TEST;

START_TEST(test_sprintf_X) {
  char buffer1[1000] = {'\0'};
  char buffer2[1000] = {'\0'};
  int spec_X_test = sprintf(buffer1, "%X", 1234678);
  int _spec_X_test = s21_sprintf(buffer2, "%X", 1234678);
  int spec_X_test_2 = sprintf(buffer1, "%6X", 1234678);
  int _spec_X_test_2 = s21_sprintf(buffer2, "%6X", 1234678);
  int spec_X_test_3 = sprintf(buffer1, "%-x", 1234678);
  int _spec_X_test_3 = s21_sprintf(buffer2, "%-x", 1234678);

  ck_assert_int_eq(spec_X_test, _spec_X_test);
  ck_assert_int_eq(spec_X_test_2, _spec_X_test_2);
  ck_assert_int_eq(spec_X_test_3, _spec_X_test_3);
}
END_TEST;

START_TEST(test_sprintf_o) {
  char buffer1[1000] = {'\0'};
  char buffer2[1000] = {'\0'};
  int o_spec_test = sprintf(buffer1, "%o", 1234);
  int _o_spec_test = s21_sprintf(buffer2, "%o", 1234);
  int o_spec_test_2 = sprintf(buffer1, "%10o", 1234);
  int _o_spec_test_2 = s21_sprintf(buffer2, "%10o", 1234);
  int o_spec_test_3 = sprintf(buffer1, "%4o", 1234);
  int _o_spec_test_3 = s21_sprintf(buffer2, "%4o", 1234);
  int o_spec_test_4 = sprintf(buffer1, "%-10o", 1234);
  int _o_spec_test_4 = s21_sprintf(buffer2, "%-10o", 1234);
  ck_assert_int_eq(o_spec_test, _o_spec_test);
  ck_assert_int_eq(o_spec_test_2, _o_spec_test_2);
  ck_assert_int_eq(o_spec_test_3, _o_spec_test_3);
  ck_assert_int_eq(o_spec_test_4, _o_spec_test_4);
}
END_TEST;

START_TEST(test_sprintf_p) {
  char buffer1[100] = {'\0'};
  char buffer2[100] = {'\0'};

  int x = 1234567;
  void *ptr = &x;
  double y = 123.1234567;
  void *ptr2 = &y;

  int test1 = sprintf(buffer1, "%p", ptr);
  int _test1 = s21_sprintf(buffer2, "%p", ptr);
  int test2 = sprintf(buffer1, "%-20p", ptr2);
  int _test2 = s21_sprintf(buffer2, "%-20p", ptr2);

  ck_assert_int_eq(test1, _test1);
  ck_assert_int_eq(test2, _test2);
}
END_TEST;

START_TEST(test_all_sprintf) {
  char buffer1[1000] = {'\0'};
  int all_spec_test =
      sprintf(buffer1, "%% char %-10c uint %-10u float %-+19f str %8s", '!',
              123, 12.123, "asd");
  int _all_spec_test =
      s21_sprintf(buffer1, "%% char %-10c uint %-10u float %-+19f str %8s", '!',
                  123, 12.123, "asd");
  int type_Ldouble_test = sprintf(buffer1, "%Lf", (long double)10.12);
  int _type_Ldouble_test = s21_sprintf(buffer1, "%Lf", (long double)10.12);

  ck_assert_int_eq(all_spec_test, _all_spec_test);
  ck_assert_int_eq(type_Ldouble_test, _type_Ldouble_test);
}
END_TEST;

START_TEST(sprintf_d_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 123;
  char *format = "|%d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MIN;
  char *format = "|%d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MAX;
  char *format = "|%+d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = INT_MAX;
  char *format = "|% d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 0;
  char *format = "|%+d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 5346457;
  char *format = "|%015d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 6878;
  char *format = "|%1d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -315;
  char *format = "|%4d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -14566;
  char *format = "|%.1d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_10) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 56368;
  char *format = "|%.10d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -67567;
  char *format = "|%.6d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_13) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = -131135;
  int y = 12;
  char *format = "|%.*d|\n";
  int res1 = s21_sprintf(str1, format, y, x);
  int res2 = sprintf(str2, format, y, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_14) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  int y = 12;
  int z = 16;
  char *format = "|%*.*d|\n";
  int res1 = s21_sprintf(str1, format, z, y, x);
  int res2 = sprintf(str2, format, z, y, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_15) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  int y = 12;
  int z = 16;
  char *format = "|%-*.*d|\n";
  int res1 = s21_sprintf(str1, format, z, y, x);
  int res2 = sprintf(str2, format, z, y, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_17) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 354634;
  char *format = "|%+-015.20d|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned int x = UINT_MAX;
  char *format = "|%+-015.20u|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ld_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  long int x = LONG_MAX;
  char *format = "|%+-015.20ld|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hd_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  short int x = SHRT_MIN;
  char *format = "|%+-015.20hd|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_i_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%+-015.20i|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%o|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%+-15.20o|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%#o|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%#+-15.9o|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_o_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned int x = 0;
  char *format = "|%o|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_lo_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  long int x = 84518;
  char *format = "|%lo|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%#x|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  int x = 12345678;
  char *format = "|%x|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned int x = UINT_MAX;
  char *format = "|%+-20.15x|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  unsigned int x = UINT_MAX;
  char *format = "|%+ 20.15x|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_X_1) {
  char str1[1024] = "test ";
  char str2[1024] = "test ";
  int x = 0xF12443;
  char *format = "|%X|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_X_2) {
  char str1[1024] = "fffff ";
  char str2[1024] = "fffff ";
  int x = 0xf12443;
  char *format = "|%015X|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_X_3) {
  char str1[1024] = "fffff ";
  char str2[1024] = "fffff ";
  int x = 0;
  char *format = "|%X|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_lx_1) {
  char str1[1024] = "fffff ";
  char str2[1024] = "fffff ";
  long int x = 15;
  char *format = "|%lx|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = '1';
  char *format = "|%c|\n";
  int res1 = s21_sprintf(str1, format, c);
  int res2 = sprintf(str2, format, c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char c = 'A';
  char *format = "|%lc|\n";
  int res1 = s21_sprintf(str1, format, (unsigned long)c);
  int res2 = sprintf(str2, format, (unsigned long)c);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_lc_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  wchar_t ch = L'1';
  char *format = "|%lc|\n";
  int res1 = s21_sprintf(str1, format, (unsigned long)ch);
  int res2 = sprintf(str2, format, (unsigned long)ch);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "\0";
  char *format = "|%s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%.2s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_4) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%.*s|\n";
  int res1 = s21_sprintf(str1, format, 3, str3);
  int res2 = sprintf(str2, format, 3, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%10.5s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%10.2s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%-5s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = NULL;
  char *format = "|%s|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ls_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  wchar_t *str3 = L"";
  char *format = "|%ls|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *str3 = "test";
  char *format = "|%p|\n";
  int res1 = s21_sprintf(str1, format, str3);
  int res2 = sprintf(str2, format, str3);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_p_3) {
//   char str1[1024] = "";
//   char str2[1024] = "";
//   char *str3 = "test";
//   char *format = "|%+-15.6p|\n";
//   int res1 = s21_sprintf(str1, format, str3);
//   int res2 = sprintf(str2, format, str3);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_p_4) {
//   char str1[1024] = "";
//   char str2[1024] = "";
//   char *str3 = "test";
//   char *format = "|%+-20.p|\n";
//   int res1 = s21_sprintf(str1, format, str3);
//   int res2 = sprintf(str2, format, str3);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_n_1) {
//   char str1[1024] = "";
//   char str2[1024] = "";
//   char *str3 = "test";
//   int count1;
//   int count2;
//   char *format = "|%+-20.p%n|\n";
//   int res1 = s21_sprintf(str1, format, str3, &count1);
//   int res2 = sprintf(str2, format, str3, &count2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_n_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  int count1;
  int count2;
  char *format = "|%n|\n";
  int res1 = s21_sprintf(str1, format, &count1);
  int res2 = sprintf(str2, format, &count2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_per_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *format = "|%%\n%d|\n";
  int res1 = s21_sprintf(str1, format, 1);
  int res2 = sprintf(str2, format, 1);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_per_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *format = "|%%%%%% %d|\n";
  int res1 = s21_sprintf(str1, format, 1);
  int res2 = sprintf(str2, format, 1);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 123.34634;
  char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -4534123.34634;
  char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.0;
  char *format = "|%f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_5) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 9123487.635;
  char *format = "|%.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_6) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -69678363.135768656;
  char *format = "|%15.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = -69678363.135768656;
  char *format = "|%*.*f|\n";
  int res1 = s21_sprintf(str1, format, 20, 2, x);
  int res2 = sprintf(str2, format, 20, 2, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 0.0;
  char *format = "|%.0f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_11) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 99934634632.3;
  char *format = "|%-+08.3f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_16) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.0;
  char *format = "|%.2f|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_Lf_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 4.1111e-30;
  char *format = "|%+40.35Lf|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_Lf_3) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 3.3489;
  char *format = "|%.3Lf|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  float x = 434561.413;
  char *format = "|%e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_2) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 0.0;
  char *format = "|%8.2e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_7) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 123;
  char *format = "|%#.0e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_8) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 123;
  char *format = "|%*.*e|\n";
  int res1 = s21_sprintf(str1, format, 1, 1, x);
  int res2 = sprintf(str2, format, 1, 1, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  double x = 9999999999;
  char *format = "|%e|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_Le_1) {
  char str1[1024] = "";
  char str2[1024] = "";
  long double x = 123e+38;
  char *format = "|%Le|\n";
  int res1 = s21_sprintf(str1, format, x);
  int res2 = sprintf(str2, format, x);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

/////////////////////////////////////////для
/// s21_sprintf/////////////////////////////////////////////////////
START_TEST(sprintf_simple_int) {
  char str1[10] = {0};
  char str2[10] = {0};
  char *format = "lol %d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_int) {
  char str1[10] = {0};
  char str2[10] = {0};
  char *format = "lol % d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_int) {
  char str1[10] = {0};
  char str2[10] = {0};
  char *format = "lol %+5d";
  int val = -69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_2_int) {
  char str1[10] = {0};
  char str2[10] = {0};
  char *format = "lol %+5d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_dot_int) {
  char str1[10] = {0};
  char str2[10] = {0};
  char *format = "lol %.3d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_mixed_1_int) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "lol %+9.3d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
#define BUFF_SIZE 512
START_TEST(sprintf_mixed_2_int) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%-20.5d %-20.5d %-20.5d";
  for (int j = 1; j < 5; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, j, j * j, j * j * j),
                     sprintf(str2, format, j, j * j, j * j * j));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST

START_TEST(sprintf_mixed_3_int) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%-20.5d %-20.5d %-20.5d";
  for (int j = 1; j < 5; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, -j, -j * j, -j * j * j),
                     sprintf(str2, format, -j, -j * j, -j * j * j));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST

START_TEST(sprintf_c) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%c %c %c";
  for (int j = 1; j < 5; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, j, j * j, j * j * j),
                     sprintf(str2, format, j, j * j, j * j * j));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST

START_TEST(sprintf_s) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%s";
  for (int j = 1; j < 5; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, "aaa"),
                     sprintf(str2, format, "aaa"));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST

START_TEST(sprintf_mixed_1_f) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%20.9f";
  for (double j = 1.0; j < 13; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, j * j * j),
                     sprintf(str2, format, j * j * j));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST

START_TEST(sprintf_mixed_1_u) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%-20.4u%-20.4u%-20.4ulol";
  for (unsigned int j = 10; j < 13; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, j, j * j, j * j * j),
                     sprintf(str2, format, j, j * j, j * j * j));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST

START_TEST(sprintf_mixed_2_u) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%20.3u%20.3u%20.3ulol";
  for (unsigned int j = 1; j < 13; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, j, j * j, j * j * j),
                     sprintf(str2, format, j, j * j, j * j * j));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST

START_TEST(sprintf_mixed_1_h) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%hd lol";
  for (short int j = 1; j < 13; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, j, j * j, j * j * j),
                     sprintf(str2, format, j, j * j, j * j * j));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST

START_TEST(sprintf_ld) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%ldlol";
  for (long int j = 1; j < 1.3; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, j, j * j, j * j * j),
                     sprintf(str2, format, j));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST

START_TEST(sprintf_hd) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%hdlol";
  for (long int j = 1; j < 1.3; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, j, j * j, j * j * j),
                     sprintf(str2, format, j));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST

START_TEST(sprintf_ldazaza) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%1.1ldlol";
  for (long int j = 1; j < 1.3; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, j, j * j, j * j * j),
                     sprintf(str2, format, j));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST

START_TEST(sprintf_hdazaza) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *format = "%1.1hdlol";
  for (long int j = 1; j < 1.3; j++) {
    ck_assert_int_eq(s21_sprintf(str1, format, j, j * j, j * j * j),
                     sprintf(str2, format, j));
    ck_assert_pstr_eq(str1, str2);
  }
}
END_TEST
/////////////////////////////////////////для
/// s21_sprintf/////////////////////////////////////////////////////
/////////////////////////////////////////для
/// s21_sprintf/////////////////////////////////////////////////////
START_TEST(sprintf_test) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  char format[] = "This is a simple value %d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%+12d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_padding_int) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%+12d";
  int val = 69;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%.0d";
  int val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "% d";
  int val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  char *format = "%u";
  unsigned int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  char *format = "%15u";
  unsigned int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%-16u";
  unsigned int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  char *format = "%.51u";
  unsigned int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  char *format = "% 5.51u";
  unsigned int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%hu";
  unsigned short int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%lu";
  unsigned long int val = 949149114140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  s21_sprintf(str1, format, val, 14, 1441, 14414, 9681);

  sprintf(str2, format, val, 14, 1441, 14414, 9681);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_short) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%hd";
  short int val = 14140;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%u";
  s21_sprintf(str1, format, 0);

  sprintf(str2, format, 0);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%s";
  char *string = "denis classniy";
  s21_sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%.4s";
  char *string = "denis classniy";
  s21_sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string__width) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%25s";
  char *string = "denis classniy";
  s21_sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_minus) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%-25s";
  char *string = "denis classniy";
  s21_sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%c";
  char sym = '!';
  s21_sprintf(str1, format, sym);
  sprintf(str2, format, sym);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_width) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%5c";
  char sym = '!';
  s21_sprintf(str1, format, sym);
  sprintf(str2, format, sym);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_minus) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%-5c";
  char sym = '!';
  s21_sprintf(str1, format, sym);
  sprintf(str2, format, sym);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprint_string_null) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%s";
  char *string = NULL;
  s21_sprintf(str1, format, string);
  sprintf(str2, format, string);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%f";
  double num = 1.9;
  s21_sprintf(str1, format, num);
  sprintf(str2, format, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_zero) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%f";
  double zero = 0;
  s21_sprintf(str1, format, zero);
  sprintf(str2, format, zero);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_double_min) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%lf";
  double num = 1E-12;
  s21_sprintf(str1, format, num);
  sprintf(str2, format, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_double) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%lf";
  double negative = -0.34834493943;
  s21_sprintf(str1, format, negative);
  sprintf(str2, format, negative);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_double_negative) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%lf";
  double num = -10.934;
  s21_sprintf(str1, format, num);
  sprintf(str2, format, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_double_nan) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%lf";
  double nan = NAN;
  s21_sprintf(str1, format, nan);
  sprintf(str2, format, nan);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_percent) {
  char str1[1000] = {0};
  char str2[1000] = {0};

  char *format = "%%lf";
  long double num = 0;
  s21_sprintf(str1, format, num);
  sprintf(str2, format, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

/////////////////////////////////////////для
/// s21_sprintf/////////////////////////////////////////////////////
char test1[20] = "Hell0 world\0";
char test2[20] = "Hell0 world\n\0";
char test3[10] = "a\n\0";
char test4[10] = " \n\0";
char test5[10] = " \0";
char test6[10] = "\n\0";
char test7[10] = "\0";

START_TEST(s21_chars_f) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};
  s21_sprintf(s21_buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1, '\n',
              test2, '-', test3, test4, test5, test6, test7);
  sprintf(buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1, '\n', test2,
          '-', test3, test4, test5, test6, test7);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

// test for printf
START_TEST(s21_nums_f) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};
  s21_sprintf(s21_buffer,
              "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u", 101,
              -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
              (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
  sprintf(buffer, "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u", 101,
          -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
          (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums2_f) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};

  s21_sprintf(s21_buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
              (long int)125123123123, (short int)160, (unsigned short)101,
              (unsigned long)210, (short int)0, (long int)0, (short int)-25,
              (long int)-51);
  sprintf(buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
          (long int)125123123123, (short int)160, (unsigned short)101,
          (unsigned long)210, (short int)0, (long int)0, (short int)-25,
          (long int)-51);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums4_f) {
  char data[100] = {0};
  char data1[100] = {0};
  s21_sprintf(data, "02) chisto rofl : %-+.f\n", -100.55);
  sprintf(data1, "02) chisto rofl : %-+.f\n", -100.55);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_nums5_f) {
  char data[100] = {0};
  char data1[100] = {0};
  s21_sprintf(data, "01)SPRINTF : |%5c|\n", 'R');
  sprintf(data1, "01)SPRINTF : |%5c|\n", 'R');
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_nums6_f) {
  char data[100] = {0};
  char data1[100] = {0};
  s21_sprintf(data, "01)SPRINTF : |%-5c|\n", 'R');
  sprintf(data1, "01)SPRINTF : |%-5c|\n", 'R');
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_nums7_f) {
  char data[100] = {0};
  char data1[100] = {0};
  s21_sprintf(data, "01)SPRINTF : |%1c|\n", '3');
  sprintf(data1, "01)SPRINTF : |%1c|\n", '3');
  ck_assert_str_eq(data, data1);
}
END_TEST

END_TEST

START_TEST(s21_nums12_f) {
  char data[100] = {0};
  char data1[100] = {0};
  s21_sprintf(data, "01)SPRINTF : |%s|\n", "salut");
  sprintf(data1, "01)SPRINTF : |%s|\n", "salut");
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_nums13_f) {
  char data[100] = {0};
  char data1[100] = {0};
  s21_sprintf(data, "01)SPRINTF : |%-s|\n", "test");
  sprintf(data1, "01)SPRINTF : |%-s|\n", "test");
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_nums14_f) {
  char data[100] = {0};
  char data1[100] = {0};
  s21_sprintf(data, "01)SPRINTF : |%-s|\n", "test2");
  sprintf(data1, "01)SPRINTF : |%-s|\n", "test2");
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_p_f) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  void *p1 = (void *)0x123456789;
  void *p2 = (void *)4325234;
  void *p3 = (void *)0x123f324b;
  void *p4 = (void *)432520;
  int r1 = sprintf(str1, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4, p2,
                   10, p3, p1, 10, p4);
  int r2 = s21_sprintf(str2, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4,
                       p2, 10, p3, p1, 10, p4);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_o_f) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  unsigned short h = 253;
  unsigned long l = 4325234324242l;
  int r1 = sprintf(str1, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                   12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
  int r2 =
      s21_sprintf(str2, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                  12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

/////////////////////////////////////////для
/// s21_sprintf/////////////////////////////////////////////////////

START_TEST(simplE_int11) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precisE_int11) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(padding_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_width_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_precision_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_flags_many_ints1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_another_long_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val1_many_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val1_short) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_long) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_many) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal1_width1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_flags1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_precision1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal1_many_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_hash) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal1_short) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_long) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_many) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_width1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_flags1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_precision1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many1_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_zero1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_huge1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_short1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_long1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_one_longer_width1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_two_longer_width1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision11) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags11) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width11) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many11) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many11_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%s";
  char *val = "I LOVE string1S AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string1_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.15s";
  char *val = "I LOVE string1S AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string1_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string1_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string1_long) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG string1";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string1_many) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG string1";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr1_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr1_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string1_width_huge) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(n_specifier1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_width1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision1_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision1_empty) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision1_huge) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision1_huge_negative) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_flags1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_many1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.16Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision1_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision1_empty) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision1_huge) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision1_huge_negative) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_huge1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_flags1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_many1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(E_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(all_empty1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_char1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_char) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_string1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_string1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_dec1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_dec1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111onE_int1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_float1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_unsigned_dec) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_unsigned_dec) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_char1_with_alignment_left) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_char1_with_alignment_right) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_char_with_alignment) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(test_111one_hex_lower) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(test_111one_hex_lower_with_alignment_left) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_lower_with_alignment_right) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_alignment_left) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_alignment_right) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(test_111one_hex_with_hashtag) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_hashtag) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(test_111one_hex_lower_with_width_star) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_width_star) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(test_111one_hex_lower_with_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(test_111one_hex_lower_with_length) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_length) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf2) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf3) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf4) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf6) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf7) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf8) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf9) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf10) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf11) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf12) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.16Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf14) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf15) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf16) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf17) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf18) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf19) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf20) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf24) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf25) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf28) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf29) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf30) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf31) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf32) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf33) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf37) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf38) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf39) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf40) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf42) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf43) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf44) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_trailing_zero11) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_large1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_small1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision1_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision1_missing) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_many1_zeroes_in_front1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_one_zero1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_zero1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_short_no_mantiss1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_char1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}

Suite *sprintf_suite(void) {
  Suite *s1 = suite_create("Tests_for_sprintf");
  TCase *tcase = tcase_create("s21_sprintf");
  TCase *tcase_1 =
      tcase_create(" (after this point) Received signal 6 (Aborted)");
  suite_add_tcase(s1, tcase);
  suite_add_tcase(s1, tcase_1);
  tcase_add_test(tcase, test_sprintf_c);
  tcase_add_test(tcase, test_sprintf_d);
  tcase_add_test(tcase, test_sprintf_f);
  tcase_add_test(tcase, test_sprintf_s);
  tcase_add_test(tcase, test_sprintf_u);
  tcase_add_test(tcase, test_sprintf_e);
  tcase_add_test(tcase, test_sprintf_X);
  tcase_add_test(tcase, test_sprintf_o);
  tcase_add_test(tcase, test_sprintf_p);
  tcase_add_test(tcase, test_all_sprintf);
  tcase_add_test(tcase, sprintf_d_1);
  tcase_add_test(tcase, sprintf_d_2);
  tcase_add_test(tcase, sprintf_d_3);
  tcase_add_test(tcase, sprintf_d_4);
  tcase_add_test(tcase, sprintf_d_5);
  tcase_add_test(tcase, sprintf_d_6);
  tcase_add_test(tcase, sprintf_d_7);
  tcase_add_test(tcase, sprintf_d_8);
  tcase_add_test(tcase, sprintf_d_9);
  tcase_add_test(tcase, sprintf_d_10);
  tcase_add_test(tcase, sprintf_d_11);
  tcase_add_test(tcase, sprintf_d_13);
  tcase_add_test(tcase, sprintf_d_14);
  tcase_add_test(tcase, sprintf_d_15);
  tcase_add_test(tcase, sprintf_d_17);
  tcase_add_test(tcase, sprintf_u_1);
  tcase_add_test(tcase, sprintf_ld_1);
  tcase_add_test(tcase, sprintf_hd_1);
  tcase_add_test(tcase, sprintf_i_1);
  tcase_add_test(tcase, sprintf_o_1);
  tcase_add_test(tcase, sprintf_o_2);
  tcase_add_test(tcase, sprintf_o_3);
  tcase_add_test(tcase, sprintf_o_4);
  tcase_add_test(tcase, sprintf_o_5);
  tcase_add_test(tcase, sprintf_lo_1);
  tcase_add_test(tcase, sprintf_x_1);
  tcase_add_test(tcase, sprintf_x_2);
  tcase_add_test(tcase, sprintf_x_3);
  tcase_add_test(tcase, sprintf_x_4);
  tcase_add_test(tcase, sprintf_X_1);
  tcase_add_test(tcase, sprintf_X_2);
  tcase_add_test(tcase, sprintf_X_3);
  tcase_add_test(tcase, sprintf_lx_1);
  tcase_add_test(tcase, sprintf_c_1);
  tcase_add_test(tcase, sprintf_c_3);
  tcase_add_test(tcase, sprintf_lc_1);
  tcase_add_test(tcase, sprintf_s_1);
  tcase_add_test(tcase, sprintf_s_2);
  tcase_add_test(tcase, sprintf_s_3);
  tcase_add_test(tcase, sprintf_s_4);
  tcase_add_test(tcase, sprintf_s_5);
  tcase_add_test(tcase, sprintf_s_6);
  tcase_add_test(tcase, sprintf_s_8);
  tcase_add_test(tcase, sprintf_s_9);
  tcase_add_test(tcase, sprintf_s_1);
  tcase_add_test(tcase, sprintf_ls_2);
  tcase_add_test(tcase, sprintf_p_1);
  tcase_add_test(tcase, sprintf_n_2);
  tcase_add_test(tcase, sprintf_per_1);
  tcase_add_test(tcase, sprintf_per_2);
  tcase_add_test(tcase, sprintf_f_1);
  tcase_add_test(tcase, sprintf_f_2);
  tcase_add_test(tcase, sprintf_f_3);
  tcase_add_test(tcase, sprintf_f_5);
  tcase_add_test(tcase, sprintf_f_6);
  tcase_add_test(tcase, sprintf_f_7);
  tcase_add_test(tcase, sprintf_f_9);
  tcase_add_test(tcase, sprintf_f_11);
  tcase_add_test(tcase, sprintf_f_16);
  tcase_add_test(tcase, sprintf_Lf_1);
  tcase_add_test(tcase, sprintf_Lf_3);
  tcase_add_test(tcase, sprintf_e_1);
  tcase_add_test(tcase, sprintf_e_2);
  tcase_add_test(tcase, sprintf_e_7);
  tcase_add_test(tcase, sprintf_e_8);
  tcase_add_test(tcase, sprintf_e_9);
  tcase_add_test(tcase, sprintf_Le_1);
  tcase_add_test(tcase, sprintf_test);
  tcase_add_test(tcase, sprintf_plus_width_int);
  tcase_add_test(tcase, sprintf_padding_int);
  tcase_add_test(tcase, sprintf_zero_precision_zero_int);
  tcase_add_test(tcase, sprintf_space_flag_int);
  tcase_add_test(tcase, sprintf_unsigned_val);
  tcase_add_test(tcase, sprintf_unsigned_val_width);
  tcase_add_test(tcase, sprintf_unsigned_val_flags);
  tcase_add_test(tcase, sprintf_unsigned_val_precision);
  tcase_add_test(tcase, sprintf_unsigned_val_many_flags);
  tcase_add_test(tcase, sprintf_unsigned_val_short);
  tcase_add_test(tcase, sprintf_unsigned_val_long);
  tcase_add_test(tcase, sprintf_unsigned_val_many);
  tcase_add_test(tcase, sprintf_octal_short);
  tcase_add_test(tcase, sprintf_unsigned_zero);
  tcase_add_test(tcase, sprintf_string);
  tcase_add_test(tcase, sprintf_string_precision);
  tcase_add_test(tcase, sprintf_string__width);
  tcase_add_test(tcase, sprintf_string_minus);
  tcase_add_test(tcase, sprintf_char);
  tcase_add_test(tcase, sprintf_char_width);
  tcase_add_test(tcase, sprintf_char_minus);
  tcase_add_test(tcase, sprint_string_null);
  tcase_add_test(tcase, sprintf_float);
  tcase_add_test(tcase, sprintf_float_zero);
  tcase_add_test(tcase, sprintf_double_min);
  tcase_add_test(tcase, sprintf_double);
  tcase_add_test(tcase, sprintf_double_negative);
  tcase_add_test(tcase, sprintf_double_nan);
  tcase_add_test(tcase, sprintf_percent);
  tcase_add_test(tcase, s21_chars_f);
  tcase_add_test(tcase, s21_nums_f);
  tcase_add_test(tcase, s21_nums2_f);
  tcase_add_test(tcase, s21_nums4_f);
  tcase_add_test(tcase, s21_nums5_f);
  tcase_add_test(tcase, s21_nums6_f);
  tcase_add_test(tcase, s21_nums7_f);
  tcase_add_test(tcase, s21_nums12_f);
  tcase_add_test(tcase, s21_nums13_f);
  tcase_add_test(tcase, s21_nums14_f);
  tcase_add_test(tcase, s21_sprintf_test_p_f);
  tcase_add_test(tcase_1, s21_sprintf_test_o_f);
  tcase_add_test(tcase, simplE_int11);
  tcase_add_test(tcase, precisE_int11);
  tcase_add_test(tcase, width_int1);
  tcase_add_test(tcase, minus_width_int1);
  tcase_add_test(tcase, plus_width_int1);
  tcase_add_test(tcase, padding_int1);
  tcase_add_test(tcase, star_width_int1);
  tcase_add_test(tcase, star_precision_int1);
  tcase_add_test(tcase, many_flags_many_ints1);
  tcase_add_test(tcase, flags_long_int1);
  tcase_add_test(tcase, flags_short_int1);
  tcase_add_test(tcase, flags_another_long_int1);
  tcase_add_test(tcase, zero_precision_zero_int1);
  tcase_add_test(tcase, space_flag_int1);
  tcase_add_test(tcase, unsigned_val1);
  tcase_add_test(tcase, unsigned_val1_width);
  tcase_add_test(tcase, unsigned_val1_flags);
  tcase_add_test(tcase, unsigned_val1_precision);
  tcase_add_test(tcase, unsigned_val1_many_flags);
  tcase_add_test(tcase, unsigned_val1_short);
  tcase_add_test(tcase, unsigned_val1_long);
  tcase_add_test(tcase, unsigned_val1_many);
  tcase_add_test(tcase, octal1);
  tcase_add_test(tcase, octal1_width1);
  tcase_add_test(tcase, octal1_flags1);
  tcase_add_test(tcase, octal1_precision1);
  tcase_add_test(tcase, octal1_many_flags);
  tcase_add_test(tcase, octal1_short);
  tcase_add_test(tcase, octal1_long);
  tcase_add_test(tcase, octal1_many);
  tcase_add_test(tcase, octal1_zero);
  tcase_add_test(tcase, octal1_hash);
  tcase_add_test(tcase, unsigned_zero1);
  tcase_add_test(tcase, hex_width1);
  tcase_add_test(tcase, hex_flags1);
  tcase_add_test(tcase, hex_precision1);
  tcase_add_test(tcase, hex_many1);
  tcase_add_test(tcase, hex_many1_flags);
  tcase_add_test(tcase, hex_zero1);
  tcase_add_test(tcase, hex_huge1);
  tcase_add_test(tcase, hex_short1);
  tcase_add_test(tcase, hex_long1);
  tcase_add_test(tcase, hex_one_longer_width1);
  tcase_add_test(tcase, hex_two_longer_width1);
  tcase_add_test(tcase, one_char1);
  tcase_add_test(tcase, one_precision11);
  tcase_add_test(tcase, one_flags11);
  tcase_add_test(tcase, one_width11);
  tcase_add_test(tcase, one_many11);
  tcase_add_test(tcase, one_many11_flags);
  tcase_add_test(tcase, string1);
  tcase_add_test(tcase, string1_precision);
  tcase_add_test(tcase, string1_width);
  tcase_add_test(tcase, string1_flags);
  tcase_add_test(tcase, string1_long);
  tcase_add_test(tcase, string1_many);
  tcase_add_test(tcase, ptr1);
  tcase_add_test(tcase, ptr1_width);
  tcase_add_test(tcase, ptr1_precision);
  tcase_add_test(tcase, n_specifier1);
  tcase_add_test(tcase, string1_width_huge);
  tcase_add_test(tcase, float_width1);
  tcase_add_test(tcase, float_precision1_zero);
  tcase_add_test(tcase, float_precision1_empty);
  tcase_add_test(tcase, float_precision1_huge);
  tcase_add_test(tcase, float_precision1_huge_negative);
  tcase_add_test(tcase, float_huge1);
  tcase_add_test(tcase, float_flags1);
  tcase_add_test(tcase, float_many1);
  tcase_add_test(tcase, e_precision1);
  tcase_add_test(tcase, e_precision1_zero);
  tcase_add_test(tcase, e_precision1_empty);
  tcase_add_test(tcase, e_precision1_huge);
  tcase_add_test(tcase, e_precision1_huge_negative);
  tcase_add_test(tcase, e_huge1);
  tcase_add_test(tcase, e_many1);
  tcase_add_test(tcase, e_flags1);
  tcase_add_test(tcase, E_int1);
  tcase_add_test(tcase, all_empty1);
  tcase_add_test(tcase, empty_format_and_parameters1);
  tcase_add_test(tcase, test_111one_char1);
  tcase_add_test(tcase, test_111many_char);
  tcase_add_test(tcase, test_111one_string1);
  tcase_add_test(tcase, test_111many_string1);
  tcase_add_test(tcase, test_111one_dec1);
  tcase_add_test(tcase, test_111many_dec1);
  tcase_add_test(tcase, test_111onE_int1);
  tcase_add_test(tcase, test_111many_int);
  tcase_add_test(tcase, test_111one_float1);
  tcase_add_test(tcase, test_111one_unsigned_dec);
  tcase_add_test(tcase, test_111many_unsigned_dec);
  tcase_add_test(tcase, test_111one_char1_with_alignment_left);
  tcase_add_test(tcase, test_111one_char1_with_alignment_right);
  tcase_add_test(tcase, test_111many_char_with_alignment);
  tcase_add_test(tcase, test_111one_hex_lower);
  tcase_add_test(tcase, test_111one_hex_upper);
  tcase_add_test(tcase, test_111many_hex_lower);
  tcase_add_test(tcase, test_111many_hex_upper);
  tcase_add_test(tcase, test_111one_hex_lower_with_alignment_left);
  tcase_add_test(tcase, test_111one_hex_lower_with_alignment_right);
  tcase_add_test(tcase, test_111one_hex_upper_with_alignment_left);
  tcase_add_test(tcase, test_111one_hex_upper_with_alignment_right);
  tcase_add_test(tcase, test_111many_hex_lower_with_alignment);
  tcase_add_test(tcase, test_111many_hex_upper_with_alignment);
  tcase_add_test(tcase, test_111one_hex_with_hashtag);
  tcase_add_test(tcase, test_111one_hex_upper_with_hashtag);
  tcase_add_test(tcase, test_111many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tcase, test_111many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tcase, test_111one_hex_lower_with_width_star);
  tcase_add_test(tcase, test_111one_hex_upper_with_width_star);
  tcase_add_test(tcase,
                 test_111many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tcase, test_111many_hex_upper_with_width_star);
  tcase_add_test(tcase, test_111one_hex_lower_with_precision);
  tcase_add_test(tcase, test_111one_hex_upper_with_precision);
  tcase_add_test(tcase, test_111many_hex_lower_with_precision_and_other);
  tcase_add_test(tcase, test_111many_hex_upper_with_precision_and_other);
  tcase_add_test(tcase, test_111one_hex_lower_with_length);
  tcase_add_test(tcase, test_111one_hex_upper_with_length);
  tcase_add_test(tcase, test_111sprintf1);
  tcase_add_test(tcase, test_111sprintf2);
  tcase_add_test(tcase, test_111sprintf3);
  tcase_add_test(tcase, test_111sprintf4);
  tcase_add_test(tcase, test_111sprintf6);
  tcase_add_test(tcase, test_111sprintf7);
  tcase_add_test(tcase, test_111sprintf8);
  tcase_add_test(tcase, test_111sprintf9);
  tcase_add_test(tcase, test_111sprintf10);
  tcase_add_test(tcase, test_111sprintf11);
  tcase_add_test(tcase, test_111sprintf12);
  tcase_add_test(tcase, test_111sprintf14);
  tcase_add_test(tcase, test_111sprintf15);
  tcase_add_test(tcase, test_111sprintf16);
  tcase_add_test(tcase, test_111sprintf17);
  tcase_add_test(tcase, test_111sprintf18);
  tcase_add_test(tcase, test_111sprintf19);
  tcase_add_test(tcase, test_111sprintf20);
  tcase_add_test(tcase, test_111sprintf24);
  tcase_add_test(tcase, test_111sprintf25);
  tcase_add_test(tcase, test_111sprintf28);
  tcase_add_test(tcase, test_111sprintf29);
  tcase_add_test(tcase, test_111sprintf30);
  tcase_add_test(tcase, test_111sprintf31);
  tcase_add_test(tcase, test_111sprintf32);
  tcase_add_test(tcase, test_111sprintf33);
  tcase_add_test(tcase, test_111sprintf37);
  tcase_add_test(tcase, test_111sprintf38);
  tcase_add_test(tcase, test_111sprintf39);
  tcase_add_test(tcase, test_111sprintf40);
  tcase_add_test(tcase, test_111sprintf42);
  tcase_add_test(tcase, test_111sprintf43);
  tcase_add_test(tcase, test_111sprintf44);
  tcase_add_test(tcase, g_trailing_zero11);
  tcase_add_test(tcase, g_large1);
  tcase_add_test(tcase, g_small1);
  tcase_add_test(tcase, g_precision1);
  tcase_add_test(tcase, g_precision1_zero);
  tcase_add_test(tcase, g_precision1_missing);
  tcase_add_test(tcase, g_many1_zeroes_in_front1);
  tcase_add_test(tcase, g_one_zero1);
  tcase_add_test(tcase, g_short_no_mantiss1);
  tcase_add_test(tcase, g_zero1);
  tcase_add_test(tcase, width_char1);
  tcase_add_test(tcase, sprintf_simple_int);
  tcase_add_test(tcase, sprintf_space_int);
  tcase_add_test(tcase, sprintf_plus_int);
  tcase_add_test(tcase, sprintf_dot_int);
  tcase_add_test(tcase, sprintf_plus_2_int);
  tcase_add_test(tcase, sprintf_mixed_1_int);
  tcase_add_test(tcase, sprintf_mixed_2_int);
  tcase_add_test(tcase, sprintf_mixed_3_int);
  tcase_add_test(tcase, sprintf_c);
  tcase_add_test(tcase, sprintf_s);
  tcase_add_test(tcase, sprintf_mixed_1_f);
  tcase_add_test(tcase, sprintf_mixed_1_u);
  tcase_add_test(tcase, sprintf_mixed_2_u);
  tcase_add_test(tcase, sprintf_mixed_1_h);
  tcase_add_test(tcase, sprintf_ld);
  tcase_add_test(tcase, sprintf_hd);
  tcase_add_test(tcase, sprintf_ldazaza);
  tcase_add_test(tcase, sprintf_hdazaza);

  return s1;
}
