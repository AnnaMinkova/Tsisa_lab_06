#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

void Print(const std::vector<std::vector<int>>& m){
    for (const auto& k: m){
        for (auto v: k){
            std::cout << std::setw(3) << v;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void FloydAlgoritm(std::vector<std::vector<int>> &m){
    for (int k = 0; k < m.size(); k++) {
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m.size(); j++) {
                if (i != j && m[i][k] != -1 && m[k][j] != -1) {
                    if (m[i][j] == -1) {
                        m[i][j] = m[i][k] + m[k][j];
                    }
                    else m[i][j] = std::max(m[i][j], m[i][k] + m[k][j]);
                }
            }
        }
    }
}

int main() {
    int INF = -9;
    std::vector<std::vector<int>> adjMatrix = {
            {0,   3,   3,   2,   INF, INF, INF, INF, INF},
            {INF, 0,   INF, 5,   INF, INF, INF, INF, INF},
            {INF, INF, 0,   1,   INF, 3,   3,   INF, INF},
            {INF, INF, INF, 0,   2,   4,   INF, INF, INF},
            {INF, INF, INF, INF, 0,   INF, INF, 4,   INF},
            {INF, INF, INF, INF, INF, 0,   2,   INF, INF},
            {INF, INF, INF, INF, INF, INF, 0,   5,   INF},
            {INF, INF, INF, INF, INF, INF, INF, 0,   INF}
    };
    Print(adjMatrix);
    FloydAlgoritm(adjMatrix);
    Print(adjMatrix);
}