#include <stdlib.h>
#include "parser.h"

ASTNode *parser_parse(Lexer *lexer) {
    ASTNode *node = malloc(sizeof(ASTNode));
    TokenType token = lexer_next_token(lexer);

    if (token == TOKEN_NUMBER) {
        node->type = TOKEN_NUMBER;
        node->value = atoi(&lexer->source[lexer->position - 1]);
    } else {
        free(node);
        return NULL;
    }

    token = lexer_next_token(lexer);
    if (token == TOKEN_PLUS || token == TOKEN_MINUS) {
        node->type = token;
    } else {
        free(node);
        return NULL;
    }

    return node;
}

void ast_free(ASTNode *node) {
    free(node);
}
