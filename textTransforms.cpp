#include "textTransforms.h"




Reformater::Reformater(std::string path){
    filePath = path;
}




std::string Reformater::removeWhitespace(std::string input)
{
    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
    return input;
}



std::string Reformater::onlyString(std::string inp){

    const char* WhiteSpace = " \t\v\r\n";
    size_t start = inp.find_first_not_of(WhiteSpace);
    size_t end = inp.find_last_not_of(WhiteSpace);
    return start == end ? std::string() : inp.substr(start, end - start + 1);
}

std::string Reformater::sameLine(std::string inp) {
    
    size_t found_checkmark = inp.find("( )");
    size_t found_checkmark1 = inp.find("()");
    size_t found_title = inp.find("<<");
    size_t found_dash = inp.find("-");
    

    if (found_title != std::string::npos){
        return "title";
    }
    else if (found_checkmark != std::string::npos){
        return "checkmark";
    }
    else if (found_checkmark1 != std::string::npos){
        return "checkmark";
    }
    else if (found_dash != std::string::npos){
        return "dash";
    }
    else {
        return "plain_text";
    }
        
    
  
}

std::vector<std::string> Reformater::reformatGood(){
    
    
    std::vector<std::string> formattedTextFile;

    std::string input;

    

    std::ifstream inFile(filePath);
    //Get section names and line numbers
    if (inFile.is_open()) {

        while (getline(inFile, input)) {
            
            input = onlyString(input);
            if (!input.empty()){
                formattedTextFile.push_back(onlyString(input));
            }
        }
        inFile.close();
    } else {
        std::cout << "Unable to open file";
    }




 for (int i = 0 ; i < formattedTextFile.size(); i++){
        std::string str = formattedTextFile[i];
        str = removeWhitespace(str);
        size_t finder = str.find("()NEPASMETTREEN");
        if (finder != std::string::npos){
         formattedTextFile.erase(formattedTextFile.begin()+i, formattedTextFile.end()); 
        }
 }
  for (int i = 0 ; i < formattedTextFile.size(); i++){
        std::string str = formattedTextFile[i];
        str = removeWhitespace(str);
        size_t finder = str.find("()S'ASSURERQUELESLIEUX");
        if (finder != std::string::npos){
         formattedTextFile.erase(formattedTextFile.begin()+i, formattedTextFile.end()); 
        }
 }
 
  for (int i = 0 ; i < formattedTextFile.size(); i++){
        std::string str = formattedTextFile[i];
        str = removeWhitespace(str);
        size_t finder = str.find("BADGE:");
        if (finder != std::string::npos){
         formattedTextFile.erase(formattedTextFile.begin()+i, formattedTextFile.end()); 
        }
 }
   for (int i = 0 ; i < formattedTextFile.size(); i++){
        std::string str = formattedTextFile[i];
        str = removeWhitespace(str);
        size_t finder = str.find("()CONFORME");
        if (finder != std::string::npos){
         formattedTextFile.erase(formattedTextFile.begin()+i, formattedTextFile.end()); 
        }
 }
 

int lineCombineCounter = 0;
bool newLine = false;

for (int i = 0; i < formattedTextFile.size(); i++){
    input = formattedTextFile[i];
    input = onlyString(input);
    
    
   
    
    
    
    lineCombineCounter = 0;
    
    
    if (sameLine(input) == "title" ){
        newLine = true;
    }
    else if (sameLine(input) == "checkmark"){
        newLine = false;
    }
    else if (sameLine(input) == "dash"){
        newLine = false;
    }
    else if (sameLine(input) == "plain_text"){
        
        if (newLine == false){
            lineCombineCounter++;
            formattedTextFile[i-1] += (" " + formattedTextFile[i]);
            formattedTextFile.erase(formattedTextFile.begin()+i);
            i= i -lineCombineCounter;
        }
        
        
        newLine = false;
    }
    

    
}



/*
 for (auto i : formattedTextFile){
    std::cout<<i <<std::endl;
}
*/
    
    return formattedTextFile;

}

