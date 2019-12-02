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
    int num;
    bool isCutV = false;
    condition isVisited = NOT_VISITED;
    std::vector<int> adjVertexes;
    std::vector<int> edgeNumber;
    int timeIn;
    int timeOut;
};

int time = 0;

std::vector<Vertex> vertexes;
std::vector<int> edges;
std::vector<int> curEdges;

int color = 0;

void dfs(int vertex, int parent) {
    vertexes[vertex].isVisited = INSIDE;
    time += 1;
    vertexes[vertex].timeIn = time;
    vertexes[vertex].timeOut = time;
    int count = 0;
    for (int i = 0; i < vertexes[vertex].adjVertexes.size(); ++i) {
        int adjVertex = vertexes[vertex].adjVertexes[i];
        if (parent == adjVertex) {
            continue;
        }
        if (vertexes[adjVertex].isVisited == VISITED) {
            vertexes[vertex].timeOut = std::min(vertexes[vertex].timeOut, vertexes[adjVertex].timeIn);
        } else if (vertexes[adjVertex].isVisited == INSIDE) {
            vertexes[vertex].timeOut = std::min(vertexes[vertex].timeOut, vertexes[adjVertex].timeIn);
            curEdges.emplace_back(vertexes[vertex].edgeNumber[i]);
        } else {
            curEdges.emplace_back(vertexes[vertex].edgeNumber[i]);
            dfs(adjVertex, vertex);
            ++count;
            vertexes[vertex].timeOut = std::min(vertexes[vertex].timeOut, vertexes[adjVertex].timeOut);
            if (parent != -1 && vertexes[adjVertex].timeOut >= vertexes[vertex].timeIn) {
                vertexes[vertex].isCutV = true;
                ++color;
                while (curEdges.back() != vertexes[vertex].edgeNumber[i]) {
                    edges[curEdges.back()] = color;
                    curEdges.pop_back();
                }
                edges[curEdges.back()] = color;
                curEdges.pop_back();
            }
        }
    }
    if (parent == -1 && count >= 2) {
        vertexes[vertex].isCutV = true;
        ++color;
        while (!curEdges.empty()) {
            edges[curEdges.back()] = color;
            curEdges.pop_back();
        }
        edges[curEdges.back()] = color;
        curEdges.pop_back();
    }
    vertexes[vertex].isVisited = VISITED;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vertexes.resize(n);
    edges.resize(m);

    for (int i = 0; i < m; ++i) {
        int startE, endE;
        std::cin >> startE >> endE;
        vertexes[startE - 1].adjVertexes.emplace_back(endE - 1);
        vertexes[startE - 1].edgeNumber.emplace_back(i);
        vertexes[endE - 1].adjVertexes.emplace_back(startE - 1);
        vertexes[endE - 1].edgeNumber.emplace_back(i);
    }

    for (int i = 0; i < n; ++i) {
        if (vertexes[i].isVisited == NOT_VISITED) {
            dfs(i, -1);
            while (!curEdges.empty()) {
                edges[curEdges.back()] = color;
                curEdges.pop_back();
            }
        }
    }
    std::cout << color << '\n';
    for (int i = 0; i < m; ++i) {
        std::cout << edges[i] << ' ';
    }
}