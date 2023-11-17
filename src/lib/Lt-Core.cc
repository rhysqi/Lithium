
#include "../../include/Lt-Core.hh"

void Lt_Core(Display *Dsp, int _CONS){
    // Software core
    XEvent Xe;
    while (_CONS) {
        XNextEvent(Dsp, &Xe);
        
    }
}

void Lt_Read(){

}

void Lt_Write(){

}


void Lt_Backups(){

}

void Lt_HotKeys(){

}

void Lt_Setting(){

}
