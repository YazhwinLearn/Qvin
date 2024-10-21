#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct {
    TokenType type;
    int value;
} ASTNode;

ASTNode *parser_parse(Lexer *lexer);
void ast_free(ASTNode *node);

#endif // PARSER_H
