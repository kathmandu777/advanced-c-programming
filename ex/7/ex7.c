/* 上級CプログラミングB 出題日：2021/10/25
   3I 9番 氏名 加藤愛斗 提出日：2021/10/25 */
/* ファイル名：ex7.c
   演習7 スタック（棚）
   スタックを操作する関数 push(), pop()を完成させる
   初期化用の関数 initialize(), 表示用の関数 display() を完成させる
 */
#include <stdio.h>

#define STACK_SIZE 5   // Stack Size
int stack[STACK_SIZE]; // Stack Area
int sp;                // Stack Point

// 設問１：push()の完成
void push(int data)
{
    if (sp < (STACK_SIZE - 1))
    {
        stack[++sp] = data;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

// 設問２：pop()の完成
int pop()
{
    if (sp >= 0)
    {
        return stack[sp--];
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

// 設問３：initialize()の完成
void initialize()
{
    // sp の値を初期化
    sp = -1;
}

// 設問４：display()の完成
void display()
{
    int i;
    for (i = STACK_SIZE - 1; i >= 0; i--) // スタックの上から下に for文を回す
    {
        if (i == sp) // スタックポインタの位置のとき SP-> を出力
            printf("SP-> ");
        else
            printf("     ");
        // 要素番号とスタックの値を出力
        printf("%d\n", stack[i]);
    }
}

int main(void)
{
    int mode = 1, id;
    // 設問５：スタックを初期化
    initialize();

    while (mode)
    {
        printf("?push(1) or pop(0) = ");
        scanf("%d", &mode);
        if (mode == 1)
        {
            printf("?id = ");
            scanf("%d", &id);
            // 設問６：id の値をスタックに入力
            push(id);
        }
        else if (mode == 0)
        {
            // 設問７：スタックから値を出力し id に代入
            id = pop();

            if (id > 0)
                printf("id = %d was picked\n", id);
        }
        // 設問８：スタックの中身を表示
        display();

        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }
}

/* 実行結果を以下に貼り付ける
   データが正しく pop, push される
   スタックが FULL / EMPTY の場合に、それぞれエラー表示がされる
/mnt/c/Users/kator/Documents/NITTC/3grade-second-semester/AdvancedCprogramming/ex/7 (master) $ ./ex7
?push(1) or pop(0) = 1
?id = 1
     0
     0
     0
     0
SP-> 1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 2
     0
     0
     0
SP-> 2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 3
     0
     0
SP-> 3
     2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 4
     0
SP-> 4
     3
     2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 4 was picked
     0
     4
SP-> 3
     2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 5
     0
     4
SP-> 3
     2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 5
     0
SP-> 5
     3
     2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 6
     0
SP-> 5
     3
     2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 6
SP-> 6
     5
     3
     2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 7
Stack Overflow
SP-> 6
     5
     3
     2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 6 was picked
     6
SP-> 5
     3
     2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 5 was picked
     6
     5
SP-> 3
     2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 3 was picked
     6
     5
     3
SP-> 2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 2 was picked
     6
     5
     3
     2
SP-> 1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 1 was picked
     6
     5
     3
     2
     1
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
Stack is empty
     6
     5
     3
     2
     1
?continue(1) or quit(0) = 0
/mnt/c/Users/kator/Documents/NITTC/3grade-second-semester/AdvancedCprogramming/ex/7 (master) $
*/
