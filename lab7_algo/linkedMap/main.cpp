#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Element
{
    string value;
    string key;
    Element* next = nullptr;
    Element* prev = nullptr;

    Element(string k, string v, Element* p = nullptr, Element* n = nullptr) : key(std::move(k)), value(std::move(v)),
                                                                              prev(p), next(n) {}
};

vector<vector<Element*>> hashTable(9883);
Element* lastPut = nullptr;

int get(string key, int num)
{
    vector<Element*> line = hashTable[num];
    for (long i = 0; i < line.size(); i++)
    {
        if (line[i]->key == key)
        {
            return i;
        }
    }
    return 10000;
}


string next(string key, int num) ///?
{
    vector<Element*> line = hashTable[num];
    for (auto& i : line)
    {
        if (i->key == key)
        {
            return (i->next ? i->next->value : "none");
        }
    }
    return "none";
}

string prev(string key, int num) ///?
{
    vector<Element*> line = hashTable[num];
    for (auto& i : line)
    {
        if (i->key == key)
        {
            return (i->prev ? i->prev->value : "none");
        }
    }
    return "none";
}

void put(string key, string value, int num)
{
    int index = get(key, num);
    if (index == 10000)
    {
        Element* el = new Element(key, value, lastPut);
        if (lastPut)
        {
            lastPut->next = el;
        }
        hashTable[num].push_back(el);
        lastPut = el;
    }
    else
    {
        hashTable[num][index]->value = value;
//        lastPut = hashTable[num][index];
    }
}

void deleteValue(string key, int num)
{
    int index = get(key, num);
    if (index != 10000)
    {
        if (hashTable[num][index]->prev)
        {
            hashTable[num][index]->prev->next = hashTable[num][index]->next;
        }
        if (hashTable[num][index]->next)
        {
            hashTable[num][index]->next->prev = hashTable[num][index]->prev;
        }
        if (lastPut == hashTable[num][index])
        {
            lastPut = hashTable[num][index]->prev;
        }
        hashTable[num].erase(hashTable[num].begin() + index);
    }
}

int hashFunction(string key)
{
    int seed = 131;
    unsigned long hash = 0;
    for (char c : key)
    {
        hash = hash * seed + c;
    }
    return hash % 9883;
}


int main()
{
    ifstream fin("multimap.in");
    ofstream fout("miltimap.out");
    string st, key;
    while (fin >> st >> key)
    {
        int num = hashFunction(key);
        if (st == "put")
        {
            string value;
            fin >> value;
            put(key, value, num);
        }
        else if (st == "delete")
        {
            deleteValue(key, num);
        }
        else if (st == "get")
        {
            int res = get(key, num);
            if (res == 10000)
            {
                fout << "none\n";
            }
            else
            {
                fout << hashTable[num][res]->value << '\n';
            }
        }
        else if (st == "prev")
        {
            deleteTable(key, num);
        }
    }
}
