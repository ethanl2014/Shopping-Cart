#include "addbutton.h"

void AddButton::add(){
    emit iChanged(this);
}
