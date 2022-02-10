#include <iostream>
#include <string>
#include <vector>


#include "htmlManip.h"
#include "textTransforms.h"
#include "menuApp.h"


using namespace std;

int main()
{


    App myApp;
    bool status =true;

    switch (myApp.mainMenu()) {
        case 1:
        {
        string path;
        path = myApp.selectFile(".txt");

	    //Exit Program if no files found
	    if (path == "") {
		    return 0;
	    }
    
        Reformater reformatTxt(path);
        vector <string> formattedFile;
        formattedFile = reformatTxt.reformatGood();
    
        HtmlGenerator htmlGen(path, formattedFile);
   
        htmlGen.callInOrder(status);
    
        htmlGen.writeBuffertohtml(status);
    
        } 
    
    break;
    
    case 2:
    {
        std::cout << "Load a PM.html" << std::endl;
    }
    break;
    
    case 3:
    {
        std::cout << "Instructions" << std::endl;
    }
    break;
    
    case 4:
    {
        std::cout << "Exit" << std::endl;
        return 0;
        
    }
    default:
    cout << "Error";
}

return 0;
}
    
        



