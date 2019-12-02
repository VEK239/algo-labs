#include <iostream>

struct element
{
    element* leftElement = nullptr;
    element* rightElement = nullptr;
    long long x, y;
    long long treeSum;
};

class DekartTree
{
private:
    element* root;

    void updateSum(element* element)
    {
        element->treeSum = element->x + (element->leftElement == nullptr ? 0 : element->leftElement->treeSum) +
                           (element->rightElement == nullptr ? 0 : element->rightElement->treeSum);
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
            updateSum(right);
            return right;
        }
        else
        {
            left->rightElement = merge(left->rightElement, right);
            updateSum(left);
            return left;
        }
    }

    std::pair<element*, element*> split(element* tree, long long key)
    {
        if (tree == nullptr)
        {
            return std::make_pair(nullptr, nullptr);
        }
        if (tree->x > key)
        {
            std::pair<element*, element*> newLeftParts = split(tree->leftElement, key);
            tree->leftElement = newLeftParts.second;
            updateSum(tree);
            return std::make_pair(newLeftParts.first, tree);
        }
        else
        {
            std::pair<element*, element*> newRightParts = split(tree->rightElement, key);
            tree->rightElement = newRightParts.first;
            updateSum(tree);
            return std::make_pair(tree, newRightParts.second);
        }
    }

    long exists(element* root, long long key)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->x == key)
        {
            return true;
        }
        if (root->x < key)
        {
            return exists(root->rightElement, key);
        }
        else
        {
            return exists(root->leftElement, key);
        }
    }

public:

    DekartTree() : root(nullptr)
    {
    }

    void insert(long long key)
    {
        if (!exists(this->root, key))
        {
            auto* ins = new element;
            ins->x = key;
            ins->y = rand();
            ins->treeSum = key;
            std::pair<element*, element*> splitRes = split(this->root, key);
            element* tree = merge(splitRes.first, ins);
            this->root = merge(tree, splitRes.second);
        }
    }

    long long findSum(long a, long b)
    {
        long long result;
        std::pair<element*, element*> firstSplitRes = split(this->root, b);
        std::pair<element*, element*> secondSplitRes = split(firstSplitRes.first, a - 1);
        if (secondSplitRes.second != nullptr)
        {
            result = secondSplitRes.second->treeSum;
        }
        else
        {
            result = 0;
        }
        element* leftPart = merge(secondSplitRes.first, secondSplitRes.second);
        this->root = merge(leftPart, firstSplitRes.second);
        return result;
    }
};

int main()
{
    long long lastAdded = 0;
    DekartTree dekart;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char k;
        std::cin >> k;
        if (k == '+')
        {
            long long num;
            std::cin >> num;
            dekart.insert((num + lastAdded) % 1000000000);
            lastAdded = 0;
        }
        else if (k == '?')
        {
            int a, b;
            std::cin >> a >> b;
            long long result = dekart.findSum(a, b);
            std::cout << result << "\n";
            lastAdded = result;
        }
    }
}