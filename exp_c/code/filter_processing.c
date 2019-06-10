#include "nubesuko.h"

//受け取った値に応じて各フィルタ処理へ分岐
gray **filter_processing(gray **image, int cols, int rows, int filter_size, int pattern)
{
    gray **filtered_img;

    switch (pattern)
    {
    case 0:
        filtered_img = fil_ave(image, cols, rows, filter_size);
        break;

    case 8:
        filtered_img = fil_dif_prew(image, cols, rows, filter_size);
        break;

    case 9:
        filtered_img = fil_dif_lap(image, cols, rows, filter_size);
        break;

    case 16: //4
        filtered_img = fil_sharpening(image, cols, rows, filter_size, 0);
        break;

    case 17: //8
        filtered_img = fil_sharpening(image, cols, rows, filter_size, 1);
        break;

    default:
        printf("filter type error.\n");
        exit(-1);
    }

    return filtered_img;
}