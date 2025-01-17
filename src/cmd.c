#include "cmd.h"

Flag new_flag(char* name) {
    Flag f;
    f.name = name;
    f.shorthand = DEF_SHORTHAND;
    return f;
}

Flag new_flag_s(const char* name, const char shorthand) {
    Flag f;
    f.name = strdup(name);
    f.shorthand = shorthand;
    return f;
}

Command new_command(const char* name, const char* description, Func cmd_function) {
    Command c;
    c.name = strdup(name);
    c.description = strdup(description);
    c.cmd = cmd_function;
    c.flag_num = 0;
    c.flags = NULL;
    return c;
}

Command new_command_flag(const char* name, const char* description, Func cmd_function, const int flag_num, const Flag* flags) {
    Command c;
    c.name = strdup(name);
    c.description = strdup(description);
    c.cmd = cmd_function;

    if (flag_num > 0 && flags != NULL) {
        c.flag_num = flag_num;
        const size_t flags_size = sizeof(Flag) * flag_num;  
        c.flags = malloc(flags_size);
        memcpy(c.flags, flags, flags_size);
    } else {
        c.flag_num = 0;
        c.flags = NULL;
    }

    return c;
}

void free_command(Command* cmd) {
    if (cmd->flag_num > 0 && cmd->flags != NULL) {
        free(cmd->flags);
    }
}

void print_command(Command* cmd) {
    if (cmd == NULL) {
        
    }

    fprintf("%s", cmd->description);
}
