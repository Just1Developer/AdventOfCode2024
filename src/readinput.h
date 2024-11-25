#ifndef READINPUT_H
#define READINPUT_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<string> readFile(string aocname, string filename) {
    string name = "../../../src/" + aocname + "/input/" + filename + ".txt";
    std::ifstream inFile(name);
    auto* strings = new vector<string>();
    if (!inFile.is_open()) {
        std::cerr << "Could not open file " << name << std::endl;
        return *strings;
    }

    for (std::string line; std::getline(inFile, line);) {
        strings->emplace_back(line);
    }

    inFile.close();
    return *strings;
}
vector<string> readFile(string filename) {
    return readFile("AoC24", filename);
}

#endif