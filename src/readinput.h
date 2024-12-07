#ifndef READINPUT_H
#define READINPUT_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

inline vector<string> readFile(const string& aocname, const string& filename) {
    //string name = "../../../src/" + aocname + "/input/" + filename + ".txt";      // Working directory as debug (macOS) (perhaps in error)
    string name = "./src/" + aocname + "/input/" + filename + ".txt";               // Working directory as root (Win11)
    std::ifstream inFile(name);
    auto* strings = new vector<string>();
    if (!inFile.is_open()) {
        std::cerr << "Could not open file " << name << std::endl;
        return *strings;
    }

    for (std::string line; std::getline(inFile, line);) {
        strings->emplace_back(line);
    }

    // To trigger some stuff in the tasks, add empty line
    //strings->emplace_back("");    // nevermind

    inFile.close();
    return *strings;
}

inline vector<string> readFile(const string& filename) {
    return readFile("AoC24", filename);
}

#endif