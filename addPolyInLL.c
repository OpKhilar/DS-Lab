#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a single polynomial term
struct Node {
    int coeff;          // Coefficient of the term
    int pow;            // Exponent/Power of the term
    struct Node* next;  // Pointer to the next term
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of a polynomial linked list
void appendNode(struct Node** head, struct Node** tail, int coeff, int pow) {
    // If the coefficient is 0, skip creating the node
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

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* resultHead = NULL;
    struct Node* resultTail = NULL;

    // Traverse both lists until one becomes empty
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            // Case 1: First polynomial has a higher exponent
            appendNode(&resultHead, &resultTail, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            // Case 2: Second polynomial has a higher exponent
            appendNode(&resultHead, &resultTail, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            // Case 3: Exponents are equal, add coefficients
            int sumCoeff = poly1->coeff + poly2->coeff;
            appendNode(&resultHead, &resultTail, sumCoeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Append remaining terms of the first polynomial, if any
    while (poly1 != NULL) {
        appendNode(&resultHead, &resultTail, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    // Append remaining terms of the second polynomial, if any
    while (poly2 != NULL) {
        appendNode(&resultHead, &resultTail, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return resultHead;
}

// Function to display the polynomial in standard mathematical format
void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    int isFirst = 1;
    while (poly != NULL) {
        if (!isFirst && poly->coeff > 0) {
            printf(" + ");
        } else if (poly->coeff < 0) {
            printf(" - ");
        }

        // Print absolute value for cleaner sign handling
        int absCoeff = (poly->coeff < 0) ? -poly->coeff : poly->coeff;

        if (poly->pow == 0) {
            printf("%d", absCoeff);
        } else if (poly->pow == 1) {
            printf("%dx", absCoeff);
        } else {
            printf("%dx^%d", absCoeff, poly->pow);
        }

        isFirst = 0;
        poly = poly->next;
    }
    printf("\n");
}

// Helper function to build a polynomial from user input (sorted by powers descending)
struct Node* inputPolynomial() {
	int i;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int numTerms, coeff, pow;

    printf("Enter the number of terms: ");
    scanf("%d", &numTerms);

    for (i = 0; i < numTerms; i++) {
        printf("Enter coefficient and power for term %d (e.g., 5 3 for 5x^3): ", i + 1);
        scanf("%d %d", &coeff, &pow);
        appendNode(&head, &tail, coeff, pow);
    }
    return head;
}

// Function to free allocated memory
void freePolynomial(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main execution entry point
int main() {
    printf("--- First Polynomial ---\n");
    struct Node* poly1 = inputPolynomial();

    printf("\n--- Second Polynomial ---\n");
    struct Node* poly2 = inputPolynomial();

    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    struct Node* sumResult = addPolynomials(poly1, poly2);

    printf("Resultant Sum   : ");
    displayPolynomial(sumResult);

    // Free memory blocks
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sumResult);

    return 0;
}