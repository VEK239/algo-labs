#include <iostream>
long long arr[10000000];
long long b[20000000];
int main()
{
    long long n, x, y;
    std::cin >> n >> x >> y;
    std::cin >> arr[0];
    for (int i = 1; i < n; ++i)
    {
        arr[i] = (x * arr[i - 1] + y) % 65536;
    }
    for (int i = 1; i < n; ++i)
    {
        arr[i] += arr[i - 1];
    }
    long long m, z, t;

    std::cin >> m >> z >> t;
    std::cin >> b[0];
    for (int i = 1 ; i < 2 * m; ++i)
    {
        b[i] = (1073741824 + (z * b[i - 1] + t)) % 1073741824;
    }
    for(int i = 0; i < 2 * m; ++i)
    {
        b[i] = b[i] % n;
    }
    long long sum = 0;
    for (int i = 0; i < m; ++i)
    {
        long long left = b[2 * i] < b[2 * i + 1] ? b[2 * i] : b[2 * i + 1];
        long long right = b[2 * i] >= b[2 * i + 1] ? b[2 * i] : b[2 * i + 1];
        if (left == 0)
        {
            sum += arr[right];
        }
        else
        {
            sum += arr[right] - arr[left - 1];
        }
    }
    std::cout << sum;
}