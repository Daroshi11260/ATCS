//
// Created by Roshan Taneja on 8/22/2023.
//

#ifndef POLYNOMIALS_POLY_H
#define POLYNOMIALS_POLY_H

#include <iostream>
#include <vector>

using namespace std;

class Poly {

public:
    Poly(int coeff, int exp);
    void add(Poly p);
    void multiply(int c);
    int eval(int x) const;
    string tostring() const;
    ~Poly();

    const Poly& operator += (const Poly &rhs);

private:
    struct Term {
        int coeff;
        int exp;
    };

    vector<Term> terms;

    void add(Term t);


};


#endif //POLYNOMIALS_POLY_H
