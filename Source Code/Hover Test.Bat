@Echo off
cls

Title Hover Test- Demo - www.thebateam.org
Set "Path=%Path%;%cd%;%cd%\files"

color 08
Echo. 
Echo. Hello, I'm a Text, Please Hover me...

:Top
For /f "Tokens=1,2,3,4* delims=:" %%A in ('Input.exe F') Do (
	Set _Input_Type=%%A
	Set _Parameter_1=%%B
	Set _Parameter_2=%%C
	Set _Parameter_3=%%D
	)

REM Assuring Mouse Input...
IF /I "%_Input_Type%" == "m" (
	REM Assuring No Clicking, only Hover...
	IF /I "%_Parameter_1%" == "0" (
		If %_Parameter_2% Gtr 1 If %_Parameter_2% Lss 42 If %_Parameter_3% EQU 1 (batbox /g 1 1 /c 0x0f /d "Hello, I'm a Text, Please Hover me... :]") ELSE (batbox /g 1 1 /c 0x08 /d "Hello, I'm a Text, Please Hover me... :]")
		)
	)

Goto :Top
