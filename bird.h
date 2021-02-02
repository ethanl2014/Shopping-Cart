#ifndef BIRD_H
#define BIRD_H
#include"pet.h"

class Bird: public Pet{
protected:
    bool m_nocturnality;
public:
    Bird(string name, string type, double price, unsigned int weight, bool nocturnality, string s_class):
    Pet(name,type,price,weight,s_class), m_nocturnality(nocturnality){}

    string getUnique()const{
        if(m_nocturnality==true)
            return "Nocturnal";
        else
            return "Diurnal";
    }
};

#endif /* BIRD_H */
