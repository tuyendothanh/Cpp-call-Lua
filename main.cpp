
#include <string>

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
int main()
{
	printf("This is a native C program.\n");

	lua_State *L;
	L = luaL_newstate();

	//luaL_dofile(L, "test.lua");
	if(luaL_loadfile(L, "test.lua") || lua_pcall(L, 0, 0, 0))
	{
		throw std::string(std::string(lua_tostring(L, -1)));
	}

	lua_getglobal(L, "foo");
	lua_pushnumber(L, 2);

	lua_pcall(L, 1, 1, 0);
	int result1;
	result1 = lua_tonumber(L, -1);
	printf("result = %d\n", result1);

	lua_getglobal(L, "x");

	int x;
	x = lua_tonumber(L, -1);
	printf("x = %d\n", x);
	
	return 0;
}