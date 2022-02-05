#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment1.h"

int sum_interval(int x, int y) {
  return x<y? (y+x)*(y-x+1)/2 : (y+x)*(x-y+1)/2;
}



int hide_letters(char* str)  {
  int x=strlen(str),j=0;
  for(int i=0;i<x;i++) 
  {
    if('a'<=str[i]&&str[i]<='z') {str[i]='*'; j++;}
    if('A'<=str[i]&&str[i]<='Z') {str[i]='$'; j++;}
  }
  return j;
}



int count_max(const int* arr, int n) {
  int maxx=arr[0],cnt=0;
  for(int i=0;i<n;i++) if(arr[i]==maxx) cnt++; else if(arr[i]>maxx) {maxx=arr[i]; cnt=1;} 
  return cnt;
}



char* mult_number_by_digit(const char* num, int digit) 
{
    int len=strlen(num);
    int current;
    char* rev_num=malloc(sizeof(char)*len);
    char* rev_qwq=malloc(sizeof(char)*(len+1));
    for(int i=0;i<len;i++) rev_num[i]=num[len-i-1];
    for(int i=0;i<=len;i++) rev_qwq[i]='0'; 
    rev_qwq[len+1]='\0';
    for(int i=0;i<len;i++) 
    {
      current=digit*(rev_num[i]-'0')+(rev_qwq[i]-'0');
      if(current<10) rev_qwq[i]=current+'0';
      else 
      {
        rev_qwq[i]=current%10+'0';
        rev_qwq[i+1]=current/10+'0';
      }
    }
    if(rev_qwq[len]=='0')
   {
       char* qwq=malloc(sizeof(char)*(len));
       for(int i=0;i<len;i++) qwq[i]=rev_qwq[len-i-1];
       qwq[len]='\0';
       free(rev_num);
       free(rev_qwq);
       return qwq;
   }    
   else
   {
      char* qwq=malloc(sizeof(char)*(len+1));
       for(int i=0;i<len+1;i++) qwq[i]=rev_qwq[len-i];
       qwq[len+1]='\0';
       free(rev_num);
       free(rev_qwq);
       return qwq;
   }
} 

char* mult_digits(const int* digits, int n)
{
    char* res=(char*) malloc(sizeof(char)*n);
    char* ans=(char*) malloc(sizeof(char)*n);
    res[0]=digits[0]+'0'; res[1]='\0';
    for(int i=1;i<n;i++)
    {
      ans=mult_number_by_digit(res,digits[i]);
      res=ans;
    }
    free(ans);
    return res;
}
