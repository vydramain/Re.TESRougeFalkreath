//
// Created by vydra on 7/31/20.
//

#ifndef RE_TESROUGEFALKREATH_MLCONTROLMAP_H
#define RE_TESROUGEFALKREATH_MLCONTROLMAP_H

#include <map>
#include "MLControlExit.h"
#include "MLControlEmpty.h"
#include "MLControlAdventure.h"


class MLControlMap {
private:
    MLControlExit *control_exit = new MLControlExit;
    MLControlEmpty *control_empty = new MLControlEmpty();
    MLControlAdventure *control_adventure;

    std::map <const char*, IMLControl*> ml_map;
    std::map <const char*, IMLControl*> :: iterator ml_iterator;

    IMLControl *last_control = nullptr;

public:
    MLControlMap(Location *input_location) {
        control_adventure = new MLControlAdventure(input_location);

        ml_map["MLAControlExit"] = control_exit;
    }

    ~MLControlMap(){
        delete control_adventure;
    }

    IMLControl* get_start_control() {
        last_control = control_adventure;
        return control_adventure;
    }

    IMLControl* get_control(IControl* input_control) {
        ml_iterator = ml_map.find(input_control->get_name());
        if (ml_iterator == ml_map.end()) {
            return last_control;
        }
        last_control = ml_iterator->second;
        return ml_iterator->second;
    }
};


#endif //RE_TESROUGEFALKREATH_MLCONTROLMAP_H
