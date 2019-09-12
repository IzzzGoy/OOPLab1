#include <QCoreApplication>
#include <iostream>
#include <company.h>
#include <vector>

int main()
{
    ////////////////////////////////////////////////
    std::vector<Person*> candidates(6);
    std::vector<Company*> companis(6);
    ///////////////////////////////////////////////
    for(uint8_t i = 0; i < 6; i++)
    {
        std::string name;
        std::cout << i+1 <<".";
        getline(std::cin,name);
        candidates[i] = new Person(name);
    }
    for(uint8_t i = 0; i < 6; i++)
    {
        companis[i] = new Company;
    }

    /////////////////////////////////////////////

    //Проверка возможноможности найма /must be true
    if(companis[0]->recrutingPerson(candidates[0]))
    {
        std::cout << "Recruting was sucsesful!\n";
    }
    else
    {
        std::cout << "Truoble with recruting (wrong)\n";
    }

    //Проверка не возможности подтверждения нейма без согласия Person /must be false
    if(companis[0]->recrutingPerson(candidates[0]))
    {
        std::cout << "Recruting fail (wrong)\n";
    }
    else
    {
        std::cout << "Normal reaction!\n";
    }

    //Проверка подтверждения рекрутинга /must be true
    if(candidates[0]->agreeToRecruting(companis[0]))
    {
        std::cout << "He can agree!\n";
    }
    else
    {
        std::cout << "He can`t agree (wrong)\n";
    }

    //Проверка возможности проверить, работает ли сотрудник /must be true
    if(companis[0]->isPerson(candidates[0]->getName()))
    {
        std::cout << "We can find him\n";
    }
    else
    {
        std::cout << "Truble with searching (wrong)\n";
    }

    //Проверка возможности подать заявление /must be true
    if(candidates[1]->tryToRecruting(companis[0]))
    {
        std::cout << "He can try!\n";
    }
    else
    {
        std::cout << "He can`t try (wrong)\n";
    }

    //Проверка невозможности самозачисления, подав доки второй раз /must be false
    if(candidates[1]->tryToRecruting(companis[0]))
    {
        std::cout << "He can cheat!(wrong)\n";
    }
    else
    {
        std::cout << "He can`t cheat! \n";
    }

    //Проверка невозможности самозачисления, пытаясь "согласиться на предложение" /must be false
    if(candidates[1]->agreeToRecruting(companis[0]))
    {
        std::cout << "He can <<agree>>!(wrong)\n";
    }
    else
    {
        std::cout << "He can`t <<agree>>! \n";
    }

    //Проверка возможности нахождения сотрудника по ФИО
    if(companis[0]->searchForPerson(candidates[0]->getName()) == candidates[0])
    {
        std::cout << "This is that person\n";
    }
    else
    {
        std::cout << "We can`t retern him\n";
    }

    //Проверка возможности увольнения сотрудника
    if(companis[0]->personSackFromCompany(candidates[0]))
    {
        std::cout << "Person was sacked\n";
    }
    else
    {
        std::cout << "Error with sackking\n";
    }


    /////////////////////////////////////////////
    std::cout << "Companis:\n";
    for(size_t i = 0; i < companis.size(); i++)
    {
        std::cout << i + 1 + ". ";
        companis[i]->showCompanyInfo();
    }
    /////////////////////////////////////////////
    for(uint8_t i = 0; i < 6; i++)
    {
        delete candidates[i];
    }
    for(uint8_t i = 0; i < 6; i++)
    {
        delete companis[i];
    }
    return 0;
}
