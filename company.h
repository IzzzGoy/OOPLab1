#ifndef COMPANY_H
#define COMPANY_H
#include "person.h"
#include "vector"
#include "person.h"
#include "string"
#include "iostream"
#include "iomanip"

class Person;

struct CandidateInfo
{
    bool companyAgree = false;
    Person* candidate;
    CandidateInfo(Person* person, bool agree = false)
    {
        candidate = person;
        companyAgree = agree;
    }
};

class Company
{
public:
    Company();

    Person* searchForPerson(std::string name);
    bool recrutingPerson(Person* person);
    bool isPerson(std::string name);
    bool personSackFromCompany(Person* person);
    bool companyAgree(Person* person);
    bool chekPersonsStatus(Person* person);

    void showCompanyInfo();

private:
    CandidateInfo* isHeCandidate(Person* person);
    std::vector<Person*> persons;
    std::vector<CandidateInfo*> candidates;
};

#endif // COMPANY_H
