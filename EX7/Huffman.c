#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char character;
    float freq;
    struct Node* left;
    struct Node* right;
};

void dispNode(struct Node n) {
    printf("Character: %c\n", n.character);
    printf("Frequency: %.2f\n", n.freq);
}

struct Node* createNode(char character, float freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->character = character;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* huffmanTree(struct Node* n1, struct Node* n2) {
    struct Node* root = createNode('\0', n1->freq + n2->freq);
    root->left = n1;
    root->right = n2;
    return root;
}

void insertNode(struct Node** heap, int* size, struct Node* node) {
    heap[*size] = node;
    (*size)++;
    int i = *size - 1;
    while (i != 0 && heap[(i - 1) / 2]->freq > heap[i]->freq) {
        struct Node* temp = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = heap[i];
        heap[i] = temp;
        i = (i - 1) / 2;
    }
}

struct Node* extractMinNode(struct Node** heap, int* size) {
    if (*size <= 0) return NULL;
    if (*size == 1) {
        (*size)--;
        return heap[0];
    }
    struct Node* root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    int i = 0;
    while (i < *size) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < *size && heap[left]->freq < heap[smallest]->freq)
            smallest = left;
        if (right < *size && heap[right]->freq < heap[smallest]->freq)
            smallest = right;
        if (smallest != i) {
            struct Node* temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
    return root;
}

struct Node* huffmanConstr(struct Node* ele, int n) {
    struct Node* heap[n];
    int heapSize = 0;
    for (int i = 0; i < n; i++) {
        insertNode(heap, &heapSize, &ele[i]);
    }
    while (heapSize > 1) {
        struct Node* n1 = extractMinNode(heap, &heapSize);
        struct Node* n2 = extractMinNode(heap, &heapSize);
        struct Node* root = huffmanTree(n1, n2);
        insertNode(heap, &heapSize, root);
    }
    return heap[0];
}

int main() {
    char* str = (char*)malloc(sizeof(char) * 100);
    printf("Enter the string: ");
    scanf("%s", str);
    int n = strlen(str);
    printf("%d\n", n);

    // Sort the string
    for (int i = 1; i < n; i++) {
        char ref = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] > ref) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = ref;
    }

    int un = 1;
    char pc = str[0];
    for (int i = 1; i < n; i++) {
        if (pc != str[i]) {
            pc = str[i];
            un++;
        }
    }

    struct Node* A = (struct Node*)malloc(un * sizeof(struct Node));
    int* freq = (int*)malloc(un * sizeof(int));
    char* unc = (char*)malloc(un * sizeof(char));
    int ind = 0;
    pc = str[0];
    freq[0] = 0;

    for (int i = 0; i < n; i++) {
        if (pc == str[i]) {
            freq[ind]++;
        } else {
            unc[ind] = pc;
            ind++;
            pc = str[i];
            freq[ind] = 1;
        }
    }
    unc[ind] = pc;

    for (int i = 0; i < un; i++) {
        printf("%c - %.2f\n", unc[i], (float)freq[i] / n);
        A[i] = *createNode(unc[i], (float)freq[i] / n);
    }

    struct Node* root = huffmanConstr(A, un);
    printf("Root frequency: %.2f\n", root->freq);

    // Free allocated memory
    free(str);
    free(freq);
    free(unc);
    for (int i = 0; i < un; i++) {
        free(A[i].left);
        free(A[i].right);
    }
    free(A);

    return 0;
}