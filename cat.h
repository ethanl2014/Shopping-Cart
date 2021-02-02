//Author: Ethan Lee (leeethan)
//Author: Cameron Lozier (lozierca)
#ifndef CAT_H
#define CAT_H
#include"pet.h"

class Cat: public Pet{
protected:
    bool m_fluffy;
public:
    Cat(string name, string type,  double price,unsigned int weight, bool fluffy, string s_class):
    Pet(name,type,price,weight,s_class), m_fluffy(fluffy){}

    string getUnique()const{
        if(m_fluffy==true)
            return "Fluffy";
        else
            return "Not Fluffy";
    }
};
#endif /* CAT_H */
