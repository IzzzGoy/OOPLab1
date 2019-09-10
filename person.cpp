#include "person.h"

Person::Person(std::string name)
{
    Ncompanis = 0;
    this->name = name;
}

Person::~Person()
{

}

bool Person::tryToRecruting()
{
    if(Ncompanis == 5)
    {
        return false;
    }else
    {
        Ncompanis++;
        return true;
    }
}

std::string Person::getName()
{
    return name;
}
