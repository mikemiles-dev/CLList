#include <stdlib.h>
#include <stdio.h>

struct LList {
    struct Node *root;
    int size; 
};

struct LList new_list(int a[], int size);
void print_list(struct LList l);
void sort(struct LList l);
void swap(struct Node *a, struct Node *b);

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
    }
    printf("\n");
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
    }
}

void swap(struct Node *a, struct Node *b) {
    int temp = b->value;
    b->value = a->value;
    a->value = temp;
}

int main() {
    int a[] = {9, 1, 4, 13, 11, 8, 7, 2, 3};

    struct LList linked_list = new_list(a, 9);

    printf("Unsorted List: ");
    print_list(linked_list);

    sort(linked_list);

    printf("Sorted List: ");
    print_list(linked_list);

    return 0;
}