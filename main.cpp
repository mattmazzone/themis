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
    

switch (myApp.mainMenu()) {
  case 1:
  {
    string path;
    path = myApp.selectFile(".txt");
    
    Reformater reformatTxt(path);
    vector <string> formattedFile;
    formattedFile = reformatTxt.reformatGood();
    
    HtmlGenerator htmlGen(path, formattedFile);
    
    htmlGen.addHeadHtml();
    htmlGen.addPreparationHtml();
    htmlGen.addPiecesHtml();
    htmlGen.addConsommablesHtml();
    
    
    
    
    
    
    htmlGen.writeBuffertohtml();
    
    
    //pass the vector to htmlGen
  } 
    
    
    break;
  case 2:
    cout << "Tuesday";
    break;
    default:
    cout << "Error";
}

}
    
        

/*
    reformatGood();


    headHtml(buffPtr);

    preparationHtml(buffPtr);
    
    piecesHtml(buffPtr);
    
    consommablesHtml(buffPtr);

    writeBuffertohtml(buffPtr);

*/
    //std::cout << buffPtr->rdbuf();








