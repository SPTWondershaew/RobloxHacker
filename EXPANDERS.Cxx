-- This is the old source
-- new source: loadstring(game:HttpGet('https://raw.githubusercontent.com/TheRealAsu/BABFT/refs/heads/main/Jan25_Source.lua'))()

if game.PlaceId ~= 537413528 then
    return
end

task.spawn(function()
loadstring(game:HttpGet('https://raw.githubusercontent.com/TheRealAsu/BABFT/refs/heads/main/MessageIssue.lua'))()
end)

if not isfolder("BABFT") then
    makefolder("BABFT")
end

if not isfolder("BABFT/Image") then
    makefolder("BABFT/Image")
end

if not isfolder("BABFT/Build") then
    makefolder("BABFT/Build")
end

local FcMaster = true
local folderName = "ImagePreview"
local previewFolder = Workspace:FindFirstChild(folderName) or Instance.new("Folder", Workspace)
previewFolder.Name = folderName

for _, v in ipairs(previewFolder:GetChildren()) do
    v:Destroy()
end

task.delay(10, function()
    if game:GetService("CoreGui"):FindFirstChild("MSGISSUE") then
        game:GetService("CoreGui").MSGISSUE:Destroy()
    end
end)

local Rayfield
local success

success, Rayfield = pcall(function()
    return loadstring(game:HttpGet('https://sirius.menu/rayfield'))()
end)

if not success then
    success, Rayfield = pcall(function()
        return loadstring(game:HttpGet('https://raw.githubusercontent.com/SiriusSoftwareLtd/Rayfield/ab965bf9a6f9890e6447c9b377678f5bffd8a379/source.lua'))()
    end)
end

if not success then
    success, Rayfield = pcall(function()
        return loadstring(game:HttpGet('https://github.com/SiriusSoftwareLtd/Rayfield/blob/28c7c270669c16a2ae1526eaaac1dbf927aa881e/source.lua'))()
    end)
end

local HttpService = cloneref(game:GetService("HttpService"))
local TeleportService = cloneref(game:GetService("TeleportService"))
local Players = game:GetService("Players")
local Workspace = game:GetService("Workspace")
local VirtualUser = game:GetService("VirtualUser")
local httprequest = (syn and syn.request) or (http and http.request) or http_request or (fluxus and fluxus.request) or request
local JobId = game.JobId
local PlaceId = game.PlaceId
local queueteleport = (syn and syn.queue_on_teleport) or queue_on_teleport or (fluxus and fluxus.queue_on_teleport)
local RunService = game:GetService("RunService")

local Window = Rayfield:CreateWindow({
    Name = "Build A Boat For Treasure",
    Icon = 85108798400826,
    LoadingTitle = "Build A Boat For Treasure",
    LoadingSubtitle = "Made With ❤️ by @thereal_asu",
    Theme = "DarkBlue",
 
    DisableRayfieldPrompts = true,
    DisableBuildWarnings = true,
 
    ConfigurationSaving = {
       Enabled = false,
       FolderName = nil,
       FileName = "Big Hub"
    },
 
    Discord = {
       Enabled = true,
       Invite = "MdtGaG7vdx",
       RememberJoins = true
    },
 
    KeySystem = false,
    KeySettings = {
       Title = "discord.gg/uGhnBu89SM",
       Subtitle = "Key System",
       Note = "Key available in discord, link copied to clipboard",
       FileName = "ASUBABFTKey",
       SaveKey = true,
       GrabKeyFromSite = false,
       Key = {"terraria"} -- yes there is a keysystem but my script is not obfuscated lol
    }
})

local connection

local function enableAntiAFK()
    if not connection then
        Rayfield:Notify({
            Title = "Анти афк | ВКЛ",
            Content = "Вы не будете отключены через 20 минут бездействия",
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
            Content = "Вы будете отключены через 20 минут бездействия",
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

local AutoFarmToggle = Window:CreateToggle({
    Name = "Авто фарм",
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
            decal.Parent = newPart

            local function TPAF(iteration)
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

                task.wait(2.3)
                if iteration == 1 then
                    task.wait(2.3)
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
                Content = "Анти-афк рекомендуется",
                Duration = 6.5,
                Image = 124144713366592,
             })
            game.Players.LocalPlayer.Character:BreakJoints()
            task.wait(1)
            charAddedConnection = game.Players.LocalPlayer.CharacterAdded:Connect(onCharacterRespawned)
        else
            Rayfield:Notify({
                Title = "Авто фарм | ВЫКЛ",
                Content = "Пожалуйста, дождитесь завершения текущей итерации...",
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

local AFKToggle = Window:CreateToggle({
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

local FStats = Window:CreateParagraph({Title = "Статистика", Content = "Время: -\nБлоков золота: -\nЗолота получено: -\n\nЗолота в час: -"})

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
})

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
            Content = "Время: " .. Ftime .. "\n" ..
                      "Блоков золота: " .. totalGoldBlock .."\n" ..
                      "Золота получено: " .. totalGoldGained .. "\n" ..
                      "Золота в час: " .. math.floor(GoldPerHour),
        })

        lastGoldValue = FinalGold

        task.wait(1)
    end
end

GoldPerHour = 0

Init()
