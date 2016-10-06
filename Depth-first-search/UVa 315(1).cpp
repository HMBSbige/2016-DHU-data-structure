#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

#define N 1000
#define met(a, b) memset (a, b, sizeof (a))

vector <vector <int> > G;
int n, Time, vis[N], low[N], dfn[N], f[N];

void Init ();
int solve ();
void Tarjan (int u, int fa);

int main ()
{
    while (scanf ("%d", &n)==1 && n)
    {
        Init ();
        int a, b;
        char ch;

        while (scanf ("%d", &a)==1 && a)
        {
            while (scanf ("%d%c", &b, &ch)==2)
            {
                G[a].push_back (b);
                G[b].push_back (a);
                if (ch == '\n') break;  //bidirectional
            }
        }
        printf ("%d\n", solve ());
    }
    return 0;
}

void Init ()
{
    G.clear ();
    G.resize (n+1);

    met (low, 0);
    met (dfn, 0);
    Time = 0;
}

int solve ()
{
    int ans = 0, rt = 0;
    met (vis, 0);
    Tarjan (1, 0);

    for (int i=2; i<=n; i++)
    {
        int v = f[i];
        if (v == 1) rt++;
        if (dfn[v] <= low[i]) vis[v] = 1;
    }

    for (int i=2; i<=n; i++)
        if (vis[i]) ans++;
    if (rt > 1) ans++;
    return ans;
}

void Tarjan (int u, int fa)
{
    low[u] = dfn[u] = ++Time;
    f[u] = fa;
    int len = G[u].size (), v;

    for (int i=0; i<len; i++)
    {
        v = G[u][i];
        if (!dfn[v])
        {
            Tarjan (v, u);
            low[u] = min (low[u], low[v]);
        }
        else if (v != fa)
            low[u] = min (low[u], dfn[v]);
    }
}

