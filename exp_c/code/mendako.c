#include "nubesuko.h"

gray **mendako(int **image, int cols, int rows, int filter_size, int pattern)
{
    int x, y;
    double **weight, **xfiltered_img, **yfiltered_img, **tmp;
    gray **filtered_img;

    filtered_img = malloc_matrix(rows, cols);

    if (pattern == 8)
    {
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
        printf("uooooo\n");
    }
    else
    {
        weight = make_filter(filter_size, pattern, 1);

        tmp = filterling(image, cols, rows, filter_size, weight);
        for (y = 1; y < cols - 1; y++)
        {
            for (x = 1; x < rows - 1; x++)
            {
                filtered_img[y][x] = (unsigned int)tmp[y][x];
            }
        }
    }

    return filtered_img;
}