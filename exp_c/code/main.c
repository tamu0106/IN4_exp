#include "nubesuko.h"

int main(int argc, char *argv[])
{

  FILE *file1, *file2;
  int pattern, size, cols, rows, i, j;
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

  image = pgm_readpgm(file1, &cols, &rows, &maxval);
  printf("Log:read pbm\n");
  fclose(file1);

  //サイズの入力
  printf("Filter size?\n>>");
  scanf("%d", &size);

  //フィルタ選択
  printf("Select Filter Type.\n");
  printf("0.Smoothing_filter\n");
  printf("8.Differential_filter\n");
  printf("9.Laplacian_filter\n");
  printf("16.Sharpening_filter\n");
  printf(">>");

  scanf("%d", &pattern);

  //フィルタ処理
  answer = mendako(image, cols, rows, size, pattern);

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
    // mono_view(answer, cols, rows, maxval);
  }

  return 0;
}

//二次元配列matrixを動的確保
gray **malloc_matrix(int rows, int cols)
{
  gray **matrix;
  int i;

  if ((matrix = malloc(rows * sizeof(gray *))) == NULL)
  {
    printf("行列用の領域が確保できませんでした。\n");
    exit(-1);
  }

  for (i = 0; i < rows; i++)
  {
    matrix[i] = malloc(cols * sizeof(gray));
  }

  return matrix;
}

void free_matrix(int **matrix, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
}
