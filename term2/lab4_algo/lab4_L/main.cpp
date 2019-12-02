#include <iostream>

long long fenvikTree[128][128][128];
int n;

void add(int x, int y, int z, long long d)
{
    for (int i = x; i < n; i = i | (i + 1))
    {
        for (int j = y; j < n; j = j | (j + 1))
        {
            for (int k = z; k < n; k = k | (k + 1))
            {
                fenvikTree[i][j][k] += d;
            }
        }
    }
}
long long prefixSum(int x, int y, int z)
{
    long long result = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
    {
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
        {
            for (int k = z; k >= 0; k = (k & (k + 1)) - 1)
            {
                result += fenvikTree[i][j][k];
            }
        }
    }
    return result;
}
long long sum(int leftX, int rightX, int leftY, int rightY, int leftZ, int rightZ)
{
    long long result = 0;
    result += prefixSum(rightX, rightY, rightZ);
    result -= prefixSum(rightX, rightY, leftZ);
    result -= prefixSum(rightX, leftY, rightZ);
    result -= prefixSum(leftX, rightY, rightZ);
    result += prefixSum(rightX, leftY, leftZ);
    result += prefixSum(leftX, leftY, rightZ);
    result += prefixSum(leftX, rightY, leftZ);
    result -= prefixSum(leftX, leftY, leftZ);
    return result;
}

int main()
{
    std::cin >> n;
    int mode;
    while (std::cin >> mode)
    {
        if (mode == 2)
        {
            int lx, rx, ly, ry, lz, rz;
            std::cin >> lx >> ly >> lz >> rx >> ry >> rz;
            std::cout << sum(lx - 1, rx, ly - 1, ry, lz - 1, rz) << "\n";
        }
        if (mode == 1)
        {
            long long k;
            int x, y, z;
            std::cin >> x >> y >> z >> k;
            add(x, y, z, k);
        }
        if (mode == 3)
        {
            return 0;
        }
    }
}