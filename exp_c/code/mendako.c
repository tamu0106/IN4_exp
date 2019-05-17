#include "nubesuko.h"

gray **mendako(gray **image, int cols, int rows, int filter_size, int pattern)
{
    gray **filtered_img;

    filtered_img = malloc_matrix(rows, cols);

    switch (pattern)
    {
    case 0:
        filtered_img = fil_smooth(image, cols, rows, filter_size);
        break;

    case 8:
        filtered_img = fil_dif_prew(image, cols, rows, filter_size);
        break;

    case 9:
        filtered_img = fil_dif_lap(image, cols, rows, filter_size);
        break;

    case 16:
        filtered_img = fil_sharpening(image, cols, rows, filter_size);
        break;

    default:
        printf("filter type error.\n");
        exit(-1);
    }

    return filtered_img;
}