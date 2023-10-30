#include <iostream>
#include <fstream>
#include "shphashtable.h"

using namespace std;

void loadFile (shphashtable &reviews){
    ifstream f("reviews.txt");

    int rating;
    string review;

    while (f>>rating){
        getline(f, review);
        string word = "";
        for (int i = 0; i < review.length();i++){
            if (review[i] == ' ') {
                if (word.length() >= 0 && isalpha(word[0])) {
                    reviews.put(word, rating);
                }
                word = "";
            } else {
                word += review[i];
            }
        }
    }
}


int main() {
    cout << "Hello, Movie Reviews!" << endl;
    shphashtable reviews(20003);
    // load review data here, probably in a function

    loadFile(reviews);


    reviews.printStats();

    return 0;
}