//for 84-2-1
#include<stdio.h>
#include<string.h>
int main()
{
    char * strArr[]={"0000","0111","0110","0101","0100","1011","1010","1001","1000","1111"};
    for(int i=0;i<10;++i)
        printf("%s  ",strArr[i]);
    printf("\n");
    for(int i=0;i<10;++i)
        printf("  %d   ",i);
    int i=10;
    printf("\n");
    int count=0;
    while(i--)
    {
        int num;
        printf("enter no(0-9):");
        scanf("%d",&num);
        int comp=9-num;
        char str[5];
        strcpy(str,strArr[num]);
        for(int i=0;i<4;++i)
        {
            if(str[i]=='0')
                str[i]='1';
            else
                str[i]='0';
        }
        if(strcmp(str,strArr[num])==0);
            count++;
        printf("~num:%d\t1`s comp of digit:%s\n",comp,str);
    }
    if(count==10)
        printf("number sys:84-2-1 satisfied self complementing property\n");

}