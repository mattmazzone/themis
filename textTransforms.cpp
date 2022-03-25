#include "textTransforms.h"





Reformater::Reformater(std::wstring path) {
	filePath = path;

}




std::wstring Reformater::removeWhitespace(std::wstring input)
{
	input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
	return input;
}



std::wstring Reformater::onlyString(std::wstring inp) {

	const wchar_t* WhiteSpace = L" \t\v\r\n";
	size_t start = inp.find_first_not_of(WhiteSpace);
	size_t end = inp.find_last_not_of(WhiteSpace);
	return start == end ? std::wstring() : inp.substr(start, end - start + 1);
}

std::wstring Reformater::sameLine(std::wstring inp) {

	std::wstring str = inp;

	//Random ish variable. May increase for tuning parser
	size_t startOfLine = 1;

	str = removeWhitespace(str);

	size_t found_checkmark = str.find(L"()");
	size_t found_title = str.find(L"<<");
	size_t found_dash = str.find(L"-");
	size_t found_ex = str.find(L"EX:");
	size_t found_endingColon = str.rfind(L":");
	size_t found_asterisk = str.rfind(L"*");

	if (found_title < std::wstring::npos) {
		return L"title";
	}
	else if (found_checkmark < startOfLine) {
		return L"checkmark";
	}
	else if (found_dash < startOfLine) {
		return L"dash";
	}
	else if (found_ex < startOfLine) {
		return L"ex";
	}
	else if (found_endingColon < startOfLine) {
		return L"colon";
	}
	else if (found_asterisk < startOfLine) {
		return L"asterisk";
	}
	else {
		return L"plain_text";
	}



}

std::wstring Reformater::detectTextFields(std::wstring inp) {
	int countUnderscores = 0;

	for (size_t i = 0; i < inp.length(); i++) {
		if (inp[i] == L'_') {
			countUnderscores++;
		}
	}

	if (countUnderscores > 5) {
		return inp;
		//return L"-INSERT_TEXTBOX" + inp;
	}
	else {
		return inp;
	}


}

std::wstring Reformater::getCadenassage()
{
	return cadenassageURL;
}


std::wstring Reformater::getFunctionnalLocation()
{
	return functionnalLocation;
}
std::wstring Reformater::getEquipmentNumber()
{
	return equipmentNumber;
}
std::wstring Reformater::getTaskNumber()
{
	return taskNumber;
}

std::vector<std::wstring> Reformater::reformatGood() {


	std::vector<std::wstring> formattedTextFile;

	std::wstring input;



	std::wifstream inFile(filePath);
	//Get section names and line numbers
	if (inFile.is_open()) {

		while (getline(inFile, input)) {


			input = onlyString(input);
			input = detectTextFields(input);

			if (!input.empty()) {

				formattedTextFile.push_back(input);
			}
		}
		inFile.close();
	}
	else {
		std::wcout << L"Unable to open file";
	}
	
	

	for (size_t i = 0; i < formattedTextFile.size(); i++) {
		std::wstring str = formattedTextFile[i];
		str = removeWhitespace(str);
		size_t finder = str.find(L"-FUNC_LOCATION:");

		

		if (finder != std::string::npos) {
			
			functionnalLocation = str.substr(15, str.length());
			formattedTextFile.erase(formattedTextFile.begin() + i);
		}
	}
	for (size_t i = 0; i < formattedTextFile.size(); i++) {
		std::wstring str = formattedTextFile[i];
		str = removeWhitespace(str);
		size_t finder = str.find(L"-EQIP_NUMBER:");
		

		if (finder != std::string::npos) {
			
			equipmentNumber = str.substr(13, str.length());
			formattedTextFile.erase(formattedTextFile.begin() + i);
		}
	}
	for (size_t i = 0; i < formattedTextFile.size(); i++) {
		std::wstring str = formattedTextFile[i];
		str = removeWhitespace(str);
		size_t finder = str.find(L"-TASK_NUMBER:");
		

		if (finder != std::string::npos) {
			
			taskNumber = str.substr(13, str.length());
			formattedTextFile.erase(formattedTextFile.begin() + i);
		}
	}



	for (size_t i = 0; i < formattedTextFile.size(); i++) {
		std::wstring str = formattedTextFile[i];
		str = removeWhitespace(str);
		size_t finder = str.find(L"-CADENASSAGE_LINK:");

		if (finder != std::string::npos) {
			cadenassageURL = str.substr(18, str.length());
			formattedTextFile.erase(formattedTextFile.begin() + i);
		}
	}


	for (size_t i = 0; i < formattedTextFile.size(); i++) {
		std::wstring str = formattedTextFile[i];
		str = removeWhitespace(str);
		size_t finder = str.find(L"()NEPASMETTREEN");
		if (finder != std::string::npos) {
			formattedTextFile.erase(formattedTextFile.begin() + i, formattedTextFile.end());
		}
	}
	for (size_t i = 0; i < formattedTextFile.size(); i++) {
		std::wstring str = formattedTextFile[i];
		str = removeWhitespace(str);
		size_t finder = str.find(L"()S'ASSURERQUELESLIEUX");
		if (finder != std::string::npos) {
			formattedTextFile.erase(formattedTextFile.begin() + i, formattedTextFile.end());
		}
	}

	for (size_t i = 0; i < formattedTextFile.size(); i++) {
		std::wstring str = formattedTextFile[i];
		str = removeWhitespace(str);
		size_t finder = str.find(L"BADGE:");
		if (finder != std::string::npos) {
			formattedTextFile.erase(formattedTextFile.begin() + i, formattedTextFile.end());
		}
	}
	for (size_t i = 0; i < formattedTextFile.size(); i++) {
		std::wstring str = formattedTextFile[i];
		str = removeWhitespace(str);
		size_t finder = str.find(L"()CONFORME");
		if (finder != std::string::npos) {
			formattedTextFile.erase(formattedTextFile.begin() + i);
		}
	}


	int lineCombineCounter = 0;
	bool newLine = false;

	for (size_t i = 0; i < formattedTextFile.size(); i++) {
		input = formattedTextFile[i];
		input = onlyString(input);






		lineCombineCounter = 0;


		if (sameLine(input) == L"title") {
			newLine = true;
		}
		else if (sameLine(input) == L"checkmark") {
			newLine = false;
		}
		else if (sameLine(input) == L"dash") {
			newLine = false;
		}
		else if (sameLine(input) == L"ex") {
			newLine = false;
		}
		else if (sameLine(input) == L"colon") {
			newLine = false;
		}
		else if (sameLine(input) == L"asterisk") {
			newLine = false;
		}
		else if (sameLine(input) == L"plain_text") {

			if (newLine == false) {
				lineCombineCounter++;
				formattedTextFile[i - 1] += (L" " + formattedTextFile[i]);
				formattedTextFile.erase(formattedTextFile.begin() + i);
				i = i - lineCombineCounter;
			}


			newLine = false;
		}



	}

	

	/*
	 for (auto i : formattedTextFile){
		std::wcout<<i <<std::endl;
	}
	*/

	return formattedTextFile;

}

