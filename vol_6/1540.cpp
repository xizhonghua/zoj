//3119507	2012-11-11 21:16:43	 Accepted	1530	C++	430	59776	花花的表世界
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;

int n;
bool found;

struct node
{
	int l;
	bool f[101];
	int sum;
	node()
	{
		memset(f, 0, sizeof(f));
		l=1;
		f[0]=1;
		sum = 1;
	}
	node(node& nd, int bit)
	{
		l = nd.l+1;
		memcpy(f, nd.f, nd.l*sizeof(bool));
		f[l-1] = bit;
		sum = ((nd.sum*10) + (bit ? 1 : 0)) % n;
	}
};

void bfs(queue<node>& q)
{
	while(!q.empty() && !found)
	{
		node& nd = q.front();
		q.pop();
		if(nd.sum == 0)
		{
			for(int i=0;i<nd.l;i++)
				printf("%d", nd.f[i] ? 1 : 0);
			printf("\n");
			found = true;
			break;
		}
		q.push(node(nd,0));
		q.push(node(nd,1));
	}
}

int main()
{
	while(~scanf("%d", &n) && n)
	{
		if(n==1) { printf("1\n"); continue; }
		found = false;
		queue<node> q;
		node nd;
		q.push(nd);
		bfs(q);
	}
}