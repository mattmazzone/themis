#include "htmlManip.h"




HtmlGenerator::HtmlGenerator(std::wstring path, std::vector<std::wstring> formattedFile, std::wstring cadenassageURL) {
	outputPath = path;
	this->formattedFile = formattedFile;

	//Create file with same name but .html extension
	outputPath.replace(outputPath.end() - 4, outputPath.end(), L".html");

	//Setup console colors
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cadenasURL = cadenassageURL;

}

void HtmlGenerator::addHeadHtml(bool release) {

	std::size_t found = outputPath.find_last_of(L"/\\");
	std::wstring pageTitle = outputPath.substr(found + 1);



	buffer << R"(<!DOCTYPE html>
<html lang="en">
   <head>
      <title>)" << pageTitle << R"(</title>
      <meta charset="ansi"/>
      <meta name=" viewport " content=" width = device - width, initial - scale = 1 " />
      <meta name=" description " content=" " />
            <style>
         #imgCadenassage {
         height: 100px;
         border-style: dashed;
         }

         @media print{    
			div {
				break-inside: avoid;
				}
            .no-print, .no-print *
            {
            display: none !important;
            }
         }
		 
		 .radio label:before {
			border-radius: 8px;
		  }
		 .checkbox label:before {
			border-radius: 3px;
		}	
		
		
		:root {
		  --form-control-color: rebeccapurple;
		  --form-control-disabled: #959495;
		  
		  --input-border: #8b8a8b;
		  --input-focus-h: 270;
		  --input-focus-s: 50%;
		  --input-focus-l: 25.9%;
		}

		*,
		*:before,
		*:after {
		  box-sizing: border-box;
		}

		body {
		  margin: 0;
		}
		h1, h2{
		 font-family: system-ui, sans-serif;
		  font-size: 1.5rem;
		 
		  line-height: 1.1;

		  gap: 0.5em;
		  }
		h3{
		  font-family: system-ui, sans-serif;
		  font-size: 1.5rem;
		 
		  line-height: 1.1;
		 
		  gap: 0.5em;
		}
		div{
			break-inside: avoid;
		}
		p{
		  font-family: system-ui, sans-serif;
		  font-size: 1.5rem;
		 
		  line-height: 1.1;
		  
		  
		  gap: 0.5em;
		  
		}
		textarea{
		border: 0.15em solid currentColor;
		  border-radius: 0.15em;

		}
		#top-logo {
		height: 200px;
		}
		
		button {
			font-size: 1.5rem;
		}
		button.button {
		  border: none;
		  background-color: transparent;
		  font-family: inherit;
		  padding: 0;
		  cursor: pointer;
		}
		@media screen and (-ms-high-contrast: active) {
		  button.button {
			border: 2px solid currentcolor;
		  }
		}

		a.button,
		button.button {
		  display: inline-flex;
		  align-items: center;
		  justify-content: center;
		  align-self: start;
		  background-color: rebeccapurple;
		  color: #fff;
		  border-radius: 8px;
		  box-shadow: 0 3px 5px rgba(0, 0, 0, 0.18);
		  padding: 0.25em 0.75em;
		  min-width: 10ch;
		  min-height: 44px;
		  text-align: center;
		  line-height: 1.1;
		  transition: 220ms all ease-in-out;
		}
		a.button:hover, a.button:active,
		button.button:hover,
		button.button:active {
		  background-color: #52297a;
		}
		a.button:focus,
		button.button:focus {
		  outline-style: solid;
		  outline-color: transparent;
		  box-shadow: 0 0 0 4px #3d1f5c;
		}

		table {
		  font-family: arial, sans-serif;
		  border-collapse: collapse;
		  width: 100%;
		}

		td, th {
		  border: 1px solid #dddddd;
		  text-align: left;
		  padding: 8px;
		}

		tr:nth-child(even) {
		  background-color: #dddddd;
		}
		form {
		   padding-left: 20px;
		 
		  place-content: center;
		  min-height: 100vh;
		}

		.form-link {
		  font-family: system-ui, sans-serif;
		  font-size: 1.5rem;
		 
		  line-height: 1.1;
		  
		  grid-template-columns: 1em auto;
		  gap: 0.5em;
		}

		.form-control {
		  font-family: system-ui, sans-serif;
		  font-size: 1.5rem;
		 
		  line-height: 1.1;
		  display: grid;
		  grid-template-columns: 1em auto;
		  gap: 0.5em;
		}

		.form-control + .form-control {
		  margin-top: 1em;
		}

		.form-control--disabled {
		  color: var(--form-control-disabled);
		  cursor: not-allowed;
		}

		input[type="checkbox"] {
		  /* Add if not using autoprefixer */
		  -webkit-appearance: none;
		  /* Remove most all native input styles */
		  appearance: none;
		  /* For iOS < 15 */
		  background-color: var(--form-background);
		  /* Not removed via appearance */
		  margin: 0;

		  font: inherit;
		  color: currentColor;
		  width: 1.15em;
		  height: 1.15em;
		  border: 0.15em solid currentColor;
		  border-radius: 0.15em;
		  transform: translateY(-0.075em);

		  display: grid;
		  place-content: center;
		}
		.input {
		  font-size: 16px;
		  font-size: max(16px, 1em);
		  font-family: inherit;
		  padding: 0.25em 0.5em;
		  background-color: #fff;
		  border: 2px solid var(--input-border);
		  border-radius: 4px;
		  transition: 180ms box-shadow ease-in-out;
		}

		.input:focus {
		  border-color: hsl(var(--input-focus-h), var(--input-focus-s), var(--input-focus-l));
		  box-shadow: 0 0 0 3px hsla(var(--input-focus-h), var(--input-focus-s), calc(var(--input-focus-l) + 40%), 0.8);
		  outline: 3px solid transparent;
		}

		.input:not(textarea) {
		  line-height: 1;
		  height: 2.25rem;
		}
		
		input[type="checkbox"]::before {
		  content: "";
		  width: 0.65em;
		  height: 0.65em;
		  clip-path: polygon(14% 44%, 0 65%, 50% 100%, 100% 16%, 80% 0%, 43% 62%);
		  transform: scale(0);
		  transform-origin: bottom left;
		  transition: 120ms transform ease-in-out;
		  box-shadow: inset 1em 1em var(--form-control-color);
		  /* Windows High Contrast Mode */
		  background-color: CanvasText;
		}

		input[type="checkbox"]:checked::before {
		  transform: scale(1);
		}

		input[type="checkbox"]:focus {
		  outline: max(2px, 0.15em) solid currentColor;
		  outline-offset: max(2px, 0.15em);
		}

		input[type="checkbox"]:disabled {
		  --form-control-color: var(--form-control-disabled);

		  color: var(--form-control-disabled);
		  cursor: not-allowed;
		}


		input[type=radio] {
		  /* Add if not using autoprefixer */
		  -webkit-appearance: none;
		  /* Remove most all native input styles */
		  -moz-appearance: none;
			   appearance: none;
		  /* For iOS < 15 */
		  background-color: var(--form-background);
		  /* Not removed via appearance */
		  margin: 0;
		  font: inherit;
		  color: currentColor;
		  width: 1.15em;
		  height: 1.15em;
		  border: 0.15em solid currentColor;
		  border-radius: 50%;
		  transform: translateY(-0.075em);
		  display: grid;
		  place-content: center;
		}

		input[type=radio]::before {
		  content: "";
		  width: 0.65em;
		  height: 0.65em;
		  border-radius: 50%;
		  transform: scale(0);
		  transition: 120ms transform ease-in-out;
		  box-shadow: inset 1em 1em var(--form-control-color);
		  /* Windows High Contrast Mode */
		  background-color: CanvasText;
		}

		input[type=radio]:checked::before {
		  transform: scale(1);
		}

		input[type=radio]:focus {
		  outline: max(2px, 0.15em) solid currentColor;
		  outline-offset: max(2px, 0.15em);
		}
      </style>
   </head>
   <body>
   <form onsubmit="return false">
	<img id="top-logo" src="O:\TFM_GESTION\PM\1_TEMPLATES\LogoPratt\Pratt_&_Whitney_logo.png">
)";
}

void HtmlGenerator::addPreparationHtml(bool release, int start, int end) {



	//Write the top part of the page
	buffer << R"(    
      <h1 style="text-align: center;">Maintenance Préventive TFM</h1>
      <h2 style="text-align: center;">TCX-XX</h2>
      <h2 style="text-align: center;">MXXXXX-XX</h2>
      <h2 style="text-align: center;">TXXXXX-XXXX</h2>
    )";

	std::vector<std::wstring> prepStrings;


	std::wstring input;


	for (int i = start + 1; i < end; i++) {

		input = formattedFile[i];

		prepStrings.push_back(input);

	}


	//Remove fake checkboxes from array
	for (size_t i = 0; i != prepStrings.size(); i++) {
		std::size_t found = prepStrings[i].find_first_of(L")");
		prepStrings[i] = prepStrings[i].substr(found + 1);

	}
	//Section title to buffer
	buffer << R"(
      <div id="Preparation" class="dontbreak">
         <h3 style="text-align: left; text-decoration: underline;">Préparation</h3>)";

	//Write array to buffer
	for (size_t i = 0; i != prepStrings.size(); i++) {
		buffer << R"(

		 <label class="form-control">
         <input type="checkbox" id="prep)" << i << R"(" name="checkbox)" << R"(" required>)"
         << prepStrings[i] << R"(
		 </label>
		 <br>)" << std::endl;

	}
	buffer << R"(
	<a style="padding-left:40px" class="form-link" href="O:\TFM_GESTION\PM\1_TEMPLATES\fiche_communication_ects.xlsx"> Fiche de communication</a>
      </div>
    )";



	//RELEASE VS DEBUG MODE
	if (release) {
		if (prepStrings.size() != 0) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Preparation to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);

		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Preparation vector EMPTY..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}

	else {
		std::wcout << L"--------------------------------" << std::endl << L"Preparation Array content:" << std::endl;
		for (auto i : prepStrings) {
			std::wcout << i << std::endl;
		}
		std::wcout << L"--------------------------------" << std::endl;
	}

}

void HtmlGenerator::addPiecesHtml(bool release, int start, int end) {

	std::vector<std::wstring> piecesStrings;

	std::wstring input;


	for (int i = start + 1; i < end; i++) {

		input = formattedFile[i];

		piecesStrings.push_back(input);
	}

	//Section title to buffer
	buffer << R"(
        <div id="Pieces" class="dontbreak">
	        <h3 style="text-align: left; text-decoration: underline;">Pièces</h3>
	        
    )" << std::endl;

	//Write array to buffer
	if (piecesStrings.size() != 0) {
		for (size_t i = 0; i < piecesStrings.size(); i++) {
			buffer << "            <p>" << piecesStrings[i] << "</p>" << std::endl;
		}
	}
	else {
		// <p> pas de pieces necessaires    
	}
	buffer << R"(
        </div>    
    )";




	//RELEASE VS DEBUG MODE
	if (release) {
		if (piecesStrings.size() != 0) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Pieces to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Pieces vector is EMPTY..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}

	}
	else {
		std::wcout << L"Pieces Array content:" << std::endl;
		for (auto i : piecesStrings) {
			std::wcout << i << std::endl;
		}

	}

}

void HtmlGenerator::addConsommablesHtml(bool release, int start, int end) {

	std::vector<std::wstring> consomStrings;

	std::wstring input;

	for (int i = start + 1; i < end; i++) {

		input = formattedFile[i];

		consomStrings.push_back(input);

	}

	//Section title to buffer
	buffer << R"(
      <div id="Consommables" class="dontbreak">
         <h3 style="text-align: left; text-decoration: underline;">Consommables</h3>)" << std::endl;

	//Write array to buffer
	if (consomStrings.size() != 0) {
		for (size_t i = 0; i < consomStrings.size(); i++) {
			buffer << "         <p>" << consomStrings[i] << "</p>" << std::endl;
		}
	}
	else {
		//Empty
	}

	buffer << R"(
      </div>
    )";



	//RELEASE VS DEBUG MODE
	if (release) {
		if (consomStrings.size() != 0) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Consommables to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Consommables vector is EMPTY..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}
	else {
		std::wcout << L"Consommables Array content:" << std::endl;
		for (auto i : consomStrings) {
			std::wcout << i << std::endl;
		}
	}


}

void HtmlGenerator::addOutilsHtml(bool release, int start, int end) {

	std::vector<std::wstring> outilsStrings;
	std::wstring input;

	for (int i = start + 1; i < end; i++) {

		input = formattedFile[i];

		outilsStrings.push_back(input);
	}

	//Section title to buffer
	buffer << R"(
        <div id="Outils" class="dontbreak">
        	<h3 style="text-align: left; text-decoration: underline;">Outils</h3>)" << std::endl;

	//Write array to buffer
	if (outilsStrings.size() != 0) {
		for (size_t i = 0; i < outilsStrings.size(); i++) {
			buffer << "<p>" << outilsStrings[i] << "</p>" << std::endl;
		}
	}
	else {
		// <p> pas de pieces necessaires    
	}

	buffer << R"(
        </div>
    )";


	//RELEASE VS DEBUG MODE
	if (release) {
		if (outilsStrings.size() != 0) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Outils to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Outils vector is EMPTY..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}

	}
	else {
		std::wcout << L"Outils Array content:" << std::endl;
		for (auto i : outilsStrings) {
			std::wcout << i << std::endl;
		}
	}
}

void HtmlGenerator::addDocrefHtml(bool release, int start, int end) {

	std::vector<std::wstring> docrefStrings;
	std::wstring input;


	for (int i = start + 1; i < end; i++) {

		input = formattedFile[i];

		docrefStrings.push_back(input);

	}

	//Section title to buffer
	buffer << R"(
      <div id="DocRef" class="dontbreak">
        	<h3 style="text-align: left; text-decoration: underline;">Documents Références</h3>)" << std::endl;

	//Write array to buffer
	if (docrefStrings.size() != 0) {
		for (size_t i = 0; i < docrefStrings.size(); i++) {
			buffer << "            <p >" << docrefStrings[i] << "</p>" << std::endl;
		}
	}
	else {
		// <p> pas de pieces necessaires    
	}

	buffer << R"(
      </div>
    )";

	//RELEASE VS DEBUG MODE
	if (release) {
		if (docrefStrings.size() != 0) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Documents Références to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Documents Reference vector is EMPTY..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}

	}
	else {
		std::wcout << L"Documents Références Array content:" << std::endl;
		for (auto i : docrefStrings) {
			std::wcout << i << std::endl;
		}
	}
}

void HtmlGenerator::addSecuriteHtml(bool release, int start, int end) {

	std::vector<std::wstring> securiteStrings;
	std::wstring input;

	for (int i = start + 1; i < end; i++) {

		input = formattedFile[i];

		securiteStrings.push_back(input);
	}

	//Remove fake checkboxes from array
	for (size_t i = 0; i < securiteStrings.size(); i++) {
		std::size_t found = securiteStrings[i].find_first_of(L")");
		securiteStrings[i] = securiteStrings[i].substr(found + 1);

	}
	//Section title to buffer
	buffer << R"(
        <div id="Securite" class="dontbreak">
        	<h3 style="text-align: left; text-decoration: underline;">Sécurité</h3>)" << std::endl;

	//Write array to buffer
	for (size_t i = 0; i < securiteStrings.size(); i++) {
		buffer << R"(
			<label class="form-control">
            <input type="checkbox" id="sec)" << i << R"(" name="sec)" << i << R"(">)"
            << securiteStrings[i] 
			<< R"(</label>
			<br>)" << std::endl;

	}

	buffer << R"(
        </div>
    )";





	//RELEASE VS DEBUG MODE
	if (release) {
		if (securiteStrings.size() != 0) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Securite to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Securite vector is EMPTY..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}

	}
	else {
		std::wcout << L"Securite Array content:" << std::endl;
		for (auto i : securiteStrings) {
			std::wcout << i << std::endl;
		}
	}
	
}

void HtmlGenerator::addChecklistHtml(bool release)   {
	size_t before = buffer.str().size();

	std::vector<std::wstring> checklistStrings;


	std::wstring input;
	std::wifstream inFile("O:/TFM_GESTION/PM/1_TEMPLATES/FormulaireA3/FormulaireA3.txt");
	if (inFile.is_open()) {

		while (getline(inFile, input)) {


			

			if (!input.empty()) {

				checklistStrings.push_back(input);
			}
		}
		inFile.close();




		buffer << R"(
         <div id="Checklist" class="breakbefore">
		   <h3 style="text-align: left; text-decoration: underline;">Checklist</h3>
		
			<table>
			  <tr>
				<th style="width:70%">Questions</th>
				<th style="width:15%; text-align: center;">Oui</th>
				<th style="width:15%; text-align: center;">Non</th>
			  </tr>
			  <tr>)";

			for (size_t i = 0; i < checklistStrings.size(); i++){
				
				buffer << R"(
				<td>)" << checklistStrings[i] << R"(</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes)" << i << R"(" name = "check)" << i << R"(">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkno)" << i << R"(" name = "check)" << i << R"(">		
				   </label>
				</td>
				
			  </tr>)";
			}
			  
		buffer << R"(
			</table>
	    </div>
		)";



	}
	else {
		SetConsoleTextAttribute(hConsole, red);
		std::wcout << L"Unable to open A3 file, default values printed" << std::endl;
		SetConsoleTextAttribute(hConsole, white);


		buffer << R"(
         <div id="Checklist" class="breakbefore">
		   <h3 style="text-align: left; text-decoration: underline;">Checklist</h3>
		
			<table>
			  <tr>
				<th style="width:70%">Questions</th>
				<th style="width:15%; text-align: center;">Oui</th>
				<th style="width:15%; text-align: center;">Non</th>
			  </tr>
			  <tr>
				<td>Est-ce j'ai besoin de EPI spécifique?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes1" name = "check1">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno1" name = "check1" required>
				   </label>	
				</td>
				
			  </tr>
			  <tr>
				<td>Est-ce que je dois cadenasser?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes2" name = "check2">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno2" name = "check2" required>
				   </label>	
				</td>
				
			  </tr>
			  <tr>
				<td>Est-ce qu'il y a d'autres sources d'énergie?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes3" name = "check3">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno3" name = "check3" required>
				   </label>	
				</td>
				
			  </tr>
			  <tr>
				<td>Est-ce que je dois me procurer un permis de travail?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes4" name = "check4">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno4" name = "check4" required>
				   </label>	
				</td>
				
			  </tr>
			  <tr>
				<td>Est-ce que j'ai besoin d'aide?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes5" name = "check5">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno5" name = "check5" required>
				   </label>	
				</td>
			   
			  </tr>
			  <tr>
				<td>Est-ce que mes outils sont appropriés et conformes?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes6" name = "check6">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkno6" name = "check6" required>
				   </label>	
				</td>
			  
			  </tr>
			  <tr>
				<td>Est-ce que je peux être frappés ou coincés par un objet?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes7" name = "check7">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno7" name = "check7" required>
				   </label>	
				</td>
			  
			  </tr>
			  <tr>
				<td>Est-ce que je suis exposé a une chute?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes8" name = "check8">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno8" name = "check8" required>
				   </label>	
				</td>
			  
			  </tr>
			  <tr>
				<td>Est-ce que je connais les risques/moyens de contrôle en lien avec les produits chimiques ou la présence de contaminant sous forme de poussières/fumées comme l’amiante, la silice et le plomb qui pourrait être généré par mes travaux ?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes9" name = "check9">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno9" name = "check9" required>
				   </label>	
				</td>
			  
			  </tr>
			  <tr>
				<td>Est-ce que l'état de la propreté des lieux est satisfaisante?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes10" name = "check10">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno10" name = "check10" required>
				   </label>	
				</td>
			  
			  </tr>
			  <tr>
				<td>Est-ce que la tache comporte des efforts excessifs?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes11" name = "check11">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno11" name = "check11" required>
				   </label>	
				</td>
			  
			  </tr>
			  <tr>
				<td>Est-ce je peux réaliser cette tache en toute sécurité?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes12" name = "check12">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno12" name = "check12" required>
				   </label>	
				</td>
			  
			  </tr>
			  <tr>
				<td>Est-ce que je dois délimiter la zone de travail?</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes13" name = "check13">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno13" name = "check13" required>
				   </label>	
				</td>
			  
			  </tr>
			  <tr>
				<td>Est-ce que le travail implique une règle cardinale non mentionnée précédemment ?(VIM, Gréage et levage, DFT, sécurité machine)</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input type = "radio" id = "checkyes14" name = "check14">		
				   </label>
				</td>
				<td>
				   <label class="form-control" style=" grid-template-rows: auto; grid-template-columns:auto; justify-items: center;">
				      <input style = "float: left;" type = "radio" id = "checkno14" name = "check14" required>
				   </label>	
				</td>
			  
			  </tr>
			 
			</table>
	    </div>

)" << std::endl;
	}


  







	if (release) {
		if (before < buffer.str().size()) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Checklist to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Failed to write Checklist to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}

}

void HtmlGenerator::addRisquesHtml(bool release) {
	size_t before = buffer.str().size();

	//HTML CODE
	buffer << R"(
    <div id="risquesetmethodes" style="clear:both; class="breakbefore"">
		<h3 style="text-align: left; text-decoration: underline;">Risques et Méthodes de Contrôle</h3>
		
		<ul id="ul">
		</ul>
		<div style="clear: both; padding: 10px;" class="no-print">
			<button class="button" id="riskBtn" type="button" class="no-print">
				Add a field 
			</button>
		</div>
	</div>
	
	
    )" << std::endl;

	//JS CODE

	buffer << R"(
    <script>
    function addRisk(){
        var ul = document.getElementById('ul');
        	
         
         var divOuter = document.createElement('div');
        	divOuter.style="clear: both";
         
       
       var divInner1 = document.createElement('div');
        	divInner1.style="float:left; clear:both; padding-bottom: 5px; width: 250px;";
          
        var divInner2 = document.createElement('div');
        	divInner2.style="float:left; clear:both; padding-bottom: 15px; width: 250px;";
        
        var textField = document.createElement('textarea');
            textField.rows="4";
			textField.cols="85";
            textField.style="float: left;"
			textField.classList.add('input')
			textField.placeholder="Risque"
         
         divInner1.appendChild(textField);
         
         var textField1 = document.createElement('textarea');
            textField1.rows="4";
			textField1.cols="85";
            textField1.style="float: left;"
			textField1.classList.add('input')
			textField1.placeholder="Méthode de contôle"
        
        
        divInner2.appendChild(textField1);
        
        var text = document.getElementById('texto');
        
        divOuter.appendChild(divInner1); 
        divOuter.appendChild(divInner2);
        
        ul.appendChild(divOuter);
    }
    var button = document.getElementById('riskBtn');
    button.onclick = addRisk 


</script>
    
    )" << std::endl;




	if (release) {
		if (before < buffer.str().size()) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Risques to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Failed to write Risques to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}
}

void HtmlGenerator::addFinmaintHtml(bool release) {

	size_t before = buffer.str().size();
	//STATIC CODE ADD TO BUFFER




	if (release) {
		if (before < buffer.str().size()) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Fin Maintenance to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Failed to write Fin Maintenance to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}

}

void HtmlGenerator::addNotesHtml(bool release) {

	size_t before = buffer.str().size();
	//STATIC CODE ADD TO BUFFER

	if (release) {
		if (before < buffer.str().size()) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Notes to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Failed to write Notes to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}

}

void HtmlGenerator::addBadgefieldHtml(bool release) {
	size_t before = buffer.str().size();

	buffer << R"(
    <div style="float: left; padding: 50px; clear: both;" class="dontbreak">
         <div style="clear:both; float: left; padding: 10px;">
            <label>Badge: </label>
            <input class="input" type="text" id="badgefield" required>
            <label># Ordre Travail: </label>
            <input  class="input" type="text" id="ordernum" required>
         </div>
         <div style="clear:both; float: left; padding: 10px;" >
            <label>Temps: </label>
            <input class="input">
            <label>Initiales: </label>
            <input class="input">
         </div>
         <div style="clear:both; float: left; padding: 10px;">
            <label>Date complétée: </label>
            <input class="input" type="Date">
         </div>
      </div>
      
      <div class="no-print" style="clear:both; float: left">
         <input id="file-input" type="file" multiple>
         <div style="padding:20px" id="preview"></div>
      </div>
      
      <script> 
         function previewImages() {
         
           var preview = document.querySelector('#preview');
           
           if (this.files) {
             [].forEach.call(this.files, readAndPreview);
           }
         
           function readAndPreview(file) {
           
           
          
           
         
             // Make sure `file.name` matches our extensions criteria
             if (!/\.(jpe?g|png|gif)$/i.test(file.name)) {
               return alert(file.name + " is not an image");
             } // else...
             
             var reader = new FileReader();
             
             reader.addEventListener("load", function() {
               var image = new Image();
               image.height = 400;
         	  image.style = "padding: 10px;";
               image.title  = file.name;
               image.src    = this.result;
         	  preview.appendChild(image);
             });
             
             reader.readAsDataURL(file);
             
           }
         
         }
         
         document.querySelector('#file-input').addEventListener("change", previewImages);
         
      </script>
      )";

	if (release) {
		if (before < buffer.str().size()) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Badge Field to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Failed to write Badge Field to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}
}

void HtmlGenerator::addCadenassageHtml(bool release) {

	size_t before = buffer.str().size();

	if (cadenasURL != L"") {
		buffer << R"(
  <div style="float: left; padding: 50px;" id="cadenassage" class="dontbreak">
      <a href=")" << cadenasURL << R"(" target="_blank"><img id="imgCadenassage" src="O:\TFM_GESTION\PM\1_TEMPLATES\LogoPratt\logo_cadenas.png"/></a>
	<p>)" << cadenasURL << R"(</p>
   </div>
   )" << std::endl;
	}
	else {
		buffer << R"(
  <div style="float: left; padding: 50px;" id="cadenassage">
      <p>Lien Cadenessage Introuvable!</p>
   </div>
   )" << std::endl;
	}
	
	   	 

		SetConsoleTextAttribute(hConsole, green);
		std::wcout << L"Inserting Cadenassage URL..." << std::endl;
		SetConsoleTextAttribute(hConsole, white);

	
	//HTML CODE
	

	if (release) {
		if (before < buffer.str().size()) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Cadenassage to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Failed to write Cadenassage to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}
}

void HtmlGenerator::addSubmitbuttonHtml(bool release) {
	size_t before = buffer.str().size();

	//HTML CODE
	buffer << R"(
  
    <div style="text-align: center; clear:both;" class="no-print">
	<button class="button" id="submitBtn" class="no-print">Soumettre</button>
	<button class="button" id="replanBtn" type="button" class="no-print">À Replanifier</button>
    </div>

     </form>
	
	<footer>
		<div style="height: 50px"></div>
	</footer>
    
<script>
    function generatePDF(){
	//Initialize to true
	var printPage = true;
	var printTitle
	
	//Checkboxes
	var checkboxes = document.getElementsByClassName('mustcheck');
	for (var i =0; i < checkboxes.length; i++) {
		if (checkboxes[i].checked === false) {
			
			printPage = false;
		}
	}
	
	//Radiobuttons
	for (var i = 0; i < 1000; i++) { 
	var radiobuttonyes = document.getElementById('checkyes'.concat(i));
	var radiobuttonno = document.getElementById('checkno'.concat(i));
		if (radiobuttonyes && radiobuttonno) {
			if (radiobuttonyes.checked === false && radiobuttonno.checked ===false){
				printPage = false;

			}
		} 
		else {
			break;
		}
	}
	
	
	//Badge Field
	var badge = document.getElementById('badgefield').value;
		if (badge === '') {
			printPage = false;
		} 
		else {
			printTitle = badge;
		}
	var order = document.getElementById('ordernum').value;
		if (order === '') {
			printPage = false;
		} 
		else {
		printTitle += '-'
			printTitle += order;
		}	
	
	if (printPage){
	
		document.title = printTitle;
		window.print();  
	}
	
	
}
    var button = document.getElementById('submitBtn');
    button.onclick = generatePDF 
    
</script>

<script>
    function replanPDF(){
	//Initialize to true
	var printPage = true;
	var printTitle

	//Badge Field
	var badge = document.getElementById('badgefield').value;
		if (badge === '') {
			printPage = false;
			alert('Specify Badge');
		} 
		else {
			printTitle = badge;
		}
	var order = document.getElementById('ordernum').value;
		if (order === '') {
			printPage = false;
			alert('Specify Order Num');
		} 
		else {
		printTitle += '-'
			printTitle += order;
		}	
	
	if (printPage){
	
		document.title = printTitle;
		window.print();  
		window.open("O:/TFM_GESTION/PM/1_TEMPLATES/WebCompanion/AppExec.hta");
	}
	
	
}
    var button = document.getElementById('replanBtn');
    button.onclick = replanPDF 
    

</script>

</body>
</html>
    
    )" << std::endl;



	if (release) {
		if (before < buffer.str().size()) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Submit Button to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Failed to write Submit Button to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}
}

void HtmlGenerator::addPagebreakHtml(bool release) {

	int before = buffer.str().size();

	buffer << R"(<div class="html2pdf__pagebreak"></div>)" << std::endl;




	if (release) {
		if (before < buffer.gcount()) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Page break to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Failed to write Page break to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}
}

bool HtmlGenerator::addTextFieldHtml(std::wstring inp) {


	size_t found = inp.find(L"-INSERT_TEXTBOX");
	if (found != std::string::npos) {
		buffer << R"(<textarea rows="2" cols="75" placeholder=")" << inp.substr(15, inp.length()) << R"("></textarea>)";
		SetConsoleTextAttribute(hConsole, green);
		std::wcout << L"Inserting Text Area..." << std::endl;
		SetConsoleTextAttribute(hConsole, white);

		return true;
	}
	else {
		return false;
	}


}

bool HtmlGenerator::addPictureHtml(std::wstring inp) {


	size_t found = inp.find(L"-INSERT_PICTURE");
	if (found != std::string::npos) {
		buffer << R"(<img style="height: 300px; padding-bottom: 30px;" src=")" << inp.substr(15, inp.length()) << R"(">)";
		SetConsoleTextAttribute(hConsole, green);
		std::wcout << L"Inserting Picture..." << std::endl;
		SetConsoleTextAttribute(hConsole, white);

		return true;
	}
	else {
		return false;
	}


}

void HtmlGenerator::addTachesHtml(bool release, int start, int end) {

	std::vector<std::wstring> tachesStrings;
	std::vector<int> subStepIndeces;

	std::wstring input;

	std::wstring ectsURL = L"http://collaboration.pwc.ca/sites/ECTS_SR/SitePages/ECTS_HOME.aspx";



	std::wifstream inFile("O:/TFM_GESTION/PM/1_TEMPLATES/Liens/lien_ects.txt");
	//Get section names and line numbers
	if (inFile.is_open()) {

		while (getline(inFile, input)) {
			ectsURL = input;
		}
		inFile.close();
	}
	else {
		std::cout << "Unable to open file";
	
	}




	bool inSection = false;
	bool subStep = false;



	for (int i = start + 1; i < end; i++) {

		input = formattedFile[i];

		tachesStrings.push_back(input);

	}


	bool prev = false;
	//Check if substep
	for (size_t i = 0; i < tachesStrings.size(); i++) {
		std::wstring str;
		str = tachesStrings[i];
		int counter = 0;


		for (int j = 0; j < 5; j++) {
			if (isdigit(str[j])) {
				counter = j;
			}
		}

		if (isdigit(str[counter]) && isalpha(str[counter + 1])) {
			prev = true;
		}

		if (isdigit(str[counter]) && isalpha(str[counter + 1])) {
			subStepIndeces.push_back(i);
		}

		if (counter == 0 && prev == true) {
			subStepIndeces.push_back(i);
		}
	}




	//Section title to buffer
	buffer << R"(
      <div id="Taches" class="breakbefore">
         <h3 style="text-align: left; text-decoration: underline;">Tâches</h3>)";

	for (size_t i = 0; i < tachesStrings.size(); i++) {

		if (addTextFieldHtml(tachesStrings[i])) {
			i++;
		}
		if (addPictureHtml(tachesStrings[i])) {
			i++;
		}

		size_t found_checkmark = tachesStrings[i].find(L"( )");
		size_t found_checkmark1 = tachesStrings[i].find(L"()");

		if ((found_checkmark != std::string::npos) || (found_checkmark1 != std::string::npos)) {

			//Is a task with checkbox case
			std::size_t found = tachesStrings[i].find_first_of(L")");
			tachesStrings[i] = tachesStrings[i].substr(found + 1);

			if (std::find(subStepIndeces.begin(), subStepIndeces.end(), i) != subStepIndeces.end()) {
				buffer << R"(
    
         <div style="clear: both; padding-bottom: 40px; padding-left: 50px;" class="dontbreak">)";
			}
			else {
				buffer << R"(
            <div style="clear: both; padding-bottom: 40px;" class="dontbreak">)";
			}


			//Write array to buffer
			buffer << R"(
               <div>
				  <label class="form-control" for="taskCheckbox")" << i << R"(">)" << R"( 
        	      <input type="checkbox" id="taskCheckbox)" << i << R"(" name="taskCheckbox)" << i << R"(" class="mustcheck" required>)"
        	      << tachesStrings[i] << R"(
				  </label>
			      <br>
    	       </div>
    	       
    	          <div style="float:left; padding-left: 20px;">
					 <label class="form-control" for="taskConforme")" << i << R"(">)" << R"( 

					 <input type="checkbox" id="taskConforme)" << i << R"(" name="taskConforme)" << i << R"(">
    			     Conforme
					 </label>
					 <br>
    		      </div> 	

				  <div style="float:left; padding-left: 20px;">
					 <label class="form-control" for="taskRepare")" << i << R"(">)" << R"( 
					 <input type="checkbox" id="taskRepare)" << i << R"(" name="taskRepare)" << i << R"(">
    			     Réparé
					 </label>
					 <br>
    		      </div> 
    		
				  <div style="float:left; padding-left: 20px;">
					 <label class="form-control" for="taskRemplace")" << i << R"(">)" << R"( 
					 <input type="checkbox" id="taskRemplace)" << i << R"(" name="taskRemplace)" << i << R"(">
    			     Remplacé
					 </label>
					 <br>
    		      </div> 

				  <div style="float:left; padding-left: 20px;">
					 <label class="form-control" for="taskAvis")" << i << R"(">)" << R"( 
					 <input type="checkbox" id="taskAvis)" << i << R"(" name="taskAvis)" << i << R"(">
    			     <a href=")" << ectsURL << R"(" target="_blank">Avis Créé </a>
					 </label>
					 <br>
    		      </div> 
    	          
    		
    		      
    		     
    		
    		      <div style="clear: both; padding-bottom: 10px;"></div>
    		<textarea class="input" placeholder="Note de réparation / remplacement" rows="4" cols="85" ></textarea>
    		      
    	       
            </div>
            )" << std::endl;

		}
		
		//Task doesnt need a checkbox
		else {

			buffer << R"(
                <p>)" << tachesStrings[i] << R"(</p>)" << std::endl;
		}
	}
	//closing tag for main section div
	buffer << R"(
        </div>)" << std::endl;




	if (release) {
		if (tachesStrings.size() != 0) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Taches to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Tache vector is EMPTY..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}
	else {
		std::wcout << L"Taches Array content:" << std::endl;
		for (auto i : tachesStrings) {
			std::wcout << i << std::endl;
		}
	}



}

void HtmlGenerator::addUnknownsHtml(bool release, int start, int end) {


	std::vector<std::wstring> unknownStrings;
	std::vector<int> subStepIndeces;


	std::wstring input;

	std::wstring ectsURL;



	std::wifstream inFile("O:/TFM_GESTION/PM/1_TEMPLATES/Liens/lien_ects.txt");
	//Get section names and line numbers
	if (inFile.is_open()) {

		while (getline(inFile, input)) {
			ectsURL = input;
		}
		inFile.close();
	}
	else {
		std::cout << "Unable to open file";
		ectsURL = L"http://collaboration.pwc.ca/sites/ECTS_SR/SitePages/ECTS_HOME.aspx";
	}

	for (int i = start + 1; i < end; i++) {

		input = formattedFile[i];

		unknownStrings.push_back(input);


	}


	//Check if substep
	bool prev = false;
	//Check if substep
	for (size_t i = 0; i < unknownStrings.size(); i++) {
		std::wstring str;
		str = unknownStrings[i];
		int counter = 0;


		for (int j = 0; j < 5; j++) {
			if (isdigit(str[j])) {
				counter = j;
			}
		}

		if (isdigit(str[counter]) && isalpha(str[counter + 1])) {
			prev = true;
		}

		if (isdigit(str[counter]) && isalpha(str[counter + 1])) {
			subStepIndeces.push_back(i);
		}
		if (isdigit(str[counter]) && isdigit(str[counter + 1]) && isalpha(str[counter + 2])) {
			subStepIndeces.push_back(i);
		}

		if (counter == 0 && prev == true) {
			subStepIndeces.push_back(i);
		}




	}



	input = formattedFile[start];
	input = input.substr(2, input.size() - 4);

	buffer << R"(
        <div id=")" << input << R"(" class="breakbefore">
	<h3 style="text-align: left; text-decoration: underline;">)" << input << R"(</h3>)";





	for (size_t i = 0; i < unknownStrings.size(); i++) {

		if (addTextFieldHtml(unknownStrings[i]) == true) {

		}
		else {



			size_t found_checkmark = unknownStrings[i].find(L"( )");
			size_t found_checkmark1 = unknownStrings[i].find(L"()");

			if ((found_checkmark != std::string::npos) || (found_checkmark1 != std::string::npos)) {

				//Is a task with checkbox case
				std::size_t found = unknownStrings[i].find_first_of(L")");
				unknownStrings[i] = unknownStrings[i].substr(found + 1);



				if (std::find(subStepIndeces.begin(), subStepIndeces.end(), i) != subStepIndeces.end()) {

					buffer << R"(

            <div style="clear: both; padding-bottom: 40px; padding-left: 50px;" class="dontbreak">)" << std::endl;
				}
				else {
					buffer << R"(

            <div style="clear: both; padding-bottom: 40px;" class="dontbreak">)" << std::endl;
				}


				//Write array to buffer
				buffer << R"(
               <div>
				  <label class="form-control" for="taskCheckbox")" << i << unknownTimesUsed << R"(">)" << R"( 
        	      <input type="checkbox" id="taskCheckbox)" << i << unknownTimesUsed << R"(" name="taskCheckbox)" << i << unknownTimesUsed << R"(" class="mustcheck" required>)"
					<< unknownStrings[i] << R"(
				  </label>
			      <br>
    	       </div>
    	       
    	          <div style="float:left; padding-left: 20px;">
					 <label class="form-control" for="taskConforme")" << i << unknownTimesUsed << R"(">)" << R"( 

					 <input type="checkbox" id="taskConforme)" << i << unknownTimesUsed << R"(" name="taskConforme)" << i << unknownTimesUsed << R"(">
    			     Conforme
					 </label>
					 <br>
    		      </div> 	

				  <div style="float:left; padding-left: 20px;">
					 <label class="form-control" for="taskRepare")" << i << unknownTimesUsed << R"(">)" << R"( 
					 <input type="checkbox" id="taskRepare)" << i << unknownTimesUsed << R"(" name="taskRepare)" << i << unknownTimesUsed << R"(">
    			     Réparé
					 </label>
					 <br>
    		      </div> 
    		
				  <div style="float:left; padding-left: 20px;">
					 <label class="form-control" for="taskRemplace")" << i << unknownTimesUsed << R"(">)" << R"( 
					 <input type="checkbox" id="taskRemplace)" << i << unknownTimesUsed << R"(" name="taskRemplace)" << i << unknownTimesUsed << R"(">
    			     Remplacé
					 </label>
					 <br>
    		      </div> 

				  <div style="float:left; padding-left: 20px;">
					 <label class="form-control" for="taskAvis")" << i << unknownTimesUsed << R"(">)" << R"( 
					 <input type="checkbox" id="taskAvis)" << i << unknownTimesUsed << R"(" name="taskAvis)" << i << unknownTimesUsed << R"(">
    			    <a href=")" << ectsURL << R"(" target="_blank">Avis Créé </a>
					 </label>
					 <br>
    		      </div> 
    	          
    		
    		      
    		     
    		
    		      <div style="clear: both; padding-bottom: 10px;"></div>
    		<textarea class="input" placeholder="Note de réparation / remplacement" rows="4" cols="85" ></textarea>
    		      
    	       
            </div>
            )" << std::endl;;

			}
			//Unkown doesnt need a checkbox
			else {

				buffer << R"(
                <p>)" << unknownStrings[i] << R"(</p>)" << std::endl;
			}
		}


		//closing tag for main section div
		buffer << R"(
        </div>)" << std::endl;


	}


	if (release) {
		if (unknownStrings.size() != 0) {
			SetConsoleTextAttribute(hConsole, green);
			std::wcout << L"Writing Unknowns to buffer..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
		else {
			SetConsoleTextAttribute(hConsole, red);
			std::wcout << L"Unknowns vector is EMPTY..." << std::endl;
			SetConsoleTextAttribute(hConsole, white);
		}
	}
	else {
		std::wcout << L"Unknowns Array content:" << std::endl;
		for (auto i : unknownStrings) {
			std::wcout << i << std::endl;
		}
	}






	unknownTimesUsed++;


}

void HtmlGenerator::callInOrder(bool release) {

	//Start
	addHeadHtml(release);

	std::wstring input;
	size_t foundTitle;
	int functionToCall = 0;
	bool callFunction = false;
	bool inSection = false;
	int start = 0;
	int end = 0;

	int last = 0;

	//Look at formatted File for titles and add them all to array. If not recognized, call unknown. Unkown should add the name to the array so as not to read it twice
	for (size_t i = 0; i < formattedFile.size(); i++) {
		input = formattedFile[i];

		foundTitle = input.find(L"<<");

		if (foundTitle != std::string::npos || i == formattedFile.size() - 1) {



			input = input.substr(2, input.size() - 4);




			if (i == formattedFile.size() - 1) {
				inSection = true;
				last = 1;

			}

			if (!inSection) {
				start = i;

			}
			else {
				start = end;
				end = i + last;
				switch (functionToCall) {

				case 1:
				{
					addPreparationHtml(release, start, end);
					callFunction = false;
					inSection = false;
					functionToCall = 0;
					break;
				}
				case 2:
				{
					addSecuriteHtml(release, start, end);
					callFunction = false;
					inSection = false;
					functionToCall = 0;
					break;
				}
				case 3:
				{
					addPiecesHtml(release, start, end);
					callFunction = false;
					inSection = false;
					functionToCall = 0;
					break;
				}
				case 4:
				{
					addConsommablesHtml(release, start, end);
					callFunction = false;
					inSection = false;
					functionToCall = 0;
					break;
				}
				case 5:
				{
					addOutilsHtml(release, start, end);
					callFunction = false;
					inSection = false;
					functionToCall = 0;
					break;
				}
				case 6:
				{
					addDocrefHtml(release, start, end);
					callFunction = false;
					inSection = false;
					functionToCall = 0;
					break;
				}
				case 7:
				{
					addTachesHtml(release, start, end);
					callFunction = false;
					inSection = false;
					functionToCall = 0;
					break;
				}
				case 10:
				{
					addUnknownsHtml(release, start, end);
					callFunction = false;
					inSection = false;
					functionToCall = 0;
					break;
				}



				}
			}

			input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());

			if (input == L"PRÉPARATION" || input == L"PREPARATION") {

				functionToCall = 1;
				inSection = true;
			}
			else if (input.find(L"SÉCURITÉ") != std::string::npos || input.find(L"SECURITE") != std::string::npos) {

				functionToCall = 2;
				inSection = true;
			}
			else if (input.find(L"PIÈCES") != std::string::npos || input.find(L"PIECES") != std::string::npos) {
				functionToCall = 3;
				inSection = true;
			}
			else if (input.find(L"CONSOMMABLES") != std::string::npos || input.find(L"CONSOMMABLE") != std::string::npos) {
				functionToCall = 4;
				inSection = true;
			}
			else if (input.find(L"OUTILS") != std::string::npos || input.find(L"OUTIL") != std::string::npos) {
				functionToCall = 5;
				inSection = true;
			}
			else if (input.find(L"DOCUMENTRÉFÉRENCE") != std::string::npos || input.find(L"DOCUMENTSRÉFÉRENCES") != std::string::npos
				|| input.find(L"DOCUMENTREFERENCE") != std::string::npos || input.find(L"DOCUMENTSREFERENCES") != std::string::npos) {

				functionToCall = 6;
				inSection = true;
			}
			else if (input == L"TÂCHES" || input == L"TACHES" || input == L"TACHE " || input == L"TÂCHE") {
				functionToCall = 7;
				inSection = true;
			}
			else {
				//CALL UNKNOWN FUNCTION

				functionToCall = 10;
				inSection = true;
			}
		}




	}

	//Static Parts
	addChecklistHtml(release);
	addRisquesHtml(release);






	//Static Parts
	addFinmaintHtml(release);
	addNotesHtml(release);
	addCadenassageHtml(release);
	addBadgefieldHtml(release);
	addSubmitbuttonHtml(release);


}

void HtmlGenerator::writeBuffertohtml(bool release) {

	//Write buffer to created file
	std::wofstream outFile(outputPath);
	if (outFile.is_open()) {

		outFile << buffer.rdbuf();

		outFile.close();




		SetConsoleTextAttribute(hConsole, 32);
		for (int i = 0; i < 70; i++) {
			
		
			std::wcout << L" ";
			Sleep(10);
		}

		SetConsoleTextAttribute(hConsole, white);

		std::wcout << std::endl;


		SetConsoleTextAttribute(hConsole, green);
		std::wcout << L"Finished writing to .html file" << std::endl;
		SetConsoleTextAttribute(hConsole, white);
	}
	else {
		SetConsoleTextAttribute(hConsole, red);
		std::wcout << L"Error writing to .html file";
		SetConsoleTextAttribute(hConsole, green);
	}


}