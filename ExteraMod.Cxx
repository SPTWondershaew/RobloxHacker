local OrionLib = loadstring(game:HttpGet(('https://raw.githubusercontent.com/ionlyusegithubformcmods/1-Line-Scripts/main/Mobile%20Friendly%20Orion')))()

local Window = OrionLib:MakeWindow({Name = "ExteraMod", HidePremium = false, SaveConfig = true, ConfigFolder = "2025.2"})

local MainTab = Window:MakeTab({
 Name = "Меню",
 Icon = "rbxassetid://4483345998",
 PremiumOnly = false
})

local Section = MainTab:AddSection({
 Name = "Функции"
})

-- Переменные для управления Киллаурой
local killAuraActive = false
local killAuraConnection = nil

MainTab:AddDropdown({
 Name = "Киллаура",
 Default = "",
 Options = {"Убивать всех"},
 Callback = function(Value)
  if Value == "Убивать всех" then
      if not killAuraActive then -- Активируем, если сейчас не активна
          killAuraActive = true
          OrionLib:MakeNotification({
             Name = "ExteraMod",
             Content = "Киллаура активирована",
             Image = "rbxassetid://1633620069",
             Time = 10
          })

          killAuraConnection = game:GetService("RunService").RenderStepped:Connect(function()
              local player = game:GetService("Players").LocalPlayer
              local playersList = game.Players:GetPlayers()
              for i = 2, #playersList do
                  local targetCharacter = playersList[i].Character
                  if targetCharacter then
                      local tool = player.Character and player.Character:FindFirstChildOfClass("Tool")
                      if tool and tool:FindFirstChild("Handle") then
                          tool:Activate()
                          for _, part in next, targetCharacter:GetChildren() do
                              if part:IsA("BasePart") then
                                  firetouchinterest(tool.Handle, part, 0)
                                  firetouchinterest(tool.Handle, part, 1)
                              end
                          end
                      end
                  end
              end
          end)
      else -- Если уже активна и выбрана снова, деактивируем (поведение переключателя)
          killAuraActive = false
          if killAuraConnection then
              killAuraConnection:Disconnect()
              killAuraConnection = nil
          end
          OrionLib:MakeNotification({
             Name = "ExteraMod",
             Content = "Киллаура деактивирована",
             Image = "rbxassetid://1633620069",
             Time = 5
          })
      end
  end
 end    
})


MainTab:AddButton({
 Name = "Подсветка игроков",
 Callback = function()
        loadstring(game:HttpGet('https://raw.githubusercontent.com/fatesc/fates-esp/main/main.lua'))()
        OrionLib:MakeNotification({
            Name = "ExteraMod",
            Content = "Подсветка игроков активирована",
            Image = "rbxassetid://1633620069",
            Time = 5
        })
   end    
})






