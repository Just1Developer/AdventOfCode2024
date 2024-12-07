#include "../readinput.h"

void part1();
void part2();

vector<vector<int>> reports;

int main() {
    auto input = readFile("day2");

    for (auto& row : input) {
        vector<int> results;
        size_t nextSpace;
        while ((nextSpace = row.find(' ')) != string::npos) {
            string nr = row.substr(0, nextSpace);
            results.push_back(stoi(nr));
            row = row.substr(nextSpace + 1);
        }
        if (!row.empty()) results.push_back(stoi(row));
        reports.push_back(results);
    }

    part1();
    part2();
}

bool isSafe(vector<int>& results) {
    if (results.size() <= 1) return true;
    int isFalling = results[0] > results[1];
    int prev = results[0];
    for (int i = 1; i < results.size(); i++) {
        if (prev == results[i]) return false;
        if (abs(prev - results[i]) > 3) return false;
        if ((prev > results[i]) != (isFalling)) return false;
        prev = results[i];
    }
    return true;
}

void part1() {
    int result = 0;

    for (auto& row : reports) {
        if (isSafe(row)) result++;
    }

    cout << "part1 >> " << result << endl;
}

void part2() {
    int result = 0;

    for (auto& row : reports) {
        for (auto i = 0; i < row.size(); i++) {
            // i is the one we leave out
            auto value = row[i];
            row.erase(row.begin() + i);

            if (isSafe(row)) {
                result++;
                break;  // Finished with this row, it can be safe
            }

            row.insert(row.begin() + i, value);
        }
    }

    cout << "part2 >> " << result << endl;
}