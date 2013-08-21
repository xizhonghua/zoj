//2893346 2012-05-15 11:05:25 Accepted  2851 C++ 0 180 花花的表世界 
#include<stdio.h>
#include<string.h>

int main()
{
 char line[1025];
 int c;
 scanf("%d\n", &c);
 while(c-->0)
 {
  int tabs = 0;
  int spaces = 0;
  while(true)
  {
   gets(line);
   if(strcmp(line, "##")==0) break;
   int l = strlen(line);
   for(int i=0;i<l;i++)
    if(line[i] == '\t') tabs++;
   for(int i=l-1;i>=0;i--)
    if(line[i] == ' ') spaces++; else if(line[i] == '\t') spaces+=4; else break;
  }
  printf("%d tab(s) replaced\n", tabs);
  printf("%d trailing space(s) removed\n", spaces);
 }
}