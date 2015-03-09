local Actor = import("..roles.Actor")

local MainScene = class("MainScene", function()
    return display.newScene("MainScene")
end)



function MainScene:ctor()

    -- background
    local background = display.newSprite("image/background.png",display.cx,display.cy)
        :addTo(self)
    -- self:addChild(background);
 
    local hero = display.newSprite("#player1-1-1.png")
    --    :setPosition(display.left, display.cy)
    --    :addTo(self)   
    hero:setPosition(display.cx, display.cy)
    self:addChild(hero)



    --cc.ui.UILabel.new({
    --        UILabelType = 2, text = "Hello, World", size = 64})
    --    :align(display.CENTER, display.cx, display.cy)
    --    :addTo(self)
end

function MainScene:onEnter()
end

function MainScene:onExit()
end

return MainScene
