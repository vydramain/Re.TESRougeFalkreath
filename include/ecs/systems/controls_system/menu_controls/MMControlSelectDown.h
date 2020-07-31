//
// Created by vydra on 7/31/20.
//

#ifndef RE_TESROUGEFALKREATH_MMCONTROLSELECTDOWN_H
#define RE_TESROUGEFALKREATH_MMCONTROLSELECTDOWN_H

#include <ecs/systems/controls_system/IControl.h>

class MMControlSelectDown : public IControl {
private:
    const unsigned count_choices;
    unsigned *highlighted;

public:
    explicit MMControlSelectDown(const unsigned input_count, unsigned &input_highlighted) : IControl("MMControlSelectDown"), count_choices(input_count) {
        highlighted = &input_highlighted;
    }

    void execute() override {
        if(*highlighted < count_choices) {
            *highlighted += 1;
        }
    }
};

#endif //RE_TESROUGEFALKREATH_MMCONTROLSELECTDOWN_H
