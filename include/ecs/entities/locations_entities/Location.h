//
// Created by vydra on 15.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_LOCATION_H
#define RE_TESROUGEFALKREATH_LOCATION_H

#include "ecs/entities/Map.h"
#include "ecs/entities/creatures_entities/Creatures.h"

class Location {
private:
    const char *name;
    const unsigned size_x;
    const unsigned size_y;

    Map *current_area;
    Creatures *current_creatures;

public:
    explicit Location(const char *input_name, Map *input_area, Creatures *input_creatures);
    ~Location();

    const char *get_name() const;
    unsigned int get_size_x() const;
    unsigned int get_size_y() const;
    Map *get_current_area() const;
    Creatures *get_current_creatures() const;

    void set_name(const char *input_name);
    void set_current_area(Map *input_area);
    void set_current_creatures(Creatures *input_creatures);
};


#endif //RE_TESROUGEFALKREATH_LOCATION_H
