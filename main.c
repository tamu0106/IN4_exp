#include "nubesuko.h"

int main(int argc, char *argv[])
{

  FILE *file1, *file2;
  int filter_num, size, cols, rows, maxval, i, j;
  double **array;
  gray **image, **answer;

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
  printf("%d", cols);
  printf("%d", rows);
  fclose(file1);

  //サイズの入力
  printf("サイズを入力してください。\n");
  scanf("%d", &size);

  //フィルタ選択
  printf("フィルタ処理を選択してください。\n");
  printf("0.Smoothing_filter\n");
  printf("8.Differential_filter\n");
  printf("16.Sharpening_filter\n");

  scanf("%d", &filter_num);

  //フィルタ処理
  array = make_filter(size, filter_num);

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      printf("%2d ", array[i][j]);
    }
    printf("\n");
  }

  answer = filterling(image, cols, rows, size, array);
  printf("うお\n");

  // mono_view(answer, cols, rows, maxval);
  file2 = fopen("nubesuko.pgm", "wb");

  pgm_writepgm(file2, answer, cols, rows, maxval, 1);
  fclose(file2);
}

//二次元配列matrixを動的確保
gray **malloc_matrix(int rows, int cols)
{
  int **matrix;
  int i;

  if ((matrix = malloc(rows * sizeof(gray *))) == NULL)
  {
    printf("行列用の領域が確保できませんでした。\n");
    exit(-1);
  }

  for (i = 0; i < rows; i++)
  {

    matrix[i] = malloc(cols * sizeof(gray));
    printf("%d\n", i);
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
