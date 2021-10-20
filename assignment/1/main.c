#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int number;
    char name[20];
    int assignment1;
    int assignment2;
    int assignment3;
} score;

void sort_score_with_number(score a[], int n)
{
    int i, j;
    score tmp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j].number > a[j + 1].number)
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
}

int main(void)
{
    // 要素数nを入力
    int n;
    printf("何人分のデータを扱いますか?\n");
    scanf("%d", &n);

    // 入力された要素数nのスコアを格納する配列を宣言
    score *score_p = (score *)malloc(n * sizeof(score));
    if (score_p == NULL)
    {
        printf("malloc error\n");
        exit(1);
    }

    // n人分のscore情報を入力
    score_p[0].number = 10001;
    strcpy(score_p[0].name, "Taro");
    score_p[0].assignment1 = 78;
    score_p[0].assignment2 = 68;
    score_p[0].assignment3 = 95;
    score_p[3].number = 10002;
    strcpy(score_p[3].name, "Jiro");
    score_p[3].assignment1 = 74;
    score_p[3].assignment2 = 63;
    score_p[3].assignment3 = 48;
    score_p[2].number = 10003;
    strcpy(score_p[2].name, "Saburo");
    score_p[2].assignment1 = 85;
    score_p[2].assignment2 = 79;
    score_p[2].assignment3 = 50;
    score_p[1].number = 10004;
    strcpy(score_p[1].name, "Shiro");
    score_p[1].assignment1 = 71;
    score_p[1].assignment2 = 72;
    score_p[1].assignment3 = 73;

    // n人分のデータを番号順にソートして出力
    sort_score_with_number(score_p, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d,%s,%d,%d,%d\n", score_p[i].number, score_p[i].name, score_p[i].assignment1, score_p[i].assignment2, score_p[i].assignment3);
    }
    printf("----------------------\n");

    //評価を計算して出力
    for (int i = 0; i < n; i++)
    {
        int assignment1_evaluation = score_p[i].assignment1 * 0.3;
        int assignment2_evaluation = score_p[i].assignment2 * 0.3;
        int assignment3_evaluation = score_p[i].assignment3 * 0.4;
        int final_score = assignment1_evaluation + assignment2_evaluation + assignment3_evaluation;
        char evaluation;
        if (final_score >= 80)
        {
            evaluation = 'A';
        }
        else if (final_score >= 70)
        {
            evaluation = 'B';
        }
        else if (final_score >= 60)
        {
            evaluation = 'C';
        }
        else
        {
            evaluation = 'F';
        }

        printf("%s,%d,%c\n", score_p[i].name, final_score, evaluation);
    }
}
