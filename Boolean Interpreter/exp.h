#include <stdlib.h>
#include <stdio.h>

struct node {
    char type;                 // Node type as a character ('N' for NUM, 'A' for AND, etc.)
    int value;                 // For NUM type, stores the number
    struct node *left, *right; // Left and right children for binary operations
};

// Functions to create nodes
struct node* create_num_node(int value) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->type = 'N';  // 'N' for NUM
    new_node->value = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}

struct node* create_binary_node(char type, struct node* left, struct node* right) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->type = type; // Set the type as a character ('A' for AND, 'O' for OR, etc.)
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

// Function to evaluate the AST
int evaluate_tree(struct node* tree) {
    if (!tree) return 0;

    switch (tree->type) {
        case 'N':  // NUM
            return tree->value;
        case 'A':  // AND
            return evaluate_tree(tree->left) && evaluate_tree(tree->right);
        case 'O':  // OR
            return evaluate_tree(tree->left) || evaluate_tree(tree->right);
        case 'X':  // NOT
            return !evaluate_tree(tree->left);
        case 'L':  // LT
            return evaluate_tree(tree->left) < evaluate_tree(tree->right);
        case 'l':  // LE
            return evaluate_tree(tree->left) <= evaluate_tree(tree->right);
        case 'G':  // GT
            return evaluate_tree(tree->left) > evaluate_tree(tree->right);
        case 'g':  // GE
            return evaluate_tree(tree->left) >= evaluate_tree(tree->right);
        case 'E':  // EQ
            return evaluate_tree(tree->left) == evaluate_tree(tree->right);
        case 'e':  // NE
            return evaluate_tree(tree->left) != evaluate_tree(tree->right);
        default:
            return 0;
    }
}

// Function to print the AST (pre-order traversal with indentation)
void print_tree(struct node* tree, int indent) {
    if (!tree) return;

    // Print spaces for indentation based on tree depth
    for (int i = 0; i < indent; i++) {
        printf("  ");  // Adjust number of spaces as needed for indentation
    }

    // Print the current node's type as a character
    switch (tree->type) {
        case 'N':  // NUM
            printf("NUM(%d)\n", tree->value);
            break;
        case 'A':  // AND
            printf("AND\n");
            break;
        case 'O':  // OR
            printf("OR\n");
            break;
        case 'X':  // NOT
            printf("NOT\n");
            break;
        case 'L':  // LT
            printf("LT\n");
            break;
        case 'l':  // LE
            printf("LE\n");
            break;
        case 'G':  // GT
            printf("GT\n");
            break;
        case 'g':  // GE
            printf("GE\n");
            break;
        case 'E':  // EQ
            printf("EQ\n");
            break;
        case 'e':  // NE
            printf("NE\n");
            break;
        default:
            printf("UNKNOWN\n");
            break;
    }

    // If it's a binary node, print its left and right children
    if (tree->left || tree->right) {
        if (tree->left) {
            print_tree(tree->left, indent + 1);  // Increase indentation for children
        }
        if (tree->right) {
            print_tree(tree->right, indent + 1);
        }
    }
}

