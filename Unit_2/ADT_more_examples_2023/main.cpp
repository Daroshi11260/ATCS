#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <map>

using namespace std;

bool checkBalance(string str){
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);
        else if (str[i] == ')') {
            if (s.empty() || s.top() != '(')
                return false;
            else
                s.pop();
        }
        else if (str[i] == ']') {
            if (s.empty() || s.top() != '[')
                return false;
            else
                s.pop();
        }
        else if (str[i] == '}') {
            if (s.empty() || s.top() != '{')
                return false;
            else
                s.pop();
        }
    }
    return s.empty();
}

void testCheckBalance(){
    if (checkBalance("if (num > 0) { x = 3; } else { x = 4; } [x = 5;] (x = 6;) {(x)=={7}}"))
        cout << "Balanced!" << endl;
    else
        cout << "Not balanced!" << endl;
}

void testLetterFrequency() {
    ifstream infile("file.txt");
    map<char, int> freqMap;
    char ch;
    while (infile >> ch) {
        ch = toupper(ch);
        if (freqMap.count(ch) == 0)
            freqMap.insert({ch, 1});
        else
            freqMap.at(ch)++;  // freqMap[ch]++;
    }

    for (auto itr = freqMap.begin(); itr != freqMap.end(); itr++) {
        cout << itr->first << " = " << itr->second << endl;
    }

}

set<int> setIntersection(set<int> setA, set<int> setB) {
    set<int> setC;
    for (int num: setA) {
        if (setB.count(num))
            setC.insert(num);
    }

    return setC;
}

void testSetIntersection() {
    set<int> setA;
    set<int> setB;
    for (int i = 1; i <= 5; i++) {
        setA.insert(i);
    }

    for (int i = 3; i <= 10; i++) {
        setB.insert(i);
    }

    set<int> setC = setIntersection(setA, setB);

    for (auto itr = setC.begin(); itr != setC.end(); itr++) {
        cout << *itr << " ";
    }

    cout << endl;
}

void testFriends() {
    cin.ignore();
    map<string, set<string>> friends;
    string line;
    getline(cin, line);
    while(!line.empty()) {
        int pos = line.find(" ");
        string name1 = line.substr(0, pos);
        string name2 = line.substr(pos + 1);
        friends[name1].insert(name2);
        friends[name2].insert(name1);
        getline(cin, line);
    }

    for (auto itr = friends.begin(); itr != friends.end(); itr++) {
        cout << itr->first << ": ";
        for (string person: itr->second) {
            cout << person << " ";
        }
        cout << endl;
    }

}

//homework
set<int> setUnion (set<int> a, set<int> b);
//write a function that removes all negative values from a stack
void removeNegatives(stack<int> &s);
//reverse a queue
void reverseQueue(queue<int> &q);

int main() {
    cout << "Hooray for ADTs!" << endl;
    cout << "Choice?" << endl;
    int choice;
    cin >> choice;
    if (choice == 0)
        testCheckBalance();
    else if (choice == 1)
        testLetterFrequency();
    else if (choice == 2)
        testSetIntersection();
    else if (choice == 3)
        testFriends();
    return 0;
}