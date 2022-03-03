using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using Outlook = Microsoft.Office.Interop.Outlook;


class MainClass
{
    static int Main(string[] args)
    {

        //Get current user for filepaths
        string userName = Environment.UserName;
        Console.WriteLine(userName);

        //Read a text file with recipients
        string[] lines = System.IO.File.ReadAllLines(@"C:\Users\pw192717\Desktop\pm_testing_saving_emailing\outlook_details.txt");

        List<string> recipients = new List<string>();
        List<string> cc_people = new List<string>();
        List<string> body_lines = new List<string>();
        List<string> attachments = new List<string>();
        List<string> subjects = new List<string>();

        bool in_recipients = false;
        bool in_cc_people = false;
        bool in_body_lines = false;
        bool in_attachments = false;
        bool in_subject = false;




        foreach (string line in lines)
        {
            if (line == "***Recipients***")
            {
                in_recipients = true;

            }
            else if (line == "***CC***")
            {
                in_cc_people = true;
                in_recipients = false;
                
            }
            else if (line == "***Subject***")
            {
                in_subject = true;
                in_cc_people = false;
            }
            else if (line == "***Body***")
            {
                in_body_lines = true;
                in_subject = false;
                
            }
            else if (line == "***Attachment Path***")
            {
                in_attachments = true;
                in_body_lines = false;
            }


            if (in_recipients)
            {
                if (line != "")
                {
                    recipients.Add(line);
                }
                
            }
            else if (in_cc_people)
            {
                if (line != "")
                {
                    cc_people.Add(line);
                }
            }
            else if (in_subject)
            {
                if (line != "")
                {
                    subjects.Add(line);
                }
            }

            else if (in_body_lines)
            {
                if (line != "")
                {
                    body_lines.Add(line);
                }
            }
            else if (in_attachments)
            {
                if (line != "")
                {
                    attachments.Add(line);
                }
            }
        }


        //Remove titles

        recipients.RemoveAt(0);
        cc_people.RemoveAt(0);
        subjects.RemoveAt(0);
        body_lines.RemoveAt(0);
        attachments.RemoveAt(0);



        // Display the file contents by using a foreach loop.

        Console.WriteLine("Recipient list content:");
        foreach (string recipient in recipients)
        {
            // Use a tab to indent each line of the file.
            Console.WriteLine("\t" + recipient);
        }

        Console.WriteLine("CC list content:");
        foreach (string cc in cc_people)
        {
            // Use a tab to indent each line of the file.
            Console.WriteLine("\t" + cc);
        }
        Console.WriteLine("Subject list content:");
        foreach (string subject in subjects)
        {
            // Use a tab to indent each line of the file.
            Console.WriteLine("\t" + subject);
        }
        Console.WriteLine("Body list content:");
        foreach (string line in body_lines)
        {
            // Use a tab to indent each line of the file.
            Console.WriteLine("\t" + line);
        }
        Console.WriteLine("Attachment list content:");
        foreach (string path in attachments)
        {
            // Use a tab to indent each line of the file.
            Console.WriteLine("\t" + path);
        }






        Outlook.Application outlookApp = new Outlook.Application();
        Outlook._MailItem oMailItem = (Outlook._MailItem)outlookApp.CreateItem(Outlook.OlItemType.olMailItem);
        Outlook.Inspector oInspector = oMailItem.GetInspector;



        // Recipient
        Outlook.Recipients oRecips = (Outlook.Recipients)oMailItem.Recipients;
        foreach (String recipient in recipients)
        {
            Outlook.Recipient oRecip = (Outlook.Recipient)oRecips.Add(recipient);
            oRecip.Resolve();
        }


        //Add CC
      

        foreach (String cc in cc_people)
        {
            Outlook.Recipient oCCRecip = oRecips.Add(cc);
            oCCRecip.Type = (int)Outlook.OlMailRecipientType.olCC;
            oCCRecip.Resolve();
        }




        
        




        //Add Subject
        oMailItem.Subject = subjects[0];

        String combined_body = "";

        foreach (String line in body_lines)
        {
            combined_body += line +"\n";
        }
        oMailItem.Body = combined_body;

        //Get name of most recent pdf (Desired File)
        DirectoryInfo info = new DirectoryInfo("c:/users/" + userName + "/Downloads");
        FileInfo[] pdfList = info.GetFiles("*.pdf").OrderBy(p => p.CreationTime).ToArray();

        foreach (FileInfo pdf in pdfList)
        {
            //Console.WriteLine(pdf.Name);
        }

        String sourceFile = pdfList.Last().FullName;
        Console.WriteLine(sourceFile);
        

        //Add Attachment
        //**Need to make this dynamic**
        oMailItem.Attachments.Add("C:/Users/pw192717/Desktop/pm_testing_saving_emailing/PM.html", Outlook.OlAttachmentType.olByValue,1,"PM");

        

        // body, bcc etc...
        oMailItem.Display(true);


        //Save a copy of most recent pdf to O:/
        String targetPath = @"O:\TFM_GESTION\PM\1- TEMPLATES\";
        String destFile = targetPath + pdfList.Last().Name;
       
        System.IO.File.Copy(sourceFile, destFile, true);

        //Delete .hta file
        String htaPath = "C:/Users/" + userName + "/Downloads/AppExec.hta";

            //Check if file exists
            if (File.Exists(htaPath))
            {
            File.Delete(htaPath);
            Console.WriteLine("Cleanup success!");

            }
        else
        {
            Console.WriteLine("Cleanup Error!")
;        }





        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        System.Console.ReadKey();
        return 0;
    }
}
