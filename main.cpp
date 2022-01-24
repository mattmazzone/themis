#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctype.h>
#include <vector>

using namespace std;

//Global variables
int lineCounter = 1;
int checkboxCounter = 0;

stringstream buffer;

//Dynamic Arrays
int sectionSize = 1;
string *sectionArray = new string[50];

int *sectionLinenum = new int[50];


//Function stores the section names and line numbers in a dynamic array
void
sectionNames(string inp) {
    size_t foundStart;
    size_t foundEnd;

    foundStart = inp.find("<<");
    foundEnd = inp.find(">>");
    if (foundStart != std::string::npos && foundEnd != std::string::npos) {

        foundStart = foundStart + 2;
        foundEnd = foundEnd;


        for (int i = foundStart; i < inp.length(); i++) {
            if (inp[i] == ' ') {
                foundStart++;
            } else {
                break;
            }
        }
        for (int i = foundEnd; i < inp.length(); i--) {
            if (inp[i] == ' ') {
                foundEnd--;
            } else {
                break;
            }
        }

        sectionArray[sectionSize - 1] =
                inp.substr(foundStart, foundEnd - foundStart - 1);
        sectionLinenum[sectionSize - 1] = lineCounter;
        sectionSize++;
    }

}

string
onlyString(string inp){

    const char* WhiteSpace = " \t\v\r\n";
    size_t start = inp.find_first_not_of(WhiteSpace);
    size_t end = inp.find_last_not_of(WhiteSpace);
    return start == end ? std::string() : inp.substr(start, end - start + 1);
}

string
sameLine(string inp, string prev) {
    if (isalpha(inp[0])){

        prev = prev + " " + onlyString(inp);

        return prev;
    }
    else{
        return "";
    }
}



string
detectCheckboxes(string inp) {
    size_t found;

    found = inp.find("( )");
    if (found != std::string::npos) {

        found = found + 3;
        for (int i = found; i < inp.length(); i++) {
            if (inp[i] == ' ') {
                found++;

            } else {
                break;
            }
        }


        return inp.substr(found);

    }
    else{
        return "";
    }

}



vector<string>
detectCheckboxes1(string inp){
    string sub = "( )";
    vector<size_t> positions;

    vector<string> checkboxStrings;

    size_t pos = inp.find(sub, 0);
    while(pos != string::npos){
        positions.push_back(pos);
        pos = inp.find(sub,pos+1);
    }

    for (int i = 0; i<positions.size(); i++){


        if (positions.size()==1){

            checkboxStrings.push_back(inp.substr(positions[i]+3,inp.length()));
        }

        if ((i+1)<positions.size()){

            checkboxStrings.push_back(inp.substr(positions[i]+3,positions[i+1]-positions[i]-4));
        }
        if ((i+1) == positions.size()){                     //Not sure about this condition but works
            string lastBox;

            for (int j =0; j<inp.length();j++){
                if (inp[positions[i]+j+3] != ' '){

                    lastBox = lastBox + (inp[positions[i]+j+3]);
                }
                else{
                    break;
                }
            }
            checkboxStrings.push_back(lastBox);

        }

        cout << endl;
    }




  
    return checkboxStrings;
}



void
beginningHtml(){
    buffer << R"_(<!DOCTYPE html>
<html lang=" en ">
<head>
  <title>Hello, world!</title>
  <meta charset=" UTF - 8 " />
  <meta name=" viewport " content=" width = device - width, initial - scale = 1 " />
  <meta name=" description " content=" " />
</head>
<body>)_" << endl;

}

void
sectionTitletobuffer(string inp){
    buffer << R"_(<h2>)_" << inp << R"_(</h2>)_" << endl;
}

void
textTobuffer(string inp){
    if (inp != ""){
        buffer << R"_(<p>)_" << inp;
        buffer <<  R"_(</p>)_" << endl;
    }
}

void
checkboxesTobuffer(string inp){

    buffer << endl << R"_(<input type="checkbox" id="checkbox)_" <<  checkboxCounter << R"_(" name="checkbox)_" << checkboxCounter << R"_(" value="Bike">)_" << endl <<
           R"_(<label for="checkbox)_" << checkboxCounter << R"_(">)_" << inp << R"_(</label><br>)_" << endl;;
    checkboxCounter++;
}

void
writeBuffertohtml(){

    ofstream outFile("output.html");
    if (outFile.is_open()) {

        outFile << buffer.rdbuf();

        outFile.close();
    } else {
        cout << "Unable to open file";
    }

}

int
main() {
    string input;
    int totalLines = 0;
    int charCounter = 0;

    stringstream goodFormat;

    ifstream inFile0("example.txt");

    string previous;
    //Get section names and line numbers
    if (inFile0.is_open()) {

        while (getline(inFile0, input)) {
            input= onlyString(input);

            if (lineCounter==1){
                previous = input;

            }
            else{
                if (sameLine(input, previous)== "" || inFile0.eof()){
                    goodFormat << previous <<endl;
                    previous =input;
                }
                else {

                    previous = sameLine(input, previous);



                }




            }


            lineCounter++;
        }
        inFile0.close();
    } else {
        cout << "Unable to open file";
    }

    ofstream outFile0("example.txt");
    if (outFile0.is_open()) {

        outFile0 << goodFormat.rdbuf();

        outFile0.close();
    } else {
        cout << "Unable to open file";
    }










    lineCounter =1;
    ifstream inFile("example.txt");
    //Get section names and line numbers
    if (inFile.is_open()) {

        while (getline(inFile, input)) {

            sectionNames(input);


            lineCounter++;
        }

        inFile.close();
    } else {
        cout << "Unable to open file";
    }

    totalLines = lineCounter;
    sectionLinenum[sectionSize - 1] = totalLines;    //Add last line of file to array



    //Get content of sections and mate with section titles
    lineCounter = 1;
    ifstream inFile1("example.txt");

    string *sectionContent = new string[500];


    beginningHtml();            //Start writing buffer



    if (inFile1.is_open()) {

        while (getline(inFile1, input)) {

            input = onlyString(input);

            for (int i = 0; i < sectionSize; i++) {

                if (lineCounter == sectionLinenum[i]){

                    sectionTitletobuffer(sectionArray[i]);
                }

                if (lineCounter > sectionLinenum[i] && lineCounter < sectionLinenum[i + 1]) {



                    if (detectCheckboxes1(input).size() == 0){
                        textTobuffer(input);

                    }
                    else{
                        for (int j = 0; j < detectCheckboxes(input).size(); j++){
                            cout << detectCheckboxes1(input)[j];
                        }




                    }

                }

            }


            lineCounter++;
        }

        inFile1.close();
    } else {
        cout << "Unable to open file";
    }




    writeBuffertohtml();





//Free memory
    delete[]sectionArray;

    return 0;
}