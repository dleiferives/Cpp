@echo off
g++ divider.cpp -o run_me_in_cmd.exe -I"C:\lib\opencv\build\include" -L"C:\lib\opencv\build\lib" -lopencv_core450.dll -lopencv_highgui450.dll -lopencv_imgproc450.dll -l"opencv_imgcodecs450"  -static-libgcc -static-libstdc++
pause