echo ------------------------Ready to Scan Code-----------------------
mkdir ScanResult
"%TSCANCODE%TscanCode.exe" -UDEBUG --enable=warning --std=c++11 --xml -j 6 . 2>ScanResult\ScanResult.xml