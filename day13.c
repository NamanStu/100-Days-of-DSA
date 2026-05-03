/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9*/
#include <stdio.h>
#include <stdlib.h>

int* traversal(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int total = rows * cols;
    int* result = (int*)malloc(total * sizeof(int));
    *returnSize = 0;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;


    while (*returnSize < total) {
        
  
        for (int i = left; i <= right && *returnSize < total; i++) {
            result[(*returnSize)++] = matrix[top][i];
        }
        top++; 

    
        for (int i = top; i <= bottom && *returnSize < total; i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--; 

     
        for (int i = right; i >= left && *returnSize < total; i--) {
            result[(*returnSize)++] = matrix[bottom][i];
        }
        bottom--; 


        for (int i = bottom; i >= top && *returnSize < total; i--) {
            result[(*returnSize)++] = matrix[i][left];
        }
        left++;  
    }

    return result; 
}


int main() {
    int r, c;
    printf("Enter the number of rows and columns of matrix:");
    if (scanf("%d %d", &r, &c) != 2) return 0;


    int** matrix = (int**)malloc(r * sizeof(int*));
    int* matrixColSize = (int*)malloc(r * sizeof(int));
    
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
        matrixColSize[i] = c; 
        for (int j = 0; j < c; j++) {
            printf("Enter element of %d row and %d column:",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int returnSize;
    int* result = traversal(matrix, r, matrixColSize, &returnSize);

    printf("RESULT: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", result[i], (i == returnSize - 1) ? "" : " ");
    }
    printf("\n");

    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(matrixColSize);
    free(result);

    return 0;
}