#include "nubesuko.h"

gray **fil_dif_sobel(gray **image, int cols, int rows, int filter_size)
{
    int x, y;
    double **xfiltered_img, **yfiltered_img, **weight, maxval, minval;
    gray **filtered_img;

    filtered_img = malloc_matrix(rows, cols);

    weight = make_filter(filter_size, 9, 0);
    xfiltered_img = filterling(image, cols, rows, filter_size, weight, &maxval, &minval);

    weight = make_filter(filter_size, 9, 1);
    yfiltered_img = filterling(image, cols, rows, filter_size, weight, &maxval, &minval);

    for (y = 1; y < cols - 1; y++)
    {
        for (x = 1; x < rows - 1; x++)
        {
            if (xfiltered_img[y][x] > 255)
            {
                xfiltered_img[y][x] = 255;
            }
            if (yfiltered_img[y][x] > 255)
            {
                yfiltered_img[y][x] = 255;
            }
            filtered_img[y][x] = (gray)hypot(xfiltered_img[y][x], yfiltered_img[y][x]);
        }
    }
    return filtered_img;
}