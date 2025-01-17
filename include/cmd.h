#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEF_SHORTHAND '\0'

typedef void (*Func)();

typedef struct flag {
    char* name;
    char shorthand;
} Flag;

Flag new_flag(char* name);
Flag new_flag_s(const char* name, const char shorthand);

typedef struct command {
    char* name;
    char* description;
    Func cmd;
    int flag_num;
    struct Flag* flags;
} Command;

Command new_command(const char* name, const char* description, Func cmd_function);
Command new_command_flag(const char* name, const char* description, Func cmd_function, const int flag_num, const Flag* flags);
void delete_command(Command* cmd);
void print_command(Command* cmd);