/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** function returning the content of a file as a string
*/

#include <iostream>
#include <fstream>
#include <string>

std::string openFile(char *file_path)
{
    std::string content;
    std::string line;
    std::ifstream myfile(file_path);

    if (myfile.is_open()) {
        while (getline(myfile, line))
            content += line += '\n';
        myfile.close();
    }
    else
        return (NULL);
    return (content);
}
