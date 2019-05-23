#include "nubesuko.h"

//値に応じてパターン生成
double **make_filter(int size, int type, int sub_type)
{
	int i, j, dis;
	double **pattern, val;

	//printf("size:%d\n", size);

	pattern = calloc_d_matrix(size, size);

	for (i = 0; i < size; i++)
	{
		//printf("%d ",i);
		for (j = 0; j < size; j++)
		{
			//printf("%d\n", j);
			dis = abs(i - size / 2) + abs(j - size / 2); //中心からの距離
			val = 0;
			//printf("dis:%d\n", dis);
			switch (type)
			{
			case 0:
				//smooth_ave
				//val = fil_smooth_ave(dis);
				val = 1 / 9.0;
				break;

			case 8:
				//dif_prewitt
				if (sub_type)
				{
					//prewitt_y
					if (i == 0)
					{
						val = -1;
					}
					else if (i == 2)
					{
						val = 1;
					}
				}
				else
				{
					//prewitt_x
					if (j == 0)
					{
						val = -1;
					}
					else if (j == 2)
					{
						val = 1;
					}
				}
				break;

			case 9:
				//dif_sobel
				if (sub_type)
				{
					//sobel_y
					if (i == 0)
					{
						val = -1;
					}
					else if (i == 2)
					{
						val = 1;
					}
				}
				else
				{
					//sobel_x
					if (j == 0)
					{
						val = -1;
					}
					else if (j == 2)
					{
						val = 1;
					}
				}
				break;

			case 10:
				//dif_lap
				//val = fil_dif_lap(dis);
				if (dis == 0)
				{
					val = -4;
				}
				else if (dis == 1)
				{
					val = 1;
				}

				break;

			case 16:
				//sharpening
				//val = fil_sharp(dis);
				if (dis == 0)
				{
					val = 5;
				}
				else if (dis == 1)
				{
					val = -1;
				}

				break;

			default:
				printf("filter make error.\n");
				exit(-1);
			}

			//printf("val:%f\n",val);
			pattern[i][j] = val;
		}
	}

	return pattern;
}
