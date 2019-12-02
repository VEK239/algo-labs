#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>
#include <hash_map>
#include <map>
#include <string>

enum condition {
    NOT_VISITED_AT_ALL,
    VISITED_DFS,
    VISITED
};

struct Vertex {
    int componentNum;
    condition isVisited = NOT_VISITED_AT_ALL;
    std::set<int> adjVertexes;
    std::set<int> adjVertexesReversed;
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
    vertexes[vertex].componentNum = componentNum;
    for (int adjVertex: vertexes[vertex].adjVertexesReversed) {
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
    vertexes.resize(2 * n);
    std::map<std::string, int> nameToNum;
    std::map<int, std::string> numToName;

    for (int i = 0; i < n; ++i) {
        std::string name;
        std::cin >> name;
        nameToNum[name] = 2 * i;
        numToName[2 * i] = name;
    }

    for (int i = 0; i < m; ++i) {
        int xVertex, yVertex;
//        fin >> xVertex >> yVertex;
        std::string x, arrow, y;
        std::cin >> x >> arrow >> y;
        xVertex = nameToNum[x.substr(1)] + (x[0] == '+' ? 0 : 1);
        yVertex = nameToNum[y.substr(1)] + (y[0] == '+' ? 0 : 1);
        vertexes[xVertex].adjVertexes.insert(yVertex);
        vertexes[yVertex].adjVertexesReversed.insert(xVertex);
        vertexes[(y[0] == '+' ? yVertex + 1 : yVertex - 1)].adjVertexes.insert((x[0] == '+' ? xVertex + 1 : xVertex - 1));
        vertexes[(x[0] == '+' ? xVertex + 1 : xVertex - 1)].adjVertexesReversed.insert((y[0] == '+' ? yVertex + 1 : yVertex - 1));
    }

//    for (int k = 0; k < 2 * n; ++k) {
//        std::cout << '\n' << k << ": ";
//        for (auto adj: vertexes[k].adjVertexes) {
//            std::cout << adj << '|';
//        }
//    }

    for (int i = 0; i < 2 * n; ++i) {
        if (vertexes[i].isVisited == NOT_VISITED_AT_ALL)
            dfsOrdering(i);
    }

    std::reverse(orderedVertexes.begin(), orderedVertexes.end());
    int compCount = 1;
    for (int vertex: orderedVertexes) {
        if (vertexes[vertex].isVisited != VISITED) {
            dfsComponentsMaking(vertex, compCount++);
        }
    }

    int countPeople = 0;
    for (int j = 0; j < 2 * n; j += 2) {
        if (vertexes[j].componentNum == vertexes[j + 1].componentNum) {
            std::cout << -1;
            return 0;
        } else if (vertexes[j].componentNum > vertexes[j + 1].componentNum) {
            ++countPeople;
        }
    }

//    std::cout << '\n';
//    for (Vertex v: vertexes) {
//        std::cout << v.componentNum << ' ';
//    }
//    std::cout << '\n';

    std::cout << countPeople << '\n';
    for (int j = 0; j < 2 * n; j += 2) {
        if (vertexes[j].componentNum > vertexes[j + 1].componentNum) {
            std::cout << numToName[j] << '\n';
        }
//        std::cout << vertexes[j].componentNum;
    }
}