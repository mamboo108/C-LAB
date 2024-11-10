#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

struct node *createNode(int coeff, int exp) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct node *addTerm(struct node *head, int coeff, int exp) {
    struct node *temp = head, *prev = NULL;

    // Find the position to insert or add to the term with the same exponent
    while (temp != NULL && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }

    // If the exponent already exists, add to the coefficient
    if (temp != NULL && temp->exp == exp) {
        temp->coeff += coeff;
    } else {
        // Otherwise, create a new node and insert it in the right position
        struct node *newNode = createNode(coeff, exp);
        if (prev == NULL) {
            newNode->next = head;
            head = newNode;
        } else {
            newNode->next = temp;
            prev->next = newNode;
        }
    }
    return head;
}

struct node *polyMultiply(struct node *pHead, struct node *qHead) {
    struct node *result = NULL;

    for (struct node *p = pHead; p != NULL; p = p->next) {
        for (struct node *q = qHead; q != NULL; q = q->next) {
            int coeff = p->coeff * q->coeff;
            int exp = p->exp + q->exp;
            result = addTerm(result, coeff, exp);
        }
    }
    return result;
}

void printPoly(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *p1 = NULL, *p2 = NULL;
    int n1, n2, coeff, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        struct node *newNode = createNode(coeff, exp);
        newNode->next = p1;
        p1 = newNode;
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        struct node *newNode = createNode(coeff, exp);
        newNode->next = p2;
        p2 = newNode;
    }

    struct node *result = polyMultiply(p1, p2);
    printf("Resulting Polynomial: ");
    printPoly(result);

    return 0;
}
