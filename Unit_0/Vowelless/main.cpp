#include <iostream>
#include <vector>

using namespace std;

string removeVowels(string str);
bool isVowel(char ch);


int main() {
    srand(time(0));
    cout << "Welcome to Vowelless!" << endl;
    cout << "How many times do you want to play? :";
    int numTimes;
    cin >> numTimes;
    cin.ignore();
    vector<string> phrases;
    phrases.push_back("Strawberry smoothie");
    phrases.push_back("Natasha Bamdad");
    phrases.push_back("Peanut butter and jelly sandwich");
    phrases.push_back("Chocolate chip cookies");
    phrases.push_back("Chicken noodle soup");
    phrases.push_back("Grilled cheese sandwich");
    phrases.push_back("Macaroni and cheese");

    for (int i = 0; i < numTimes; i++){
        int index = rand() % phrases.size();
        string phrase = phrases[index];
        string hint = removeVowels(phrase);
        cout << "heres your hint: " << hint << endl;
        cout << "your guess? ";
        string guess;
        getline(cin, guess);
        if (guess == phrase) {
            cout << "Correct!" << endl << endl;
        } else {
            cout << "Wrong! It was " << phrase << endl << endl;
        }
    }
    return 0;
}

bool isVowel(char ch) {
    return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

string removeVowels(string str){
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        char ch = toupper(str[i]);
        if (!isVowel(ch) && isalpha(ch)) {
            result += ch;
        }
    }
    return result;
}


