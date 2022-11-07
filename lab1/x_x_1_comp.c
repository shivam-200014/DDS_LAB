//r and r-1 complements...
//1<=r<=10

#include<stdio.h>
#include<string.h>

char eq[]={'0','1','2','3','4','5','6','7','8','9'};

void str_nset(char *s,int n,char ch)
{
    int i=0;
    while(n--)
    {
        s[i]=ch;
        i++;
    }
}

char* add(char *n1,char *n2,int r)
{
    int carry=0;
    int i=strlen(n1)-1;
    int j=strlen(n2)-1;
    static char res[100];
    res[0]='\0';
    int k=0;
    while (i>=0||j>=0)
    {
        int d1,d2;   
        d1=n1[i]-'0';
        d2=n2[i]-'0';
        res[k]=eq[(carry+d1+d2)%r];
        carry=(carry+d1+d2)/r;
        k++;
        --i;
        --j;
    }
    if(carry!=0)
    {
        res[k]=eq[carry];
    }
    strrev(res);
    return res;  
}

int main()
{
    int r;
    char num[11];
    printf("enter radix(<=10) and number:");
    scanf("%d %s",&r,num);
    char r_1[strlen(num)+1];
    for(int i=0;i<strlen(num);++i)
    {
        int x=num[i]-'0';
        r_1[i]=eq[(r-1)-x];
    }
    char _1[strlen(num)+1];
    str_nset(_1,strlen(num)-1,'0');
    _1[strlen(num)-1]='1';
    _1[strlen(num)]='\0';           //termination with null is mandatory else wrong results come
    r_1[strlen(num)]='\0';
    printf("\n%d's comp:%s\n%d's comp:%s",r-1,r_1,r,add(r_1,_1,r));
}
