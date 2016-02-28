# AGK---Lua V0.1
A Lua interface for the AGK C++ library by The Game Creators which can be found here: http://www.appgamekit.com/

At the moment AGK - Lua is based on AGK version 2.0.14b

Setup
=============

Currently AGK-Lua has only been tested on Windows; however it should be able to run on every platform that AGK supports.

Simply download/pull the files and place them into your AGK Native folder. 

Open the Template.sln and compile the project (using Visual Studio 2013, but it should work fine with Visual Studio 2015)

Upon a successful compilation a "Template.exe" will appear in the "Final" folder. This .exe can now be used to create games using Lua.


Testing the examples
=====================
To try the examples simply copy the "Template.exe" into the example's folder (along side the main.lua script). Run the "Template.exe" and the game will begin to run.


Creating your own game
=======================
To make your own game using AGK-Lua simply make a new folder and place the "Template.exe" in it.

Create a "main.lua" script and add the following lua functions to it:

```
function Setup()

end

function Update()

end
```

The Setup() function will be called when the application starts and the Update() is your main loop. From there you can call almost all of the AGK functions which can be found here: www.appgamekit.com/documentation/

The only unsupport AGK functions are the math functions simply because Lua has the same functions built in. It is also suggested that you use Lua's string.format() rather than AGK's Str() function.


At the moment there is little to no error handling for improper calls to AGK functions, so when calling an AGK function make sure you are providing it with the correct arguments.