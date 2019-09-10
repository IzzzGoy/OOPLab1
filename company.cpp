#include "company.h"

Company::Company()
{
    persons.resize(0);
}

bool Company::recruting(Person *person)
{
    for(size_t i = 0; i < persons.size(); i++)
    {
        if(persons[i]->getName() == person->getName())
        {
            return false;
        }
    }
    if(person->tryToRecruting())
    {
        persons.push_back(person);
        return true;
    }
    else
    {
        return false;
    }
}

Person* Company::searchForPerson(std::string name)
{
    for(size_t i = 0; i < persons.size(); i++)
    {
        if(persons[i]->getName() == name)
        {
            return persons[i];
        }
    }
    return nullptr;
}

bool Company::isPerson(std::string name)
{
    for(size_t i = 0; i < persons.size(); i++)
    {
        if(persons[i]->getName() == name)
        {
            return true;
        }
    }
    return false;
}

bool Company::sack(std::string name)
{
    for(size_t i = 0; i < persons.size(); i++)
    {
        if(persons[i]->getName() == name)
        {
            persons.erase(persons.begin() + i);
            return true;
        }
    }
    return false;
}
