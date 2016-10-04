#include <stdio.h>
#include <stdlib.h>


#define TOK_WIDTH 13    // The max width needed to print a token

// Each token of the program will be placed in a tokNode
struct tokNode {
    char tok[TOK_WIDTH];
    int tokType;
    struct tokNode *next;
};


void printTokens(struct tokNode *head);	// Prints the tokens found in the program


int main()
{
    // Will always stay at the top of tokNode linked list
    struct tokNode *root;
    // Will traverse the tokNode linked list
    struct tokNode *tmp;

    // Creates space for the root node in memory
    root = malloc( sizeof(struct tokNode) );
    // Checks if not enough memory to even create the root node
    if (root == NULL) {
        return -1;
    }
    root->next = NULL;  // Sets the next pointer of root node to null
    root->tokType = 0;  // Sets the default token type to null - non-existent
    tmp = root;     // Starts the tmp pointer at the top of the linked list



    /* TEST AREA - DELETE ME LATER PLZ */
    strcpy( tmp->tok, "nulsym" );
    tmp->tokType = 2;
    printTokens(root);
    /* END OF TEST AREA */



    // Frees up the nodes in the tokNode linked list
    tmp = root;
    while (tmp->next != NULL) {
        root = tmp;
        free(tmp);
        tmp = root->next;
    }
    free(root);

    return 0;
}



// Prints the tokens from the program by traversing the tokType linked list
void printTokens(struct tokNode *head)
{
    printf("tokens:\n-------\n");

    // If a linked list was not passed, then simply return
    if (head == NULL) {
        return;
    }

    // Print the contents of the tokNode linked list
    while (head->next != NULL) {
        printf("%s\t\t%d", head->tok, head->tokType);
    }
    printf("%s\t\t%d", head->tok, head->tokType);
}
