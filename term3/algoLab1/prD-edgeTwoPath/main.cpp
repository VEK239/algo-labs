#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>

int time = 0;
int curColor = 0;
enum condition {
    NOT_VISITED_AT_ALL,
    VISITED_BRIDGE,
    VISITED
};

struct Vertex {
    int color = 0;
    condition isVisited = NOT_VISITED_AT_ALL;
    std::vector<int> adjVertexes;
    int timeIn;
    int timeOut;
};
std::vector<Vertex> vertexes;

void dfsBridge(int vertex, int parent) {
    vertexes[vertex].isVisited = VISITED_BRIDGE;
    ++time;
    vertexes[vertex].timeIn = time;
    vertexes[vertex].timeOut = time;
    bool seenParent = false;
    for (int i = 0; i < vertexes[vertex].adjVertexes.size(); ++i) {
        int adjVertex = vertexes[vertex].adjVertexes[i];
        if (parent == adjVertex && !seenParent) {
            seenParent = true;
            continue;
        }
        if (vertexes[adjVertex].isVisited != NOT_VISITED_AT_ALL) {
            vertexes[vertex].timeOut = std::min(vertexes[vertex].timeOut, vertexes[adjVertex].timeIn);
        } else {
            dfsBridge(adjVertex, vertex);
            vertexes[vertex].timeOut = std::min(vertexes[vertex].timeOut, vertexes[adjVertex].timeOut);
        }
    }
}

void doColor(int vertex, int color) {
    vertexes[vertex].isVisited = VISITED;
    vertexes[vertex].color = color;
    for (int adjVertex: vertexes[vertex].adjVertexes) {
        if (vertexes[adjVertex].isVisited != VISITED) {
            if (vertexes[vertex].timeIn < vertexes[adjVertex].timeOut) {
                doColor(adjVertex, ++curColor);
            } else {
                doColor(adjVertex, color);
            }
        }
    }
}

int main() {
//    std::ifstream fin("test.in");
    int n, m;
    std::cin >> n >> m;
    vertexes.resize(n);

    for (int i = 0; i < m; ++i) {
        int startE, endE;
        std::cin >> startE >> endE;
        vertexes[startE - 1].adjVertexes.emplace_back(endE - 1);
        vertexes[endE - 1].adjVertexes.emplace_back(startE - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (vertexes[i].isVisited == NOT_VISITED_AT_ALL)
            dfsBridge(i, -1);
    }
    for (int i = 0; i < n; ++i) {
        if (vertexes[i].isVisited != VISITED) {
            doColor(i, ++curColor);
        }
    }

    std::cout << curColor << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << vertexes[i].color << ' ';
    }
}