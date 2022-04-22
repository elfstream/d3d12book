call "%vsdevcmd_path%\Common7\Tools\VsDevCmd.bat" -arch=amd64
where cl

echo ------------------------Ready to Rebuild-----------------------
"D:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\devenv.com" .\DX12All\DX12All.sln /Rebuild "Release|x64"

echo ------------------------ end of build ---------------------

REM .\DX12All\x64\Release\MyFirstGTestProj.exe
pwd
REM echo check net config
REM ipconfig 