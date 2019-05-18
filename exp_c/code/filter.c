#include "nubesuko.h"

double **filterling(gray **image, int cols, int rows, int filter_size, double **weight, double *maxval, double *minval)
{

	int i, j, x, y;
	double pixcel_value, **filtered_img;

	*maxval = 0.0;
	*minval = 255.0;

	/*
	for (i = 0; i < filter_size; i++)
	{
		for (j = 0; j < filter_size; j++)
		{
			printf("%f ", weight[i][j]);
		}
		printf("\n");
	}
	*/

	filtered_img = malloc(rows * sizeof(double *));
	for (i = 0; i < rows; i++)
	{
		filtered_img[i] = malloc(cols * sizeof(double));
	}

	for (y = 1; y < cols - 1; y++)
	{
		for (x = 1; x < rows - 1; x++)
		{
			pixcel_value = 0.0;
			for (i = -1; i < filter_size - 1; i++)
			{
				for (j = -1; j < filter_size - 1; j++)
				{
					pixcel_value = pixcel_value + weight[i + 1][j + 1] * image[y + i][x + j];
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
