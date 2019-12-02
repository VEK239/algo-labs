#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Element
{
    string value;
    string key;

    Element(string k, string v, Element* p = nullptr, Element* n = nullptr) : key(std::move(k)), value(std::move(v))
    {
    }
};

vector<vector<vector<Element*>>> hashTable(1331);

vector<string> get(string key, int num)
{
    vector<string> result;
    vector<vector<Element*>> table = hashTable[num];
    for (auto line : table)
    {
        for (auto el: line)
        {
            if (el->key == key)
            {
                result.push_back(el->value);
            }
        }
    }
    return result;
}

int get(string key, string value, int keyHash, int valHash)
{
    vector<Element*> line = hashTable[keyHash][valHash];
    for (int j = 0; j < line.size(); j++)
    {
        if (line[j]->key == key && line[j]->value == value)
        {
            return j;
        }
    }
    return 10000;
}

void put(string key, string value, int keyHash, int valHash)
{
    if (get(key, value, keyHash, valHash) == 10000)
    {
        auto* el = new Element(key, value);
        hashTable[keyHash][valHash].push_back(el);
    }
}

void deleteValue(string key, string value, int keyHash, int valHash)
{
    int index = get(key, value, keyHash, valHash);
    if (index != 10000)
    {
        hashTable[keyHash][valHash].erase(hashTable[keyHash][valHash].begin() + index);
    }
}

void deleteTable(string key, int keyHash)
{
    for (auto& line : hashTable[keyHash])
    {
        vector<Element*> newLine;
        for (auto& el : line)
        {
            if (el->key != key)
            {
                newLine.push_back(el);
            }
        }
        line = newLine;
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
    return hash % 1331;
}


int main()
{
    for (int i = 0; i < 1331; ++i)
    {
        hashTable[i].resize(1331);
    }
    ifstream fin("multimap.in");
    ofstream fout("multimap.out");
    string st, key;
    while (fin >> st >> key)
    {
        int keyHash = hashFunction(key);
        if (st == "put")
        {
            string value;
            fin >> value;
            put(key, value, keyHash, hashFunction(value));
        }
        else if (st == "delete")
        {
            string value;
            fin >> value;
            deleteValue(key, value, keyHash, hashFunction(value));
        }
        else if (st == "get")
        {
            vector<string> res = get(key, keyHash);
            fout << res.size() << " ";
            for (const auto& i : res)
            {
                fout << i << " ";
            }
            fout << '\n';
        }
        else
        {
            deleteTable(key, keyHash);
        }
    }
}
