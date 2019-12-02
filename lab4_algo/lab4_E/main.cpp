//#include <iostream>
#include <fstream>
std::ifstream fin("crypto.in");
std::ofstream fout("crypto.out");

int arrLength(int n)
{
    int y = 1;
    while (y < n)
    {
        y = y * 2;
    }
    return y;
}

struct mulres
{
    int value00;
    int value01;
    int value10;
    int value11;
};
struct node
{
    int leftBound;
    int rightBound;
    mulres value;
};

int r, n;
node tree[1000000];

mulres matrixmult(mulres a, mulres b)
{
    mulres result;
    result.value00 = (a.value00 * b.value00 + a.value01 * b.value10) % r;
    result.value01 = (a.value00 * b.value01 + a.value01 * b.value11) % r;
    result.value11 = (a.value10 * b.value01 + a.value11 * b.value11) % r;
    result.value10 = (a.value10 * b.value00 + a.value11 * b.value10) % r;
    return result;
}

mulres mul(int element, int l, int r)
{
    if (tree[element].rightBound < l || tree[element].leftBound > r)
    {
        mulres result;
        result.value00 = 1;
        result.value01 = 0;
        result.value10 = 0;
        result.value11 = 1;
        return result;
    }
    if (tree[element].rightBound <= r && tree[element].leftBound >= l)
    {
        return tree[element].value;
    }
    return matrixmult(mul(2 * element + 1, l , r), mul(2 * element + 2, l , r));
}

void treeBuild(int k)
{
    for (int i = 0; i < n; ++i)
    {
        tree[k - 1 + i].leftBound = i + 1;
        tree[k - 1 + i].rightBound = i + 1;
        fin >> tree[k - 1 + i].value.value00 >> tree[k - 1 + i].value.value01
        >> tree[k - 1 + i].value.value10 >> tree[k - 1 + i].value.value11;
    }
    for (int i = n; i < k; ++i)
    {
        tree[k - 1 + i].leftBound = i + 1;
        tree[k - 1 + i].rightBound = i + 1;
        tree[k - 1 + i].value.value00 = 1;
        tree[k - 1 + i].value.value01 = 0;
        tree[k - 1 + i].value.value10 = 0;
        tree[k - 1 + i].value.value11 = 1;
    }
    for (int i = k - 2; i >= 0; --i)
    {
        tree[i].leftBound = tree[2 * i + 1].leftBound;
        tree[i].rightBound = tree[2 * i + 2].rightBound;
        tree[i].value = matrixmult(tree[2 * i + 1].value, tree[2 * i + 2].value);
    }
}

int main()
{
    int m;
    fin >> r >> n >> m;
    treeBuild(arrLength(n));
    for (int i = 0; i < m; ++i)
    {
        int left, right;
        fin >> left >> right;
        mulres result = mul(0, left, right);
        fout << result.value00 << " " << result.value01 << "\n" << result.value10
        << " " << result.value11 << "\n" << "\n";
    }
    fin.close();
    fout.close();
}