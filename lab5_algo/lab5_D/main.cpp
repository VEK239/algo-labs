#include <iostream>
#include <vector>

struct element
{
    element* leftElement = nullptr;
    element* rightElement = nullptr;
    long y;
    int treeSize = 1;
    long info;
    int leftZero = 0;
};

class DekartTree
{
private:
    std::vector<long> printingArr;

    void updateSize(element* element)
    {
        if (element == nullptr)
        {
            return;
        }
        int leftLeftZero = (element->leftElement ? element->leftElement->leftZero : 0);
        int rightLeftZero = (element->rightElement ? element->rightElement->leftZero : 0);
        if (leftLeftZero != 0)
        {
            element->leftZero = leftLeftZero;
        }
        else if (element->info == 0)
        {
            element->leftZero = (element->leftElement ? element->leftElement->treeSize : 0) + 1;
        }
        else if (rightLeftZero != 0)
        {
            element->leftZero = (element->leftElement ? element->leftElement->treeSize : 0) + 1 + rightLeftZero;
        }
        else
        {
            element->leftZero = 0;
        }
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
        int search = tree->leftElement == nullptr ? 0 : tree->leftElement->treeSize;
        if (search >= key)
        {
            std::pair<element*, element*> newLeftParts = split(tree->leftElement, key);
            tree->leftElement = newLeftParts.second;
            updateSize(tree);
            return std::make_pair(newLeftParts.first, tree);
        }
        else
        {
            std::pair<element*, element*> newRightParts = split(tree->rightElement, key - search - 1);
            tree->rightElement = newRightParts.first;
            updateSize(tree);
            return std::make_pair(tree, newRightParts.second);
        }
    }

public:

    DekartTree() : root(nullptr)
    {
    }

    void del(long key)
    {
        std::pair<element*, element*> forRightPart, forLeftPart;
        forRightPart = split(this->root, key);
        forLeftPart = split(forRightPart.first, key - 1);
        delete(forLeftPart.second);
        this->root = merge(forLeftPart.first, forRightPart.second);
    }

    void insert(long info, int position)
    {
        auto* ins = new element;
        ins->y = rand();
        ins->info = info;
        std::pair<element*, element*> newParts = split(this->root, position - 1);
        int number = newParts.second->leftZero;
        this->root = newParts.second;
        if (number != 0)
        {
            del(number);
        }
        element* tmp = merge(newParts.first, ins);
        this->root = merge(tmp, this->root);
    }

    void insertZeros(int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            auto* ins = new element;
            ins->y = rand();
            ins->info = 0;
            ins->leftZero = i;
            this->root = merge(this->root, ins);
        }
    }

    int vectorSize = 0;
    int zerosCount = 0;

    void countArraySize(element* currRoot)
    {
        if (currRoot == nullptr)
        {
            return;
        }
        countArraySize(currRoot->leftElement);
        if (currRoot->info != 0)
        {
            vectorSize += zerosCount + 1;
            zerosCount = 0;
        }
        else
        {
            zerosCount++;
        }
        printingArr.push_back(currRoot->info);
        countArraySize(currRoot->rightElement);
    }

    void printRes()
    {
        std::cout << vectorSize << "\n";
        for (int i = 0; i < vectorSize; ++i)
        {
            std::cout << printingArr[i] << " ";
        }
    }

    element* root;
};

int main()
{
    DekartTree dekart;
    int n, m;
    std::cin >> n >> m;
    dekart.insertZeros(m + 1);
    for (int i = 1; i <= n; ++i)
    {
        int key;
        std::cin >> key;
        dekart.insert(i, key);
    }
    dekart.countArraySize(dekart.root);
    dekart.printRes();
}