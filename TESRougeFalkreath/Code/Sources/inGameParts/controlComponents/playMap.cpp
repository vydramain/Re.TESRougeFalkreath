#include "inGameParts/controlComponents/playMap.cpp"

playMap::playMap(){
    ph= NULL;
    pb= NULL;
    countX_= 0;
    countY_= 0;
    errorcode= 0;
}

bool playMap::newKnot1(){
    if(errorcode == 0){
        if(ph != NULL){
            pb = ph;
            while(pb->next1 != NULL){
                pb = pb->next1;
            }
            pknot p = new knot();
            p->next1 = NULL;
            p->next2 = NULL;
            pb->next1 = p;
        } else{
            pknot p = new knot();
            p->next1 = NULL;
            p->next2 = NULL;
            ph = p;
        }
        return 0;
    }else{
        return 1;
    }
}

bool playMap::newKnot2(unsigned Y){
    if(errorcode == 0 && Y < countY_){
        if(ph != NULL){
            pb = ph;
            for(unsigned i(0); i < Y; i ++){
                pb= pb->next1;
            }
            while(pb->next2 != NULL){
                pb = pb->next2;
            }
            pknot p = new knot();
            p->next1= NULL;
            p->next2= NULL;
            pb-next2 = p;
        } else{
            pknot p = new knot();
            p->next1 = NULL;
            p->next2 = NULL;
            ph = p;            
        }
        return 0;
    } else{
        return 1;
    }
}

playMap::playMap(unsigned X, unsigned Y){
    countX_ = X;
    countY_ = Y;
    ph = NULL;
    for (unsigned i(0); i < countY_; i++){
        newKnot1();
    }
    for (unsigned i(0); i < countY_; i++){
        for (unsigned ii(0); ii < countX_; ii++){
            newKnot2(i);
        }
    }
}

playMap::~playMap(){
    for (unsigned i(0); i < countY_; i++){
        for (unsigned ii(0); ii < countX_; ii++){
            pb=ph;
            while(pb->next1 != NULL){
                pb= pb->next1;
            }
            while(pb->next2 != NULL){
                pb = pb->next2;
            }
            delete pb;
        }
    }
    ph= NULL;
}
    

        
        
        
            
