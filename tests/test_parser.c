#include <assert.h>
#include "parser.h"
#include "lexer.h"

void test_parser() {
    const char* input = "12 + 34 - 5";
    Lexer* lexer = create_lexer(input);
    Parser* parser = create_parser(lexer);
    Node* ast = parse_expression(parser);

    assert(ast->type == TOKEN_MINUS);
    assert(ast->left->type == TOKEN_PLUS);
    assert(strcmp(ast->left->left->value, "12") == 0);
    assert(strcmp(ast->left->right->value, "34") == 0);
    assert(strcmp(ast->right->value, "5") == 0);

    free_node(ast);
    free_parser(parser);
    free_lexer(lexer);
    printf("All parser tests passed!\n");
}
