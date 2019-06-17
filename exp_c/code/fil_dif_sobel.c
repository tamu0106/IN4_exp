#include "temp.h"

//sobel
gray **fil_dif_sobel(gray **image, int cols, int rows, int filter_size)
{
    int x, y;
    double **xfiltered_img, **yfiltered_img, **weight, multi, maxval = 0, minval = 255;
    gray **filtered_img;

    filtered_img = calloc_g_matrix(rows, cols);

    weight = make_filter(filter_size, 9, 0);
    xfiltered_img = filtering(image, cols, rows, filter_size, weight, &maxval, &minval);

    weight = make_filter(filter_size, 9, 1);
    yfiltered_img = filtering(image, cols, rows, filter_size, weight, &maxval, &minval);
    multi = 255 / (maxval - minval);

    for (y = 1; y < cols - 1; y++)
    {
        for (x = 1; x < rows - 1; x++)
        {
            xfiltered_img[y][x] *= multi;
            yfiltered_img[y][x] *= multi;
            if (xfiltered_img[y][x] > 255)
            {
                xfiltered_img[y][x] = 255;
            }

            if (yfiltered_img[y][x] > 255)
            {
                yfiltered_img[y][x] = 255;
            }

            filtered_img[y][x] = rounding(hypot(xfiltered_img[y][x], yfiltered_img[y][x]));
        }
    }
    free_d_matrix(weight, filter_size);
    free_d_matrix(xfiltered_img, filter_size);
    free_d_matrix(yfiltered_img, filter_size);
    return filtered_img;
}