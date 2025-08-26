if game.PlaceId ~= 537413528 then
    return
end

-- Rayfield loading (minimal)
local Rayfield
local success

success, Rayfield = pcall(function()
    return loadstring(game:HttpGet('https://sirius.menu/rayfield'))()
end)

if not success then
    warn("Failed to load Rayfield from sirius.menu. Script may not function.")
    return
end

-- Core Roblox services and player info
local Players = game:GetService("Players")
local Workspace = game:GetService("Workspace")
local VirtualUser = game:GetService("VirtualUser")
local RunService = game:GetService("RunService")

local player = game.Players.LocalPlayer
local Nplayer = game.Players.LocalPlayer.Name

-- Main Rayfield window setup
local Window = Rayfield:CreateWindow({
    Name = "🐱 Котик бизнесмен 🌟", -- Как на примере
    LoadingTitle = "Кот бизнесмен 🌟",
    LoadingSubtitle = "Привет! Меня зовут котик бизнесмен! 🐱",
    Theme = "DarkBlue",
    DisableRayfieldPrompts = true,
    DisableBuildWarnings = true,
    ConfigurationSaving = {
       Enabled = false,
       FolderName = nil,
       FileName = "CHH Minimal"
    },
    Discord = {
       Enabled = false, -- Отключено, так как функционал вебхуков удален
       Invite = "",
       RememberJoins = false
    },
    KeySystem = false,
    KeySettings = {
       Title = "CHHHHH",
       Subtitle = "Минимальный скрипт",
       Note = "Ключ не требуется для этой версии.",
       FileName = "CHHMinimalKey",
       SaveKey = true,
       GrabKeyFromSite = false,
       Key = {"minimal"}
    }
})

-- Создаем только вкладку Global
local Global = Window:CreateTab("Бизнес (авто фарм)", 125428076789049)

-- === Анти-АФК логика ===
local connection

local function enableAntiAFK()
    if not connection then
        Rayfield:Notify({
            Title = "Анти афк | ВКЛ",
            Content = "Я буду следить чтобы не активности не было! 🐱",
            Duration = 6.5,
            Image = 124144713366592,
         })
        connection = player.Idled:Connect(function()
            if getgenv().afk6464 then
                VirtualUser:CaptureController()
                VirtualUser:ClickButton2(Vector2.new())
            end
        end)
    end
end

local function disableAntiAFK()
    if connection then
        connection:Disconnect()
        connection = nil
        Rayfield:Notify({
            Title = "Анти афк | ВЫКЛ",
            Content = "Ниит! Очень жаль 😿",
            Duration = 6.5,
            Image = 124144713366592,
         })
    end
end

local function antiAFKLoop()
    while true do
        if getgenv().afk6464 then
            enableAntiAFK()
        else
            disableAntiAFK()
        end
        task.wait(1)
    end
end

task.spawn(antiAFKLoop)

-- === Элементы GUI на вкладке Global ===

-- Авто фарм
local AutoFarmToggle = Global:CreateToggle({
    Name = "Включить",
    CurrentValue = false,
    Flag = "AutoFarmToggle",
    Callback = function(Value)
        getgenv().AF = Value
        
        local function startAutoFarm()
            if Value == false then return end

            local character = player.Character or player.CharacterAdded:Wait()
            local humanoidRootPart = character:WaitForChild("HumanoidRootPart")

            local newPart = Instance.new("Part")
            newPart.Size = Vector3.new(5, 1, 5)
            newPart.Transparency = 1
            newPart.CanCollide = true
            newPart.Anchored = true
            newPart.Parent = workspace

            local decal = Instance.new("Decal")
            decal.Texture = "rbxassetid://139953968294114"
            decal.Face = Enum.NormalId.Top 
            decal.Parent = newPart local function TPAF(iteration)
                if Value == false then return end
                if iteration == 5 then
                    firetouchinterest(game.Players.LocalPlayer.Character:WaitForChild("HumanoidRootPart"), workspace.BoatStages.NormalStages.TheEnd.GoldenChest.Trigger, 0)
                    task.delay(0.8, function()
                        workspace.ClaimRiverResultsGold:FireServer()
                    end)

                    humanoidRootPart.CFrame = CFrame.new(-51, 65, 984 + (iteration - 1) * 770)
                else
                    if iteration == 1 then
                        humanoidRootPart.CFrame = CFrame.new(160.16104125976562, 29.595888137817383, 973.813720703125)
                    else
                    humanoidRootPart.CFrame = CFrame.new(-51, 65, 984 + (iteration - 1) * 770)
                    end
                end
                newPart.Position = humanoidRootPart.Position - Vector3.new(0, 2, 0)

                task.wait(2.0)
                if iteration == 1 then
                    task.wait(2.0)
                end
                if iteration == 4 then
                else
                    workspace.ClaimRiverResultsGold:FireServer()
                end
            end

            for i = 1, 10 do
                if not Value then
                    break
                end
                TPAF(i)
            end

            newPart:Destroy()
        end

        local charAddedConnection
        local function onCharacterRespawned()
            if getgenv().AF == true then
                local character = player.Character or player.CharacterAdded:Wait()
                character:WaitForChild("HumanoidRootPart")
                startAutoFarm()
            end
        end

        if Value then
            Rayfield:Notify({
                Title = "Авто фарм | ВКЛ",
                Content = "Мани мани мани 🤑💴💰",
                Duration = 6.5,
                Image = 124144713366592,
             })
            game.Players.LocalPlayer.Character:BreakJoints()
            task.wait(1)
            charAddedConnection = game.Players.LocalPlayer.CharacterAdded:Connect(onCharacterRespawned)
        else
            Rayfield:Notify({
                Title = "Авто фарм | ВЫКЛ",
                Content = "Надеюсь тебе понравилось! ресетнись либо дождись до конца 🐱",
                Duration = 6.5,
                Image = 124144713366592,
             })
            if charAddedConnection then
                charAddedConnection:Disconnect()
                charAddedConnection = nil
            end
        end
    end,
})

-- Анти афк
local AFKToggle = Global:CreateToggle({
    Name = "Анти афк",
    CurrentValue = false,
    Flag = "AntiAfkToggle",
    Callback = function(Value)
        getgenv().afk6464 = Value
    end,
})

if getgenv().afk6464 == true then
    AFKToggle:Set(true)
end

-- Статистика
local FStats = Global:CreateParagraph({Title = "Статистика", Content = "Время работы: -\nДошёл до конца: -\nЗолота получено: -\n\nЗолота в час: -"})

local clockTime = 0
local running = false
local totalGoldGained = 0
local Ftime = 0 
local totalGoldBlock = 0
local GoldPerHour = 0
local lastGoldValue = game:GetService("Players").LocalPlayer.Data.Gold.Value
local IGBLOCK = game:GetService("Players").LocalPlayer.Data.GoldBlock.Value

local function formatTime(seconds)
    local hours = math.floor(seconds / 3600)
    local minutes = math.floor((seconds % 3600) / 60)
    local sec = seconds % 60
    return hours .. " часов " .. minutes .. " минут " .. sec .. " секунд"
end

local function startClock()
    if running then return end
    running = true

    while running do
        if getgenv().AF then
            clockTime = clockTime + 1
        else
            running = false
        end
        task.wait(1) 
    end
end

game:GetService("RunService").Stepped:Connect(function()
    if getgenv().AF and not running then
        task.wait(5)
        startClock()
    end
end)

local function initClockUpdate()
while true do
    local FinalGold = game:GetService("Players").LocalPlayer.Data.Gold.Value
    Ftime = formatTime(clockTime)
    local GoldGained = FinalGold - lastGoldValue
    totalGoldGained = totalGoldGained + GoldGained
    local FGBLOCK = game:GetService("Players").LocalPlayer.Data.GoldBlock.Value
    totalGoldBlock = FGBLOCK - IGBLOCK

    GoldPerHour = (clockTime > 0) and (totalGoldGained / clockTime) * 3600 or 0

FStats:Set({
        Title = "Статистика",
        Content = "Время работы: " .. Ftime .. "\n" ..
                  "Дошёл до конца: " .. totalGoldBlock .. " раз\n" ..
                  "Золота получено: " .. totalGoldGained .. "\n" ..
                  "Золота в час: " .. math.floor(GoldPerHour) .. "\n" ..
                  "Золота в секунду: 6.2" .. "\n" ..
                  " " .. "\n" ..
                  "--- Информация ---\n" ..
                  "Телеграм создателей:\n" ..
                  " " .. "\n" ..
                  "👾 Разработчик: t.me/Im_DrHacker 👾\n" ..
                  "🙄 Помощница: t.me/Im_DrHackersha 🙄" .. "\n" ..
                  " " .. "\n" ..
                  "Дата создания: 26.08.2025 все права зафырканы 🦔", 
    })


    lastGoldValue = FinalGold

    task.wait(1)
end
end

GoldPerHour = 0

task.spawn(initClockUpdate)

