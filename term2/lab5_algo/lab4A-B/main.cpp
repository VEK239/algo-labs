#include<iostream>
#include<string>
#include<set>
using namespace std;

struct element
{
    int value;
    element* left;
    element* right;
    int balance;
    int height;
};

class AvlBst
{
private:

    int getHeight(element* v)
    {
        return v == nullptr ? 0 : fixHeight(v);
    }

    int fixBalance(element* v)
    {
        v->balance = getHeight(v->right) - getHeight(v->left);
        return v->balance;
    }

    int fixHeight(element* v)
    {
        v->height = max(getHeight(v->right), getHeight(v->left)) + 1;
        return v->height;
    }

    element* rotateRight(element* v)
    {
        element* newIns = v->left;
        v->left = newIns->right;
        newIns->right = v;
        if (v == this->root)
        {
            this->root = newIns;
        }
        fixHeight(v);
        fixHeight(newIns);
        return newIns;
    }

    element* rotateLeft(element* v)
    {
        element* newIns = v->right;
        v->right = newIns->left;
        newIns->left = v;
        if (v == this->root)
        {
            this->root = newIns;
        }
        fixHeight(v);
        fixHeight(newIns);
        return newIns;
    }

    element* doBalance(element* v)
    {
        fixHeight(v);
        fixBalance(v);
        if (abs(v->balance) < 2)
        {
            return v;
        }
        if (v->balance == -2)
        {
            if (v->left->balance > 0)
            {
                v->left = rotateLeft(v->left);
            }
            return rotateRight(v);
        }
        else
        {
            if (v->right->balance < 0)
            {
                v->right = rotateRight(v->right);
            }
            return rotateLeft(v);
        }
    }

    element* searchMin(element* v)
    {
        return v->left == nullptr ? v : searchMin(v->left);
    }

public:

    element* root;

    AvlBst() : root(nullptr)
    {
    }

    element* insert(element* currRoot, int x)
    {
        if (currRoot == nullptr)
        {
            auto* ins = new element;
            ins->value = x;
            ins->left = nullptr;
            ins->right = nullptr;
            if (this->root == nullptr)
            {
                this->root = ins;
            }
            return ins;
        }
        if (currRoot->value < x)
        {
            currRoot->right = insert(currRoot->right, x);
        }
        else if (currRoot->value > x)
        {
            currRoot->left = insert(currRoot->left, x);
        }
        else
            return currRoot;
        return doBalance(currRoot);
    }

    element* exist(int x)
    {
        element* t = this->root;
        while (t != nullptr)
        {
            if (x == t->value)
            {
                return t;
            }
            if (x > t->value)
            {
                t = t->right;
            }
            else
            {
                t = t->left;
            }
        }
        return nullptr;
    }

    element* next(int x)
    {
        element* t = this->root;
        element* tmpParent = nullptr;
        while (t != nullptr)
        {
            if (t->value <= x)
            {
                t = t->right;
            }
            else
            {
                if (tmpParent == nullptr || tmpParent->value > t->value)
                {
                    tmpParent = t;
                }
                t = t->left;
            }
        }
        return tmpParent;
    }

    element* prev(int x)
    {
        element* t = this->root;
        element* tmpParent = nullptr;
        while (t != nullptr)
        {
            if (t->value < x)
            {
                if (tmpParent == nullptr || tmpParent->value < t->value)
                {
                    tmpParent = t;
                }
                t = t->right;
            }
            else
            {
                t = t->left;
            }
        }
        return tmpParent;
    }

    element* del(element* currRoot, int x)
    {
        if (currRoot == nullptr)
        {
            return currRoot;
        }
        else if (currRoot->value < x)
        {
            currRoot->right = del(currRoot->right, x);
        }
        else if (currRoot->value > x)
        {
            currRoot->left = del(currRoot->left, x);
        }
        else
        {
            element* currLeft = currRoot->left;
            element* currRight = currRoot->right;
            if (currLeft == nullptr && currRight == nullptr && this->root == currRoot)
            {
                this->root = nullptr;
                delete currRoot;
            }
            if (currRight == nullptr)
            {
                if (currRoot == this->root)
                {
                    this->root = currLeft;
                }
                currRoot = currLeft;
                return currRoot;
            }
            if (currLeft == nullptr)
            {
                if (currRoot == this->root)
                {
                    this->root = currRight;
                }
                currRoot = currRight;
                return currRoot;
            }
            element* currNext = searchMin(currRoot->right);
            currRoot->value = currNext->value;
            currRoot->right = del(currRoot->right, currNext->value);
        }
        return doBalance(currRoot);
    }
};

void test() {
    AvlBst a;
    set<int> m;
    int b;
    for (int i = 0; i < 1000000; i++) {
        b = i % 7;
        if (i == 17) {
            for (int j = 0; j < 100; j++) {
                a.insert(a.root, j + 100);
                a.del(a.root, j + 100);
            }
        }
        if (i % 5 == 0) {
            a.insert(a.root, b);
            m.insert(b);
        }
        if (i % 5 == 1) {
            bool find1 = a.exist(b);
            bool find2 = (m.find(b) != m.end());
            if (find1 != find2) {
                cout << b << " " << (i % 3) << endl;
            }
        }
        if (i % 5 == 2) {
            m.erase(b);
            a.del(a.root, b);
        }
        if (i % 5 == 3) {
            a.next(b);
        }
        if (i % 5 == 4) {
            a.prev(b);
        }
        //cout << b << " " << (i % 3) << " " << i << endl;
    }
}


int main()
{
    test();
//    string st;
//    AvlBst tree;
//    while (cin >> st)
//    {
//        int x;
//        cin >> x;
//        if (st == "insert")
//        {
//            tree.insert(tree.root, x);
//        }
//        if (st == "delete")
//        {
//            tree.del(tree.root, x);
//        }
//        if (st == "exists")
//        {
//            element* res = tree.exist(x);
//            if (res != nullptr)
//            {
//                cout << "true\n";
//            }
//            else
//            {
//                cout << "false\n";
//            }
//        }
//        if (st == "next")
//        {
//            element* res = tree.next(x);
//            if (res != nullptr)
//            {
//                cout << res->value << endl;
//            }
//            else
//            {
//                cout << "none\n";
//            }
//        }
//        if (st == "prev")
//        {
//            element* res = tree.prev(x);
//            if (res != nullptr)
//            {
//                cout << res->value << endl;
//            }
//            else
//            {
//                cout << "none\n";
//            }
//        }
//    }
//    return 0;
}
