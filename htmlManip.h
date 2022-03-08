#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>

#include "textTransforms.h"




class HtmlGenerator {
private:
	std::wstring outputPath;
	std::wstringstream buffer;
	std::wstring cadenasURL;
	std::vector<std::wstring> formattedFile;

	std::vector<int> fileTitlesLN;
	int unknownTimesUsed = 0;

	HANDLE hConsole;
	const int green = 10;
	const int yellow = 14;
	const int red = 12;
	const int white = 15;




public:
	HtmlGenerator(std::wstring path, std::vector<std::wstring> formattedFile, std::wstring cadenassageURL);


	void addHeadHtml(bool release);
	void addPreparationHtml(bool release, int start, int end);
	void addPiecesHtml(bool release, int start, int end);
	void addConsommablesHtml(bool release, int start, int end);
	void addOutilsHtml(bool release, int start, int end);
	void addTachesHtml(bool release, int start, int end);
	void addDocrefHtml(bool release, int start, int end);
	void addSecuriteHtml(bool release, int start, int end);

	void addCadenassageHtml( bool release);

	void addUnknownsHtml(bool release, int start, int end);

	void addChecklistHtml(bool release);            //Static
	void addRisquesHtml(bool release);              //Static
	void addFinmaintHtml(bool release);             //Static
	void addNotesHtml(bool release);                //Static
	void addBadgefieldHtml(bool release);                //Static
	void addSubmitbuttonHtml(bool release);             //Static
	void addPagebreakHtml(bool release);                //Static
	bool addTextFieldHtml(std::wstring);
	bool addPictureHtml(std::wstring);					//Static

	void callInOrder(bool release);

	void writeBuffertohtml(bool release);
};






