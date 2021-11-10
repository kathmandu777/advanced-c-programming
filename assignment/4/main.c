#include <stdio.h>

#define MAX_QUEUE_SIZE 10

// キューの構造体(typedefで名前付け)
typedef struct  {
    int head;
    int tail;
    int count;
    char queue[MAX_QUEUE_SIZE];
} Queue_k;

// キューを初期化する
void initialize(Queue_k *q) {
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

// キューの末尾に要素を追加
void enterq(Queue_k *q, int x) {
    if (q->count == MAX_QUEUE_SIZE) {
        printf("Queue is full\n");
        return;
    }
    q->queue[q->tail++] = x;
    q->tail = q->tail == MAX_QUEUE_SIZE ? 0 : q->tail;
    q->count++;
}

// キューの先頭を取り出す
int removeq(Queue_k *q) {
    if (q->count == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = q->queue[q->head++];
    q->head = q->head == MAX_QUEUE_SIZE ? 0 : q->head;
    q->count--;
    return x;
}

// キューの中身を表示する
void display(Queue_k *q) {
    for(int i=0; i<MAX_QUEUE_SIZE; i++) {
        if (i == q->head) {
            printf(" head->");
        }
        else{
            printf("       ");
        }
        printf("%6d: %6c",i, q->queue[i]);
        if (i == q->tail) {
            printf(" <-tail\n");
        }
        else{
            printf("       \n");
        }
      }
}

int main(void){
    Queue_k queue1;
    initialize(&queue1);

    FILE *fp = fopen("./input_kadai4.txt", "r");
    if (fp == NULL) {
        printf("File open error\n");
        return -1;
    }

    char element;
    while((element = fgetc(fp)) != EOF) {
        if (element == '\n') {
            char tmp = removeq(&queue1);
            putchar(tmp);
            continue;
        }
        enterq(&queue1, element);
    }
    putchar('\n');

    display(&queue1);
    fclose(fp);
}