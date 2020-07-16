//
// Created by vydra on 15.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_LOCATION_ENTITY_H
#define RE_TESROUGEFALKREATH_LOCATION_ENTITY_H

#include "ecs/entities/area_entity.h"

class location_entity {
private:
    const char *name;
    unsigned size_x;
    unsigned size_y;

    area_entity *current_area;

public:
    explicit location_entity(const char *input_name, area_entity *input_area) {
        name = input_name;
        size_x = input_area->get_size_x();
        size_y = input_area->get_size_y();
        current_area = input_area;
    }

    location_entity(location_entity &input_location) {
        name = input_location.name;
        size_x = input_location.size_x;
        size_y = input_location.size_y;
        current_area = new area_entity(*input_location.current_area);
    }

    location_entity(location_entity &&input_location) noexcept {
        name = input_location.name;
        size_x = input_location.size_x;
        size_y = input_location.size_y;
        current_area = input_location.current_area;
        input_location.current_area = nullptr;
    }

    ~location_entity() {
        delete current_area;
    }

    location_entity &operator=(location_entity &input_location) {
        name = input_location.name;
        size_x = input_location.size_x;
        size_y = input_location.size_y;
        current_area = new area_entity(*input_location.current_area);
        return *this;
    }

    location_entity &operator=(location_entity &&input_location) noexcept {
        name = input_location.name;
        size_x = input_location.size_x;
        size_y = input_location.size_y;
        current_area = input_location.current_area;
        input_location.current_area = nullptr;
        return *this;
    }

};


#endif //RE_TESROUGEFALKREATH_LOCATION_ENTITY_H
