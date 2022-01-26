#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctype.h>
#include <vector>

#include "htmlManip.h"
#include "textTransforms.h"

int main()
{


    std::stringstream buff;
    std::stringstream *buffPtr;
    buffPtr = &buff;


    reformatGood();


    headHtml(buffPtr);

    preparationHtml(buffPtr);

    writeBuffertohtml(buffPtr);

    //std::cout << buffPtr->rdbuf();








}