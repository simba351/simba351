#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment3.h"

// generic swap
// assumption: the memory segments don't overlap
void swap(void* a, void* b, size_t s)  {
  char* char_a = (char*)a;
  char* char_b = (char*)b;

  for (int i=0;i<s;i++) {
    char tmp = char_a[i];
    char_a[i] = char_b[i];
    char_b[i] = tmp;
  }
} 

int cmp(const void* _A, const void* _B)
{
  point2d* A=(point2d*)_A;
  point2d* B=(point2d*)_B;
  if(abs(A->x)+abs(A->y)<abs(B->x)+abs(B->y)) return -1;
  if(abs(A->x)+abs(A->y)==abs(B->x)+abs(B->y))
  {
    if(A->x==B->x) return (A->y)-(B->y);
    else return (A->x)-(B->x);
  }
}
void sort_points(point2d* ar, int n)
{
  qsort(ar,n,sizeof(point2d),cmp);
  return;
}



int gen_insertion_sort(void* ar, int n, size_t size, int (*compare)(const void*, const void*)) {
  int cnt=0;
  int* temp;
  for(int i=1;i<n;i++)
  {
    void* key=malloc(size);
    memcpy(key,(ar+i*size),size);
    temp=(int*)key;
    int j=i-1;
    while((j>=0)&&(compare(key,(ar+j*size))<0))
    {
      
      memcpy((ar+(j+1)*size),(ar+j*size),size);
      j--;
      cnt++;
    }
    memcpy((ar+(j+1)*size),key,size);
  }
  return cnt;
}  


int find(int* A, int start, int end, bool (*pred)(int))
{
  for(int i=start;i<=end;i++)
    if(pred(A[i])==true) return i;
  return -1;
}

int count(int* A, int start, int end, bool (*pred)(int))
{
  int cnt=0;
  for(int i=start;i<=end;i++)
    if(pred(A[i])==true) cnt++;
  return cnt;
}

void map(int* A, int start, int end, int (*f)(int))
{
  for(int i=start;i<=end;i++)
    A[i]=f(A[i]);
}

int reduce(int* A, int start, int end, int (*f)(int,int))
{
  int cnt=A[start];
  for(int i=start+1;i<=end;i++)
    cnt=f(cnt,A[i]);
  return cnt;
}