#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>

enum condition {
    NOT_VISITED_AT_ALL,
    VISITED_DFS,
    VISITED
};

struct Vertex {
    int componentNum;
    condition isVisited = NOT_VISITED_AT_ALL;
    std::vector<int> adjVertexes;
    std::vector<int> adjVertexesReversed;
};

std::vector<Vertex> vertexes;
std::vector<int> orderedVertexes;

void dfsOrdering(int vertex) {
    vertexes[vertex].isVisited = VISITED_DFS;
    for (int adjVertex: vertexes[vertex].adjVertexes) {
        if (vertexes[adjVertex].isVisited == NOT_VISITED_AT_ALL) {
            dfsOrdering(adjVertex);
        }
    }
    orderedVertexes.emplace_back(vertex);
}

void dfsComponentsMaking(int vertex, int componentNum) {
    vertexes[vertex].isVisited = VISITED;
    std::cout << '{' << vertex << ' ' << componentNum << '}';
    vertexes[vertex].componentNum = componentNum;
    for (int adjVertex: vertexes[vertex].adjVertexesReversed) {
        std::cout << "!!" << vertex << adjVertex << "!!";
        if (vertexes[adjVertex].isVisited != VISITED) {
            dfsComponentsMaking(adjVertex, componentNum);
        }
    }
}

int main() {
//    std::ifstream fin("test.in");
    int n, m;
    std::cin >> n >> m;
//    fin >> n >> m;
    vertexes.resize(n);

    for (int i = 0; i < m; ++i) {
        int startE, endE;
//        fin >> startE >> endE;
        std::cin >> startE >> endE;
        vertexes[startE - 1].adjVertexes.emplace_back(endE - 1);
        vertexes[endE - 1].adjVertexesReversed.emplace_back(startE - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (vertexes[i].isVisited == NOT_VISITED_AT_ALL)
            dfsOrdering(i);
    }
    std::cout << "\n!";
    for (int j = 0; j < n; ++j) {
        std::cout << orderedVertexes[j];
    }


    std::reverse(orderedVertexes.begin(), orderedVertexes.end());
    std::cout << "\n!";
    for (int j = 0; j < n; ++j) {
        std::cout << orderedVertexes[j];
    }
    int compCount = 1;
    for (int vertex: orderedVertexes) {
        if (vertexes[vertex].isVisited != VISITED) {
            dfsComponentsMaking(vertex, compCount++);
        }
    }

    for (Vertex v: vertexes) {
        std::cout << v.componentNum;
    }

    std::set<std::pair<int, int>> edges;

    for (int i = 0; i < n; ++i) {
        for (int adjVertex: vertexes[i].adjVertexes) {
            if (vertexes[i].componentNum != vertexes[adjVertex].componentNum) {
                edges.insert({vertexes[i].componentNum, vertexes[adjVertex].componentNum});
            }
        }
    }

    std::cout << edges.size();
}