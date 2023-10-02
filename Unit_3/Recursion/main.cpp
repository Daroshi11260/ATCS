#include <iostream>

using namespace std;

int fibbonaci(int n);
int power(int base, int exp);
bool isPalindrome(string str);
int countAs(string str);
int c(int n, int r);
string numStars(int n);
void moveTower(int n, char a, char b, char c);

int main() {
    cout << "Hello, Recursion!" << endl;

    cout << "fibbonaci: " << fibbonaci(7) << endl;

    cout << "power: " << power(2, 5) << endl;

    cout << "isPalindrome: " << isPalindrome("racecar") << endl;

    cout << "count As: " << countAs("Natasha Bamdad") << endl;

    cout << "7 choose 4: " << c(7, 4) << endl;

    cout << "num of stars: " << numStars(27) << endl;

    cout << "move tower: " << endl;

    moveTower(100, 'A', 'C', 'B');

    return 0;
}

int fibbonaci(int n){
    if(n < 2){
        return n;
    } else {
        return fibbonaci(n-1) + fibbonaci(n-2);
    }
}

int power(int base, int exp){
    if(exp == 0){
        return 1;
    } else {
        return base * power(base, exp-1);
    }
}

bool isPalindrome(string str){
    if (str.length() < 2){
        return true;
    } else {
        return str[0] == str[str.length()-1]
                && isPalindrome(str.substr(1, str.length()-2));
    }
}

int countAs(string str){
    if(str.length() == 0){
        return 0;
    } else {
        if(str[0] == 'a'){
            return 1 + countAs(str.substr(1));
        } else {
            return countAs(str.substr(1));
        }
    }
}

int c(int n, int r){
    if(r == 0 || r == n){
        return 1;
    } else {
        return c(n-1, r-1) + c(n-1, r);
    }
}

string numStars(int n){
    if(n == 0){
        return "";
    } else {
        return "*" + numStars(n-1);
    }
}

void moveTower(int n, char source, char dest, char temp){
    if (n == 0){
        return;
    } else {
        moveTower(n-1, source, temp, dest);
        cout << "Move disk " << n << " from " << source << " to " << dest << endl;
        moveTower(n-1, temp, dest, source);
    }
}
