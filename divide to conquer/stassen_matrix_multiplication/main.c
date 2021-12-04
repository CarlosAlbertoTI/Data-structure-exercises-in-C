#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int size)
{
	printf("\n------------------------------------\n");
	printf("Show the matrix");
	printf("\n------------------------------------\n");

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%i ", matrix[i][j]);
		}
		printf("\n");
	}
}

void addValuesToMatriz(int **matrix, int size)
{
	printf("\n------------------------------------\n");
	printf("Adding value to Matrix");
	printf("\n------------------------------------\n");

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("Insert the value of position [%i][%i] : ", i + 1, j + 1);
			scanf("%i", &matrix[i][j]);
		}
	}
}

int **initMatrix(int n)
{
	int **matrix = (int **)malloc(n * n * sizeof(int));
	if (matrix == NULL)
	{
		printf("Error na criação da matrix");
	}
	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int *)malloc(n * sizeof(int));
		if (matrix[i] == NULL)
		{
			printf("Error na criação da matrix");
		}
	}
	return matrix;
}

void cleanMemoryMatrix(int **matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

int **add(int **M1, int **M2, int n)
{
	int **temp = initMatrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = M1[i][j] + M2[i][j];
	return temp;
}

int **subtract(int **M1, int **M2, int n)
{
	int **temp = initMatrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = M1[i][j] - M2[i][j];
	return temp;
}

int **strassen(int **mat1, int **mat2, int size)
{
	// ? if the size of the matrix is one, them we just have to multiply the values of mat1[0][0] * mat2[1][1]
	if (size == 1)
	{
		int **C = initMatrix(1);
		C[0][0] = mat1[0][0] * mat2[0][0];
		return C;
	}
	else
	{
		// ? If not, them we need to slip the matrix in 4 pieces and apply the algorithm again

		// first initialize the matrix C
		int **C = initMatrix(size);
		int splitSize = size / 2;

		// now we created the submatrizes and
		int **A11 = initMatrix(splitSize);
		int **A12 = initMatrix(splitSize);
		int **A21 = initMatrix(splitSize);
		int **A22 = initMatrix(splitSize);
		int **B11 = initMatrix(splitSize);
		int **B12 = initMatrix(splitSize);
		int **B21 = initMatrix(splitSize);
		int **B22 = initMatrix(splitSize);

		for (int i = 0; i < splitSize; i++)
			for (int j = 0; j < splitSize; j++)
			{
				A11[i][j] = mat1[i][j];
				A12[i][j] = mat1[i][splitSize + j];
				A21[i][j] = mat1[splitSize + i][j];
				A22[i][j] = mat1[splitSize + i][splitSize + j];
				B11[i][j] = mat2[i][j];
				B12[i][j] = mat2[i][splitSize + j];
				B21[i][j] = mat2[splitSize + i][j];
				B22[i][j] = mat2[splitSize + i][splitSize + j];
			}

		// Here the recursion comes in!
		// Now we calculate all the submatrizes until splitSize == 1;
		int **P1 = strassen(A11, subtract(B12, B22, splitSize), splitSize);
		int **P2 = strassen(add(A11, A12, splitSize), B22, splitSize);
		int **P3 = strassen(add(A21, A22, splitSize), B11, splitSize);
		int **P4 = strassen(A22, subtract(B21, B11, splitSize), splitSize);
		int **P5 = strassen(add(A11, A22, splitSize), add(B11, B22, splitSize), splitSize);
		int **P6 = strassen(subtract(A12, A22, splitSize), add(B21, B22, splitSize), splitSize);
		int **P7 = strassen(subtract(A11, A21, splitSize), add(B11, B12, splitSize), splitSize);

		

		// Now calculate the position on the final matrix
		int **C11 = subtract(add(add(P5, P4, splitSize), P6, splitSize), P2, splitSize);
		int **C12 = add(P1, P2, splitSize);
		int **C21 = add(P3, P4, splitSize);
		int **C22 = subtract(subtract(add(P5, P1, splitSize), P3, splitSize), P7, splitSize);

		for (int i = 0; i < splitSize; i++){
			for (int j = 0; j < splitSize; j++)
			{
				C[i][j] = C11[i][j];
				C[i][j + splitSize] = C12[i][j];
				C[splitSize + i][j] = C21[i][j];
				C[splitSize + i][splitSize + j] = C22[i][j];
			}
		}
		return C;
	}
}

int main()
{
	int size = 2;
	int **A = initMatrix(size);
	int **B = initMatrix(size);
	int **C = initMatrix(size);

	addValuesToMatriz(A, size);
	addValuesToMatriz(B, size);

	C = strassen(A, B, size);

	printMatrix(A, size);
	printMatrix(B, size);
	printMatrix(C,size);
	return 0;
}
