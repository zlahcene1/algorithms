/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** functions to parse the content of the file passed as parameter, from a string to array
*/

#include "my.hpp"
#include <cstring>

enum
{
    CHIPSET_INSTRUCTIONS,
    LINKS_INSTRUCTIONS
};

static int lengthOfInstructions(char **allInstructions, int instructions)
{
    int len = 0;
    int idx = 0;

    for (; allInstructions[idx]; idx++)
        if (strcmp(".chipsets:", allInstructions[idx]) == 0)
            for (int i = (idx + 1); allInstructions[i] && strcmp(".links:", allInstructions[i]) != 0 && strlen(allInstructions[i]) > 1; i++, len++)
                ;
    if (instructions == CHIPSET_INSTRUCTIONS)
    {
        return (len);
    }
    len = 0;
    if (instructions == LINKS_INSTRUCTIONS)
        for (idx = 0; allInstructions[idx]; idx++)
            if (strcmp(".links:", allInstructions[idx]) == 0)
                for (int i = idx; allInstructions[i] && strcmp(".chipsets:", allInstructions[i]) != 0 && strlen(allInstructions[i]) > 1; i++, len++)
                    ;
    return (len);
}

static std::vector<std::string> chipsetToArray(char **allInstructions)
{
    int i = 0;
    std::vector<std::string> chipset;

    for (i = 1; strcmp(".chipsets:", allInstructions[i - 1]) != 0 && allInstructions[i]; i++)
        ;
    for (; allInstructions[i] && strcmp(allInstructions[i], "") != 0; i++)
        chipset.push_back(allInstructions[i]);
    return (chipset);
}

static std::vector<std::string> linksToArray(char **allInstructions)
{
    int i = 0;
    std::vector<std::string> links;

    for (i = 0; allInstructions[i] && strcmp(".links:", allInstructions[i]) != 0; i++)
        ;
    i++;
    for (; allInstructions[i] && strcmp(allInstructions[i], ""); i++)
        links.push_back(allInstructions[i]);
    return (links);
}

struct instructions_s *parser(std::string contentFile)
{
    char *content = strdup(contentFile.c_str());
    char **allContent = str_to_word_array(content);
    instru_t *Allinstructions = new (instru_t);

    Allinstructions->chipsets = chipsetToArray(allContent);
    Allinstructions->links = linksToArray(allContent);
    return (Allinstructions);
}
