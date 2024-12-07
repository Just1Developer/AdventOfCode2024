#include "../readinput.h"

void part1();
void part2();

vector<string> map;

int main() {
    auto input = readFile("day4");

    for (const auto &line : input) {
        map.push_back(line);
    }

    part1();
    part2();
}

int look_xmas(int i, int j, int deltaX, int deltaY) {
    if (deltaY < 0 && i < 3) return 0;
    if (deltaY > 0 && map.size() - i <= 3) return 0;
    if (deltaX < 0 && j < 3) return 0;
    if (deltaX > 0 && map[i].length() - j <= 3) return 0;

    return map[i + deltaY][j + deltaX] == 'M'
        && map[i + 2 * deltaY][j + 2 * deltaX] == 'A'
        && map[i + 3 * deltaY][j + 3 * deltaX] == 'S';
}

void part1() {
    int result = 0;

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].length(); j++) {
            if (map[i][j] != 'X') continue;
            result += look_xmas(i, j, 0, 1);
            result += look_xmas(i, j, 1, 0);
            result += look_xmas(i, j, 0, -1);
            result += look_xmas(i, j, -1, 0);
            result += look_xmas(i, j, 1, 1);
            result += look_xmas(i, j, 1, -1);
            result += look_xmas(i, j, -1, 1);
            result += look_xmas(i, j, -1, -1);
        }
    }

    cout << "part1 >> " << result << endl;
}

int look_mas(int i, int j) {
    return ((map[i - 1][j - 1] == 'M' && map[i + 1][j + 1] == 'S') || map[i - 1][j - 1] == 'S' && map[i + 1][j + 1] == 'M')
        && ((map[i + 1][j - 1] == 'M' && map[i - 1][j + 1] == 'S') || map[i + 1][j - 1] == 'S' && map[i - 1][j + 1] == 'M');
}

void part2() {
    int result = 0;

    for (int i = 1; i < map.size() - 1; i++) {
        for (int j = 1; j < map[i].length() - 1; j++) {
            if (map[i][j] != 'A') continue;
            result += look_mas(i, j);
        }
    }

    cout << "part2 >> " << result << endl;
}