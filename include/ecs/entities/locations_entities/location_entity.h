//
// Created by vydra on 15.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_LOCATION_ENTITY_H
#define RE_TESROUGEFALKREATH_LOCATION_ENTITY_H

#include "ecs/entities/area_entity.h"
#include "ecs/entities/creatures_entities/creatures_entity.h"

class location_entity {
private:
    const char *name;
    unsigned size_x;
    unsigned size_y;

    area_entity *current_area;
    creatures_entity *current_creatures;

public:
    explicit location_entity(const char *input_name, area_entity *input_area, creatures_entity *input_creatures) {
        name = input_name;
        size_x = input_area->get_size_x();
        size_y = input_area->get_size_y();
        current_area = input_area;
        current_creatures = input_creatures;
    }

    location_entity(location_entity &input_location) {
        name = input_location.name;
        size_x = input_location.size_x;
        size_y = input_location.size_y;
        current_area = new area_entity(*input_location.current_area);
        current_creatures = new creatures_entity(*input_location.current_creatures);
    }

    location_entity(location_entity &&input_location) noexcept {
        name = input_location.name;
        size_x = input_location.size_x;
        size_y = input_location.size_y;
        current_area = input_location.current_area;
        current_creatures = input_location.current_creatures;
        input_location.current_area = nullptr;
        input_location.current_creatures = nullptr;
    }

    ~location_entity() {
        delete current_area;
        delete current_creatures;
    }

    location_entity &operator=(location_entity &input_location) {
        name = input_location.name;
        size_x = input_location.size_x;
        size_y = input_location.size_y;
        current_area = new area_entity(*input_location.current_area);
        current_creatures = new creatures_entity(*input_location.current_creatures);
        return *this;
    }

    location_entity &operator=(location_entity &&input_location) noexcept {
        name = input_location.name;
        size_x = input_location.size_x;
        size_y = input_location.size_y;
        current_area = input_location.current_area;
        current_creatures = input_location.current_creatures;
        input_location.current_area = nullptr;
        input_location.current_creatures = nullptr;
        return *this;
    }

    const char *get_name() const;
    unsigned int get_size_x() const;
    unsigned int get_size_y() const;
    area_entity *get_current_area() const;
    creatures_entity *get_current_creatures() const;

    void set_name(const char *input_name);
    void set_size_x(unsigned int input_x);
    void set_size_y(unsigned int input_y);
    void set_current_area(area_entity *input_area);
    void set_current_creatures(creatures_entity *input_creatures);


};


#endif //RE_TESROUGEFALKREATH_LOCATION_ENTITY_H
