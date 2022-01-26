
#include "textTransforms.h"

std::string removeWhitespace(std::string input)
{
    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
    return input;
}



std::string onlyString(std::string inp){

    const char* WhiteSpace = " \t\v\r\n";
    size_t start = inp.find_first_not_of(WhiteSpace);
    size_t end = inp.find_last_not_of(WhiteSpace);
    return start == end ? std::string() : inp.substr(start, end - start + 1);
}

std::string sameLine(std::string inp, std::string prev) {
    if (isalpha(inp[0])){

        prev = prev + " " + onlyString(inp);

        return prev;
    }
    else{
        return "";
    }
}

void reformatGood(){
    int lineCounter = 0;
    std::string input;
    int totalLines = 0;


    std::stringstream goodFormat;

    std::ifstream inFile("example.txt");

    std::string previous;
    //Get section names and line numbers
    if (inFile.is_open()) {

        while (getline(inFile, input)) {
            input = onlyString(input);

            if (lineCounter == 1){
                previous = input;

            }
            else{
                if ((sameLine(input, previous)== "") || inFile.eof()){
                    if (previous != input) {
                        goodFormat << previous << "-P"<< std::endl;
                    }
                    previous = input;
                }
                else {
                    if (previous != input) {
                        goodFormat << sameLine(input, previous) << "L-------";
                    }
                    previous = input;
                }
            }
            lineCounter++;
        }
        inFile.close();
    } else {
        std::cout << "Unable to open file";
    }

    std::cout << goodFormat.rdbuf();


    std::ifstream outFile("example.txt");
    if (outFile.is_open()) {

        //outFile << goodFormat.rdbuf();



        outFile.close();
    } else {
        std::cout << "Unable to open file";
    }
}