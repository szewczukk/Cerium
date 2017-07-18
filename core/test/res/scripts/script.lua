-- Function running once, at start of game
function init()
    resourceManager.get("music"):use()
end


-- Function running non-stop
function update(deltaTime)
    if inputManager.isKeyPressed(KEY_ESCAPE) then
        inputManager.closeWindow()
    end
end