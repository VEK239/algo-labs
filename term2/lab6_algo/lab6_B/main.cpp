#include <iostream>
#include <vector>

using namespace std;
int maxRange = 1;
vector<int> parent;
vector<vector<int>> children;
vector<int> depth;
unsigned long long n;
vector<vector<int>> dp;

int dfs(int num)
{
    int curD = 0;
    for (auto el: children[num])
    {
        curD = max(curD, dfs(el));
    }
    depth[num] = 1 + curD;
    return depth[num];
}

void new_dfs(int v, int d)
{
    depth[v] = d;
    for (auto u: children[v])
    {
        new_dfs(u, d - 1);
    }
}

void preprocess()
{
    dfs(1);
    new_dfs(1, depth[1]);
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = parent[i];
    }
    for (int j = 1; j <= maxRange; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] > depth[v])
    {
        swap(u, v);
    }
    for (int i = maxRange; i >= 0; --i)
    {
        if ((dp[u][i] != 0) && (depth[dp[u][i]] - depth[v] <= 0))
        {
                u = dp[u][i];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int i = maxRange; i >= 0; --i)
    {
        if (dp[v][i] != dp[u][i])
        {
            v = dp[v][i];
            u = dp[u][i];
        }
    }
    return parent[u];
}

int main()
{
    cin >> n;
    parent.resize(n + 1);
    children.resize(n + 1);
    depth.resize(n + 1);
    dp.resize(n + 1);
    while (1 << maxRange <= n)
    {
        ++maxRange;
    }
    for (int i = 0; i <= n; ++i)
    {
        dp[i].resize(maxRange + 1);
    }
    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        parent[i] = p;
        children[p].push_back(i);
    }
    preprocess();
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}