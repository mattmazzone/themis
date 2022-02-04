#include "menuApp.h"


int App::mainMenu() {
 
    int userSelect;
    std::cout << "PM Conversion Tool - Developped by Matteo Mazzone" << std::endl << std::endl;

    
    std::cout << std::endl << "Menu Options: " << std::endl << "   1 - Load a PM.txt file" << std::endl << "   2 - Load a PM.html file" << std::endl << "   3 - Instructions" << std::endl << "   4 - Exit" << std::endl;    
    
    std::cout << "Enter selection: ";
    std::cin >> userSelect;
    
    return userSelect;
}

std::string App::selectFile(std::string extension)
{
    
    int counter = 1;
    int selection = 0;
    
    std::vector<std::string> listPaths;
    
    for (const auto & entry : std::filesystem::directory_iterator(std::filesystem::current_path())){
            
        
        if(entry.path().extension() == extension) {
            std::cout << counter << " - " << entry.path() << std::endl;
            listPaths.push_back(entry.path().u8string());
            counter++;
        }
    }
    
    std::cout << std::endl << "Enter selection: ";
    std::cin >> selection;
    
    std::cout << "Selected: " << listPaths[selection-1] << std::endl;
    return listPaths[selection-1];
    
    
    
}