; -- UninstallCodeExample1.iss --
;
; This script shows various things you can achieve using a [Code] section for Uninstall

[Setup]
AppName=Magic Passwords
AppVersion=1.0.3
AppPublisher=Moneetor
AppPublisherURL=http://www.moneetor.mon.net.pl/
VersionInfoVersion=1.0.3
AppId=Magic Passwords
DefaultDirName={pf}\Magic Passwords
DefaultGroupName=MON.NET\Magic Passwords
UninstallDisplayIcon={app}\MagicPasswords.exe
OutputDir=snapshot
OutputBaseFilename=MagicPasswords_update-1.0.2-1.0.3-pl
Uninstallable=no

[Files]
Source: "MagicPasswords.exe"; DestDir: "{app}"
Source: "Readme.txt"; DestDir: "{app}"; Flags: isreadme
Source: "changelog.txt"; DestDir: "{app}"
Source: "lang\pl.lang"; DestDir: "{app}\lang";
 
[Languages]
Name: pl; MessagesFile: "compiler:Languages\Polish.isl"

[Registry]
; Start "Software\My Company\My Program" keys under HKEY_CURRENT_USER
; and HKEY_LOCAL_MACHINE. The flags tell it to always delete the
; "My Program" keys upon uninstall, and delete the "My Company" keys
; if there is nothing left in them.
Root: HKCU; Subkey: "Software\MON.NET"; Flags: uninsdeletekeyifempty
Root: HKCU; Subkey: "Software\2012 Era"; Flags: uninsdeletekeyifempty
Root: HKCU; Subkey: "Software\MON.NET\Updater"; Flags: uninsdeletekeyifempty
Root: HKCU; Subkey: "Software\MON.NET\Updater\Magic Passwords"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\MON.NET\Updater\Magic Passwords"; ValueType: string; ValueName: "Root"; ValueData: "HKCU"
Root: HKCU; Subkey: "Software\MON.NET\Updater\Magic Passwords"; ValueType: string; ValueName: "Key"; ValueData: "Software\2012 Era\Magic Passwords"
Root: HKCU; Subkey: "Software\2012 Era\Magic Passwords"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\2012 Era\Magic Passwords"; ValueType: string; ValueName: "Path"; ValueData: "{app}"
Root: HKCU; Subkey: "Software\2012 Era\Magic Passwords"; ValueType: string; ValueName: "Version"; ValueData: "1.0.3"
Root: HKCU; Subkey: "Software\2012 Era\Magic Passwords"; ValueType: string; ValueName: "Language"; ValueData: "pl"

[Code]
function InitializeUninstall(): Boolean;
begin
  Result := MsgBox('InitializeUninstall:' #13#13 'Deinstalacja zosta³a zainicjalizowana. Czy naprawdê chcesz rozpocz¹æ Deinstalacjê?', mbConfirmation, MB_YESNO) = idYes;
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
        MsgBox('CurUninstallStepChanged:' #13#13 'Deinstalacja zakoñczona.', mbInformation, MB_OK);
        // ...insert code to perform post-uninstall tasks here...
      end;
  end;
end;
