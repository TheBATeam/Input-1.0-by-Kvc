@Echo off
cls

Title Input - Demo - www.thebateam.org
Set "Path=%Path%;%cd%;%cd%\files"
Color 0a
Echo. Please Click with MOUSE or Press KEYBOARD button now!
Echo.
:Top
For /f "Tokens=1,2,3,4* delims=:" %%A in ('Input.exe') Do (
	Set _Input_Type=%%A
	Set _Parameter_1=%%B
	Set _Parameter_2=%%C
	Set _Parameter_3=%%D
	Title Input Test By Kvc [%%A:%%B:%%C:%%D]
	)

REM Assuring Mouse Input...
IF /I "%_Input_Type%" == "m" (Echo. Mouse Input...)
IF /I "%_Input_Type%" == "k" (Echo. Keyboad Input...)

Goto :Top
