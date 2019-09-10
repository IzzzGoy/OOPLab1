#ifndef PERSON_H
#define PERSON_H

#include "vector"
#include "string"

class Person
{
public:
    Person(std::string name);
    ~Person();

    bool tryToRecruting();
    std::string getName();

private:
    uint8_t Ncompanis;
    std::string name;
};

#endif // PERSON_H
