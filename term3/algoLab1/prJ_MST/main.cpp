#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

struct Edge {
    Edge() = default;

    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}

    int from = 0, to = 0, weight = 0;
};

std::vector<int> vertexParent;
std::vector<int> snmSize;
std::vector<Edge> edges;

int getParent(int vertex) {
    if (vertexParent[vertex] != vertex) {
        vertexParent[vertex] = getParent(vertexParent[vertex]);
    }
    return vertexParent[vertex];
}

bool uniteSets(int vFirst, int vSecond) {
    vFirst = getParent(vFirst);
    vSecond = getParent(vSecond);
    if (vFirst != vSecond) {
        if (snmSize[vFirst] < snmSize[vSecond]) {
            std::swap(vFirst, vSecond);
        }
        vertexParent[vSecond] = vFirst;
        snmSize[vFirst] += snmSize[vSecond];
        return true;
    }
    return false;
}

bool comp(const Edge &first, const Edge &second) {
    return first.weight < second.weight;
}

int main() {
//    std::ifstream fin("test.in");
    int n, m;
    std::cin >> n >> m;
//    fin >> n >> m;
    vertexParent.resize(n);
    snmSize.resize(n);
    for (int j = 0; j < n; ++j) {
        vertexParent[j] = j;
        snmSize[j] = 1;
    }

    for (int i = 0; i < m; ++i) {
        int startE, endE, weight;
        std::cin >> startE >> endE >> weight;
//        fin >> startE >> endE >> weight;
        edges.emplace_back(Edge(startE - 1, endE - 1, weight));
    }

    std::sort(edges.begin(), edges.end(), comp);
    long long weight = 0;
    for (Edge edge: edges) {
        if (uniteSets(edge.from, edge.to)) {
            weight += edge.weight;
        }
    }
    std::cout << weight;
}