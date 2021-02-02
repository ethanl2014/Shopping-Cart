#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <iostream>
#include "Builder.h"

class ExpParser{
protected:
    Builder* m_expBuilder;
public:
    void setBuilder(ExpBuilder* builder){
        m_expBuilder=builder;
    }

    void parse(string exp){
        string test;
        for(int i=0; i<exp.size(); i++){
            test = exp[i];
            switch(exp[i]){
                case ',':
                    m_expBuilder->addcomma();
                    break;
                default:
                    m_expBuilder->addother(test);
                    break;
            }
        }
    }
};

#endif /* PARSER_H */

