//Author: Ethan Lee (leeethan)
//Author: Cameron Lozier (lozierca)
#ifndef FISH_H
#define FISH_H
#include"pet.h"

class Fish: public Pet{
protected:
    string m_habitat;
public:
    Fish(string name, string type, double price, unsigned int weight, string habitat, string s_class):
    Pet(name,type,price,weight,s_class), m_habitat(habitat){}

    string getUnique()const{
        return m_habitat;
    }
};
#endif /* FISH_H */
