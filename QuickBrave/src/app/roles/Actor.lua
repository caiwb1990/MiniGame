local Actor = class("Actor",function ()
    local sprite = 	display.newSprite("#player1-1-1.png")
    return sprite
end)

function Actor:ctor()

end

function Actor:addAnimation()
	local animtionNames = {"walk","attack","dead"}
	local animationFrameNum = {4,4,4}
	
	for i = 1, #animtionNames do
	   local frames = display.newFrames("player1-" .. i .. "-%d.png", 1, animationFrameNum[i])
	   local animation = display.newAnimation(frames ,0.2)
        display.setAnimationCache("player1-" .. animationNames[i], animation)
	end
end

function Actor:walkTo(pos, callback)

    local function moveStop()
        transition.stopTarget(self)
        if callback then
            callback()
        end
    end

    local currentPos = CCPoint(CCNode.getPositionX(self), CCNode.getPositionY(self))
    local destPos = CCPoint(pos.x, pos.y)
    local posDiff = cc.PointDistance(currentPos, destPos)
    local seq = transition.sequence({CCMoveTo:create(5 * posDiff / display.width, CCPoint(pos.x,pos.y)), CCCallFunc:create(moveStop)})
    transition.playAnimationForever(self, display.getAnimationCache("player1-walk"))
    self:runAction(seq)
    return true
end

function Actor:attack()
    transition.playAnimationOnce(self, display.getAnimationCache("player1-attack"))
end

function Actor:dead()
    transition.playAnimationOnce(self, display.getAnimationCache("player1-dead"))
end

return Actor