#include <stdio.h>

int main(void)
{
    struct xyz
    {
        int x;
        long y;
        float z;
    };

    struct xyz a;
    a.x = 1;
    a.y = 299999999999;
    a.z = 3.0;

    printf("%d %ld %f\n", a.x, a.y, a.z);

    struct xyz *p = &a;
    p->x = 10;
    p->y = 20000000;
    p->z = 30.0;

    printf("%d %ld %f\n", p->x, p->y, p->z);

    return 0;
}