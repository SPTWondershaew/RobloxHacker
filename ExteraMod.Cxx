local OrionLib = loadstring(game:HttpGet(('https://raw.githubusercontent.com/ionlyusegithubformcmods/1-Line-Scripts/main/Mobile%20Friendly%20Orion')))()

local Window = OrionLib:MakeWindow({Name = "BendyHubX", HidePremium = false, SaveConfig = true, ConfigFolder = "OrionTest"})

local MainTab = Window:MakeTab({
 Name = "Меню",
 Icon = "rbxassetid://4483345998",
 PremiumOnly = false
})

local Section = MainTab:AddSection({
 Name = "Creator Im_DrHacker (tg)"
})

-- Переменные для управления Киллаурой
local killAllActive = false
local killAllConnection = nil

MainTab:AddDropdown({
 Name = "Kill all versions",
 Default = "",
 Options = {"Убивать всех"}, -- Оставлена только опция "Kill all"
 Callback = function(Value)
  if Value == "Убивать всех" then
      if not killAllActive then -- Активируем, если сейчас не активна
          killAllActive = true
          OrionLib:MakeNotification({
             Name = "ExteraMod",
             Content = "Киллаура активирована",
             Image = "rbxassetid://1633620069",
             Time = 10
          })

          killAllConnection = game:GetService("RunService").RenderStepped:Connect(function()
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
          killAllActive = false
          if killAllConnection then
              killAllConnection:Disconnect()
              killAllConnection = nil
          end
          OrionLib:MakeNotification({
             Name = "ExteraMod",
             Content = "Киллаура активирована",
             Image = "rbxassetid://1633620069",
             Time = 5
          })
      end
  end
 end    
})
-- Кнопка "ESP" удалена
MainTab:AddButton({
 Name = "Подсветка игроков",
 Callback = function()
        loadstring(game:HttpGet('https://raw.githubusercontent.com/fatesc/fates-esp/main/main.lua'))()
   end    
})
-- Все остальные вкладки и функционал удалены

