#include <iostream>

struct element
{
    element* leftElement = nullptr;
    element* rightElement = nullptr;
    long x;
    long y;
};

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
        if (left->y < right->y)
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


    element* findMax(element* currRoot)
    {
        if (currRoot == nullptr)
            return nullptr;
        while (currRoot->rightElement != nullptr)
        {
            currRoot = currRoot->rightElement;
        }
        return currRoot;
    }

    element* findMin(element* currRoot)
    {
        if (currRoot == nullptr)
            return nullptr;
        while (currRoot->leftElement != nullptr)
        {
            currRoot = currRoot->leftElement;
        }
        return currRoot;
    }
public:

    DekartTree() : root(nullptr)
    {
    }

    bool exists(element* root, long long key)
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

    void insert(long key)
    {
        if (!exists(this->root, key))
        {
            auto* ins = new element;
            ins->x = key;
            ins->y = rand();
            std::pair<element*, element*> splitRes = split(this->root, key);
            element* tree = merge(splitRes.first, ins);
            this->root = merge(tree, splitRes.second);
        }
    }

    void del(long key)
    {
        std::pair<element*, element*> forRightPart, forLeftPart;
        forRightPart = split(this->root, key);
        forLeftPart = split(forRightPart.first, key - 1);
        this->root = merge(forLeftPart.first, forRightPart.second);
    }

    element* next(long key)
    {
        std::pair<element*, element*> partedRes = split(this->root, key);
        element* next = findMin(partedRes.second);
        this->root = merge(partedRes.first, partedRes.second);
        return next;
    }
    element* prev(long key)
    {
        std::pair<element*, element*> partedRes = split(this->root, key - 1);
        element* prev = findMax(partedRes.first);
        this->root = merge(partedRes.first, partedRes.second);
        return prev;
    }
    element* root;
};

int main()
{
    std::string st;
    DekartTree tree;
    while (std::cin >> st)
    {
        int x;
        std::cin >> x;
        if (st == "insert")
        {
            tree.insert(x);
        }
        if (st == "delete")
        {
            tree.del(x);
        }
        if (st == "exists")
        {
            bool res = tree.exists(tree.root, x);
            if (res)
            {
                std::cout << "true\n";
            }
            else
            {
                std::cout << "false\n";
            }
        }
        if (st == "next")
        {
            element* res = tree.next(x);
            if (res != nullptr)
            {
                std::cout << res->x << "\n";
            }
            else
            {
                std::cout << "none\n";
            }
        }
        if (st == "prev")
        {
            element* res = tree.prev(x);
            if (res != nullptr)
            {
                std::cout << res->x << "\n";
            }
            else
            {
                std::cout << "none\n";
            }
        }
    }
    return 0;
}
