#ifndef BUBBLESORTTEMPLATE_H
#define BUBBLESORTTEMPLATE_H
#include"sortablevector.h"

class BubbleSortTemplate{
public:
    void sort(SortableVector* sortableVector){
        bool sorted = false;
        int n=sortableVector->getSize();
        while( !sorted ){
            sorted = true;
            for(int i=1; i<n; i++){
                if(needSwap(sortableVector, i-1, i)){
                    sortableVector->swap(i-1,i);
                    sorted = false;
                }
            }
            n--;
        }
    }

    virtual bool needSwap(SortableVector* sv, int i, int j)const = 0;
};

#endif /* BUBBLESORTTEMPLATE_H */
