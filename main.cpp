#include <fcntl.h>
#include <io.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>

#include "htmlManip.h"
#include "textTransforms.h"
#include "menuApp.h"





using namespace std;

int main()
{
	
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
			return 0;
		}

		Reformater reformatTxt(path);
		vector <wstring> formattedFile;
		formattedFile = reformatTxt.reformatGood();

		HtmlGenerator htmlGen(path, formattedFile);

		htmlGen.callInOrder(status);

		htmlGen.writeBuffertohtml(status);

	}

	break;

	case 2:
	{
		std::cout << "Load a PM.html" << std::endl;
	}
	break;

	case 3:
	{
		std::cout << "Instructions" << std::endl;
	}
	break;

	case 4:
	{
		std::cout << "Exit" << std::endl;
		return 0;

	}
	default:
		cout << "Error";
	}







	return 0;
}





