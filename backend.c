#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main()
{
    char icode[10][12], str[20], opr[10];
    int i = 0;
    printf("\nEnter the set of intermediate code (terminated by exit):\n");
    do
    {
        scanf("%s", icode[i]);
    } while (strcmp(icode[i++], "exit") != 0);
    printf("\nTarget code generation");
    printf("\n----------------------");
    i = 0;
    do
    {
        strcpy(str, icode[i]);
        switch (str[3])
        {
        case '+':
            strcpy(opr, "ADD");
            break;
        case '-':
            strcpy(opr, "SUB");
            break;
        case '*':
            strcpy(opr, "MUL");
            break;
        case '/':
            strcpy(opr, "DIV");
            break;
        }
        if(isdigit(str[2]))
         printf("\n\tMOV #%c,R%d", str[2], i);
         else 
        printf("\n\tMOV %c,R%d", str[2], i);
         if(isdigit(str[4]))
        printf("\n\t%s #%c,R%d", opr, str[4], i);
        else
         printf("\n\t%s %c,R%d", opr, str[4], i);
           printf("\n\tMOV R%d,%c", i, str[0]);
    } while (strcmp(icode[++i], "exit") != 0);
    printf("\n");
}

/*Enter the set of intermediate code (terminated by exit):
a=b+c
w=9+e
v=k+7
exit

Target code generation
----------------------
        MOV b,R0
        ADD c,R0
        MOV R0,a
        MOV #9,R1
        ADD e,R1
        MOV R1,w
        MOV k,R2
        ADD #7,R2
        MOV R2,v
        */