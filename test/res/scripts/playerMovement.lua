velocity = nil
acceleration = nil

-- Function running once, at start of game
function init()
	velocity = vec2:new(0)
	acceleration = vec2:new(0)
end

-- Function running non-stop
function update(deltaTime)
	if eventManager.isKeyPressed(KEY_LEFT) then
		velocity.x = -300000 * deltaTime
	elseif eventManager.isKeyPressed(KEY_RIGHT) then
		velocity.x = 300000 * deltaTime
	else
		velocity.x = 0
	end
	
	if eventManager.isKeyPressed(KEY_UP) and cast_to_rigidbody(this.getProp("rigidbody")):isOnGround() then
		acceleration.y = -300000
	else
		acceleration.y = 0
	end
	
	this.move(velocity)
	cast_to_rigidbody(this.getProp("rigidbody")):applyForce(acceleration)
end