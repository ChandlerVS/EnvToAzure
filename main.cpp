#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "nlohmann/json.hpp"

using namespace std;
using nlohmann::json;

int main(int argc, char *argv[]) {
    regex envCheckRegex("([a-zA-Z0-9_-]+)=(.+)");

    if(argc != 3) {
        cerr << "Not enough arguments" << endl;
        return 1;
    }

    fstream inputFile;
    inputFile.open(argv[1], ios::in);
    if(inputFile.is_open()) {
        // Create the json variable
        json outputJson = json::array();

        string line;
        while (getline(inputFile, line)) {
            smatch match;
            if(regex_match(line, match, envCheckRegex)) {
                outputJson.insert(outputJson.end(), json::object({{"name", match[1]}, {"value", match[2]}, {"slotSetting", false}}));
            }
        }

        ofstream out(argv[2]);
        if(out.is_open()) {
            out << outputJson.dump(2) << endl;
            out.close();
        }
    }

    return 0;
}
