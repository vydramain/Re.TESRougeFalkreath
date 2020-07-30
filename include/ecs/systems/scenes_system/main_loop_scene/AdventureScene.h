//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_ADVETURESCENE_H
#define RE_TESROUGEFALKREATH_ADVETURESCENE_H

#include <ecs/systems/scenes_system/IScene.h>
#include <ecs/systems/controls_system/Controls.h>
#include <ecs/entities/locations_entities/Location.h>
#include <ecs/systems/controls_system/loop_controls/main_loop_adventure_scene_controls/MLASControls.h>

class AdventureScene : public IScene {
private:
    Location *location;
    MLASControls *mlas_input;
    IControl *last_control = nullptr;

public:
    explicit AdventureScene(Location *input_location) : IScene("AdventureScene"),
                                                                         location(input_location),
                                                                         mlas_input(new MLASControls(input_location->get_current_creatures()->get_creature(0))) {}

    ~AdventureScene() {
        location = nullptr;
        delete mlas_input;
    }

    IControl *get_last_control() {
        return last_control;
    }

    void run();
};

#endif //RE_TESROUGEFALKREATH_ADVETURESCENE_H
