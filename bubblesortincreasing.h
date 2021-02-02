#ifndef BUBBLESORTINCREASING_H
#define BUBBLESORTINCREASING_H
#include "bubblesorttemplate.h"

class BubbleSortIncreasing: public BubbleSortTemplate{
public:
    virtual bool needSwap(SortableVector* sv, int i, int j)const override{
        return !sv->smaller(i,j);
    }

};

#endif /* BUBBLESORTINCREASING_H */

