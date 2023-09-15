#include <iostream>
#include <fstream>
#include "Celebrity.h"
#include <vector>
#include <chrono>

using namespace std;

vector<Celebrity> celebrities;

void loadCelebrities(string filename);

int main() {
    srand(time(0));
    int score = 0;

    cout << "welcome to celebrity!" << endl << endl;
    loadCelebrities("celebrities.txt");

    //timing stuff
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    while (chrono::duration_cast<chrono::seconds>(end-start).count() < 60) {
        int index = rand() % celebrities.size();
        Celebrity c = celebrities[index];
        bool guessed = false;
        while (!guessed){
            cout << "Guess who this is: " << c.getClue() << endl;
            string guess;
            getline(cin, guess);
            if (guess == c.getName()) {
                cout << "You got it!" << endl;
                guessed = true;
                celebrities.erase(celebrities.begin() + index);
                score++;
            } else {
                cout << "Nope, try again!" << endl;
            }
        }
        end = chrono::high_resolution_clock::now();
    }
    cout << "out of time!" << endl << " your score was " << score << "!"<< endl;
    return 0;

}

void loadCelebrities(string filename){
    ifstream file;
    file.open(filename);
    if (file.is_open()){
        string line;
        while (getline(file, line)){
            string name;
            string clues;
            name = line.substr(0, line.find(":"));
            clues = line.substr(line.find(":") + 1, line.length());
            Celebrity c(name, clues);
            celebrities.push_back(c);
        }
    }
    file.close();
}