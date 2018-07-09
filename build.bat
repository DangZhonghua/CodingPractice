@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x64     
set compilerflags=/Od /Zi /EHsc /MD
set linkerflags=/OUT:kw.exe
cl.exe %compilerflags% "Dynamic Programming/easy/Longest Bitonic subsequence.cpp" /link %linkerflags%