#include <iostream>
#include <vector>
using namespace std;

int maxRange = 1;
int curNum = 2;
struct Dino
{
    bool alive = true;
    int aliveParent = 0;
};

vector<Dino> dinos;
vector<int> depth;
unsigned long long n;
vector<vector<int>> dp;

int findAlive(int u)
{
    if (!dinos[u].alive)
    {
        dinos[u].aliveParent = findAlive(dinos[u].aliveParent);
    }
    return (dinos[u].alive ? u : dinos[u].aliveParent);
}

int lca(int u, int v)
{

    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    for (int i = maxRange; i >= 0; --i)
    {
        if ((dp[u][i] != 0) && (depth[dp[u][i]] - depth[v] >= 0))
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
    return findAlive(dinos[u].aliveParent);
}

int main()
{
    cin >> n;
    dinos.resize(n + 1);
    dinos[1].aliveParent = 1;
    depth.resize(n + 1, 0);
    dp.resize(n + 1);
    while (1 << maxRange <= n)
    {
        ++maxRange;
    }
    for (int i = 0; i <= n; ++i)
    {
        dp[i].resize(static_cast<unsigned long long int>(maxRange + 1), 0);
    }
    dp[1][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        char mode;
        cin >> mode;
        if (mode == '+')
        {
            int p;
            cin >> p;
            dinos[curNum].aliveParent = p;
            depth[curNum] = depth[p] + 1;
            dp[curNum][0] = p;
            for (int j = 1; j <= maxRange; ++j)
            {
                dp[curNum][j] = dp[dp[curNum][j - 1]][j - 1];
            }
            ++curNum;
        }
        else if (mode == '-')
        {
            int del;
            cin >> del;
            dinos[del].alive = false;
        }
        else
        {
            int left, right;
            cin >> left >> right;
            cout << lca(left, right) << "\n";
        }
    }
}
