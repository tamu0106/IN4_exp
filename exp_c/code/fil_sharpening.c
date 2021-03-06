#include "temp.h"

//鮮鋭化フィルタ
gray **fil_sharpening(gray **image, int cols, int rows, int filter_size, int mode)
{
    int x, y;
    double **tmp, **weight, maxval = 0, minval = 255;
    gray **filtered_img;

    filtered_img = calloc_g_matrix(rows, cols);

    if (mode)
    {
        //8
        weight = make_filter(filter_size, 17, 0);
    }
    else
    {
        //4
        weight = make_filter(filter_size, 16, 0);
    }

    tmp = filtering(image, cols, rows, filter_size, weight, &maxval, &minval);

    for (y = 1; y < cols - 1; y++)
    {
        for (x = 1; x < rows - 1; x++)
        {
            if (tmp[y][x] <= 0)
            {
                tmp[y][x] = 0;
            }
            else if (tmp[y][x] >= 256)
            {
                tmp[y][x] = 255;
            }
            filtered_img[y][x] = (unsigned int)(tmp[y][x]);
        }
    }
    free_d_matrix(weight, filter_size);
    free_d_matrix(tmp, filter_size);
    return filtered_img;
}
