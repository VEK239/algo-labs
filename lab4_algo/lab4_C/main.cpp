#include <iostream>
#include <cmath>
struct node
{
    long long add = 0;
    bool set = false;
    int leftBound;
    int rightBound;
    long long value;
};

long long a[200000];
node tree[600000];

long long min(long long a, long long b)
{
    return a < b ? a : b;
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

void treeBuild(int n)
{
    for (int i = 0; i < n; ++i)
    {
        tree[n - 1 + i].value = a[i];
        tree[n - 1 + i].leftBound = i + 1;
        tree[n - 1 + i].rightBound = i + 1;
    }
    for (int i = n - 2; i >= 0; --i)
    {
        tree[i].value = min(tree[2 * i + 1].value, tree[2 * i + 2].value);
        tree[i].leftBound = tree[2 * i + 1].leftBound;
        tree[i].rightBound = tree[2 * i + 2].rightBound;
    }
}

void push(int element) {
    if (tree[element].set)
    {
        tree[2 * element + 1].value = tree[element].value;
        tree[2 * element + 2].value = tree[element].value;
        tree[2 * element + 1].add = tree[element].add;
        tree[2 * element + 2].add = tree[element].add;
        tree[element].add = 0;
        tree[2 * element + 1].set = true;
        tree[2 * element + 2].set = true;
        tree[element].set = false;
    }
    if (tree[element].add != 0)
    {
        tree[2 * element + 1].add += tree[element].add;
        tree[2 * element + 2].add += tree[element].add;
        tree[2 * element + 1].value += tree[element].add;
        tree[2 * element + 2].value += tree[element].add;
        tree[element].add = 0;
    }
}

void add(int element, int l, int r, long long addValue)
{
    if (tree[element].rightBound < l || tree[element].leftBound > r)
    {
        return;
    }
    if (tree[element].rightBound <= r && tree[element].leftBound >= l)
    {
        tree[element].add += addValue;
        tree[element].value += addValue;
        return;
    }
    push(element);
    add(2 * element + 2, l, r, addValue);
    add(2 * element + 1, l, r, addValue);
    tree[element].value = min(tree[2 * element + 1].value, tree[2 * element + 2].value);
}

void set(int element, int l, int r, long long newValue)
{
    if (tree[element].rightBound < l || tree[element].leftBound > r)
    {
        return;
    }
    if (tree[element].rightBound <= r && tree[element].leftBound >= l)
    {
        tree[element].set = true;
        tree[element].value = newValue;
        tree[element].add = 0;
        return;
    }
    push(element);
    set(2 * element + 2, l, r, newValue);
    set(2 * element + 1, l, r, newValue);
    tree[element].value = min(tree[2 * element + 1].value, tree[2 * element + 2].value);
}

long long minlook(int element, int l, int r)
{
    if (tree[element].rightBound < l || tree[element].leftBound > r)
    {
        return LLONG_MAX;
    }
    if (tree[element].rightBound <= r && tree[element].leftBound >= l)
    {
        return tree[element].value;
    }
    push(element);
    return min(minlook(2 * element + 1, l , r), minlook(2 * element + 2, l , r));
}

/*void print(int n)
{
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        std::cout << "element: " << i << " value: " << tree[i].value << " left: " << tree[i].leftBound << " right: "
        << tree[i].rightBound << " set: " << tree[i].set << std::endl;
    }
}*/



int main()
{
    int n;
    std::cin >> n;
    int arrLen = arrLength(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    for (int i = n; i < arrLen; ++i)
    {
        a[i] = LLONG_MAX;
    }
    treeBuild(arrLen);
    std::string st;
    while (std::cin >> st)
    {
        if (st == "min")
        {
            int l, r;
            std::cin >> l >> r;
            std::cout << minlook(0, l, r) << "\n";
        }
        if (st == "set")
        {
            int l, r;
            long long x;
            std::cin >> l >> r >> x;
            set(0, l, r, x);
        }
        if (st == "add")
        {
            int l, r;
            long long x;
            std::cin >> l >> r >> x;
            add(0, l, r, x);
        }
        /*if (st == "print")
        {
            print(arrLen);
        }*/
    }
}