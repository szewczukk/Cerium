-- Function running once, at start of game
function init()
	print("a")
end


-- Function running non-stop
function update(deltaTime)
	if cast_to_button(this.getProp("btn")):isClicked() then
		eventManager.closeWindow()
	end
end