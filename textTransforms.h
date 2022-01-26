#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctype.h>
#include <vector>



std::string removeWhitespace(std::string input);

std::string onlyString(std::string inp);                //Removes escape characters

std::string sameLine(std::string inp, std::string prev);

void reformatGood();