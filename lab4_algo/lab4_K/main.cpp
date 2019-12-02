#include <fstream>
#include <iostream>
using namespace std;
int n, arrLen;

struct node
{
    int rightOne = 0;
    int leftBound;
    int rightBound;
};

int arrLength(int n)
{
    int y = 1;
    while (y < n)
    {
        y = y * 2;
    }
    return y;
}

node tree[600000];
int place;

void min(int element, int left)
{
    if (tree[element].leftBound == tree[element].rightBound)
    {
        place = element;
    }
    else
    {
        if (tree[2 * element + 1].rightOne != 0 && tree[2 * element + 1].rightOne >= left && place == 0)
        {
            min(2 * element + 1, left);
        }
        else
        {
            min(2 * element + 2, left);
        }
    }
}

void treeBuild()
{
    for (int i = 0; i < n; ++i)
    {
        tree[arrLen - 1 + i].rightOne = i + 1;
        tree[arrLen - 1 + i].leftBound = i + 1;
        tree[arrLen - 1 + i].rightBound = i + 1;
    }
    for (int i = n; i < arrLen; ++i)
    {
        tree[arrLen - 1 + i].leftBound = i + 1;
        tree[arrLen - 1 + i].rightBound = i + 1;
    }
    for (int i = arrLen - 2; i >= 0; --i)
    {
        tree[i].leftBound = tree[2 * i + 1].leftBound;
        tree[i].rightOne = tree[2 * i + 1].rightOne > tree[2 * i + 2].rightOne ? tree[2 * i + 1].rightOne : tree[2 * i + 2].rightOne;
        tree[i].rightBound = tree[2 * i + 2].rightBound;
    }
}

int set(int element, int value, int number)
{
    if (value == 1 || (value == 0 && tree[element].rightOne == 1))
    {
        tree[element].rightOne = value == 1 ? number : 0;
    }
    else
    {
        place = 0;
        min(0, number);
        if (tree[place].rightOne == 0)
        {
            place = 0;
            min(0, 1);
        }
        tree[place].rightOne = 0;
        element = place;
    }
    int result = element;
    while (element > 0)
    {
        element = (element - 1) / 2;
        tree[element].rightOne = tree[2 * element + 1].rightOne > tree[2 * element + 2].rightOne ?
                tree[2 * element + 1].rightOne : tree[2 * element + 2].rightOne;
    }
    return result;
}

int main()
{
    ifstream fin("parking.in");
    ofstream fout("parking.out");
    int m;
    fin >> n >> m;
    arrLen = arrLength(n);
    treeBuild();
    string st;
    for (int i = 0; i < m; ++i)
    {
        int x;
        fin >> st;
        if (st == "enter")
        {
            fin >> x;
            fout << set(arrLen - 2 + x, 0, x) - arrLen + 2 << "\n";
        }
        else if (st == "exit")
        {
            fin >> x;
            set(arrLen - 2 + x, 1, x);
        }
    }
}