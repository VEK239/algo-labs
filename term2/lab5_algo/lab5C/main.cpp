#include <iostream>
#include <vector>
#include <algorithm>

struct element
{
    element* parent = nullptr;
    element* leftElement = nullptr;
    element* rightElement = nullptr;
    long x, y;
    int number;
};
element** printingArray = new element* [300001];
std::vector <element*> sortingArray(300001);

class DekartTree
{
private:
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
        if (left->y >= right->y)
        {
            right->leftElement = merge(left, right->leftElement);
            return right;
        }
        else
        {
            left->rightElement = merge(left->rightElement, right);
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
            return std::make_pair(newLeftParts.first, tree);
        }
        else
        {
            std::pair<element*, element*> newRightParts = split(tree->rightElement, key);
            tree->rightElement = newRightParts.first;
            return std::make_pair(tree, newRightParts.second);
        }
    }

public:
    DekartTree()
    {
    }

    element* lastInserted;

    void create(long key, long priority, int i)
    {
        auto* ins = new element;
        ins->x = key;
        ins->number = i + 1;
        ins->y = priority;
        printingArray[i] = ins;
    }

    element* insert(element* ins)
    {
        if (lastInserted->y < ins->y) ///min heap??
        {
            ins->parent = lastInserted;
            lastInserted->rightElement = ins;
        }
        else
        {
            element* currLast = lastInserted;
            while (currLast->parent != nullptr && currLast->y > ins->y) /// min
            {
                currLast = currLast->parent;
            }
            if (currLast->y > ins->y)
            {
                currLast->parent = ins;
                ins->leftElement = currLast;
            }
            else
            {
                ins->parent = currLast;
                ins->leftElement = currLast->rightElement;
                ins->leftElement->parent = ins;
                currLast->rightElement = ins;
            }
        }
        lastInserted = ins;
        return ins;
    }
};

int comp (element* a, element* b) {
    return a->x < b->x;
}

int main()
{
    int n;
    std::cin >> n;
    sortingArray.resize(n);
    for (int i = 0; i < n; ++i)
    {
        long key, priority;
        std::cin >>  key >> priority;
        auto* root = new element;
        root->x = key;
        root->y = priority;
        root->number = i + 1;
        sortingArray[i] = root;
        printingArray[i] = root;
    }

    std::sort(sortingArray.begin(), sortingArray.end(), comp);
    DekartTree dekart;
    dekart.lastInserted = sortingArray[0];

    for (int i = 1; i < n; ++i)
    {
        dekart.insert(sortingArray[i]);
    }

    std::cout << "YES\n";

    for (int i = 0; i < n; ++i)
    {
        std::cout << (printingArray[i]->parent != nullptr ? printingArray[i]->parent->number : 0) << " ";
        std::cout << (printingArray[i]->leftElement != nullptr ? printingArray[i]->leftElement->number : 0) << " ";
        std::cout << (printingArray[i]->rightElement != nullptr ? printingArray[i]->rightElement->number : 0) << "\n";
    }
}