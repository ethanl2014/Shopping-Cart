#ifndef BUILDER_H
#define BUILDER_H
#include <string>

class Builder{
public:
    virtual void addcomma()=0;
    virtual void addother(std::string other)=0;
    virtual void printExpression()=0;
};


#endif /* BUILDER_H */

