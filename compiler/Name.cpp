//
// Created by vasiliy on 02/06/2023.
//

#include "Name.h"

Name::Name(std::string name, int position) : name(name), position(position) {}

const std::string &Name::getName() const {
    return name;
}

void Name::setName(const std::string &name) {
    Name::name = name;
}

int Name::getPosition() const {
    return position;
}

void Name::setPosition(int position) {
    Name::position = position;
}
