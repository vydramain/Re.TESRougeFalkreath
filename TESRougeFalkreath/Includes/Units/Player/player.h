//
// Created by vydra on 7/15/19.
//

#ifndef TESROUGEFALKREATH_PLAYER_H
#define TESROUGEFALKREATH_PLAYER_H


#include <BearLibTerminal.h>
#include "Includes/inputKey/inputKey.h"


class player {
private:
        char symbol= 'i';
        

        const inputKey InputKey_;
        unsigned x_= 0, y_= 0;

        void Render(){
                terminal_put(x_, y_, symbol);
        }

        void Move(){
            if(InputKey_.IsUp()){y_--;}
            if(InputKey_.IsDown()){y_++;}
            if(InputKey_.IsLeft()){x_--;}
            if(InputKey_.IsRight()){x_++;}

        }

public:
        player(const inputKey &InputKey, unsigned x, unsigned y) : x_(x), y_(y), InputKey_(InputKey) {}

        void Update(){
            Move();
            Render();

        }
};


#endif //TESROUGEFALKREATH_PLAYER_H
