set MATLAB=C:\Arquivos de programas\MATLAB\R2008b
set MSVCDir=c:\arquivos de programas\microsoft visual studio 9.0\VC

"C:\Arquivos de programas\MATLAB\R2008b\rtw\bin\win32\envcheck" INCLUDE "c:\arquivos de programas\microsoft visual studio 9.0\VC\include"
if errorlevel 1 goto vcvars32
"C:\Arquivos de programas\MATLAB\R2008b\rtw\bin\win32\envcheck" PATH "c:\arquivos de programas\microsoft visual studio 9.0\VC\bin"
if errorlevel 1 goto vcvars32
goto make

:vcvars32
set VSINSTALLDIR=c:\arquivos de programas\microsoft visual studio 9.0
set VCINSTALLDIR=c:\arquivos de programas\microsoft visual studio 9.0\VC
set FrameworkSDKDir=c:\arquivos de programas\microsoft visual studio 9.0\SDK\v3.5
call "C:\Arquivos de programas\MATLAB\R2008b\toolbox\rtw\rtw\private\vcvars32_900.bat"

:make
cd .
nmake -f template_linear.mk  GENERATE_REPORT=0 MAT_FILE=0 DEBUG=0 DEBUG_HEAP=0
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
