#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctype.h>
#include <vector>

#include "htmlManip.h"

#include "textTransforms.h"




void headHtml(std::stringstream *buffer) {


    *buffer << R"_(<!DOCTYPE html>
<html lang=" en ">
<head>
  <title>Hello, world!</title>
  <meta charset=" UTF - 8 " />
  <meta name=" viewport " content=" width = device - width, initial - scale = 1 " />
  <meta name=" description " content=" " />
</head>
<body>)_" << std::endl;

}

void preparationHtml(std::stringstream * buff)
{

    std::vector<std::string> prepStrings;

    std::string input;
    int lineCounter = 1;
    size_t foundPrep;
    size_t foundPrep1;
    size_t foundEnd;

    bool inSection = false;



    std::ifstream inFile("example.txt");
    if (inFile.is_open()) {

        while (getline(inFile, input)) {


            if (inSection) {
                foundEnd = input.find("<<");

                if (foundEnd == std::string::npos) {
                    prepStrings.push_back(input);
                    //*buff << input << std::endl;


                }
                else {
                    inSection = false;
                    inFile.close();
                }
            }
            else {
                input = removeWhitespace(input);

            }

            foundPrep = input.find("<<PREPARATION>>");
            foundPrep1 = input.find("<<PRÉPARATION>>");

            if ((foundPrep != std::string::npos) || (foundPrep1 != std::string::npos)) {
                //Found Prepartion (next line until << is good
                inSection = true;


            }


            lineCounter++;
        }
        inFile.close();
    }
    else {
        std::cout << "Unable to open file";
    }

    //Check if strings are on right lineCounter
    //for (auto i: prepStrings)
        //std::cout << i << std::endl;






}

void piecesHtml(std::stringstream * buff)
{
}

void consommablesHtml(std::stringstream * buff)
{
}

void outilsHtml(std::stringstream * buff)
{
}

void pagebreakHtml(std::stringstream * buff)
{
}

void checklistHtml(std::stringstream * buff)
{
}

void risquesHtml(std::stringstream * buff)
{
}

void securiteHtml(std::stringstream * buff)
{
}

void tachesHtml(std::stringstream * buff)
{
}

void finmaintenanceHtml(std::stringstream * buff)
{
}

void notesHtml(std::stringstream * buff)
{
}

void badgeHtml(std::stringstream * buff)
{
}

void buttonHtml(std::stringstream * buff)
{
}

void page1toBuffer(std::stringstream * buff)
{

}




void writeBuffertohtml(std::stringstream *buffer) {

    std::ofstream outFile("output.html");
    if (outFile.is_open()) {

        outFile << buffer->rdbuf();

        outFile.close();
    }
    else {
        std::cout << "Unable to open file";
    }

}