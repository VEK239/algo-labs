#include <iostream>

struct element
{
    element* leftElement = nullptr;
    element* rightElement = nullptr;
    long y;
    int treeSize = 1;
    long info;
};

class DekartTree
{
private:
    void updateSize(element* element)
    {
        element->treeSize = 1 + (element->leftElement == nullptr ? 0 : element->leftElement->treeSize) +
                            (element->rightElement == nullptr ? 0 : element->rightElement->treeSize);
    }

    element* merge(element* left, element* right)
    {
        if (left == nullptr)
        {
            return right;
        }
        if (right == nullptr)
        {
            return left;
        }
        if (left->y < right->y)
        {
            right->leftElement = merge(left, right->leftElement);
            updateSize(right);
            return right;
        }
        else
        {
            left->rightElement = merge(left->rightElement, right);
            updateSize(left);
            return left;
        }
    }

    std::pair<element*, element*> split(element* tree, long key)
    {
        if (tree == nullptr)
        {
            return std::make_pair(nullptr, nullptr);
        }
        int search = 1 + (tree->leftElement == nullptr ? 0 : tree->leftElement->treeSize);
        if (search > key)
        {
            std::pair<element*, element*> newLeftParts = split(tree->leftElement, key);
            tree->leftElement = newLeftParts.second;
            updateSize(tree);
            return std::make_pair(newLeftParts.first, tree);
        }
        else
        {
            std::pair<element*, element*> newRightParts = split(tree->rightElement, key - search);
            tree->rightElement = newRightParts.first;
            updateSize(tree);
            return std::make_pair(tree, newRightParts.second);
        }
    }

public:

    DekartTree() : root(nullptr)
    {
    }

    void insert(long info, int position)
    {
        auto* ins = new element;
        ins->y = rand();
        ins->info = info;
        std::pair<element*, element*> splitRes = split(this->root, position - 1);
        element* tree = merge(splitRes.first, ins);
        this->root = merge(tree, splitRes.second);

    }

    void print(element* currRoot)
    {
        if (currRoot == nullptr)
        {
            return;
        }
        print(currRoot->leftElement);
        std::cout << currRoot->info << " ";
        print(currRoot->rightElement);
    }

    void replace(int l, int r)
    {
        std::pair<element*, element*> rightResult = split(this->root, r);
        std::pair<element*, element*> midResult = split(rightResult.first, l - 1);
        element* tmp = merge(midResult.second, midResult.first);
        this->root = merge(tmp, rightResult.second);
    }

    element* root;
};

int main()
{
    DekartTree dekart;
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        dekart.insert(i, i);
    }
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        dekart.replace(l, r);
    }
    dekart.print(dekart.root);
}