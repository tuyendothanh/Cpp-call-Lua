# Cpp-call-Lua

Build Lua Library

cl /MD /O2 /c /DLUA_BUILD_AS_DLL *.c
ren lua.obj lua.o
ren luac.obj luac.o
link /DLL /IMPLIB:lua5.3.0.lib /OUT:lua5.3.0.dll *.obj 
link /OUT:lua.exe lua.o lua5.3.0.lib 
lib /OUT:lua5.3.0-static.lib *.obj
link /OUT:luac.exe luac.o lua5.3.0-static.lib

Build C++ source

cl /EHsc /MD /O2 /c *.cpp
ren main.obj main.o
link /OUT:main.exe main.o lua5.3.0-static.lib

