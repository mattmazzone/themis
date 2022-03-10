#include <fcntl.h>
#include <io.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>

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

		htmlGen.writeBuffertohtml(status);

	}

	break;

	case 2:
	{

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





