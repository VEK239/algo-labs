#include <iostream>
//using namespace std;

struct node
{
    int leftBound;
    int rightBound;
    long long value;
};

node tree[500000];

void print(int n)
{
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        std::cout << "element: " << i << " value: " << tree[i].value << " left: " << tree[i].leftBound << " right: " << tree[i].rightBound << endl;
    }
}

int arrLength(int n)
{
    int y = 1;
    while (y < n)
    {
        y = y * 2;
    }
    return y;
}

void treeBuild(int n, const long long *a)
{
    for (int i = 0; i < n; ++i)
    {
        tree[n - 1 + i].value = a[i];
        tree[n - 1 + i].leftBound = i + 1;
        tree[n - 1 + i].rightBound = i + 1;
    }
    for (int i = n - 2; i >= 0; --i)
    {
        tree[i].value = tree[2 * i + 1].value + tree[2 * i + 2].value;
        tree[i].leftBound = tree[2 * i + 1].leftBound;
        tree[i].rightBound = tree[2 * i + 2].rightBound;
    }
}

void set(int element, long long newValue)
{
    tree[element].value = newValue;
    while (element > 0)
    {
        element = (element - 1) / 2;
        tree[element].value = tree[2 * element + 1].value + tree[2 * element + 2].value;
    }
}

long long sum(int element, int l, int r)
{
    if (tree[element].rightBound < l || tree[element].leftBound > r)
    {
        return 0;
    }
    if (tree[element].rightBound <= r && tree[element].leftBound >= l)
    {
        return tree[element].value;
    }
    return sum(2 * element + 1, l , r) + sum(2 * element + 2, l , r);
}

int main()
{
    int n;
    std::cin >> n;
    int arrLen = arrLength(n);
    long long a[arrLen];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    for (int i = n; i < arrLen; ++i)
    {
        a[i] = 0;
    }
    treeBuild(arrLen, a);
    std::string st;
    while (std::cin >> st)
    {
        if (st == "sum")
        {
            int l, r;
            std::cin >> l >> r;
            std::cout << sum(0, l, r) << std::endl;
        }
        if (st == "set")
        {
            int el;
            long long x;
            std::cin >> el >> x;
            set(arrLen - 2 + el, x);
        }
        /*if (st == "print")
        {
            print(arrLen);
        }*/
    }
}