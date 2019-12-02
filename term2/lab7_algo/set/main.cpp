#include <fstream>
//#include <iostream>
#include <vector>

using namespace std;

bool exists(vector<long>& line, long value)
{
    for (long el : line)
    {
        if (el == value)
        {
            return true;
        }
    }
    return false;
}

void insertValue(vector<long>& line, long value)
{
    if (!exists(line, value))
    {
        line.push_back(value);
    }
}

void deleteValue(vector<long>& line, long value)
{
    for (long i = 0; i < line.size(); i++)
    {
        if (line[i] == value)
        {
            line.erase(line.begin() + i);
            break;
        }
    }
}

int hashFunction(long key)
{
    return (key >= 0 ? key : -key) % 9883;
}


int main()
{
    vector<vector<long>> hashTable(9883);
    string st;
    long x;
    ifstream cin("set.in");
    ofstream cout("set.out");
    while (cin >> st >> x)
    {
        int num = hashFunction(x);
        if (st == "insert")
        {
            insertValue(hashTable[num], x);
        }
        else if (st == "delete")
        {
            deleteValue(hashTable[num], x);
        }
        else
        {
            cout << (exists(hashTable[num], x) ? "true\n" : "false\n");
        }
    }
}
