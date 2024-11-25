#include "../readinput.h"

int main() {
    auto input = readFile("AoC22", "day1ex");

    for (string& s : input) {
        cout << s << endl;
    }
}