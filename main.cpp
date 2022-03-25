#include <fcntl.h>
#include <io.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>
#include <filesystem>
#include <chrono>

#include "htmlManip.h"
#include "textTransforms.h"
#include "menuApp.h"


using namespace std;

int main()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	//Set Console mode
	_setmode(_fileno(stdout), _O_U8TEXT);


	App myApp;
	bool status = true;

	switch (myApp.mainMenu()) {
	case 1:
	{
		wstring path;
		path = myApp.selectFile(L".txt");

		//Exit Program if no files found
		if (path == L"") {
			system("pause");
			return 0;
		}

		Reformater reformatTxt(path);
		vector <wstring> formattedFile;
		formattedFile = reformatTxt.reformatGood();

		HtmlGenerator htmlGen(path, formattedFile, reformatTxt.getCadenassage() );

		htmlGen.setFunctionnalLocation(reformatTxt.getFunctionnalLocation());
		htmlGen.setEquipmentNumber(reformatTxt.getEquipmentNumber());
		htmlGen.setTaskNumber(reformatTxt.getTaskNumber());

		htmlGen.callInOrder(status);

		htmlGen.writeBuffertohtml(status,true);

	}

	break;

	case 2:
	{
		std::filesystem::current_path("C:/Users/pw192717/Desktop/PWC-TFE-0001-TC02 - Test");
		wstring path;
		int fileCounter = 1;

		auto start = std::chrono::steady_clock::now();
		
		// Iterate over the `std::filesystem::directory_entry` elements using `auto`
		for (auto const& dir_entry : std::filesystem::recursive_directory_iterator(std::filesystem::current_path()))
		{
			if (dir_entry.path().extension() == ".txt") {
				std::wcout << dir_entry.path() << std::endl;
				path = dir_entry.path();

				{
					Reformater reformatTxt(path);
					vector <wstring> formattedFile;
					formattedFile = reformatTxt.reformatGood();
									   
					HtmlGenerator htmlGen(path, formattedFile, reformatTxt.getCadenassage());

					htmlGen.setFunctionnalLocation(reformatTxt.getFunctionnalLocation());
					htmlGen.setEquipmentNumber(reformatTxt.getEquipmentNumber());
					htmlGen.setTaskNumber(reformatTxt.getTaskNumber());

					htmlGen.callInOrder(status);

					htmlGen.writeBuffertohtml(status,false);
					fileCounter++;
				}

			}
		}
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::wcout << L"Elapsed time: " << elapsed_seconds.count() << L"s for " << fileCounter << L" files";
	}
	break;

	case 3:
	{
		std::cout << L"See Documentation.docx" << std::endl;
	}
	break;

	case 4:
	{
		std::cout << L"Exit" << std::endl;
		return 0;
	}
	default:
		cout << L"Error";
	}
	return 0;
}





