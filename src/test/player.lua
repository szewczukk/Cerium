-- Function running once, at start of game
function init()
    io.write("Init function\n")
end


-- Function running non-stop
function update(deltaTime)
    if isKeyPressed(0) then
        io.write("Key pressed \n")
    end
    move(1, 0.0)
end