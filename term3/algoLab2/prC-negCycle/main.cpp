#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findCycle(int n, vector<int> &parent, vector<vector<pair<long long, int>>> &matrix, vector<long long> &distance) {
    int cycleStart = -1;
    for (int from = 0; from < n; ++from) {
        for (auto edge: matrix[from]) {
            if (distance[edge.second] > distance[from] + edge.first) {
                cycleStart = from;
                break;
            }
        }
        if (cycleStart != -1) {
            break;
        }
    }
    vector<int> negCycle;
    if (cycleStart != -1) {
        for (int i = 0; i < n && parent[cycleStart] != -1; ++i) {
            cycleStart = parent[cycleStart];
        }
        for (int curVer = cycleStart; (curVer != cycleStart && curVer != -1) || negCycle.empty(); curVer = parent[curVer]) {
            negCycle.emplace_back(curVer);
        }
        reverse(negCycle.begin(), negCycle.end());
    }
    return negCycle;
}


vector<int> fordBellman(int n, vector<vector<pair<long long, int>>> &matrix, vector<long long> &distance, vector<int> &parent) {
    for (int i = 0; i < n - 1; ++i) {
        for (int from = 0; from < n; ++from) {
            for (auto edge: matrix[from]) {
                if (distance[edge.second] > distance[from] + edge.first) {
                    distance[edge.second] = max((long long) -10e18, distance[from] + edge.first);
                    parent[edge.second] = from;
                }
            }
        }
    }
    return findCycle(n, parent, matrix, distance);
}


int main() {
    int n, edgeCount = 0;
    std::cin >> n;
    vector<vector<pair<long long, int>>> vertexes(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long el;
            std::cin >> el;
            if (el != 100000) {
                vertexes[i].emplace_back(make_pair(el, j));
            }
        }
    }

    vector<long long> distance(n, 1e18);
    vector<int> parent(n, -1);
    vector<int> negCycle = fordBellman(n, vertexes, distance, parent);
    if (negCycle.empty()) {
        cout << "NO";
        return 0;
    } else {
        cout << "YES\n" << negCycle.size() << '\n';
        for (auto ver: negCycle) {
            cout << ver + 1 << ' ';
        }
    }
}