; -- UninstallCodeExample1.iss --
;
; This script shows various things you can achieve using a [Code] section for Uninstall

[Setup]
AppName=Magic Passwords
AppVersion=1.0.4
AppPublisher=Moneetor
AppPublisherURL=http://www.moneetor.mon.net.pl/
VersionInfoVersion=1.0.4
DefaultDirName={pf}\Magic Passwords
DefaultGroupName=MON.NET\Magic Passwords
UninstallDisplayIcon={app}\MagicPasswords.exe
SetupIconFile=GFX\MP.ico
OutputDir=snapshot
OutputBaseFilename=MagicPassword_1.0.4

[Files]
Source: "MagicPasswords.exe"; DestDir: "{app}"
Source: "video\monnet.avi"; DestDir: "{app}\video"
Source: "Readme-pl.txt"; DestDir: "{app}"; Flags: isreadme
Source: "Readme-en.txt"; DestDir: "{app}"; Flags: isreadme
Source: "changelog-pl.txt"; DestDir: "{app}";
Source: "changelog-en.txt"; DestDir: "{app}";
Source: "bpl\vcl50.bpl"; DestDir: "{sys}"; Flags: "sharedfile"
Source: "bpl\bcbsmp50.bpl"; DestDir: "{sys}"; Flags: "sharedfile"
Source: "bpl\vclx50.bpl"; DestDir: "{sys}"; Flags: "sharedfile"
Source: "dll\borlndmm.dll"; DestDir: "{sys}"; Flags: "sharedfile"
Source: "dll\cc3250mt.dll"; DestDir: "{sys}"; Flags: "sharedfile"
Source: "lang\pl.lang"; DestDir: "{app}\lang";
Source: "lang\en.lang"; DestDir: "{app}\lang";
Source: "lang\list.txt"; DestDir: "{app}\lang";
 
[Languages]
Name: pl; MessagesFile: "compiler:Languages\Polish.isl"

[Icons]
Name: "{group}\Magic Passwords"; Filename: "{app}\MagicPasswords.exe"
Name: "{group}\Magic Passwords Readme - pl"; Filename: "{app}\Readme-pl.txt"
Name: "{group}\Magic Passwords Readme - en"; Filename: "{app}\Readme-en.txt"
Name: "{commondesktop}\Magic Passwords"; Filename: "{app}\MagicPasswords.exe"

[Registry]
; Start "Software\My Company\My Program" keys under HKEY_CURRENT_USER
; and HKEY_LOCAL_MACHINE. The flags tell it to always delete the
; "My Program" keys upon uninstall, and delete the "My Company" keys
; if there is nothing left in them.
Root: HKCU; Subkey: "Software\MON.NET"; Flags: uninsdeletekeyifempty
Root: HKCU; Subkey: "Software\MON.NET\Updater"; Flags: uninsdeletekeyifempty
Root: HKCU; Subkey: "Software\MON.NET\Updater\Magic Passwords"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\MON.NET\Updater\Magic Passwords"; ValueType: string; ValueName: "Root"; ValueData: "HKCU"
Root: HKCU; Subkey: "Software\MON.NET\Updater\Magic Passwords"; ValueType: string; ValueName: "Key"; ValueData: "Software\MON.NET\Magic Passwords"
Root: HKCU; Subkey: "Software\MON.NET\Magic Passwords"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\MON.NET\Magic Passwords"; ValueType: string; ValueName: "Path"; ValueData: "{app}"
Root: HKCU; Subkey: "Software\MON.NET\Magic Passwords"; ValueType: string; ValueName: "Version"; ValueData: "1.0.4"
Root: HKCU; Subkey: "Software\MON.NET\Magic Passwords"; ValueType: string; ValueName: "Language"; ValueData: "pl"

[Code]
function InitializeUninstall(): Boolean;
begin
  Result := MsgBox('InitializeUninstall:' #13#13 'Deinstalacja zosta�a zainicjalizowana. Czy naprawd� chcesz rozpocz�� Deinstalacj�?', mbConfirmation, MB_YESNO) = idYes;
  if Result = False then
    MsgBox('InitializeUninstall:' #13#13 'Ok, Pa Pa.', mbInformation, MB_OK);
end;

procedure DeinitializeUninstall();
begin
  MsgBox('DeinitializeUninstall:' #13#13 'Pa Pa!', mbInformation, MB_OK);
end;

procedure CurUninstallStepChanged(CurUninstallStep: TUninstallStep);
begin
  case CurUninstallStep of
    usUninstall:
      begin
        MsgBox('CurUninstallStepChanged:' #13#13 'Deinstalacja uruchomiona.', mbInformation, MB_OK)
        // ...insert code to perform pre-uninstall tasks here...
      end;
    usPostUninstall:
      begin
        MsgBox('CurUninstallStepChanged:' #13#13 'Deinstalacja zako�czona.', mbInformation, MB_OK);
        // ...insert code to perform post-uninstall tasks here...
      end;
  end;
end;
