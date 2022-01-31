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
        void addChecklistHtml(bool release);            //Static
        void addRisquesHtml(bool release);              //Static
        void addFinmaintHtml(bool release);             //Static
        void addNotesHtml(bool release);                //Static
        void addBadgefieldHtml(bool release);                //Static
        void addSubmitbuttonHtml(bool release);             //Static
        void addPagebreakHtml(bool release);                //Static
        
        void writeBuffertohtml(bool release);
};






