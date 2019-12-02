#include <iostream>
#include <vector>

using namespace std;
unsigned long long maxRange = 1;
vector<int> tree;
unsigned long long n;
vector<vector<int>> dp;

void preprocess()
{
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = tree[i];
    }
    for (int j = 1; j <= maxRange; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}

int main()
{
    cin >> n;
    tree.resize(n + 1);
    dp.resize(n + 1);
    while (1 << maxRange <= n)
    {
        ++maxRange;
    }
    for (int i = 0; i <= n; ++i)
    {
        dp[i].resize(maxRange + 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        int parent;
        cin >> parent;
        if (parent != 0)
        {
            tree[i] = parent;
        }
    }
    preprocess();
    for (int i = 1; i <= n; ++i)
    {
        cout << i << ": ";
        for (auto el: dp[i])
        {
            if (el != 0)
            {
                cout << el << " ";
            }
        }
        cout << "\n";
    }
}