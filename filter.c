#include "nubesuko.h"

gray **filterling(int **image, int cols, int rows, int filter_size, double **weight)
{

	gray **filtered_img;
	int i, j, x, y, max_value = 0;
	double nube, pixcel_value;

	for (i = 0; i < filter_size; i++)
	{
		for (j = 0; j < filter_size; j++)
		{
			printf("%f ", weight[i][j]);
		}
		printf("\n");
	}

	filtered_img = malloc_matrix(rows, cols);


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
		}
	}

	printf("uo2\n");
	nube = max_value / 255;

	printf("uo3\n");
	//正規化
	for (y = 1; y < cols - 1; y++)
	{
		for (x = 1; x < rows - 1; x++)
		{
			pixcel_value = 0.0;
			for (i = -1; i < filter_size - 1; i++)
			{
				for (j = -1; j < filter_size - 1; j++)
				{
					/*
					pixcel_value = pixcel_value + weight[i + 1][j + 1] * image[y + i][x + j];
					pixcel_value = abs((int)pixcel_value);
					pixcel_value *= nube;
					if (pixcel_value > 255)
					{
						pixcel_value = 255;
					}
					filtered_img[y][x] = pixcel_value;
					*/
				}
			}
		}
	}

	return filtered_img;
}
