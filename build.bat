@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x64     
set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:kw.exe
cl.exe %compilerflags% "Graph\Medium\Knight Walk.cpp" /link %linkerflags%