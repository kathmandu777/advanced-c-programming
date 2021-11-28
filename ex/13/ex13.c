/* 上級CプログラミングB 出題日：2021/11/22
   3I 9番 氏名 加藤愛斗 提出日：2021/11/28 */
/* ファイル名：ex13.c
   演習 線形リストによるスタック，キューの実現
   設問：pop(), push(), enterq(), removeq() の作成
*/

#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int data;
    struct Element *next;
};
struct Element *head, *tail;

void initialize()
{
    head = tail = NULL;
}

// 設問 １：スタックの入出力関数 push, pop を作成
void push(int data)
{
    struct Element *p;
    p = (struct Element *)malloc(sizeof(struct Element));
    p->data = data;
    p->next = head;
    head = p;
}

int pop()
{
    if (head == NULL)
        return -1;
    else
    {
        struct Element *p;
        int data;
        p = head;
        data = p->data;
        head = p->next;
        free(p);
        return data;
    }
}

// 設問 2：キューの入出力関数 enterq, removeq を作成
void enterq(int data)
{
    struct Element *p;
    p = (struct Element *)malloc(sizeof(struct Element));
    p->data = data;
    if (head == NULL)
        head = tail = p;
    else
    {
        tail->next = p;
        tail = p;
    }
    tail->next = NULL;
}

int removeq()
{
    if (head == NULL)
        return -1;
    else
    {
        struct Element *p;
        int data;
        p = head;
        data = p->data;
        head = p->next;
        free(p);
        return data;
    }
}

void display() // 変更しない
{
    int i;
    struct Element *p;
    for (i = 0, p = head; p != NULL; i++, p = p->next)
        printf("%6d: %p %6d %p\n", i, p, p->data, p->next);
}

// スタックを使用する場合には push(id);, id=pop(); の行のコメントを
// キューを使用する場合には enterq(id);, id=removeq(); の行のコメントを外す
int main(void)
{
    int mode = 1, id;
    initialize();
    while (mode)
    {
        printf("list process ?input(1) or output(2) = ");
        scanf("%d", &mode);
        if (mode == 1)
        {
            printf("?id = ");
            scanf("%d", &id);
            push(id); //スタック
            // enterq(id); //キュー
        }
        else if (mode == 2)
        {
            id = pop(); //スタック
            // id = removeq(); //キュー

            if (id == -1)
            { // 取り出し失敗
                printf("empty\n");
            }
            else
            {
                printf("id = %d was picked\n", id);
            }
        }

        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }
}

/* スタック，キュー の動作が確認ができる出力結果を貼る
/mnt/c/Users/kator/Documents/NITTC/3grade-second-semester/advanced-c-programming/ex/13 (master) $ ./ex13
list process ?input(1) or output(2) = 1
?id = 10
     0: 0x55cade98fac0     10 (nil)
?continue(1) or quit(0) = 1
list process ?input(1) or output(2) = 1
?id = 20
     0: 0x55cade98fae0     20 0x55cade98fac0
     1: 0x55cade98fac0     10 (nil)
?continue(1) or quit(0) = 1
list process ?input(1) or output(2) = 1
?id = 30
     0: 0x55cade98fb00     30 0x55cade98fae0
     1: 0x55cade98fae0     20 0x55cade98fac0
     2: 0x55cade98fac0     10 (nil)
?continue(1) or quit(0) = 1
list process ?input(1) or output(2) = 2
id = 30 was picked
     0: 0x55cade98fae0     20 0x55cade98fac0
     1: 0x55cade98fac0     10 (nil)
?continue(1) or quit(0) = 1
list process ?input(1) or output(2) = 2
id = 20 was picked
     0: 0x55cade98fac0     10 (nil)
?continue(1) or quit(0) = 0
*/