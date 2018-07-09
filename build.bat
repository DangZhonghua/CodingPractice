@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x64     
set compilerflags=/Od /Zi /EHsc /MD
set linkerflags=/OUT:kw.exe
<<<<<<< HEAD
cl.exe %compilerflags% "Dynamic Programming/easy/Longest Bitonic subsequence.cpp" /link %linkerflags%
=======
cl.exe %compilerflags% "Dynamic Programming/easy/Palindromic patitioning.cpp" /link %linkerflags%
>>>>>>> e20504fe4bfdcfcddd0c029756f0c4f2cd97389a
