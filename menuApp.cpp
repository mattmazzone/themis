#include "menuApp.h"


int App::mainMenu() {

	int userSelect;
	std::wcout << L"PM Conversion Tool - Developped by Matteo Mazzone" << std::endl << std::endl;


	std::wcout << std::endl << L"Menu Options: " << std::endl << L"   1 - Load a PM.txt file" << std::endl << L"   2 - Load a PM.html file" << std::endl << L"   3 - Instructions" << std::endl << L"   4 - Exit" << std::endl;

	std::wcout << L"Enter selection: ";
	std::cin >> userSelect;

	return userSelect;
}

std::wstring App::selectFile(std::wstring extension)
{

	int counter = 1;
	int selection = 0;

	std::vector<std::filesystem::path> listPaths;

	for (const auto & entry : std::filesystem::directory_iterator(std::filesystem::current_path())) {


		if (entry.path().extension() == extension) {
			std::wcout << counter << L" - " << entry.path() << std::endl;
			listPaths.push_back(entry.path());
			counter++;
		}
	}

	if (listPaths.size() != 0) {

		std::wcout << std::endl << L"Enter selection: ";
		std::cin >> selection;

		std::wcout << L"Selected: " << listPaths[selection - 1] << std::endl;
		return listPaths[selection - 1].wstring();

	}
	else {
		std::wcout << L"Didn't find any corresponding files, make sure they are in the same directory as the executable." << std::endl;
		return L"";
	}



}