#ifndef PETDATABASESORTABLE_H
#define PETDATABASESORTABLE_H
#include<vector>
#include"pet.h"
#include "sortablevector.h"
using namespace std;

class PetDatabaseSortable: public SortableVector{
protected:
    vector<Pet*> m_Pets;
    PetDatabaseSortable(){};
public:
    PetDatabaseSortable(vector<Pet*> pets){
        m_Pets = pets;
    }
    PetDatabaseSortable(const PetDatabaseSortable& other) = default;
    PetDatabaseSortable& operator=(const PetDatabaseSortable& other) = default;
    virtual ~PetDatabaseSortable() = default;
    virtual unsigned int getSize() const override{
        return m_Pets.size();
    }

    virtual bool smaller(int i, int j) const override{
        return true;
    }
    virtual void swap(int i, int j) override{
        Pet* temp = m_Pets[i];
        m_Pets[i]=m_Pets[j];
        m_Pets[j]=temp;
    }
    virtual void DisplayRecords(QTableWidget* table){
        for(Pet* p : m_Pets){
            p->print(table);
            //cout << p->getName();
        }
    }
    Pet* AnotherFunction(int i){
        return m_Pets[i];
    }
};


#endif /* PETDATABASESORTABLE_H */
