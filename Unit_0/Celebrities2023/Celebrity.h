//
// Created by Roshan Taneja on 8/24/2023.
//

#ifndef CELEBRITIES_CELEBRITY_H
#define CELEBRITIES_CELEBRITY_H
#include <iostream>
#include <vector>

using namespace std;

class Celebrity {
public:
    Celebrity();
    string getName();
    string getClue();
    ~Celebrity();

private:
    string name;
    vector<string> clues;
    string getClue();
};


#endif //CELEBRITIES_CELEBRITY_H
