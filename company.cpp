#include "company.h"
#include "company.h"

Company::Company()
{

}

bool Company::recrutingPerson(Person *person)
{
    CandidateInfo* thisPerson = isHeCandidate(person);
    if(thisPerson != nullptr )
    {
        if(thisPerson->companyAgree == false)
        {
            thisPerson->companyAgree = true;
            person->tryToRecruting(this);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        candidates.push_back(new CandidateInfo(person,true));
        person->checkProposal(this);
    }
    if(isHeCandidate(person) != nullptr)
    {
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

bool Company::personSackFromCompany(Person* person)
{
    for(size_t i = 0; i < persons.size(); i++)
    {
        if(persons[i] == person)
        {
            person->tryToSack(this);
            persons.erase(persons.begin() + i);
            return true;
        }
    }
    return false;
}

bool Company::companyAgree(Person *person)
{
    CandidateInfo* thisPerson = isHeCandidate(person);
    if(thisPerson != nullptr)
    {
        if(thisPerson->companyAgree == false)
        {
            thisPerson->companyAgree = true;
            if(person->tryToRecruting(this))return true;
            else return false;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Company::chekPersonsStatus(Person *person)
{
    CandidateInfo* thisPerson = isHeCandidate(person);
    if( thisPerson != nullptr)
    {
        if(thisPerson->companyAgree == true)
        {
            persons.push_back(person);
            for(size_t i = 0; i < candidates.size(); i++)
            {
                if(candidates[i]->candidate == person)
                {
                    candidates.erase(candidates.begin() + i);
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        candidates.push_back(new CandidateInfo(person));
        return false;
    }
}

void Company::showCompanyInfo()
{
    std::cout << "Worckers:\n";
    for(size_t i = 0; i < persons.size(); i++)
    {
        std::cout << i + 1 + ". ";
        persons[i]->showPersonInfo(this);
    }
    std::cout << "Candidates:\n";
    for(size_t i = 0; i < candidates.size(); i++)
    {
        std::cout << i + 1 + ". ";
        candidates[i]->candidate->showPersonInfo(this);
    }
}

CandidateInfo *Company::isHeCandidate(Person *person)
{
    for(size_t i = 0; i < candidates.size(); i++)
    {
        if(candidates[i]->candidate == person) return candidates[i];
    }
    return nullptr;
}
