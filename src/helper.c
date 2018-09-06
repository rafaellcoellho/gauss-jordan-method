#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

double **allocateMatrix(int lines, int coluns)
{
	double **matrix;
	
	matrix = malloc(sizeof(double *) * lines);
	if(matrix == NULL)
		return NULL;
	
	for(int i=0; i<lines; i++){
		matrix[i] = malloc(sizeof(double) * coluns);
		if(matrix[i] == NULL){
			for(int j=0; j<i; j++)
				free(matrix[j]);
			free(matrix);
			return NULL;
		}
	}

	return matrix;
}

void readMatrix(double **matrix, int lines, int coluns)
{
	for(int i=0; i<lines; i++){
		for(int j=0; j<coluns; j++){
			printf("M[%d][%d]=",i+1,j+1);
			scanf("%lf", &matrix[i][j]);
		}
	}
}

void printMatrix(double **matrix, int lines, int coluns)
{
	for(int i=0; i<lines; i++){
		printf("\n");
		for(int j=0; j<coluns; j++){
			printf("%10.3lf", matrix[i][j]);
		}
	}
}