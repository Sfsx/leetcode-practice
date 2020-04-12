#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#define INF 1e6
using namespace std;
const int maxn = 1510;
int g[maxn][maxn];
int du[maxn], n, m, L[maxn];

void bfs()
{
    queue<int> q;
    memset(L, -1, sizeof L);
    L[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
            if (g[t][i] && L[i] < L[t] + g[t][i])
            {
                L[i] = L[t] + g[t][i];
                q.push(i);
            }
    }
}
int main()
{
    int a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        g[a][b] = max(g[a][b], c);
    }
    bfs();
    cout << L[n];
    return 0;
}