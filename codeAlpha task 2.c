#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for Matrix Addition
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function for Matrix Multiplication
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function for Matrix Transpose
void transposeMatrix(int matrix[MAX][MAX], int trans[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            trans[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2, choice;

    while (1) {
        printf("\n=== MATRIX OPERATIONS MENU ===\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        switch (choice) {
            case 1:
                printf("Enter rows and columns for matrices: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter Matrix A:\n");
                inputMatrix(a, r1, c1);
                printf("Enter Matrix B:\n");
                inputMatrix(b, r1, c1);
                addMatrices(a, b, result, r1, c1);
                printf("Result of Addition:\n");
                displayMatrix(result, r1, c1);
                break;

            case 2:
                printf("Enter rows and columns for Matrix A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (c1 != r2) {
                    printf("Matrix multiplication not possible!\n");
                } else {
                    printf("Enter Matrix A:\n");
                    inputMatrix(a, r1, c1);
                    printf("Enter Matrix B:\n");
                    inputMatrix(b, r2, c2);
                    multiplyMatrices(a, b, result, r1, c1, c2);
                    printf("Result of Multiplication:\n");
                    displayMatrix(result, r1, c2);
                }
                break;

            case 3:
                printf("Enter rows and columns for Matrix: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter Matrix:\n");
                inputMatrix(a, r1, c1);
                transposeMatrix(a, result, r1, c1);
                printf("Result of Transpose:\n");
                displayMatrix(result, c1, r1);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
    