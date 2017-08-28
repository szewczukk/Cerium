
-- Function running once, at start of game
function init()
	
end

-- Function running non-stop
function update(deltaTime)
	if this.isHovered() then
		cast_to_label(this.getProp("label"))
	else
		cast_to_label(this.getProp("label"))
	end

	if this.isClicked() then
		eventManager.closeWindow()
	end
end