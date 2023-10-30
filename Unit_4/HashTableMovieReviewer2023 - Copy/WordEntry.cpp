
#include "WordEntry.h"
using namespace std;


WordEntry::WordEntry(string str, int score) {
    word = str;
    totalStars = score;
    numRatings = 1;
}

string WordEntry::getWord() const {
    return word;
}

double WordEntry::getAvgScore() const {
    return (1.0 * totalStars) / numRatings;
}

void WordEntry::addScore(int score) {
    totalStars += score;
    numRatings ++;
}
