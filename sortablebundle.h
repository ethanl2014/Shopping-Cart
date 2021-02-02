#ifndef SORTABLEBUNDLE_H
#define SORTABLEBUNDLE_H
#include<vector>
#include"bundle.h"
#include "sortablevector.h"
using namespace std;

class BundleDatabaseSortable: public SortableVector{
protected:
    vector<Bundle*> m_Bundles;
    BundleDatabaseSortable(){};
public:
    BundleDatabaseSortable(vector<Bundle*> bundles){
        m_Bundles = bundles;
    }
    BundleDatabaseSortable(const BundleDatabaseSortable& other) = default;
    BundleDatabaseSortable& operator=(const BundleDatabaseSortable& other) = default;
    virtual ~BundleDatabaseSortable() = default;
    virtual unsigned int getSize() const override{
        return m_Bundles.size();
    }

    virtual bool smaller(int i, int j) const override{
        return true;
    }
    virtual void swap(int i, int j) override{
        Bundle* temp = m_Bundles[i];
        m_Bundles[i]=m_Bundles[j];
        m_Bundles[j]=temp;
    }
    virtual void DisplayRecords(QTableWidget* table){
        for(Bundle* p : m_Bundles){
            p->print(table);
            //cout << p->getName();
        }
    }
    Bundle* AnotherFunction(int i){
        return m_Bundles[i];
    }
};


#endif /* PETDATABASESORTABLE_H */
