#include <stdio.h>

#define MAX 100

// Define structure to represent a sparse matrix in 3-tuple format
struct SparseMatrix {
    int row;
    int col;
    int value;
};

// Function to add two sparse matrices
void addSparseMatrices(struct SparseMatrix mat1[], struct SparseMatrix mat2[], struct SparseMatrix result[]) {
    int i = 1, j = 1, k = 1;
    int total1 = mat1[0].value;
    int total2 = mat2[0].value;

    // Initialize the result matrix size
    result[0].row = mat1[0].row;
    result[0].col = mat1[0].col;

    // Loop through both matrices
    while (i <= total1 && j <= total2) {
        // If the row and column positions match, add the values
        if (mat1[i].row == mat2[j].row && mat1[i].col == mat2[j].col) {
            result[k].row = mat1[i].row;
            result[k].col = mat1[i].col;
            result[k].value = mat1[i].value + mat2[j].value;
            i++;
            j++;
        }
        // If mat1's position is smaller, add it to the result
        else if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[k].row = mat1[i].row;
            result[k].col = mat1[i].col;
            result[k].value = mat1[i].value;
            i++;
        }
        // If mat2's position is smaller, add it to the result
        else {
            result[k].row = mat2[j].row;
            result[k].col = mat2[j].col;
            result[k].value = mat2[j].value;
            j++;
        }
        k++;
    }

    // Add remaining elements from mat1 (if any)
    while (i <= total1) {
        result[k].row = mat1[i].row;
        result[k].col = mat1[i].col;
        result[k].value = mat1[i].value;
        i++;
        k++;
    }

    // Add remaining elements from mat2 (if any)
    while (j <= total2) {
        result[k].row = mat2[j].row;
        result[k].col = mat2[j].col;
        result[k].value = mat2[j].value;
        j++;
        k++;
    }

    // Set the total number of non-zero values in the result matrix
    result[0].value = k - 1;
}

// Function to print a sparse matrix in 3-tuple format
void printSparseMatrix(struct SparseMatrix matrix[]) {
    int i;
    printf("Row\tCol\tValue\n");
    for (i = 0; i <= matrix[0].value; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    int i, n1, n2;

    struct SparseMatrix mat1[MAX], mat2[MAX], result[MAX];

    // Input the first sparse matrix
    printf("Enter the number of rows, columns, and non-zero elements of the first matrix: ");
    scanf("%d %d %d", &mat1[0].row, &mat1[0].col, &mat1[0].value);
    n1 = mat1[0].value;

    printf("Enter the non-zero elements (row, column, value) of the first matrix:\n");
    for (i = 1; i <= n1; i++) {
        scanf("%d %d %d", &mat1[i].row, &mat1[i].col, &mat1[i].value);
    }

    // Input the second sparse matrix
    printf("Enter the number of rows, columns, and non-zero elements of the second matrix: ");
    scanf("%d %d %d", &mat2[0].row, &mat2[0].col, &mat2[0].value);
    n2 = mat2[0].value;

    printf("Enter the non-zero elements (row, column, value) of the second matrix:\n");
    for (i = 1; i <= n2; i++) {
        scanf("%d %d %d", &mat2[i].row, &mat2[i].col, &mat2[i].value);
    }

    // Check if the matrices have the same dimensions
    if (mat1[0].row != mat2[0].row || mat1[0].col != mat2[0].col) {
        printf("Matrices cannot be added! They have different dimensions.\n");
        return 0;
    }

    // Add the two sparse matrices
    addSparseMatrices(mat1, mat2, result);

    // Output the result sparse matrix
    printf("\nFirst Sparse Matrix (3-tuple format):\n");
    printSparseMatrix(mat1);

    printf("\nSecond Sparse Matrix (3-tuple format):\n");
    printSparseMatrix(mat2);

    printf("\nResultant Sparse Matrix after Addition (3-tuple format):\n");
    printSparseMatrix(result);

    return 0;
}
