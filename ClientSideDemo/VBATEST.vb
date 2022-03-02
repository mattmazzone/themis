Dim OutApp As Outlook.Application
Dim objMsg As MailItem
Set OutApp = CreateObject("Outlook.Application")
Set objMsg = OutApp.CreateItem(olMailItem)
With objMsg
  .Body = messageBody
  .Display
End With