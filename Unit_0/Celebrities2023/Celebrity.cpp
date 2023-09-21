//
// Created by Roshan Taneja on 8/24/2023.
//

#include "Celebrity.h"

using namespace std;

Celebrity::Celebrity(string n, string clueString) {
    name = n;
    string clueString = clues;
    for (int i = 0; i < clueString.length(); i++){
        if (clueString[i] == ','){
            clues.push_back(clueString.substr(0, i));
            clueString = clueString.substr(i + 1, clueString.length());
            i = 0;
        }
    }
}

string Celebrity::getName() {
    return name;
}

string Celebrity::getClue() {
    string clue = clues[0];
    clues.erase(clues.begin());
    return clue;
}

Celebrity::~Celebrity() {

}
