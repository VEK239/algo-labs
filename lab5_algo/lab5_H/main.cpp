#include <iostream>
#include <vector>
#include <set>
long binary[26];

struct element
{
    long letters = 0;
    element* leftElement = nullptr;
    element* rightElement = nullptr;
    long y;
    int treeSize;
    short info;
    int infoCount;

    element(short info, int infoCount)
    {
        y = rand();
        treeSize = infoCount;
        this->infoCount = infoCount;
        this->info = info;
        letters = binary[info];
    }
};

class DekartTree
{
private:
    void updateSize(element* element)
    {
        if (element == nullptr)
        {
            return;
        }
        element->letters = binary[element->info];
        element->treeSize = element->infoCount;
        if (element->leftElement)
        {
            element->letters = element->letters | element->leftElement->letters;
            element->treeSize += element->leftElement->treeSize;
        }
        if (element->rightElement)
        {
            element->treeSize += element->rightElement->treeSize;
            element->letters = element->letters | element->rightElement->letters;
        }
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
        int search = tree->leftElement == nullptr ? 0 : tree->leftElement->treeSize;
        if (search >= key)
        {
            std::pair<element*, element*> newLeftParts = split(tree->leftElement, key);
            tree->leftElement = newLeftParts.second;
            updateSize(tree);
            return std::make_pair(newLeftParts.first, tree);
        }
        else if (search + tree->infoCount > key)
        {
            auto* insLeft = new element(tree->info, key - search);
            auto* insRight = new element(tree->info, tree->infoCount - key + search);
            insLeft = merge(tree->leftElement, insLeft);
            insRight = merge(insRight, tree->rightElement);
            return std::make_pair(insLeft, insRight);
        }
        else
        {
            std::pair<element*, element*> newRightParts = split(tree->rightElement, key - search - tree->infoCount);
            tree->rightElement = newRightParts.first;
            updateSize(tree);
            return std::make_pair(tree, newRightParts.second);
        }
    }

public:

    DekartTree() : root(nullptr)
    {
    }

    void del(int leftIndex, int rightIndex)
    {
        std::pair<element*, element*> forRightPart, forLeftPart;
        forRightPart = split(this->root, rightIndex);
        forLeftPart = split(forRightPart.first, leftIndex - 1);
        this->root = merge(forLeftPart.first, forRightPart.second);
    }

    void insert(short info, int infoCount, int position)
    {
        auto* ins = new element(info, infoCount);
        std::pair<element*, element*> newParts = split(this->root, position - 1);
        element* tmp = merge(newParts.first, ins);
        this->root = merge(tmp, newParts.second);
    }

    short query(int leftIndex, int rightIndex)
    {
        std::pair<element*, element*> forRightPart, forLeftPart;
        forRightPart = split(this->root, rightIndex);
        forLeftPart = split(forRightPart.first, leftIndex - 1);
        short result = 0;
        for (long long num = forLeftPart.second->letters; num; num >>= 1)
        {
            if (num & 1)
            {
                ++result;
            }
        }
        element* tmp = merge(forLeftPart.first, forLeftPart.second);
        this->root = merge(tmp, forRightPart.second);
        return result;
    }

    element* root;
};

int main()
{
    DekartTree dekart;
    int n, m;
    binary[0] = 1;
    for (int i = 1; i < 26; ++i)
    {
        binary[i] = binary[i - 1] << 1;
    }
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char mode;
        std::cin >> mode;
        if (mode == '+')
        {
            int index, number;
            char letter;
            std::cin >> index >> number >> letter;
            dekart.insert(short(letter) - 97, number, index);
        }
        else if (mode == '-')
        {
            int index, number;
            std::cin >> index >> number;
            dekart.del(index, index + number - 1);
        }
        else
        {
            int leftIndex, rightIndex;
            std::cin >> leftIndex >> rightIndex;
            std::cout << dekart.query(leftIndex, rightIndex) << "\n";
        }
    }
}