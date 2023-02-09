#include<stdio.h>
#include<string.h>
int check(char);
char result[10];
int k=0;
char res[23][23];
void main()
{
    int i=0,j=0,n,counter=0,r=0;
    char mat[23][23],r2[23][23];
    printf("enter the number of instructions : ");
    scanf("%d",&n);
    printf("enter the 3 address codes\n");
    for(i=0;i<n;i++)
    scanf("%s",mat[i]);
    for(i=0;i<n;i++)
    {
        printf("leng = %d\n",strlen(mat[i]));

        if(strlen(mat[i])>4) //for a=c+d
        {
            res[k][0]=mat[i][3];
            res[k][1]=mat[i][2];
            res[k][2]=mat[i][4];
            res[k][3]=mat[i][0];
            res[k][4]=counter++ + '0';
            result[r++]=mat[i][0];
            k++; 
        }

        else   //for a=c assigning
          {
            printf("enter");
            res[k][0]=mat[i][1];
            res[k][1]=mat[i][2];
            res[k][2]=' ';
            res[k][3]=mat[i][0];
              res[k][4]=counter++ + '0';
            k++;
            result[r++]=mat[i][0];
        }
    }
    printf("k:%d\n",k);

    printf("\nthe quadruple");
    printf("\ni\top\top1\top2\tresult\n");
    for(i=0;i<k;i++)
    {printf("%d\t",i);
        for(j=0;j<4;j++)
    printf("%c\t",res[i][j]);
    printf("\n");}
    
    printf("\n changed values : %s\n",result);
    
    
    printf("\nthe triple");
    printf("\ni\top\ta1\ta2\n");
    for(i=0;i<k;i++)
    {printf("%d\t",i);
        for(j=0;j<3;j++){
    
    if(!check(res[i][j]))
    printf("%c\t",res[i][j]);      
        }
    printf("\n");}

}

int check(char ch)
{
    //printf("inside check() %c",ch);
    for(int i=0;i<strlen(result);i++)
    {
        if(ch==result[i])
        {
            for(int j=0;j<k;j++)
            {
                if(res[j][3]==ch){
                printf("%c\t",res[j][4]);
                return 1;}
            }
        }
    }
    return 0;
    
}
/*
enter the number of instructions : 3
enter the 3 address codes
a=b*c
v=d*s
e=9+f
leng = 5
leng = 5
leng = 5
k:3

the quadruple
i       op      op1     op2     result
0       *       b       c       a
1       *       d       s       v
2       +       9       f       e

 changed values : ave

the triple
i       op      a1      a2
0       *       b       c
1       *       d       s
2       +       9       f
*/