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
    if (isalpha(inp[0])){

        return inp;
    }
    else{
        return "";
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


for (int i = 0; i < formattedTextFile.size(); i++){
    input = formattedTextFile[i];
    input = onlyString(input);
    
    
    if ((sameLine(input) == "")&&(i != 0)){
        
    }
    else {
        if (i!=0){
            formattedTextFile[i-1] += (" " + formattedTextFile[i]);
            formattedTextFile.erase(formattedTextFile.begin()+i);
        }
    }
        
    
    
}

formattedTextFile.shrink_to_fit();


for (int i = 0; i < formattedTextFile.size(); i++){
    if (formattedTextFile[i].find("( )NE PAS METTRE EN FONCTION SI ÉQUIPEMENT N'EST PAS SÉCURITAIRE") != std::string::npos){
        formattedTextFile.erase(formattedTextFile.begin()+i, formattedTextFile.end());
    }
}

/*
//For testing contents of vector
for (int i = 0; i < formattedTextFile.size(); i++){
    std::cout << formattedTextFile[i] << std::endl;
}

*/
    
    return formattedTextFile;

}

