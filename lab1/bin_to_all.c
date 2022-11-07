//q1 no system conversion from bin to rest 3

#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
  char EQU[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  char num[32];
  printf("enter a binary no:");
  scanf("%s",num);//binary input only
  strrev(num);

  //for decimal conversion
  int dec=0;
  int i=0;
  for(;i<strlen(num);++i)
  {
    if(num[i]=='1')
    {
      dec+=(int)pow(2,i);
    }
  }
  printf("in dec:%d",dec);

  //for octal conversion
  int n=dec;
  char oct[20]={'\0'};
  i=0;
  while(n>0)
  {
    int d=n%8;
    oct[i]=EQU[d] ;
    i++;  
    n/=8;
  }
  strrev(oct);
  printf("\nin oct:%s",oct);
  //for hexadecimal
  
  char hex[20]={'\0'};
  i=0;
  while(dec>0)
  {
    int d=dec%16;
    hex[i]=EQU[d];
    i++;
    dec/=16;
  }
  strrev(hex);
  printf("\nin hex:%s",hex);
}