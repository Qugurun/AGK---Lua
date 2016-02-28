#ifndef _H_SMACKIT_
#define _H_SMACKIT_

// Link to GDK libraries
#include "AGK.h"
#include "AGKLua.h"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


#define DEVICE_WIDTH 1024
#define DEVICE_HEIGHT 768
#define DEVICE_POS_X 32
#define DEVICE_POS_Y 32
#define FULLSCREEN false

// Global values for the app
class app
{
private:
	lua_State *luaState;

public:

	// constructor
	app() { memset(this, 0, sizeof(app)); }

	// main app functions - mike to experiment with a derived class for this..
	void Begin(void);
	void Loop(void);
	void End(void);
};

extern app App;

#endif

// Allow us to use the LoadImage function name
#ifdef LoadImage
#undef LoadImage
#endif