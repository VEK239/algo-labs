struct element
{
    element* leftElement = nullptr;
    element* rightElement = nullptr;
    long x, y;
    int treeSize = 1;
};

#include <iostream>

class DekartTree
{
private:
    element* root;

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
        if (tree->x > key)
        {
            std::pair<element*, element*> newLeftParts = split(tree->leftElement, key);
            tree->leftElement = newLeftParts.second;
            updateSize(tree);
            return std::make_pair(newLeftParts.first, tree);
        }
        else
        {
            std::pair<element*, element*> newRightParts = split(tree->rightElement, key);
            tree->rightElement = newRightParts.first;
            updateSize(tree);
            return std::make_pair(tree, newRightParts.second);
        }
    }

    long findElement(element* currRoot, int number)
    {
        int currNumber = (currRoot->leftElement == nullptr ? 0 : currRoot->leftElement->treeSize) + 1;
        if (currNumber < number)
        {
            return findElement(currRoot->rightElement, number - currNumber);
        }
        else if (currNumber > number)
        {
            return findElement(currRoot->leftElement, number);
        }
        else
        {
            return currRoot->x;
        }
    }
public:

    DekartTree() : root(nullptr)
    {
    }

    void insert(long key)
    {
        auto* ins = new element;
        ins->x = key;
        ins->y = rand();
        std::pair<element*, element*> splitRes = split(this->root, key);
        element* tree = merge(splitRes.first, ins);
        this->root = merge(tree, splitRes.second);
    }

    void del(long key)
    {
        std::pair<element*, element*> forRightPart, forLeftPart;
        forRightPart = split(this->root, key);
        forLeftPart = split(forRightPart.first, key - 1);
        this->root = merge(forLeftPart.first, forRightPart.second);
    }

    long findKMax(int number)
    {
        return findElement(this->root, this->root->treeSize - number + 1);
    }
};

int main()
{
    DekartTree dekart;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        long k, num;
        std::cin >> k >> num;
        if (k == 1)
        {
            dekart.insert(num);
        }
        else if (k == -1)
        {
            dekart.del(num);
        }
        else if (k == 0)
        {
            std::cout << dekart.findKMax(num) << "\n";
        }
    }
}