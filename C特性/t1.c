#include <stdio.h>
int main(int argc, char *argv[])
{
    int i = 1;
    printf("%d,%d,%d,%d\n", i, ++i, ++i, ++i);
    char *q = 'a';
    int p = sizeof *q;
    struct A
    {
        int a;
        char b;
        short c;
    };
    printf("%d", sizeof(struct A));

    return 0;
}