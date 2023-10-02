#include <stdio.h>
#include <stdlib.h>

// Node structure for the Huffman tree
struct Node {
    char character;
    double probability;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(char character, double probability) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->character = character;
    newNode->probability = probability;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(char characters[], double probabilities[], int n) {
    while (n > 1) {
        int min1 = 0;
        int min2 = 1;

        if (probabilities[min1] > probabilities[min2]) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        for (int i = 2; i < n; i++) {
            if (probabilities[i] < probabilities[min1]) {
                min2 = min1;
                min1 = i;
            } else if (probabilities[i] < probabilities[min2]) {
                min2 = i;
            }
        }

        struct Node *left = createNode(characters[min1], probabilities[min1]);
        struct Node *right = createNode(characters[min2], probabilities[min2]);
        struct Node *internalNode = createNode('\0', probabilities[min1] + probabilities[min2]);

        internalNode->left = left;
        internalNode->right = right;

        characters[min1] = '\0';
        characters[min2] = internalNode->character;

        probabilities[min1] = probabilities[min1] + probabilities[min2];
        probabilities[min2] = 1.0;  // A non-zero value

        n--;
    }

    return createNode(characters[0], probabilities[0]);
}

// Function to print Huffman codes
void printHuffmanCodes(struct Node *root, char code[], int top) {
    if (root->left) {
        code[top] = '0';
        printHuffmanCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printHuffmanCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        code[top] = '\0';
        printf("%c: %s\n", root->character, code);
    }
}

int main() {
    int n = 10;
    char characters[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    double probabilities[10] = {0.01, 0.09, 0.10, 0.05, 0.15, 0.10, 0.20, 0.02, 0.08, 0.20};

    struct Node *root = buildHuffmanTree(characters, probabilities, n);
    char code[50];  // Assuming a maximum code length of 50
    int top = 0;

    printf("Huffman Codes:\n");
    printHuffmanCodes(root, code, top);

    return 0;
}
