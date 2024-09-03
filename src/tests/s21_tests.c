#include <check.h>

Suite *string_suite(void);
Suite *sprintf_suite(void);
Suite *sscanf_suite(void);

int main(void) {
  int number_failed;

  SRunner *sr = srunner_create(string_suite());
  srunner_add_suite(sr, sprintf_suite());
  srunner_add_suite(sr, sscanf_suite());

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
