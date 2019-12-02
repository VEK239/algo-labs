#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>

enum condition {
    NOT_VISITED,
    INSIDE,
    ALL_VISITED,
    VISITED_DFS
};

struct Vertex {
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

void dfs(int vertex, int parent) {
    vertexes[vertex].isVisited = VISITED_DFS;
    time++;
    vertexes[vertex].timeIn = time;
    vertexes[vertex].timeOut = time;
    for (int i = 0; i < vertexes[vertex].adjVertexes.size(); ++i) {
        int adjVertex = vertexes[vertex].adjVertexes[i];
        if (parent == adjVertex) {
            continue;
        }
        if (vertexes[adjVertex].isVisited == VISITED_DFS) {
            vertexes[vertex].timeOut = std::min(vertexes[vertex].timeOut, vertexes[adjVertex].timeIn);
        } else {
            dfs(adjVertex, vertex);
            vertexes[vertex].timeOut = std::min(vertexes[vertex].timeOut, vertexes[adjVertex].timeOut);
        }
    }
}

int color = 1;
void dfsComp(int vertex, int parent) {
    vertexes[vertex].isVisited = INSIDE;
    bool wasParent = false;
    for (int i = 0; i < vertexes[vertex].adjVertexes.size(); ++i) {
        int adjVertex = vertexes[vertex].adjVertexes[i];
        if (vertexes[adjVertex].isVisited == VISITED_DFS) {
            curEdges.emplace_back(vertexes[vertex].edgeNumber[i]);
            dfsComp(adjVertex, vertex);
            if (vertexes[vertex].timeIn <= vertexes[adjVertex].timeOut) {
                while (curEdges.back() != vertexes[vertex].edgeNumber[i]) {
                    edges[curEdges.back()] = color;
                    curEdges.pop_back();
                }
                edges[curEdges.back()] = color++;
                curEdges.pop_back();
            }
        } else if (adjVertex != parent && vertexes[adjVertex].isVisited != ALL_VISITED) {
            curEdges.emplace_back(vertexes[vertex].edgeNumber[i]);
        } else if (adjVertex == parent && wasParent) {
            curEdges.emplace_back(vertexes[vertex].edgeNumber[i]);
        }
        if (parent == adjVertex) {
            wasParent = true;
        }
    }
    vertexes[vertex].isVisited = ALL_VISITED;
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
        if (vertexes[i].isVisited == NOT_VISITED)
            dfs(i, -1);
    }
    for (int i = 0; i < n; ++i) {
        if (vertexes[i].isVisited == VISITED_DFS) {
            dfsComp(i, -1);
            while (!curEdges.empty()) {
                edges[curEdges.back()] = color - 1;
                curEdges.pop_back();
            }
        }
    }
    std::cout << color - 1 << '\n';
    for (int i = 0; i < m; ++i) {
        std::cout << edges[i] << ' ';
    }
}