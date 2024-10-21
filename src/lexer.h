#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_EOF
} TokenType;

typedef struct {
    const char *source;
    size_t position;
} Lexer;

Lexer *lexer_new(const char *source);
TokenType lexer_next_token(Lexer *lexer);
void lexer_free(Lexer *lexer);

#endif // LEXER_H
