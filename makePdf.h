#include "Aspose.Pdf.h"


using namespace System;
using namespace Aspose::Pdf;
using namespace Aspose::Pdf::Text;

void ExampleComplex()
{
	String outputFileName;

	// String for path name.
	String _dataDir("C:\\Samples\\");

	// String for file name.
	String filename("Complex.pdf");

	// Initialize document object
	auto document = MakeObject<Document>();
	// Add page
	auto page = document->get_Pages()->Add();

	// Add image
	String imageFileName = _dataDir + String(u"logo.png");



	// Add Header
	auto header = MakeObject<TextFragment>(u"New ferry routes in Fall 2020");
	auto textFragementState = header->get_TextState();
	textFragementState->set_Font(FontRepository::FindFont(u"Arial"));
	textFragementState->set_FontSize(24);
	header->set_HorizontalAlignment(HorizontalAlignment::Center);
	auto position = MakeObject<Aspose::Pdf::Text::Position>(130, 720);
	header->set_Position(position);
	page->get_Paragraphs()->Add(header);

	// Add description
	String descriptionText(u"Visitors must buy tickets online and tickets are limited to 5,000 per day. Ferry service is operating at half capacity and on a reduced schedule. Expect lineups.");
	auto description = MakeObject<TextFragment>(descriptionText);
	description->get_TextState()->set_Font(FontRepository::FindFont(u"Times New Roman"));
	description->get_TextState()->set_FontSize(14);
	description->set_HorizontalAlignment(HorizontalAlignment::Left);
	page->get_Paragraphs()->Add(description);

	// Add table
	auto table = MakeObject<Table>();
	table->set_ColumnWidths(u"200");

	table->set_Border(MakeObject<BorderInfo>(Aspose::Pdf::BorderSide::Box, 1.0f, Aspose::Pdf::Color::get_DarkSlateGray()));
	table->set_DefaultCellBorder(MakeObject<BorderInfo>(Aspose::Pdf::BorderSide::Box, .5f, Aspose::Pdf::Color::get_Black()));
	
	table->get_DefaultCellTextState()->set_Font(FontRepository::FindFont(u"Helvetica"));

	auto headerRow = table->get_Rows()->Add();
	headerRow->get_Cells()->Add(u"Departs City");
	headerRow->get_Cells()->Add(u"Departs Island");

	for (auto headerRowCell : headerRow->get_Cells())
	{
		headerRowCell->set_BackgroundColor(Color::get_Gray());
		headerRowCell->get_DefaultCellTextState()->set_ForegroundColor(Color::get_WhiteSmoke());
	}

	String arrivals[10] = { u"6:00",u"6:45", u"7:00", u"7:45", u"8:00", u"8:45", u"9:00", u"9:45", u"10:00", u"10:45" };
	String departures[10] = { u"7:00", u"7:45", u"8:00", u"8:45", u"9:00", u"9:45", u"10:00", u"10:45", u"11:00", u"11:45" };

	for (int i = 0; i < 10; i++)
	{
		auto dataRow = table->get_Rows()->Add();
		dataRow->get_Cells()->Add(arrivals[i]);
		dataRow->get_Cells()->Add(departures[i]);
	}

	page->get_Paragraphs()->Add(table);

	// Save updated PDF
	outputFileName = _dataDir + filename;

	document->Save(outputFileName);
}
