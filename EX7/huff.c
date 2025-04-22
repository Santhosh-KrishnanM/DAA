#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct Node {
    char symbol;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

void printCodes(Node* , char [], int );

Node* createNode(char symbol, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->symbol = symbol;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Node* heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left]->frequency < heap[smallest]->frequency) {
        smallest = left;
    }
    if (right < size && heap[right]->frequency < heap[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

Node* extractMin(Node* heap[], int* size) {
    Node* minNode = heap[0];
    heap[0] = heap[--(*size)];
    minHeapify(heap, *size, 0);
    return minNode;
}

void insertHeap(Node* heap[], Node* node, int* size) {
    heap[(*size)++] = node;
    for (int i = (*size) / 2 - 1; i >= 0; i--) {
        minHeapify(heap, *size, i);
    }
}

void buildHuffmanTree(char symbols[], int frequencies[], int size) {
    Node* heap[MAX_TREE_NODES];
    int heapSize = 0;

    for (int i = 0; i < size; i++) {
        insertHeap(heap, createNode(symbols[i], frequencies[i]), &heapSize);
    }

    while (heapSize > 1) {
        Node* left = extractMin(heap, &heapSize);
        Node* right = extractMin(heap, &heapSize);
        Node* newNode = createNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        insertHeap(heap, newNode, &heapSize);
    }

    Node* root = heap[0];
    printf("Huffman Codes:\n");
    char code[MAX_TREE_NODES];
    int top = 0;
    printCodes(root, code, top);
}

void printCodes(Node* root, char code[], int top) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        code[top] = '\0';
        printf("%c: %s\n", root->symbol, code);
    }
}

int main() {
    char *input = NULL;
    size_t inputSize = 0;
    int frequencies[MAX_TREE_NODES] = {0};
    char symbols[MAX_TREE_NODES];
    int size = 0;
    printf("Enter a sentence: ");
    getline(&input, &inputSize, stdin);
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ' && input[i] != '\n') {
            int found = 0;
            for (int j = 0; j < size; j++) {
                if (symbols[j] == input[i]) {
                    frequencies[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                symbols[size] = input[i];
                frequencies[size] = 1;
                size++;
            }
        }
    }
    buildHuffmanTree(symbols, frequencies, size);
    free(input);
}