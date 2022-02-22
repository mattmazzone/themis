#include "htmlManip.h"




HtmlGenerator::HtmlGenerator(std::wstring path, std::vector<std::wstring> formattedFile) {
	outputPath = path;
	this->formattedFile = formattedFile;

	//Create file with same name but .html extension
	outputPath.replace(outputPath.end() - 4, outputPath.end(), L".html");

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
   </head>
   <body>
   <style>
   @media print
   {    
       .no-print, .no-print *
       {
           display: none !important;
       }
   }
	</style>
	<form onsubmit="return false">

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
      <div id="Preparation">
         <h3 style="text-align: left; text-decoration: underline;">Préparation</h3>)";

	//Write array to buffer
	for (size_t i = 0; i != prepStrings.size(); i++) {
		buffer << R"(
         <input type="checkbox" id="prep)" << i << R"(" name="prep)" << i << R"(" required>
         <label for="prep)" << i << R"(">)" << prepStrings[i] << R"(</label><br>)" << std::endl;

	}
	buffer << R"(
      </div>
    )";



	//RELEASE VS DEBUG MODE
	if (release) {
		if (prepStrings.size() != 0) {
			std::wcout << L"Writing Preparation to buffer..." << std::endl;

		}
		else {
			std::wcout << L"Preparation vector EMPTY..." << std::endl;
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
        <div id="Pieces">
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
			std::cout << "Writing Pieces to buffer..." << std::endl;
		}
		else {
			std::cout << "Pieces vector is EMPTY..." << std::endl;
		}

	}
	else {
		std::cout << "Pieces Array content:" << std::endl;
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
      <div id="Consommables">
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
			std::wcout << L"Writing Consommables to buffer..." << std::endl;
		}
		else {
			std::wcout << L"Consommables vector is EMPTY..." << std::endl;
		}
	}
	else {
		std::cout << "Consommables Array content:" << std::endl;
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
        <div id="Outils" style="page-break-after: always">
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
			std::cout << "Writing Outils to buffer..." << std::endl;
		}
		else {
			std::cout << "Outils vector is EMPTY..." << std::endl;
		}

	}
	else {
		std::cout << "Outils Array content:" << std::endl;
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
      <div id="DocRef" style="page-break-after: always">
        	<h3 style="text-align: left; text-decoration: underline;">Documents Références</h3>)" << std::endl;

	//Write array to buffer
	if (docrefStrings.size() != 0) {
		for (size_t i = 0; i < docrefStrings.size(); i++) {
			buffer << "            <p>" << docrefStrings[i] << "</p>" << std::endl;
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
			std::wcout << L"Writing Documents Références to buffer..." << std::endl;

		}
		else {
			std::wcout << L"Documents Reference vector is EMPTY..." << std::endl;
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
        <div id="Securite" style="page-break-after: always">
        	<h3 style="text-align: left; text-decoration: underline;">Sécurité</h3>)" << std::endl;

	//Write array to buffer
	for (size_t i = 0; i < securiteStrings.size(); i++) {
		buffer << R"(
            <input type="checkbox" id="sec)" << i << R"(" name="sec)" << i << R"(">
            <label for="sec)" << i << R"(">)" << securiteStrings[i] << R"(</label><br>)" << std::endl;

	}

	buffer << R"(
        </div>
    )";





	//RELEASE VS DEBUG MODE
	if (release) {
		if (securiteStrings.size() != 0) {
			std::cout << "Writing Securite to buffer..." << std::endl;
		}
		else {
			std::cout << "Securite vector is EMPTY..." << std::endl;
		}

	}
	else {
		std::cout << "Securite Array content:" << std::endl;
		for (auto i : securiteStrings) {
			std::wcout << i << std::endl;
		}
	}

}

void HtmlGenerator::addChecklistHtml(bool release) {
	size_t before = buffer.str().size();

	std::vector<std::wstring> checklistStrings;


	std::wstring input;
	std::wifstream inFile("FormulaireA3.txt");
	if (inFile.is_open()) {

		while (getline(inFile, input)) {


			

			if (!input.empty()) {

				checklistStrings.push_back(input);
			}
		}
		inFile.close();
	}
	else {
		std::cout << "Unable to open file";


		buffer << R"(
        <div id="Checklist" style="page-break-before: always; page-break-after: always;">
		   <h3 style="text-align: left; text-decoration: underline;">Checklist</h3>
			
			<div style="clear:both; padding: 10px;">
				<div style="width: 400px; word-wrap: break-word; float: left;">
					<label> Est-ce j'ai besoin de EPI spécifique?</label>
				</div>
				<div style="float: left; width: 100px;">
					<label style="float: right;" for="check1">Non</label>
					<input style="float: right;" type="radio" id="check1" name="check1">
					<label style="float: right;" for="check1">Oui</label>
					<input style="float: right;" type="radio" id="check1" name="check1">
				</div>

			</div>
			
			<div style="clear:both; padding: 10px;">
				<div style="width: 400px; word-wrap: break-word; float: left;">
				    <label> Est-ce que je dois cadenasser?</label>
			    </div>
				<div style="float: left; width: 100px;">
				    <label  style="float: right;" for="check2">Non</label>
				    <input style="float: right;" type="radio" id="check2" name="check2">
				    <label style="float: right;" for="check2">Oui</label>
			    	<input style="float: right;" type="radio" id="check2" name="check2">
			    </div>

		    </div>

	    	<div style="clear:both; padding: 10px;">
				<div style="width: 400px; word-wrap: break-word; float: left;">
			    	<label>  Est-ce qu'il y a d'autres sources d'énergie?</label>
			    </div>
				<div style="float: left; width: 100px;">
			    	<label  style="float: right;" for="check3">Non</label>
			    	<input style="float: right;" type="radio" id="check3" name="check3">
			    	<label style="float: right;" for="check3">Oui</label>
			    	<input style="float: right;" type="radio" id="check3" name="check3">
		    	</div>

	    	</div>

		    <div style="clear:both; padding: 10px;">
				<div style="width: 400px; word-wrap: break-word; float: left;">
			    	<label> Est-ce que je dois me procurer un permis de travail?</label>
		    	</div>
				<div style="float: left; width: 100px;">
					<label  style="float: right;" for="check4">Non</label>
					<input style="float: right;" type="radio" id="check4" name="check4">
					<label style="float: right;" for="check4">Oui</label>
					<input style="float: right;" type="radio" id="check4" name="check4">
		    	</div>

	    	</div>


		    <div style="clear:both; padding: 10px;">
				<div style="width: 400px; word-wrap: break-word; float: left;">
			        <label>Est-ce que j'ai besoin d'aide?</label>
			    </div>
				<div style="float: left; width: 100px;">
			    	<label  style="float: right;" for="check5">Non</label>
			    	<input style="float: right;" type="radio" id="check5" name="check5">
			    	<label style="float: right;" for="check5">Oui</label>
			    	<input style="float: right;" type="radio" id="check5" name="check5">
		    	</div>

		    </div>


	    	<div style="clear:both; padding: 10px;">
				<div style="width: 400px; word-wrap: break-word; float: left;">
			    	<label>Est-ce que mes outils sont appropriés et conformes?</label>
			    </div>
				<div style="float: left; width: 100px;">
			    	<label  style="float: right;" for="check6">Non</label>
			    	<input style="float: right;" type="radio" id="check6" name="check6">
			    	<label style="float: right;" for="check6">Oui</label>
			    	<input style="float: right;" type="radio" id="check6" name="check6">
		    	</div>

	    	</div>

	    	<div style="clear:both; padding: 10px;">
				<div style="width: 400px; word-wrap: break-word; float: left;">
			    	<label>  Est-ce que je peux être frappés ou coincés par un objet?</label>
			</div>
				<div style="float: left; width: 100px;">
			    	<label  style="float: right;" for="check7">Non</label>
			    	<input style="float: right;" type="radio" id="check7" name="check7">
			    	<label style="float: right;" for="check7">Oui</label>
			    	<input style="float: right;" type="radio" id="check7" name="check7">
		    	</div>

		    </div>

		    <div style="clear:both; padding: 10px;">
				<div style="width: 400px; word-wrap: break-word; float: left;">
			    	<label> Est-ce que je suis exposé a une chute?</label>
			    </div>
				<div style="float: left; width: 100px;">
			    	<label  style="float: right;" for="check8">Non</label>
			    	<input style="float: right;" type="radio" id="check8" name="check8">
			    	<label style="float: right;" for="check8">Oui</label>
			    	<input style="float: right;" type="radio" id="check8" name="check8">
		    	</div>

		    </div>
		
	
		
		    <div style="clear:both; padding: 10px;">
		    	<div style="width: 400px; word-wrap: break-word; float: left;">
			    	<label> Est-ce que je connais les risques/moyens de contrôle en lien avec les produits chimiques ou la présence
						de contaminant sous forme de poussières/fumées comme l’amiante, la silice et le plomb qui pourrait être généré par mes 
						travaux?
			    	</label>
			    </div>
				<div style="float: left; width: 100px;">
			    	<label  style="float: right;" for="check9">Non</label>
			    	<input style="float: right;" type="radio" id="check9" name="check9">
			    	<label style="float: right;" for="check9">Oui</label>
			    	<input style="float: right;" type="radio" id="check9" name="check9">
		    	</div>
		    </div>

	    	<div style="clear:both; padding: 10px;">
		    	<div style="width: 400px; word-wrap: break-word; float: left;">
		    		<label> Est-ce que l'état de la propreté des lieux est satisfaisante?</label>
		    	</div>
		   		<div style="float: left; width: 100px;">
			    	<label  style="float: right;" for="check10">Non</label>
			    	<input style="float: right;" type="radio" id="check10" name="check10">
			    	<label style="float: right;" for="check1">Oui</label>
			    	<input style="float: right;" type="radio" id="check10" name="check10">
		    	</div>

		    </div>

		    <div style="clear:both; padding: 10px;">
				<div style="width: 400px; word-wrap: break-word; float: left;">
			    	<label> Est-ce que je dois délimiter la zone de travail?</label>
			    </div>
				<div style="float: left; width: 100px;">
			    	<label  style="float: right;" for="check1">Non</label>
			    	<input style="float: right;" type="radio" id="check11" name="check11">
			    	<label style="float: right;" for="check11">Oui</label>
			    	<input style="float: right;" type="radio" id="check11" name="check11">
			    </div>

		    </div>
			
			
			
	    	<div style="clear:both; padding: 10px;">
		    	<div style="width: 400px; word-wrap: break-word; float: left;">
		    		<label>Est-ce que la tache comporte des efforts excessifs?</label>
		    	</div>
		   		<div style="float: left; width: 100px;">
			    	<label  style="float: right;" for="check12">Non</label>
			    	<input style="float: right;" type="radio" id="check12" name="check12">
			    	<label style="float: right;" for="check12">Oui</label>
			    	<input style="float: right;" type="radio" id="check12" name="check12">
			    </div>
	    	</div>
	    	

	    	<div style="clear:both; padding: 10px;">
			    <div style="width: 400px; word-wrap: break-word; float: left;">
			    	<label> Est-ce je peux réaliser cette tache en toute sécurité?</label>
			</div>
				<div style="float: left; width: 100px;">
			    	<label  style="float: right;" for="check13">Non</label>
			    	<input style="float: right;" type="radio" id="check13" name="check13">
			    	<label style="float: right;" for="check13">Oui</label>
			    	<input style="float: right;" type="radio" id="check13" name="check13">
		    	</div>
		    </div>

		    <div style="clear:both; padding: 10px;">
		    	<div style="width: 400px; word-wrap: break-word; float: left;">
			    	<label> Est-ce que le travail implique une règle cardinale non mentionnée précédemment ? (VIM, 
						Gréage et levage, DFT, sécurité machine)
			    	</label>
			    </div>
				<div style="float: left; width: 100px;">
			    	<label  style="float: right;" for="check14">Non</label>
			    	<input style="float: right;" type="radio" id="check14" name="check14">
			    	<label style="float: right;" for="check14">Oui</label>
			    	<input style="float: right;" type="radio" id="check14" name="check14">
		    	</div>
	    	</div>
	    </div>

)" << std::endl;
	}


	if (checklistStrings.size() != 0) {

		buffer << R"(
        <div id="Checklist" style="page-break-before: always; page-break-after: always;">
		   <h3 style="text-align: left; text-decoration: underline;">Checklist</h3>)";




		for (size_t i = 0; i != checklistStrings.size(); i++) {
			buffer << R"(
		<div style = "clear:both; padding: 10px;">
			<div style = "width: 400px; word-wrap: break-word; float: left;">
			<label>)" << checklistStrings[i] << R"(</label>
			</div>
			<div style = "float: left; width: 100px;">
			<label style = "float: right;" for = "check)" << i << R"(">Non</label>
			<input style = "float: right;" type = "radio" id = "checkno)" << i << R"(" name = "check)" << i << R"(" required>
			<label style = "float: right;" for = "check)" << i << R"(">Oui</label>
			<input style = "float: right;" type = "radio" id = "checkyes)" << i << R"(" name = "check)" << i << R"(">
			</div>
		</div>)";

		}
	}








	if (release) {
		if (before < buffer.str().size()) {
			std::wcout << L"Writing Checklist to buffer..." << std::endl;
		}
		else {
			std::cout << "Failed to write Checklist to buffer..." << std::endl;
		}
	}

}

void HtmlGenerator::addRisquesHtml(bool release) {
	size_t before = buffer.str().size();

	//HTML CODE
	buffer << R"(
    <div id="risquesetmethodes" style="page-break-after: always; clear:both;">
		<div style="clear:both; padding: 10px;">
			<div style="width: 200px; float: left; padding-left: 40px;">Risques</div>
			<div style="width: 200px; float: left; padding-left: 50px;">Méthodes de contrôle</div>
		</div>
		<ul id="ul">
		</ul>
		<div style="clear: both; padding: 10px;">
			<button id="riskBtn" class="no-print">
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
        	divInner1.style="float:left;  padding-left: 10px; width: 250px;";
          
        var divInner2 = document.createElement('div');
        	divInner2.style="float:left;  padding-bottom: 10px; width: 250px;";
        
        var textField = document.createElement('textarea');
            textField.rows="5";
			textField.cols="30";
            textField.style="float: left;"
         
         divInner1.appendChild(textField);
         
         var textField1 = document.createElement('textarea');
            textField1.rows="5";
			textField1.cols="30";
            textField1.style="float: left;"
        
        
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
			std::wcout << L"Writing Risques to buffer..." << std::endl;
		}
		else {
			std::cout << "Failed to write Risques to buffer..." << std::endl;
		}
	}
}

void HtmlGenerator::addFinmaintHtml(bool release) {

	size_t before = buffer.str().size();
	//STATIC CODE ADD TO BUFFER




	if (release) {
		if (before < buffer.str().size()) {
			std::wcout << L"Writing Fin Maintenance to buffer..." << std::endl;
		}
		else {
			std::wcout << L"Failed to write Fin Maintenance to buffer..." << std::endl;
		}
	}

}

void HtmlGenerator::addNotesHtml(bool release) {

	size_t before = buffer.str().size();
	//STATIC CODE ADD TO BUFFER

	if (release) {
		if (before < buffer.str().size()) {
			std::wcout << L"Writing Notes to buffer..." << std::endl;
		}
		else {
			std::wcout << L"Failed to write Notes to buffer..." << std::endl;
		}
	}

}

void HtmlGenerator::addBadgefieldHtml(bool release) {
	size_t before = buffer.str().size();

	buffer << R"(
    <div style="float: left; padding: 50px;">
         <div style="clear:both; float: left; padding: 10px;">
            <label>Badge: </label>
            <input>
            <label># Ordre Travail: </label>
            <input>
         </div>
         <div style="clear:both; float: left; padding: 10px;">
            <label>Temps: </label>
            <input type="Time">
            <label>Initiales: </label>
            <input>
         </div>
         <div style="clear:both; float: left; padding: 10px;">
            <label>Date complétée: </label>
            <input type="Date">
         </div>
      </div>
      
      <div style="clear:both; float: left">
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
			std::wcout << L"Writing Badge Field to buffer..." << std::endl;
		}
		else {
			std::wcout << L"Failed to write Badge Field to buffer..." << std::endl;
		}
	}
}

void HtmlGenerator::addCadenassageHtml(bool release) {

	size_t before = buffer.str().size();

	//HTML CODE
	buffer << R"(
    
   <div style="float: left; padding: 50px;" id="cadenassage">
      <a href="https://www.google.com"><img id="imgCadenassage" src="https://i.imgur.com/Sf9u25n.png""/></a>
   </div>
   <style>
      #imgCadenassage {
      height: 200px;
	  border-style: dashed;
	  }
   </style>)" << std::endl;

	if (release) {
		if (before < buffer.str().size()) {
			std::wcout << L"Writing Cadenassage to buffer..." << std::endl;
		}
		else {
			std::wcout << L"Failed to write Cadenassage to buffer..." << std::endl;
		}
	}
}

void HtmlGenerator::addSubmitbuttonHtml(bool release) {
	size_t before = buffer.str().size();

	//HTML CODE
	buffer << R"(
   </form>
    <div style="text-align: center;">
	<button id="submitBtn">Submit</button>
    </div>

    
    

<script>
    function generatePDF(){
	
	var printPage = true;
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
	
	
	
	if (printPage){
		window.print();  
	}
	
	
}
    var button = document.getElementById('submitBtn');
    button.onclick = generatePDF 
    
</script>

</body>
</html>
    
    )" << std::endl;



	if (release) {
		if (before < buffer.str().size()) {
			std::wcout << L"Writing Submit Button to buffer..." << std::endl;
		}
		else {
			std::wcout << L"Failed to write Submit Button to buffer..." << std::endl;
		}
	}
}

void HtmlGenerator::addPagebreakHtml(bool release) {

	int before = buffer.str().size();

	buffer << R"(<div class="html2pdf__pagebreak"></div>)" << std::endl;




	if (release) {
		if (before < buffer.gcount()) {
			std::wcout << L"Writing Page break to buffer..." << std::endl;
		}
		else {
			std::wcout << L"Failed to write Page break to buffer..." << std::endl;
		}
	}
}

bool HtmlGenerator::addTextFieldHtml(std::wstring inp) {


	size_t found = inp.find(L"-INSERT_TEXTBOX");
	if (found != std::string::npos) {
		buffer << R"(<textarea rows="2" cols="75" placeholder=")" << inp.substr(15, inp.length()) << R"("></textarea>)";

		return true;
	}
	else {
		return false;
	}


}

bool HtmlGenerator::addPictureHtml(std::wstring inp) {


	size_t found = inp.find(L"-INSERT_PICTURE");
	if (found != std::string::npos) {
		buffer << R"(<img style="height: 400px" src=")" << inp.substr(15, inp.length()) << R"("></img>)";
		std::wcout << "FOUND PICTURE!";

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
      <div id="Taches">
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
    
         <div style="clear: both; padding-bottom: 50px; padding-left: 50px;">)";
			}
			else {
				buffer << R"(
            <div style="clear: both; padding-bottom: 50px;">)";
			}


			//Write array to buffer
			buffer << R"(
               <div>
        	      <input type="checkbox" id="taskCheckbox)" << i << R"(" name="taskCheckbox)" << i << R"("class="mustcheck" required>
        	      <label for="taskLabel)" << i << R"(">)" << tachesStrings[i] << R"(</label><br>
    	       </div>
    	       <div>
    	          <div style="float:left; padding-left: 20px;">
    			     <input type="checkbox" id="taskConforme)" << i << R"(" name="taskConforme)" << i << R"(">
    			     <label for="labelConforme)" << i << R"(">Conforme</label><br>
    		      </div> 	
    		
    	          <div style="float:left; padding-left: 20px;">
    		         <input type="checkbox" id="taskRepare)" << i << R"(" name="taskRepare)" << i << R"(">
    		         <label for="labelRepare)" << i << R"(">Réparé</label><br>
    		      </div>
    		
    		      <div style="float:left; padding-left: 20px;">
    		         <input type="checkbox" id="taskRemplace)" << i << R"(" name="taskRemplace)" << i << R"(">
    		         <label for="labelRemplace)" << i << R"(">Remplacé</label><br>
    		      </div>
    		      <div style="float:left; padding-left: 20px;">
    		         <input type="checkbox" id="taskAvis)" << i << R"(" name="taskAvis)" << i << R"(">
    		         <label for="labelAvis)" << i << R"(">Avis Créer:</label><br>
    		      </div>
    		
    		      <div style="float:left; padding-left: 5px;">
    		         <input  type="text" id="taskAvisText)" << i << R"(" name="taskAvisText)" << i << R"(" value="">
    			  </div>
    	       </div>
            </div>
            )" << std::endl;

		}
		//<?php echo isset($_POST['name']) ? htmlspecialchars($_POST['name'], ENT_QUOTES) : ''; ?>
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
			std::wcout << L"Writing Taches to buffer..." << std::endl;

		}
		else {
			std::wcout << L"Tache vector is EMPTY..." << std::endl;
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
        <div id=")" << input << R"(">
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

            <div style="clear: both; padding-bottom: 50px; padding-left: 50px;">)" << std::endl;
				}
				else {
					buffer << R"(

            <div style="clear: both; padding-bottom: 50px;">)" << std::endl;
				}


				//Write array to buffer
				buffer << R"(

        	    <div>
    	        	<input type="checkbox" id="tache)" << i << unknownTimesUsed << R"(" name="tache)" << i << unknownTimesUsed << R"(">
    	        	<label for="tache)" << i << unknownTimesUsed << R"(">)" << unknownStrings[i] << R"(</label><br>
	    	    </div>
	
	            <div>

		            <div style="float:left; padding-left: 20px;">
			            <input type="checkbox" id="tache)" << i << unknownTimesUsed << R"(" name="tache)" << i << unknownTimesUsed << R"(">
			            <label for="tache)" << i << unknownTimesUsed << R"(">Conforme</label><br>
		            </div> 	
		
	            	<div style="float:left; padding-left: 20px;">
		            	<input type="checkbox" id="tache)" << i << unknownTimesUsed << R"(" name="tache)" << i << unknownTimesUsed << R"(">
		            	<label for="tache)" << i << unknownTimesUsed << R"(">Repare</label><br>
		            </div>
		
		            <div style="float:left; padding-left: 20px;">
		            	<input type="checkbox" id="tache)" << i << unknownTimesUsed << R"(" name="tache)" << i << unknownTimesUsed << R"(">
		            	<label for="tache)" << i << unknownTimesUsed << R"(">Remplace</label><br>
		            </div>
		
		            <div style="float:left; padding-left: 20px;">
		            	<input type="checkbox" id="tache)" << i << unknownTimesUsed << R"(" name="tache)" << i << unknownTimesUsed << R"(">
		            	<label for="tache)" << i << unknownTimesUsed << R"(">Avis Creer:</label><br>
		            </div>
		
		            <div style="float:left; padding-left: 5px;">
		            	<input type="text" id="tache)" << i << unknownTimesUsed << R"(" name="tache)" << i << unknownTimesUsed << R"(">
			
		            </div>
	
                </div>

            
        )" << std::endl;

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
			std::wcout << L"Writing Unknowns to buffer..." << std::endl;

		}
		else {
			std::wcout << L"Unknowns vector is EMPTY..." << std::endl;
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
	}
	else {
		std::wcout << L"Unable to open file";
	}


}