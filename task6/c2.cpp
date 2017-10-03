#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
#define N 200009
using namespace std;
int n,m,first[N],number=1,vis[N],used[N<<1],ans,fa[N],deep[N]; 
struct edge
{
	int to,next;
	void add(int x,int y)
	{
		to=y,next=first[x],first[x]=number;
	}
}e[N<<1];
struct node
{
	int x,y,z;
	node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
}Ans[N];
int read()
{
	int x=1;
	char ch;
	while (ch=gc,ch<'0'||ch>'9') if (ch=='-') x=-1;
	int s=ch-'0';
	while (ch=gc,ch>='0'&&ch<='9') s=s*10+ch-'0';
	return x*s;
}
void dfs(int x,int last)
{
	deep[x]=deep[fa[x]]+1;
	vis[x]=1;
	int num=0;
	for (int i=first[x];i;i=e[i].next)
		if (!vis[e[i].to]) fa[e[i].to]=x,dfs(e[i].to,i);
	bool flag=1;
	for (int i=first[x];i;i=e[i].next)
		if (deep[e[i].to]>deep[x]&&!used[i])
		{
			if (flag) Ans[++ans].x=e[i].to,Ans[ans].y=x;
			else Ans[ans].z=e[i].to;
			flag^=1;
			used[i]=used[i^1]=1;
		}
	if (!flag)
	{
		Ans[ans].z=fa[x];
		if (fa[x]==0) ans--;
		used[last]=used[last^1]=1;
	}
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		e[++number].add(x,y),e[++number].add(y,x);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]) dfs(i,0);
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++)
		printf("%d %d %d\n",Ans[i].x,Ans[i].y,Ans[i].z);
	return 0;
}