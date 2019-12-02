#include <fstream>
struct node
{
    bool set = false;
    int leftBound;
    int rightBound;
    long long value = LONG_MIN;
};

long long a[200000];
node tree[600000];
long long requests[100000][3];
int n, arrLen;

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
        tree[n - 1 + i].leftBound = i + 1;
        tree[n - 1 + i].rightBound = i + 1;
    }
    for (int i = n - 2; i >= 0; --i)
    {
        tree[i].leftBound = tree[2 * i + 1].leftBound;
        tree[i].rightBound = tree[2 * i + 2].rightBound;
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

void set(int element, long long l, long long r, long long newValue)
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
}

long long minlook(int element, long long l, long long r)
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

int main()
{
    std::ifstream cin("rmq.in");
    std::ofstream cout("rmq.out");
    long m;
    cin >> n >> m;
    arrLen = arrLength(n);
    treeBuild(arrLen);
    std::string st;
    for (int i = 0; i < m; ++i)
    {
        cin >> requests[i][0] >> requests[i][1] >> requests[i][2];
        set(0, requests[i][0], requests[i][1], requests[i][2]);
    }
    for (int i = 0; i < arrLen; ++i)
    {
        if (tree[i].set)
        {
            push(i);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (minlook(0, requests[i][0], requests[i][1]) != requests[i][2])
        {
            cout << "inconsistent\n";
            return 0;
        }
    }
    cout << "consistent\n";
    for (int i = 0; i < n; ++i)
    {
        cout << tree[arrLen - 1 + i].value << " ";
    }
}