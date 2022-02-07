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

	std::string str = inp;

	//Random ish variable. May increase for tuning parser
	int startOfLine = 4;

	str = removeWhitespace(str);
    
    size_t found_checkmark = str.find("()");
    size_t found_title = str.find("<<");
    size_t found_dash = str.find("-");
	size_t found_ex = str.find("EX:");
	size_t found_endingColon = str.rfind(":");
    

    if (found_title < std::string::npos){
        return "title";
    }
    else if (found_checkmark < startOfLine){
        return "checkmark";
    }
    else if (found_dash < startOfLine){
        return "dash";
    }
	else if (found_ex < startOfLine) {
		return "ex";
	}
	else if (found_endingColon < startOfLine) {
		return "colon";
	}
    else {
        return "plain_text";
    }
        
    
  
}

std::string Reformater::detectTextFields(std::string inp) {
    int countUnderscores = 0;
    
    for (int i = 0; i < inp.length(); i++){
        if (inp[i] == '_'){
            countUnderscores++;
        }
    }
    
    if (countUnderscores > 5) {
        return "-INSERT_TEXTBOX" + inp;
    } else{
        return inp;
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
            input = detectTextFields(input);
            
            if (!input.empty()){
                
                formattedTextFile.push_back(input);
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
         formattedTextFile.erase(formattedTextFile.begin()+i); 
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
	else if (sameLine(input) == "ex") {
		newLine = false;
	}
	else if (sameLine(input) == "colon") {
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

