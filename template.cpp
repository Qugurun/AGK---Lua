// ***************************************
// *         AGK - Lua                   *
// *                                     *
// *       By Sean Regan				 *
// *   AGK made by The Game Creators     *
// *                                     *
// *                                     *
// ***************************************

// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

void app::Begin(void)
{
	//Create a new lua state object
	luaState = luaL_newstate();
	luaL_openlibs(luaState);

	//Register all of the AGK functions as Lua functions
	agkLua::RegisterFunctions(luaState);

	//Run the main.lua script
	if (luaL_dofile(luaState, "main.lua"))
	{
		//Error messages
		agk::Message(lua_tostring(luaState, -1));
		exit(1);
	}

	//Call the Lua Setup function
	lua_getglobal(luaState, "Setup");
	if (lua_pcall(luaState, 0, 0, 0))
	{
		//Error handling
		agk::Message(lua_tostring(luaState, -1));
		exit(1);
	}

}

void app::Loop(void)
{
	//Call the Lua Update function
	lua_getglobal(luaState, "Update");
	if (lua_pcall(luaState, 0, 0, 0))
	{
		//Error handling
		agk::Message(lua_tostring(luaState, -1));
		exit(1);
	}
}


void app::End(void)
{
	//Clean up the Lua state
	lua_close(luaState);
	luaState = 0;
}
