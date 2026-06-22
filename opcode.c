#include "monty.h"

void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},

        {"swap", swap},

        {"add", add},
        {"sub", sub},
        {"div", divi},
        {"mul", mul},
        {"mod", mod},

        {"nop", nop},
        {"pchar", pchar},
        {"pstr", pstr},
        {"rotl", rotl},   /* 🔥 THIS WAS MISSING */

        {NULL, NULL}
    };

    int i = 0;

    while (ops[i].opcode)
    {
        if (strcmp(ops[i].opcode, opcode) == 0)
            return ops[i].f;
        i++;
    }

    return NULL;
}
