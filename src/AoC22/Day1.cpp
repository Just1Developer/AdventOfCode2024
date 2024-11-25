#include "../readinput.h"

int main() {
    auto input = readFile("AoC22", "day1-robert");

    int sum = 0;
    int max1 = -1;
    int max2 = -2;
    int max3 = -3;

    for (string& s : input) {
        if (s.empty()) {
            if (max3 < sum) {
                max3 = sum;
                if (max2 < max3) {
                    max3 = max2;
                    max2 = sum;
                    if (max1 < max2) {
                        max2 = max1;
                        max1 = sum;
                    }
                }
            }
            sum = 0;
            continue;
        }
        sum += stoi(s);
    }
    int finalSum = max1 + max2 + max3;
    cout << finalSum << endl;
}