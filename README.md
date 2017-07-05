
<p align="center">
    <img src="/logo.png">
</p>

Simple 2D Game Engine written in C++ 14 & modern OpenGL with SDL2 and scripting in lua

## Lua scripting example
Simple moving script supported by Cerium

```lua
local speed = 100

-- Function running once, at start of game
function init()
    print("Init function")
end


-- Function running non-stop
function update(deltaTime)
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

## Lua Scripting VERY SIMPLE documentation
```lua
    -- Moving person
    move(vec2.new(5, 6))
    
    -- Setting person position
    setPosition(vec2.new(100, 100))
    
    -- Rotating person
    rotate(90)
    
    -- Setting person rotation
    setRotation(180)
    
    -- Moving camera
    camera.move(vec2.new(50, 0))
    
    -- Setting Camera position
    camera.setPosition(vec2.new(100, 100))
    
    -- Checking state of key(ALPHA VERSION!)
    local is_pressed = inputManager.isKeyPressed(79)
    
    -- Checking state of window
    local is_closed = inputManager.isWindowClosed()
    
    -- Checking state of mouse button
    local is_mouse_button_pressed = inputManager.isMouseButtonClicked(1)
    
    -- Closing window
    inputManager.closeWindow()
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
* <a href="https://www.libsdl.org/projects/SDL_ttf/">SDL_ttf</a>
* <a href="http://glew.sourceforge.net">GLEW</a>
* <a href="http://glm.g-truc.net/0.9.8/index.html">GLM</a>
* <a href="https://github.com/ThePhD/sol2">sol2</a>
* <a href="http://rapidxml.sourceforge.net">RapidXML</a>

## Licensing
To see the license of Bromine, open <a href="https://github.com/bjornus/Cerium/blob/master/LICENSE" target="_blank">LICENSE</a> file.
