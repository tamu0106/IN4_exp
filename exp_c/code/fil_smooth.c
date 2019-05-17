#include "nubesuko.h"

gray fil_smooth(gray image, int cols, int rows, int filter_size)
{
    int maxval, minval, x, y;
    double **tmp, **weight;
    gray **filtered_img;

    filtered_img = malloc_matrix(rows, cols);

    weight = make_filter(filter_size, 0, 0);

    tmp = filterling(image, cols, rows, filter_size, weight);
    for (y = 1; y < cols - 1; y++)
    {
        for (x = 1; x < rows - 1; x++)
        {
            filtered_img[y][x] = (unsigned int)tmp[y][x];
        }
    }
    return filtered_img;
}