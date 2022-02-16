#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "textTransforms.h"




class HtmlGenerator {
private:
	std::wstring outputPath;
	std::wstringstream buffer;
	std::vector<std::wstring> formattedFile;

	std::vector<int> fileTitlesLN;
	int unknownTimesUsed = 0;


public:
	HtmlGenerator(std::wstring path, std::vector<std::wstring> formattedFile);


	void addHeadHtml(bool release);
	void addPreparationHtml(bool release, int start, int end);
	void addPiecesHtml(bool release, int start, int end);
	void addConsommablesHtml(bool release, int start, int end);
	void addOutilsHtml(bool release, int start, int end);
	void addTachesHtml(bool release, int start, int end);
	void addDocrefHtml(bool release, int start, int end);
	void addSecuriteHtml(bool release, int start, int end);

	void addCadenassageHtml(bool release);

	void addUnknownsHtml(bool release, int start, int end);

	void addChecklistHtml(bool release);            //Static
	void addRisquesHtml(bool release);              //Static
	void addFinmaintHtml(bool release);             //Static
	void addNotesHtml(bool release);                //Static
	void addBadgefieldHtml(bool release);                //Static
	void addSubmitbuttonHtml(bool release);             //Static
	void addPagebreakHtml(bool release);                //Static
	bool addTextFieldHtml(std::wstring);

	void callInOrder(bool release);

	void writeBuffertohtml(bool release);
};






