;--------------------------------
;Include Modern UI

	!include "MUI2.nsh"

;--------------------------------
;General

	!define OVERLAY_BASEDIR "..\client_overlay_standalone\bin\win64"
	!define OVERLAY_WIP_BASEDIR "..\client_overlay\bin\win64"

	;Name and file
	Name "OpenVR Walk In Place"
	OutFile "OpenVR-WalkInPlace-OVRIE-driver.exe"
	
	;Default installation folder
	InstallDir "$PROGRAMFILES64\OpenVR-WalkInPlace"
	
	;Get installation folder from registry if available
	InstallDirRegKey HKLM "Software\OpenVR-WalkInPlace\Overlay" ""
	
	;Request application privileges for Windows Vista
	RequestExecutionLevel admin
	
;--------------------------------
;Variables

VAR upgradeInstallation

;--------------------------------
;Interface Settings

	!define MUI_ABORTWARNING

;--------------------------------
;Pages

	!insertmacro MUI_PAGE_LICENSE "..\LICENSE"
	!define MUI_PAGE_CUSTOMFUNCTION_PRE dirPre
	!insertmacro MUI_PAGE_DIRECTORY
	!insertmacro MUI_PAGE_INSTFILES
  
	!insertmacro MUI_UNPAGE_CONFIRM
	!insertmacro MUI_UNPAGE_INSTFILES
  
;--------------------------------
;Languages
 
	!insertmacro MUI_LANGUAGE "English"

;--------------------------------
;Macros

;--------------------------------
;Functions

Function dirPre
	StrCmp $upgradeInstallation "true" 0 +2 
		Abort
FunctionEnd

Function .onInit
	StrCpy $upgradeInstallation "false"
 
	; If OVRIE is not installed then cannot continue
	IfFileExists $INSTDIR\..\OpenVR-InputEmulator\OpenVR-InputEmulatorOverlay.exe +5 0
	MessageBox MB_OK|MB_ICONEXCLAMATION \
		"OpenVR-InputEmulator is not installed.$\nPlease either install OpenVR-InputEmulator's driver system.$\nOr use OpenVR-WalkInPlace's driver system by using the main installer."
	Abort 

	ReadRegStr $R0 HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\OpenVRWalkInPlace" "UninstallString"
	StrCmp $R0 "" done
		
	; If SteamVR is already running, display a warning message and exit
	FindWindow $0 "Qt5QWindowIcon" "SteamVR Status"
	StrCmp $0 0 +3
		MessageBox MB_OK|MB_ICONEXCLAMATION \
			"SteamVR is still running. Cannot install this software.$\nPlease close SteamVR and try again."
		Abort
	
	MessageBox MB_OKCANCEL|MB_ICONEXCLAMATION \
		"OpenVR Walk In Place is already installed. $\n$\nClick `OK` to upgrade the \
		existing installation or `Cancel` to cancel this upgrade." \
		IDOK upgrade
	Abort
 
	upgrade:
		StrCpy $upgradeInstallation "true"
	done:
FunctionEnd

;--------------------------------
;Installer Sections

Section "Install" SecInstall
	
	StrCmp $upgradeInstallation "true" 0 noupgrade 
		DetailPrint "Uninstall previous version..."
		ExecWait '"$INSTDIR\Uninstall.exe" /S _?=$INSTDIR'
		Delete $INSTDIR\Uninstall.exe
		Goto afterupgrade
		
	noupgrade:

	afterupgrade:

	SetOutPath "$INSTDIR"

	;ADD YOUR OWN FILES HERE...
	File "${OVERLAY_BASEDIR}\*.exe"
	File "${OVERLAY_WIP_BASEDIR}\*.vrmanifest"
	File "${OVERLAY_WIP_BASEDIR}\*.conf"
	File "${OVERLAY_WIP_BASEDIR}\LICENSE"
	File "${OVERLAY_WIP_BASEDIR}\*.dll"
	File "${OVERLAY_WIP_BASEDIR}\*.bat"
	File /r "${OVERLAY_WIP_BASEDIR}\res"
	File /r "${OVERLAY_WIP_BASEDIR}\qtdata"


	; Install redistributable
	ExecWait '"$INSTDIR\vcredist_x64.exe" /install /quiet'
		
	; Install the vrmanifest
	nsExec::ExecToLog '"$INSTDIR\OpenVR-WalkInPlaceOverlay.exe" -installmanifest'
	
	; Post-installation step
	nsExec::ExecToLog '"$INSTDIR\OpenVR-WalkInPlaceOverlay.exe" -postinstallationstep'
  
	;Store installation folder
	WriteRegStr HKLM "Software\OpenVR-WalkInPlace\Overlay" "" $INSTDIR
  
	;Create uninstaller
	WriteUninstaller "$INSTDIR\Uninstall.exe"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\OpenVRWalkInPlace" "DisplayName" "OpenVR Walk In Place"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\OpenVRWalkInPlace" "UninstallString" "$\"$INSTDIR\Uninstall.exe$\""

SectionEnd

;--------------------------------
;Uninstaller Section

Section "Uninstall"
	; If SteamVR is already running, display a warning message and exit
	FindWindow $0 "Qt5QWindowIcon" "SteamVR Status"
	StrCmp $0 0 +3
		MessageBox MB_OK|MB_ICONEXCLAMATION \
			"SteamVR is still running. Cannot uninstall this software.$\nPlease close SteamVR and try again."
		Abort

	; Remove the vrmanifest
	nsExec::ExecToLog '"$INSTDIR\OpenVR-WalkInPlaceOverlay.exe" -removemanifest'
	
	!include uninstallFiles.list

	DeleteRegKey HKLM "Software\OpenVR-WalkInPlace\Overlay"
	DeleteRegKey HKLM "Software\OpenVR-WalkInPlace"
	DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\OpenVRWalkInPlace"
SectionEnd

