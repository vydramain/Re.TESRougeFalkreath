//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_ADVETURESCENE_H
#define RE_TESROUGEFALKREATH_ADVETURESCENE_H

#include <ecs/systems/scenes_system/IScene.h>
#include <ecs/systems/controls_system/Controls.h>
#include <ecs/entities/locations_entities/Location.h>

class AdvScene : public IScene {
private:
    Controls *input;
    Location *location;

public:
    explicit AdvScene(Controls* input, Location* input_location) : input(input), location(input_location) {}
    ~AdvScene() {
        location = nullptr;
        input = nullptr;
    }

    void run();
};

#endif //RE_TESROUGEFALKREATH_ADVETURESCENE_H
