#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "textTransforms.h"




class HtmlGenerator {
    private:
        std::string outputPath;
        std::stringstream buffer;
        std::vector<std::string> formattedFile;
    
    
    public:
        HtmlGenerator(std::string path, std::vector<std::string> formattedFile); 
        
        
        void addHeadHtml(bool release);
        void addPreparationHtml(bool release);
        void addPiecesHtml(bool release);
        void addConsommablesHtml(bool release);
        void addOutilsHtml(bool release);
        void addTachesHtml(bool release);
        void addDocrefHtml(bool release);
        void addSecuriteHtml(bool release);
        void addChecklistHtml(bool release);
        void addFinmaintHtml(bool release);
        
        void writeBuffertohtml(bool release);
};











						

//void pagebreakHtml(std::stringstream *buff);



//void risquesHtml(std::stringstream *buff);







//void notesHtml(std::stringstream *buff);

//void badgeHtml(std::stringstream *buff);

//void buttonHtml(std::stringstream *buff);

