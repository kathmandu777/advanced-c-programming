/* 上級CプログラミングB 出題日：2021/10/11
   3I 9番 氏名 加藤愛斗 提出日：2021/10/11 */
/* 演習3 バブルソートのデータ構造を静的な配列から動的な配列に変更する
   ファイル名 ex3.c */

#include <stdio.h>
#include <stdlib.h> // 設問１：必要なヘッダファイルのインクルード

#define N 100000

// プロトタイプ宣言
void bsort(int[], int);      // バブルソート用の関数
void set_random(int[], int); // 配列にランダムな数字をセットする関数

int main()
{
    // 設問２：一次元配列に相当する一連鎖のポインタ p を宣言する
    int *p;

    int n, i; // n は要素数
    // 設問３：標準入力から要素数を取得し n へ
    printf("要素数を入力：");
    scanf("%d", &n);

    // 設問４：取得した要素数を指定して領域を動的に確保する
    p = (int *)malloc(n * sizeof(int));

    // エラー処理
    if (p == NULL)
    {
        printf("cannot allocate!\n");
        exit(1);
    }

    set_random(p, n); // 配列をランダムな値で初期化
    printf("ソート前\n");
    // 設問５：配列の中身を出力（for文で）
    for (i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    // 設問６：バブルソートを行う関数を呼び出して，p をソート
    bsort(p, n);

    printf("ソート後\n");
    // 再度出力（設問５と同じ）
    for (i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    // 設問７：配列の利用が終わったら，領域を解放する
    free(p);
}

// 以下，関数定義．変更の必要はない
void bsort(int a[], int n)
{
    int i, j;
    int tmp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
}

void set_random(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand() % (10 * n);
}

/*
Output:

/mnt/c/Users/kator/Documents/NITTC/3grade-second-semester/AdvancedCprogramming/ex $ ./ex3
要素数を入力：30
ソート前
283 286 177 115 293 235 286 192 249 121 62 127 290 259 263 226 240 126 172 136 11 68 267 129 182 230 62 223 67 235 
ソート後
11 62 62 67 68 115 121 126 127 129 136 172 177 182 192 223 226 230 235 235 240 249 259 263 267 283 286 286 290 293 
/mnt/c/Users/kator/Documents/NITTC/3grade-second-semester/AdvancedCprogramming/ex $ ./ex3
要素数を入力：7
ソート前
43 46 37 5 43 45 66 
ソート後
5 37 43 43 45 46 66 
*/