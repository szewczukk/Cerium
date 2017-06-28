local speed = 0.000000001

-- Function running once, at start of game
function init()

end


-- Function running non-stop
function update(deltaTime)
    rotate((speed * deltaTime)/100)
    if isKeyPressed(79) then
        move(vec2.new(speed * deltaTime, 0))

    elseif isKeyPressed(80) then
        move(vec2.new(-speed * deltaTime, 0))

    elseif isKeyPressed(81) then
        move(vec2.new(0, speed * deltaTime))

    elseif isKeyPressed(82) then
        move(vec2.new(0, -speed * deltaTime))
    end
end