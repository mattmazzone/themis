#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>


class Reformater
{
    private:
        std::string filePath;
    
    public:
        Reformater(std::string path);
    
        std::string removeWhitespace(std::string input);
        std::string onlyString(std::string inp);                //Removes escape characters
        std::string sameLine(std::string inp);
        std::vector<std::string> reformatGood();
    
};



