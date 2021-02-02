#ifndef PETDATABASESORTABLEBYNAME_H
#define PETDATABASESORTABLEBYNAME_H
#include"PetDatabaseSortable.h"

class PetDatabaseSortableByName:public PetDatabaseSortable{
public:
    PetDatabaseSortableByName(vector<Pet*> pets):PetDatabaseSortable(pets){}

    virtual bool smaller(int i, int j) const override{
        if(m_Pets[i]->getName() < m_Pets[j]->getName())
            return true;
        else
            return false;
    }
    string GetName (int i){
        return m_Pets[i]->getName();
    }
};

#endif /* PETDATABASESORTABLEBYNAME_H */
