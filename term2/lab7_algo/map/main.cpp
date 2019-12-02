#include <fstream>
//#include <iostream>
#include <vector>

using namespace std;

int get(vector<string>& keyLine, string key, vector<string>& valueLine)
{
    for (long i = 0; i < keyLine.size(); i++)
    {
        if (keyLine[i] == key)
        {
            return i;
        }
    }
    return 10000;
}


void put(string key, vector<string>& keyLine, string value, vector<string>& valueLine)
{
    int index = get(keyLine, key, valueLine);
    if (index == 10000)
    {
        keyLine.push_back(key);
        valueLine.push_back(value);
    }
    else
    {
        valueLine[index] = value;
    }
}

void deleteValue(string key, vector<string>& keyLine, vector<string>& valueLine)
{
    for (long i = 0; i < keyLine.size(); i++)
    {
        if (keyLine[i] == key)
        {
            valueLine.erase(valueLine.begin() + i);
            keyLine.erase(keyLine.begin() + i);
            break;
        }
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
    ifstream cin("map.in");
    ofstream cout("map.out");
    vector<vector<string>> valueTable(9883);
    vector<vector<string>> keyTable(9883);
    string st, key;
    while (cin >> st >> key)
    {
        int num = hashFunction(key);
        if (st == "put")
        {
            string value;
            cin >> value;
            put(key, keyTable[num], value, valueTable[num]);
        }
        else if (st == "delete")
        {
            deleteValue(key, keyTable[num], valueTable[num]);
        }
        else
        {
            int res = get(keyTable[num], key, valueTable[num]);
            if (res == 10000)
            {
                cout << "none\n";
            }
            else
            {
                cout << valueTable[num][res] << '\n';
            }
        }
    }
}
