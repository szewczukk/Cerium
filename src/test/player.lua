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
