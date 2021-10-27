#include <stdio.h>
#include <ctype.h>

#define STACK_SIZE 5   // Stack Size
int stack[STACK_SIZE]; // Stack Area
int sp;                // Stack Point

/*
スタックに関する関数
*/
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

void initialize()
{
    sp = -1;
}

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

/*
main関数
*/
int main(void)
{
    initialize();

    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File open error\n");
        return -1;
    }

    char element;
    while ((element = fgetc(fp)) != EOF)
    {
        if (isdigit(element))
        {
            int num = element - '0';
            printf("数字の%dをpushします\n", num);
            push(num);
            display();
            putchar('\n');
        }
        else if (element == '=')
        {
            printf("計算結果は%dです\n", pop());
            printf("-------------------------\n\n");
        }
        else // 演算に関するオペランドだったら
        {
            int num2 = pop();
            int num1 = pop();
            printf("%d %c %d を計算します\n", num1, element, num2);
            int ans;
            switch (element)
            {
            case '+':
                ans = num1 + num2;
                break;
            case '-':
                ans = num1 - num2;
                break;
            case '*':
                ans = num1 * num2;
                break;
            case '/':
                ans = num1 / num2;
                break;
            }

            push(ans);
            printf("数字の%dをpushします\n", ans);
            display();
            putchar('\n');
        }
    }

    fclose(fp);

    return 0;
}
