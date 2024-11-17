#include <stdio.h>

// Define a structure for representing a sparse matrix in 3-tuple format
struct SparseMatrix {
    int row;
    int col;
    int value;
};

// Function to transpose a sparse matrix
void transposeSparse(struct SparseMatrix matrix[], struct SparseMatrix transpose[]) {
    int i, j, k = 1;
    int totalRows = matrix[0].row;
    int totalCols = matrix[0].col;
    int totalValues = matrix[0].value;

    // First row stores the size information for the transposed matrix
    transpose[0].row = totalCols;  // Transposed matrix will have rows = original matrix columns
    transpose[0].col = totalRows;  // Transposed matrix will have columns = original matrix rows
    transpose[0].value = totalValues;

    // For each non-zero element, swap the row and column
    for (i = 0; i < totalCols; i++) {
        for (j = 1; j <= totalValues; j++) {
            if (matrix[j].col == i) {
                transpose[k].row = matrix[j].col; // Swap row and column
                transpose[k].col = matrix[j].row;
                transpose[k].value = matrix[j].value;
                k++;
            }
        }
    }
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
    int i, totalNonZero;

    // Example sparse matrix in 3-tuple format (with non-zero elements only)
    struct SparseMatrix matrix[10], transpose[10];

    // Input the matrix dimensions and the number of non-zero elements
    printf("Enter the number of rows, columns, and non-zero elements in the matrix: ");
    scanf("%d %d %d", &matrix[0].row, &matrix[0].col, &matrix[0].value);

    totalNonZero = matrix[0].value;

    // Input the non-zero elements (row, column, value)
    printf("Enter the non-zero elements (row, column, value):\n");
    for (i = 1; i <= totalNonZero; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }

    // Perform transpose
    transposeSparse(matrix, transpose);

    // Output the original and transposed sparse matrices
    printf("\nOriginal Sparse Matrix (3-tuple format):\n");
    printSparseMatrix(matrix);

    printf("\nTransposed Sparse Matrix (3-tuple format):\n");
    printSparseMatrix(transpose);

    return 0;
}
