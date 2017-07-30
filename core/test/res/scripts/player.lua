local speed = 10000

-- Function running once, at start of game
function init()

end


-- Function running non-stop
function update(deltaTime)
    if eventManager.isKeyPressed(KEY_RIGHT) then
        move(vec2.new(speed * deltaTime, 0))
    elseif eventManager.isKeyPressed(KEY_LEFT) then
        move(vec2.new(-speed * deltaTime, 0))
    elseif eventManager.isKeyPressed(KEY_UP) then
        move(vec2.new(0, -speed * deltaTime))
    elseif eventManager.isKeyPressed(KEY_DOWN) then
        move(vec2.new(0, speed * deltaTime))
    end
end