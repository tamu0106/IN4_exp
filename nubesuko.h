#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pgm.h>

double **make_filter(int size, int type);
gray **filterling(int **image, int rows, int cols, int filter_size, double **weight);
gray **malloc_matrix(int rows, int cols);
void free_matrix(int **matrix, int size);