#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>

enum condition {
    NOT_VISITED,
    INSIDE,
    VISITED
};

struct Vertex {
    condition isVisited = NOT_VISITED;
    std::vector<int> adjVertexes;
};

std::vector<Vertex> vertexes;
std::set<int> notVisited;
std::vector<int> sortedGraph;

bool topSort(int vertex) {
    notVisited.erase(vertex);
    vertexes[vertex].isVisited = INSIDE;
    for (int adjVertex: vertexes[vertex].adjVertexes) {
        if (vertexes[adjVertex].isVisited == INSIDE || (vertexes[adjVertex].isVisited == NOT_VISITED && !topSort(adjVertex))) {
            return false;
        }
    }
    if (vertexes[vertex].isVisited != VISITED) {
        vertexes[vertex].isVisited = VISITED;
        sortedGraph.emplace_back(vertex);
    }
    return true;
}

int main() {
    //std::ifstream fin("test.in");
    int n, m;
    std::cin >> n >> m;

    vertexes.resize(n);

    for (int i = 0; i < n; ++i) {
        notVisited.insert(i);
    }

    for (int i = 0; i < m; ++i) {
        int startE, endE;
        std::cin >> startE >> endE;
        vertexes[startE - 1].adjVertexes.emplace_back(endE - 1);
    }

    while (!notVisited.empty()) {
        if (!topSort(*notVisited.begin())) {
            std::cout << -1;
            return 0;
        }
    }

    std::reverse(std::begin(sortedGraph), std::end(sortedGraph));
    for (int vertex: sortedGraph) {
        std::cout << vertex + 1 << ' ';
    }
}