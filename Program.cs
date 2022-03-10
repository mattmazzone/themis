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

        //Assign download directory
        DirectoryInfo downloadDir = new DirectoryInfo("c:/users/" + userName + "/Downloads");

        //Get name of most recent PDF in downloads 
        FileInfo[] pdfList = downloadDir.GetFiles("*.pdf").OrderBy(p => p.CreationTime).ToArray();
        string pdfFile = pdfList.Last().FullName;

        //Get name of most recent HTML in downloads
        FileInfo[] htmlList = downloadDir.GetFiles("*.html").OrderBy(p => p.CreationTime).ToArray();
        string htmlFile = htmlList.Last().FullName;



        //Find the path info stored in HTML file
        string functionnal_location = "";
        string equipment_number = "";
        string task_number = "";
        foreach (string line in System.IO.File.ReadLines(htmlFile))
        {
            if (line.Contains("func_location:"))
            {
                functionnal_location = line.Substring(15);

            }
            else if (line.Contains("equip_num:"))
            {
                equipment_number = line.Substring(11);

            }
            else if (line.Contains("task_num:"))
            {
                task_number = line.Substring(10);
                break;
            }

        }
        //Save a copy of most recent pdf to O:/
        string targetPath = "O:/TFM_GESTION/PM/" + functionnal_location + "/" + equipment_number + "/" + task_number + "/";
        if (Directory.Exists(targetPath))
        {
            string destFile = targetPath + pdfList.Last().Name;
            System.IO.File.Copy(pdfFile, destFile, true);
            Console.WriteLine("Copied File to specified directory");
        }
        else
        {
            targetPath = @"O:/TFM_GESTION/PM/BACKUP/";
            string destFile = targetPath + pdfList.Last().Name;
            System.IO.File.Copy(pdfFile, destFile, true);
            Console.WriteLine("Copied File to BACKUP directory");
        }

               

        //Read a text file with recipients
        string[] lines = System.IO.File.ReadAllLines(@"O:\TFM_GESTION\PM\1_TEMPLATES\WebCompanion\outlook_details.txt");

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



        //Parse outlook_details.txt and assign respective List Variables
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

            //Don't add empty lines to Lists
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


        //Remove titles from Lists
        recipients.RemoveAt(0);
        cc_people.RemoveAt(0);
        subjects.RemoveAt(0);
        body_lines.RemoveAt(0);
        attachments.RemoveAt(0);


        //Create outlookApp object and bring new email window to foreground
        Outlook.Application outlookApp = new Outlook.Application();
        Outlook._MailItem oMailItem = (Outlook._MailItem)outlookApp.CreateItem(Outlook.OlItemType.olMailItem);
        Outlook.Inspector oInspector = oMailItem.GetInspector;
        oInspector.Activate();



        //Add Recipients to the new email
        Outlook.Recipients oRecips = (Outlook.Recipients)oMailItem.Recipients;
        foreach (string recipient in recipients)
        {
            Outlook.Recipient oRecip = (Outlook.Recipient)oRecips.Add(recipient);
            oRecip.Resolve();
        }


        //Add CC to the new email
        foreach (string cc in cc_people)
        {
            Outlook.Recipient oCCRecip = oRecips.Add(cc);
            oCCRecip.Type = (int)Outlook.OlMailRecipientType.olCC;
            oCCRecip.Resolve();
        }


        //Add Subject to the new email
        oMailItem.Subject = subjects[0];


        //Add body to the new email
        string combined_body = "";
        foreach (string line in body_lines)
        {
            combined_body += line + "\n";
        }
        oMailItem.Body = combined_body;


        //Add Attachment
        oMailItem.Attachments.Add(pdfList.Last().FullName, Outlook.OlAttachmentType.olByValue, 1, pdfList.Last().Name);
               
        // body, bcc etc...
        try //New mail tab already open EXCEPTION
        {
            oMailItem.Display(true);
        }
        catch (System.Runtime.InteropServices.COMException)
        {
            System.Windows.Forms.MessageBox.Show("Close open Outlook tabs and try again!");

        }
        
        //Delete .hta file
        string htaPath = "C:/Users/" + userName + "/Downloads/AppExec.hta";

        //Check if file exists
        if (File.Exists(htaPath))
        {
            File.Delete(htaPath);
            Console.WriteLine("Cleanup success!");
        }
        else
        {
            Console.WriteLine("Cleanup Error!")
;
        }





        // Keep the console window open in debug mode.
        Console.WriteLine("Press any key to exit.");
        System.Console.ReadKey();
        return 0;
    }
}
