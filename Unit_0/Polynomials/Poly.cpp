//
// Created by Roshan Taneja on 8/22/2023.
//

#include "Poly.h"
#include <cmath>

Poly::Poly(int coeff, int exp) {
    Term t;
    t.coeff = coeff;
    t.exp = exp;
    terms.push_back(t);
}

void Poly::add(Poly p) {
    for (Term term: p.terms){
        add(term);
    }
}

void Poly::multiply(int c) {
    for (int i = 0; i < terms.size(); i++) {
        terms[i].coeff *= c;
    }
}

int Poly::eval(int x) const {
    int result = 0;
    for (int i = 0; i < terms.size(); i++){
        result += terms[i].coeff * pow(x, terms[i].exp);
    }
    return result;
}

string Poly::tostring() const {
    string result = "";
    for (Term term: terms){
        result += to_string(term.coeff) + "x^" + to_string(term.exp) + " + ";
    }

    return result.substr(0, result.length() - 3);
}

Poly::~Poly() {
    //we're done
}

void Poly::add(Poly::Term t) {

    if(t.exp > terms[0].exp){
        terms.insert(terms.begin(), t);
        return;
    } else {
        for (int i = 0; i < terms.size(); i++){
            if (t.exp > terms[i].exp){
                terms.insert(terms.begin() + i, t);
                return;
            } else if (t.exp == terms[i].exp){
                terms[i].coeff += t.coeff;
                return;
            }
        }
        terms.push_back(t);
    }
}

const Poly &Poly::operator+=(const Poly &rhs) {
    add(rhs);
    return *this;
}
