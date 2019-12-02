#include <iostream>
#include <cmath>
struct node
{
    bool set = false;
    int leftBound;
    int rightBound;
    long long value = 0;
    int valNum;
};
node tree[2500000];
long n, arrLen;
long long min(long long a, long long b)
{
    return a < b ? a : b;
}
node max;
int arrLength(int n)
{
    int y = 1;
    while (y < n)
    {
        y = y * 2;
    }
    return y;
}

void treeBuild(int len)
{
    max.leftBound = 0;
    max.rightBound = 0;
    max.value = LLONG_MAX;
    max.valNum = 0;
    for (int i = 0; i < n; ++i)
    {
        tree[len - 1 + i].leftBound = i + 1;
        tree[len - 1 + i].rightBound = i + 1;
        tree[len - 1 + i].valNum = i + 1;
    }
    for (int i = n; i < len; ++i)
    {
        tree[len - 1 + i].leftBound = i + 1;
        tree[len - 1 + i].rightBound = i + 1;
        tree[len - 1 + i].valNum = i + 1;
        tree[len - 1 + i].value = LLONG_MAX;
    }
    for (int i = len - 2; i >= 0; --i)
    {
        tree[i].leftBound = tree[2 * i + 1].leftBound;
        tree[i].rightBound = tree[2 * i + 2].rightBound;
        tree[i].valNum = tree[2 * i + 1].valNum;
    }
}

void push(int element) {
    if (tree[element].set)
    {
        if (tree[2 * element + 1].value < tree[element].value)
        {
            tree[2 * element + 1].value = tree[element].value;
            tree[2 * element + 1].set = true;
        }
        if (tree[2 * element + 2].value < tree[element].value)
        {
            tree[2 * element + 2].value = tree[element].value;
            tree[2 * element + 2].set = true;
        }
        tree[element].set = false;
    }
}

void set(int element, int l, int r, long long newValue)
{
    if (tree[element].rightBound < l || tree[element].leftBound > r)
    {
        return;
    }
    if (tree[element].rightBound <= r && tree[element].leftBound >= l)
    {
        if (tree[element].value < newValue)
        {
            tree[element].value = newValue;
            tree[element].set = true;
        }
        return;
    }
    push(element);
    set(2 * element + 2, l, r, newValue);
    set(2 * element + 1, l, r, newValue);
    tree[element].value = min(tree[2 * element + 1].value, tree[2 * element + 2].value);
    if (tree[2 * element + 1].value <= tree[2 * element + 2].value)
    {
        tree[element].valNum = tree[2 * element + 1].valNum;
    }
    else
    {
        tree[element].valNum = tree[2 * element + 2].valNum;
    }
}

node minlook(int element, int l, int r)
{
    if (tree[element].rightBound < l || tree[element].leftBound > r)
    {
        return max;
    }
    if (tree[element].rightBound <= r && tree[element].leftBound >= l)
    {
        return tree[element];
    }
    push(element);
    node left = minlook(2 * element + 1, l , r);
    node right = minlook(2 * element + 2, l , r);
    return left.value < right.value ? left : right;
}

void print(int n)
{
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        std::cout << "element: " << i << " value: " << tree[i].value << " left: " << tree[i].leftBound << " right: "
        << tree[i].rightBound << " set: " << tree[i].set << " valNum: " << tree[i].valNum << std::endl;
    }
}

int main()
{
    long m;
    std::cin >> n >> m;
    arrLen = arrLength(n);
    treeBuild(arrLen);
    std::string st;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> st;
        if (st == "attack")
        {
            int l, r;
            std::cin >> l >> r;
            node result = minlook(0, l, r);
            std::cout << result.value << " " << result.valNum << "\n";
        }
        if (st == "defend")
        {
            int l, r;
            long long x;
            std::cin >> l >> r >> x;
            set(0, l, r, x);
        }
        if (st == "print")
        {
            print(arrLen);
        }
    }
}