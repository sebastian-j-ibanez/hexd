# hexd  🔍
![GitHub License](https://img.shields.io/github/license/sebastian-j-ibanez/hexd?color=red)

hexd is a CLI program that creates hex dumps.

## Usage
`hexd [file]`

## Example
Example C file:
```exaple.c
#include <stdio.h>

int main(void) {
    printf("Hello, hexd user!");
    return 0;
}
```
Hex dump:

![image](https://github.com/user-attachments/assets/5d01fe00-4f58-462a-8c06-5e9f5208d6c5)

## Building the project
The project is built using `make`. The default `make` target will create a `hexd` binary in the build folder.

***Note:*** If you use clangd, it is recommended to generate clangd config files with [compiledb](https://github.com/nickdiego/compiledb/tree/master).
