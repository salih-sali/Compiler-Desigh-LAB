#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    int t=0;
    char postfix[20];
    while(*e != '\0')
    {
        if(isalnum(*e))
             postfix[t++]=*e;
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                postfix[t++] = x;
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
               postfix[t++]=pop();
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        postfix[t++]=pop();
    }
   postfix[t]='\0';
   // printf("sssssssssss\n ");
    puts(postfix);
   


    int i,l=0,s=0;
    char st[20]="",a,b,cntr;
    top=-1;
    for( i=0;i<strlen(postfix);i++){
        // printf("\n %d ", i);
         if(isalnum(postfix[i]))
               st[++top]=postfix[i];
         else if(postfix[i]=='*' || postfix[i]=='+' || postfix[i]=='/' || postfix[i]=='-'){
               b=st[top];
               a=st[--top];
               cntr=s+'0';
               printf("\n %c = %c %c %c\n",cntr,a,postfix[i],b); //printing...
               s++;
               st[top]=cntr;
         } 
        //  puts(st);
    }
}

/*Enter the expression : a+b*c/k-h

abc*k/+h-

 0 = b * c

 1 = 0 / k

 2 = a + 1

 3 = 2 - h*/