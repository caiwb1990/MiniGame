local Enemy = class("Enemy",function ()
    local sprite =  display.newSprite("#enemy1-1-1.png")
    return sprite
end)

function Enemy:ctor()

end

return Enemy