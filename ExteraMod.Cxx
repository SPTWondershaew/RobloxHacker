local OrionLib = loadstring(game:HttpGet(('https://raw.githubusercontent.com/ionlyusegithubformcmods/1-Line-Scripts/main/Mobile%20Friendly%20Orion')))()

local Window = OrionLib:MakeWindow({Name = "ExteraMod", HidePremium = false, SaveConfig = true, ConfigFolder = "2025.2"})

local MainTab = Window:MakeTab({
 Name = "Main",
 Icon = "rbxassetid://4483345998",
 PremiumOnly = false
})

local Section = MainTab:AddSection({
 Name = "Функции"
})

MainTab:AddDropdown({
 Name = "Киллаура",
 Default = "",
 Options = {"Убивать всех"}, -- Оставлены все опции, но логика только для "Kill all"
 Callback = function(Value)
  if Value == "Kill all" then
  local range = 1000
local player = game:GetService("Players").LocalPlayer
game:GetService("RunService").RenderStepped:Connect(function()
    local p = game.Players:GetPlayers()
    for i = 2, #p do local v = p[i].Character
local tool = player.Character and player.Character:FindFirstChildOfClass("Tool")
            if tool and tool:FindFirstChild("Handle") then
                tool:Activate()
                for i,v in next, v:GetChildren() do
                    if v:IsA("BasePart") then
                        firetouchinterest(tool.Handle,v,0)
                        firetouchinterest(tool.Handle,v,1)
                    end
                end
            end
        end
end)

wait()

OrionLib:MakeNotification({
 Name = "ExteraMod",
 Content = "Киллаура активирована",
 Image = "rbxassetid://1633620069",
 Time = 10
})
  end
  -- Логика для "Multi kill all", "Anti kill friends", "Multi anti kill friends" удалена
 end    
})


MiscTab:AddButton({
 Name = "Подсветка игроков",
 Callback = function()
        loadstring(game:HttpGet('https://raw.githubusercontent.com/fatesc/fates-esp/main/main.lua'))()
   end    
})

-- Все остальные вкладки и функционал удалены

