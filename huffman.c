// Input : A total of 10 characters, and their probability distribution.
// Output : Huffman Code for these 10 characters. Calculate hand/code also.
/*
Enter character 1 and its probability: a 0.01
Enter character 2 and its probability: b 0.09
Enter character 3 and its probability: c 0.10
Enter character 4 and its probability: d 0.05
Enter character 5 and its probability: e 0.15
Enter character 6 and its probability: f 0.10
Enter character 7 and its probability: g 0.20
Enter character 8 and its probability: h 0.02
Enter character 9 and its probability: i 0.08
Enter character 10 and its probability: j 0.20
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 50

// Node structure for the Huffman tree
struct Node {
    char character;
    double probability;
    struct Node *left;
    struct Node *right;
};

// Priority queue to store nodes
struct PriorityQueue {
    struct Node *nodes[MAX_NODES];
    int size;
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

// Function to create a priority queue
struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->size = 0;
    return pq;
}

// Function to swap two nodes
void swap(struct Node **a, struct Node **b) {
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min-heap property of the priority queue
void heapify(struct PriorityQueue *pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->nodes[left]->probability < pq->nodes[smallest]->probability)
        smallest = left;

    if (right < pq->size && pq->nodes[right]->probability < pq->nodes[smallest]->probability)
        smallest = right;

    if (smallest != idx) {
        swap(&pq->nodes[idx], &pq->nodes[smallest]);
        heapify(pq, smallest);
    }
}

// Function to insert a node into the priority queue
void insert(struct PriorityQueue *pq, struct Node *node) {
    pq->size++;
    int i = pq->size - 1;
    while (i > 0 && node->probability < pq->nodes[(i - 1) / 2]->probability) {
        pq->nodes[i] = pq->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->nodes[i] = node;
}

// Function to extract the node with the lowest probability from the priority queue
struct Node* extractMin(struct PriorityQueue *pq) {
    struct Node *minNode = pq->nodes[0];
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;
    heapify(pq, 0);
    return minNode;
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(char characters[], double probabilities[], int n) {
    struct PriorityQueue *pq = createPriorityQueue();
    
    for (int i = 0; i < n; i++) {
        struct Node *node = createNode(characters[i], probabilities[i]);
        insert(pq, node);
    }

    while (pq->size > 1) {
        struct Node *left = extractMin(pq);
        struct Node *right = extractMin(pq);
        struct Node *internalNode = createNode('\0', left->probability + right->probability);
        internalNode->left = left;
        internalNode->right = right;
        insert(pq, internalNode);
    }

    return extractMin(pq);
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
    char characters[10];
    double probabilities[10];

    for (int i = 0; i < n; i++) {
        printf("Enter character %d and its probability: ", i + 1);
        scanf(" %c %lf", &characters[i], &probabilities[i]); 
    }

    struct Node *root = buildHuffmanTree(characters, probabilities, n);
    char code[MAX_NODES];
    int top = 0;

    printf("Huffman Codes:\n");
    printHuffmanCodes(root, code, top);

    return 0;
}