#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct node
{
    int u, v, w, p;
} edge[1000000];
bool mark[1000000];
int fa[1000000];
int n, m, num = 1;
void add(int x, int y, int z)
{
    edge[num].u = x;
    edge[num].v = y;
    edge[num].w = z;
    edge[num].p = num;
    num++;
}
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void unionn(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}
void kruskal(int p)
{
    int ans = 0;
    int k = 0;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= num - 1; i++)
    {
        if (find(edge[i].u) != find(edge[i].v) && edge[i].p <= p)
        {
            unionn(edge[i].u, edge[i].v);
            ans += edge[i].w;
            k++;
        }
        if (k == n - 1)
        {
            cout << ans << endl;
            return;
        }
    }
    cout << -1 << endl;
}
bool comp(node a, node b)
{
    return a.w < b.w;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        sort(edge + 1, edge + num, comp);
        kruskal(i);
    }
    return 0;
}