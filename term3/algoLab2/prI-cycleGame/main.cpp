#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum Condition {
    WIN,
    LOSE,
    DRAW
};

struct Vertex {
    vector<int> edges;
    vector<int> backEdges;
    Condition condition = DRAW;
    int counter = 0;
};

void gameDfs(vector<Vertex> &vertexes, bool isFromZero, int vertexNum) {
    vertexes[vertexNum].condition = isFromZero ? WIN : LOSE;
    for (int i = 0; i < vertexes[vertexNum].backEdges.size(); ++i) {
        int curVer = vertexes[vertexNum].backEdges[i];
        if (vertexes[curVer].condition == DRAW) {
            if (isFromZero) {
                if (--vertexes[curVer].counter == 0) {
                    gameDfs(vertexes, false, curVer);
                }
            } else {
                gameDfs(vertexes, true, curVer);
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<Vertex> vertexes(n);
        for (int i = 0; i < m; ++i) {
            int from, to;
            cin >> from >> to;
            vertexes[--to].backEdges.emplace_back(--from);
            vertexes[from].edges.emplace_back(to);
        }
        vector<int> zeroVer;
        for (int k = 0; k < n; ++k) {
            vertexes[k].counter = vertexes[k].edges.size();
            if (vertexes[k].counter == 0) {
                zeroVer.emplace_back(k);
            }
        }
        for (int j : zeroVer) {
            if (vertexes[j].condition == DRAW) {
                gameDfs(vertexes, false, j);
            }
        }
        for (int i = 0; i < n; ++i) {
            switch (vertexes[i].condition) {
                case WIN:
                    cout << "FIRST\n";
                    break;
                case LOSE:
                    cout << "SECOND\n";
                    break;
                case DRAW:
                    cout << "DRAW\n";
                    break;
            }
        }
        cout << '\n';
    }
}