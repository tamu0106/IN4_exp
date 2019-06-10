#include "temp.h"

//パターンを用いてフィルタ処理
double **filtering(gray **image, int cols, int rows, int filter_size, double **weight, double *maxval, double *minval)
{

	int i, j, x, y, clip;
	double pixcel_value, **filtered_img;

	clip = filter_size / 2; //無視する広さ

	for (i = 0; i < filter_size; i++)
	{
		for (j = 0; j < filter_size; j++)
		{
			printf("%f ", weight[i][j]);
		}
		printf("\n");
	}

	filtered_img = calloc_d_matrix(rows, cols);

	for (y = clip; y < cols - clip; y++)
	{
		for (x = clip; x < rows - clip; x++)
		{
			pixcel_value = 0.0;
			for (i = 0 - clip; i < filter_size - clip; i++)
			{
				for (j = 0 - clip; j < filter_size - clip; j++)
				{
					pixcel_value = pixcel_value + weight[i + clip][j + clip] * image[y + i][x + j];
				}
			}
			filtered_img[y][x] = pixcel_value;
			if (pixcel_value < *minval)
			{
				*minval = pixcel_value;
			}

			if (pixcel_value > *maxval)
			{
				*maxval = pixcel_value;
			}
		}
	}

	//printf("uo2\n");
	//printf("max:%f\n", *maxval);
	//printf("min:%f\n", *minval);

	return filtered_img;
}
