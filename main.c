#include <stdio.h>
#include <stdlib.h>

void array2d_print(char (*arr)[9],char row,char col)
{
    char j,i;
    printf("#======================================================#\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if (arr[i][j]<10)
            {
                printf("%4d |",arr[i][j]);
            }
            else
            {
                printf("%4c |",arr[i][j]);
            }
        }
        printf("\n");
        printf("______________________________________________________\n");
        printf("\n");
    }
    printf("#======================================================#\n");
}

int Check_rules1 (char (*arr)[9],int n,char r,char c)
{
    int i,j,h=0;
    for(i=0; i<9; i++)
    {
        if(arr[r-1][i]== n)
        {
            return 0;
        }
        if(arr[i][c-1]== n)
        {
            return 0;
        }
    }
    return 1;
}

int Check_rules2(char *arr1,char r,char c)
{
    char x,i;
    x = (r-1)*9+(c-1);
    for(i=0; i<31; i++)
    {
        if (arr1[i]== x)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char arr1[]= {1,2,3,6,7,14,19,23,25,26,28,32,34,36,39,40,45,48,52,53,55,57,61,65,66,71,72,73,76,78,79};
    int r,c,y,x=0;
    char c1=0,c2=0,counter=0;
    char arr[9][9]=
    {
        {' ',9,1,2,' ',' ',8,3,' '},
        {' ',' ',' ',' ',' ',6,' ',' ',' '},
        {' ',2,' ',' ',' ',9,' ',4,7},
        {' ',5,' ',' ',' ',3,' ',8,' '},
        {6,' ',' ',4,1,' ',' ',' ',' '},
        {1,' ',' ',8,' ',' ',' ',9,5},
        {' ',6,' ',9,' ',' ',' ',2,' '},
        {' ',' ',2,3,' ',' ',' ',' ',4},
        {8,3,' ',' ',4,' ',1,6,' '}
    };
    printf("\n");
    printf("#======================================================#\n");
    printf("\n");
    printf("                    Sudoku Game\n");
    printf("               Created by Ahmed Khaled\n");
    printf("\n");
    printf("#======================================================#\n");
    while(counter<50)
    {
        array2d_print(arr,9,9);
        printf("Enter the number of Column: \n");
        scanf("%d",&c);
        printf("Enter the number of Row: \n");
        scanf("%d",&r);
        printf("Enter the number : \n");
        scanf("%d",&x);
        printf("Row: %d -- Column: %d -- Num: %d  \n",r,c,x);
        if((c<10)&&(c>0)&&(r<10)&&(r>0)&&(x<10)&&(x>0))
        {
            c1=Check_rules1(arr,x,r,c);
            c2=Check_rules2(arr1,r,c);
            if((c1==1) && (c2==1))
            {
                if( (arr[r-1][c-1]) > 10 )
                {
                    arr[r-1][c-1]=x;
                    counter++;
                }
                else
                {
                    arr[r-1][c-1]=x;
                }
            }
            else
            {
                printf("#======================================================#\n");
                printf("\n");
                printf("                      Error!!!     \n");
                printf("            U can't write this number here!!\n");
                printf("\n");
                printf("#======================================================#\n");
            }
        }
        else
        {
            printf("#======================================================#\n");
            printf("\n");
            printf("                  Error!!!     \n");
            printf("            Pls Enter Valid Number!!\n");
            printf("\n");
            printf("#======================================================#\n");
        }
        printf("Counter: %d \n",counter);
    }
    printf("#======================================================#\n");
    printf("\n");
    printf("                    Congratulations\n");
    printf("\n");
    printf("#======================================================#\n");
    return 0;
}
