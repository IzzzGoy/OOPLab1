#include "person.h"

Person::Person(std::string name)
{
    Ncompanis = 0;
    this->name = name;
    companis.resize(0);
}

Person::~Person()
{

}

bool Person::tryToRecruting(Company* company) //false - не смог попасть в компанию. true - смог.
{
    if(Ncompanis == 5)
    {
        return false;
    }else
    {
        if(company->chekPersonsStatus(this) == false)
        {
            for(size_t i = 0; i < companis.size(); i++)
            {
                if(companis[i]->company == company)return true;
            }
            companis.push_back(new CompanyInfo(company));
            return true;
        }
        else
        {
            companis.push_back(new CompanyInfo(company,true));
            Ncompanis++;
            return true;
        }
    }
}

void Person::tryToSack(Company *company)
{
    for(size_t i = 0; i < companis.size(); i++)
    {
        if(companis[i]->company == company)
        {
            companis.erase(companis.begin() + i);
            Ncompanis--;
        }
    }
}

bool Person::agreeToRecruting(Company *company)
{
    for(size_t i = 0; i < companis.size(); i++)
    {
        if((companis[i]->company == company) && companis[i]->isProposed)
        {
            if(tryToRecruting(company) == false)
            {
                companis.erase(companis.begin() + i);
                return false;
            }
            else
            {
                return true;
            }
        }

    }
    return false;
}

std::string Person::getName()
{
    return name;
}

bool Person::checkProposal(Company *company)
{
    for(size_t i = 0; i < companis.size(); i++)
    {
        if(companis[i]->company == company)
        {
            companis[i]->isProposed = true;
            return true;
        }
    }
    companis.push_back(new CompanyInfo(company));
    companis[companis.size() - 1]->isProposed = true;
    return true;
}

void Person::showPersonInfo(Company* company)
{
    for(size_t i = 0; i < companis.size(); i++)
    {
        if(companis[i]->company == company)
        {
            std::cout << name;
            std::cout << " Worck status: " << std::boolalpha << companis[i]->isWorcking;
            std::cout << " Was proposed: " << std::boolalpha << companis[i]->isProposed;
            std::cout << " " << std::endl;
        }
    }
}

