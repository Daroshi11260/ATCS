#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <fstream>

using namespace std;

int main() {
    std::cout << "Hello, ADT's!" << std::endl;

    stack<string> s;

    s.push("Red");
    s.push("Natasha");
    s.push("Roshan");

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    queue<string> q;

    q.push("Thalia");
    q.push("Ethan");
    q.push("Neil");

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    set<string> names;

    names.insert("Nick");
    names.insert("Nick");
    names.insert("Nick");
    names.insert("Natasha");
    names.insert("Neil");

    names.erase("Natasha");

    set<string>::iterator itr = names.begin();

    while (itr != names.end()) {
        cout << *itr << endl;
        itr++;
    }


    cout << "MAPS" << endl;

    map<string, int> cousinMap;

    cousinMap.insert({"Nick", 5});
    cousinMap.insert({"Thalia", 7});
    cousinMap.insert({"Roshan", 9});

    cout << cousinMap.at("Roshan") << endl;
    cout << cousinMap["Nick"] << endl;

    cousinMap["Thalia"] += 1;

    cousinMap.erase("Roshan");



    for(auto iter = cousinMap.begin(); iter != cousinMap.end(); iter++){
        cout << iter->first << " has " << iter->second << " cousins." <<endl;
    }

    ifstream f("stuff.txt");

    map<char,int> freqMap;
    char ch;
    while (f >> ch) {
        freqMap[ch]++;
    }

    for (auto iter = freqMap.begin(); iter != freqMap.end(); iter++) {
        cout << iter->first << " : " << iter->second << endl;
    }


    return 0;
}
