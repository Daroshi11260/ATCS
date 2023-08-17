#include <iostream>

using namespace std;

string removeVowels(string str);
bool isVowel(char ch);


int main() {
    cout << "Welcome to Vowelless!" << endl;
    cout << "How many times do you want to play? :";
    int numTimes;
    cin >> numTimes;
    cin.ignore();
    string phrase = "Strawberry smoothie";
    for (int i = 0; i < numTimes; i++){
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


