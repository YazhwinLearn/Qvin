#ifndef AST_H
#define AST_H

typedef struct Node {
    enum { TOKEN_NUMBER, TOKEN_PLUS, TOKEN_MINUS } type;
    struct Node* left;  // Pointer to left child
    struct Node* right; // Pointer to right child
    char* value;        // Value for TOKEN_NUMBER
} Node;

Node* create_node(int type, Node* left, Node* right, char* value);
void free_node(Node* node);

#endif
