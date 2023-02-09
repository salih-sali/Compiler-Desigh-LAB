#include <stdio.h>

char opt[10][10] = {
{' ','>','>','>','>','>'},
{'<','>','>','<','<','>'},
{'<','>','>','<','<','>'},
{'<','>','>','>','>','>'},
{'<','>','>','>','>','>'},
{'<','<','<','<','<',' '}
};

int number(char c)
{
    switch(c){
        case 'a': return 0;
        case '+': return 1;
        case '-': return 2;
        case '*': return 3;
        case '/': return 4;
        case '$': return 5;

    }
}

char ter[6] = {'a','+','-','*','/','$'};


void main()
{
char stack[20], ip[20];
int i, j, k, n=6, top = 0, col, row;
for (i = 0; i < 10; i++)
{
stack[i] = NULL;
ip[i] = NULL;
}
printf("\n** OPERATOR PRECEDENCE TABLE **\n");
for (i = 0; i < n; i++)
{
printf("\t%c", ter[i]);
}
printf("\n");
for (i = 0; i < n; i++)
{
printf("\n%c", ter[i]);
for (j = 0; j < n; j++)
{
printf("\t%c", opt[i][j]);
}
}

stack[top] = '$';
printf("\nEnter the input string:");
scanf("%s", ip);
i = 0;
printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
printf("\n%s\t\t\t%s\t\t\t", stack, ip);
while (i <= strlen(ip))
{
row=number(ip[i]);
col=number(stack[top]);

if ((stack[top] == '$') && (ip[i] == '$'))
{
printf("String is accepted\n");
break;
}
else if (opt[col][row] == '<')
{
stack[++top] = opt[col][row];
stack[++top] = ip[i];
printf("Shift %c", ip[i]);
i++;
}
else if (opt[col][row]== '>')
{
while (stack[top] != '<')
{
--top;
}
top = top - 1;
printf("Reduce");
}

else
{
printf("\nString is not accepted");
break;
}

printf("\n");
for (k = 0; k <= top; k++)
{
printf("%c", stack[k]);
}
printf("\t\t\t");
for (k = i; k < strlen(ip); k++)
{
printf("%c", ip[k]);
}
printf("\t\t\t");
}
}

/*

** OPERATOR PRECEDENCE TABLE **
        a       +       -       *       /       $

a               >       >       >       >       >
+       <       >       >       <       <       >
-       <       >       >       <       <       >
*       <       >       >       >       >       >
/       <       >       >       >       >       >
$       <       <       <       <       <
Enter the input string: a+a*a$

STACK                   INPUT STRING                    ACTION

$                       a+a*a$                  Shift a
$<a                     +a*a$                   Reduce
$                       +a*a$                   Shift +
$<+                     a*a$                    Shift a
$<+<a                   *a$                     Reduce
$<+                     *a$                     Shift *
$<+<*                   a$                      Shift a
$<+<*<a                 $                       Reduce
$<+<*                   $                       Reduce
$<+                     $                       Reduce
$                       $                       String is accepted
*/