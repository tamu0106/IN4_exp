#include "temp.h"

//値に応じてパターン生成
double **make_filter(int size, int type, int sub_type)
{
	int i, j, dis, x_section, y_section, cnt = 0;
	double **pattern, val = 0;

	//printf("size:%d\n", size);

	pattern = calloc_d_matrix(size, size);

	for (i = 0; i < size; i++)
	{
		//printf("%d ",i);
		for (j = 0; j < size; j++)
		{
			//printf("%d\n", j);
			dis = abs(i - size / 2) + abs(j - size / 2); //中心からの距離

			//3*3に均等に割った範囲でどれに属する座標か
			//x_sec,y_sec
			//3,3 2,3 1,3
			//3,2 2,2 1,2
			//3,1 2,1 1,1
			x_section = (i <= size / 3 - 1) + (i <= size * 2 / 3 - 1) + 1;
			y_section = (j <= size / 3 - 1) + (j <= size * 2 / 3 - 1) + 1;
			//printf("%d,%d\n", x_section, y_section);
			val = 0;
			//printf("dis:%d\n", dis);
			switch (type)
			{
			case 0:
				//smooth_ave
				val = 1;
				cnt += 1;
				break;

			case 1:
				//smooth_ave_weighted
				if ((x_section == 2) && (y_section == 2))
				{
					val = 4;
					cnt += 4;
				}
				else if ((x_section == 2) || (y_section == 2))
				{
					val = 2;
					cnt += 2;
				}
				else
				{
					val = 1;
					cnt += 1;
				}
				break;

			case 8:
				//dif_prewitt
				if (sub_type)
				{
					//prewitt_y
					if (x_section == 3)
					{
						val = -1;
					}
					else if (x_section == 1)
					{
						val = 1;
					}
				}
				else
				{
					//prewitt_x
					if (y_section == 3)
					{
						val = -1;
					}
					else if (y_section == 1)
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
					if (x_section == 3)
					{
						val = -1;
						if (y_section == 2)
						{
							val *= 2;
						}
					}
					else if (x_section == 1)
					{
						val = 1;
						if (y_section == 2)
						{
							val *= 2;
						}
					}
				}
				else
				{
					//sobel_x
					if (y_section == 3)
					{
						val = -1;
						if (x_section == 2)
						{
							val *= 2;
						}
					}
					else if (y_section == 1)
					{
						val = 1;
						if (x_section == 2)
						{
							val *= 2;
						}
					}
					else
					{
						val = 0;
					}
				}
				break;

			case 10:
				//dif_lap_4
				if (dis == 0)
				{
					val = -4;
				}
				else if (dis == 1)
				{
					val = 1;
				}
				else
				{
					val = 0;
				}
				break;

			case 10:
				//dif_lap_8
				if (dis == 0)
				{
					val = -8;
				}
				else
				{
					val = 1;
				}
				break;

			case 16:
				//sharpening_4
				if (dis == 0)
				{
					val = 5;
				}
				else if (dis == 1)
				{
					val = -1;
				}
				else
				{
					val = 0;
				}
				break;

			case 17:
				//sharpening_8
				if (dis == 0)
				{
					val = 9;
				}
				else
				{
					val = -1;
				}

				break;

			default:
				printf("filter make error.\n");
				exit(-1);
			}

			//printf("val:%f\n", val);
			pattern[i][j] = val;
		}
	}

	//printf("cnt:%d\n", cnt);
	if (type < 8 && type >= 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				pattern[i][j] /= (double)cnt;
				//printf("%f ", pattern[i][j]);
			}
			//printf("\n");
		}
	}

	return pattern;
}
