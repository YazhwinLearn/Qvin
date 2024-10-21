#include <stdio.h>
#include "lexer.h"

void test_lexer() {
    Lexer *lexer = lexer_new("1 + 2");
    TokenType token;

    token = lexer_next_token(lexer);
    printf("Token: %d\n", token); // Expect TOKEN_NUMBER
    token = lexer_next_token(lexer);
    printf("Token: %d\n", token); // Expect TOKEN_PLUS
    token = lexer_next_token(lexer);
    printf("Token: %d\n", token); // Expect TOKEN_NUMBER

    lexer_free(lexer);
}

int main() {
    test_lexer();
    return 0;
}
