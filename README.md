# Cerium
Simple 2D Game Engine written in C++ 14 & modern OpenGL with SDL2 and scripting in lua

## Lua scripting example
Simple moving script supported by Cerium

```lua
local speed = 0.1

-- Function running once, at start of game
function init()
    print("Init function")
end


-- Function running non-stop
function update(deltaTime)
    rotate(0.0004 * deltaTime)
    if isKeyPressed(79) then
        move(speed * deltaTime, 0)

    elseif isKeyPressed(80) then
        move(-speed * deltaTime, 0)

    elseif isKeyPressed(81) then
        move(0, speed * deltaTime)

    elseif isKeyPressed(82) then
        move(0, -speed * deltaTime)
    end
end
```

## Installation
Just clone this repository at your project catalog

    $ git clone https://github.com/bjornus/Cerium

## Configuration of documentation

    $ chmod +x update
    $ ./update

## Building

    $ cmake .
    $ make

## Running
Before running, copy all assets (shaders, textures etc.) to catalogue where the executable of Cerium is.

    $ ./Cerium


## Third parts
* <a href="https://github.com/bjornus/Bromine">Bromine</a>
* <a href="https://www.libsdl.org">SDL</a>
* <a href="https://www.libsdl.org/projects/SDL_image/">SDL_image</a>
* <a href="http://glew.sourceforge.net">GLEW</a>
* <a href="http://glm.g-truc.net/0.9.8/index.html">GLM</a>
* <a href="https://www.lua.org">lua</a>
* <a href="http://rapidxml.sourceforge.net">RapidXML</a>

## Licensing
To see the license of Bromine, open <a href="https://github.com/bjornus/Cerium/blob/master/LICENSE" target="_blank">LICENSE</a> file.
