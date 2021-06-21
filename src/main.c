#include "bison-bug/parser.y.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int new_string_token(const char* str, YYSTYPE* val)
{
    int len = strlen(str);
    val->string = malloc(len + 1);
    strcpy(val->string, str);
    return TOK_STRING;
}

int main(int argc, char** argv)
{
    yypstate* parser = yypstate_new();

    YYSTYPE pushed_value;
    int pushed_char;
    int ret;

    pushed_char = new_string_token("string1", &pushed_value);
    printf("pushing %s\n", pushed_value.string);
    ret = yypush_parse(parser, pushed_char, &pushed_value);
    printf("push returned: %d\n", ret);

    pushed_char = new_string_token("string2", &pushed_value);
    printf("pushing %s\n", pushed_value.string);
    ret = yypush_parse(parser, pushed_char, &pushed_value);
    printf("push returned: %d\n", ret);

    pushed_char = new_string_token("string3", &pushed_value);
    printf("pushing %s\n", pushed_value.string);
    ret = yypush_parse(parser, pushed_char, &pushed_value);
    printf("push returned: %d\n", ret);

    pushed_char = new_string_token("string4", &pushed_value);
    printf("pushing %s\n", pushed_value.string);
    ret = yypush_parse(parser, pushed_char, &pushed_value);
    printf("push returned: %d\n", ret);

    yypstate_delete(parser);
    return 0;
}

