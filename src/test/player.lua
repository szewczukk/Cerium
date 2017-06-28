local speed = 0.000000001

local velocity

-- Function running once, at start of game
function init()
    velocity = vec2.new(0)
end


-- Function running non-stop
function update(deltaTime)
    rotate((speed * deltaTime)/100)
    if isKeyPressed(79) then
        if velocity.x == 0 then
            velocity.x = velocity.x + speed * deltaTime
        end

    elseif isKeyPressed(80) then
        if velocity.x == 0 then
            velocity.x = velocity.x - speed * deltaTime
        end
    else
        velocity.x = 0
    end

    if isKeyPressed(81) then
        if velocity.y == 0 then
            velocity.y = velocity.y + speed * deltaTime
        end
    elseif isKeyPressed(82) then
        if velocity.y == 0 then
            velocity.y = velocity.y - speed * deltaTime
        end
    else
        velocity.y = 0
    end

    move(velocity)
end