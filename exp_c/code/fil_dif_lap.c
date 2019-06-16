#include "temp.h"

//ラプラシアンフィルタ
gray **fil_dif_lap(gray **image, int cols, int rows, int filter_size, int mode)
{
    int x, y;
    double **tmp, **weight, multi, correct, maxval = 0, minval = 255;
    gray **filtered_img;

    filtered_img = calloc_g_matrix(rows, cols);

    if (mode)
    {
        //8
        weight = make_filter(filter_size, 11, 0);
    }
    else
    {
        //4
        weight = make_filter(filter_size, 10, 0);
    }

    tmp = filtering(image, cols, rows, filter_size, weight, &maxval, &minval);

    multi = 255 / (maxval - minval);
    correct = fabs(minval * multi);
    printf("max:%f\n", maxval);
    printf("min:%f\n", minval);
    printf("multi:%f\n", multi);
    printf("correct:%f\n", correct);

    for (y = 1; y < cols - 1; y++)
    {
        for (x = 1; x < rows - 1; x++)
        {
            tmp[y][x] = (tmp[y][x] * multi) + correct;
            filtered_img[y][x] = (unsigned int)tmp[y][x];
        }
    }
    free_d_matrix(weight, filter_size);
    free_d_matrix(tmp, filter_size);
    return filtered_img;
}