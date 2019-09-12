#ifndef PERSON_H
#define PERSON_H
#include "company.h"
#include "vector"
#include "string"
#include "iostream"
#include "iomanip"


class Company;

struct CompanyInfo
{
    Company* company;
    bool isWorcking;
    bool isProposed = false;
    CompanyInfo(Company* com, bool worck = false)
    {
        company = com;
        isWorcking = worck;
    }
};

class Person
{
public:
    Person(std::string name);
    ~Person();

    bool tryToRecruting(Company *company);
    void tryToSack(Company* company);
    bool agreeToRecruting(Company* company);
    std::string getName();
    bool checkProposal(Company* company);

    void showPersonInfo(Company *company);

private:
    std::vector<CompanyInfo*> companis;
    uint8_t Ncompanis;
    std::string name;
};

#endif // PERSON_H
