#include "nubesuko.h"

gray fil_dif_prew(gray image, int cols, int rows, int filter_size)
{
    int maxval, minval, x, y;
    double **xfiltered_img, **yfiltered_img, **weight;
    gray **filtered_img;

    filtered_img = malloc_matrix(rows, cols);

    weight = make_filter(filter_size, 8, 0);
    xfiltered_img = filterling(image, cols, rows, filter_size, weight);

    weight = make_filter(filter_size, 8, 1);
    yfiltered_img = filterling(image, cols, rows, filter_size, weight);

    for (y = 1; y < cols - 1; y++)
    {
        for (x = 1; x < rows - 1; x++)
        {
            filtered_img[y][x] = (unsigned int)hypot(xfiltered_img[y][x], yfiltered_img[y][x]);
        }
    }
    return filtered_img;
}