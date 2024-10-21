#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

Lexer *lexer_new(const char *source) {
    Lexer *lexer = malloc(sizeof(Lexer));
    lexer->source = source;
    lexer->position = 0;
    return lexer;
}

TokenType lexer_next_token(Lexer *lexer) {
    while (lexer->source[lexer->position] != '\0') {
        char c = lexer->source[lexer->position];

        if (c >= '0' && c <= '9') {
            lexer->position++;
            return TOKEN_NUMBER;
        } else if (c == '+') {
            lexer->position++;
            return TOKEN_PLUS;
        } else if (c == '-') {
            lexer->position++;
            return TOKEN_MINUS;
        }

        lexer->position++;
    }
    return TOKEN_EOF;
}

void lexer_free(Lexer *lexer) {
    free(lexer);
}
