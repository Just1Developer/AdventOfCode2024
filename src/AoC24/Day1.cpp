#include "../readinput.h"

//#include <bits/regex.h>
#include <algorithm>
#include <vector>

void part1();
void part2();

vector<int> leftNums, rightNums;

int main() {
    auto input = readFile("day1");
    for (string& s : input) {
        int number = 0;
        int processed = 0;
        for (char c : s + " ") {
            // Own Number Parsing
            if (c >= '0' && c <= '9') {
                number *= 10;
                number += c - '0';
                processed = processed == 0 ? 1 : processed == 2 ? 3 : processed;
            } else if (processed & 1) {
                (processed == 1 ? leftNums : rightNums).push_back(number);
                number = 0;
                processed++;
            }
        }

        std::sort(leftNums.begin(), leftNums.end());
        std::sort(rightNums.begin(), rightNums.end());

        /* Regex doesn't wanna, regex.h doesnt compile
        regex pattern("(\\d+) +(\\d+)");
        smatch matches;
        regex_search(s, matches, pattern);
        if (regex_search(s, matches, pattern)) {
            for (auto i : matches) {
                // ...
            }
        }*/
    }

    part1();
    part2();
}

void part1() {
    int result = 0;

    for (int i = 0; i < leftNums.size(); i++) {
        result += abs(leftNums[i] - rightNums[i]);
    }

    cout << "part1 >> " << result << endl;
}

void part2() {
    uint64_t result = 0;

    int prevNum = -1;
    uint64_t prevOcc = 0;
    for (int& num : leftNums) {
        if (num == prevNum) {
            result += prevOcc * num;
            continue;
        }

        auto lower = std::lower_bound(rightNums.begin(), rightNums.end(), num);
        auto upper = std::upper_bound(rightNums.begin(), rightNums.end(), num);
        uint64_t occ = upper - lower;

        prevNum = num;
        prevOcc = occ;
        result += occ * num;
    }

    cout << "part2 >> " << result << endl;
}