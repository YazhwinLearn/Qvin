#include <assert.h>
#include "src/interpreter.h"
#include "src/ast.h"

void test_interpreter() {
    Node* node = create_node(TOKEN_NUMBER, NULL, NULL, "42");
    int result = interpret(node);
    assert(result == 42);
    free_node(node);

    Node* node_plus = create_node(TOKEN_PLUS,
        create_node(TOKEN_NUMBER, NULL, NULL, "5"),
        create_node(TOKEN_NUMBER, NULL, NULL, "10"));
    result = interpret(node_plus);
    assert(result == 15);
    free_node(node_plus);

    Node* node_minus = create_node(TOKEN_MINUS,
        create_node(TOKEN_NUMBER, NULL, NULL, "20"),
        create_node(TOKEN_NUMBER, NULL, NULL, "5"));
    result = interpret(node_minus);
    assert(result == 15);
    free_node(node_minus);

    printf("All interpreter tests passed!\n");
}
