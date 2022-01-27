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
        
        
        void addHeadHtml();
        void addPreparationHtml();
        void addPiecesHtml();
        void addConsommablesHtml();
        
        void writeBuffertohtml();
};











							//dynamic

//void outilsHtml(std::stringstream *buff);							//dynamic

//void pagebreakHtml(std::stringstream *buff);

//void checklistHtml(std::stringstream *buff);

//void risquesHtml(std::stringstream *buff);

//void securiteHtml(std::stringstream *buff);							//dynamic

//void tachesHtml(std::stringstream *buff);							//dynamic

//void finmaintenanceHtml(std::stringstream *buff);

//void notesHtml(std::stringstream *buff);

//void badgeHtml(std::stringstream *buff);

//void buttonHtml(std::stringstream *buff);

//void writeBuffertohtml(std::stringstream *buff);