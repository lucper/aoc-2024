#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>

bool is_safe(std::vector<int>& report) {
    bool increasing = report[0] - report[1] < 0;
    for (int i = 1; i < report.size(); ++i) {
        int diff = report[i-1] - report[i];
        if (std::abs(diff) < 1 || std::abs(diff) > 3)
            return false;
        if ((diff < 0 && !increasing) || (diff > 0 && increasing))
            return false;
    }
    return true;
}

int main() {
    int safe_reports = 0;
    std::vector<int> report(5, 0);
    
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string number;
        while (iss >> number)
            report.push_back(std::stoi(number));
        if (is_safe(report))
            safe_reports++;
        report.erase(report.begin(), report.end());
    }

    std::cout << "Safe reports: " << safe_reports << "\n";
}
