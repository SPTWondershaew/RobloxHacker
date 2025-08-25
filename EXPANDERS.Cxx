
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
    LoadingSubtitle = "Made With ❤️ by ",
    Theme = "DarkBlue",
 
    DisableRayfieldPrompts = true,
    DisableBuildWarnings = true,
 
    ConfigurationSaving = {
       Enabled = false,
       FolderName = nil,
       FileName = "Big Hub"
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

local Global = Window:CreateTab("Global", 125428076789049)





local Button = Global:CreateButton({
    Name = "Load new script",
    Callback = function()
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
    LoadingSubtitle = "by @kill666you_0",
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

local Global = Window:CreateTab("Фарм", 125428076789049)
Section = Information:CreateSection("Auto Farm")
local Paragraph = Information:CreateParagraph({Title = "Information", Content = "let me know if you've ever seen an auto farm more powerful than this one in terms of gold per hour, you can use a webhook to follow the auto farm stats when you're not in front of your screen.\n\n - With no boost: 20K/hour\n - With x1.25: 25K/hour\n - With x2: 40K/hour\n - With Both: 50k/hour"})
Section = Information:CreateSection("Image Loader")
local Paragraph = Information:CreateParagraph({Title = "Requirement", Content = "Paste the image URL in the textbox and let the server convert the image, the server can't access certain images (it's not a coding problem) OR you can convert the image yourself: (more images are supported) Images are created from files that contain special data (RGB), to have these files or to create your own files from an image that you have chosen you must join the discord, you need an external script (open source) that converts the image into a file suitable for this script to be used, a tutorial is in the Discord Server.\n\n - Build Speed: You can choose the speed at which the image is built. If you have a slow internet connection, set the speed to low. Do not set it to max for large images\n\n- Preview: Displays a preview of the image, making it easier to use modifiers or to see how the image will look. It is also required to build the image.\n\n- Change Speed: Stop the current process by opening your inventory and checking if no more blocks are being placed. Change the speed and press 'Load Image' again. It should automatically resume from where it stopped.\n\n- Optimize Mode: Allows even the weakest PCs or those without a good connection to load images."})
local Button = Information:CreateButton({
    Name = "copy the list of working sites",
    Callback = function()
        setclipboard("https://www.pythonanywhere.com/whitelist/")
        Rayfield:Notify({
            Title = "Copied!",
            Content = "past the link in your browser to see which sites work",
            Duration = 6.5,
            Image = 124144713366592,
         })
    end,
 })
Section = Information:CreateSection("Auto Build")
local Paragraph = Information:CreateParagraph({Title = "Information - [AUTO BUILD IS IN WORK IN PROGRESS]", Content = "this feature does not require any external requirement, if you save a build with a name that already existed, it will overwrite it. You can download and shares files in the Discord Server.\n\n - Safe Mode: prevents crashes during loading if you have a poor internet connection, this toggle slows down build speed.\n\n - Preview: displays a preview of the build."})

local player = game.Players.LocalPlayer
local Nplayer = game.Players.LocalPlayer.Name


local Section = Credit:CreateSection("Discord")
Section = Information:CreateSection("Discord")

local Button = Credit:CreateButton({
    Name = "Мяу мяу мяуу",
    Callback = function()
        setclipboard("Я пользуюсь RBXH!")
        Rayfield:Notify({
            Title = "Вау ты скопировал!",
            Content = "Мяу!",
            Duration = 6.5,
            Image = 124144713366592,
         })
    end,
 })

local Paragraph = Global:CreateParagraph({Title = "Script Outdated", Content = "Get the new one in the discord server or replace 'Source.lua' by 'Jan25_Source.lua' in the loadstring."})
--local Paragraph = Global:CreateParagraph({Title = "New script down", Content = "The new script is currently down, use this one (old one) instead."})

local Button = Global:CreateButton({
    Name = "Load new script",
    Callback = function()
        for _, v in ipairs(previewFolder:GetChildren()) do
            v:Destroy()
    end
        FcMaster = false
        Rayfield:Destroy()
        local GameStuff = {
            "Blocks",
            "Challenge",
            "TempStuff",
            "Teams",
            "MainTerrain",
            "OtherStages",
            "BlackZone",
            "CamoZone",
            "MagentaZone",
            "New YellerZone",
            "Really blueZone",
            "Really redZone",
            "Sand",
            "Water",
            "WhiteZone",
            "WaterMask"
        }
            for _, v in ipairs(GameStuff) do
                local object = game:GetService("ReplicatedStorage"):FindFirstChild(v)
                if object then
                    if v == "OtherStages" then
                        game:GetService("ReplicatedStorage").OtherStages.Parent = workspace.BoatStages
                    else
                        object.Parent = workspace
                    end
                end
            end

        loadstring(game:HttpGet('https://raw.githubusercontent.com/TheRealAsu/BABFT/refs/heads/main/Jan25_Source.lua'))()
    end,
})

Global:CreateDivider()


local yjdtjf = Global:CreateButton({
    Name = "Unload Script",
    Callback = function()
        for _, v in ipairs(previewFolder:GetChildren()) do
            v:Destroy()
    end
        FcMaster = false
        Rayfield:Destroy()
        local GameStuff = {
            "Blocks",
            "Challenge",
            "TempStuff",
            "Teams",
            "MainTerrain",
            "OtherStages",
            "BlackZone",
            "CamoZone",
            "MagentaZone",
            "New YellerZone",
            "Really blueZone",
            "Really redZone",
            "Sand",
            "Water",
            "WhiteZone",
            "WaterMask"
        }
            for _, v in ipairs(GameStuff) do
                local object = game:GetService("ReplicatedStorage"):FindFirstChild(v)
                if object then
                    if v == "OtherStages" then
                        game:GetService("ReplicatedStorage").OtherStages.Parent = workspace.BoatStages
                    else
                        object.Parent = workspace
                    end
                end
            end
    end,
 })

local player = game.Players.LocalPlayer
local Nplayer = game.Players.LocalPlayer.Name

local characterConnection
local connection

local function enableAntiAFK()
    if not connection then
        Rayfield:Notify({
            Title = "Анти кик",
            Content = "Тебя теперь не кикнет через 20 минут! Мяв 🐱",
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
            Title = "Анти кик",
            Content = "Ниит не уходи а то через 20 минут кикнет.. 😿",
            Duration = 6.5,
            Image = 124144713366592,
         })
    end
end

local function loop()
    while true do
        if getgenv().afk6464 then
            enableAntiAFK()
        else
            disableAntiAFK()
        end
        wait(1)
    end
end

spawn(loop)

Section = Global:CreateSection("Utilities")
local AFKToggle = Global:CreateToggle({
    Name = "Анти афк",
    CurrentValue = false,
    Flag = "",
    Callback = function(Value)
        getgenv().afk6464 = Value
    end,
})

if getgenv().afk6464 == true then
    AFKToggle:Set(true)
end


local Button = Global:CreateButton({ -- From IY
    Name = "Перезайти",
    Callback = function()
        Rayfield:Notify({
            Title = "Перезаход..",
            Content = "Вы будете играть там же где и играли :)",
            Duration = 6.5,
            Image = 124144713366592,
         })
         wait(0.2)
        if #Players:GetPlayers() <= 1 then
            Players.LocalPlayer:Kick("\nRejoining...")
            wait()
            TeleportService:Teleport(PlaceId, Players.LocalPlayer)
        else
            TeleportService:TeleportToPlaceInstance(PlaceId, JobId, Players.LocalPlayer)
        end
        wait(5)
        Rayfield:Notify({
            Title = "Rejoin may have failed",
            Content = "try with infinite yield",
            Duration = 6.5,
            Image = 124144713366592,
         })
    end,
})


Section = Global:CreateSection("Auto Farm - The most powerful one")
local AutoFarm1 = Global:CreateToggle({
    Name = "Auto Farm",
    CurrentValue = false,
    Flag = "",
    Callback = function(Value)
        getgenv().AF = Value
        local isFarming = false

        local function startAutoFarm()
            if Value == false then return end

            local character = player.Character or player.CharacterAdded:Wait()
            local humanoidRootPart = character:WaitForChild("HumanoidRootPart") -- What are you looking for, basket ? :) no skid ;)

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
            if not Silent then
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

                wait(2.3) -- if lower, it can't work every time
                if iteration == 1 then
                    wait(2.3)
                end
                if iteration == 4 then
                else
                    workspace.ClaimRiverResultsGold:FireServer()
                end
            else
                if Value == false then return end
                if iteration == 1 then
                    humanoidRootPart.CFrame = CFrame.new(160.16104125976562, 29.595888137817383, 973.813720703125)
                elseif iteration == 5 then
                    firetouchinterest(game.Players.LocalPlayer.Character:WaitForChild("HumanoidRootPart"), workspace.BoatStages.NormalStages.TheEnd.GoldenChest.Trigger, 0)
                    task.delay(0.8, function()
                        workspace.ClaimRiverResultsGold:FireServer()
                    end)
                    
                    humanoidRootPart.CFrame = CFrame.new(70.02417755126953, 138.9026336669922, 1371.6341552734375 + (iteration - 2) * 770)
                else
                    humanoidRootPart.CFrame = CFrame.new(70.02417755126953, 138.9026336669922, 1371.6341552734375 + (iteration - 2) * 770)
                end
                newPart.Position = humanoidRootPart.Position - Vector3.new(0, 2, 0)

                wait(2.3) -- if lower, it can't work every time
                if iteration == 1 then
                    wait(2.3)

                end
                if iteration == 4 then
                else
                    workspace.ClaimRiverResultsGold:FireServer()
                end
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

                local function onCharacterRespawned()
                    if getgenv().AF == true then
                        if FcMaster == false then return end
                    local character = player.Character or player.CharacterAdded:Wait()
                    character:WaitForChild("HumanoidRootPart")
                       -- wait(2)
                    startAutoFarm()
                    end
                end

        if Value then
            Rayfield:Notify({
                Title = "Мани мани мани 🙀",
                Content = "Лучше включить анти афк :)",
                Duration = 6.5,
                Image = 124144713366592,
             })
            game.Players.LocalPlayer.Character:BreakJoints()
            wait(1)
            game.Players.LocalPlayer.CharacterAdded:Connect(onCharacterRespawned)
        else
            Rayfield:Notify({
                Title = "Мани бизнес выключен, только же начали!",
                Content = "Игрок дойдёт до конца, либо можете ресетнуться.",
                Duration = 6.5,
                Image = 124144713366592,
             })
            game.Players.LocalPlayer.CharacterAdded:Connect(function() end)
        end
    end,
})

local FStats = Global:CreateParagraph({Title = "Stats", Content = "Elapsed time: -".."\n".."GoldBlock Gained: -".."\n".."Gold Gained: -".."\n".."\n".."Gold per hour: -"})

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
    return hours .. " hours " .. minutes .. " minutes " .. sec .. " seconds"
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
        wait(5)
        startClock()
    end
end)

function initclock()
while true do
    local FinalGold = game:GetService("Players").LocalPlayer.Data.Gold.Value
    Ftime = formatTime(clockTime)
    local GoldGained = FinalGold - lastGoldValue
    totalGoldGained = totalGoldGained + GoldGained
    local FGBLOCK = game:GetService("Players").LocalPlayer.Data.GoldBlock.Value
    totalGoldBlock = FGBLOCK - IGBLOCK

    GoldPerHour = (totalGoldGained / clockTime) * 3600

    FStats:Set({
        Title = "Stats",
        Content = "Elapsed time: " .. Ftime .. "\n" ..
                  "GoldBlock Gained: " .. totalGoldBlock .. "\n" ..
                  "Gold Gained: " .. totalGoldGained .. "\n" ..
                  "Gold per hour: " .. math.floor(GoldPerHour),
    })

    lastGoldValue = FinalGold

    wait(1)
end
end

GoldPerHour = 0

function SendMessageEMBED(url, embed)
    local http = game:GetService("HttpService")
    local headers = {
        ["Content-Type"] = "application/json"
    }
    local data = {
        ["embeds"] = {
            {
                ["title"] = embed.title,
                ["description"] = embed.description,
                ["color"] = embed.color,
                ["fields"] = embed.fields,
                ["footer"] = {
                    ["text"] = embed.footer.text
                },
                ["thumbnail"] = {
                    ["url"] = embed.thumbnail_url
                }
            }
        }
    }
    local body = http:JSONEncode(data)
    local response = request({
        Url = url,
        Method = "POST",
        Headers = headers,
        Body = body
    })
end

local WebHook = "a"
local interval = 1800

function SendAUTOFARMInfo(Ftime, totalGoldBlock, totalGoldGained, GoldPerHour)
    local embed = {
        ["title"] = "BABFT | Auto Farm",
        ["description"] = "Stats",
        ["color"] = 16777215,
        ["fields"] = {
            {
                ["name"] = "Time Elapsed",
                ["value"] = Ftime or 0
            },
            {
                ["name"] = "GoldBlock Gained:",
                ["value"] = tostring(totalGoldBlock) or 0
            },
            {
                ["name"] = "Gold Gained:",
                ["value"] = tostring(totalGoldGained) or 0
            },
            {
                ["name"] = "Gold per hour:",
                ["value"] = tostring(math.floor(GoldPerHour)) or 0
            },
            {
                ["name"] = "Total Gold:",
                ["value"] = game:GetService("Players").LocalPlayer.Data.Gold.Value or 0
            },
        },
        ["footer"] = {
            ["text"] = "Script by @thereal_asu"
        },
        ["thumbnail_url"] = "https://tr.rbxcdn.com/180DAY-5cc07c05652006d448479ae66212782d/768/432/Image/Webp/noFilter"
    }

    if WebHook then
        print("send")
        SendMessageEMBED(WebHook, embed)
    end
end

--[[
local embed2 = { -- Hello, this webhook is just for me to know how many people execute this script, everything is anonymous
    ["title"] = "Build A Boat For Treasure",
    ["description"] = "Script Executed!",
    ["color"] = math.random(1, 16777215),
    ["footer"] = {
        ["text"] = "Script by @thereal_asu"
    },
    ["thumbnail_url"] = "https://tr.rbxcdn.com/180DAY-5cc07c05652006d448479ae66212782d/768/432/Image/Webp/noFilter"
}
SendMessageEMBED("the webhook got found and removed, i won't put a new one lol, thanks for the 15K executions in 3 days. - 7th january 2025", embed2)
]]

local InputWebHook = Global:CreateInput({
    Name = "Discord Webhook URL:",
    CurrentValue = "",
    PlaceholderText = "URL",
    RemoveTextAfterFocusLost = false,
    Flag = "Input1",
    Callback = function(Text)
        WebHook = Text
    end,
})

local InputInterval = Global:CreateInput({
    Name = "Time between messages:",
    CurrentValue = "1800",
    PlaceholderText = "Seconds",
    RemoveTextAfterFocusLost = false,
    Flag = "Input2",
    Callback = function(Text)
        interval = tonumber(Text)
    end,
})

local Toggle = Global:CreateToggle({
    Name = "Use WebHook",
    CurrentValue = false,
    Flag = "Toggle1",
    Callback = function(Value)
        getgenv().WBhook = Value
    end,
})

coroutine.wrap(function()
    while true do
        if getgenv().WBhook and getgenv().AF and not getgenv().intervalLock then
            getgenv().intervalLock = true
            SendAUTOFARMInfo(Ftime, totalGoldBlock, totalGoldGained, GoldPerHour)
            task.wait(interval)
            getgenv().intervalLock = false
        end
        task.wait(1)
    end
end)()

local BlockId = loadstring(game:HttpGet('https://raw.githubusercontent.com/TheRealAsu/BABFT/refs/heads/main/BlockId.lua'))()

local ImageFiles = {}

local function updateImageFiles()

    local files = listfiles("BABFT/Image")

    ImageFiles = {}

    for _, file in ipairs(files) do
        if isfile(file) then
            table.insert(ImageFiles, file)
        end
    end

end

local Label = ImageLoader:CreateLabel("Check the Information tab to use this feature", 134637165939940, Color3.fromRGB(204, 156, 0), true)

--[[
local Dropdownimg = ImageLoader:CreateDropdown({ --When shlex adds a script to refresh the dropdown
    Name = "Files",
    Options = ImageFiles,
    CurrentOption = {""},
    MultipleOptions = false,
    Flag = "",
    Callback = function(Options)
    end,
 })


--AUTO BUILD
local Label = AutoBuild:CreateLabel("Check the Information tab to use this feature", 134637165939940, Color3.fromRGB(204, 156, 0), true)
local Label = AutoBuild:CreateLabel("THIS FEATURE IS IN WIP - it's not working right now", 134637165939940, Color3.fromRGB(204, 31, 0), true)

local Divider = AutoBuild:CreateDivider()

--[[
Section = AutoBuild:CreateSection("Steal Build")

local Dropdown = AutoBuild:CreateDropdown({
    Name = "Target Player",
    Options = {"Option 1","Option 2"},
    CurrentOption = {"Option 1"},
    MultipleOptions = false,
    Flag = "Dropdown1", -- A flag is the identifier for the configuration file, make sure every element has a different flag if you're using configuration saving to ensure no overlaps
    Callback = function(Options)
    -- The function that takes place when the selected option is changed
    -- The variable (Options) is a table of strings for the current selected options
    end,
 })

 local Input = AutoBuild:CreateInput({
    Name = "Build Name",
    CurrentValue = "",
    PlaceholderText = "Name",
    RemoveTextAfterFocusLost = false,
    Flag = "Input1",
    Callback = function(Text)
    -- The function that takes place when the input is changed
    -- The variable (Text) is a string for the value in the text box
    end,
 })

 local Button = AutoBuild:CreateButton({
    Name = "Save",
    Callback = function()
    -- The function that takes place when the button is pressed
    end,
 })

 local Divider = AutoBuild:CreateDivider()
Section = AutoBuild:CreateSection("Auto Build")

 local Dropdown = AutoBuild:CreateDropdown({
    Name = "Build File",
    Options = {"Option 1","Option 2"},
    CurrentOption = {"Option 1"},
    MultipleOptions = false,
    Flag = "Dropdown1", -- A flag is the identifier for the configuration file, make sure every element has a different flag if you're using configuration saving to ensure no overlaps
    Callback = function(Options)
    -- The function that takes place when the selected option is changed
    -- The variable (Options) is a table of strings for the current selected options
    end,
 })

 local Toggle = AutoBuild:CreateToggle({
    Name = "Preview",
    CurrentValue = false,
    Flag = "Toggle1", -- A flag is the identifier for the configuration file, make sure every element has a different flag if you're using configuration saving to ensure no overlaps
    Callback = function(Value)
    -- The function that takes place when the toggle is pressed
    -- The variable (Value) is a boolean on whether the toggle is true or false
    end,
 })

 local Toggle = AutoBuild:CreateToggle({
    Name = "Safe Mode",
    CurrentValue = false,
    Flag = "Toggle1", -- A flag is the identifier for the configuration file, make sure every element has a different flag if you're using configuration saving to ensure no overlaps
    Callback = function(Value)
    -- The function that takes place when the toggle is pressed
    -- The variable (Value) is a boolean on whether the toggle is true or false
    end,
 })

 local Button = AutoBuild:CreateButton({
    Name = "Load",
    Callback = function()
    -- The function that takes place when the button is pressed
    end,
 })
]]

 local Paragraph = BlockNeeded:CreateParagraph({Title = "Important", Content = "Preview mode must be enabled to calculate the number of blocks required"})
 local Divider = BlockNeeded:CreateDivider()
Section = BlockNeeded:CreateSection("Image Loader")
 local LblBlockNeeded = BlockNeeded:CreateLabel("No block found", 72272740678757, Color3.fromRGB(255, 255, 255), true)
 local Divider = BlockNeeded:CreateDivider()
Section = BlockNeeded:CreateSection("Auto Build")
 local Label = BlockNeeded:CreateLabel("THIS FEATURE IS IN WIP", 134637165939940, Color3.fromRGB(204, 31, 0), true)
 local Divider = BlockNeeded:CreateDivider()
  local NbBlockneeded = 0
  local NbBlockmissing = 0
  local Button = BlockNeeded:CreateButton({
      Name = "Refresh List",
      Callback = function()
          NbBlockneeded = 0
          local blocktypeID = BlockId[BlockType]

          for _, skibidi in ipairs(workspace.ImagePreview:GetChildren()) do
            if skibidi.Name == "Part" then

                local blockVolume = skibidi.Size.X * skibidi.Size.Y * skibidi.Size.Z

                local blockSize = (blockVolume < 8) and 8 or blockVolume

                NbBlockneeded = NbBlockneeded + blockSize
            end
        end
            UUserBlockList()
          LPBlockvalue = UserBlockList[BlockType]
          NbBlockneeded = math.ceil(NbBlockneeded / 8)
          NbBlockmissing = NbBlockneeded - LPBlockvalue
          if NbBlockmissing < 0 then
            NbBlockmissing = 0
          end
          LblBlockNeeded:Set("Need " .. tostring(NbBlockneeded) .. " " .. BlockType .. " and " .. tostring(NbBlockmissing) .. " blocks are missing", blocktypeID, Color3.fromRGB(255, 255, 255), true)
      end,
  })

Section = Miscellaneous:CreateSection("Teleportation")

local Button = Miscellaneous:CreateButton({
    Name = "White",
    Callback = function()
        game.Players.LocalPlayer.Character:SetPrimaryPartCFrame(CFrame.new(-49.8510132, -9.7000021, -520.37085, -1, 0, 0, 0, 1, 0, 0, 0, -1))
    end,
 })

 local Button = Miscellaneous:CreateButton({
    Name = "Black",
    Callback = function()
        game.Players.LocalPlayer.Character:SetPrimaryPartCFrame(CFrame.new(-503.82843, -9.7000021, -69.433342, 0, 0, -1, 0, 1, 0, 1, 0, 0))
    end,
 })

 local Button = Miscellaneous:CreateButton({
    Name = "Red",
    Callback = function()
        game.Players.LocalPlayer.Character:SetPrimaryPartCFrame(CFrame.new(396.697418, -9.7000021, -64.7801361, 0, 0, 1, 0, 1, -0, -1, 0, 0))
    end,
 })

 local Button = Miscellaneous:CreateButton({
    Name = "Blue",
    Callback = function()
        game.Players.LocalPlayer.Character:SetPrimaryPartCFrame(CFrame.new(396.697418, -9.7000021, 300.219849, 0, 0, 1, 0, 1, -0, -1, 0, 0))
    end,
 })

 local Button = Miscellaneous:CreateButton({
    Name = "Magenta",
    Callback = function()
        game.Players.LocalPlayer.Character:SetPrimaryPartCFrame(CFrame.new(396.697418, -9.7000021, 647.219849, 0, 0, 1, 0, 1, -0, -1, 0, 0))
    end,
 })

 local Button = Miscellaneous:CreateButton({
    Name = "Yellow",
    Callback = function()
        game.Players.LocalPlayer.Character:SetPrimaryPartCFrame(CFrame.new(-503.82843, -9.7000021, 640.56665, 0, 0, -1, 0, 1, 0, 1, 0, 0))
    end,
 })

 local Button = Miscellaneous:CreateButton({
    Name = "Green",
    Callback = function()
        game.Players.LocalPlayer.Character:SetPrimaryPartCFrame(CFrame.new(-503.82843, -9.7000021, 293.56665, 0, 0, -1, 0, 1, 0, 1, 0, 0))
    end,
 })

Section = Miscellaneous:CreateSection("Troll")
local Button = Miscellaneous:CreateButton({
    Name = "Disable Maximum click detector distance",
    Callback = function()
        for _, object in ipairs(game:GetDescendants()) do
            if object:IsA("ClickDetector") then
                object.MaxActivationDistance = 9995649849899589
            end
        end
        Rayfield:Notify({
            Title = "Maximum click detector distance Disabled!",
            Content = "You can click on a lever, button, etc.. from anywhere",
            Duration = 6.5,
            Image = 124144713366592,
        })
    end,
 })

local Button = Miscellaneous:CreateButton({
    Name = "Force Share Mode",
    Callback = function()
        local args = {
            [1] = "ShareBlocks",
            [2] = true
        }
        workspace.SettingFunction:InvokeServer(unpack(args))
        Rayfield:Notify({
            Title = "Share Mode",
            Content = "you can use leader's blocks now",
            Duration = 6.5,
            Image = 124144713366592,
        })
    end,
 })

 local Button = Miscellaneous:CreateButton({
    Name = "disable Share Mode",
    Callback = function()
        local args = {
            [1] = "ShareBlocks",
            [2] = false
        }
        workspace.SettingFunction:InvokeServer(unpack(args))
        Rayfield:Notify({
            Title = "Share Mode",
            Content = "Share Mode is disabled",
            Duration = 6.5,
            Image = 124144713366592,
        })
    end,
 })
 
 local Button = Miscellaneous:CreateButton({
    Name = "Color all blocks",
    Callback = function()
        local playerteam = player.Team.Name
        local blocktoget = game:GetService("Teams"):FindFirstChild(playerteam).TeamLeader.Value
        local playerFolder = game.Workspace.Blocks:FindFirstChild(blocktoget)
        local paintData = {}
        local totalBlocks = #playerFolder:GetChildren()

        for _, block in ipairs(playerFolder:GetChildren()) do
            local color = Color3.new(
                math.random(0, 1000) / 1000,
                math.random(0, 1000) / 1000,
                math.random(0, 1000) / 1000
            )

            table.insert(paintData, {
                block,
                color
            })

            if #paintData >= 10000 then
                game:GetService("Players").LocalPlayer.Backpack.PaintingTool.RF:InvokeServer(paintData)
                paintData = {}
            end
        end

        if #paintData > 0 then
            game:GetService("Players").LocalPlayer.Backpack.PaintingTool.RF:InvokeServer(paintData)
        end
    end,
})

local Toggle = Miscellaneous:CreateToggle({
    Name = "Loop Color all blocks",
    CurrentValue = false,
    Flag = "Toggle1",
    Callback = function(Value)
while Value do
    if Value then
    local playerteam = player.Team.Name
    local blocktoget = game:GetService("Teams"):FindFirstChild(playerteam).TeamLeader.Value
    local playerFolder = game.Workspace.Blocks:FindFirstChild(blocktoget)
    local paintData = {}
    local totalBlocks = #playerFolder:GetChildren()

    for _, block in ipairs(playerFolder:GetChildren()) do
        local color = Color3.new(
            math.random(0, 1000) / 1000,
            math.random(0, 1000) / 1000,
            math.random(0, 1000) / 1000
        )

        table.insert(paintData, {
            block,
            color
        })

        if #paintData >= 10000 then
            game:GetService("Players").LocalPlayer.Backpack.PaintingTool.RF:InvokeServer(paintData)
            paintData = {}
        end
    end

    if #paintData > 0 then
        game:GetService("Players").LocalPlayer.Backpack.PaintingTool.RF:InvokeServer(paintData)
    end
    task.wait()
end
end
    end,
 })


 local Toggle = Miscellaneous:CreateToggle({
    Name = "Hide All [Optimized for Auto Farm]",
    CurrentValue = false,
    Flag = "Toggle1",
    Callback = function(Value)
        local Stuff = {
            "Blocks",
            "Challenge",
            "TempStuff",
            "Teams",
            "MainTerrain",
            "OtherStages",
            "BlackZone",
            "CamoZone",
            "MagentaZone",
            "New YellerZone",
            "Really blueZone",
            "Really redZone",
            "Sand",
            "Water",
            "WhiteZone",
            "WaterMask"
        }

        if Value then
            for _, v in ipairs(Stuff) do
                local object = workspace:FindFirstChild(v) or workspace.BoatStages:FindFirstChild("OtherStages")
                if object then
                    object.Parent = game:GetService("ReplicatedStorage")
                end
            end
        else
            for _, v in ipairs(Stuff) do
                local object = game:GetService("ReplicatedStorage"):FindFirstChild(v)
                if object then
                    if v == "OtherStages" then
                        game:GetService("ReplicatedStorage").OtherStages.Parent = workspace.BoatStages
                    else
                        object.Parent = workspace
                    end
                end
            end
        end
    end,
})

local spoofSpeed = 40

Section = Miscellaneous:CreateSection("Spoofer")
 local Slider = Miscellaneous:CreateSlider({
    Name = "Wheel Speed",
    Range = {10, 1000},
    Increment = 10,
    Suffix = " - MaxSpeed",
    CurrentValue = 40,
    Flag = "Slider1",
    Callback = function(Value)
        spoofSpeed = Value
    end,
 })

 local Button = Miscellaneous:CreateButton({
    Name = "Spoof speed",
    Callback = function()
        local itcihmsoeoesoes = workspace.Blocks:FindFirstChild(Nplayer)
        if itcihmsoeoesoes then
    for _, model in ipairs(itcihmsoeoesoes:GetChildren()) do
        if model:IsA("Model") then
            local maxSpeed = model:FindFirstChild("MaxSpeed")
            if maxSpeed and maxSpeed:IsA("NumberValue") then
                maxSpeed.Value = spoofSpeed
            end
        end
    end
end
    end,
 })

Section = Miscellaneous:CreateSection("Teleport to Place")
 local Button = Miscellaneous:CreateButton({
    Name = "Inner Cloud",
    Callback = function()
        TeleportService:Teleport(1930863474, game.Players.LocalPlayer)
    end,
 })

Button = Miscellaneous:CreateButton({
    Name = "Christmas",
    Callback = function()
        TeleportService:Teleport(1930866268, game.Players.LocalPlayer)
    end,
 })

local function Init()
local initclock = coroutine.create(initclock)
local ImgStats = coroutine.create(ImgStats)
local initimgfiles = coroutine.create(initimgfiles)
local ImgStats2 = coroutine.create(ImgStats2)

coroutine.resume(initclock)
coroutine.resume(ImgStats)
coroutine.resume(initimgfiles)
coroutine.resume(ImgStats2)
end

zdzddz = Miscellaneous:CreateButton({
    Name = "Halloween [maybe need an anti-kick]",
    Callback = function()
        TeleportService:Teleport(1930665568, game.Players.LocalPlayer) -- WARNING: YOU WILL GET KICKED WHEN YOU JOIN IT, need to try with a client-sided anti kick
    end,
 })
Init()
