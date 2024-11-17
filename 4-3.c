#include <stdio.h>
#include <stdlib.h>


struct Node {
    int coeff;      
    int exp;        
    struct Node* next;
};


struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}


void insertTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL && temp->next->exp > exp) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->exp == exp) {
            temp->next->coeff += coeff;  
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}


void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }

    while (poly != NULL) {
        printf("%d*x^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL && poly->coeff >= 0)
            printf(" + ");
        else if (poly != NULL && poly->coeff < 0)
            printf(" ");
    }
    printf("\n");
}


struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n, coeff, exp;

    // Input first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent (e.g. 3 2 for 3*x^2): ");
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    // Input second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent (e.g. 2 1 for 2*x^1): ");
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    // Display the polynomials
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);
    
    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    // Add the polynomials
    sum = addPolynomials(poly1, poly2);

    // Display the result
    printf("\nSum of the Polynomials: ");
    displayPolynomial(sum);

    return 0;
}
