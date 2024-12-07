#include <regex>

#include "../readinput.h"

void part1();
void part2();

string combined;

int main() {
    auto input = readFile("day3");
    for (auto& _input : input) {
        combined += _input;
    }

    part1();
    part2();
}

void part1() {
    int result = 0;

    regex exp(R"((mul\((\d+),(\d+)\)))");
    string::const_iterator searchStart(combined.cbegin());
    smatch matches;
    while ( regex_search(searchStart, combined.cend(), matches, exp)) {

        // used https://stackoverflow.com/questions/21667295/how-to-match-multiple-results-using-stdregex

        string numbers = matches[0].str().substr(4, matches[0].length() - 5);   // take away mul()
        auto comma = numbers.find(',');
        string firstStr = numbers.substr(0, comma);
        string secondStr = numbers.substr(comma + 1);

        int first = stoi(firstStr);
        int second = stoi(secondStr);

        result += first * second;

        searchStart = matches.suffix().first;
    }

    cout << "part1 >> " << result << endl;
}

void part2() {
    int result = 0;

    regex exp(R"((mul\((\d+),(\d+)\)|do\(\)|don't\(\)))");
    string::const_iterator searchStart(combined.cbegin());
    smatch matches;

    bool enabled = true;

    while ( regex_search(searchStart, combined.cend(), matches, exp)) {

        if (matches[0].str() == "do()") enabled = true;
        else if (matches[0].str() == "don't()") enabled = false;
        else if (enabled) {
            string numbers = matches[0].str().substr(4, matches[0].length() - 5);   // take away mul()
            auto comma = numbers.find(',');
            string firstStr = numbers.substr(0, comma);
            string secondStr = numbers.substr(comma + 1);

            int first = stoi(firstStr);
            int second = stoi(secondStr);

            result += first * second;
        }

        searchStart = matches.suffix().first;
    }

    cout << "part2 >> " << result << endl;
}