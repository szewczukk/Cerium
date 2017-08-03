
<p align="center">
    <img src="/logo.png">
</p>

Amateur 2D Game Engine written in C++ 14 & modern OpenGL with SDL2 and scripting in lua

## Lua scripting example
Simple moving script supported by Cerium

```lua
local speed = 100

-- Function running once, at start of game
function init()

end


-- Function running non-stop
function update(deltaTime)
    if inputManager.isKeyPressed(KEY_RIGHT) then
        move(vec2.new(speed * deltaTime, 0))
    elseif inputManager.isKeyPressed(KEY_LEFT) then
        move(vec2.new(-speed * deltaTime, 0))
    elseif inputManager.isKeyPressed(KEY_UP) then
        move(vec2.new(0, -speed * deltaTime * 10))
    end
end
```

## Installation
Coming soon!


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
To see the license of Cerium, open <a href="https://github.com/bjornus/Cerium/blob/master/LICENSE" target="_blank">LICENSE</a> file.

## Logo
Logo created by Vunny (Rafał Michałuszek)
