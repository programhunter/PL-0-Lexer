#include <stdio.h>
#include <stdlib.h>


#define TOK_WIDTH 13    // The max width needed to print a token

// Each token of the program will be placed in a tokNode
struct tokNode {
    char tok[TOK_WIDTH];
    int tokType;
    struct tokNode *next;
};


// Mel's list of possible token names
const char token[34][TOK_WIDTH]={"", "nulsym", "identsym", "numbersym", "plussym", "minussym", "multsym", "slashsym", "oddsym", "eqlsym", "neqsym", "lessym", "leqsym", "gtrsym", "geqsym", "lparentsym", "rparentsym", "commasym", "semicolonsym", "periodsym", "becomessym", "beginsym", "endsym", "ifsym", "thensym", "whilesym", "dosym", "callsym", "constsym", "varsym", "procsym", "writesym", "readsym", "elsesym"};


void analyzeTokens();   // Display all tokens found within the program
struct tokNode *makeTokNode();  // Makes a new token node for the linked list
void setNode(struct tokNode *emptyNode, char *sym, int symNum); // Saves a token to a node
void printTokens(struct tokNode *head); // Displays all of the tokens found in the program



int main(int argc, char * argv[])
{
    analyzeTokens();

    return 0;
}


// Prints the 3rd output option - each token found in the program
void analyzeTokens()
{
    struct tokNode *root;   // Top of linked list.  Will not change
    struct tokNode *tmp;    // Will traverse the tokNode linked list
    char currTok[TOK_WIDTH];    // The current token symbol
    int symNum = 0;         // Token identifier.  See const int symbols

    // Creates space for the root node in memory
    root = malloc( sizeof(struct tokNode) );
    // Checks if not enough memory to even create the root node
    if (root == NULL) {
        return -1;
    }
    root->next = NULL;  // Sets the next pointer of root node to null
    root->tokType = 0;  // Sets the default token type to null - non-existent
    tmp = root;     // Starts the tmp pointer at the top of the linked list


    /* -------------------------------------------------------------------- */
    /* --- START OF TEMPORARY DEMO FOR HOW TO ADD TOKENS TO LINKED LIST --- */
    /* -------------------------------------------------------------------- */
    strcpy(currTok, token[symNum]); // Retrieves the name of the token
    setNode(tmp, currTok, symNum);  // Add the first value to the linked list

    for (symNum = 1; symNum < 9; symNum++)
    {
        tmp->next = makeTokNode();  // Adds the new node to the linked list
        // If not enough memory to create a new node, then stop program
        if (tmp->next == NULL) {
            return -1;
        }
        tmp = tmp->next;    // Move tmp to the new bottom of the list

        strcpy(currTok, token[symNum]); // Retrieves the name of the token
        setNode(tmp, currTok, symNum);  // Add the first value to the linked list
    }
    /* ------------------------------------------------------------------ */
    /* --- END OF TEMPORARY DEMO FOR HOW TO ADD TOKENS TO LINKED LIST --- */
    /* ------------------------------------------------------------------ */


    // Display the contents of the entire linked list
    printTokens(root);


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


// Creates a new node which could be added to the linked list of tokens.
struct tokNode *makeTokNode()
{
    // Creates a new node of type tokNode
    struct tokNode *nuevoNode;
    nuevoNode = malloc( sizeof(struct tokNode) );

    // Safely initializes the values of the new node
    nuevoNode->next = NULL;
    nuevoNode->tokType = 0;

    // Provides the caller with a pointer to the new node
    return nuevoNode;
}


// Fills an empty node with data - the symbol (token) and symbol number
void setNode(struct tokNode *emptyNode, char *sym, int symNum)
{
    strcpy( emptyNode->tok, sym );  // Sets the name of the token
    emptyNode->tokType = symNum;    // Sets the symbol (token) number
}


// Prints the tokens from the program by traversing the tokType linked list
void printTokens(struct tokNode *head)
{
    printf("tokens:\n-------\n");

    // Print the contents of the tokNode linked list
    while (head != NULL) {
        printf("%-13s\t%d\n", head->tok, head->tokType);
        head = head->next;
    }
}
