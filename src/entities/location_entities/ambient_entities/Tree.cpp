//
// Created by vydra on 8/14/20.
//

#include "entities/location_entities/ambient_entities/Tree.h"

Tree::Tree(unsigned int input_x, unsigned int input_y) :
      Ambient("Tree", "t", 0xff2e8d36, input_x, input_y) {}

Tree::~Tree() = default;
