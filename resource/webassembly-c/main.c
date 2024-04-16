#include <stdio.h>

#define N 3 // Define the size of the matrix (N x N)

// Function to multiply two matrices A and B, storing the result in C
void matrixMultiply()
{
    int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[N][N]; // To store result
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0; // Initialize the result matrix element
            for (int k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}