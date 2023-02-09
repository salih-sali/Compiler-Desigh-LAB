#include <stdio.h>
void E();
void E1();
void T();
void T1();
void F();
int z = 0, e = 0;
char a[20];
void main()
{
    printf("enter the string\n");
    scanf("%s", a);
    E();
    if (a[z] == '\0' && e == 0)
    {
        printf("valid\n");
    }
    else
        printf("invalid");
}
void E()
{
    T();
    E1();
}
void T()
{
    F();
    T1();
}
void F()
{
    if (a[z] == '(')
    {
        z++;
        E();
        if (a[z] == ')')
            z++;
        else
            e = 1;
    }
    else if (a[z] == 'i')
    {
        z++;
    }
    else
        e = 1;
}
void E1()
{
    if (a[z] == '+')
    {
        z++;
        T();
        E1();
    }
}
void T1()
{
    if (a[z] == '*')
    {
        z++;
        F();
        T1();
    }
}