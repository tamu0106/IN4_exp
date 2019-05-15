#include "nubesuko.h"

gray **mendako(int **image, int cols, int rows, int filter_size, int pattern)
{
    int x, y;
    double **weight;
    gray **xfiltered_img, **yfiltered_img, **filtered_img;

    if (pattern != 0)
    {
        weight = make_filter(filter_size, pattern);
        xfiltered_img = filterling(image, cols, rows, filter_size, weight);

        weight = make_filter(filter_size, pattern);
        yfiltered_img = filterling(image, cols, rows, filter_size, weight);

        for (y = 1; y < cols - 1; y++)
        {
            for (x = 1; x < rows - 1; x++)
            {
                filtered_img[y][x] = hypot(xfiltered_img[y][x], yfiltered_img[y][x]);
            }
        }
    }
    else
    {
        weight = make_filter(filter_size, pattern);
        filtered_img = filterling(image, cols, rows, filter_size, weight);
    }

    return filtered_img;
}