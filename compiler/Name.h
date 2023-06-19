//
// Created by vasiliy on 02/06/2023.
//

#ifndef PLD_COMP_NAME_H
#define PLD_COMP_NAME_H


#include <string>

class Name {
public:
    Name(const std::string name, int position);

    Name(const std::string &name, int position, bool initialized);

    const std::string getName() const;

    void setName(const std::string &name);

    int getPosition() const;

    void setPosition(int position);

    bool isInitialized() const;

    void setInitialized(bool initialized);

private:
    std::string name;
    int position;
    bool initialized = false;
};


#endif //PLD_COMP_NAME_H
