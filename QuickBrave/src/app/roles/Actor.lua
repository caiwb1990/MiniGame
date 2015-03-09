local Actor = class("Actor",function ()
    local sprite = 	display.newSprite("#player1-1-1.png")
    return sprite
end)

function Actor:ctor()

end

return Actor