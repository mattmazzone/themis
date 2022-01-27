#include "htmlManip.h"




HtmlGenerator::HtmlGenerator(std::string path, std::vector<std::string> formattedFile){
    outputPath = path;
    this->formattedFile = formattedFile;
    
    //Create file with same name but .html extension
    outputPath.replace(outputPath.end()-4,outputPath.end(),".html");
}

void HtmlGenerator::addHeadHtml() {

    buffer << R"_(<!DOCTYPE html>
<html lang=" en ">
<head>
  <title>Hello, world!</title>
  <meta charset=" UTF - 8 " />
  <meta name=" viewport " content=" width = device - width, initial - scale = 1 " />
  <meta name=" description " content=" " />
</head>
<body>)_" << std::endl;



}



void HtmlGenerator::addPreparationHtml(){
    

    std::vector<std::string> prepStrings;
    

    std::string input;
    
    size_t foundPrep;
    size_t foundPrep1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    prepStrings.push_back(input);
                    //*buff << input << std::endl;
            }
            else {
                inSection = false;
                
            }
        }
            else {
                //Remove Whitespace from string
                input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
            }

        foundPrep = input.find("<<PREPARATION>>");
        foundPrep1 = input.find("<<PRÉPARATION>>");

        if ((foundPrep != std::string::npos) || (foundPrep1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }

//Test function
/*
std::cout << "Preparation (in array):" << std::endl;
    //Check if strings are on right lineCounter
    if (prepStrings.size()==0){
        std::cout << "EMPTY" << std::endl;
    }
    for (auto i: prepStrings){
        std::cout << i << std::endl;
    }
*/
}


void HtmlGenerator::addPiecesHtml()
{

    std::vector<std::string> piecesStrings;
    

    std::string input;
    
    size_t foundPieces;
    size_t foundPieces1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    piecesStrings.push_back(input);
                    //*buff << input << std::endl;
            }
            else {
                inSection = false;
                
            }
        }
            else {
                //Remove Whitespace from string
                input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
            }

        foundPieces = input.find("<<PIECES>>");
        foundPieces1 = input.find("<<PIÈCES>>");

        if ((foundPieces != std::string::npos) || (foundPieces1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }

//Test function

std::cout << "PIÈCES (in array):" << std::endl;
    //Check if strings are on right lineCounter
    if (piecesStrings.size()==0){
        std::cout << "EMPTY" << std::endl;
    }
    for (auto i: piecesStrings){
        std::cout << i << std::endl;
    }

}


void HtmlGenerator::addConsommablesHtml() {
    
    std::vector<std::string> consomStrings;

    std::string input;
    
    size_t foundConsom;
    size_t foundConsom1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    consomStrings.push_back(input);
                    //*buff << input << std::endl;
            }
            else {
                inSection = false;
                
            }
        }
            else {
                //Remove Whitespace from string
                input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
            }

        foundConsom = input.find("<<CONSOMMABLES>>");
        foundConsom1 = input.find("<<CONSOMMABLE>>");

        if ((foundConsom != std::string::npos) || (foundConsom1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }

//Test function

std::cout << "CONSOM (in array):" << std::endl;
    //Check if strings are on right lineCounter
    if (consomStrings.size()==0){
        std::cout << "EMPTY" << std::endl;
    }
    for (auto i: consomStrings){
        std::cout << i << std::endl;
    }

}


//void outilsHtml(std::stringstream * buff)


//void pagebreakHtml(std::stringstream * buff)


//void checklistHtml(std::stringstream * buff)


//void risquesHtml(std::stringstream * buff)


//void securiteHtml(std::stringstream * buff)


//void tachesHtml(std::stringstream * buff)


//void finmaintenanceHtml(std::stringstream * buff)


//void notesHtml(std::stringstream * buff)

//void badgeHtml(std::stringstream * buff)


//void buttonHtml(std::stringstream * buff)


//void page1toBuffer(std::stringstream * buff)





void HtmlGenerator::writeBuffertohtml() {

//Write buffer to created file
    std::ofstream outFile(outputPath);
    if (outFile.is_open()) {

        outFile << buffer.rdbuf();

        outFile.close();
    }
    else {
        std::cout << "Unable to open file";
    }


}