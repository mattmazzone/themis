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
    
    Reformater reformatTxt(path);
    vector <string> formattedFile;
    formattedFile = reformatTxt.reformatGood();
    
    HtmlGenerator htmlGen(path, formattedFile);
    
    htmlGen.addHeadHtml(status);
    htmlGen.addPreparationHtml(status);
    htmlGen.addPiecesHtml(status);
    htmlGen.addConsommablesHtml(status);
    htmlGen.addOutilsHtml(status);
    htmlGen.addTachesHtml(status);
    htmlGen.addDocrefHtml(status);
    htmlGen.addSecuriteHtml(status);
    htmlGen.addChecklistHtml(status);
    htmlGen.addFinmaintHtml(status);                                                 
    htmlGen.addRisquesHtml(status); 
    htmlGen.addNotesHtml(status); 
    htmlGen.addBadgefieldHtml(status); 
    htmlGen.addSubmitbuttonHtml(status); 
    //htmlGen.addPagebreakHtml(status); 
 
    
    
    
    
    htmlGen.writeBuffertohtml(status);
    
    
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
    
        



