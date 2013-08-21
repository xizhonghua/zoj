//2895372	2012-05-16 22:28:35	 Accepted	1159	C++	2700	5764	花花的表世界
#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int t, n;
char no[1025];
char c[11];
map<string, int> dict;
vector<string> keys;
int main(){
    scanf("%d", &t);
    while(t--)
    {
        dict.clear();
        keys.clear();
        scanf("%d", &n);
        scanf("%c", c);
        while(n--)
        {
            gets(no);
            int l = strlen(no);
            int p = 0;
            for(int i=0;i<l;i++)
                if(no[i] >= '0' && no[i] <= '9') c[p++] = no[i];
                else if(no[i] >= 'A' && no[i] <= 'C') c[p++] = '2';
                else if(no[i] >= 'D' && no[i] <= 'F') c[p++] = '3';
                else if(no[i] >= 'G' && no[i] <= 'I') c[p++] = '4';
                else if(no[i] >= 'J' && no[i] <= 'L') c[p++] = '5';
                else if(no[i] >= 'M' && no[i] <= 'O') c[p++] = '6';
                else if(no[i] == 'P' ||  no[i] == 'R' || no[i] == 'S') c[p++] = '7';
                else if(no[i] >= 'T' && no[i] <= 'V') c[p++] = '8';
                else if(no[i] >= 'W' && no[i] <= 'Z') c[p++] = '9';
            c[p] = '\0';
            string s(c);
            if(dict.count(s))
            {
                if(dict[s]==1) keys.push_back(s);
                dict[s]++;
            }
            else
            {
                dict[s] = 1;
            }
        }
        sort(keys.begin(), keys.end());
        for(vector<string>::iterator iter = keys.begin(); iter != keys.end(); iter++)
        {
            string s = *iter;
            int count = dict[s];
            iter->insert(iter->begin()+3, '-');
            printf("%s %d\n", iter->c_str(), count);
        }
        if(keys.size() == 0)
        {
            printf("No duplicates.\n");
        }
        if(t>0) printf("\n");
    }
}