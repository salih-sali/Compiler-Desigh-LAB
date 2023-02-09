
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>
void input();
void output();
void change(int p, char *res);
void constant();

struct expr
{
    char op[2], op1[5], op2[5], res[5], eq[2];
    int flag;
} arr[10];
int n;
void main()
{

    input();
    constant();
    output();
}
void input()
{
    int i;
    printf("\n\nEnter the maximum number of expressions : ");
    scanf("%d", &n);
    printf("\n ***** NOTE *****\n");
    printf("\n For direct assignment statements, write it in the form :\n<result> <=> <operand> <#> <NA>\n\n");
    printf("\nEnter the input : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i].res);
        scanf("%s", arr[i].eq);
        scanf("%s", arr[i].op1);
        scanf("%s", arr[i].op);
        scanf("%s", arr[i].op2);
        arr[i].flag = 0;
    }
}
void constant()
{
    int i;
    int op1, op2, res;
    char op, res1[5];
    for (i = 0; i < n; i++)
    {
        if ((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) || (strcmp(arr[i].eq, "=") == 0 && strcmp(arr[i].op, "#") == 0 && (strcmp(arr[i].op2, "NA") == 0)))
        {
            op1 = atoi(arr[i].op1);
            op2 = atoi(arr[i].op2);
            op = arr[i].op[0];
            switch (op)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '#':
                res = op1;
                break;
            }
            sprintf(res1, "%d", res);
            arr[i].flag = 1;
            change(i, res1);
        }
    }
}
void output()
{
    int i = 0;
    printf("\nOptimized code is : ");
    for (i = 0; i < n; i++)
    {
        if (!arr[i].flag)
        {
            printf("\n%s %s %s %s %s", arr[i].res, arr[i].eq, arr[i].op1, arr[i].op, arr[i].op2);
        }
    }
}
void change(int p, char *res)
{
    int i;
    for (i = p + 1; i < n; i++)
    {
        if (strcmp(arr[p].res, arr[i].op1) == 0)
            strcpy(arr[i].op1, res);
        else if (strcmp(arr[p].res, arr[i].op2) == 0)
            strcpy(arr[i].op2, res);
    }
}

/*
OUTPUT:

Enter the maximum number of expressions : 6

 ***** NOTE *****

 For direct assignment statements, write it in the form :
<result> <=> <operand> <#> <NA>


Enter the input :
a = 3 # NA
b = 4 # NA
c = a * b
t1 = c * t2
t3 = c * t4
t5 = t1 * t3

Optimized code is :
t1 = 12 * t2
t3 = 12 * t4
t5 = t1 * t3
*/