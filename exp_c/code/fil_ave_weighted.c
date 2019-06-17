#include "temp.h"

//局所荷重平均値フィルタ
gray **fil_ave_weighted(gray **image, int cols, int rows, int filter_size)
{
    int x, y;
    double **tmp, **weight, maxval = 0, minval = 255;
    gray **filtered_img;

    filtered_img = calloc_g_matrix(rows, cols);

    weight = make_filter(filter_size, 1, 0);

    tmp = filtering(image, cols, rows, filter_size, weight, &maxval, &minval);
    for (y = 0; y < cols; y++)
    {
        for (x = 0; x < rows; x++)
        {
            if (tmp[y][x] <= 0)
            {
                tmp[y][x] = 0;
            }
            else if (tmp[y][x] > 255.0)
            {
                tmp[y][x] = 255.0;
            }
            filtered_img[y][x] = rounding(tmp[y][x]);
        }
    }

    free_d_matrix(weight, filter_size);
    free_d_matrix(tmp, filter_size);
    return filtered_img;
}
