#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment2.h"

struct dat
{
    int tag;
    char* term;
    char* defi;
}Dat[30010];
int cnt=0; int knt=0;
char* file[8010];
int add_term(const char* file_name, const char* word, const char* definition) {
  int flag=0;
    for(int i=0;i<cnt;i++)
        if(!strcmp(file_name,file[i])) flag=i;
    if(flag==0)
    {
        file[cnt]=file_name;
        Dat[knt].tag=cnt;
        Dat[knt].term=term;
        Dat[knt].defi=definition;
        knt++; cnt++;
        return 1;
    }
    else
    {
        int qwq=0;
        for(int i=0;i<knt;i++)
            if(Dat[i].tag==flag&&Dat[i].term==term) qwq=1;
        if(qwq==1) return 0;
        Dat[knt].tag=flag;
        Dat[knt].term=term;
        Dat[knt].defi=definition;
        knt++;
        return 1;
    }
}  



char* find_term(const char* file_name, const char* word) {
  int flag=0;
    for(int i=0;i<cnt;i++)
        if(!strcmp(file_name,file[i])) flag=i;
    if(!flag) return NULL;
    for(int i=0;i<knt;i++)
        if(Dat[i].tag==flag&&!strcmp(Dat[i].term,term))
            return Dat[i].defi;
    return NULL;
}  



uint64_t fib3(unsigned int n) {
  uint64_t dataA[55];
    dataA[0]=0; dataA[1]=1; dataA[2]=2;
    for(int i=3;i<50;i++)
        dataA[i]=dataA[i-1]+2*dataA[i-2]+3*dataA[i-3];
    return dataA[n];
}



int count_tokens(const char* str) {
  int cnt=0; int now=1;
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]==32)
        {
            if(i==0&&str[i]==32) continue;
            if(i>0&&str[i-1]==32) continue;
            if(now) cnt+=1;
            now=1;
        }
        else
        {
            if(str[i]>='a'&&str[i]<='z') continue;
            else now=0; 
        }
    }
    if(now&&str[len-1]!=32) cnt+=1;
    return cnt;
}  



char** get_tokens(const char* str) {
  int cnt=-1; int now=1; int knt=0;
    int len=strlen(str);
    char** ans=(char**)malloc(sizeof(char*)*count_tokens(str));
    char* temp=(char*)malloc(sizeof(char)*len);
    for(int i=0;i<len;i++)
    {
        if(str[i]==32)
        {
            if(i==0) continue;
            if(i>0&&str[i-1]==32) continue;
            if(now)
            {
                ans[knt]=(char*)malloc(sizeof(char)*(cnt+1));
                for(int i=0;i<=cnt;i++) ans[knt][i]=temp[i];
                ans[knt][cnt+1]='\0';
                cnt=-1; knt++;
            }
            now=1;
        }
        else
        {
            if(str[i]>='a'&&str[i]<='z'&&now)
            {
                cnt+=1; temp[cnt]=str[i];
            }
            else
            {
                now=0; cnt=-1;
            }
        }
    }
    if(now==1&&str[len-1]!=32)
    {
        ans[knt]=(char*)malloc(sizeof(char)*(cnt+1));
        for(int i=0;i<=cnt;i++) ans[knt][i]=temp[i];
        ans[knt][cnt+1]='\0';
        cnt=-1; knt++;
    }
    return ans;
}  

