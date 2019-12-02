#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Vertex {
    bool used = false;
    vector<int> edges;
    bool isFirstWinning = false;
};

bool gameDfs(vector<Vertex>& vertexes, int vertexNum) {
    int counter = 0;
    vertexes[vertexNum].used = true;
    for (int i = 0; i < vertexes[vertexNum].edges.size(); ++i) {
        if (!vertexes[vertexNum].used) {
            counter += gameDfs(vertexes, vertexes[vertexNum].edges[i]);
        }
    }
    if ((vertexes[vertexNum].edges.size() % 2 == 0 && counter != 0 && counter % 2 == 0) ||
            (vertexes[vertexNum].edges.size() % 2 != 0 && (counter == 0 || counter % 2 ==1))) {
        vertexes[vertexNum].isFirstWinning = true;
        return true;
    }
    return false;
}

int main() {
//    ifstream cin("game.in");
//    ofstream cout("game.out");
    int n, m, start;
    cin >> n >> start;
    vector<Vertex> vertexes(n);
    for (int i = 0; i < n - 1; ++i) {
        int from, to;
        cin >> from >> to;
        vertexes[--from].edges.emplace_back(--to);
        vertexes[to].edges.emplace_back(from);
    }
    cout << (gameDfs(vertexes, start - 1) ? "First player wins" : "Second player wins");
}