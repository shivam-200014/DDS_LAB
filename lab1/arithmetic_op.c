//q3) arithmetic operation on binary numbers
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char eq[]={'0','1'};
void to_bin(char *s,int n)
{
    char res[100]={'\0'};
    int i=0;
    while(n>=0)
    {
        int d=n%2;
        res[i++]=eq[d];
        n/=2;
        if(n==0)
            n--;
    }
    strrev(res);
    strcpy(s,res);
}

int to_dec(char *s)//binary string
{
    int dec=0;
    char *temp=(char*)malloc(sizeof(char)*100);
    strcpy(temp,s);
    strrev(temp);
    int i=0;
    while(*temp!='\0')
    {
        if(*temp=='1')
        {
            dec+=pow(2,i);
        }
        ++i;
        temp++;
    }
    return dec;
}

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int main()
{
    char num1[32],num2[32];
    printf("enter two binary numbers:");
    scanf("%s%s",num1,num2);
    int n1=to_dec(num1);
    int n2=to_dec(num2);

    //addition
    char add_res[100]={'\0'};
    to_bin(add_res,n1+n2);

    //subtraction
    int count=0;
    if(n1<n2)
    {
        swap(&n1,&n2);
        count++;
    }
    char sub_res[100]={'\0'};
    to_bin(sub_res,n1-n2);
    char ch=' ';
    if(count==1)
        ch='-';
    
    //multiplication
    char mul_res[100]={'\0'};
    to_bin(mul_res,n1*n2);

    //division
    if(count==1)
        swap(&n1,&n2);
    char dev_res[100]={'\0'};
    to_bin(dev_res,n1/n2);
    printf("add:%s\nsub:%c%s\nmul:%s\ndiv:%s\n",add_res,ch,sub_res,mul_res,dev_res);

}