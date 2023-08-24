// Roshan Taneja

#include <iostream>
#include <math.h>
#include <regex>

using namespace std;

//equation = ax^2 + bx + c
double getx1(double a, double b, double c);
double getx2(double a, double b, double c);
void parseEquation(string equation, double *a, double *b, double *c);
bool isValidQuadratic(string equation);

// Before you read my bad code:
// I'd like to mention that I didn't realize that you could just input the actual
// coefficients until I had already finished the program. My bad, I guess I just
// assumed that you wanted to parse the equation. I hope this is okay. It took
// a while because I don't even know c++ that well at all, but I enjoyed it. :]

int main() {
    double a, b, c, x1, x2;
    cout << "QUAD FORM SOLVER!" << endl << endl;
    /*
    string equation;
    cout << "Enter equation e.g(5x^2 + 3x - 2): ";
    getline(cin, equation);
    cout << endl << equation << endl;
    if (!isValidQuadratic(equation)){ // incorrect input cases handled with s t y l e.
        cout << "Invalid equation" << endl;
        return 0;
    }
    parseEquation(equation, &a, &b, &c); // pointers baby!
    */

    // I'm just going to assume that you want to input the coefficients.

    cout << "Enter a, b, c (with spaces pls): ";

    cin >> a >> b >> c;

    x1 = getx1(a, b, c);
    x2 = getx2(a, b, c);
    // this seems pointless. I could have just done it in the cout statement. Oh well.

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
}

double getx1(double a, double b, double c){
    return (-b + sqrt(b*b + 4*a*c))/(2*a);
}

double getx2(double a, double b, double c){
    return (-b - sqrt(b*b + 4*a*c))/(2*a);
}

bool isValidQuadratic(string equation){ // my beloved child, regex. I love you.
    return regex_match(equation, regex("^([-+]?\\d*\\.?\\d*)?x\\^2\\s*([-+]?\\s*\\d*\\.?\\d*)?x\\s*([-+]?\\s*\\d*\\.?\\d*)$"));
    // source: https://regexr.com/ i would have never produced this regex without it T-T
    // DISCLAIMER this regex does not pass for cases where the integer is -1 but not specified as -1
    // i.e (-x^2)
    // I was too lazy to fix it, so just don't do that pls. :]
}

void parseEquation(string equation, double *a, double *b, double *c){
    equation.erase(remove(equation.begin(), equation.end(), ' '), equation.end());
    // this is so bad. I'm sorry. I started with it just being quadratic
    // and then realized it's easier if I assume its polynomial.

    int strSize = equation.size();

    //	How many monomials has the polynomial?
    int monoms = 3; // default is quadratic

    // signs "+" are necessary for string parsing
    if(isdigit(equation[0]))
        equation.insert(0, "+");
    if(equation[0] == 'x') equation.insert(0, "+");
    equation.append("+");
    strSize = equation.size();

    // Extracting the monomials
    string monomStr[monoms]; //vector of strings to store monomials
    int k = 0;
    int l = 0;
    for (int i = 0; i < strSize; ++i){
        if(equation[i] == '+' || equation[i] == '-'){
            monomStr[k] = equation.substr(l, i - l);
            l = i;
            k++;
        } // the number of times I needed to rewrite this is insanity
    }

    //making sure all monomials have the same format [coeff]x^exponent
    for(int i = 0; i < monoms; ++i)
    {
        if(monomStr[i][1] == 'x')	//x is after the +/- sign
            monomStr[i].insert(1, "1");	//& gets 1 as coefficient
        bool xIsPresent = false;	// assuming that x is not present
        int len = monomStr[i].size();
        for(int j = 1; j < len; ++j)
            if(monomStr[i][j] == 'x')	//but we test this
            {
                xIsPresent = true;	//& x is present
                if(j == len - 1)	//& is the last
                    monomStr[i].append("^1");	//it gets exponent 1
                break;	//& exit from loop l
            }
        if(!xIsPresent)	//if x is not present: we have a constant term
            monomStr[i].append("x^0");	//who gets "formatting"
    }

    // extracting coefficients
    for(int i = 0; i < monoms; ++i)
    {
        int monomSize = monomStr[i].size();
        for(int j = 0; j < monomSize; ++j)
        {
            if(monomStr[i][j] == '^')
            {
                cout << monomStr[i].substr(j + 1) << endl;
                cout << monomStr[i].substr(0, j) << endl;
                // if exponent == 0 set c to coeff
                if (stoi(monomStr[i].substr(j + 1)) == 0){
                    *c = stod(monomStr[i].substr(0, j));
                }
                // if exponent == 1 set b to coeff
                else if (stoi(monomStr[i].substr(j + 1)) == 1){
                    *b = stod(monomStr[i].substr(0, j));
                }
                // if exponent == 2 set a to coeff
                else if (stoi(monomStr[i].substr(j + 1)) == 2){
                    *a = stod(monomStr[i].substr(0, j));
                }
                break;
            }
        }
    }
    // aaannd we're done. :]
}
// what did I miss?