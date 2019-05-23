#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <netpbm/pgm.h>

gray **mendako(gray **image, int cols, int rows, int filter_size, int pattern);

gray **fil_ave(gray **image, int cols, int rows, int filter_size);
gray **fil_ave_weighted(gray **image, int cols, int rows, int filter_size);
gray **fil_dif_prew(gray **image, int cols, int rows, int filter_size);
gray **fil_dif_sobel(gray **image, int cols, int rows, int filter_size);
gray **fil_dif_lap(gray **image, int cols, int rows, int filter_size);
gray **fil_sharpening(gray **image, int cols, int rows, int filter_size);

double **make_filter(int size, int type, int sub_sype);
double **filterling(gray **image, int rows, int cols, int filter_size, double **weight, double *maxval, double *minval);

gray **calloc_g_matrix(int rows, int cols);
double **calloc_d_matrix(int rows, int cols);
void free_matrix(int **matrix, int cols);