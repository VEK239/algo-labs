#include <iostream>

struct node
{
    int leftBound;
    int rightBound;
    bool leftB = false;
    bool rightB = false;
    int bCount = 0;
    int bSum = 0;
};

node tree[1048576 * 2];

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
    if (tree[element].bCount == 1 && tree[element].leftB && tree[element].rightB)
    {
        tree[2 * element + 1].bCount = 1;
        tree[2 * element + 2].bCount = 1;
        tree[2 * element + 1].bSum = tree[2 * element + 1].rightBound - tree[2 * element + 1].leftBound + 1;
        tree[2 * element + 2].bSum = tree[2 * element + 2].rightBound - tree[2 * element + 2].leftBound + 1;
        tree[2 * element + 1].leftB = true;
        tree[2 * element + 2].leftB = true;
        tree[2 * element + 1].rightB = true;
        tree[2 * element + 2].rightB = true;
    }
    else if (tree[element].bCount == 0)
    {
        tree[2 * element + 1].bCount = 0;
        tree[2 * element + 1].bSum = 0;
        tree[2 * element + 1].rightB = false;
        tree[2 * element + 1].leftB = false;
        tree[2 * element + 2].bCount = 0;
        tree[2 * element + 2].bSum = 0;
        tree[2 * element + 2].rightB = false;
        tree[2 * element + 2].leftB = false;
    }
}
void set(int element, int value, int l, int r)
{
    if (tree[element].rightBound < l || tree[element].leftBound > r)
    {
        return;
    }
    if (tree[element].rightBound <= r && tree[element].leftBound >= l)
    {
        tree[element].bCount = value;
        tree[element].rightB = bool(value);
        tree[element].leftB = bool(value);
        tree[element].bSum = value * (tree[element].rightBound - tree[element].leftBound + 1);
        return;
    }
    push(element);
    set(2 * element + 2, value, l, r);
    set(2 * element + 1, value, l, r);
    tree[element].leftB = tree[2 * element + 1].leftB;
    tree[element].rightB = tree[2 * element + 2].rightB;
    tree[element].bSum = tree[2 * element + 1].bSum + tree[2 * element + 2].bSum;
    tree[element].bCount = tree[2 * element + 1].bCount + tree[2 * element + 2].bCount;
    if (tree[2 * element + 1].rightB && tree[2 * element + 2].leftB)
    {
        tree[element].bCount--;
    }
}

int main()
{
    int n;
    std::cin >> n;
    treeBuild(524288 * 2); //524288
    std::string st;
    for (int i = 0; i < n; ++i)
    {
        int l, x;
        std::cin >> st;
        if (st == "W")
        {
            std::cin >> l >> x;
            set(0, 0, l + 524288, l + x + 524287);
        }
        else
        {
            std::cin >> l >> x;
            set(0, 1, l + 524288, l + x + 524287);
        }
        std::cout << tree[0].bCount << " " << tree[0].bSum << std::endl;
    }
}