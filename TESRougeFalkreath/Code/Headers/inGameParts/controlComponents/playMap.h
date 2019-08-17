#ifndef PLAYMAP_H_INCLUDED
#define PLAYMAP_H_INCLUDED

class playMap{
private:
    struct knot{
        char* layer0;   // Карта
        char* layer1;   // Предмет
        char* layer2;   // Непись
        char* layer3;   // Игрок
        knot* next1;
        knot* next2;

        knot(){
            layer0= new char[ ];
            layer1= new char[ ];
            layer2= new char[ ];
            layer3= new char[ ];
        }
        ~knot(){
            delete layer0;
            delete layer1;
            delete layer2;
            delete layer3;
        }
        };  typedef knot* pKnot;
    unsigned countX_;
    unsigned countY_;
    pknot ph;  // голова
    pknot pb;  // бегунок

    unsigned errorcode;

    bool newKnot1();  // Создаёт в конце линейки первого уровня ещё один узел
    bool newKnot2(unsigned);  // Создаёт в конце линейки второго уроня, заданного положения первого уровня ещё один узел

public:
    playMap();
    playMap(unsigned, unsigned);

    ~playMap();
