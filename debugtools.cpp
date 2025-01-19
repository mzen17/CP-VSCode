// printlib.cpp
#include <iostream>
#include <vector>
#include <set>

void printV2D(const std::vector<std::vector<int>>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printS2D(const std::set<std::vector<int>>& a) {
    for (const auto& v : a) {
        for (int x : v) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}

void printV(const std::vector<int>& a) {
    for (int b : a) {
        std::cout << b << " ";
    }
    std::cout << std::endl;
}
