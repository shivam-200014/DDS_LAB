//q2 determine x and y radixes in which 2 no are equal
// radix<=10

#include<stdio.h>
#include<math.h>
int num(int x,int i)
{
    int sum=0;
    int k=0;
    while(x>0)
    {
        int d=x%10;
        sum+=(d*pow(i,k));
        k++;
        x/=10;
    }
    return sum;  
}
int main()
{
    int n1,n2;
    printf("enter num1 and num2(radix<=10):");
    scanf("%d%d",&n1,&n2);
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            if(num(n1,i)==num(n2,j))
            printf("%d   %d\n", i, j);
    }
    }
}