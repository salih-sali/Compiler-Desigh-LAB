
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void FIRST(char);
void FOLLOW(char);
int n, m = 0, p, i = 0, j = 0;
char a[10][10], f[10];
void main()
{
    int i, choice;
    char c, ch;
    printf("\nEnter the number of productions : ");
    scanf("%d", &n);
    printf("\nEnter %d produtions ( Note : epsilon denoted as $ ) : \n\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%s%c", a[i], &ch);
    }
    do
    {
        m = 0;
        printf("\nEnter the element to find the first and follow : ");
        scanf("%c", &c);
        FIRST(c);
        printf("\nFIRST(%c) = { ", c);
        for (int i = 0; i < m; i++)
            printf("%c ", f[i]);
        printf("}");
        strcpy(f, "");
        m = 0;
        FOLLOW(c);
        printf("\nFOLLOW(%c) = { ", c);
        for (int i = 0; i < m; i++)
            printf("%c ", f[i]);
        printf("}\n");
        printf("\npress 1 to continue OR 0 to exit : ");
        scanf("%d%c", &choice, &ch);
    } while (choice == 1);
    printf("\n");
}

void FIRST(char c)
{
    int k;
    if (!isupper(c))
        f[m++] = c;
    for (k = 0; k < n; k++)
    {
        if (a[k][0] == c)
        {
            if (a[k][2] == '$')
                FOLLOW(a[k][0]);
            else if (islower(a[k][2]))
                f[m++] = a[k][2];
            else
                FIRST(a[k][2]);
        }
    }
}
void FOLLOW(char c)
{
    if (a[0][0] == c)
        f[m++] = '$';
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < strlen(a[i]); j++)
        {
            if (a[i][j] == c)
            {
                if (a[i][j + 1] != '\0')
                    FIRST(a[i][j + 1]);
                if (a[i][j + 1] == '\0' && c != a[i][0])
                    FOLLOW(a[i][0]);
            }
        }
    }
}