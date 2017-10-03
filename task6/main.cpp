#define DEBUG_DEV

#ifdef DEBUG_DEV
#include <ctime>
#endif

#include <fstream>
#include <iostream>

using namespace std;

#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
#define N 200009

static int n, m;
static int first[N], number = 1, vis[N], used[N << 1], ansCount, fa[N], deep[N];

static struct edge
{
    int to, next;
    void add(int x, int y)
    {
        to = y;
        first[x] = number;
        next = first[x];
    }
} e[N << 1];

static struct Node
{
    int x,y,z;
    Node(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
} ans[N];

void dfs(int x, int last)
{
    deep[x] = deep[fa[x]] + 1;
    vis[x] = 1;
    for (int i = first[x]; i; i = e[i].next)
        if (!vis[e[i].to]) {
            dfs(e[i].to, i);
            fa[e[i].to] = x;
        }

    bool flag = 1;
    for (int i = first[x]; i; i = e[i].next)
        if (deep[e[i].to] > deep[x] && !used[i])
        {
            if (flag) {
                ans[ansCount].y = x;
                ans[++ansCount].x = e[i].to;
            } else ans[ansCount].z = e[i].to;
            flag ^= 1;
            used[i] = used[i ^ 1] = 1;
        }

    if (!flag)
    {
        ans[ansCount].z = fa[x];
        if (fa[x] == 0) ansCount--;
        used[last] = used[last ^ 1] = 1;
    }
}

int main(int argc, char **argv)
{
    istream *inp = &cin;
    ifstream inf;
#ifdef DEBUG_DEV
    if (argc > 1) {
        inf.open(argv[1]);
        if (inf.good()) inp = &inf;
    }
#endif

#ifdef DEBUG_DEV
    clock_t beg = clock();
#endif

    int *_f = (int *)&first;
    edge *_e = (edge *)e;

    *inp >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        *inp >> x >> y;
        e[++number].add(x, y);
        e[++number].add(y, x);
    }

    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs(i, 0);

    cout << ansCount << endl;
    for (int i = 1; i <= ansCount; ++i)
        cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << endl;

#ifdef DEBUG_DEV
    clock_t end = clock();
    int ms = int(double(end - beg) * 1000 / CLOCKS_PER_SEC);
    cout << "Elapsed: " << ms << " ms" << endl;
#endif

    return 0;
}
