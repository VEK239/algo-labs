#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vertex {
    vector<pair<long long, int>> edgesFrom;
    bool canReach = false;
    bool fromCycle = false;
    long long distance = static_cast<long long int>(1e18);
};

void dfs(vector<Vertex> &vertexes, int curV) {
    vertexes[curV].fromCycle = true;
    for (auto edge: vertexes[curV].edgesFrom) {
        if (!vertexes[edge.second].fromCycle) {
            dfs(vertexes, edge.second);
        }
    }
}
void dfsReach(vector<Vertex> &vertexes, int curV) {
    vertexes[curV].canReach = true;
    for (auto edge: vertexes[curV].edgesFrom) {
        if (!vertexes[edge.second].canReach) {
            dfsReach(vertexes, edge.second);
        }
    }
}

void findFromCycle(int n, vector<Vertex> &vertexes) {
    for (int from = 0; from < n; ++from) {
        if (!vertexes[from].canReach) {
            continue;
        }
        for (auto edge: vertexes[from].edgesFrom) {
            if (vertexes[edge.second].distance > vertexes[from].distance + edge.first) {
                dfs(vertexes, from);
                break;
            }
        }
    }
}


void fordBellman(int n, vector<Vertex> &vertexes) {
    for (int i = 0; i < n - 1; ++i) {
        for (int from = 0; from < n; ++from) {
            if (vertexes[from].distance == (long long)1e18) {
                continue;
            }
            for (auto edge: vertexes[from].edgesFrom) {
                if (vertexes[edge.second].distance > vertexes[from].distance + edge.first) {
                    vertexes[edge.second].distance = vertexes[from].distance + edge.first;
                }
            }
        }
    }
    findFromCycle(n, vertexes);
}


int main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    vector<Vertex> vertexes(n);
    for (int i = 0; i < m; ++i) {
        long long el;
        int from, to;
        std::cin >> from >> to >> el;
        vertexes[from - 1].edgesFrom.emplace_back(make_pair(el, to - 1));
    }
    vertexes[s - 1].distance = 0;
    dfsReach(vertexes, s - 1);

    fordBellman(n, vertexes);

    for (int k = 0; k < n; ++k) {
        if (!vertexes[k].canReach) {
            cout << "*\n";
        } else if (vertexes[k].fromCycle) {
            cout << "-\n";
        } else {
            cout << vertexes[k].distance << '\n';
        }
    }
}
