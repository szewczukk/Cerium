-- Function running once, at start of game
function init()

end

-- Function running non-stop
function update(deltaTime)
	if eventManager.isKeyPressed(KEY_LEFT) then
		this.move(vec2:new(-300000 * deltaTime, 0))
	elseif eventManager.isKeyPressed(KEY_RIGHT) then
		this.move(vec2:new( 300000 * deltaTime, 0))
	end
	if eventManager.isKeyPressed(KEY_UP) and cast_to_rigidbody(this.getProp("rigidbody")):isOnGround() then
		cast_to_rigidbody(this.getProp("rigidbody")):applyForce(vec2:new(0, -300000))
	end
end