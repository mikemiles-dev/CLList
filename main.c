#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct LList {
    struct Node *root;
    int size; 
};

struct LList new_list(int a[], int size);
int* list_to_array(struct LList l);
void print_list(struct LList l);
void sort(struct LList l);
void swap(struct Node *a, struct Node *b);
int areEqual(int arr1[], int arr2[], int n, int m);

struct Node {
    int value;
    struct Node *next;
};

struct LList new_list(int a[], int size) {
    struct LList l;
    struct Node *n = malloc(sizeof(struct LList));
    l.root = n;
    l.size = size;
    for (int i = 0; i < size; i++) {
        n->value = a[i];
        struct Node *new = malloc(sizeof(struct LList));
        n->next = new;
        n = new;
    }
    return l;
}

void print_list(struct LList l) {
    if (l.root != NULL) {
        struct Node *n = l.root;
        while(n->next != NULL) {
            printf("%d ", n->value);
            n = n->next;
        }
        free(n);
    }
    printf("\n");
}

int* list_to_array(struct LList l) {
    int *t = malloc(l.size * sizeof(int));
    struct Node * n = l.root;
    for (int i = 0; i < l.size; i++) {
        t[i] = n->value;
        n = n->next;
    }
    return t;
}

void sort(struct LList l) {
    if (l.root != NULL) {
        struct Node *n = l.root;
        struct Node *p = l.root;
        int count = 0;
        while (n->next != NULL) {
            for (int i = 0; i < count; i++) {
                if (p->value > n->value) {
                    swap(p, n);
                }
                p = p->next;
            }
            count = count + 1;
            n = n->next;
            p = l.root;
        }
        free(n);
    }
}

int areEqual(int arr1[], int arr2[], int n, int m) {
    // If lengths of array are not equal means
    // array are not equal
    if (n != m) {
        return 0;
    }
 
    // Linearly compare elements
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
 
    // If all elements were same.
    return 1;
}

void swap(struct Node *a, struct Node *b) {
    int temp = b->value;
    b->value = a->value;
    a->value = temp;
}

int main() {
    int unsorted[] = {9, 1, 4, 13, 11, 8, 7, 2, 3};
    int sorted[] = {1, 2, 3, 4, 7, 8, 9, 11, 13};
    int size = 9;

    struct LList linked_list = new_list(unsorted, size);

    sort(linked_list);

    int *b = list_to_array(linked_list);

    assert(areEqual(b, sorted, size, size));

    return 0;
}