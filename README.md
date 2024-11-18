# cstring
## Cstring is a C library with implementation of easy-to-use, STL-like strings.

### Before usage you need to change macros "MEMORY_ALLOCATE_ERROR" and "DEREFERENCING_NULL_PTR" in [cstring.h](src/cstring.h) up to you project
```c
// src/cstring.h

/*-------------- change this in your project ---------------*/
#define MEMORY_ALLOCATE_ERROR 1
#define DEREFERENCING_NULL_PTR 2
/*----------------------------------------------------------*/
```

### Usage examples are stored in [main.c](src/main.c) file
```c
// src/main.c

int main(int argc, char *argv[]) {
  int i, err;

  String str = string_from("Hello, world!");
  String str2 = string_init();
  String str3 = string_from("");
  String str4 = string_from("string_cat_c_test");
  if (str == NULL || str2 == NULL || str3 == NULL) {
    return MEMORY_ALLOCATE_ERROR;
  }
// ...
```

### This project is under [MIT license](LICENSE)
