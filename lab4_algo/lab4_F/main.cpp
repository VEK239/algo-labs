#include <iostream>
long long a[17][100500];
int lg[100500];

long long min(long long a, long long b)
{
    return a < b ? a : b;
}

long long max(long long a, long long b)
{
    return a >= b ? a : b;
}

void lgBuild(long long n)
{
    for (long long i = 0; i <= n; i++)
    {
        lg[i] = (i > 1 ? lg[i / 2] + 1 : 0);
    }
}

void arrayBuild(long long n)
{
    for (long long i = 2; i <= n; ++i)
    {
        a[0][i] = (23 * a[0][i - 1] + 21563) % 16714589;
    }
    for (long long p = 1; (1 << p) <= n; p++)
    {
        for (long long i = 1; i + (1 << p) <= n + 1; i++)
        {
            a[p][i] = min(a[p - 1][i], a[p - 1][i + (1 << (p - 1))]);
        }
    }
}

long long getmin(long long u, long long v)
{
    int p = lg[v - u + 1];
    return min(a[p][u], a[p][v - (1 << p) + 1]);
}

int main()
{
    long long n, m;
    std::cin >> n >> m >> a[0][1];
    lgBuild(n);
    arrayBuild(n);
    long long u, v;
    std::cin >> u >> v;
    long long ans = getmin(u,v);
    for (int i = 1; i < m; ++i)
    {
        u = ((17 * u + 751 + ans + 2 * i) % n) + 1;
        v = ((13 * v + 593 + ans + 5 * i) % n) + 1;
        ans = getmin(min(u, v), max(u, v));
    }
    std::cout << u << " " << v << " " << ans;
}