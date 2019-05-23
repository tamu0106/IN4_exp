#include "nubesuko.h"

gray **fil_ave(gray **image, int cols, int rows, int filter_size)
{
    int x, y;
    double **tmp, **weight, maxval, minval;
    gray **filtered_img;

    filtered_img = calloc_g_matrix(rows, cols);

    weight = make_filter(filter_size, 0, 0);

    tmp = filterling(image, cols, rows, filter_size, weight, &maxval, &minval);
    free_matrix(weight, filter_size);
    for (y = 0; y < cols; y++)
    {
        for (x = 0; x < rows; x++)
        {
            if (tmp[y][x] <= 0)
            {
                tmp[y][x] = 0;
            }
            else if (tmp[y][x] > 255)
            {
                tmp[y][x] = 255;
            }
            filtered_img[y][x] = (unsigned int)tmp[y][x];
        }
    }
    return filtered_img;
}
