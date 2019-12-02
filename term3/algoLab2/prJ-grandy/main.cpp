#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

struct Vertex {
    int grandy = 0;
    bool used = false;
    std::set<int> adjVertexes;
    std::set<int> backAdjVertexes;
};

int grundy(std::vector<Vertex>& vertexes, int vertex) {
    vertexes[vertex].used = true;
    int curGrandy = 0;
    for (auto adj: vertexes[vertex].adjVertexes) {
        if (!vertexes[adj].used) {
            curGrandy = curGrandy ^ (grundy(vertexes, adj) + 1);
        }
    }
    vertexes[vertex].grandy = curGrandy;
    return curGrandy;
}

int main() {
    std::vector<Vertex> vertexes;
    //std::ifstream fin("test.in");
    int n, start;
    std::cin >> n >> start;

    vertexes.resize(n);

    std::map<std::pair<int, int>, int> edgeNumber;
    for (int i = 0; i < start; ++i) {
        int startE, endE;
        std::cin >> startE >> endE;
        vertexes[startE - 1].adjVertexes.insert(endE - 1);
//        vertexes[endE - 1].backAdjVertexes.insert(startE - 1);
        vertexes[endE - 1].adjVertexes.insert(startE - 1);
        edgeNumber[std::make_pair(startE - 1, endE - 1)] = i + 1;
        edgeNumber[std::make_pair(endE - 1, startE - 1)] = i + 1;
    }

    for (int k = 0; k < n; ++k) {
        if (vertexes[k].backAdjVertexes.size() == 0) {
            grundy(vertexes, k);
        }
    }

    for (int j = 0; j < n; ++j) {
        std::cout << vertexes[j].grandy << '\n';
    }
}