#ifndef COMPANY_H
#define COMPANY_H
#include "person.h"
#include "vector"

class Company
{
public:
    Company();

    Person* searchForPerson(std::string name);
    bool recruting(Person* person);
    bool isPerson(std::string name);
    bool sack(std::string name);

private:
    std::vector<Person*> persons;
};

#endif // COMPANY_H
