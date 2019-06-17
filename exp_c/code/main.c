#include "temp.h"

int main(int argc, char *argv[])
{

  FILE *file1, *file2;
  int pattern = 0, size = 3, cols, rows, i, j;
  double **array;
  char filename[32];
  gray **image, **answer, maxval;

  //画像の読み込み
  file1 = fopen(argv[1], "rb");
  if (file1 == NULL)
  {
    printf("Cannot open image file.\nexit.\n");
    return -1;
  }
  printf("Log:file open\n");

  //pgm読み込み
  image = pgm_readpgm(file1, &cols, &rows, &maxval);
  printf("Log:read pbm\n");
  fclose(file1);

  //サイズの入力
  printf("Filter size?\n>>");
  scanf("%d", &size);

  //フィルタ選択
  printf("Select Filter Type.\n");
  printf("0.Smoothing Filter\n");
  printf("1.Differential Filter\n");
  printf("2.Sharpening Filter\n");
  printf(">>");

  scanf("%d", &pattern);

  switch (pattern)
  {
  case 0:
    printf("Select Smoothing Filter Type.\n");
    printf("0.Smoothing Filter\n");
    printf("1.Weighted Smoothing filter\n");
    printf("2.Median Filter\n");
    printf(">>");

    scanf("%d", &pattern);
    break;

  case 1:
    printf("Select Differential Filter Type.\n");
    printf("0.Operation Prewitt\n");
    printf("1.Operation Sobel\n");
    printf("2.Laplacian Filter\n");
    printf(">>");

    scanf("%d", &pattern);
    pattern += 8;
    break;
  case 2:
    printf("Select Sharpening Filter Type.\n");
    printf("0.Four directions Sharpening Filter\n");
    printf("1.Eight directions Sharpening Filter\n");
    printf(">>");

    scanf("%d", &pattern);
    pattern += 16;
    break;
  }

  //フィルタ処理
  answer = filter_processing(image, cols, rows, size, pattern);

  printf("Select output.\n");
  printf("1.Write File\n");
  printf("2.Output Window\n");
  printf(">>");

  scanf("%d", &pattern);

  if (pattern == 1)
  {
    printf("Filename?\n>>");
    scanf("%s", filename);

    printf("Log:file open\n");
    file2 = fopen(filename, "wb");

    pgm_writepgm(file2, answer, cols, rows, maxval, 1);
    fclose(file2);
    printf("Log:Write File.\n");
  }
  else
  {
    mono_view(answer, cols, rows, maxval);
  }

  free_g_matrix(answer, cols);
  return 0;
}

//gray型二次元配列matrixを動的確保
gray **calloc_g_matrix(int rows, int cols)
{
  gray **matrix;
  int i;

  if ((matrix = calloc(rows, sizeof(gray *))) == NULL)
  {
    printf("calloc error.\n");
    exit(-1);
  }

  for (i = 0; i < rows; i++)
  {
    if ((matrix[i] = calloc(cols, sizeof(gray))) == NULL)
    {
      printf("calloc error.\n");
      exit(-1);
    }
  }

  return matrix;
}

//double型二次元配列matrixを動的確保
double **calloc_d_matrix(int rows, int cols)
{
  double **matrix;
  int i;

  if ((matrix = calloc(rows, sizeof(double *))) == NULL)
  {
    printf("calloc error.\n");
    exit(-1);
  }

  for (i = 0; i < rows; i++)
  {
    if ((matrix[i] = calloc(cols, sizeof(double))) == NULL)
    {
      printf("calloc error.\n");
      exit(-1);
    }
  }

  return matrix;
}

//メモリ解放
void free_g_matrix(gray **matrix, int cols)
{
  int i;
  for (i = 0; i < cols; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
}

//メモリ解放
void free_d_matrix(double **matrix, int cols)
{
  int i;
  for (i = 0; i < cols; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
}
