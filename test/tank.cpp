#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long

const int MAXN = 1e3 + 10;

struct abc
{
    LL pos, speed;
};

LL rest[MAXN], d;
int n, m, cnt = 0;
abc a[MAXN];
bool bo[MAXN], can[MAXN][MAXN];

int main()
{
    scanf("%d%d%I64d", &n, &m, &d);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &rest[i]);
    sort(rest + 1, rest + 1 + n);
    for (int i = 1; i <= m; i++)
        scanf("%I64d%I64d", &a[i].pos, &a[i].speed);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (a[j].pos <= d)
                can[i][j] = true;
        for (int j = 1; j <= m; j++)
            a[j].pos += rest[i] * a[j].speed;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
            if (!bo[j] && can[i][j])
            {
                bo[j] = true;
                cnt++;
                break;
            }
    }
    printf("%d\n", cnt);
    return 0;
}