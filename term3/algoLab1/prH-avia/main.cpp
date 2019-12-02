#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>

int n;
long mid;

std::vector<std::vector<int>> graphMatrix;
std::vector<bool> isVisitedVertexVector;

void dfs(int vertex) {
    isVisitedVertexVector[vertex] = true;
    for (int i = 0; i < n; ++i) {
        if (graphMatrix[vertex][i] <= mid && !isVisitedVertexVector[i]) {
            dfs(i);
        }
    }
}
void backDfs(int vertex) {
    isVisitedVertexVector[vertex] = true;
    for (int i = 0; i < n; ++i) {
        if (graphMatrix[i][vertex] <= mid && !isVisitedVertexVector[i]) {
            backDfs(i);
        }
    }
}

void doZeroVector() {
    for (int i = 0; i < n; ++i) {
        isVisitedVertexVector[i] = false;
    }
}
bool checkStrongConnected() {
    doZeroVector();
    dfs(0);
    for (int i = 0; i < n; ++i) {
        if (!isVisitedVertexVector[i]) {
            return false;
        }
    }
    doZeroVector();
    backDfs(0);
    for (int i = 0; i < n; ++i) {
        if (!isVisitedVertexVector[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ifstream fin("avia.in");
    std::ofstream fout("avia.out");
    fin >> n;
//    std::cin >> n;
    graphMatrix.resize(n);
    isVisitedVertexVector.resize(n);
    int right = 0;
    for (int i = 0; i < n; ++i) {
        graphMatrix[i].resize(n);
        for (int j = 0; j < n; ++j) {
            fin >> graphMatrix[i][j];
//            std::cin >> graphMatrix[i][j];
            if (graphMatrix[i][j] > right) {
                right = graphMatrix[i][j];
            }
        }
    }

    long left = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (!checkStrongConnected()) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    fout << left;
//    std::cout << left;
}