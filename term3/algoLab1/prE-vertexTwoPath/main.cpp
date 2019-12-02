#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>

int time = 0;
int curColor = 0;
enum condition {
    NOT_VISITED_AT_ALL,
    VISITED_CUT,
    VISITED
};

struct Vertex {
    condition isVisited = NOT_VISITED_AT_ALL;
    std::vector<int> adjVertexes;
    std::vector<int> edgeNumber;
    int timeIn;
    int timeOut;
};

std::vector<Vertex> vertexes;
std::vector<int> edges;


void dfsCutVertex(int vertex, int parent) {
    vertexes[vertex].isVisited = VISITED_CUT;
    ++time;
    vertexes[vertex].timeIn = time;
    vertexes[vertex].timeOut = time;
    for (int i = 0; i < vertexes[vertex].adjVertexes.size(); ++i) {
        int adjVertex = vertexes[vertex].adjVertexes[i];
        if (parent == adjVertex) {
            continue;
        }
        if (vertexes[adjVertex].isVisited != NOT_VISITED_AT_ALL) {
            vertexes[vertex].timeOut = std::min(vertexes[vertex].timeOut, vertexes[adjVertex].timeIn);
        } else {
            dfsCutVertex(adjVertex, vertex);
            vertexes[vertex].timeOut = std::min(vertexes[vertex].timeOut, vertexes[adjVertex].timeOut);
        }
    }
}

void doColor(int vertex, int parent, int color) {
    vertexes[vertex].isVisited = VISITED;
    for (int i = 0; i < vertexes[vertex].adjVertexes.size(); ++i) {
        if (edges[vertexes[vertex].edgeNumber[i]] == 0) {
            int adjVertex = vertexes[vertex].adjVertexes[i];
            std::cout << vertexes[vertex].edgeNumber[i] << ' ' << edges[vertexes[vertex].edgeNumber[i]] << '\n';
            if (vertexes[vertex].timeIn <= vertexes[adjVertex].timeOut) {
                edges[vertexes[vertex].edgeNumber[i]] = ++curColor;
                doColor(adjVertex, vertex, curColor);
            } else {
                edges[vertexes[vertex].edgeNumber[i]] = color;
                doColor(adjVertex, vertex, color);
            }
        }
    }
}

int main() {
    std::ifstream fin("test.in");
    int n, m;
//    std::cin >> n >> m;
    fin >> n >> m;
    vertexes.resize(n);

    for (int i = 0; i < m; ++i) {
        int startE, endE;
//        std::cin >> startE >> endE;
        fin >> startE >> endE;
        vertexes[startE - 1].adjVertexes.emplace_back(endE - 1);
        vertexes[startE - 1].edgeNumber.emplace_back(i);
        vertexes[endE - 1].adjVertexes.emplace_back(startE - 1);
        vertexes[endE - 1].edgeNumber.emplace_back(i);
        edges.emplace_back(0);
    }

    for (int i = 0; i < n; ++i) {
        if (vertexes[i].isVisited == NOT_VISITED_AT_ALL)
            dfsCutVertex(i, -1);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << vertexes[i].timeIn << vertexes[i].timeOut << '\n';
    }

    for (int i = 0; i < n; ++i) {
        if (vertexes[i].isVisited != VISITED) {
            std::cout << i;
            doColor(i, -1, curColor);
        }
    }

    std::cout << curColor << '\n';
    for (int i = 0; i < m; ++i) {
        std::cout << edges[i] << ' ';
    }
}