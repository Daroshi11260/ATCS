//
// Created by Roshan Taneja on 8/24/2023.
//

#include "Celebrity.h"

using namespace std;

Celebrity::Celebrity(string input) {
    
}

string Celebrity::getName() {
    return string();
}

string Celebrity::getClue() {
    string clue = clues[0];
    clues.erase(clues.begin());
    return clue;
}

Celebrity::~Celebrity() {

}
