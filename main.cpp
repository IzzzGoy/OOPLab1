#include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <company.h>
#include <vector>

int main()
{
    ////////////////////////////////////////////////
    std::ofstream output("LabLog.txt");
    std::vector<Person*> candidates(6);
    std::vector<Company*> companis(6);
    /////////////////////////////////////////////
    if(!output.is_open())
    {
        std::cout << "trouble with file!" << std::endl;
        return -1;
    }
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

    //Проверка возможноможности найма
    if(companis[0]->recruting(candidates[0]))
    {
        output << "Recruting was sucsesful!\n";
    }
    else
    {
        output << "Truoble with recruting\n";
    }

    //Проверка того, что один работник не может быть задействован в более чем 5ти компаниях
    companis[1]->recruting(candidates[0]);
    companis[2]->recruting(candidates[0]);
    companis[3]->recruting(candidates[0]);
    companis[4]->recruting(candidates[0]);
    if(companis[5]->recruting(candidates[0]))
    {
        output << "Wrong nuber of companis\n";
    }
    else
    {
        output << "Reached limit of companis\n";
    }

    //Проверка возможности проверить, работает ли сотрудник
    if(companis[0]->isPerson(candidates[0]->getName()))
    {
        output << "We can find him\n";
    }
    else
    {
        output << "Truble with searching\n";
    }

    //Проверка возможности нахождения сотрудника по ФИО
    if(companis[0]->searchForPerson(candidates[0]->getName()) == candidates[0])
    {
        output << "This is that person\n";
    }
    else
    {
        output << "We can`t retern him\n";
    }

    //Проверка возможности увольнения сотрудника
    if(companis[0]->sack(candidates[0]->getName()))
    {
        output << "Person was sacked\n";
    }
    else
    {
        output << "Error with sackking\n";
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
    output.close();
    return 0;
}
