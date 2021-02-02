#ifndef DOG_H
#define DOG_H
#include"pet.h"

class Dog: public Pet{
protected:
    string m_breed;
public:
    Dog(string name, string type,  double price, unsigned int weight,string breed, string s_class):
    Pet(name,type,price,weight,s_class), m_breed(breed){}

    string getUnique()const{
        return m_breed;
    }
};

#endif /* DOG_H */
