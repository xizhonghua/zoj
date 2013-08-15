//2893886 2012-05-15 17:05:52 Accepted  1970 C++ 0 180 花花的表世界 
#include<stdio.h>
#include<string.h>
#define MAX 100001

int main(){
 char a[MAX], b[MAX];
 while(~scanf("%s %s", a, b))
 {
  int la = strlen(a);
  int lb = strlen(b);
  int i = 0;
  for(int j=0;j<lb;j++)
   if(b[j] == a[i]) i++;
  printf("%s\n", i == la ? "Yes" : "No");
 }
}