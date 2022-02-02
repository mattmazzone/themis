#include "htmlManip.h"




HtmlGenerator::HtmlGenerator(std::string path, std::vector<std::string> formattedFile){
    outputPath = path;
    this->formattedFile = formattedFile;
    
    //Create file with same name but .html extension
    outputPath.replace(outputPath.end()-4,outputPath.end(),".html");
}

void HtmlGenerator::addHeadHtml(bool release) {
    
    std::size_t found = outputPath.find_last_of("/\\");
    std::string pageTitle = outputPath.substr(found+1);
    
    

    buffer << R"(<!DOCTYPE html>
    <html lang=" en ">
<head>
  <title>)" << pageTitle << R"(</title>
  <meta charset=" UTF - 8 " />
  <meta name=" viewport " content=" width = device - width, initial - scale = 1 " />
  <meta name=" description " content=" " />
</head>
<body>
    <div id="pdf">
)" << std::endl;



}

void HtmlGenerator::addPreparationHtml(bool release){
    
    
    
    //Write the top part of the page
    buffer <<R"(    
        <h1 style="text-align: center;">Maintenance Préventive TFM</h1>
        <h2 style="text-align: center;">TCX-XX</h2>
        <h2 style="text-align: center;">MXXXXX-XX</h2>
        <h2 style="text-align: center;">TXXXXX-XXXX</h2>
    )";

    std::vector<std::string> prepStrings;
    

    std::string input;
    
    size_t foundPrep;
    size_t foundPrep1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    prepStrings.push_back(input);
                    //*buff << input << std::endl;
            }
            else {
                inSection = false;
                
            }
        }
            else {
                //Remove Whitespace from string
                input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
            }

        foundPrep = input.find("<<PREPARATION>>");
        foundPrep1 = input.find("<<PRÉPARATION>>");

        if ((foundPrep != std::string::npos) || (foundPrep1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }

//Remove fake checkboxes from array
for (int i = 0; i < prepStrings.size(); i++){
    std::size_t found = prepStrings[i].find_first_of(")");
    prepStrings[i] = prepStrings[i].substr(found+1);

}
//Section title to buffer
buffer << R"(
        <div id="Preparation">
        	<h3 style="text-align: left; text-decoration: underline;">Préparation</h3>)" << std::endl;
	
//Write array to buffer
for (int i = 0; i < prepStrings.size(); i++){
    buffer << R"(
            <input type="checkbox" id="prep)" << i << R"(" name="prep)" << i << R"(">
            <label for="prep)" << i << R"(">)" << prepStrings[i] << R"(</label><br>)"<< std::endl;
    
}
buffer << R"(
        </div>
    )";



//RELEASE VS DEBUG MODE
if (release){
    if (prepStrings.size()!=0){
        std::cout << "Writing Preparation to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Preparation Array content:" << std::endl;
    for (auto i: prepStrings){
        std::cout << i << std::endl;
    }

}

}

void HtmlGenerator::addPiecesHtml(bool release) {

    std::vector<std::string> piecesStrings;
    

    std::string input;
    
    size_t foundPieces;
    size_t foundPieces1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    piecesStrings.push_back(input);
                    //*buff << input << std::endl;
            }
            else {
                inSection = false;
                
            }
        }
            else {
                //Remove Whitespace from string
                input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
            }

        foundPieces = input.find("<<PIECES>>");
        foundPieces1 = input.find("<<PIÈCES>>");

        if ((foundPieces != std::string::npos) || (foundPieces1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }




//Section title to buffer
buffer << R"(
        <div id="Pieces">
	        <h3 style="text-align: left; text-decoration: underline;">Pièces</h3>
	        
)" << std::endl;
	
//Write array to buffer
if (piecesStrings.size() != 0){
    for (int i = 0; i < piecesStrings.size(); i++){
        buffer << "            <p>" << piecesStrings[i]<< "</p>" << std::endl;
    }
}
else{
    // <p> pas de pieces necessaires    
    }
buffer << R"(
        </div>    
    )";




//RELEASE VS DEBUG MODE
if (release){
    if (piecesStrings.size()!=0){
        std::cout << "Writing Pieces to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Pieces Array content:" << std::endl;
    for (auto i: piecesStrings){
        std::cout << i << std::endl;
    }

}

}

void HtmlGenerator::addConsommablesHtml(bool release) {
    
    std::vector<std::string> consomStrings;

    std::string input;
    
    size_t foundConsom;
    size_t foundConsom1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    consomStrings.push_back(input);
                    //*buff << input << std::endl;
            }
            else {
                inSection = false;
                
            }
        }
        else {
            //Remove Whitespace from string
            input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
        }

        foundConsom = input.find("<<CONSOMMABLES>>");
        foundConsom1 = input.find("<<CONSOMMABLE>>");

        if ((foundConsom != std::string::npos) || (foundConsom1 != std::string::npos)) {
            //Found Consommables (next line until << is good
            inSection = true;
            //std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
        }
    }
    
//Section title to buffer
buffer << R"(
        <div id="Consommables">
        	<h3 style="text-align: left; text-decoration: underline;">Consommables</h3>)" << std::endl;
	
//Write array to buffer
if (consomStrings.size() != 0){
    for (int i = 0; i < consomStrings.size(); i++){
        buffer << "            <p>" << consomStrings[i] << "</p>" << std::endl;
    
    }
}
else {
    //Empty
}

buffer << R"(
        </div>
)";



//RELEASE VS DEBUG MODE
if (release){
    if (consomStrings.size()!=0){
        std::cout << "Writing Consommables to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Consommables Array content:" << std::endl;
    for (auto i: consomStrings){
        std::cout << i << std::endl;
    }

}


}

void HtmlGenerator::addOutilsHtml(bool release){
    std::vector<std::string> outilsStrings;

    std::string input;
    
    size_t foundOutils;
    size_t foundOutils1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    outilsStrings.push_back(input);
                    //*buff << input << std::endl;
            }
            else {
                inSection = false;
                
            }
        }
            else {
                //Remove Whitespace from string
                input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
            }

        foundOutils = input.find("<<OUTILS>>");
        foundOutils1 = input.find("<<OUTIL>>");

        if ((foundOutils != std::string::npos) || (foundOutils1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }

//Section title to buffer
buffer << R"(
        <div id="Outils" style="page-break-after: always">
        	<h3 style="text-align: left; text-decoration: underline;">Outils</h3>)" << std::endl;
	
//Write array to buffer
if (outilsStrings.size() != 0){
    for (int i = 0; i < outilsStrings.size(); i++){
        buffer << "<p>" << outilsStrings[i]<< "</p>" << std::endl;
    }
}
else{
    // <p> pas de pieces necessaires    
    }
    
buffer << R"(
        </div>
)";


//RELEASE VS DEBUG MODE
if (release){
    if (outilsStrings.size()!=0){
        std::cout << "Writing Outils to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Outils Array content:" << std::endl;
    for (auto i: outilsStrings){
        std::cout << i << std::endl;
    }


}
}

void HtmlGenerator::addDocrefHtml(bool release){
    std::vector<std::string> docrefStrings;

    std::string input;
    
    size_t foundDocref;
    size_t foundDocref1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    docrefStrings.push_back(input);
                    //*buff << input << std::endl;
            }
            else {
                inSection = false;
                
            }
        }
            else {
                //Remove Whitespace from string
                input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
            }

        foundDocref = input.find("<<DOCUMENTRÉFÉRENCE>>");
        foundDocref1 = input.find("<<DOCUMENTSRÉFÉRENCES>>");

        if ((foundDocref != std::string::npos) || (foundDocref1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }

//RELEASE VS DEBUG MODE
if (release){
    if (docrefStrings.size()!=0){
        std::cout << "Writing Documents Références to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Documents Références Array content:" << std::endl;
    for (auto i: docrefStrings){
        std::cout << i << std::endl;
    }
}
}

void HtmlGenerator::addSecuriteHtml(bool release){
    std::vector<std::string> securiteStrings;
    std::string input;
    
    size_t foundSecurite;
    size_t foundSecurite1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    securiteStrings.push_back(input);
                    //*buff << input << std::endl;
            }
            else {
                inSection = false;
                
            }
        }
            else {
                //Remove Whitespace from string
                input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
            }

        foundSecurite = input.find("<<SECURITE>>");
        foundSecurite1 = input.find("<<SÉCURITÉ>>");

        if ((foundSecurite != std::string::npos) || (foundSecurite1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }
    
    //Remove fake checkboxes from array
for (int i = 0; i < securiteStrings.size(); i++){
    std::size_t found = securiteStrings[i].find_first_of(")");
    securiteStrings[i] = securiteStrings[i].substr(found+1);

}
//Section title to buffer
buffer << R"(
        <div id="Securite" style="page-break-after: always">
        	<h3 style="text-align: left; text-decoration: underline;">Sécurité</h3>)" << std::endl;
	
//Write array to buffer
for (int i = 0; i < securiteStrings.size(); i++){
    buffer << R"(
            <input type="checkbox" id="sec)" << i << R"(" name="sec)" << i << R"(">
            <label for="sec)" << i << R"(">)" << securiteStrings[i] << R"(</label><br>)"<< std::endl;
    
}
buffer << R"(
        </div>
    )";

    
    
    
    
    //RELEASE VS DEBUG MODE
if (release){
    if (securiteStrings.size()!=0){
        std::cout << "Writing Securite to buffer..." << std::endl;
    }
    
}
else {
    std::cout << "Securite Array content:" << std::endl;
    for (auto i: securiteStrings){
        std::cout << i << std::endl;
    }
}
    
}

void HtmlGenerator::addChecklistHtml(bool release){
    int before = buffer.gcount();
    
    buffer << R"(
        <div id="Checklist" style="page-break-after: always;">
		   <h3 style="text-align: left; text-decoration: underline;">CHECKLIST</h3>
			
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


    if (release)  {
        if (before < buffer.gcount()){
            std::cout << "Writing Checklist to buffer..." << std::endl;
        }
        else{
            std::cout << "Failed to write Checklist to buffer..." << std::endl;
        }
    }
    
}

void HtmlGenerator::addRisquesHtml(bool release){
     int before = buffer.gcount();
    
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
			<button id="riskBtn">
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
    
    
    
    
    if (release)  {
        if (before < buffer.gcount()){
            std::cout << "Writing Risques to buffer..." << std::endl;
        }
        else{
            std::cout << "Failed to write Risques to buffer..." << std::endl;
        }
    }
}

void HtmlGenerator::addFinmaintHtml(bool release) {
        int before = buffer.gcount();
    
    
    //STATIC CODE ADD TO BUFFER
    
    
    
    
    if (release)  {
        if (before < buffer.gcount()){
            std::cout << "Writing Fin Maintenance to buffer..." << std::endl;
        }
        else{
            std::cout << "Failed to write Fin Maintenance to buffer..." << std::endl;
        }
    }
    
}

void HtmlGenerator::addNotesHtml(bool release){
     int before = buffer.gcount();
    
    
    //STATIC CODE ADD TO BUFFER
    
    
    
    
    if (release)  {
        if (before < buffer.gcount()){
            std::cout << "Writing Notes to buffer..." << std::endl;
        }
        else{
            std::cout << "Failed to write Notes to buffer..." << std::endl;
        }
    }
    
}

void HtmlGenerator::addBadgefieldHtml(bool release){
    int before = buffer.gcount();
    
    
    //STATIC CODE ADD TO BUFFER
    
    
    
    
    if (release)  {
        if (before < buffer.gcount()){
            std::cout << "Writing Badge Field to buffer..." << std::endl;
        }
        else{
            std::cout << "Failed to write Badge Field to buffer..." << std::endl;
        }
    }
}

void HtmlGenerator::addSubmitbuttonHtml(bool release){
    int before = buffer.gcount();
    
    
    //HTML CODE
    buffer << R"(
    
    <div style="text-align: center;">
	<button id="submitBtn">Submit</button>
    </div>

    
    )" << std::endl;
    
    //JS CODE
    
    buffer << R"(
<script>
    function generatePDF(){

        var element = document.getElementById('pdf')
        html2pdf(element,{
	        margin:	10,
	        filename: 'myfile.pdf',
	        image:	{ type: 'jpeg', quality: 0.98},
	        html2canvas: { scale: 1, scrollY: 0, logging: true, dpi: 192, letterRendering: true},
	        jsPDF:	{uni :'mm',format: 'a4', orientation: 'portrait'}
        });
    console.log('Generated PDF');
}

    var button = document.getElementById('submitBtn');
    button.onclick = generatePDF 
    
</script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/html2pdf.js/0.10.1/html2pdf.bundle.min.js" integrity="sha512-GsLlZN/3F2ErC5ifS5QtgpiJtWd43JWSuIgh7mbzZ8zBps+dvLusV+eNQATqgA/HdeKFVgA5v3S/cIrLF7QnIg==" crossorigin="anonymous" referrerpolicy="no-referrer"></script>
</body>
</html>
    
    )" <<std::endl;
    
    
    
    if (release)  {
        if (before < buffer.gcount()){
            std::cout << "Writing Submit Button to buffer..." << std::endl;
        }
        else{
            std::cout << "Failed to write Submit Button to buffer..." << std::endl;
        }
    }
}

void HtmlGenerator::addPagebreakHtml(bool release){
    
    int before = buffer.gcount();
    
    buffer << R"(<div class="html2pdf__pagebreak"></div>)" << std::endl;
    
    
    
    
    if (release)  {
        if (before < buffer.gcount()){
            std::cout << "Writing Page break to buffer..." << std::endl;
        }
        else{
            std::cout << "Failed to write Page break to buffer..." << std::endl;
        }
    }
}

void HtmlGenerator::addTachesHtml(bool release) {
   
    std::vector<std::string> tachesStrings;

    std::string input;
    
    size_t foundTaches;
    size_t foundTaches1;
    size_t foundEnd;

    bool inSection = false;



    for (int i = 0; i < formattedFile.size(); i++){
        
        input = formattedFile[i];
        
        if (inSection) {
            foundEnd = input.find("<<");

            if (foundEnd == std::string::npos) {
                    tachesStrings.push_back(input);
                    //*buff << input << std::endl;
            }
            else {
                inSection = false;
                
            }
        }
        else {
            //Remove Whitespace from string
            input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
        }

        foundTaches = input.find("<<TÂCHE>>");
        foundTaches1 = input.find("<<TÂCHES>>");

        if ((foundTaches != std::string::npos) || (foundTaches1 != std::string::npos)) {
            //Found Prepartion (next line until << is good
            inSection = true;
        }
    }
    
    
    
    //Section title to buffer
        buffer << R"(
        <div id="Taches">
        	<h3 style="text-align: left; text-decoration: underline;">Tâches</h3>)" << std::endl;
    
    
    for (int i = 0; i < tachesStrings.size(); i++){

    size_t found_checkmark = tachesStrings[i].find("( )");
    size_t found_checkmark1 = tachesStrings[i].find("()");

    if ((found_checkmark != std::string::npos) || (found_checkmark1 != std::string::npos)) {
        
        //Is a task with checkbox case
        std::size_t found = tachesStrings[i].find_first_of(")");
        tachesStrings[i] = tachesStrings[i].substr(found+1);
       
        
        
	
        //Write array to buffer
        buffer << R"(

            <div style="clear: both; padding-bottom: 50px;">
        	    <div>
    	        	<input type="checkbox" id="tache)" << i <<   R"(" name="tache)" << i << R"(">
    	        	<label for="tache)" << i << R"(">)" << tachesStrings[i] << R"(</label><br>
	    	    </div>
	
	            <div>

		            <div style="float:left; padding-left: 20px;">
			            <input type="checkbox" id="tache)" << i << R"(" name="tache)" << i << R"(">
			            <label for="tache)" << i << R"(">Conforme</label><br>
		            </div> 	
		
	            	<div style="float:left; padding-left: 20px;">
		            	<input type="checkbox" id="tache)" << i << R"(" name="tache)" << i << R"(">
		            	<label for="tache)" << i << R"(">Repare</label><br>
		            </div>
		
		            <div style="float:left; padding-left: 20px;">
		            	<input type="checkbox" id="tache)" << i << R"(" name="tache)" << i << R"(">
		            	<label for="tache)" << i << R"(">Remplace</label><br>
		            </div>
		
		            <div style="float:left; padding-left: 20px;">
		            	<input type="checkbox" id="tache)" << i << R"(" name="tache)" << i << R"(">
		            	<label for="tache)" << i << R"(">Avis Creer:</label><br>
		            </div>
		
		            <div style="float:left; padding-left: 5px;">
		            	<input type="text" id="tache)" << i << R"(" name="tache)" << i << R"(">
			
		            </div>
	
                </div>

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

    
    

    if (release){
        if (tachesStrings.size()!=0){
            std::cout << "Writing Taches to buffer..." << std::endl;
        }
        else {
            std::cout << "Did not detect any Taches in file..." << std::endl;
        }
    }
    else {
        std::cout << "Taches Array content:" << std::endl;
            for (auto i: tachesStrings){
                std::cout << i << std::endl;
            }
    }

    
    
}

void HtmlGenerator::writeBuffertohtml(bool release) {

//Write buffer to created file
    std::ofstream outFile(outputPath);
    if (outFile.is_open()) {

        outFile << buffer.rdbuf();

        outFile.close();
    }
    else {
        std::cout << "Unable to open file";
    }


}