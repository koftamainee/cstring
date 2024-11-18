#include <stdio.h>

#include "cstring.h"

int main(int argc, char *argv[]) {
  int i, err;

  String str = string_from("Hello, world!");
  String str2 = string_init();
  String str3 = string_from("");
  String str4 = string_from("string_cat_c_test");
  if (str == NULL || str2 == NULL || str3 == NULL) {
    return MEMORY_ALLOCATE_ERROR;
  }

  for (i = 0; i < 52; i++) {
    err = string_add(&str2, i + 50);
    if (err) {
      string_free(str);
      string_free(str2);
      string_free(str3);
      string_free(str4);
      return err;
    }
  }
  printf("string_from(): ");
  string_print(str);
  printf("\nstring_init(): ");
  string_print(str2);
  printf("\n");

  string_grow(&str, 5);
  printf("string after -grow(): ");
  string_print(str);

  err = string_cpy_c(&str2, " string_cpy_c_test ");
  if (err) {
    string_free(str);
    string_free(str2);
    string_free(str3);
    string_free(str4);
    return err;
  }
  printf("\nstring_cpy_c(): ");
  string_print(str2);

  err = string_cat_c(&str2, " string_cat_c_test ");
  if (err) {
    string_free(str);
    string_free(str2);
    string_free(str3);
    string_free(str4);
    return err;
  }
  printf("\nstring_cat_c(): ");
  string_print(str2);

  printf("\nnow str3 == str2 (via string_cpy()): ");

  err = string_cpy(&str3, &str2);
  if (err) {
    string_free(str);
    string_free(str2);
    string_free(str3);
    string_free(str4);
    return err;
  }

  string_print(str3);

  printf("\nlet's double the content of str2 (via string_cat()): ");

  err = string_cat(&str2, &str3);
  if (err) {
    string_free(str);
    string_free(str2);
    string_free(str3);
    string_free(str4);
    return err;
  }

  string_print(str2);

  printf("\nnow we will compare str and str2 (via string_cmp()): %d\nstr1: ",
         string_cmp(str, str2));
  string_print(str);
  printf("\nstr2: ");
  string_print(str2);

  printf(
      "\nnow we will compare str2 and str3 (via string_lex_cmp()): %d\nstr2: ",
      string_lex_cmp(str2, str3));
  string_print(str2);
  printf("\nstr3: ");
  string_print(str3);

  printf("\nlet's find str4 in str2 (via string_str()): %d\nstr2: ",
         string_str(str2, str4));
  string_print(str2);
  printf("\nstr4: ");
  string_print(str4);
  printf("\nnow let's do the same via string_str_c(): %d\nstr2: ",
         string_str_c(str2, "string_cat_c_test"));
  string_print(str2);
  printf("\n");

  string_free(str);
  string_free(str2);
  string_free(str3);
  string_free(str4);
  return 0;
}