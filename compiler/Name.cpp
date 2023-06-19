//
// Created by vasiliy on 02/06/2023.
//

#include "Name.h"

Name::Name(std::string name, int position) : name(name), position(position) {}

Name::Name(const std::string &name, int position, bool initialized) : name(name), position(position),
                                                                      initialized(initialized) {}

const std::string Name::getName() const {
    return name;
}

void Name::setName(const std::string &name) {
    this->name = name;
}

int Name::getPosition() const {
    return position;
}

void Name::setPosition(int position) {
    this->position = position;
}

bool Name::isInitialized() const {
    return initialized;
}

void Name::setInitialized(bool initialized) {
    Name::initialized = initialized;
}

