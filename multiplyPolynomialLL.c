#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int expo;
    struct Node* next;
};

struct Node* createNode(int coeff, int expo) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertTerm(struct Node* head, int coeff, int expo) {
    if (coeff == 0) return head;

    struct Node* temp = createNode(coeff, expo);

    if (head == NULL || expo > head->expo) {
        temp->next = head;
        return temp;
    }

    struct Node* current = head;
    
    if (head->expo == expo) {
        head->coeff += coeff;
        free(temp);
        return head;
    }

    while (current->next != NULL && current->next->expo >= expo) {
        current = current->next;
    }

    if (current->expo == expo) {
        current->coeff += coeff;
        free(temp);
    } 
    else if (current->next != NULL && current->next->expo == expo) {
        current->next->coeff += coeff;
        free(temp);
    }
    else {
        temp->next = current->next;
        current->next = temp;
    }

    return head;
}

void appendNode(struct Node** head, struct Node** tail, int coeff, int pow) {
    if (coeff == 0) return; 

    struct Node* newNode = createNode(coeff, pow);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* ptr1 = poly1;
    struct Node* ptr2 = poly2;

    if (poly1 == NULL || poly2 == NULL) {
        return NULL;
    }

    while (ptr1 != NULL) {
        ptr2 = poly2;
        while (ptr2 != NULL) {
            int coeff = ptr1->coeff * ptr2->coeff;
            int expo = ptr1->expo + ptr2->expo;

            result = insertTerm(result, coeff, expo);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return result;
}

void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != NULL && temp->coeff >= 0) {
            printf(" + ");
        } else if (temp != NULL && temp->coeff < 0) {
            printf(" ");
        }
    }
    printf("\n");
}

struct Node* inputPolynomial() {
	
	int i,numTerms, coeff, expo;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
	printf("Enter the number of terms: ");
    scanf("%d", &numTerms);

    for (i = 0; i < numTerms; i++) 
	{
        printf("Enter coefficient and power for term %d (e.g., 5 3 for 5x^3): ", i + 1);
        scanf("%d %d", &coeff, &expo);
        appendNode(&head, &tail, coeff, expo);
    }
    return head;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    printf("--- First Polynomial ---\n");
    poly1 = inputPolynomial();

    printf("\n--- Second Polynomial ---\n");
    poly2 = inputPolynomial();

    printf("\n First Polynomial: ");
    displayPolynomial(poly1);

    printf("\n Second Polynomial: ");
    displayPolynomial(poly2);

    result = multiplyPolynomials(poly1, poly2);

    printf("\n Resultant Product: ");
    displayPolynomial(result);

    freeList(poly1);
    freeList(poly2);
    freeList(result);

    return 0;
}
