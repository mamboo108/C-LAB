#include <stdio.h>
#include <stdlib.h>

#define size 10

struct node {
    int data;
    struct node *next;
};

struct hashtable {
    struct node *chaining[size];
    int linear[size];
};

struct node *create(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct hashtable *createhash() {
    struct hashtable *hash = (struct hashtable *)malloc(sizeof(struct hashtable));
    for (int i = 0; i < size; i++) {
        hash->chaining[i] = NULL;
        hash->linear[i] = -1;
    }
    return hash;
}

void insertchain(struct hashtable *hash, int data) {
    int index = data % size;
    struct node *newnode = create(data);
    if (hash->chaining[index] == NULL) {
        hash->chaining[index] = newnode;
    } else {
        struct node *current = hash->chaining[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

void insertlinear(struct hashtable *hash, int data) {
    int index = data % size;
    while (hash->linear[index] != -1) {
        index = (index + 1) % size;
    }
    hash->linear[index] = data;
}

void displaychaining(struct hashtable *hash) {
    for (int i = 0; i < size; i++) {
        printf("Index %d: ", i);
        struct node *current = hash->chaining[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");  // End of chain
    }
}

void displaylinear(struct hashtable *hash) {
    for (int i = 0; i < size; i++) {
        printf("Index %d: %d\n", i, hash->linear[i]);
    }
}

int main() {
    struct hashtable *hash = createhash();
    char ch;
    int opt;
    int data;
    
    do {
        printf("\nMenu:\n");
        printf("1. Insert into Chaining Method\n");
        printf("2. Insert into Linear Probing Method\n");
        printf("3. Display Chaining Method\n");
        printf("4. Display Linear Probing Method\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        
        switch (opt) {
            case 1:
                printf("Enter key to insert using Chaining Method: ");
                scanf("%d", &data);
                insertchain(hash, data);
                break;
            case 2:
                printf("Enter key to insert using Linear Probing Method: ");
                scanf("%d", &data);
                insertlinear(hash, data);
                break;
            case 3:
                printf("Hash Table using Chaining Method:\n");
                displaychaining(hash);
                break;
            case 4:
                printf("Hash Table using Linear Probing Method:\n");
                displaylinear(hash);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
        
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &ch);  // Corrected character input format
        
    } while (ch == 'y' || ch == 'Y');
    
    return 0;
}
