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

struct node *polyAdd(struct node *pHead, struct node *qHead) {
    struct node *rHead = NULL, *r = NULL;
    while (pHead != NULL && qHead != NULL) {
        if (pHead->exp == qHead->exp) {
            if (rHead == NULL) {
                rHead = createNode(pHead->coeff + qHead->coeff, pHead->exp);
                r = rHead;
            } else {
                r->next = createNode(pHead->coeff + qHead->coeff, pHead->exp);
                r = r->next;
            }
            pHead = pHead->next;
            qHead = qHead->next;
        } else if (pHead->exp > qHead->exp) {
            if (rHead == NULL) {
                rHead = createNode(pHead->coeff, pHead->exp);
                r = rHead;
            } else {
                r->next = createNode(pHead->coeff, pHead->exp);
                r = r->next;
            }
            pHead = pHead->next;
        } else {
            if (rHead == NULL) {
                rHead = createNode(qHead->coeff, qHead->exp);
                r = rHead;
            } else {
                r->next = createNode(qHead->coeff, qHead->exp);
                r = r->next;
            }
            qHead = qHead->next;
        }
    }
    while (pHead != NULL) {
        if (rHead == NULL) {
            rHead = createNode(pHead->coeff, pHead->exp);
            r = rHead;
        } else {
            r->next= createNode(pHead->coeff, pHead->exp);
            r = r->next;
        }
        pHead = pHead->next;
    }
    while (qHead != NULL) {
        if (rHead == NULL) {
            rHead = createNode(qHead->coeff, qHead->exp);
            r = rHead;
        } else {
            r->next = createNode(qHead->coeff, qHead->exp);
            r = r->next;
        }
        qHead = qHead->next;
    }
    return rHead;
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

    struct node *result = polyAdd(p1, p2);
    printf("Resulting Polynomial: ");
    printPoly(result);

    return 0;
}
