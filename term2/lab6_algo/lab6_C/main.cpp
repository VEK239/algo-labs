//#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int maxRange = 1;
vector<int> parent;
vector<int> capacity;
vector<vector<int>> children;
vector<int> depth;
unsigned long long n;
vector<vector<int>> dp;
vector<vector<int>> minp;
ifstream cin("minonpath.in");
ofstream cout("minonpath.out");

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
        minp[i][0] = capacity[i];
    }
    for (int j = 1; j <= maxRange; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
        for (int i = 1; i <= n; ++i)
        {
            minp[i][j] = min(minp[dp[i][j - 1]][j - 1], minp[i][j - 1]);
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] > depth[v])
    {
        swap(u, v);
    }
    int currMin = capacity[u];
    for (int i = maxRange; i >= 0; --i)
    {
        if ((dp[u][i] != 0) && (depth[dp[u][i]] - depth[v] <= 0))
        {
            currMin = min(currMin, minp[u][i]);
            u = dp[u][i];
        }
    }
    if (u == v)
    {
        return currMin;
    }
    for (int i = maxRange; i >= 0; --i)
    {
        if (dp[v][i] != dp[u][i])
        {
            currMin = min(currMin, min(minp[v][i], minp[u][i]));
            v = dp[v][i];
            u = dp[u][i];
        }
    }
    return min(currMin, min(capacity[u], capacity[v]));
}

int main()
{
    cin >> n;
    parent.resize(n + 1);
    capacity.resize(n + 1);
    children.resize(n + 1);
    depth.resize(n + 1);
    dp.resize(n + 1);
    minp.resize(n + 1);
    while (1 << maxRange <= n)
    {
        ++maxRange;
    }
    for (int i = 0; i <= n; ++i)
    {
        dp[i].resize(maxRange + 1);
        minp[i].resize(maxRange + 1);
    }
    for (int i = 2; i <= n; ++i)
    {
        int p, c;
        cin >> p >> c;
        parent[i] = p;
        capacity[i] = c;
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