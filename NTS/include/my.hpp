/*
** EPITECHw PROJECT, 2022
** NanoTekSpice
** File description:
** Bunch of usefull functions
*/

#ifndef MY_HPP
#define MY_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <utility>
#include <memory>
#include "IComponent.hpp"

//PARSING THE FILE
//& SEND TO TWO VECTOR STORED IN STRUCT::INSTRUCTIONS_S
std::string openFile(char *file);
char **str_to_word_array(char *input);
struct instructions_s *parser(std::string contentFile);

//STRUCTS
typedef struct instructions_s
{
    std::vector<std::string> chipsets;
    std::vector<std::string> links;
} instru_t;

//LINKED-LISTS CONSTRUCTION
typedef struct chipsetList_s
{
    char *chipset;
    struct chipsetList_s *next;
} chipsetList_t;

typedef struct linksList_s
{
    char *link;
    struct linksList_s *next;
} linksList_t;

std::list<std::string> chipsetTbToList(instru_t *allInstructions);
std::vector<std::string> linksTbToList(instru_t *allInstructions);

//CREATE COMPONENTS FROM THE TWO LISTS

std::vector<std::shared_ptr<nts::IComponent>> createComponent(std::list<std::string> chipsets, std::vector<std::string> links);

//FUNCTIONS TOOLS FOR THE PROJECT
//(PARSING)
std::string giveChipsetType(std::string str);
std::string giveChipsetName(std::string str);

std::string giveBefore(std::string str, char a);
std::string giveAfter(std::string str, char a);
//return the value of the pin
int givefirstPin(std::string str);
int giveScondPin(std::string str);

//////////////////////////////////// CORE ////////////////////////////////////

void display(std::vector<std::shared_ptr<nts::IComponent>> AllChipset, int tick);

#endif
