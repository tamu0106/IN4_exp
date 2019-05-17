#include "nubesuko.h"

int main(int argc, char *argv[])
{

  FILE *file1, *file2;
  int pattern, size, cols, rows, i, j;
  double **array;
  char filename[16];
  gray **image, **answer, maxval;

  //画像の読み込み
  file1 = fopen(argv[1], "rb");

  if (file1 == NULL)
  {
    printf("ファイルが存在しません。\n");
    return 0;
  }

  printf("file open\n");

  image = pgm_readpgm(file1, &cols, &rows, &maxval);
  printf("read pbm\n");
  fclose(file1);

  //サイズの入力
  printf("サイズを入力してください。\n");
  scanf("%d", &size);

  //フィルタ選択
  printf("フィルタ処理を選択してください。\n");
  printf("0.Smoothing_filter\n");
  printf("8.Differential_filter\n");
  printf("16.Sharpening_filter\n");

  scanf("%d", &pattern);

  //フィルタ処理
  answer = mendako(image, cols, rows, size, pattern);

  printf("1.ファイルに保存\n");
  printf("2.画面に表示\n");

  scanf("%d", &pattern);

  if (pattern == 1)
  {
    printf("ファイル名を入力してください\n");
    scanf("%s", filename);

    file2 = fopen(filename, "wb");

    pgm_writepgm(file2, answer, cols, rows, maxval, 1);
    fclose(file2);
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
