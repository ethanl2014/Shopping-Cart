#ifndef EXPRESSIONBUILDER_H
#define EXPRESSIONBUILDER_H
#include <vector>
#include <iostream>
#include "Builder.h"
using namespace std;
class ExpBuilder: public Builder{
protected:
    vector<string> expStack;
public:
    virtual void addcomma(){
        expStack.push_back(",");
    };
    virtual void addother(string other){
        expStack.push_back(other);
    }
    virtual void printExpression(){
        ofstream myfile;
        myfile.open ("Checkout.csv");
        for(int i=0;i<expStack.size();i++){
            myfile << expStack[i];
        }
        myfile.close();
    };
};
#endif /* EXPRESSIONBUILDER_H */
