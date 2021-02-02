#ifndef BUNDLEDATABASESORTABLEBYNAME_H
#define BUNDLEDATABASESORTABLEBYNAME_H
#include"sortablebundle.h"

class BundleDatabaseSortableByName:public BundleDatabaseSortable{
public:
    BundleDatabaseSortableByName(vector<Bundle*> bundles):BundleDatabaseSortable(bundles){}

    virtual bool smaller(int i, int j) const override{
        if(m_Bundles[i]->getName() < m_Bundles[j]->getName())
            return true;
        else
            return false;
    }
    string GetName (int i){
        return m_Bundles[i]->getName();
    }
};

#endif /* PETDATABASESORTABLEBYNAME_H */
