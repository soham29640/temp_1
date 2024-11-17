#include <stdio.h>

// Function to read a polynomial into an array
void readPolynomial(int poly[], int degree) {
    printf("Enter the coefficients from degree 0 to %d:\n", degree);
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &poly[i]);
    }
}

// Function to add two polynomials and store the result in a third array
void addPolynomials(int poly1[], int poly2[], int result[], int degree1, int degree2) {
    int maxDegree = (degree1 > degree2) ? degree1 : degree2;

    // Initialize the result array with 0s
    for (int i = 0; i <= maxDegree; i++) {
        result[i] = 0;
    }

    // Add corresponding coefficients of both polynomials
    for (int i = 0; i <= degree1; i++) {
        result[i] += poly1[i];
    }
    for (int i = 0; i <= degree2; i++) {
        result[i] += poly2[i];
    }
}

// Function to print the polynomial
void printPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%d", poly[i]);
            if (i > 0) {
                printf("x^%d", i);
            }
            if (i > 0 && poly[i-1] >= 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main() {
    int degree1, degree2, maxDegree;

    // Input the degree of the first polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    int poly1[degree1 + 1];

    // Read the first polynomial
    readPolynomial(poly1, degree1);

    // Input the degree of the second polynomial
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    int poly2[degree2 + 1];

    // Read the second polynomial
    readPolynomial(poly2, degree2);

    // Determine the maximum degree for the result
    maxDegree = (degree1 > degree2) ? degree1 : degree2;
    int result[maxDegree + 1];

    // Add the polynomials
    addPolynomials(poly1, poly2, result, degree1, degree2);

    // Print the resulting polynomial
    printf("Resultant Polynomial after addition: ");
    printPolynomial(result, maxDegree);

    return 0;
}
