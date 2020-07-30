//
// Created by vydra on 7/31/20.
//

#ifndef RE_TESROUGEFALKREATH_MLCONTROLADVENTURE_H
#define RE_TESROUGEFALKREATH_MLCONTROLADVENTURE_H

#include <ecs/systems/scenes_system/IScene.h>
#include "IMLControl.h"

class MLControlAdventure : public IMLControl {
private:
    IControl *last_control = nullptr;
    AdventureScene *scene;

public:
    explicit MLControlAdventure(Location* input_location) : IMLControl("MLControlAdventure"), scene(new AdventureScene(input_location)) {}
    ~MLControlAdventure() {
        delete scene;
    }

    IControl *get_last_control() {
        return last_control;
    }

    void execute() override {
        scene->run();
        last_control = scene->get_last_control();
    }

};

#endif //RE_TESROUGEFALKREATH_MLCONTROLADVENTURE_H
