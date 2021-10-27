#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void print_array(int **array, int row, int column)
{
    printf(" |");
    for (int i = 0; i < column; i++)
    {
        printf("%3d", i);
    }
    printf("\n-------------------------------\n");
    for (int i = 0; i < row; i++)
    {
        printf("%d|", i);
        for (int j = 0; j < column; j++)
        {
            printf("%3d", array[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    ////////////////////////////////////////////////
    /////////////////  課題1  /////////////////////
    ////////////////////////////////////////////////
    int column, row;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &column);

    // 元画像を扱うinput配列の初期化
    int **input = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++)
    {
        input[i] = (int *)malloc(sizeof(int) * column);
    }

    // 処理後の画像として扱うoutput配列の初期化
    int **output = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++)
    {
        output[i] = (int *)malloc(sizeof(int) * column);
    }

    // inputを100以下の乱数で初期化
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            input[i][j] = rand() % 100;
        }
    }

    ////////////////////////////////////////////////
    /////////////////  課題2  /////////////////////
    ////////////////////////////////////////////////

    // inputに対して平均化を行った画像をoutputに代入
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int sum = 0;
            bool is_around_8_cell_exists = true;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (i + k >= 0 && i + k < row && j + l >= 0 && j + l < column)
                    {
                        sum += input[i + k][j + l];
                    }
                    else
                    {
                        is_around_8_cell_exists = false;
                        break;
                    }
                }
            }
            if (is_around_8_cell_exists)
            {
                output[i][j] = sum / 9;
            }
            else
            {
                output[i][j] = input[i][j];
            }
        }
    }

    // inputと平均化を行ったoutputを表示
    printf("input:\n");
    print_array(input, row, column);
    printf("\noutput after averaging: \n");
    print_array(output, row, column);

    ////////////////////////////////////////////////
    /////////////////  課題3  /////////////////////
    ////////////////////////////////////////////////

    // inputに対して膨張を行った画像をoutputに代入(膨張=周りのマスの最大値で自分を置き換える)
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int max = 0;
            bool is_around_8_cell_exists = true;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (i + k >= 0 && i + k < row && j + l >= 0 && j + l < column)
                    {
                        if (max < input[i + k][j + l])
                        {
                            max = input[i + k][j + l];
                        }
                    }
                    else
                    {
                        is_around_8_cell_exists = false;
                        break;
                    }
                }
            }
            if (is_around_8_cell_exists)
            {
                output[i][j] = max;
            }
            else
            {
                output[i][j] = input[i][j];
            }
        }
    }

    // inputと膨張を行ったoutputを表示
    printf("\ninput:\n");
    print_array(input, row, column);
    printf("\noutput after dilating: \n");
    print_array(output, row, column);

    ////////////////////////////////////////////////
    /////////////////  解放する  /////////////////////
    ////////////////////////////////////////////////
    // inputとoutputを解放
    for (int i = 0; i < row; i++)
    {
        free(input[i]);
        free(output[i]);
    }
    free(input);
    free(output);
}

// TODO: 周りに8マスないときはそのまま代入するがその実装はflag(is_around_8_cell_exists)を使うのが最適か？

/* 実行結果
/mnt/c/Users/kator/Documents/NITTC/3grade-second-semester/AdvancedCprogramming/assignment/2 (master *) $ ./main
Enter the number of rows and columns: 7 8
input:
 |  0  1  2  3  4  5  6  7
-------------------------------
0| 83 86 77 15 93 35 86 92
1| 49 21 62 27 90 59 63 26
2| 40 26 72 36 11 68 67 29
3| 82 30 62 23 67 35 29  2
4| 22 58 69 67 93 56 11 42
5| 29 73 21 19 84 37 98 24
6| 15 70 13 26 91 80 56 73

output after averaging:
 |  0  1  2  3  4  5  6  7
-------------------------------
0| 83 86 77 15 93 35 86 92
1| 49 57 46 53 48 63 58 26
2| 40 49 39 50 46 54 42 29
3| 82 51 49 55 50 48 37  2
4| 22 49 46 56 53 56 37 42
5| 29 41 46 53 61 67 53 24
6| 15 70 13 26 91 80 56 73

input:
 |  0  1  2  3  4  5  6  7
-------------------------------
0| 83 86 77 15 93 35 86 92
1| 49 21 62 27 90 59 63 26
2| 40 26 72 36 11 68 67 29
3| 82 30 62 23 67 35 29  2
4| 22 58 69 67 93 56 11 42
5| 29 73 21 19 84 37 98 24
6| 15 70 13 26 91 80 56 73

output after dilating:
 |  0  1  2  3  4  5  6  7
-------------------------------
0| 83 86 77 15 93 35 86 92
1| 49 86 86 93 93 93 92 26
2| 40 82 72 90 90 90 68 29
3| 82 82 72 93 93 93 68  2
4| 22 82 73 93 93 98 98 42
5| 29 73 73 93 93 98 98 24
6| 15 70 13 26 91 80 56 73
*/