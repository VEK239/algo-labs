#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

struct Vertex {
    long long x = 0, y = 0, distUsed = 0;
    bool isUsed = false;
};

long long sqDist(Vertex vFirst, Vertex vSecond) {
    return (vFirst.x - vSecond.x) * (vFirst.x - vSecond.x) + (vFirst.y - vSecond.y) * (vFirst.y - vSecond.y);
}

int main() {
    std::vector<Vertex> vertexes;
//    std::ifstream fin("test.in");
    int n;
    std::cin >> n;
//    fin >> n;
    vertexes.resize(n);
    for (int j = 0; j < n; ++j) {
        std::cin >> vertexes[j].x >> vertexes[j].y;
//        fin >> vertexes[j].x >> vertexes[j].y;
        vertexes[j].distUsed = sqDist(vertexes[j], vertexes[0]);
    }

    double weight = 0;
    int oldV = 0;
    for (int i = 0; i < n; i++) {
        bool isFound = false;
        int newV = 0;
        vertexes[oldV].isUsed = true;
        for (int j = 0; j < n; j++) {
            if (!vertexes[j].isUsed && (!isFound || vertexes[j].distUsed < vertexes[newV].distUsed)) {
                isFound = true;
                newV = j;
            }
        }
        weight += std::sqrt(std::min(sqDist(vertexes[newV], vertexes[oldV]), vertexes[newV].distUsed));
        for (int j = 0; j < n; j++) {
            vertexes[j].distUsed = std::min(vertexes[j].distUsed, sqDist(vertexes[j], vertexes[newV]));
        }
        oldV = newV;
    }
    std::cout << weight;
}
