// ***************************************
// *         AGK - Lua                   *
// *                                     *
// *       By Sean Regan				 *
// *   AGK made by The Game Creators     *
// *                                     *
// *                                     *
// ***************************************

#include "AGKLua.h"

int agkLua::SetScreenResolution(lua_State *state)
{
	agk::SetScreenResolution(lua_tointeger(state, 1), lua_tointeger(state, 2));

	return 0;
}

int agkLua::SetWindowSize(lua_State *state)
{
	agk::SetWindowSize(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));

	return 0;
}

int agkLua::GetDeviceWidth(lua_State *state)
{
	lua_pushinteger(state, agk::GetDeviceWidth());
	return 1;
}

int agkLua::GetRealDeviceWidth(lua_State *state)
{
	lua_pushinteger(state, agk::GetRealDeviceWidth());
	return 1;
}

int agkLua::GetDeviceHeight(lua_State *state)
{
	lua_pushinteger(state, agk::GetDeviceHeight());
	return 1;
}

int agkLua::GetRealDeviceHeight(lua_State *state)
{
	lua_pushinteger(state, agk::GetRealDeviceHeight());
	return 1;
}

int agkLua::GetMaxDeviceWidth(lua_State *state)
{
	lua_pushinteger(state, agk::GetMaxDeviceWidth());
	return 1;
}

int agkLua::GetMaxDeviceHeight(lua_State *state)
{
	lua_pushinteger(state, agk::GetMaxDeviceHeight());
	return 1;
}

int agkLua::SetVSync(lua_State *state)
{
	agk::SetVSync(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSyncRate(lua_State *state)
{
	agk::SetSyncRate(lua_tonumber(state, 1), lua_tointeger(state, 2));

	return 0;
}

int agkLua::SetVirtualResolution(lua_State *state)
{
	agk::SetVirtualResolution(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetDisplayAspect(lua_State *state)
{
	agk::SetDisplayAspect(lua_tonumber(state, 1));
	return 0;
}

int agkLua::GetVirtualWidth(lua_State *state)
{
	lua_pushinteger(state, agk::GetVirtualWidth());
	return 1;
}

int agkLua::GetVirtualHeight(lua_State *state)
{
	lua_pushinteger(state, agk::GetVirtualHeight());
	return 1;
}

int agkLua::GetScreenBoundsLeft(lua_State *state)
{
	lua_pushnumber(state, agk::GetScreenBoundsLeft());
	return 1;
}

int agkLua::GetScreenBoundsRight(lua_State *state)
{
	lua_pushnumber(state, agk::GetScreenBoundsRight());
	return 1;
}

int agkLua::GetScreenBoundsTop(lua_State *state)
{
	lua_pushnumber(state, agk::GetScreenBoundsTop());
	return 1;
}

int agkLua::GetScreenBoundsBottom(lua_State *state)
{
	lua_pushnumber(state, agk::GetScreenBoundsBottom());
	return 1;
}

int agkLua::GetDisplayAspect(lua_State *state)
{
	lua_pushnumber(state, agk::GetDisplayAspect());
	return 1;
}

int agkLua::GetOrientation(lua_State *state)
{
	lua_pushinteger(state, agk::GetOrientation());
	return 1;
}

int agkLua::GetResumed(lua_State *state)
{
	lua_pushinteger(state, agk::GetResumed());
	return 1;
}

int agkLua::GetResumed2(lua_State *state)
{
	lua_pushinteger(state, agk::GetResumed2());
	return 1;
}

int agkLua::GetDeviceName(lua_State *state)
{
	char *s = agk::GetDeviceName();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetDeviceBaseName(lua_State *state)
{
	char *s = agk::GetDeviceBaseName();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetDeviceType(lua_State *state)
{
	char *s = agk::GetDeviceType();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetAppName(lua_State *state)
{
	char *s = agk::GetAppName();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetCL(lua_State *state)
{
	return 0;
}

int agkLua::SetWindowTitle(lua_State *state)
{
	agk::SetWindowTitle(lua_tostring(state, 1));
	return 0;
}

int agkLua::UpdateDeviceSize(lua_State *state)
{

	unsigned int w = 0, h = 0;
	if (lua_gettop(state))
	{
		w = lua_tonumber(state, 1);
		h = lua_tonumber(state, 1);
	}

	agk::UpdateDeviceSize(w, h);
	return 0;
}


int agkLua::StepPhysics(lua_State *state)
{
	agk::StepPhysics(lua_tonumber(state, 1));
	return 0;
}

int agkLua::Sync(lua_State *state)
{
	agk::Sync();
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::Break(lua_State *state)
{
	return 0;
}

int agkLua::Update(lua_State *state)
{

	double t = 0;
	if (lua_gettop(state) > 0)
	{
		t = lua_tonumber(state, 1);
	}

	agk::Update(t);
	return 0;
}

int agkLua::Update2D(lua_State *state)
{

	double t = 0;
	if (lua_gettop(state) > 0)
	{
		t = lua_tonumber(state, 1);
	}

	agk::Update2D(t);
	return 0;
}

int agkLua::Update3D(lua_State *state)
{

	double t = 0;
	if (lua_gettop(state) > 0)
	{
		t = lua_tonumber(state, 1);
	}

	agk::Update3D(t);

	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::DrawAllLines(lua_State *state)
{
	return 0;
}

int agkLua::Render2DBack(lua_State *state)
{
	agk::Render2DBack();
	return 0;
}

int agkLua::Render2DFront(lua_State *state)
{
	agk::Render2DFront();
	return 0;
}

int agkLua::Render3D(lua_State *state)
{
	agk::Render3D();
	return 0;
}

int agkLua::Render(lua_State *state)
{
	agk::Render();
	return 0;
}

int agkLua::Swap(lua_State *state)
{
	agk::Swap();
	return 0;
}

//NOT AND OFFICIAL COMMAND
int agkLua::UpdateInput(lua_State *state)
{
	return 0;
}

int agkLua::ClearScreen(lua_State *state)
{
	agk::ClearScreen();
	return 0;
}

int agkLua::ClearDepthBuffer(lua_State *state)
{
	agk::ClearDepthBuffer();
	return 0;
}

int agkLua::Sleep(lua_State *state)
{
	agk::Sleep(lua_tonumber(state, 1));
	return 0;
}

int agkLua::Timer(lua_State *state)
{
	lua_pushnumber(state, agk::Timer());
	return 1;
}

int agkLua::ResetTimer(lua_State *state)
{
	agk::ResetTimer();
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetRunTime(lua_State *state)
{
	return 0;
}

int agkLua::GetSeconds(lua_State *state)
{
	lua_pushinteger(state, agk::GetSeconds());
	return 1;
}

int agkLua::GetFrameTime(lua_State *state)
{
	lua_pushnumber(state, agk::GetFrameTime());
	return 1;
}

int agkLua::GetMilliseconds(lua_State *state)
{
	lua_pushnumber(state, agk::GetMilliseconds());
	return 1;
}

int agkLua::GetDeviceLanguage(lua_State *state)
{
	char *s = agk::GetDeviceLanguage();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::SetSleepMode(lua_State *state)
{
	agk::SetSleepMode(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetExpansionFileKey(lua_State *state)
{
	agk::SetExpansionFileKey(lua_tostring(state, 1));
	return 0;
}

int agkLua::SetExpansionFileVersion(lua_State *state)
{
	agk::SetExpansionFileVersion(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetExpansionFileState(lua_State *state)
{
	lua_pushinteger(state, agk::GetExpansionFileState());
	return 1;
}

int agkLua::DownloadExpansionFile(lua_State *state)
{
	agk::DownloadExpansionFile();
	return 0;
}

int agkLua::GetExpansionFileProgress(lua_State *state)
{
	lua_pushnumber(state, agk::GetExpansionFileProgress());
	return 1;
}

int agkLua::GetDeviceID(lua_State *state)
{
	char *s = agk::GetDeviceID();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::Sha1(lua_State *state)
{
	char *s = agk::Sha1(lua_tostring(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::HTTPEncode(lua_State *state)
{
	char *s = agk::HTTPEncode(lua_tostring(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::HTTPDecode(lua_State *state)
{
	char *s = agk::HTTPDecode(lua_tostring(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetNumProcessors(lua_State *state)
{
	lua_pushinteger(state, agk::GetNumProcessors());

	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SortArray(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SortFloatToUINT(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SortUINTToFloat(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SortIntToUINT(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SortUINTToInt(lua_State *state)
{
	return 0;
}

int agkLua::SetRandomSeed(lua_State *state)
{
	agk::SetRandomSeed(lua_tonumber(state, 1));
	return 0;
}

int agkLua::Random(lua_State *state)
{

	unsigned int r = 0;
	if (lua_gettop(state) > 0) r = agk::Random(lua_tonumber(state, 1), lua_tonumber(state, 2));
	else r = agk::Random();

	lua_pushnumber(state, r);

	return 1;
}

int agkLua::RandomSign(lua_State *state)
{
	lua_pushinteger(state, agk::RandomSign(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetRandomSeed2(lua_State *state)
{
	agk::SetRandomSeed2(lua_tonumber(state, 1));
	return 0;
}

int agkLua::Random2(lua_State *state)
{

	int r = 0;
	if (lua_gettop(state) > 0) r = agk::Random2(lua_tointeger(state, 1), lua_tointeger(state, 2));
	else r = agk::Random2();

	lua_pushinteger(state, r);


	return 1;
}

//MATH FUNCTIONS SUPPORTED NATIVELY IN LUA
int agkLua::Sin(lua_State *state)
{
	return 0;
}

int agkLua::Cos(lua_State *state)
{
	return 0;
}

int agkLua::Tan(lua_State *state)
{
	return 0;
}

int agkLua::SinRad(lua_State *state)
{
	return 0;
}

int agkLua::CosRad(lua_State *state)
{
	return 0;
}

int agkLua::TanRad(lua_State *state)
{
	return 0;
}

int agkLua::ASin(lua_State *state)
{
	return 0;
}

int agkLua::ACos(lua_State *state)
{
	return 0;
}

int agkLua::ATan(lua_State *state)
{
	return 0;
}

int agkLua::ATan2(lua_State *state)
{
	return 0;
}

int agkLua::ATanFull(lua_State *state)
{
	return 0;
}

int agkLua::ASinRad(lua_State *state)
{
	return 0;
}

int agkLua::ACosRad(lua_State *state)
{
	return 0;
}

int agkLua::ATanRad(lua_State *state)
{
	return 0;
}

int agkLua::ATan2Rad(lua_State *state)
{
	return 0;
}

int agkLua::ATanFullRad(lua_State *state)
{
	return 0;
}

int agkLua::Trunc(lua_State *state)
{
	return 0;
}

int agkLua::Floor(lua_State *state)
{
	return 0;
}

int agkLua::Ceil(lua_State *state)
{
	return 0;
}

int agkLua::Round(lua_State *state)
{
	return 0;
}

int agkLua::Sqrt(lua_State *state)
{
	return 0;
}

int agkLua::Abs(lua_State *state)
{
	return 0;
}

int agkLua::Mod(lua_State *state)
{
	return 0;
}

int agkLua::FMod(lua_State *state)
{
	return 0;
}

int agkLua::Pow(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SetAlphaTestThreshold(lua_State *state)
{
	return 0;
}

int agkLua::SetGenerateMipmaps(lua_State *state)
{
	agk::SetGenerateMipmaps(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetOrientationAllowed(lua_State *state)
{
	agk::SetOrientationAllowed(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTransitionMode(lua_State *state)
{
	agk::SetTransitionMode(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSortTextures(lua_State *state)
{
	agk::SetSortTextures(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSortDepth(lua_State *state)
{
	agk::SetSortDepth(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSortTransparentDepth(lua_State *state)
{
	agk::SetSortTransparentDepth(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSortCreated(lua_State *state)
{
	agk::SetSortCreated(lua_tointeger(state, 1));
	return 0;
}

int agkLua::ScreenFPS(lua_State *state)
{
	lua_pushnumber(state, agk::ScreenFPS());
	return 1;
}

int agkLua::GetPolygonsDrawn(lua_State *state)
{
	lua_pushnumber(state, agk::GetPolygonsDrawn());
	return 1;
}

int agkLua::GetVerticesProcessed(lua_State *state)
{
	lua_pushnumber(state, agk::GetVerticesProcessed());
	return 1;
}

int agkLua::EnableClearDepth(lua_State *state)
{
	agk::EnableClearDepth(lua_tointeger(state, 1));
	return 0;
}

int agkLua::EnableClearColor(lua_State *state)
{
	agk::EnableClearColor(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetBorderColor(lua_State *state)
{
	agk::SetBorderColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetClearColor(lua_State *state)
{
	agk::SetClearColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::BindDefaultFramebuffer(lua_State *state)
{
	return 0;
}

int agkLua::SetDefaultMagFilter(lua_State *state)
{
	agk::SetDefaultMagFilter(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetDefaultMinFilter(lua_State *state)
{
	agk::SetDefaultMinFilter(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetDefaultWrapU(lua_State *state)
{
	agk::SetDefaultWrapU(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetDefaultWrapV(lua_State *state)
{
	agk::SetDefaultWrapU(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetViewOffset(lua_State *state)
{
	agk::SetViewOffset(lua_tonumber(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetViewZoom(lua_State *state)
{
	agk::SetViewZoom(lua_tonumber(state, 1));
	return 0;
}

int agkLua::SetViewZoomMode(lua_State *state)
{
	agk::SetViewZoomMode(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetViewOffsetX(lua_State *state)
{
	lua_pushnumber(state, agk::GetViewOffsetX());
	return 1;
}

int agkLua::GetViewOffsetY(lua_State *state)
{
	lua_pushnumber(state, agk::GetViewOffsetY());
	return 1;
}

int agkLua::GetViewZoom(lua_State *state)
{
	lua_pushnumber(state, agk::GetViewZoom());
	return 1;
}

int agkLua::SetScissor(lua_State *state)
{
	agk::SetScissor(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::SetIntendedDeviceSize(lua_State *state)
{
	agk::SetIntendedDeviceSize(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::DebugInfo(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::Error(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::Warning(lua_State *state)
{
	return 0;
}

int agkLua::SetErrorMode(lua_State *state)
{
	agk::SetErrorMode(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetLastError(lua_State *state)
{
	char *s = agk::GetLastError();
	lua_pushstring(state, s);
	delete[] s;
	return 1;
}

int agkLua::GetErrorOccurred(lua_State *state)
{
	lua_pushinteger(state, agk::GetErrorOccurred());
	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SetWarningCallback(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SetErrorCallback(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SetDebugCallback(lua_State *state)
{
	return 0;
}

int agkLua::Message(lua_State *state)
{
	agk::Message(lua_tostring(state, 1));
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetImagePtr(lua_State *state)
{
	return 0;
}

int agkLua::LoadImage(lua_State *state)
{

	switch (lua_gettop(state))
	{
	case 1:
		lua_pushinteger(state, agk::LoadImage(lua_tostring(state, 1)));
		return 1;
		break;
	case 2:
		if (lua_type(state, 1) == LUA_TSTRING)
		{
			lua_pushinteger(state, agk::LoadImage(lua_tostring(state, 1), lua_tointeger(state, 2)));
			return 1;
		}
		else
		{
			agk::LoadImage(lua_tointeger(state, 1), lua_tostring(state, 2));
		}
		break;
	case 3:
		agk::LoadImage(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tointeger(state, 3));
		break;

	}

	return 0;
}

int agkLua::LoadSubImage(lua_State *state)
{

	switch (lua_gettop(state))
	{
	case 1:
		lua_pushinteger(state, agk::LoadSubImage(lua_tointeger(state, 1), lua_tostring(state, 2)));
		return 1;
		break;
	case 2:
		agk::LoadSubImage(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tostring(state, 3));
		break;

	}
	return 0;
}

int agkLua::CreateImageColor(lua_State *state)
{
	if (lua_gettop(state) > 0)
	{
		lua_pushinteger(state, agk::CreateImageColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4)));
		return 1;
	}
	else
	{
		agk::CreateImageColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	}

	return 0;
}

int agkLua::CreateRenderImage(lua_State *state)
{
	if (lua_gettop(state) > 0)
	{
		lua_pushinteger(state, agk::CreateRenderImage(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4)));
		return 1;
	}
	else
	{
		agk::CreateRenderImage(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	}

	return 0;
}

int agkLua::GetImageExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetImageExists(lua_tointeger(state, 1)));

	return 1;
}

int agkLua::DeleteImage(lua_State *state)
{
	agk::DeleteImage(lua_tointeger(state, 1));

	return 0;
}

int agkLua::DeleteAllImages(lua_State *state)
{
	agk::DeleteAllImages();

	return 0;
}

int agkLua::GetImageWidth(lua_State *state)
{
	lua_pushinteger(state, agk::GetImageWidth(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetImageHeight(lua_State *state)
{
	lua_pushinteger(state, agk::GetImageHeight(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetImageMinFilter(lua_State *state)
{
	agk::SetImageMinFilter(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetImageMagFilter(lua_State *state)
{
	agk::SetImageMagFilter(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetImageWrapU(lua_State *state)
{
	agk::SetImageWrapU(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetImageWrapV(lua_State *state)
{
	agk::SetImageWrapV(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetImageMask(lua_State *state)
{
	agk::SetImageMask(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5), lua_tointeger(state, 6));
	return 0;
}

int agkLua::SaveImage(lua_State *state)
{
	agk::SaveImage(lua_tointeger(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::CopyImage(lua_State *state)
{
	if (lua_gettop(state) == 5) agk::CopyImage(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	else agk::CopyImage(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5), lua_tointeger(state, 6));
	return 0;
}

int agkLua::GetImage(lua_State *state)
{
	if (lua_gettop(state) > 0)
	{
		agk::GetImage(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	}
	else
	{
		lua_pushinteger(state, agk::GetImage(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4)));
		return 1;
	}
	return 0;
}

int agkLua::GetImageFilename(lua_State *state)
{
	char *s = agk::GetImageFilename(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::SetImageSavePixels(lua_State *state)
{
	agk::SetImageSavePixels(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetImageTransparentColor(lua_State *state)
{
	agk::SetImageTransparentColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::ChooseImage(lua_State *state)
{
	lua_pushinteger(state, agk::ChooseImage());
	return 1;
}

int agkLua::ShowChooseImageScreen(lua_State *state)
{
	lua_pushinteger(state, agk::ShowChooseImageScreen());
	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::ChooseInternal(lua_State *state)
{
	return 0;
}

int agkLua::GetChosenImage(lua_State *state)
{
	lua_pushinteger(state, agk::GetChosenImage());
	return 1;
}

int agkLua::IsChoosingImage(lua_State *state)
{
	lua_pushinteger(state, agk::IsChoosingImage());
	return 1;
}

int agkLua::ShowImageCaptureScreen(lua_State *state)
{
	lua_pushinteger(state, agk::ShowImageCaptureScreen());
	return 1;
}

int agkLua::CaptureImage(lua_State *state)
{
	agk::CaptureImage();
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::CaptureInternal(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::CancelCapture(lua_State *state)
{
	return 0;
}

int agkLua::GetCapturedImage(lua_State *state)
{
	lua_pushinteger(state, agk::GetCapturedImage());
	return 1;
}

int agkLua::IsCapturingImage(lua_State *state)
{
	lua_pushinteger(state, agk::IsCapturingImage());
	return 1;
}

int agkLua::DecodeQRCode(lua_State *state)
{

	char *s = agk::DecodeQRCode(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::EncodeQRCode(lua_State *state)
{
	lua_pushinteger(state, agk::EncodeQRCode(lua_tostring(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::PrintImage(lua_State *state)
{
	agk::PrintImage(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetRenderToImage(lua_State *state)
{
	agk::SetRenderToImage(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetRenderToScreen(lua_State *state)
{
	agk::SetRenderToScreen();
	return 0;
}

int agkLua::IsSupportedDepthTexture(lua_State *state)
{
	lua_pushinteger(state, agk::IsSupportedDepthTexture());
	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetSpritePtr(lua_State *state)
{
	return 0;
}

int agkLua::GetSpriteImageID(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteImageID(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::CreateSprite(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::CreateSprite(lua_tointeger(state, 1)));
		return 1;
	}
	else
	{
		agk::CreateSprite(lua_tointeger(state, 1), lua_tointeger(state, 2));
	}
	return 0;
}

int agkLua::LoadSprite(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::LoadSprite(lua_tostring(state, 1)));
		return 1;
	}
	else
	{
		agk::LoadSprite(lua_tointeger(state, 1), lua_tostring(state, 2));
	}
	return 0;
}

int agkLua::CreateDummySprite(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::CreateDummySprite());
		return 1;
	}
	else
	{
		agk::CreateDummySprite(lua_tointeger(state, 1));
	}
	return 0;
}

int agkLua::CloneSprite(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::CloneSprite(lua_tointeger(state, 1)));
		return 1;
	}
	else
	{
		agk::CloneSprite(lua_tointeger(state, 1), lua_tointeger(state, 2));
	}
	return 0;
}

int agkLua::DeleteSprite(lua_State *state)
{
	agk::DeleteSprite(lua_tointeger(state, 1));
	return 0;
}

int agkLua::DeleteAllSprites(lua_State *state)
{
	agk::DeleteAllSprites();
	return 0;
}

int agkLua::SetSpritePosition(lua_State *state)
{
	agk::SetSpritePosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetSpritePositionByOffset(lua_State *state)
{
	agk::SetSpritePositionByOffset(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetSpriteX(lua_State *state)
{
	agk::SetSpriteX(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpriteY(lua_State *state)
{
	agk::SetSpriteY(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpriteAngle(lua_State *state)
{
	agk::SetSpriteAngle(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpriteAngleRad(lua_State *state)
{
	agk::SetSpriteAngleRad(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpriteDepth(lua_State *state)
{
	agk::SetSpriteDepth(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteFlip(lua_State *state)
{
	agk::SetSpriteFlip(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetSpriteSnap(lua_State *state)
{
	agk::SetSpriteSnap(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteVisible(lua_State *state)
{
	agk::SetSpriteVisible(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteActive(lua_State *state)
{
	agk::SetSpriteActive(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteImage(lua_State *state)
{
	agk::SetSpriteImage(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteAdditionalImage(lua_State *state)
{
	agk::SetSpriteAdditionalImage(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetSpriteUV(lua_State *state)
{
	agk::SetSpriteUV(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tonumber(state, 7), lua_tonumber(state, 8), lua_tonumber(state, 9));
	return 0;
}

int agkLua::ResetSpriteUV(lua_State *state)
{
	agk::ResetSpriteUV(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetSpriteExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteX(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteY(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteXByOffset(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteXByOffset(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteYByOffset(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteYByOffset(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteWidth(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteWidth(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteHeight(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteHeight(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteAngle(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteAngle(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteAngleRad(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteAngleRad(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteScaleX(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteScaleX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteScaleY(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteScaleY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteHitTest(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteHitTest(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3)));
	return 1;
}

int agkLua::GetSpriteDepth(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteDepth(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteColorRed(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteColorRed(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteColorGreen(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteColorGreen(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteColorBlue(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteColorBlue(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteColorAlpha(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteColorAlpha(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpritePlaying(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpritePlaying(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteVisible(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteVisible(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteActive(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteActive(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteGroup(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteGroup(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteXFromPixel(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteXFromPixel(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetSpriteYFromPixel(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteYFromPixel(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetSpritePixelFromX(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpritePixelFromX(lua_tointeger(state, 1), lua_tonumber(state, 2)));
	return 1;
}

int agkLua::GetSpritePixelFromY(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpritePixelFromY(lua_tointeger(state, 1), lua_tonumber(state, 2)));
	return 1;
}

int agkLua::GetWorldXFromSprite(lua_State *state)
{
	lua_pushnumber(state, agk::GetWorldXFromSprite(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3)));
	return 1;
}

int agkLua::GetWorldYFromSprite(lua_State *state)
{
	lua_pushnumber(state, agk::GetWorldYFromSprite(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3)));
	return 1;
}

int agkLua::GetSpriteXFromWorld(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteXFromWorld(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3)));
	return 1;
}

int agkLua::GetSpriteYFromWorld(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteYFromWorld(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3)));
	return 1;
}

int agkLua::SetSpriteSize(lua_State *state)
{
	agk::SetSpriteSize(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetSpriteAnimation(lua_State *state)
{
	agk::SetSpriteAnimation(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::AddSpriteAnimationFrame(lua_State *state)
{
	agk::AddSpriteAnimationFrame(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::ClearSpriteAnimationFrames(lua_State *state)
{
	agk::ClearSpriteAnimationFrames(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSpriteSpeed(lua_State *state)
{
	agk::SetSpriteSpeed(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::PlaySprite(lua_State *state)
{
	switch (lua_gettop(state))
	{
	case 1:
		agk::PlaySprite(lua_tointeger(state, 1));
		break;
	case 2:
		agk::PlaySprite(lua_tointeger(state, 1), lua_tonumber(state, 2));
		break;
	case 3:
		agk::PlaySprite(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tointeger(state, 3));
		break;
	case 5:
		agk::PlaySprite(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
		break;
	}

	return 0;
}

int agkLua::StopSprite(lua_State *state)
{
	agk::StopSprite(lua_tointeger(state, 1));
	return 0;
}

int agkLua::ResumeSprite(lua_State *state)
{
	agk::ResumeSprite(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSpriteFrame(lua_State *state)
{
	agk::SetSpriteFrame(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetSpriteCurrentFrame(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteCurrentFrame(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteFrameCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteFrameCount(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetSpriteTransparency(lua_State *state)
{
	agk::SetSpriteTransparency(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteOffset(lua_State *state)
{
	agk::SetSpriteOffset(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetSpriteColor(lua_State *state)
{
	agk::SetSpriteColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	return 0;
}

int agkLua::SetSpriteColorRed(lua_State *state)
{
	agk::SetSpriteColorRed(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteColorGreen(lua_State *state)
{
	agk::SetSpriteColorGreen(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteColorBlue(lua_State *state)
{
	agk::SetSpriteColorBlue(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteColorAlpha(lua_State *state)
{
	agk::SetSpriteColorAlpha(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteUVBorder(lua_State *state)
{
	agk::SetSpriteUVBorder(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpriteUVOffset(lua_State *state)
{
	agk::SetSpriteUVOffset(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetSpriteUVScale(lua_State *state)
{
	agk::SetSpriteUVScale(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::FixSpriteToScreen(lua_State *state)
{
	agk::FixSpriteToScreen(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteScale(lua_State *state)
{
	agk::SetSpriteScale(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetSpriteScaleByOffset(lua_State *state)
{
	agk::SetSpriteScaleByOffset(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetSpriteScissor(lua_State *state)
{
	agk::SetSpriteScissor(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetSpriteShader(lua_State *state)
{
	agk::SetSpriteShader(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteGroup(lua_State *state)
{
	agk::SetSpriteGroup(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteCategoryBits(lua_State *state)
{
	agk::SetSpriteCategoryBits(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteCategoryBit(lua_State *state)
{
	agk::SetSpriteCategoryBit(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetSpriteCollideBits(lua_State *state)
{
	agk::SetSpriteCollideBits(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteCollideBit(lua_State *state)
{
	agk::SetSpriteCollideBit(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::DrawSprite(lua_State *state)
{
	agk::DrawSprite(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetPhysicsScale(lua_State *state)
{
	agk::SetPhysicsScale(lua_tonumber(state, 1));
	return 0;
}

int agkLua::SetPhysicsGravity(lua_State *state)
{
	agk::SetPhysicsGravity(lua_tonumber(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetPhysicsDebugOn(lua_State *state)
{
	agk::SetPhysicsDebugOn();
	return 0;
}

int agkLua::SetPhysicsDebugOff(lua_State *state)
{
	agk::SetPhysicsDebugOff();
	return 0;
}

int agkLua::SetPhysicsThreading(lua_State *state)
{
	agk::SetPhysicsThreading(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetPhysicsCCD(lua_State *state)
{
	agk::SetPhysicsCCD(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetPhysicsSleeping(lua_State *state)
{
	agk::SetPhysicsSleeping(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetPhysicsMaxPolygonPoints(lua_State *state)
{
	agk::SetPhysicsMaxPolygonPoints(lua_tointeger(state, 1));
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetPhysicsWorld(lua_State *state)
{
	return 0;
}

int agkLua::GetPhysicsSolveTime(lua_State *state)
{
	lua_pushnumber(state, agk::GetPhysicsSolveTime());
	return 1;
}

int agkLua::GetPhysicsIslandCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetPhysicsIslandCount());
	return 1;
}

int agkLua::SetPhysicsWallTop(lua_State *state)
{
	agk::SetPhysicsWallTop(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetPhysicsWallLeft(lua_State *state)
{
	agk::SetPhysicsWallLeft(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetPhysicsWallRight(lua_State *state)
{
	agk::SetPhysicsWallRight(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetPhysicsWallBottom(lua_State *state)
{
	agk::SetPhysicsWallBottom(lua_tointeger(state, 1));
	return 0;
}

int agkLua::CreatePhysicsForce(lua_State *state)
{
	lua_pushinteger(state, agk::CreatePhysicsForce(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tointeger(state, 6)));
	return 1;
}

int agkLua::DeletePhysicsForce(lua_State *state)
{
	agk::DeletePhysicsForce(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetPhysicsForcePosition(lua_State *state)
{
	agk::SetPhysicsForcePosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetPhysicsForcePower(lua_State *state)
{
	agk::SetPhysicsForcePower(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetPhysicsForceRange(lua_State *state)
{
	agk::SetPhysicsForceRange(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpriteShape(lua_State *state)
{
	agk::SetSpriteShape(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpriteShapeBox(lua_State *state)
{
	agk::SetSpriteShapeBox(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6));
	return 0;
}

int agkLua::SetSpriteShapeCircle(lua_State *state)
{
	agk::SetSpriteShapeCircle(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::SetSpriteShapePolygon(lua_State *state)
{
	agk::SetSpriteShapePolygon(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::AddSpriteShapeBox(lua_State *state)
{
	agk::AddSpriteShapeBox(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6));
	return 0;
}

int agkLua::AddSpriteShapeCircle(lua_State *state)
{
	agk::AddSpriteShapeCircle(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::AddSpriteShapePolygon(lua_State *state)
{
	agk::AddSpriteShapePolygon(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::ClearSpriteShapes(lua_State *state)
{
	agk::ClearSpriteShapes(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSpritePhysicsCOM(lua_State *state)
{
	agk::SetSpritePhysicsCOM(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::CalculateSpritePhysicsCOM(lua_State *state)
{
	agk::CalculateSpritePhysicsCOM(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSpritePhysicsOn(lua_State *state)
{
	agk::SetSpritePhysicsOn(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpritePhysicsOff(lua_State *state)
{
	agk::SetSpritePhysicsOff(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSpritePhysicsDelete(lua_State *state)
{
	agk::SetSpritePhysicsDelete(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSpritePhysicsFriction(lua_State *state)
{
	agk::SetSpritePhysicsFriction(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpritePhysicsRestitution(lua_State *state)
{
	agk::SetSpritePhysicsRestitution(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpritePhysicsCanRotate(lua_State *state)
{
	agk::SetSpritePhysicsCanRotate(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpritePhysicsVelocity(lua_State *state)
{
	agk::SetSpritePhysicsVelocity(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetSpritePhysicsAngularVelocity(lua_State *state)
{
	agk::GetSpritePhysicsAngularVelocity(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetSpritePhysicsDamping(lua_State *state)
{
	agk::SetSpritePhysicsDamping(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpritePhysicsAngularDamping(lua_State *state)
{
	agk::SetSpritePhysicsAngularDamping(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpritePhysicsIsBullet(lua_State *state)
{
	agk::SetSpritePhysicsIsBullet(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpritePhysicsMass(lua_State *state)
{
	agk::SetSpritePhysicsMass(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpritePhysicsIsSensor(lua_State *state)
{
	agk::SetSpritePhysicsIsSensor(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSpritePhysicsForce(lua_State *state)
{
	agk::SetSpritePhysicsForce(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetSpritePhysicsTorque(lua_State *state)
{
	agk::SetSpritePhysicsTorque(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSpritePhysicsImpulse(lua_State *state)
{
	agk::SetSpritePhysicsImpulse(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetSpritePhysicsAngularImpulse(lua_State *state)
{
	agk::SetSpritePhysicsAngularImpulse(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::GetSpritePhysicsVelocityX(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpritePhysicsVelocityX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpritePhysicsVelocityY(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpritePhysicsVelocityY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpritePhysicsAngularVelocity(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpritePhysicsAngularVelocity(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpritePhysicsMass(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpritePhysicsMass(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::DeleteJoint(lua_State *state)
{
	agk::DeleteJoint(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetJointExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetJointExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::CreateDistanceJoint(lua_State *state)
{
	if (lua_gettop(state) == 7)
	{
		lua_pushinteger(state, agk::CreateDistanceJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), (float)lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tointeger(state, 7)));
		return 1;
	}
	else
	{
		agk::CreateDistanceJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tonumber(state, 7), lua_tointeger(state, 8));
	}

	return 0;
}

int agkLua::CreateRevoluteJoint(lua_State *state)
{
	if (lua_gettop(state) == 5)
	{
		lua_pushinteger(state, agk::CreateRevoluteJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), (float)lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tointeger(state, 5)));
		return 1;
	}
	else
	{
		agk::CreateRevoluteJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tointeger(state, 6));
	}
	return 0;
}

int agkLua::CreatePrismaticJoint(lua_State *state)
{
	if (lua_gettop(state) == 7)
	{
		lua_pushinteger(state, agk::CreatePrismaticJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), (float)lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tointeger(state, 7)));
		return 1;
	}
	else
	{
		agk::CreatePrismaticJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tonumber(state, 7), lua_tointeger(state, 8));
	}
	return 0;
}

int agkLua::CreatePulleyJoint(lua_State *state)
{
	if (lua_gettop(state) == 12)
	{
		lua_pushinteger(state, agk::CreatePulleyJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), (float)lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tonumber(state, 7), lua_tonumber(state, 8), lua_tonumber(state, 9), lua_tonumber(state, 10), lua_tonumber(state, 11), lua_tointeger(state, 12)));
		return 1;
	}
	else
	{
		agk::CreatePulleyJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tonumber(state, 7), lua_tonumber(state, 8), lua_tonumber(state, 9), lua_tonumber(state, 10), lua_tonumber(state, 11), lua_tonumber(state, 12), lua_tointeger(state, 13));
	}
	return 0;
}

int agkLua::CreateMouseJoint(lua_State *state)
{
	if (lua_gettop(state) == 4)
	{
		lua_pushinteger(state, agk::CreateMouseJoint(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4)));
		return 1;
	}
	else
	{
		agk::CreateMouseJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	}
	return 0;
}

int agkLua::CreateLineJoint(lua_State *state)
{
	if (lua_gettop(state) == 7)
	{
		lua_pushinteger(state, agk::CreateLineJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), (float)lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tointeger(state, 7)));
		return 1;
	}
	else
	{
		agk::CreateLineJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tonumber(state, 7), lua_tointeger(state, 8));
	}
	return 0;
}

int agkLua::CreateWeldJoint(lua_State *state)
{
	if (lua_gettop(state) == 4)
	{
		lua_pushinteger(state, agk::CreateWeldJoint(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4)));
		return 1;
	}
	else
	{
		agk::CreateWeldJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), (float)lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tointeger(state, 5));
	}
	return 0;
}

int agkLua::CreateGearJoint(lua_State *state)
{
	if (lua_gettop(state) == 3)
	{
		lua_pushinteger(state, agk::CreateGearJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3)));
		return 1;
	}
	else
	{
		agk::CreateGearJoint(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4));
	}
	return 0;
}

int agkLua::CreatePulleyJoint2(lua_State *state)
{
	agk::CreatePulleyJoint2(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::FinishPulleyJoint(lua_State *state)
{
	lua_pushinteger(state, agk::FinishPulleyJoint(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tonumber(state, 7), lua_tonumber(state, 8)));
	return 1;
}

int agkLua::SetJointLimitOn(lua_State *state)
{
	agk::SetJointLimitOn(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetJointLimitOff(lua_State *state)
{
	agk::SetJointLimitOff(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetJointMotorOn(lua_State *state)
{
	agk::SetJointMotorOn(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetJointMotorOff(lua_State *state)
{
	agk::SetJointMotorOff(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetJointMouseTarget(lua_State *state)
{
	agk::SetJointMouseTarget(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::GetJointReactionForceX(lua_State *state)
{
	lua_pushnumber(state, agk::GetJointReactionForceX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetJointReactionForceY(lua_State *state)
{
	lua_pushnumber(state, agk::GetJointReactionForceY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetJointReactionTorque(lua_State *state)
{
	lua_pushnumber(state, agk::GetJointReactionTorque(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::PhysicsRayCast(lua_State *state)
{
	lua_pushinteger(state, agk::PhysicsRayCast(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4)));
	return 1;
}

int agkLua::PhysicsRayCastGroup(lua_State *state)
{
	lua_pushinteger(state, agk::PhysicsRayCastGroup(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5)));
	return 1;
}

int agkLua::PhysicsRayCastCategory(lua_State *state)
{
	lua_pushinteger(state, agk::PhysicsRayCastCategory(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5)));
	return 1;
}

int agkLua::SpriteRayCast(lua_State *state)
{
	lua_pushinteger(state, agk::SpriteRayCast(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4)));
	return 1;
}

int agkLua::SpriteRayCastGroup(lua_State *state)
{
	lua_pushinteger(state, agk::SpriteRayCastGroup(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5)));
	return 1;
}

int agkLua::SpriteRayCastCategory(lua_State *state)
{
	lua_pushinteger(state, agk::SpriteRayCastCategory(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5)));
	return 1;
}

int agkLua::SpriteRayCastSingle(lua_State *state)
{
	lua_pushinteger(state, agk::SpriteRayCastSingle(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5)));
	return 1;
}

int agkLua::GetRayCastSpriteID(lua_State *state)
{
	lua_pushinteger(state, agk::GetRayCastSpriteID());
	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetRayCastSprite(lua_State *state)
{
	return 0;
}

int agkLua::GetRayCastX(lua_State *state)
{
	lua_pushnumber(state, agk::GetRayCastX());
	return 1;
}

int agkLua::GetRayCastY(lua_State *state)
{
	lua_pushnumber(state, agk::GetRayCastY());
	return 1;
}

int agkLua::GetRayCastNormalX(lua_State *state)
{
	lua_pushnumber(state, agk::GetRayCastNormalX());
	return 1;
}

int agkLua::GetRayCastNormalY(lua_State *state)
{
	lua_pushnumber(state, agk::GetRayCastNormalY());
	return 1;
}

int agkLua::GetRayCastFraction(lua_State *state)
{
	lua_pushnumber(state, agk::GetRayCastFraction());
	return 1;
}

int agkLua::GetSpriteInBox(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteInBox(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5)));
	return 1;
}

int agkLua::GetSpriteInCircle(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteInCircle(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4)));
	return 1;
}

int agkLua::GetSpriteCollision(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteCollision(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetSpriteHit(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteHit(lua_tonumber(state, 1), lua_tonumber(state, 2)));
	return 1;
}

int agkLua::GetSpriteHitGroup(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteHitGroup(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3)));
	return 1;
}

int agkLua::GetSpriteHitCategory(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteHitCategory(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3)));
	return 1;
}

int agkLua::GetSpriteDistance(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteDistance(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetSpriteDistancePoint1X(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteDistancePoint1X());
	return 1;
}

int agkLua::GetSpriteDistancePoint1Y(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteDistancePoint1Y());
	return 1;
}

int agkLua::GetSpriteDistancePoint2X(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteDistancePoint2X());
	return 1;
}

int agkLua::GetSpriteDistancePoint2Y(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteDistancePoint2Y());
	return 1;
}

int agkLua::GetFirstContact(lua_State *state)
{
	lua_pushinteger(state, agk::GetFirstContact());
	return 1;
}

int agkLua::GetNextContact(lua_State *state)
{
	lua_pushinteger(state, agk::GetNextContact());
	return 1;
}

int agkLua::GetContactWorldX(lua_State *state)
{
	lua_pushnumber(state, agk::GetContactWorldX());
	return 1;
}

int agkLua::GetContactWorldY(lua_State *state)
{
	lua_pushnumber(state, agk::GetContactWorldY());
	return 1;
}

int agkLua::GetContactSpriteID1(lua_State *state)
{
	lua_pushinteger(state, agk::GetContactSpriteID1());
	return 1;
}

int agkLua::GetContactSpriteID2(lua_State *state)
{
	lua_pushinteger(state, agk::GetContactSpriteID2());
	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetContactSprite1(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetContactSprite2(lua_State *state)
{
	return 0;
}

int agkLua::GetSpriteFirstContact(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteFirstContact(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSpriteNextContact(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteNextContact());
	return 1;
}

int agkLua::GetSpriteContactWorldX(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteContactWorldX());
	return 1;
}

int agkLua::GetSpriteContactWorldY(lua_State *state)
{
	lua_pushnumber(state, agk::GetSpriteContactWorldY());
	return 1;
}

int agkLua::GetSpriteContactSpriteID2(lua_State *state)
{
	lua_pushinteger(state, agk::GetSpriteContactSpriteID2());
	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetSpriteContactSprite2(lua_State *state)
{
	return 0;
}

int agkLua::GetPhysicsCollision(lua_State *state)
{
	lua_pushinteger(state, agk::GetPhysicsCollision(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetPhysicsCollisionX(lua_State *state)
{
	lua_pushnumber(state, agk::GetPhysicsCollisionX());
	return 1;
}

int agkLua::GetPhysicsCollisionY(lua_State *state)
{
	lua_pushnumber(state, agk::GetPhysicsCollisionY());
	return 1;
}

int agkLua::GetPhysicsCollisionWorldX(lua_State *state)
{
	lua_pushnumber(state, agk::GetPhysicsCollisionWorldX());
	return 1;
}

int agkLua::GetPhysicsCollisionWorldY(lua_State *state)
{
	lua_pushnumber(state, agk::GetPhysicsCollisionWorldY());
	return 1;
}

int agkLua::CreateParticles(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		lua_pushinteger(state, agk::CreateParticles(lua_tonumber(state, 1), lua_tonumber(state, 2)));
		return 1;
	}
	else
	{
		agk::CreateParticles(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	}

	return 0;
}

int agkLua::GetParticlesExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetParticlesExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::DeleteParticles(lua_State *state)
{
	agk::DeleteParticles(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetParticlesPosition(lua_State *state)
{
	agk::SetParticlesPosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetParticlesDepth(lua_State *state)
{
	agk::SetParticlesDepth(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetParticlesFrequency(lua_State *state)
{
	agk::SetParticlesFrequency(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetParticlesStartZone(lua_State *state)
{
	agk::SetParticlesStartZone(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetParticlesDirection(lua_State *state)
{
	agk::SetParticlesDirection(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetParticlesVelocityRange(lua_State *state)
{
	agk::SetParticlesVelocityRange(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetParticlesAngle(lua_State *state)
{
	agk::SetParticlesAngle(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetParticlesAngleRad(lua_State *state)
{
	agk::SetParticlesAngleRad(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetParticlesRotationRange(lua_State *state)
{
	agk::SetParticlesRotationRange(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetParticlesRotationRangeRad(lua_State *state)
{
	agk::SetParticlesRotationRangeRad(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetParticlesFaceDirection(lua_State *state)
{
	agk::SetParticlesFaceDirection(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetParticlesSize(lua_State *state)
{
	agk::SetParticlesSize(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetParticlesLife(lua_State *state)
{
	agk::SetParticlesLife(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetParticlesMax(lua_State *state)
{
	agk::SetParticlesMax(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::ResetParticleCount(lua_State *state)
{
	agk::ResetParticleCount(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetParticlesImage(lua_State *state)
{
	agk::SetParticlesImage(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetParticlesColorInterpolation(lua_State *state)
{
	agk::SetParticlesColorInterpolation(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetParticlesVisible(lua_State *state)
{
	agk::SetParticlesVisible(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetParticlesActive(lua_State *state)
{
	agk::SetParticlesActive(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetParticlesTransparency(lua_State *state)
{
	agk::SetParticlesTransparency(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetParticlesX(lua_State *state)
{
	lua_pushnumber(state, agk::GetParticlesX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesY(lua_State *state)
{
	lua_pushnumber(state, agk::GetParticlesY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesDepth(lua_State *state)
{
	lua_pushinteger(state, agk::GetParticlesDepth(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesVisible(lua_State *state)
{
	lua_pushinteger(state, agk::GetParticlesVisible(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesActive(lua_State *state)
{
	lua_pushinteger(state, agk::GetParticlesActive(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesFrequency(lua_State *state)
{
	lua_pushnumber(state, agk::GetParticlesFrequency(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesDirectionX(lua_State *state)
{
	lua_pushnumber(state, agk::GetParticlesDirectionX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesDirectionY(lua_State *state)
{
	lua_pushnumber(state, agk::GetParticlesDirectionY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesAngle(lua_State *state)
{
	lua_pushnumber(state, agk::GetParticlesAngle(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesAngleRad(lua_State *state)
{
	lua_pushnumber(state, agk::GetParticlesAngleRad(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesSize(lua_State *state)
{
	lua_pushnumber(state, agk::GetParticlesSize(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesLife(lua_State *state)
{
	lua_pushnumber(state, agk::GetParticlesLife(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetParticlesMaxReached(lua_State *state)
{
	lua_pushinteger(state, agk::GetParticlesMaxReached(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::AddParticlesForce(lua_State *state)
{
	agk::AddParticlesForce(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::ClearParticlesForces(lua_State *state)
{
	agk::ClearParticlesForces(lua_tointeger(state, 1));
	return 0;
}

int agkLua::AddParticlesColorKeyFrame(lua_State *state)
{
	agk::AddParticlesColorKeyFrame(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5), lua_tointeger(state, 6));
	return 0;
}

int agkLua::ClearParticlesColors(lua_State *state)
{
	agk::ClearParticlesColors(lua_tointeger(state, 1));
	return 0;
}

int agkLua::AddParticlesScaleKeyFrame(lua_State *state)
{
	agk::AddParticlesScaleKeyFrame(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::ClearParticlesScales(lua_State *state)
{
	agk::ClearParticlesScales(lua_tointeger(state, 1));
	return 0;
}

int agkLua::FixParticlesToScreen(lua_State *state)
{
	agk::FixParticlesToScreen(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::UpdateParticles(lua_State *state)
{
	agk::UpdateParticles(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::OffsetParticles(lua_State *state)
{
	agk::OffsetParticles(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetTextDefaultFontImage(lua_State *state)
{
	agk::SetTextDefaultFontImage(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetTextDefaultExtendedFontImage(lua_State *state)
{
	agk::SetTextDefaultExtendedFontImage(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetTextDefaultMinFilter(lua_State *state)
{
	agk::SetTextDefaultMinFilter(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetTextDefaultMagFilter(lua_State *state)
{
	agk::SetTextDefaultMagFilter(lua_tointeger(state, 1));
	return 0;
}

int agkLua::CreateText(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::CreateText(lua_tostring(state, 1)));
		return 1;
	}
	else
	{
		agk::CreateText(lua_tointeger(state, 1), lua_tostring(state, 2));
	}
	return 0;
}

int agkLua::DeleteText(lua_State *state)
{
	agk::DeleteText(lua_tointeger(state, 1));
	return 0;
}

int agkLua::DeleteAllText(lua_State *state)
{
	agk::DeleteAllText();
	return 0;
}

int agkLua::SetTextString(lua_State *state)
{
	agk::SetTextString(lua_tointeger(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::SetTextPosition(lua_State *state)
{
	agk::SetTextPosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetTextX(lua_State *state)
{
	agk::SetTextX(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetTextY(lua_State *state)
{
	agk::SetTextY(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetTextSize(lua_State *state)
{
	agk::SetTextSize(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetTextSpacing(lua_State *state)
{
	agk::SetTextSpacing(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetTextLineSpacing(lua_State *state)
{
	agk::SetTextLineSpacing(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetTextDepth(lua_State *state)
{
	agk::SetTextDepth(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetTextVisible(lua_State *state)
{
	agk::SetTextVisible(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetTextAlignment(lua_State *state)
{
	agk::SetTextAlignment(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetTextColor(lua_State *state)
{
	agk::SetTextColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	return 0;
}

int agkLua::SetTextColorRed(lua_State *state)
{
	agk::SetTextColorRed(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetTextColorGreen(lua_State *state)
{
	agk::SetTextColorGreen(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetTextColorBlue(lua_State *state)
{
	agk::SetTextColorBlue(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetTextColorAlpha(lua_State *state)
{
	agk::SetTextColorAlpha(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetTextFontImage(lua_State *state)
{
	agk::SetTextFontImage(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetTextExtendedFontImage(lua_State *state)
{
	agk::SetTextExtendedFontImage(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::FixTextToScreen(lua_State *state)
{
	agk::FixTextToScreen(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetTextMaxWidth(lua_State *state)
{
	agk::SetTextMaxWidth(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetTextScissor(lua_State *state)
{
	agk::SetTextScissor(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetTextTransparency(lua_State *state)
{
	agk::SetTextTransparency(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetTextColorRed(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextColorRed(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextColorGreen(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextColorGreen(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextColorBlue(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextColorBlue(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextColorAlpha(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextColorAlpha(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextX(lua_State *state)
{
	lua_pushnumber(state, agk::GetTextX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextY(lua_State *state)
{
	lua_pushnumber(state, agk::GetTextY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextLength(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextLength(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextTotalWidth(lua_State *state)
{
	lua_pushnumber(state, agk::GetTextTotalWidth(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextTotalHeight(lua_State *state)
{
	lua_pushnumber(state, agk::GetTextTotalHeight(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextHitTest(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextHitTest(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3)));
	return 1;
}

int agkLua::GetTextVisible(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextVisible(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextDepth(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextDepth(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextSize(lua_State *state)
{
	lua_pushnumber(state, agk::GetTextSize(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextString(lua_State *state)
{
	char *s = agk::GetTextString(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetTextSpacing(lua_State *state)
{
	lua_pushnumber(state, agk::GetTextSpacing(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetTextLineSpacing(lua_State *state)
{
	lua_pushnumber(state, agk::GetTextLineSpacing(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetTextCharPosition(lua_State *state)
{
	agk::SetTextCharPosition(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::SetTextCharX(lua_State *state)
{
	agk::SetTextCharX(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetTextCharY(lua_State *state)
{
	agk::SetTextCharY(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetTextCharAngle(lua_State *state)
{
	agk::SetTextCharAngle(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetTextCharAngleRad(lua_State *state)
{
	agk::SetTextCharAngleRad(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetTextCharColor(lua_State *state)
{
	agk::SetTextCharColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5), lua_tointeger(state, 6));
	return 0;
}

int agkLua::SetTextCharColorRed(lua_State *state)
{
	agk::SetTextCharColorRed(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetTextCharColorGreen(lua_State *state)
{
	agk::SetTextCharColorGreen(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetTextCharColorBlue(lua_State *state)
{
	agk::SetTextCharColorBlue(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetTextCharColorAlpha(lua_State *state)
{
	agk::SetTextCharColorAlpha(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::GetTextCharX(lua_State *state)
{
	lua_pushnumber(state, agk::GetTextCharX(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetTextCharY(lua_State *state)
{
	lua_pushnumber(state, agk::GetTextCharY(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetTextCharAngle(lua_State *state)
{
	lua_pushnumber(state, agk::GetTextCharAngle(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetTextCharAngleRad(lua_State *state)
{
	lua_pushnumber(state, agk::GetTextCharAngleRad(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetTextCharColorRed(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextCharColorRed(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetTextCharColorGreen(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextCharColorGreen(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetTextCharColorBlue(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextCharColorBlue(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetTextCharColorAlpha(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextCharColorAlpha(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::CreateSkeleton2D(lua_State *state)
{
	if (lua_gettop(state) == 0)
	{
		lua_pushinteger(state, agk::CreateSkeleton2D());
		return 1;
	}
	else
	{
		agk::CreateSkeleton2D(lua_tointeger(state, 1));
	}
}

int agkLua::GetSkeleton2DExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetSkeleton2DExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::DeleteSkeleton2D(lua_State *state)
{
	agk::DeleteSkeleton2D(lua_tointeger(state, 1));
	return 0;
}

int agkLua::LoadSkeleton2DFromSpineFile(lua_State *state)
{
	if (lua_gettop(state) == 4)
	{
		lua_pushinteger(state, agk::LoadSkeleton2DFromSpineFile(lua_tostring(state, 1), lua_tonumber(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4)));
		return 1;
	}
	else
	{
		agk::LoadSkeleton2DFromSpineFile(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	}
	
	return 0;
}

int agkLua::LoadSkeleton2DFromSpriterFile(lua_State *state)
{
	if (lua_gettop(state) == 3)
	{
		lua_pushinteger(state, agk::LoadSkeleton2DFromSpriterFile(lua_tostring(state, 1), lua_tonumber(state, 2), lua_tointeger(state, 3)));
		return 1;
	}
	else
	{
		agk::LoadSkeleton2DFromSpriterFile(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	}

	return 0;
}

int agkLua::SetSkeleton2DPosition(lua_State *state)
{
	agk::SetSkeleton2DPosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetSkeleton2DRotation(lua_State *state)
{
	agk::SetSkeleton2DRotation(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSkeleton2DFlip(lua_State *state)
{
	agk::SetSkeleton2DFlip(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetSkeleton2DDepth(lua_State *state)
{
	agk::SetSkeleton2DDepth(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::FixSkeleton2DToScreen(lua_State *state)
{
	agk::FixSkeleton2DToScreen(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetSkeleton2DX(lua_State *state)
{
	lua_pushnumber(state, agk::GetSkeleton2DX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSkeleton2DY(lua_State *state)
{
	lua_pushnumber(state, agk::GetSkeleton2DY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSkeleton2DAngle(lua_State *state)
{
	lua_pushnumber(state, agk::GetSkeleton2DAngle(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSkeleton2DBone(lua_State *state)
{
	lua_pushinteger(state, agk::GetSkeleton2DBone(lua_tointeger(state, 1), lua_tostring(state, 2)));
	return 1;
}

int agkLua::GetSkeleton2DBoneParent(lua_State *state)
{
	lua_pushinteger(state, agk::GetSkeleton2DBoneParent(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetSkeleton2DBoneX(lua_State *state)
{
	lua_pushnumber(state, agk::GetSkeleton2DBoneX(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetSkeleton2DBoneY(lua_State *state)
{
	lua_pushnumber(state, agk::GetSkeleton2DBoneY(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetSkeleton2DBoneAngle(lua_State *state)
{
	lua_pushnumber(state, agk::GetSkeleton2DBoneAngle(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetSkeleton2DBoneCurrX(lua_State *state)
{
	lua_pushnumber(state, agk::GetSkeleton2DBoneCurrX(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetSkeleton2DBoneCurrY(lua_State *state)
{
	lua_pushnumber(state, agk::GetSkeleton2DBoneCurrY(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetSkeleton2DBoneCurrAngle(lua_State *state)
{
	lua_pushnumber(state, agk::GetSkeleton2DBoneCurrAngle(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::SetSkeleton2DBonePosition(lua_State *state)
{
	agk::SetSkeleton2DBonePosition(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::SetSkeleton2DBoneAngle(lua_State *state)
{
	agk::SetSkeleton2DBoneAngle(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetSkeleton2DBoneScale(lua_State *state)
{
	agk::SetSkeleton2DBoneScale(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::SetSkeleton2DBoneMode(lua_State *state)
{
	agk::SetSkeleton2DBoneMode(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::PlaySkeleton2DAnimation(lua_State *state)
{
	agk::PlaySkeleton2DAnimation(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetSkeleton2DAnimationFrame(lua_State *state)
{
	agk::SetSkeleton2DAnimationFrame(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::SetSkeleton2DAnimationSpeed(lua_State *state)
{
	agk::SetSkeleton2DAnimationSpeed(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::GetSkeleton2DCurrentTime(lua_State *state)
{
	lua_tonumber(state, agk::GetSkeleton2DCurrentTime(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::StopSkeleton2DAnimation(lua_State *state)
{
	agk::StopSkeleton2DAnimation(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetSkeleton2DIsAnimating(lua_State *state)
{
	lua_pushinteger(state, agk::GetSkeleton2DIsAnimating(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSkeleton2DIsTweening(lua_State *state)
{
	lua_pushinteger(state, agk::GetSkeleton2DIsTweening(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSkeleton2DAnimationTime(lua_State *state)
{
	lua_pushnumber(state, agk::GetSkeleton2DAnimationTime(lua_tointeger(state, 1), lua_tostring(state, 2)));
	return 1;
}

int agkLua::DeleteTween(lua_State *state)
{
	agk::DeleteTween(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetTweenExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::TweenLinear(lua_State *state)
{
	lua_pushinteger(state, agk::TweenLinear());
	return 1;
}

int agkLua::TweenSmooth1(lua_State *state)
{
	lua_pushinteger(state, agk::TweenSmooth1());
	return 1;
}

int agkLua::TweenSmooth2(lua_State *state)
{
	lua_pushinteger(state, agk::TweenSmooth2());
	return 1;
}

int agkLua::TweenEaseIn1(lua_State *state)
{
	lua_pushinteger(state, agk::TweenEaseIn1());
	return 1;
}

int agkLua::TweenEaseIn2(lua_State *state)
{
	lua_pushinteger(state, agk::TweenEaseIn2());
	return 1;
}

int agkLua::TweenEaseOut1(lua_State *state)
{
	lua_pushinteger(state, agk::TweenEaseOut1());
	return 1;
}

int agkLua::TweenEaseOut2(lua_State *state)
{
	lua_pushinteger(state, agk::TweenEaseOut2());
	return 1;
}

int agkLua::TweenBounce(lua_State *state)
{
	lua_pushinteger(state, agk::TweenBounce());
	return 1;
}

int agkLua::TweenOvershoot(lua_State *state)
{
	lua_pushinteger(state, agk::TweenOvershoot());
	return 1;
}

int agkLua::CreateTweenSprite(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::CreateTweenSprite(lua_tonumber(state, 1)));
		return 1;
	}
	else
	{
		agk::CreateTweenSprite(lua_tointeger(state, 1), lua_tonumber(state, 2));
	}

	return 0;
}

int agkLua::GetTweenSpriteExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenSpriteExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetTweenSpriteX(lua_State *state)
{
	agk::SetTweenSpriteX(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenSpriteY(lua_State *state)
{
	agk::SetTweenSpriteY(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenSpriteAngle(lua_State *state)
{
	agk::SetTweenSpriteAngle(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenSpriteSizeX(lua_State *state)
{
	agk::SetTweenSpriteSizeX(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenSpriteSizeY(lua_State *state)
{
	agk::SetTweenSpriteSizeY(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenSpriteRed(lua_State *state)
{
	agk::SetTweenSpriteRed(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenSpriteGreen(lua_State *state)
{
	agk::SetTweenSpriteGreen(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenSpriteBlue(lua_State *state)
{
	agk::SetTweenSpriteBlue(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenSpriteAlpha(lua_State *state)
{
	agk::SetTweenSpriteAlpha(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::PlayTweenSprite(lua_State *state)
{
	agk::PlayTweenSprite(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::StopTweenSprite(lua_State *state)
{
	agk::StopTweenSprite(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetTweenSpritePlaying(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenSpritePlaying(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::CreateTweenText(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::CreateTweenText(lua_tonumber(state, 1)));
		return 1;
	}
	else
	{
		agk::CreateTweenText(lua_tointeger(state, 1), lua_tonumber(state, 2));
	}

	return 0;
}

int agkLua::GetTweenTextExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenTextExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetTweenTextX(lua_State *state)
{
	agk::SetTweenTextX(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenTextY(lua_State *state)
{
	agk::SetTweenTextY(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenTextAngle(lua_State *state)
{
	agk::SetTweenTextAngle(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenTextSize(lua_State *state)
{
	agk::SetTweenTextSize(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenTextSpacing(lua_State *state)
{
	agk::SetTweenTextSpacing(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenTextLineSpacing(lua_State *state)
{
	agk::SetTweenTextLineSpacing(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenTextRed(lua_State *state)
{
	agk::SetTweenTextRed(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenTextGreen(lua_State *state)
{
	agk::SetTweenTextGreen(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenTextBlue(lua_State *state)
{
	agk::SetTweenTextBlue(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenTextAlpha(lua_State *state)
{
	agk::SetTweenTextAlpha(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::PlayTweenText(lua_State *state)
{
	agk::PlayTweenText(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::StopTweenText(lua_State *state)
{
	agk::StopTweenText(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetTweenTextPlaying(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenTextPlaying(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::CreateTweenChar(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::CreateTweenChar(lua_tonumber(state, 1)));
		return 1;
	}
	else
	{
		agk::CreateTweenChar(lua_tointeger(state, 1), lua_tonumber(state, 2));
	}
	return 0;
}

int agkLua::GetTweenCharExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenCharExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetTweenCharX(lua_State *state)
{
	agk::SetTweenCharX(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCharY(lua_State *state)
{
	agk::SetTweenCharY(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCharAngle(lua_State *state)
{
	agk::SetTweenCharAngle(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCharRed(lua_State *state)
{
	agk::SetTweenCharRed(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCharGreen(lua_State *state)
{
	agk::SetTweenCharGreen(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCharBlue(lua_State *state)
{
	agk::SetTweenCharBlue(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCharAlpha(lua_State *state)
{
	agk::SetTweenCharAlpha(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::PlayTweenChar(lua_State *state)
{
	agk::PlayTweenChar(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::StopTweenChar(lua_State *state)
{
	agk::StopTweenChar(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::GetTweenCharPlaying(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenCharPlaying(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3)));
	return 1;
}

int agkLua::CreateTweenObject(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::CreateTweenObject(lua_tonumber(state, 1)));
		return 1;
	}
	else
	{
		agk::CreateTweenObject(lua_tointeger(state, 1), lua_tonumber(state, 2));
	}
	return 0;
}

int agkLua::GetTweenObjectExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenObjectExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetTweenObjectX(lua_State *state)
{
	agk::SetTweenObjectX(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectY(lua_State *state)
{
	agk::SetTweenObjectY(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectZ(lua_State *state)
{
	agk::SetTweenObjectZ(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectAngleX(lua_State *state)
{
	agk::SetTweenObjectAngleX(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectAngleY(lua_State *state)
{
	agk::SetTweenObjectAngleY(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectAngleZ(lua_State *state)
{
	agk::SetTweenObjectAngleZ(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectScaleX(lua_State *state)
{
	agk::SetTweenObjectScaleX(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectScaleY(lua_State *state)
{
	agk::SetTweenObjectScaleY(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectScaleZ(lua_State *state)
{
	agk::SetTweenObjectScaleZ(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectRed(lua_State *state)
{
	agk::SetTweenObjectRed(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectGreen(lua_State *state)
{
	agk::SetTweenObjectGreen(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectBlue(lua_State *state)
{
	agk::SetTweenObjectBlue(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenObjectAlpha(lua_State *state)
{
	agk::SetTweenObjectAlpha(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::PlayTweenObject(lua_State *state)
{
	agk::PlayTweenObject(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::StopTweenObject(lua_State *state)
{
	agk::StopTweenObject(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetTweenObjectPlaying(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenObjectPlaying(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::CreateTweenCamera(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::CreateTweenCamera(lua_tonumber(state, 1)));
		return 1;
	}
	else
	{
		agk::CreateTweenCamera(lua_tointeger(state, 1), lua_tonumber(state, 2));
	}
	return 0;
}

int agkLua::GetTweenCameraExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenCameraExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetTweenCameraX(lua_State *state)
{
	agk::SetTweenCameraX(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCameraY(lua_State *state)
{
	agk::SetTweenCameraY(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCameraZ(lua_State *state)
{
	agk::SetTweenCameraZ(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCameraAngleX(lua_State *state)
{
	agk::SetTweenCameraAngleX(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCameraAngleY(lua_State *state)
{
	agk::SetTweenCameraAngleY(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCameraAngleZ(lua_State *state)
{
	agk::SetTweenCameraAngleZ(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetTweenCameraFOV(lua_State *state)
{
	agk::SetTweenCameraFOV(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::PlayTweenCamera(lua_State *state)
{
	agk::PlayTweenCamera(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::StopTweenCamera(lua_State *state)
{
	agk::StopTweenCamera(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetTweenCameraPlaying(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenCameraPlaying(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::CreateTweenChain(lua_State *state)
{
	if (lua_gettop(state) == 0)
	{
		lua_pushinteger(state, agk::CreateTweenChain());
		return 1;
	}
	else
	{
		agk::CreateTweenChain(lua_tointeger(state, 1));
	}

	return 0;
}

int agkLua::DeleteTweenChain(lua_State *state)
{
	agk::DeleteTweenChain(lua_tointeger(state, 1));
	return 0;
}

int agkLua::ClearTweenChain(lua_State *state)
{
	agk::ClearTweenChain(lua_tointeger(state, 1));
	return 0;
}

int agkLua::AddTweenChainSprite(lua_State *state)
{
	agk::AddTweenChainSprite(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::AddTweenChainText(lua_State *state)
{
	agk::AddTweenChainText(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::AddTweenChainChar(lua_State *state)
{
	agk::AddTweenChainChar(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::AddTweenChainObject(lua_State *state)
{
	agk::AddTweenChainObject(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::AddTweenChainCamera(lua_State *state)
{
	agk::AddTweenChainCamera(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::PlayTweenChain(lua_State *state)
{
	agk::PlayTweenChain(lua_tointeger(state, 1));
	return 0;
}

int agkLua::PauseTweenChain(lua_State *state)
{
	agk::PauseTweenChain(lua_tointeger(state, 1));
	return 0;
}

int agkLua::StopTweenChain(lua_State *state)
{
	agk::StopTweenChain(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetTweenChainPlaying(lua_State *state)
{
	lua_pushinteger(state, agk::GetTweenChainPlaying(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetTweenChainTime(lua_State *state)
{
	agk::SetTweenChainTime(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::GetTweenChainEndTime(lua_State *state)
{
	lua_pushnumber(state, agk::GetTweenChainEndTime(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::UpdateAllTweens(lua_State *state)
{
	agk::UpdateAllTweens(lua_tonumber(state, 1));
	return 0;
}

int agkLua::UpdateTweenChain(lua_State *state)
{
	agk::UpdateTweenChain(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::Print(lua_State *state)
{
	if (lua_type(state, 1) == LUA_TSTRING)
	{
		agk::Print(lua_tostring(state, 1));
	}
	else
	{
		agk::Print((float)lua_tonumber(state, 1));
	}

	return 0;
}

int agkLua::PrintC(lua_State *state)
{
	if (lua_type(state, 1) == LUA_TSTRING)
	{
		agk::PrintC(lua_tostring(state, 1));
	}
	else
	{
		agk::PrintC((float)lua_tonumber(state, 1));
	}
	return 0;
}

int agkLua::SetPrintSize(lua_State *state)
{
	agk::SetPrintSize(lua_tonumber(state, 1));
	return 0;
}

int agkLua::GetPrintSize(lua_State *state)
{
	lua_pushnumber(state, agk::GetPrintSize());
	return 1;
}

int agkLua::SetPrintSpacing(lua_State *state)
{
	agk::SetPrintSpacing(lua_tonumber(state, 1));
	return 0;
}

int agkLua::SetPrintColor(lua_State *state)
{
	if (lua_gettop(state) == 4)
	{
		agk::SetPrintColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	}
	else
	{
		agk::SetPrintColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	}
	
	return 0;
}

int agkLua::GetMultiTouchExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetMultiTouchExists());
	return 1;
}

int agkLua::GetMouseExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetMouseExists());
	return 1;
}

int agkLua::GetKeyboardExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetKeyboardExists());
	return 1;
}

int agkLua::GetJoystickExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetJoystickExists());
	return 1;
}

int agkLua::GetCameraExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetCameraExists());
	return 1;
}

int agkLua::GetAccelerometerExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetAccelerometerExists());
	return 1;
}

int agkLua::GetGyroSensorExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetGyroSensorExists());
	return 1;
}

int agkLua::GetProximitySensorExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetProximitySensorExists());
	return 1;
}

int agkLua::GetLightSensorExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetLightSensorExists());
	return 1;
}

int agkLua::GetMagneticSensorExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetMagneticSensorExists());
	return 1;
}

int agkLua::GetRotationVectorSensorExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetRotationVectorSensorExists());
	return 1;
}

int agkLua::GetGPSSensorExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetGPSSensorExists());
	return 1;
}

int agkLua::GetRawTouchCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawTouchCount());
	return 1;
}

int agkLua::GetRawFirstTouchEvent(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::GetRawFirstTouchEvent(lua_tointeger(state, 1)));
	}
	else
	{
		lua_pushinteger(state, agk::GetRawFirstTouchEvent());
	}
	
	return 1;
}

int agkLua::GetRawNextTouchEvent(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawNextTouchEvent());
	return 1;
}

int agkLua::GetRawTouchType(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawTouchType(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawTouchStartX(lua_State *state)
{
	lua_tonumber(state, agk::GetRawTouchStartX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawTouchStartY(lua_State *state)
{
	lua_tonumber(state, agk::GetRawTouchStartY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawTouchCurrentX(lua_State *state)
{
	lua_tonumber(state, agk::GetRawTouchCurrentX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawTouchCurrentY(lua_State *state)
{
	lua_tonumber(state, agk::GetRawTouchCurrentY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawTouchLastX(lua_State *state)
{
	lua_tonumber(state, agk::GetRawTouchLastX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawTouchLastY(lua_State *state)
{
	lua_tonumber(state, agk::GetRawTouchLastY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawTouchReleased(lua_State *state)
{
	lua_toboolean(state, agk::GetRawTouchReleased(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetRawTouchValue(lua_State *state)
{
	agk::SetRawTouchValue(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetRawTouchValue(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawTouchValue(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawTouchTime(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawTouchTime(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawMouseX(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawMouseX());
	return 1;
}

int agkLua::GetRawMouseY(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawMouseY());
	return 1;
}

int agkLua::GetRawMouseWheel(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawMouseWheel());
	return 1;
}

int agkLua::GetRawMouseWheelDelta(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawMouseWheelDelta());
	return 1;
}

int agkLua::GetRawMouseLeftPressed(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawMouseLeftPressed());
	return 1;
}

int agkLua::GetRawMouseLeftState(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawMouseLeftState());
	return 1;
}

int agkLua::GetRawMouseLeftReleased(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawMouseLeftReleased());
	return 1;
}

int agkLua::GetRawMouseRightPressed(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawMouseRightPressed());
	return 1;
}

int agkLua::GetRawMouseRightState(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawMouseRightState());
	return 1;
}

int agkLua::GetRawMouseRightReleased(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawMouseRightReleased());
	return 1;
}

int agkLua::GetRawMouseMiddlePressed(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawMouseMiddlePressed());
	return 1;
}

int agkLua::GetRawMouseMiddleState(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawMouseMiddleState());
	return 1;
}

int agkLua::GetRawMouseMiddleReleased(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawMouseMiddleReleased());
	return 1;
}

int agkLua::SetRawMouseVisible(lua_State *state)
{
	agk::SetRawMouseVisible(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetRawMousePosition(lua_State *state)
{
	agk::SetRawMousePosition(lua_tonumber(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::FixOrientationByDefault(lua_State *state)
{
	agk::FixOrientationByDefault();
	return 0;
}

int agkLua::GetRawAccelX(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawAccelX());
	return 1;
}

int agkLua::GetRawAccelY(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawAccelY());
	return 1;
}

int agkLua::GetRawAccelZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawAccelZ());
	return 1;
}

int agkLua::GetRawGyroVelocityX(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawGyroVelocityX());
	return 1;
}

int agkLua::GetRawGyroVelocityY(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawGyroVelocityY());
	return 1;
}

int agkLua::GetRawGyroVelocityZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawGyroVelocityZ());
	return 1;
}

int agkLua::GetRawProximityDistance(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawProximityDistance());
	return 1;
}

int agkLua::GetRawLightLevel(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawLightLevel());
	return 1;
}

int agkLua::GetRawMagneticX(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawMagneticX());
	return 1;
}

int agkLua::GetRawMagneticY(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawMagneticY());
	return 1;
}

int agkLua::GetRawMagneticZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawMagneticZ());
	return 1;
}

int agkLua::GetRawRotationVectorX(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawRotationVectorX());
	return 1;
}

int agkLua::GetRawRotationVectorY(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawRotationVectorY());
	return 1;
}

int agkLua::GetRawRotationVectorZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawRotationVectorZ());
	return 1;
}

int agkLua::GetRawRotationVectorW(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawRotationVectorW());
	return 1;
}

int agkLua::GetRawRotationVectorX2(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawRotationVectorX2());
	return 1;
}

int agkLua::GetRawRotationVectorY2(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawRotationVectorY2());
	return 1;
}

int agkLua::GetRawRotationVectorZ2(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawRotationVectorZ2());
	return 1;
}

int agkLua::GetRawRotationVectorW2(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawRotationVectorW2());
	return 1;
}

int agkLua::StartGPSTracking(lua_State *state)
{
	agk::StartGPSTracking();
	return 0;
}

int agkLua::StopGPSTracking(lua_State *state)
{
	agk::StopGPSTracking();
	return 0;
}

int agkLua::GetRawGPSLatitude(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawGPSLatitude());
	return 1;
}

int agkLua::GetRawGPSLongitude(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawGPSLongitude());
	return 1;
}

int agkLua::GetRawGPSAltitude(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawGPSAltitude());
	return 1;
}

int agkLua::CompleteRawJoystickDetection(lua_State *state)
{
	agk::CompleteRawJoystickDetection();
	return 0;
}

int agkLua::GetRawJoystickExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawJoystickExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawJoystickConnected(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawJoystickConnected(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawJoystickX(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawJoystickX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawJoystickY(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawJoystickY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawJoystickZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawJoystickZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawJoystickRX(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawJoystickRX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawJoystickRY(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawJoystickRY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawJoystickRZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetRawJoystickRZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawJoystickButtonPressed(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawJoystickButtonPressed(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetRawJoystickButtonState(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawJoystickButtonState(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetRawJoystickButtonReleased(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawJoystickButtonReleased(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::SetRawJoystickDeadZone(lua_State *state)
{
	agk::SetRawJoystickDeadZone(lua_tonumber(state, 1));
	return 0;
}

int agkLua::AddVirtualJoystick(lua_State *state)
{
	agk::AddVirtualJoystick(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::DeleteVirtualJoystick(lua_State *state)
{
	agk::DeleteVirtualJoystick(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetVirtualJoystickExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetVirtualJoystickExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetVirtualJoystickX(lua_State *state)
{
	lua_pushnumber(state, agk::GetVirtualJoystickX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetVirtualJoystickY(lua_State *state)
{
	lua_pushnumber(state, agk::GetVirtualJoystickY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetVirtualJoystickAlpha(lua_State *state)
{
	agk::SetVirtualJoystickAlpha(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetVirtualJoystickPosition(lua_State *state)
{
	agk::SetVirtualJoystickPosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetVirtualJoystickSize(lua_State *state)
{
	agk::SetVirtualJoystickSize(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetVirtualJoystickActive(lua_State *state)
{
	agk::SetVirtualJoystickActive(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetVirtualJoystickVisible(lua_State *state)
{
	agk::SetVirtualJoystickVisible(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetVirtualJoystickImageInner(lua_State *state)
{
	agk::SetVirtualJoystickImageInner(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetVirtualJoystickImageOuter(lua_State *state)
{
	agk::SetVirtualJoystickImageOuter(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetVirtualJoystickDeadZone(lua_State *state)
{
	agk::SetVirtualJoystickDeadZone(lua_tonumber(state, 1));
	return 0;
}

int agkLua::AddVirtualButton(lua_State *state)
{
	agk::AddVirtualButton(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::DeleteVirtualButton(lua_State *state)
{
	agk::DeleteVirtualButton(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetVirtualButtonExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetVirtualButtonExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetVirtualButtonPressed(lua_State *state)
{
	lua_pushinteger(state, agk::GetVirtualButtonPressed(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetVirtualButtonReleased(lua_State *state)
{
	lua_pushinteger(state, agk::GetVirtualButtonReleased(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetVirtualButtonState(lua_State *state)
{
	lua_pushinteger(state, agk::GetVirtualButtonState(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetVirtualButtonColor(lua_State *state)
{
	agk::SetVirtualButtonColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetVirtualButtonAlpha(lua_State *state)
{
	agk::SetVirtualButtonAlpha(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetVirtualButtonPosition(lua_State *state)
{
	agk::SetVirtualButtonPosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetVirtualButtonSize(lua_State *state)
{
	agk::SetVirtualButtonSize(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetVirtualButtonActive(lua_State *state)
{
	agk::SetVirtualButtonActive(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetVirtualButtonVisible(lua_State *state)
{
	agk::SetVirtualButtonVisible(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetVirtualButtonImageUp(lua_State *state)
{
	agk::SetVirtualButtonImageUp(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetVirtualButtonImageDown(lua_State *state)
{
	agk::SetVirtualButtonImageDown(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetVirtualButtonText(lua_State *state)
{
	agk::SetVirtualButtonText(lua_tointeger(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::GetRawKeyPressed(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawKeyPressed(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawKeyState(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawKeyState(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawKeyReleased(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawKeyReleased(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetRawLastKey(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawLastKey());
	return 1;
}

int agkLua::GetPointerPressed(lua_State *state)
{
	lua_pushinteger(state, agk::GetPointerPressed());
	return 1;
}

int agkLua::GetPointerState(lua_State *state)
{
	lua_pushinteger(state, agk::GetPointerState());
	return 1;
}

int agkLua::GetPointerReleased(lua_State *state)
{
	lua_pushinteger(state, agk::GetPointerReleased());
	return 1;
}


//NOT AND OFFICIAL COMMAND
int agkLua::GetPointerGesture(lua_State *state)
{
	return 0;
}

int agkLua::GetPointerX(lua_State *state)
{
	lua_pushnumber(state, agk::GetPointerX());
	return 1;
}

int agkLua::GetPointerY(lua_State *state)
{
	lua_pushnumber(state, agk::GetPointerY());
	return 1;
}

int agkLua::GetDirectionX(lua_State *state)
{
	lua_pushnumber(state, agk::GetDirectionX());
	return 1;
}

int agkLua::GetDirectionY(lua_State *state)
{
	lua_pushnumber(state, agk::GetDirectionY());
	return 1;
}

int agkLua::GetDirectionAngle(lua_State *state)
{
	lua_pushnumber(state, agk::GetDirectionAngle());
	return 1;
}

int agkLua::GetDirectionSpeed(lua_State *state)
{
	lua_pushnumber(state, agk::GetDirectionSpeed());
	return 1;
}

int agkLua::GetJoystickX(lua_State *state)
{
	lua_pushnumber(state, agk::GetJoystickX());
	return 1;
}

int agkLua::GetJoystickY(lua_State *state)
{
	lua_pushnumber(state, agk::GetJoystickY());
	return 1;
}

int agkLua::SetJoystickScreenPosition(lua_State *state)
{
	agk::SetJoystickScreenPosition(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetJoystickDeadZone(lua_State *state)
{
	agk::SetJoystickDeadZone(lua_tonumber(state, 1));
	return 0;
}

int agkLua::GetButtonPressed(lua_State *state)
{
	lua_pushinteger(state, agk::GetButtonPressed(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetButtonState(lua_State *state)
{
	lua_pushinteger(state, agk::GetButtonState(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetButtonReleased(lua_State *state)
{
	lua_pushinteger(state, agk::GetButtonReleased(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetButtonScreenPosition(lua_State *state)
{
	agk::SetButtonScreenPosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::StartTextInput(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		agk::StartTextInput(lua_tostring(state, 1));
	}
	else
	{
		agk::StartTextInput();
	}
	return 0;
}

int agkLua::StopTextInput(lua_State *state)
{
	agk::StopTextInput();
	return 0;
}

int agkLua::GetTextInputState(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextInputState());
	return 1;
}

int agkLua::GetTextInputCompleted(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextInputCompleted());
	return 1;
}

int agkLua::GetTextInputCancelled(lua_State *state)
{
	lua_pushinteger(state, agk::GetTextInputCancelled());
	return 1;
}

int agkLua::GetTextInput(lua_State *state)
{
	char *s = agk::GetTextInput();
	lua_pushstring(state, s);
	delete[] s;
	
	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetPrevChar(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetLastChar(lua_State *state)
{
	return 0;
}

int agkLua::SetCursorBlinkTime(lua_State *state)
{
	agk::SetCursorBlinkTime(lua_tonumber(state, 1));
	return 0;
}

int agkLua::SetTextInputMaxChars(lua_State *state)
{
	agk::SetTextInputMaxChars(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetTextInputLabel(lua_State *state)
{
	agk::SetTextInputLabel(lua_tostring(state, 1));
	return 0;
}

int agkLua::CreateEditBox(lua_State *state)
{
	if (lua_gettop(state) == 0)
	{
		lua_pushinteger(state, agk::CreateEditBox());
		return 1;
	}
	else
	{
		agk::CreateEditBox(lua_tointeger(state, 1));
	}

	return 0;
}

int agkLua::GetEditBoxExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetEditBoxExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::DeleteEditBox(lua_State *state)
{
	agk::DeleteEditBox(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetEditBoxHasFocus(lua_State *state)
{
	lua_pushinteger(state, agk::GetEditBoxHasFocus(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetCurrentEditBox(lua_State *state)
{
	lua_pushinteger(state, agk::GetCurrentEditBox());
	return 1;
}

int agkLua::SetEditBoxPosition(lua_State *state)
{
	agk::SetEditBoxPosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetEditBoxSize(lua_State *state)
{
	agk::SetEditBoxSize(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetEditBoxDepth(lua_State *state)
{
	agk::SetEditBoxDepth(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxBorderSize(lua_State *state)
{
	agk::SetEditBoxBorderSize(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetEditBoxBorderColor(lua_State *state)
{
	agk::SetEditBoxBorderColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	return 0;
}

int agkLua::SetEditBoxBackgroundColor(lua_State *state)
{
	agk::SetEditBoxBackgroundColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	return 0;
}

int agkLua::SetEditBoxText(lua_State *state)
{
	agk::SetEditBoxText(lua_tointeger(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::SetEditBoxTextColor(lua_State *state)
{
	agk::SetEditBoxTextColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetEditBoxCursorColor(lua_State *state)
{
	agk::SetEditBoxCursorColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetEditBoxFontImage(lua_State *state)
{
	agk::SetEditBoxFontImage(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxExtendedFontImage(lua_State *state)
{
	agk::SetEditBoxExtendedFontImage(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxTextSize(lua_State *state)
{
	agk::SetEditBoxTextSize(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetEditBoxCursorPosition(lua_State *state)
{
	agk::SetEditBoxCursorPosition(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxFocus(lua_State *state)
{
	agk::SetEditBoxFocus(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxActive(lua_State *state)
{
	agk::SetEditBoxActive(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxVisible(lua_State *state)
{
	agk::SetEditBoxVisible(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxBorderImage(lua_State *state)
{
	agk::SetEditBoxBorderImage(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxBackgroundImage(lua_State *state)
{
	agk::SetEditBoxBackgroundImage(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxCursorBlinkTime(lua_State *state)
{
	agk::SetEditBoxCursorBlinkTime(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetEditBoxCursorWidth(lua_State *state)
{
	agk::SetEditBoxCursorWidth(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetEditBoxMaxChars(lua_State *state)
{
	agk::SetEditBoxMaxChars(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxMaxLines(lua_State *state)
{
	agk::SetEditBoxMaxLines(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxMultiLine(lua_State *state)
{
	agk::SetEditBoxMultiLine(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxScissor(lua_State *state)
{
	agk::SetEditBoxScissor(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetEditBoxPasswordMode(lua_State *state)
{
	agk::SetEditBoxPasswordMode(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxUseAlternateInput(lua_State *state)
{
	agk::SetEditBoxUseAlternateInput(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetEditBoxWrapMode(lua_State *state)
{
	agk::SetEditBoxWrapMode(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::FixEditBoxToScreen(lua_State *state)
{
	agk::FixEditBoxToScreen(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetEditBoxText(lua_State *state)
{
	char *s = agk::GetEditBoxText(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetEditBoxX(lua_State *state)
{
	lua_pushnumber(state, agk::GetEditBoxX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetEditBoxY(lua_State *state)
{
	lua_pushnumber(state, agk::GetEditBoxY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetEditBoxWidth(lua_State *state)
{
	lua_pushnumber(state, agk::GetEditBoxWidth(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetEditBoxHeight(lua_State *state)
{
	lua_pushnumber(state, agk::GetEditBoxHeight(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetEditBoxChanged(lua_State *state)
{
	lua_pushinteger(state, agk::GetEditBoxChanged(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetEditBoxActive(lua_State *state)
{
	lua_pushinteger(state, agk::GetEditBoxActive(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetEditBoxVisible(lua_State *state)
{
	lua_pushinteger(state, agk::GetEditBoxVisible(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetEditBoxLines(lua_State *state)
{
	lua_pushinteger(state, agk::GetEditBoxLines(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::LoadSound(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::LoadSound(lua_tostring(state, 1)));
		return 1;
	}
	else
	{
		agk::LoadSound(lua_tointeger(state, 1), lua_tostring(state, 2));
	}
	return 0;
}

int agkLua::PlaySound(lua_State *state)
{
	switch (lua_gettop(state))
	{
	case 1:
		agk::PlaySound(lua_tointeger(state, 1));
		break;
	case 2:
		agk::PlaySound(lua_tointeger(state, 1), lua_tointeger(state, 2));
		break;
	case 3:
		agk::PlaySound(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
		break;
	case 4:
		agk::PlaySound(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
		break;
	}
	return 0;
}

int agkLua::StopSound(lua_State *state)
{
	agk::StopSound(lua_tointeger(state, 1));
	return 0;
}

int agkLua::DeleteSound(lua_State *state)
{
	agk::DeleteSound(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetSoundInstances(lua_State *state)
{
	lua_pushinteger(state, agk::GetSoundInstances(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSoundsPlaying(lua_State *state)
{
	lua_pushinteger(state, agk::GetSoundsPlaying(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetSoundSystemVolume(lua_State *state)
{
	agk::SetSoundSystemVolume(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetSoundExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetSoundExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSoundMaxRate(lua_State *state)
{
	lua_pushnumber(state, agk::GetSoundMaxRate());
	return 1;
}

int agkLua::GetSoundMinRate(lua_State *state)
{
	lua_pushnumber(state, agk::GetSoundMinRate());
	return 1;
}

int agkLua::SaveSound(lua_State *state)
{
	agk::SaveSound(lua_tointeger(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::GetSoundInstancePlaying(lua_State *state)
{
	lua_pushinteger(state, agk::GetSoundInstancePlaying(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSoundInstanceVolume(lua_State *state)
{
	lua_pushinteger(state, agk::GetSoundInstanceVolume(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSoundInstanceRate(lua_State *state)
{
	lua_pushnumber(state, agk::GetSoundInstanceRate(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetSoundInstanceVolume(lua_State *state)
{
	agk::SetSoundInstanceVolume(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetSoundInstanceRate(lua_State *state)
{
	agk::SetSoundInstanceRate(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetSoundInstanceBalance(lua_State *state)
{
	agk::SetSoundInstanceBalance(lua_tointeger(state, 1), lua_tonumber(state, 1));
	return 0;
}

int agkLua::GetSoundInstanceLoopCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetSoundInstanceLoopCount(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::StopSoundInstance(lua_State *state)
{
	agk::StopSoundInstance(lua_tointeger(state, 1));
	return 0;
}

int agkLua::LoadMusic(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		lua_pushinteger(state, agk::LoadMusic(lua_tostring(state, 1)));
		return 1;
	}
	else
	{
		agk::LoadMusic(lua_tointeger(state, 1), lua_tostring(state, 2));
	}
	return 0;
}

int agkLua::SetMusicFileVolume(lua_State *state)
{
	agk::SetMusicFileVolume(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::PlayMusic(lua_State *state)
{
	switch (lua_gettop(state))
	{
	case 0:
		agk::PlayMusic();
		break;
	case 1:
		agk::PlayMusic(lua_tointeger(state, 1));
		break;
	case 2:
		agk::PlayMusic(lua_tointeger(state, 1), lua_tointeger(state, 2));
		break;
	case 4:
		agk::PlayMusic(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
		break;
	}
	return 0;
}

int agkLua::PauseMusic(lua_State *state)
{
	agk::PauseMusic();
	return 0;
}

int agkLua::ResumeMusic(lua_State *state)
{
	agk::ResumeMusic();
	return 0;
}

int agkLua::StopMusic(lua_State *state)
{
	agk::StopMusic();
	return 0;
}

int agkLua::DeleteMusic(lua_State *state)
{
	agk::DeleteMusic(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetMusicPlaying(lua_State *state)
{
	lua_pushinteger(state, agk::GetMusicPlaying());
	return 1;
}

int agkLua::SetMusicSystemVolume(lua_State *state)
{
	agk::SetMusicSystemVolume(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetMusicExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetMusicExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetMusicDuration(lua_State *state)
{
	lua_pushnumber(state, agk::GetMusicDuration(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetMusicPosition(lua_State *state)
{
	lua_pushnumber(state, agk::GetMusicPosition());
	return 1;
}

int agkLua::SeekMusic(lua_State *state)
{
	agk::SeekMusic(lua_tonumber(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::RecordSound(lua_State *state)
{
	agk::RecordSound(lua_tostring(state, 1));
	return 0;
}

int agkLua::StopSoundRecording(lua_State *state)
{
	agk::StopSoundRecording();
	return 0;
}

int agkLua::IsSoundRecording(lua_State *state)
{
	lua_pushinteger(state, agk::IsSoundRecording());
	return 1;
}

int agkLua::SetRawWritePath(lua_State *state)
{
	agk::SetRawWritePath(lua_tostring(state, 1));
	return 0;
}

int agkLua::GetWritePath(lua_State *state)
{
	char *s = agk::GetWritePath();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetReadPath(lua_State *state)
{
	char *s = agk::GetReadPath();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetDocumentsPath(lua_State *state)
{
	char *s = agk::GetDocumentsPath();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::ChooseRawFile(lua_State *state)
{
	char *s = agk::ChooseRawFile(lua_tostring(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetFileExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetFileExists(lua_tostring(state, 1)));
	return 1;
}

int agkLua::agkDeleteFile(lua_State *state)
{
	agk::DeleteFileA(lua_tostring(state, 1));
	return 0;
}

int agkLua::OpenToWrite(lua_State *state)
{
	switch(lua_gettop(state))
	{
	case 1:
		lua_pushinteger(state, agk::OpenToWrite(lua_tostring(state, 1)));
		return 1;
		break;
	case 2:
		if (lua_type(state, 1) == LUA_TSTRING)
		{
			lua_pushinteger(state, agk::OpenToWrite(lua_tostring(state, 1), lua_tointeger(state, 2)));
			return 1;
		}
		else
		{
			agk::OpenToWrite(lua_tointeger(state, 1), lua_tostring(state, 2));
		}
		break;
	case 3:
		agk::OpenToWrite(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tointeger(state, 3));
		break;
	}
	return 0;
}

int agkLua::OpenToRead(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		lua_pushinteger(state, agk::OpenToRead(lua_tostring(state, 1)));
	}
	else
	{
		agk::OpenToRead(lua_tointeger(state, 1), lua_tostring(state, 2));
	}
	return 0;
}

int agkLua::FileIsOpen(lua_State *state)
{
	lua_pushinteger(state, agk::FileIsOpen(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::CloseFile(lua_State *state)
{
	agk::CloseFile(lua_tointeger(state, 1));
	return 0;
}

int agkLua::FileEOF(lua_State *state)
{
	lua_pushinteger(state, agk::FileEOF(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetFileSize(lua_State *state)
{
	lua_pushinteger(state, agk::GetFileSize(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::WriteByte(lua_State *state)
{
	agk::WriteByte(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::WriteInteger(lua_State *state)
{
	agk::WriteInteger(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::WriteFloat(lua_State *state)
{
	agk::WriteFloat(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::WriteString(lua_State *state)
{
	agk::WriteString(lua_tointeger(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::WriteString2(lua_State *state)
{
	agk::WriteString2(lua_tointeger(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::WriteLine(lua_State *state)
{
	agk::WriteLine(lua_tointeger(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::ReadByte(lua_State *state)
{
	lua_pushinteger(state, agk::ReadByte(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::ReadInteger(lua_State *state)
{
	lua_pushinteger(state, agk::ReadInteger(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::ReadFloat(lua_State *state)
{
	lua_pushnumber(state, agk::ReadFloat(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::ReadString(lua_State *state)
{
	char *s = agk::ReadString(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::ReadString2(lua_State *state)
{
	char *s = agk::ReadString2(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::ReadLine(lua_State *state)
{
	char *s = agk::ReadLine(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::SetCurrentDir(lua_State *state)
{
	agk::SetCurrentDir(lua_tostring(state, 1));
	return 0;
}

int agkLua::GetCurrentDir(lua_State *state)
{
	char *s = agk::GetCurrentDir();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::SetFolder(lua_State *state)
{
	agk::SetFolder(lua_tostring(state, 1));
	return 0;
}

int agkLua::GetFolder(lua_State *state)
{
	char *s = agk::GetFolder();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::MakeFolder(lua_State *state)
{
	agk::MakeFolder(lua_tostring(state, 1));
	return 0;
}

int agkLua::DeleteFolder(lua_State *state)
{
	agk::DeleteFolder(lua_tostring(state, 1));
	return 0;
}

int agkLua::GetFirstFolder(lua_State *state)
{
	char *s = agk::GetFirstFolder();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetNextFolder(lua_State *state)
{
	char *s = agk::GetNextFolder();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetFolderCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetFolderCount());
	return 1;
}

int agkLua::GetFirstFile(lua_State *state)
{
	char *s = agk::GetFirstFile();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetNextFile(lua_State *state)
{
	char *s = agk::GetNextFile();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetFileCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetFileCount());
	return 1;
}

int agkLua::CreateBroadcastListener(lua_State *state)
{
	lua_pushinteger(state, agk::CreateBroadcastListener(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::DeleteBroadcastListener(lua_State *state)
{
	agk::DeleteBroadcastListener(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetBroadcastMessage(lua_State *state)
{
	lua_pushinteger(state, agk::GetBroadcastMessage(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::HostNetwork(lua_State *state)
{
	agk::HostNetwork(lua_tostring(state, 1), lua_tostring(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetNetworkNoMoreClients(lua_State *state)
{
	agk::SetNetworkNoMoreClients(lua_tointeger(state, 1));
	return 0;
}

int agkLua::JoinNetwork(lua_State *state)
{
	if (lua_gettop(state) == 3)
	{
		lua_pushinteger(state, agk::JoinNetwork(lua_tostring(state, 1), lua_tointeger(state, 2), lua_tostring(state, 3)));
	}
	else
	{
		lua_pushinteger(state, agk::JoinNetwork(lua_tostring(state, 1), lua_tostring(state, 2)));
	}

	return 1;
}

int agkLua::IsNetworkActive(lua_State *state)
{
	lua_pushinteger(state, agk::IsNetworkActive(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetDeviceIP(lua_State *state)
{
	char *s = agk::GetDeviceIP();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::CloseNetwork(lua_State *state)
{
	agk::CloseNetwork(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetNetworkLatency(lua_State *state)
{
	agk::SetNetworkLatency(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetNetworkMyClientID(lua_State *state)
{
	lua_pushinteger(state, agk::GetNetworkMyClientID(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetNetworkNumClients(lua_State *state)
{
	lua_pushinteger(state, agk::GetNetworkNumClients(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetNetworkFirstClient(lua_State *state)
{
	lua_pushinteger(state, agk::GetNetworkFirstClient(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetNetworkNextClient(lua_State *state)
{
	lua_pushinteger(state, agk::GetNetworkNextClient(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetNetworkClientDisconnected(lua_State *state)
{
	lua_pushinteger(state, agk::GetNetworkClientDisconnected(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::DeleteNetworkClient(lua_State *state)
{
	agk::DeleteNetworkClient(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetNetworkClientName(lua_State *state)
{
	char *s = agk::GetNetworkClientName(lua_tointeger(state, 1), lua_tointeger(state, 2));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetNetworkClientPing(lua_State *state)
{
	lua_pushnumber(state, agk::GetNetworkClientPing(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetNetworkServerID(lua_State *state)
{
	lua_pushinteger(state, agk::GetNetworkServerID(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetNetworkLocalInteger(lua_State *state)
{
	if (lua_gettop(state) == 4)
	{
		agk::SetNetworkLocalInteger(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	}
	else
	{
		agk::SetNetworkLocalInteger(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tointeger(state, 3));
	}
	return 0;
}

int agkLua::SetNetworkLocalFloat(lua_State *state)
{
	if (lua_gettop(state) == 4)
	{
		agk::SetNetworkLocalFloat(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	}
	else
	{
		agk::SetNetworkLocalFloat(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tonumber(state, 3));
	}
	return 0;
}

int agkLua::GetNetworkClientInteger(lua_State *state)
{
	lua_pushinteger(state, agk::GetNetworkClientInteger(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tostring(state, 3)));
	return 1;
}

int agkLua::GetNetworkClientFloat(lua_State *state)
{
	lua_pushnumber(state, agk::GetNetworkClientInteger(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tostring(state, 3)));
	return 1;
}

int agkLua::CreateNetworkMessage(lua_State *state)
{
	lua_pushinteger(state, agk::CreateNetworkMessage());
	return 1;
}

int agkLua::AddNetworkMessageInteger(lua_State *state)
{
	agk::AddNetworkMessageInteger(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::AddNetworkMessageFloat(lua_State *state)
{
	agk::AddNetworkMessageFloat(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::AddNetworkMessageString(lua_State *state)
{
	agk::AddNetworkMessageString(lua_tointeger(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::GetNetworkMessageFromIP(lua_State *state)
{
	char *s = agk::GetNetworkMessageFromIP(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetNetworkMessageFromClient(lua_State *state)
{
	lua_pushinteger(state, agk::GetNetworkMessageFromClient(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetNetworkMessageInteger(lua_State *state)
{
	lua_pushinteger(state, agk::GetNetworkMessageInteger(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetNetworkMessageFloat(lua_State *state)
{
	lua_pushnumber(state, agk::GetNetworkMessageFloat(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetNetworkMessageString(lua_State *state)
{
	char *s = agk::GetNetworkMessageString(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::DeleteNetworkMessage(lua_State *state)
{
	agk::DeleteNetworkMessage(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SendNetworkMessage(lua_State *state)
{
	agk::SendNetworkMessage(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::GetNetworkMessage(lua_State *state)
{
	lua_pushinteger(state, agk::GetNetworkMessage(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetNetworkClientUserData(lua_State *state)
{
	agk::SetNetworkClientUserData(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::GetNetworkClientUserData(lua_State *state)
{
	lua_pushinteger(state, agk::GetNetworkClientUserData(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3)));
	return 1;
}

int agkLua::CreateHTTPConnection(lua_State *state)
{
	lua_pushinteger(state ,agk::CreateHTTPConnection());
	return 1;
}

int agkLua::DeleteHTTPConnection(lua_State *state)
{
	agk::DeleteHTTPConnection(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetInternetState(lua_State *state)
{
	lua_pushinteger(state, agk::GetInternetState());
	return 1;
}

int agkLua::SetHTTPHost(lua_State *state)
{
	if (lua_gettop(state) == 5)
	{
		lua_pushinteger(state, agk::SetHTTPHost(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tointeger(state, 3), lua_tostring(state, 4), lua_tostring(state, 5)));
	}
	else
	{
		lua_pushinteger(state, agk::SetHTTPHost(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tointeger(state, 3)));
	}
	
	return 1;
}

int agkLua::CloseHTTPConnection(lua_State *state)
{
	agk::CloseHTTPConnection(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetHTTPTimeout(lua_State *state)
{
	agk::SetHTTPTimeout(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SendHTTPRequest(lua_State *state)
{
	char *s = 0;
	if (lua_gettop(state) == 3)
	{
		s = agk::SendHTTPRequest(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tostring(state, 3));
	}
	else
	{
		s = agk::SendHTTPRequest(lua_tointeger(state, 1), lua_tostring(state, 2));
	}
	lua_pushstring(state, s);
	delete[] s;
	return 1;
}

int agkLua::SendHTTPRequestASync(lua_State *state)
{
	if (lua_gettop(state) == 3)
	{
		lua_pushinteger(state, agk::SendHTTPRequestASync(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tostring(state, 3)));
	}
	else
	{
		lua_pushinteger(state, agk::SendHTTPRequestASync(lua_tointeger(state, 1), lua_tostring(state, 2)));
	}
	return 1;
}

int agkLua::SendHTTPFile(lua_State *state)
{
	lua_pushinteger(state, agk::SendHTTPFile(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tostring(state, 3), lua_tostring(state, 4)));
	return 1;
}

int agkLua::GetHTTPResponse(lua_State *state)
{
	char *s = agk::GetHTTPResponse(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetHTTPResponseReady(lua_State *state)
{
	lua_pushinteger(state, agk::GetHTTPResponseReady(lua_tointeger(state, 1)));
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetHTTPResponseC(lua_State *state)
{
	return 0;
}

int agkLua::GetHTTPFile(lua_State *state)
{
	if (lua_gettop(state) == 4)
	{
		lua_pushinteger(state, agk::GetHTTPFile(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tostring(state, 3), lua_tostring(state, 4)));
	}
	else
	{
		lua_pushinteger(state, agk::GetHTTPFile(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tostring(state, 3)));
	}
	return 1;
}

int agkLua::GetHTTPFileComplete(lua_State *state)
{
	lua_pushinteger(state, agk::GetHTTPFileComplete(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetHTTPFileProgress(lua_State *state)
{
	lua_pushnumber(state, agk::GetHTTPFileProgress(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::OpenBrowser(lua_State *state)
{
	agk::OpenBrowser(lua_tostring(state, 1));
	return 0;
}

int agkLua::Str(lua_State *state)
{
	char *s = agk::Str((float)lua_tonumber(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::Bin(lua_State *state)
{
	char *s = agk::Bin(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::Hex(lua_State *state)
{
	char *s = agk::Hex(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::Val(lua_State *state)
{
	lua_pushinteger(state, agk::Val(lua_tostring(state, 1)));
	return 1;
}

int agkLua::ValFloat(lua_State *state)
{
	lua_pushnumber(state, agk::ValFloat(lua_tostring(state, 1)));
	return 1;
}

int agkLua::Left(lua_State *state)
{
	char *s = agk::Left(lua_tostring(state, 1), lua_tointeger(state, 2));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::Right(lua_State *state)
{
	char *s = agk::Right(lua_tostring(state, 1), lua_tointeger(state, 2));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::Mid(lua_State *state)
{
	char *s = agk::Mid(lua_tostring(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::Asc(lua_State *state)
{
	lua_pushinteger(state, agk::Asc(lua_tostring(state, 1)));
	return 1;
}

int agkLua::Len(lua_State *state)
{
	lua_pushinteger(state, agk::Len(lua_tostring(state, 1)));
	return 1;
}

int agkLua::Chr(lua_State *state)
{
	char *s = agk::Chr(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::Lower(lua_State *state)
{
	char *s = agk::Lower(lua_tostring(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::Upper(lua_State *state)
{
	char *s = agk::Upper(lua_tostring(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::Spaces(lua_State *state)
{
	char *s = agk::Spaces(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::CountStringTokens(lua_State *state)
{
	lua_pushinteger(state, agk::CountStringTokens(lua_tostring(state, 1), lua_tostring(state, 2)));
	return 1;
}

int agkLua::GetStringToken(lua_State *state)
{
	char *s = agk::GetStringToken(lua_tostring(state, 1), lua_tostring(state, 2), lua_tointeger(state, 3));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetManagedSpriteCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetManagedSpriteCount());
	return 1;
}

int agkLua::GetManagedSpriteSortedCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetManagedSpriteSortedCount());
	return 1;
}

int agkLua::GetManagedSpriteDrawnCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetManagedSpriteDrawnCount());
	return 1;
}

int agkLua::GetPixelsDrawn(lua_State *state)
{
	lua_pushinteger(state, agk::GetPixelsDrawn());
	return 1;
}

int agkLua::GetManagedSpriteDrawCalls(lua_State *state)
{
	lua_pushinteger(state, agk::GetManagedSpriteDrawCalls());
	return 1;
}

int agkLua::GetParticleDrawnPointCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetParticleDrawnPointCount());
	return 1;
}

int agkLua::GetParticleDrawnQuadCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetParticleDrawnQuadCount());
	return 1;
}

int agkLua::GetUpdateTime(lua_State *state)
{
	lua_pushnumber(state, agk::GetUpdateTime());
	return 1;
}

int agkLua::GetPhysicsTime(lua_State *state)
{
	lua_pushnumber(state, agk::GetPhysicsTime());
	return 1;
}

int agkLua::GetDrawingSetupTime(lua_State *state)
{
	lua_pushnumber(state, agk::GetDrawingSetupTime());
	return 1;
}

int agkLua::GetDrawingTime(lua_State *state)
{
	lua_pushnumber(state, agk::GetDrawingTime());
	return 1;
}

int agkLua::GetLoadedImages(lua_State *state)
{
	lua_pushinteger(state, agk::GetLoadedImages());
	return 1;
}

int agkLua::GetUnassignedImages(lua_State *state)
{
	lua_pushinteger(state, agk::GetUnassignedImages());
	return 1;
}

int agkLua::GetUnassignedImageFileName(lua_State *state)
{
	char *s = agk::GetUnassignedImageFileName(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetYearFromUnix64(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetMonthFromUnix64(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetDayFromUnix64(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetHoursFromUnix64(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetMinutesFromUnix64(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetSecondsFromUnix64(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetUnixFromDate64(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetUnixTime64(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetYearFromUnix32(lua_State *state)
{
	return 0;
}

int agkLua::GetYearFromUnix(lua_State *state)
{
	lua_pushinteger(state, agk::GetYearFromUnix(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetMonthFromUnix(lua_State *state)
{
	lua_pushinteger(state, agk::GetMonthFromUnix(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetDaysFromUnix(lua_State *state)
{
	lua_pushinteger(state, agk::GetDaysFromUnix(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetHoursFromUnix(lua_State *state)
{
	lua_pushinteger(state, agk::GetHoursFromUnix(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetMinutesFromUnix(lua_State *state)
{
	lua_pushinteger(state, agk::GetMinutesFromUnix(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetSecondsFromUnix(lua_State *state)
{
	lua_pushinteger(state, agk::GetSecondsFromUnix(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetUnixFromDate(lua_State *state)
{
	lua_pushinteger(state, agk::GetUnixFromDate(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5), lua_tointeger(state, 6)));
	return 1;
}

int agkLua::GetUnixTime(lua_State *state)
{
	lua_pushinteger(state, agk::GetUnixTime());
	return 1;
}

int agkLua::GetLeapYear(lua_State *state)
{
	lua_pushinteger(state, agk::GetLeapYear(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetCurrentDate(lua_State *state)
{
	char *s = agk::GetCurrentDate();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::agkGetCurrentTime(lua_State *state)
{
	char *s = agk::GetCurrentTime();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetDayOfWeek(lua_State *state)
{
	lua_pushinteger(state, agk::GetDayOfWeek());
	return 1;
}

int agkLua::SetInneractiveDetails(lua_State *state)
{
	agk::SetInneractiveDetails(lua_tostring(state, 1));
	return 0;
}

int agkLua::SetAdMobDetails(lua_State *state)
{
	agk::SetAdMobDetails(lua_tostring(state, 1));
	return 0;
}

int agkLua::SetChartboostDetails(lua_State *state)
{
	agk::SetChartboostDetails(lua_tostring(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::CreateFullscreenAdvert(lua_State *state)
{
	agk::CreateFullscreenAdvert();
	return 0;
}

int agkLua::CreateAdvert(lua_State *state)
{
	agk::CreateAdvert(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::CreateAdvertEx(lua_State *state)
{
	agk::CreateAdvertEx(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6));
	return 0;
}

int agkLua::SetAdvertPosition(lua_State *state)
{
	agk::SetAdvertPosition(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetAdvertLocation(lua_State *state)
{
	agk::SetAdvertLocation(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetAdvertLocationEx(lua_State *state)
{
	agk::SetAdvertLocationEx(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetAdvertVisible(lua_State *state)
{
	agk::SetAdvertVisible(lua_tointeger(state, 1));
	return 0;
}

int agkLua::RequestAdvertRefresh(lua_State *state)
{
	agk::RequestAdvertRefresh();
	return 0;
}

int agkLua::DeleteAdvert(lua_State *state)
{
	agk::DeleteAdvert();
	return 0;
}

//NOT RELEVANT FOR LUA
int agkLua::Log(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SocialPluginsSetup(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SocialPluginsDestroy(lua_State *state)
{
	return 0;
}

int agkLua::LoadVideo(lua_State *state)
{
	lua_pushinteger(state, agk::LoadVideo(lua_tostring(state, 1)));
	return 1;
}

int agkLua::DeleteVideo(lua_State *state)
{
	agk::DeleteVideo();
	return 0;
}

int agkLua::SetVideoDimensions(lua_State *state)
{
	agk::SetVideoDimensions(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::PlayVideo(lua_State *state)
{
	agk::PlayVideo();
	return 0;
}

int agkLua::PauseVideo(lua_State *state)
{
	agk::PauseVideo();
	return 0;
}

int agkLua::StopVideo(lua_State *state)
{
	agk::StopVideo();
	return 0;
}

int agkLua::GetVideoPlaying(lua_State *state)
{
	lua_pushinteger(state, agk::GetVideoPlaying());
	return 1;
}

int agkLua::GetVideoPosition(lua_State *state)
{
	lua_pushnumber(state, agk::GetVideoPosition());
	return 1;
}

int agkLua::GetVideoDuration(lua_State *state)
{
	lua_pushnumber(state, agk::GetVideoDuration());
	return 1;
}

int agkLua::SetVideoVolume(lua_State *state)
{
	agk::SetVideoVolume(lua_tonumber(state, 1));
	return 0;
}

int agkLua::GetVideoWidth(lua_State *state)
{
	lua_pushnumber(state, agk::GetVideoWidth());
	return 1;
}

int agkLua::GetVideoHeight(lua_State *state)
{
	lua_pushnumber(state, agk::GetVideoHeight());
	return 1;
}

int agkLua::RateApp(lua_State *state)
{
	switch (lua_gettop(state))
	{
	case 1:
		agk::RateApp(lua_tostring(state, 1));
		break;
	case 2:
		agk::RateApp(lua_tostring(state, 1), lua_tostring(state, 2));
		break;
	case 3:
		agk::RateApp(lua_tostring(state, 1), lua_tostring(state, 2), lua_tostring(state, 3));
		break;
	}

	return 0;
}

int agkLua::InAppPurchaseSetKeys(lua_State *state)
{
	agk::InAppPurchaseSetKeys(lua_tostring(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::InAppPurchaseSetTitle(lua_State *state)
{
	agk::InAppPurchaseSetTitle(lua_tostring(state, 1));
	return 0;
}

int agkLua::InAppPurchaseAddProductID(lua_State *state)
{
	agk::InAppPurchaseAddProductID(lua_tostring(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::InAppPurchaseSetup(lua_State *state)
{
	agk::InAppPurchaseSetup();
	return 0;
}

int agkLua::InAppPurchaseActivate(lua_State *state)
{
	agk::InAppPurchaseActivate(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetInAppPurchaseState(lua_State *state)
{
	lua_pushinteger(state, agk::GetInAppPurchaseState());
	return 1;
}

int agkLua::GetInAppPurchaseAvailable(lua_State *state)
{
	lua_pushinteger(state, agk::GetInAppPurchaseAvailable(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::InAppPurchaseRestore(lua_State *state)
{
	agk::InAppPurchaseRestore();
	return 0;
}

int agkLua::FacebookSetup(lua_State *state)
{
	agk::FacebookSetup(lua_tostring(state, 1));
	return 0;
}

int agkLua::FacebookLogin(lua_State *state)
{
	agk::FacebookLogin();
	return 0;
}

int agkLua::FacebookLogout(lua_State *state)
{
	agk::FacebookLogout();
	return 0;
}

int agkLua::FacebookShowLikeButton(lua_State *state)
{
	agk::FacebookShowLikeButton(lua_tostring(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	return 0;
}

int agkLua::FacebookDestroyLikeButton(lua_State *state)
{
	agk::FacebookDestroyLikeButton();
	return 0;
}

int agkLua::FacebookPostOnMyWall(lua_State *state)
{
	agk::FacebookPostOnMyWall(lua_tostring(state, 1), lua_tostring(state, 2), lua_tostring(state, 3), lua_tostring(state, 4), lua_tostring(state, 5));
	return 0;
}

int agkLua::FacebookPostOnFriendsWall(lua_State *state)
{
	agk::FacebookPostOnFriendsWall(lua_tostring(state, 1), lua_tostring(state, 2), lua_tostring(state, 3), lua_tostring(state, 4), lua_tostring(state, 5), lua_tostring(state, 6));
	return 0;
}

int agkLua::FacebookInviteFriend(lua_State *state)
{
	agk::FacebookInviteFriend(lua_tostring(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::FacebookGetFriends(lua_State *state)
{
	agk::FacebookGetFriends();
	return 0;
}

int agkLua::FacebookGetFriendsState(lua_State *state)
{
	lua_pushinteger(state, agk::FacebookGetFriendsState());
	return 1;
}

int agkLua::FacebookGetFriendsCount(lua_State *state)
{
	lua_pushinteger(state, agk::FacebookGetFriendsCount());
	return 1;
}

int agkLua::FacebookGetFriendsName(lua_State *state)
{
	char *s = agk::FacebookGetFriendsName(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::FacebookGetFriendsID(lua_State *state)
{
	char *s = agk::FacebookGetFriendsID(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::FacebookDownloadFriendsPhoto(lua_State *state)
{
	agk::FacebookDownloadFriendsPhoto(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetFacebookDownloadState(lua_State *state)
{
	lua_pushinteger(state, agk::GetFacebookDownloadState());
	return 1;
}

int agkLua::GetFacebookDownloadFile(lua_State *state)
{
	char *s = agk::GetFacebookDownloadFile();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetFacebookLoggedIn(lua_State *state)
{
	lua_pushinteger(state, agk::GetFacebookLoggedIn());
	return 1;
}

int agkLua::FacebookGetUserID(lua_State *state)
{
	char *s = agk::FacebookGetUserID();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::FacebookGetUserName(lua_State *state)
{
	char *s = agk::FacebookGetUserName();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::TwitterSetup(lua_State *state)
{
	agk::TwitterSetup(lua_tostring(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::TwitterMessage(lua_State *state)
{
	agk::TwitterMessage(lua_tostring(state, 1));
	return 0;
}

int agkLua::NotificationCreate(lua_State *state)
{
	agk::NotificationCreate(lua_tostring(state, 1), lua_tostring(state, 2), lua_tostring(state, 3));
	return 0;
}

int agkLua::NotificationReset(lua_State *state)
{
	agk::NotificationReset();
	return 0;
}

int agkLua::GetNotification(lua_State *state)
{
	lua_pushinteger(state, agk::GetNotification());
	return 1;
}

int agkLua::GetNotificationData(lua_State *state)
{
	char *s = agk::GetNotificationData();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::GetNotificationType(lua_State *state)
{
	lua_pushinteger(state, agk::GetNotificationType());
	return 1;
}

int agkLua::SetNotificationImage(lua_State *state)
{
	agk::SetNotificationImage(lua_tointeger(state, 1));
	return 0;
}

int agkLua::SetNotificationText(lua_State *state)
{
	agk::SetNotificationText(lua_tostring(state, 1));
	return 0;
}

int agkLua::SetPushNotificationKeys(lua_State *state)
{
	agk::SetPushNotificationKeys(lua_tostring(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::PushNotificationSetup(lua_State *state)
{
	lua_pushinteger(state, agk::PushNotificationSetup());
	return 1;
}

int agkLua::GetPushNotificationToken(lua_State *state)
{
	char *s = agk::GetPushNotificationToken();
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::CreateZip(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		agk::CreateZip(lua_tointeger(state, 1), lua_tostring(state, 2));
	}
	else
	{
		lua_pushinteger(state, agk::CreateZip(lua_tostring(state, 1)));
		return 1;
	}

	return 0;
}

int agkLua::AddZipEntry(lua_State *state)
{
	agk::AddZipEntry(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tostring(state, 3));
	return 0;
}

int agkLua::CloseZip(lua_State *state)
{
	agk::CloseZip(lua_tointeger(state, 1));
	return 0;
}

int agkLua::ExtractZip(lua_State *state)
{
	agk::ExtractZip(lua_tostring(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::CreateMemblock(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		agk::CreateMemblock(lua_tointeger(state, 1), lua_tointeger(state, 2));
	}
	else
	{
		lua_pushinteger(state, agk::CreateMemblock(lua_tointeger(state, 1)));
		return 1;
	}
	return 0;
}

int agkLua::GetMemblockExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetMemblockExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::DeleteMemblock(lua_State *state)
{
	agk::DeleteMemblock(lua_tointeger(state, 1));
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetMemblockPtr(lua_State *state)
{
	return 0;
}


int agkLua::CopyMemblock(lua_State *state)
{
	agk::CopyMemblock(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	return 0;
}

int agkLua::GetMemblockSize(lua_State *state)
{
	lua_pushinteger(state, agk::GetMemblockSize(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetMemblockByte(lua_State *state)
{
	lua_pushinteger(state, agk::GetMemblockByte(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetMemblockByteSigned(lua_State *state)
{
	lua_pushinteger(state, agk::GetMemblockByteSigned(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetMemblockShort(lua_State *state)
{
	lua_pushinteger(state, agk::GetMemblockShort(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetMemblockInt(lua_State *state)
{
	lua_pushinteger(state, agk::GetMemblockInt(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetMemblockFloat(lua_State *state)
{
	lua_pushnumber(state, agk::GetMemblockFloat(lua_tointeger(state, 1), lua_tointeger(state, 2)));
	return 1;
}

int agkLua::GetMemblockString(lua_State *state)
{
	char *s = agk::GetMemblockString(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

int agkLua::SetMemblockByte(lua_State *state)
{
	agk::SetMemblockByte(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetMemblockByteSigned(lua_State *state)
{
	agk::SetMemblockByteSigned(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetMemblockShort(lua_State *state)
{
	agk::SetMemblockShort(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetMemblockInt(lua_State *state)
{
	agk::SetMemblockInt(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetMemblockFloat(lua_State *state)
{
	agk::SetMemblockFloat(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetMemblockString(lua_State *state)
{
	agk::SetMemblockString(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tostring(state, 3));
	return 0;
}

int agkLua::CreateMemblockFromImage(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		agk::CreateMemblockFromImage(lua_tointeger(state, 1), lua_tointeger(state, 2));
	}
	else
	{
		lua_pushinteger(state, agk::CreateMemblockFromImage(lua_tointeger(state, 1)));
		return 1;
	}

	return 0;
}

int agkLua::CreateImageFromMemblock(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		agk::CreateImageFromMemblock(lua_tointeger(state, 1), lua_tointeger(state, 2));
	}
	else
	{
		lua_pushinteger(state, agk::CreateImageFromMemblock(lua_tointeger(state, 1)));
		return 1;
	}

	return 0;
}

int agkLua::CreateMemblockFromSound(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		agk::CreateMemblockFromSound(lua_tointeger(state, 1), lua_tointeger(state, 2));
	}
	else
	{
		lua_pushinteger(state, agk::CreateMemblockFromSound(lua_tointeger(state, 1)));
		return 1;
	}

	return 0;
}

int agkLua::CreateSoundFromMemblock(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		agk::CreateSoundFromMemblock(lua_tointeger(state, 1), lua_tointeger(state, 2));
	}
	else
	{
		lua_pushinteger(state, agk::CreateSoundFromMemblock(lua_tointeger(state, 1)));
		return 1;
	}

	return 0;
}

int agkLua::CreateMemblockFromFile(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		agk::CreateMemblockFromFile(lua_tointeger(state, 1), lua_tostring(state, 2));
	}
	else
	{
		lua_pushinteger(state, agk::CreateMemblockFromFile(lua_tostring(state, 1)));
		return 1;
	}

	return 0;
}

int agkLua::CreateFileFromMemblock(lua_State *state)
{
	agk::CreateFileFromMemblock(lua_tostring(state, 1), lua_tointeger(state, 2));
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::InitialiseSensorCommands(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::FreeSensorCommands(lua_State *state)
{
	return 0;
}

int agkLua::GetNFCExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetNFCExists());
	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetRawNFCCount(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawNFCCount());
	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetRawFirstNFCDevice(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawFirstNFCDevice());
	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetRawNextNFCDevice(lua_State *state)
{
	lua_pushinteger(state, agk::GetRawNextNFCDevice());
	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetRawNFCName(lua_State *state)
{
	char *s = agk::GetRawNFCName(lua_tointeger(state, 1));
	lua_pushstring(state, s);
	delete[] s;

	return 1;
}

//NOT AN OFFICIAL COMMAND
int agkLua::SendRawNFCData(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetRawNFCDataState(lua_State *state)
{
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetRawNFCData(lua_State *state)
{
	return 0;
}

int agkLua::GetGameCenterExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetGameCenterExists());
	return 1;
}

int agkLua::GameCenterSetup(lua_State *state)
{
	agk::GameCenterSetup();
	return 0;
}

int agkLua::GameCenterLogin(lua_State *state)
{
	agk::GameCenterLogin();
	return 0;
}

int agkLua::GetGameCenterLoggedIn(lua_State *state)
{
	lua_pushinteger(state, agk::GetGameCenterLoggedIn());
	return 1;
}

int agkLua::GameCenterSubmitScore(lua_State *state)
{
	agk::GameCenterSubmitScore(lua_tointeger(state, 1), lua_tostring(state, 2));
	return 0;
}

int agkLua::GameCenterShowLeaderBoard(lua_State *state)
{
	agk::GameCenterShowLeaderBoard(lua_tostring(state, 1));
	return 0;
}

int agkLua::GameCenterSubmitAchievement(lua_State *state)
{
	agk::GameCenterSubmitAchievement(lua_tostring(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GameCenterAchievementsShow(lua_State *state)
{
	agk::GameCenterAchievementsShow();
	return 0;
}

int agkLua::GameCenterAchievementsReset(lua_State *state)
{
	agk::GameCenterAchievementsReset();
	return 0;
}

int agkLua::MakeColor(lua_State *state)
{
	lua_pushinteger(state, agk::MakeColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3)));
	return 1;
}

int agkLua::GetColorRed(lua_State *state)
{
	lua_pushinteger(state, agk::GetColorRed(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetColorGreen(lua_State *state)
{
	lua_pushinteger(state, agk::GetColorGreen(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetColorBlue(lua_State *state)
{
	lua_pushinteger(state, agk::GetColorBlue(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::DrawLine(lua_State *state)
{
	if (lua_gettop(state) == 7)
	{
		agk::DrawLine(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tointeger(state, 5), lua_tointeger(state, 6), lua_tointeger(state, 7));
	}
	else
	{
		agk::DrawLine(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tointeger(state, 5), lua_tointeger(state, 6));
	}
	return 0;
}

int agkLua::DrawBox(lua_State *state)
{
	agk::DrawBox(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tointeger(state, 5), lua_tointeger(state, 6), lua_tointeger(state, 7), lua_tointeger(state, 8), lua_tointeger(state, 9));
	return 0;
}

int agkLua::DrawEllipse(lua_State *state)
{
	agk::DrawEllipse(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tointeger(state, 5), lua_tointeger(state, 6), lua_tointeger(state, 7));
	return 0;
}

int agkLua::SetGlobal3DDepth(lua_State *state)
{
	agk::SetGlobal3DDepth(lua_tointeger(state, 1));
	return 0;
}

int agkLua::CreateObjectBox(lua_State *state)
{
	if (lua_gettop(state) == 4)
	{
		agk::CreateObjectBox(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	}
	else
	{
		lua_pushinteger(state, agk::CreateObjectBox(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3)));
		return 1;
	}

	return 0;
}

int agkLua::CreateObjectSphere(lua_State *state)
{
	if (lua_gettop(state) == 4)
	{
		agk::CreateObjectSphere(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	}
	else
	{
		lua_pushinteger(state, agk::CreateObjectSphere(lua_tonumber(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3)));
		return 1;
	}
	return 0;
}

int agkLua::CreateObjectCone(lua_State *state)
{
	if (lua_gettop(state) == 4)
	{
		agk::CreateObjectCone(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	}
	else
	{
		lua_pushinteger(state, agk::CreateObjectCone(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tointeger(state, 3)));
		return 1;
	}
	return 0;
}

int agkLua::CreateObjectCylinder(lua_State *state)
{
	if (lua_gettop(state) == 4)
	{
		agk::CreateObjectCylinder(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tointeger(state, 4));
	}
	else
	{
		lua_pushinteger(state, agk::CreateObjectCylinder(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tointeger(state, 3)));
		return 1;
	}
	return 0;
}

int agkLua::CreateObjectPlane(lua_State *state)
{
	if (lua_gettop(state) == 3)
	{
		agk::CreateObjectPlane(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	}
	else
	{
		lua_pushinteger(state, agk::CreateObjectPlane(lua_tonumber(state, 1), lua_tonumber(state, 2)));
		return 1;
	}
	return 0;
}

int agkLua::CreateObjectQuad(lua_State *state)
{
	if (lua_gettop(state) == 1)
	{
		agk::CreateObjectQuad(lua_tointeger(state, 1));
	}
	else
	{
		lua_pushinteger(state, agk::CreateObjectQuad());
		return 1;
	}
	return 0;
}

int agkLua::LoadObject(lua_State *state)
{
	switch (lua_gettop(state))
	{
	case 1:
		lua_pushinteger(state, agk::LoadObject(lua_tostring(state, 1)));
		return 1;
		break;
	case 2:
		if (lua_type(state, 1) == LUA_TSTRING)
		{
			lua_pushinteger(state, agk::LoadObject(lua_tostring(state, 1), lua_tointeger(state, 2)));
			return 1;
		}
		else
		{
			agk::LoadObject(lua_tointeger(state, 1), lua_tostring(state, 2));
		}
		break;
	case 3:
		agk::LoadObject(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tointeger(state, 3));
		break;

	}

	return 0;
}

int agkLua::CloneObject(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		agk::CloneObject(lua_tointeger(state, 1), lua_tointeger(state, 2));
	}
	else
	{
		lua_pushinteger(state, agk::CloneObject(lua_tointeger(state, 1)));
		return 1;
	}
	return 0;
}

int agkLua::InstanceObject(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		agk::InstanceObject(lua_tointeger(state, 1), lua_tointeger(state, 2));
	}
	else
	{
		lua_pushinteger(state, agk::InstanceObject(lua_tointeger(state, 1)));
		return 1;
	}
	return 0;
}

int agkLua::GetObjectExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetObjectExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::DeleteObject(lua_State *state)
{
	agk::DeleteObject(lua_tointeger(state, 1));
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::GetObjectPtr(lua_State *state)
{
	return 0;
}

int agkLua::DeleteAllObjects(lua_State *state)
{
	agk::DeleteAllObjects();
	return 0;
}

int agkLua::SetObjectPosition(lua_State *state)
{
	agk::SetObjectPosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::SetObjectRotation(lua_State *state)
{
	agk::SetObjectRotation(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::SetObjectRotationQuat(lua_State *state)
{
	agk::SetObjectRotationQuat(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetObjectScale(lua_State *state)
{
	agk::SetObjectScale(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::MoveObjectLocalX(lua_State *state)
{
	agk::MoveObjectLocalX(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::MoveObjectLocalY(lua_State *state)
{
	agk::MoveObjectLocalY(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::MoveObjectLocalZ(lua_State *state)
{
	agk::MoveObjectLocalZ(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateObjectLocalX(lua_State *state)
{
	agk::RotateObjectLocalX(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateObjectLocalY(lua_State *state)
{
	agk::RotateObjectLocalY(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateObjectLocalZ(lua_State *state)
{
	agk::RotateObjectLocalZ(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateObjectGlobalX(lua_State *state)
{
	agk::RotateObjectGlobalX(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateObjectGlobalY(lua_State *state)
{
	agk::RotateObjectGlobalY(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateObjectGlobalZ(lua_State *state)
{
	agk::RotateObjectGlobalZ(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::GetObjectX(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectY(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectAngleX(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectAngleX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectAngleY(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectAngleY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectAngleZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectAngleZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectQuatW(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectQuatW(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectQuatX(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectQuatX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectQuatY(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectQuatY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectQuatZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectQuatZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetObjectLookAt(lua_State *state)
{
	agk::SetObjectLookAt(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetObjectImage(lua_State *state)
{
	agk::SetObjectImage(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3));
	return 0;
}

int agkLua::SetObjectShader(lua_State *state)
{
	agk::SetObjectShader(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetObjectColor(lua_State *state)
{
	agk::SetObjectColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4), lua_tointeger(state, 5));
	return 0;
}

int agkLua::SetObjectLightMode(lua_State *state)
{
	agk::SetObjectLightMode(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetObjectDepthReadMode(lua_State *state)
{
	agk::SetObjectDepthReadMode(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetObjectDepthWrite(lua_State *state)
{
	agk::SetObjectDepthWrite(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetObjectTransparency(lua_State *state)
{
	agk::SetObjectTransparency(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetObjectCullMode(lua_State *state)
{
	agk::SetObjectCullMode(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::SetObjectVisible(lua_State *state)
{
	agk::SetObjectVisible(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

int agkLua::GetObjectDepthReadMode(lua_State *state)
{
	lua_pushinteger(state, agk::GetObjectDepthReadMode(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectDepthWrite(lua_State *state)
{
	lua_pushinteger(state, agk::GetObjectDepthWrite(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectTransparency(lua_State *state)
{
	lua_pushinteger(state, agk::GetObjectTransparency(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectCullMode(lua_State *state)
{
	lua_pushinteger(state, agk::GetObjectCullMode(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectVisible(lua_State *state)
{
	lua_pushinteger(state, agk::GetObjectVisible(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectInScreen(lua_State *state)
{
	lua_pushinteger(state, agk::GetObjectInScreen(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::DrawObject(lua_State *state)
{
	agk::DrawObject(lua_tointeger(state, 1));
	return 0;
}

int agkLua::GetScreenXFrom3D(lua_State *state)
{
	lua_pushnumber(state, agk::GetScreenXFrom3D(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3)));
	return 1;
}

int agkLua::GetScreenYFrom3D(lua_State *state)
{
	lua_pushnumber(state, agk::GetScreenYFrom3D(lua_tonumber(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3)));
	return 1;
}

int agkLua::Get3DVectorXFromScreen(lua_State *state)
{
	lua_pushnumber(state, agk::Get3DVectorXFromScreen(lua_tonumber(state, 1), lua_tonumber(state, 2)));
	return 1;
}

int agkLua::Get3DVectorYFromScreen(lua_State *state)
{
	lua_pushnumber(state, agk::Get3DVectorYFromScreen(lua_tonumber(state, 1), lua_tonumber(state, 2)));
	return 1;
}

int agkLua::Get3DVectorZFromScreen(lua_State *state)
{
	lua_pushnumber(state, agk::Get3DVectorZFromScreen(lua_tonumber(state, 1), lua_tonumber(state, 2)));
	return 1;
}

int agkLua::SetObjectCollisionMode(lua_State *state)
{
	agk::SetObjectCollisionMode(lua_tointeger(state, 1), lua_tointeger(state, 2));
	return 0;
}

//NOT AN OFFICIAL COMMAND
int agkLua::InternalSphereCast(lua_State *state)
{
	return 0;
}

int agkLua::ObjectRayCast(lua_State *state)
{
	lua_pushinteger(state, agk::ObjectRayCast(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tonumber(state, 7)));
	return 1;
}

int agkLua::ObjectSphereCast(lua_State *state)
{
	lua_pushinteger(state, agk::ObjectSphereCast(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tonumber(state, 7), lua_tonumber(state, 8)));
	return 1;
}

int agkLua::ObjectSphereSlide(lua_State *state)
{
	lua_pushinteger(state, agk::ObjectSphereSlide(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6), lua_tonumber(state, 7), lua_tonumber(state, 8)));
	return 1;
}

int agkLua::GetObjectRayCastNumHits(lua_State *state)
{
	lua_pushinteger(state, agk::GetObjectRayCastNumHits());
	return 1;
}

int agkLua::GetObjectRayCastHitID(lua_State *state)
{
	lua_pushinteger(state, agk::GetObjectRayCastHitID(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastX(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastY(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastSlideX(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastSlideX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastSlideY(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastSlideY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastSlideZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastSlideZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastNormalX(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastNormalX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastNormalY(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastNormalY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastNormalZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastNormalZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastBounceX(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastBounceX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastBounceY(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastBounceY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastBounceZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastBounceZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetObjectRayCastDistance(lua_State *state)
{
	lua_pushnumber(state, agk::GetObjectRayCastDistance(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::LoadShader(lua_State *state)
{
	if (lua_gettop(state) == 3)
	{
		agk::LoadShader(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tostring(state, 3));
	}
	else
	{
		lua_pushinteger(state, agk::LoadShader(lua_tostring(state, 1), lua_tostring(state, 2)));
		return 1;
	}
	
	return 0;
}

int agkLua::LoadFullScreenShader(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		agk::LoadFullScreenShader(lua_tointeger(state, 1), lua_tostring(state, 2));
	}
	else
	{
		lua_pushinteger(state, agk::LoadFullScreenShader(lua_tostring(state, 1)));
		return 1;
	}

	return 0;
}

int agkLua::LoadSpriteShader(lua_State *state)
{
	if (lua_gettop(state) == 2)
	{
		agk::LoadSpriteShader(lua_tointeger(state, 1), lua_tostring(state, 2));
	}
	else
	{
		lua_pushinteger(state, agk::LoadSpriteShader(lua_tostring(state, 1)));
		return 1;
	}
	return 0;
}

int agkLua::SetShaderConstantByName(lua_State *state)
{
	agk::SetShaderConstantByName(lua_tointeger(state, 1), lua_tostring(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tonumber(state, 6));
	return 0;
}

int agkLua::SetCameraPosition(lua_State *state)
{
	agk::SetCameraPosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::SetCameraRotationQuat(lua_State *state)
{
	agk::SetCameraRotationQuat(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetCameraRotation(lua_State *state)
{
	agk::SetCameraRotation(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::MoveCameraLocalX(lua_State *state)
{
	agk::MoveCameraLocalX(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::MoveCameraLocalY(lua_State *state)
{
	agk::MoveCameraLocalY(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::MoveCameraLocalZ(lua_State *state)
{
	agk::MoveCameraLocalZ(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateCameraLocalX(lua_State *state)
{
	agk::RotateCameraLocalX(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateCameraLocalY(lua_State *state)
{
	agk::RotateCameraLocalY(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateCameraLocalZ(lua_State *state)
{
	agk::RotateCameraLocalZ(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateCameraGlobalX(lua_State *state)
{
	agk::RotateCameraGlobalX(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateCameraGlobalY(lua_State *state)
{
	agk::RotateCameraGlobalY(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::RotateCameraGlobalZ(lua_State *state)
{
	agk::RotateCameraGlobalZ(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::GetCameraX(lua_State *state)
{
	lua_pushnumber(state, agk::GetCameraX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetCameraY(lua_State *state)
{
	lua_pushnumber(state, agk::GetCameraY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetCameraZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetCameraZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetCameraAngleX(lua_State *state)
{
	lua_pushnumber(state, agk::GetCameraAngleX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetCameraAngleY(lua_State *state)
{
	lua_pushnumber(state, agk::GetCameraAngleY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetCameraAngleZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetCameraAngleZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetCameraQuatW(lua_State *state)
{
	lua_pushnumber(state, agk::GetCameraQuatW(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetCameraQuatX(lua_State *state)
{
	lua_pushnumber(state, agk::GetCameraQuatX(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetCameraQuatY(lua_State *state)
{
	lua_pushnumber(state, agk::GetCameraQuatY(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::GetCameraQuatZ(lua_State *state)
{
	lua_pushnumber(state, agk::GetCameraQuatZ(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::SetCameraLookAt(lua_State *state)
{
	agk::SetCameraLookAt(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5));
	return 0;
}

int agkLua::SetCameraRange(lua_State *state)
{
	agk::SetCameraRange(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3));
	return 0;
}

int agkLua::SetCameraFOV(lua_State *state)
{
	agk::SetCameraFOV(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::SetCameraAspect(lua_State *state)
{
	agk::SetCameraAspect(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::CreateLightPoint(lua_State *state)
{
	agk::CreateLightPoint(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tonumber(state, 5), lua_tointeger(state, 6), lua_tointeger(state, 7), lua_tointeger(state, 8));
	return 0;
}

int agkLua::GetLightPointExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetLightPointExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::DeleteLightPoint(lua_State *state)
{
	agk::DeleteLightPoint(lua_tointeger(state, 1));
	return 0;
}

int agkLua::ClearLightPoints(lua_State *state)
{
	agk::ClearLightPoints();
	return 0;
}

int agkLua::SetLightPointPosition(lua_State *state)
{
	agk::SetLightPointPosition(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::SetLightPointColor(lua_State *state)
{
	agk::SetLightPointColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	return 0;
}

int agkLua::SetLightPointRadius(lua_State *state)
{
	agk::SetLightPointRadius(lua_tointeger(state, 1), lua_tonumber(state, 2));
	return 0;
}

int agkLua::CreateLightDirectional(lua_State *state)
{
	agk::CreateLightDirectional(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4), lua_tointeger(state, 5), lua_tointeger(state, 6), lua_tointeger(state, 7));
	return 0;
}

int agkLua::GetLightDirectionalExists(lua_State *state)
{
	lua_pushinteger(state, agk::GetLightDirectionalExists(lua_tointeger(state, 1)));
	return 1;
}

int agkLua::DeleteLightDirectional(lua_State *state)
{
	agk::DeleteLightDirectional(lua_tointeger(state, 1));
	return 0;
}

int agkLua::ClearLightDirectionals(lua_State *state)
{
	agk::ClearLightDirectionals();
	return 0;
}

int agkLua::SetLightDirectionalDirection(lua_State *state)
{
	agk::SetLightDirectionalDirection(lua_tointeger(state, 1), lua_tonumber(state, 2), lua_tonumber(state, 3), lua_tonumber(state, 4));
	return 0;
}

int agkLua::SetLightDirectionalColor(lua_State *state)
{
	agk::SetLightDirectionalColor(lua_tointeger(state, 1), lua_tointeger(state, 2), lua_tointeger(state, 3), lua_tointeger(state, 4));
	return 0;
}




