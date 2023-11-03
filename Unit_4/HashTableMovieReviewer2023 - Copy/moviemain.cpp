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

void getReviewRating(const shphashtable & reviews){
    cout << endl << "ENTER A REVIEW: ";
    string review;
    getline(cin, review);
    review += " ";

    string word = "";
    double sum = 0;
    int count = 0;

    for (int i=0; i<review.length(); i++){
        if (review[i] == ' '){
            if (word != ""){
                if (reviews.contains(word)){
                    sum += reviews.getAverageRating(word);
                    cout << word << " = " << reviews.getAverageRating(word) << endl;
                    count++;
                }
            }
            word = "";
        }
        else word += review[i];
    }
    sum += reviews.getAverageRating(word);
    count++;
    cout << "RATING = " << (1.0 * sum)/count << endl;
}


int main() {
    cout << "Hello, Movie Reviews!" << endl;
    shphashtable reviews(20003);
    // load review data here, probably in a function

    loadFile(reviews);
    reviews.printStats();

    getReviewRating(reviews);

    return 0;
}