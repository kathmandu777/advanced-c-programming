/* 上級CプログラミングB 出題日：2021/11/15
   3I 9番 氏名 加藤愛斗 提出日：2021/11/22 */
/* ファイル名：ex11.c
   演習 リスト序論、node[N]を連結しfor文で出力する．
 */

#include <stdio.h>
#define N 10

// 設問１：ノードを表現するための構造体を定義する
struct Element
{
   int data;
   struct Element *next;
};

int main()
{
   int i;
   // 設問２：ノード用の構造体配列 node（要素数 N）を宣言する
   struct Element node[N];

   // 設問３：配列 0 から 9 番目をノードとして順に連結する
   for (i = 0; i < N; i++)
   {
      node[i].data = i;
      node[i].next = &node[i + 1];
   }

   // ノードの data に代入する値は i の二乗とする
   for (i = 0; i < N; i++)
   {
      node[i].data = i * i;
   }

   // 設問４：末端ノードを正しく設定する
   node[N - 1].next = NULL;

   // 設問５：head を正しく設定する
   struct Element *head = &node[0];

   // 設問６：線形リスト用のfor文(ポインタ p を用いる)によって先頭から出力する
   // 出力する値は，現在のノードのアドレス，現在のノードの値，次のノードのアドレス
   for (struct Element *p = head; p != NULL; p = p->next)
   {
      printf("%p %d %p\n", p, p->data, p->next);
   }

   return 0;
}

/*
出力結果:
/mnt/c/Users/kator/Documents/NITTC/3grade-second-semester/advanced-c-programming/ex/11 (master) $ ./ex11
0x7fffd3a7f670 0 0x7fffd3a7f680
0x7fffd3a7f680 1 0x7fffd3a7f690
0x7fffd3a7f690 4 0x7fffd3a7f6a0
0x7fffd3a7f6a0 9 0x7fffd3a7f6b0
0x7fffd3a7f6b0 16 0x7fffd3a7f6c0
0x7fffd3a7f6c0 25 0x7fffd3a7f6d0
0x7fffd3a7f6d0 36 0x7fffd3a7f6e0
0x7fffd3a7f6e0 49 0x7fffd3a7f6f0
0x7fffd3a7f6f0 64 0x7fffd3a7f700
0x7fffd3a7f700 81 (nil)

*/