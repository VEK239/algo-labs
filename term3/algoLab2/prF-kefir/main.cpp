#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(int n, const vector<vector<pair<int, long long>>> &vertexes, vector<long long>& distance, int startVertex) {
    distance[startVertex] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> priorityQueue;
    for (int i = 0; i < n; i++) {
        priorityQueue.push({distance[i], i});
    }

    while (!priorityQueue.empty()) {
        pair<long long, int> v = priorityQueue.top();
        priorityQueue.pop();

        if (v.first > distance[v.second]) { continue; }

        for (int j = 0; j < vertexes[v.second].size(); ++j) {
            pair<int, long long> to = vertexes[v.second][j];
            if (distance[to.first] > v.first + to.second) {
                distance[to.first] = v.first + to.second;
                priorityQueue.push({distance[to.first], to.first});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> vertexes(n);
    vector<long long> distanceFromOne(n, 1e18);
    vector<long long> distanceFromTwo(n, 1e18);
    vector<long long> distanceFromThree(n, 1e18);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        vertexes[--u].emplace_back(make_pair(--v, w));
        vertexes[v].emplace_back(make_pair(u, w));
    }

    vector<int> houses(3);
    for (int j = 0; j < 3; ++j) {
        cin >> houses[j];
        --houses[j];
    }

    dijkstra(n, vertexes, distanceFromOne, houses[0]);
    dijkstra(n, vertexes, distanceFromTwo, houses[1]);
    dijkstra(n, vertexes, distanceFromThree, houses[2]);

    long long sum = min(min(distanceFromOne[houses[2]] + distanceFromTwo[houses[2]],
            distanceFromThree[houses[0]] + distanceFromTwo[houses[0]]),
                        distanceFromOne[houses[1]] + distanceFromThree[houses[1]]);
    cout << (sum < (long long) 1e18 ? sum : -1);
}