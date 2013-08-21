//2896404	2012-05-18 16:16:12	Accepted	3474	C++	0	180	花花的表世界
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Friend
{
    int recover;
    int consume;
    Friend(int _p1, int _p2, int _p3, int _r)
    {
        this->recover = _r;
        this->consume = 99999;
        
        for(int i=0;i<=3;i++)
            for(int j=0;j<=4;j++)
                for(int k=0;k<=7;k++)
                    if(i*3 + j*2 + k >= 7)
                    {
                        int c = _p1 * i + _p2*j + _p3*k;
                        if(c<this->consume) this->consume = c;
                    }
    }
};

vector<Friend> f1;
vector<Friend> f2;

bool cmp1(const Friend &fa, const Friend &fb)
{
    return fa.consume < fb.consume;
}

bool cmp2(const Friend &fa, const Friend &fb)
{
    return fa.recover > fb.recover;
}

int main()
{
    int m, t, s;
    int p1, p2, p3, r;
    scanf("%d", &m);
    while(m--)
    {
        f1.clear();
        f2.clear();
        scanf("%d %d", &t, &s);
        for(int i=0;i<t;i++)
        {
            scanf("%d %d %d %d", &p1, &p2, &p3, &r);
            Friend f(p1, p2, p3, r);
            if(f.recover > f.consume) f1.push_back(f); else f2.push_back(f);
        }
        sort(f1.begin(), f1.end(), cmp1);
        sort(f2.begin(), f2.end(), cmp2);

        for(vector<Friend>::iterator it = f1.begin(); it != f1.end(); ++it)
        {
            s -= it->consume;
            if(s <= 0) break;
            s += it->recover;
        }

        for(vector<Friend>::iterator it = f2.begin(); it != f2.end(); ++it)
        {
            s -= it->consume;
            if(s <= 0) break;
            s += it->recover;
        }

        if(s <= 0) printf("no\n"); else printf("%d\n", s);
    }
}