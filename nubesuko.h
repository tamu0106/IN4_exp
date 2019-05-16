#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <netpbm/pgm.h>

double **make_filter(int size, int type);
double **filterling(int **image, int rows, int cols, int filter_size, double **weight);
gray **malloc_matrix(int rows, int cols);
void free_matrix(int **matrix, int size);
gray **mendako(int **image, int cols, int rows, int filter_size, int pattern);