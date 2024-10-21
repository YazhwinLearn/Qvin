#include <stdio.h>
#include "interpreter.h"

int interpret(ASTNode *node) {
    if (node->type == TOKEN_NUMBER) {
        return node->value;
    }
    return 0; // Handle other cases later
}
