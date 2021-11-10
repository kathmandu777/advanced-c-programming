/* 上級CプログラミングB 出題日：2021/11/1
   3I 9番 氏名 加藤愛斗 提出日：2021/11/09 */
/* ファイル名：ex9.c
   演習9 キュー（待ち行列）
   キューを操作する関数 enterq(), removeq()を完成させる
   初期化用の関数 initialize(), 表示用の関数 display() を完成させる
 */
#include <stdio.h>

#define QUEUE_SIZE 5
int queue[QUEUE_SIZE]; // Queue Area
int head, tail;        // Queue in:out Point
int count;             // count of Queue member

// 設問１：enterqの完成
void enterq(int data)
{
    if (count == QUEUE_SIZE)
    {
        printf("キューがいっぱいです\n");
        return;
    }
    queue[tail] = data;
    tail = (tail + 1) % QUEUE_SIZE;
    count++;
}

// 設問２：removeqの完成
int removeq()
{
    int data;
    if (count == 0)
    {
        printf("キューが空です\n");
        return -1;
    }
    data = queue[head];
    head = (head + 1) % QUEUE_SIZE;
    count--;
    return data;
}

// 設問３：initializeの完成（head, tail, count の初期化）
void initialize()
{
    head = 0;
    tail = 0;
    count = 0;
}

// 設問４：displayの完成
void display()
{
    int i;
    // キューの(イメージ的に)左から右に for文を回す
    for (i = head; i != tail; i = (i + 1) % QUEUE_SIZE)
    {
        // haed の位置には head-> と出力．でなければスペース
        printf("%s%d", i == head ? "head->" : "     ", queue[i]);

        // 要素番号とキューの値を出力
        printf("(%d) ", i);

        // tail の位置には <-tail と出力．でなければスペース
        printf("%s%d\n", i == tail ? "<-tail" : "     ", queue[i]);
    }
}

int main(void)
{
    int mode = 1, id;
    initialize();
    while (mode)
    {
        printf("?enter(1) or remove(0) = ");
        scanf("%d", &mode);
        if (mode == 1)
        {
            printf("?id = ");
            scanf("%d", &id);
            // 設問５：id の値をキューに入力
            enterq(id);
        }
        else if (mode == 0)
        {
            // 設問６：キューから値を出力し，id に代入
            id = removeq();
            if (id > 0)
                printf("id = %d was removed\n", id);
        }
        // 設問７：キューの中身を表示
        display();

        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }

    return 0;
}

/* 実行結果を以下に貼り付ける
   データが正しく入出力される
   キューが FULL / EMPTY の場合に、それぞれエラー表示がされる
   head, tail が配列末尾に到達したとき，先頭（0）に戻る

/mnt/c/Users/kator/Documents/NITTC/3grade-second-semester/advanced-c-programming/ex/9 (master) $ ./ex9
?enter(1) or remove(0) = 0
キューが空です
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 1
head->1(0)      1
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 2
head->1(0)      1
     2(1)      2
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 1
?id = 3
head->1(0)      1
     2(1)      2
     3(2)      3
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 0
id = 1 was removed
head->2(1)      2
     3(2)      3
?continue(1) or quit(0) = 1
?enter(1) or remove(0) = 0
id = 2 was removed
head->3(2)      3
?continue(1) or quit(0) = 0
*/