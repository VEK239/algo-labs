#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fordBellman(int n, int k, int start, vector<vector<pair<long long, int>>> &matrix, vector<vector<long long>> &distance) {
    for (int i = 1; i < k + 1; ++i) {
        for (int from = 0; from < n; ++from) {
            for (auto edge: matrix[from]) {
                distance[i][edge.second] = min(distance[i][edge.second], distance[i - 1][from] + edge.first);
            }
        }
    }
}


int main() {
    int n, m, k, start;
    std::cin >> n >> m >> k >> start;
    vector<vector<pair<long long, int>>> vertexes(n);
    for (int i = 0; i < m; ++i) {
        long long el;
        int from, to;
        std::cin >> from >> to >> el;
        vertexes[--from].emplace_back(make_pair(el, --to));
    }
    vector<vector<long long>> distance(k + 1);
    for (int j = 0; j < k + 1; ++j) {
        distance[j].resize(n, 1e12);
    }
    distance[0][--start] = 0;

    fordBellman(n, k, start, vertexes, distance);
    for (auto el: distance[k]) {
        if (el > 1e9) {
            cout << "-1\n";
        } else {
            cout << el << '\n';
        }
    }
}
