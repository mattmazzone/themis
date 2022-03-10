#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <vector>

#include <filesystem>


class Reformater
{
private:
	std::wstring filePath;
	std::wstring cadenassageURL;
	std::wstring functionnalLocation;
	std::wstring equipmentNumber;
	std::wstring taskNumber;

public:
	Reformater(std::wstring path);

	std::wstring removeWhitespace(std::wstring input);
	std::wstring onlyString(std::wstring inp);                //Removes escape characters
	std::wstring sameLine(std::wstring inp);
	std::wstring detectTextFields(std::wstring inp);
	std::vector<std::wstring> reformatGood();

	std::wstring getCadenassage();

	std::wstring getFunctionnalLocation();
	std::wstring getEquipmentNumber();
	std::wstring getTaskNumber();
};



