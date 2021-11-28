/* 上級CプログラミングB 出題日：2021/11/17
   3I 9番 氏名 加藤愛斗 提出日：2021/11/22 */
/* ファイル名：ex12.c
   演習 リストの操作
   設問 initialize(), add(), delete(), insert(), search() を作成する
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int data;
    struct Element *next;
};

Element *head;

// 設問 １：リストの基本処理のための関数を作成
void initialize()
{
    head = NULL;
}

void add(int data)
{
    Element *p = (Element *)malloc(sizeof(Element));
    p->data = data;
    p->next = head;
    head = p;
}

int delete (int data)
{
    Element *p = head;
    Element *q = head;
    for (int i = 0; p != NULL; i++, q = p, p = p->next)
    {
        if (p->data == data)
        {
            if (p == head)
            {
                head = p->next;
            }
            else
            {
                q->next = p->next;
            }
            free(p);
            return i;
        }
    }
    return -1;
}

void insert(int index, int data)
{
    if (index <= 0 || head == NULL)
    {
        add(data);
    }
    Element *p = head;
    Element *q = head;
    int i;
    for (i = 0; i < index && p->next != NULL; q = p, p = p->next, i++)
        ;
    if (i == index)
    {
        Element *r = malloc(sizeof(Element));
        r->data = data;
        r->next = p;
        q->next = r;
    }
    else
    {
        Element *r = malloc(sizeof(Element));
        r->data = data;
        r->next = NULL;
        p->next = r;
    }
}

int search(int data)
{
    Element *p = head;
    int i = 0;
    while (p != NULL)
    {
        if (p->data == data)
        {
            return i;
        }
        p = p->next;
        i++;
    }
    return -1;
}

// displayは変更の必要はない
void display()
{
    int i;
    Element *p;
    for (i = 0, p = head; p != NULL; i++, p = p->next)
        printf("%6d: %p %6d %p\n", i, p, p->data, p->next);
}

int main(void)
{
    int mode = 1, id;
    // 線形リストの初期化（関数の呼び出し）
    initialize();

    while (mode)
    {
        printf("list process ?add(1), insert(2), search(3) or delete(0) = ");
        scanf("%d", &mode);
        if (mode == 1)
        {
            printf("?data = ");
            scanf("%d", &id);
            // 設問２：ノードの追加を実行（関数の呼び出し）
            add(id);
        }
        else if (mode == 2)
        {
            int data;
            printf("?index = ");
            scanf("%d", &id);
            printf("?data = ");
            scanf("%d", &data);
            // 設問３：ノードの挿入を実行（関数の呼び出し）
            insert(id, data);
        }
        else if (mode == 3)
        {
            int index;
            printf("?data = ");
            scanf("%d", &id);
            // 設問４：ノードの探索を実行（index = ??; の形で関数の呼び出し）
            index = search(id);

            if (index == -1)
            {
                printf("data = %d was not found\n", id);
            }
            else
            {
                printf("data = %d was found at %d\n", id, index);
            }
        }
        else if (mode == 0)
        {
            printf("?data = ");
            scanf("%d", &id);
            if (delete (id) < 0)
                printf("id = %d was not found\n", id);
        }
        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }

    return 0;
}

/* 実行結果を以下に貼り付ける
   add(), delete(), insert(), search() の動作確認

/mnt/c/Users/kator/Documents/NITTC/3grade-second-semester/advanced-c-programming/ex/12 (master) $ ./ex12
list process ?add(1), insert(2), search(3) or delete(0) = 1
?data = 10
     0: 0x5569f3f37ac0     10 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 20
     0: 0x5569f3f37ac0     10 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 1
?data = 20
     0: 0x5569f3f37ae0     20 0x5569f3f37ac0
     1: 0x5569f3f37ac0     10 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 1
?data = 30
     0: 0x5569f3f37b00     30 0x5569f3f37ae0
     1: 0x5569f3f37ae0     20 0x5569f3f37ac0
     2: 0x5569f3f37ac0     10 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 2
?index = 1
?data = 40
     0: 0x5569f3f37b00     30 0x5569f3f37b20
     1: 0x5569f3f37b20     40 0x5569f3f37ae0
     2: 0x5569f3f37ae0     20 0x5569f3f37ac0
     3: 0x5569f3f37ac0     10 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 3
?data = 20
data = 20 was found at 2
     0: 0x5569f3f37b00     30 0x5569f3f37b20
     1: 0x5569f3f37b20     40 0x5569f3f37ae0
     2: 0x5569f3f37ae0     20 0x5569f3f37ac0
     3: 0x5569f3f37ac0     10 (nil)
?continue(1) or quit(0) = 1
list process ?add(1), insert(2), search(3) or delete(0) = 0
?data = 20
     0: 0x5569f3f37b00     30 0x5569f3f37b20
     1: 0x5569f3f37b20     40 0x5569f3f37ac0
     2: 0x5569f3f37ac0     10 (nil)
?continue(1) or quit(0) = 0
 */
