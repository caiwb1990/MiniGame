local Actor = import("..roles.Actor")
local Enemy = import("..roles.Enemy")

local MainScene = class("MainScene", function()
    return display.newScene("MainScene")
end)



function MainScene:ctor()

    -- background
    local background = display.newSprite("image/background.png",display.cx,display.cy)
        :addTo(self)
    -- self:addChild(background);
 
    -- hero
    local hero = Actor.new() --display.newSprite("#player1-1-1.png")
     --   :setPosition(display.cx, display.cy)
      --  :addTo(self)   
    hero:setPosition(display.left + hero:getContentSize().width/2, display.cy)
    self:addChild(hero)

    -- enemy 
    local enemy = Enemy.new() 
    enemy:setPosition(display.right - enemy:getContentSize().width/2, display.cy)
    self:addChild(enemy)

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
