#include "htmlManip.h"




HtmlGenerator::HtmlGenerator(std::string path, std::vector<std::string> formattedFile){
    outputPath = path;
    this->formattedFile = formattedFile;
    
    //Create file with same name but .html extension
    outputPath.replace(outputPath.end()-4,outputPath.end(),".html");
}

void HtmlGenerator::addHeadHtml(bool release) {

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



void HtmlGenerator::addPreparationHtml(bool release){
    

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


//RELEASE VS DEBUG MODE
if (release){
    if (prepStrings.size()!=0){
        std::cout << "Writing Preparation to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Preparation Array content:" << std::endl;
    for (auto i: prepStrings){
        std::cout << i << std::endl;
    }

}

}

void HtmlGenerator::addPiecesHtml(bool release) {

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

//RELEASE VS DEBUG MODE
if (release){
    if (piecesStrings.size()!=0){
        std::cout << "Writing Pieces to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Pieces Array content:" << std::endl;
    for (auto i: piecesStrings){
        std::cout << i << std::endl;
    }

}

}

void HtmlGenerator::addConsommablesHtml(bool release) {
    
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

//RELEASE VS DEBUG MODE
if (release){
    if (consomStrings.size()!=0){
        std::cout << "Writing Consommables to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Consommables Array content:" << std::endl;
    for (auto i: consomStrings){
        std::cout << i << std::endl;
    }

}


}

void HtmlGenerator::addOutilsHtml(bool release){
    std::vector<std::string> outilsStrings;

    std::string input;
    
    size_t foundOutils;
    size_t foundOutils1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    outilsStrings.push_back(input);
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

        foundOutils = input.find("<<OUTILS>>");
        foundOutils1 = input.find("<<OUTIL>>");

        if ((foundOutils != std::string::npos) || (foundOutils1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }

//RELEASE VS DEBUG MODE
if (release){
    if (outilsStrings.size()!=0){
        std::cout << "Writing Outils to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Outils Array content:" << std::endl;
    for (auto i: outilsStrings){
        std::cout << i << std::endl;
    }


}
}

void HtmlGenerator::addDocrefHtml(bool release){
    std::vector<std::string> docrefStrings;

    std::string input;
    
    size_t foundDocref;
    size_t foundDocref1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    docrefStrings.push_back(input);
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

        foundDocref = input.find("<<DOCUMENTRÉFÉRENCE>>");
        foundDocref1 = input.find("<<DOCUMENTSRÉFÉRENCES>>");

        if ((foundDocref != std::string::npos) || (foundDocref1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }

//RELEASE VS DEBUG MODE
if (release){
    if (docrefStrings.size()!=0){
        std::cout << "Writing Documents Références to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Documents Références Array content:" << std::endl;
    for (auto i: docrefStrings){
        std::cout << i << std::endl;
    }
}
}

void HtmlGenerator::addSecuriteHtml(bool release){
    std::vector<std::string> securiteStrings;

    std::string input;
    
    size_t foundSecurite;
    size_t foundSecurite1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    securiteStrings.push_back(input);
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

        foundSecurite = input.find("<<SECURITE>>");
        foundSecurite1 = input.find("<<SÉCURITÉ>>");

        if ((foundSecurite != std::string::npos) || (foundSecurite1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }
    
    
    //RELEASE VS DEBUG MODE
if (release){
    if (securiteStrings.size()!=0){
        std::cout << "Writing Securite to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Securite Array content:" << std::endl;
    for (auto i: securiteStrings){
        std::cout << i << std::endl;
    }
}
    
}

void HtmlGenerator::addChecklistHtml(bool release){
    int before = buffer.gcount();
    
    
    //STATIC CODE ADD TO BUFFER
    
    
    
    
    if (release)  {
        if (before < buffer.gcount()){
            std::cout << "Writing Checklist to buffer..." << std::endl;
        }
        else{
            std::cout << "Failed to write Checklist to buffer..." << std::endl;
        }
    }
    
}

void HtmlGenerator::addFinmaintHtml(bool release) {
        int before = buffer.gcount();
    
    
    //STATIC CODE ADD TO BUFFER
    
    
    
    
    if (release)  {
        if (before < buffer.gcount()){
            std::cout << "Writing Fin Maintenance to buffer..." << std::endl;
        }
        else{
            std::cout << "Failed to write Fin Maintenance to buffer..." << std::endl;
        }
    }
    
}

//void pagebreakHtml(std::stringstream * buff)




//void risquesHtml(std::stringstream * buff)





void HtmlGenerator::addTachesHtml(bool release) {
    std::vector<std::string> tachesStrings;

    std::string input;
    
    size_t foundTaches;
    size_t foundTaches1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    tachesStrings.push_back(input);
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

        foundTaches = input.find("<<TÂCHE>>");
        foundTaches1 = input.find("<<TÂCHES>>");

        if ((foundTaches != std::string::npos) || (foundTaches1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }

if (release){
    if (tachesStrings.size()!=0){
        std::cout << "Writing Taches Références to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Taches Array content:" << std::endl;
    for (auto i: tachesStrings){
        std::cout << i << std::endl;
    }
}
}





//void notesHtml(std::stringstream * buff)

//void badgeHtml(std::stringstream * buff)


//void buttonHtml(std::stringstream * buff)







void HtmlGenerator::writeBuffertohtml(bool release) {

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