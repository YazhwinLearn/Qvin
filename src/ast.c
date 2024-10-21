#include <stdlib.h>
#include <string.h>
#include "ast.h"

Node* create_node(int type, Node* left, Node* right, char* value) {
    Node* node = malloc(sizeof(Node));
    node->type = type;
    node->left = left;
    node->right = right;
    node->value = value ? strdup(value) : NULL;
    return node;
}

void free_node(Node* node) {
    if (node) {
        free_node(node->left);
        free_node(node->right);
        free(node->value);
        free(node);
    }
}
