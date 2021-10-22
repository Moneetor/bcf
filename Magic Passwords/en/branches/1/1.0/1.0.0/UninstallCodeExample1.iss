; -- UninstallCodeExample1.iss --
;
; This script shows various things you can achieve using a [Code] section for Uninstall

[Setup]
AppName=Magic Passwords
AppVersion=1.0.0
DefaultDirName={pf}\Magic Passwords
DefaultGroupName=MON.NET
UninstallDisplayIcon={app}\MagicPasswords.exe
OutputDir=snapshot

[Files]
Source: "MagicPasswords.exe"; DestDir: "{app}"
Source: "video\monnet.avi"; DestDir: "{app}\video"
Source: "Readme.txt"; DestDir: "{app}"; Flags: isreadme
Source: "bpl\vcl50.bpl"; DestDir: "{sys}"; Flags: "sharedfile"
Source: "dll\borlndmm.dll"; DestDir: "{sys}"; Flags: "sharedfile"
Source: "dll\cc3250mt.dll"; DestDir: "{sys}"; Flags: "sharedfile"
 
[Icons]
Name: "{group}\Magic Passwords"; Filename: "{app}\MagicPasswords.exe"

[Registry]
; Start "Software\My Company\My Program" keys under HKEY_CURRENT_USER
; and HKEY_LOCAL_MACHINE. The flags tell it to always delete the
; "My Program" keys upon uninstall, and delete the "My Company" keys
; if there is nothing left in them.
Root: HKCU; Subkey: "Software\MON.NET"; Flags: uninsdeletekeyifempty
Root: HKCU; Subkey: "Software\MON.NET\Magic Passwords"; Flags: uninsdeletekey
Root: HKLM; Subkey: "Software\MON.NET"; Flags: uninsdeletekeyifempty
Root: HKLM; Subkey: "Software\MON.NET\Magic Passwords"; Flags: uninsdeletekey
Root: HKLM; Subkey: "Software\MON.NET\Magic Passwords"; ValueType: string; ValueName: "Path"; ValueData: "{app}"
Root: HKLM; Subkey: "Software\MON.NET\Magic Passwords"; ValueType: string; ValueName: "Version"; ValueData: "1.0.0"

[Code]
function InitializeUninstall(): Boolean;
begin
  Result := MsgBox('InitializeUninstall:' #13#13 'Uninstall is initializing. Do you really want to start Uninstall?', mbConfirmation, MB_YESNO) = idYes;
  if Result = False then
    MsgBox('InitializeUninstall:' #13#13 'Ok, bye bye.', mbInformation, MB_OK);
end;

procedure DeinitializeUninstall();
begin
  MsgBox('DeinitializeUninstall:' #13#13 'Bye bye!', mbInformation, MB_OK);
end;

procedure CurUninstallStepChanged(CurUninstallStep: TUninstallStep);
begin
  case CurUninstallStep of
    usUninstall:
      begin
        MsgBox('CurUninstallStepChanged:' #13#13 'Uninstall is about to start.', mbInformation, MB_OK)
        // ...insert code to perform pre-uninstall tasks here...
      end;
    usPostUninstall:
      begin
        MsgBox('CurUninstallStepChanged:' #13#13 'Uninstall just finished.', mbInformation, MB_OK);
        // ...insert code to perform post-uninstall tasks here...
      end;
  end;
end;
