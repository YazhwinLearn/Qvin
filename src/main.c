#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

int main(int argc, char **argv) {
    const char *source = "1 + 2";
    Lexer *lexer = lexer_new(source);
    ASTNode *node = parser_parse(lexer);

    if (node) {
        int result = interpret(node);
        printf("Result: %d\n", result);
        ast_free(node);
    } else {
        printf("Parsing failed.\n");
    }

    lexer_free(lexer);
    return 0;
}
