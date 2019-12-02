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
    std::vector<int> edgesNum;
    int timeIn;
    int timeOut;
};

int time = 0;

std::vector<Vertex> vertexes;
std::set<int> notVisited;
std::set<std::pair<int, int>> bridges;
std::set<int> bridgesByNum;

void dfs(int vertex, int parent) {
    vertexes[vertex].isVisited = VISITED;
    time += 1;
    vertexes[vertex].timeIn = time;
    vertexes[vertex].timeOut = time;
    for (int i = 0; i < vertexes[vertex].adjVertexes.size(); ++i) {
//    for (int adjVertex: vertexes[vertex].adjVertexes) {
        int adjVertex = vertexes[vertex].adjVertexes[i];
        if (parent == adjVertex) {
            continue;
        }

        if (vertexes[adjVertex].isVisited != NOT_VISITED) {
            vertexes[vertex].timeOut = std::min(vertexes[vertex].timeOut, vertexes[adjVertex].timeIn);
        } else {
            dfs(adjVertex, vertex);
            vertexes[vertex].timeOut = std::min(vertexes[vertex].timeOut, vertexes[adjVertex].timeOut);
        }

        if (vertexes[adjVertex].timeOut > vertexes[vertex].timeIn) {
            bridges.insert(std::make_pair(vertex, adjVertex));
            bridgesByNum.insert(vertexes[vertex].edgesNum[i]);
        }
    }
}

int main() {
//    std::ifstream fin("test.in");
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
        vertexes[startE - 1].edgesNum.emplace_back(i + 1);
        vertexes[endE - 1].adjVertexes.emplace_back(startE - 1);
        vertexes[endE - 1].edgesNum.emplace_back(i + 1);
    }

    for (int i = 0; i < n; ++i) {
        if (vertexes[i].isVisited == NOT_VISITED)
            dfs(i, -1);
    }
    std::cout << bridgesByNum.size() << "\n";
//    for (auto vertex: bridges) {
//        std::cout << vertex.first << ' ' << vertex.second << "\n";
//    }
    for (int bridge: bridgesByNum) {
        std::cout << bridge << " ";
    }
}