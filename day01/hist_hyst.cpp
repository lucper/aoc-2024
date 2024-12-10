#include <iostream>
#include <numeric> // std::accumulate
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // std::sort
#include <cstdlib> // std::abs

int main() {
    std::vector<int> col1, col2;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int v1, v2;
        iss >> v1 >> v2;
        col1.push_back(v1);
        col2.push_back(v2);
    }

    // Part One
    std::sort(col1.begin(), col1.end());
    std::sort(col2.begin(), col2.end());

    std::vector<int> dists;
    for (int i = 0; i < col1.size(); ++i)
        dists.push_back(std::abs(col1[i] - col2[i]));

    std::cout << "Total distance: " << std::accumulate(dists.begin(), dists.end(), 0) << "\n";

    // Part Two
    std::vector<int> count(col2.back(), 0);
    for (int i = 0; i < col2.size(); ++i)
        count[col2[i]]++;

    int sim_score = 0;
    for (auto i : col1)
        sim_score += i * count[i];
    std::cout << "Similarity: " << sim_score << "\n";
}
