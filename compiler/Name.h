//
// Created by vasiliy on 02/06/2023.
//

#ifndef PLD_COMP_NAME_H
#define PLD_COMP_NAME_H


#include <string>

class Name {
public:
    Name(const std::string name, int position);

    const std::string getName() const;

    void setName(const std::string &name);

    int getPosition() const;

    void setPosition(int position);

private:
    std::string name;
    int position;
};


#endif //PLD_COMP_NAME_H
