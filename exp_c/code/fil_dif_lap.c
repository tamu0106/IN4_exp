#include "nubesuko.h"

gray **fil_dif_lap(gray image, int cols, int rows, int filter_size)
{
    int maxval, minval;
    double **tmp, **weight, multi, correct, x, y;
    gray **filtered_img;

    filtered_img = malloc_matrix(rows, cols);

    weight = make_filter(filter_size, 9, 0);

    tmp = filterling(image, cols, rows, filter_size, weight, &maxval, &minval);

    multi = 255 / (maxval - minval);
    correct = abs(minval * multi);

    for (y = 1; y < cols - 1; y++)
    {
        for (x = 1; x < rows - 1; x++)
        {
            tmp[y][x] = (tmp[y][x] * multi) + correct;
            filtered_img[y][x] = (unsigned int)tmp[y][x];
        }
    }
    return filtered_img;
}