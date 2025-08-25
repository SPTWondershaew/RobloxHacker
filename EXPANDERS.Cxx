local HttpService = cloneref(game:GetService("HttpService"))
local Players = game:GetService("Players")
local Workspace = game:GetService("Workspace")
local VirtualUser = game:GetService("VirtualUser")
local httprequest = (syn and syn.request) or (http and http.request) or http_request or (fluxus and fluxus.request) or request
local RunService = game:GetService("RunService")

local player = game.Players.LocalPlayer
local Nplayer = game.Players.LocalPlayer.Name

-- Create the main window for CHH
local Window = Rayfield:CreateWindow({
    Name = "CHH",
    Icon = 85108798400826, -- You can change this icon ID
    LoadingTitle = "CHH",
    LoadingSubtitle = "Minimal Edition by @thereal_asu",
    Theme = "DarkBlue",
    DisableRayfieldPrompts = true,
    DisableBuildWarnings = true,
    ConfigurationSaving = {
       Enabled = false,
       FolderName = nil,
       FileName = "CHH Minimal"
    },
    Discord = {
       Enabled = false, -- Disable Discord for minimal version
       Invite = "MdtGaG7vdx",
       RememberJoins = true
    },
    KeySystem = false, -- Keep key system if desired, but remove default key message
    KeySettings = {
       Title = "CHH",
       Subtitle = "Minimal Script",
       Note = "No key needed for this version.",
       FileName = "CHHMinimalKey",
       SaveKey = true,
       GrabKeyFromSite = false,
       Key = {"minimal"}
    }
})

-- Anti-AFK Logic
local connection

local function enableAntiAFK()
    if not connection then
        Rayfield:Notify({
            Title = "Anti-Afk | ON",
            Content = "You won't get kicked after 20 minutes of inactivity",
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
            Title = "Anti-Afk | OFF",
            Content = "You will be kicked after 20 minutes of inactivity",
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

-- Auto Farm Logic
local Silent = false

local AFKToggle = Window:CreateToggle({
    Name = "Anti-Afk",
    CurrentValue = false,
    Flag = "AntiAfkToggle",
    Callback = function(Value)
        getgenv().afk6464 = Value
    end,
})

if getgenv().afk6464 == true then
    AFKToggle:Set(true)
end

Window:CreateDivider()

local AutoFarmToggle = Window:CreateToggle({
    Name = "Auto Farm",
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

                    task.wait(2.3) -- if lower, it can't work every time
                    if iteration == 1 then
                        task.wait(2.3)
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

                    task.wait(2.3) -- if lower, it can't work every time
                    if iteration == 1 then
                        task.wait(2.3)
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
                Title = "Auto Farm - Enabled",
                Content = "Anti-afk is recommended",
                Duration = 6.5,
                Image = 124144713366592,})
            game.Players.LocalPlayer.Character:BreakJoints()
            task.wait(1)
            charAddedConnection = game.Players.LocalPlayer.CharacterAdded:Connect(onCharacterRespawned)
        else
            Rayfield:Notify({
                Title = "Auto Farm - Disabled",
                Content = "Please, wait for the current iteration to finish...",
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

local SilentToggle = Window:CreateToggle({
    Name = "Make it Silent",
    CurrentValue = false,
    Flag = "SilentModeToggle",
    Callback = function(Value)
        Silent = Value
    end,
})

local FStats = Window:CreateParagraph({Title = "Auto Farm Stats", Content = "Elapsed time: -\nGoldBlock Gained: -\nGold Gained: -\n\nGold per hour: -"})

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
            Title = "Auto Farm Stats",
            Content = "Elapsed time: " .. Ftime .. "\n" ..
                      "GoldBlock Gained: " .. totalGoldBlock .. "\n" ..
                      "Gold Gained: " .. totalGoldGained .. "\n" ..
                      "Gold per hour: " .. math.floor(GoldPerHour),
        })

        lastGoldValue = FinalGold

        task.wait(1)
    end
end

GoldPerHour = 0 -- This line is redundant as GoldPerHour is initialized to 0 above.

-- Webhook functionality
local WebHook = "" -- Initialize as empty string
local interval = 1800

local function SendMessageEMBED(url, embed)
    if not httprequest then return end -- Check if httprequest is available
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
    local success, response = pcall(function()
        return httprequest({
            Url = url,
            Method = "POST",
            Headers = headers,
            Body = body
        })
    end)
    if not success then
        warn("Webhook request failed: ", response)
    end
end

local function SendAUTOFARMInfo(Ftime_param, totalGoldBlock_param, totalGoldGained_param, GoldPerHour_param)
    local embed = {
        ["title"] = "BABFT | Auto Farm",
        ["description"] = "Stats",
        ["color"] = 16777215,
        ["fields"] = {
            {
                ["name"] = "Time Elapsed",
                ["value"] = Ftime_param or "0 hours 0 minutes 0 seconds"
            },
            {
                ["name"] = "GoldBlock Gained:",
                ["value"] = tostring(totalGoldBlock_param) or "0"
            },
            {
                ["name"] = "Gold Gained:",
                ["value"] = tostring(totalGoldGained_param) or "0"
            },
            {
                ["name"] = "Gold per hour:",
                ["value"] = tostring(math.floor(GoldPerHour_param)) or "0"
            },
            {
                ["name"] = "Total Gold:",
                ["value"] = tostring(game:GetService("Players").LocalPlayer.Data.Gold.Value) or "0"
            },
        },
        ["footer"] = {
            ["text"] = "Script by @thereal_asu"
        },
        ["thumbnail_url"] = "https://tr.rbxcdn.com/180DAY-5cc07c05652006d448479ae66212782d/768/432/Image/Webp/noFilter"
    }

    if WebHook and WebHook ~= "" then
        print("Sending webhook message...")
        SendMessageEMBED(WebHook, embed)
    else
        warn("Webhook URL is empty. Not sending message.")
    end
end

Window:CreateDivider()

Window:CreateInput({
    Name = "Discord Webhook URL:",
    CurrentValue = "",
    PlaceholderText = "URL",
    RemoveTextAfterFocusLost = false,
    Flag = "WebhookInput",
    Callback = function(Text)
        WebHook = Text
    end,
})

Window:CreateInput({
    Name = "Time between webhook messages:",
    CurrentValue = "1800",
    PlaceholderText = "Seconds",
    RemoveTextAfterFocusLost = false,
    Flag = "IntervalInput",
    Callback = function(Text)
        interval = tonumber(Text) or 1800 -- Ensure it's a number, default to 1800
    end,
})

Window:CreateToggle({
    Name = "Use WebHook",
    CurrentValue = false,
    Flag = "UseWebhookToggle",
    Callback = function(Value)
        getgenv().WBhook = Value
    end,
})

coroutine.wrap(function()
    while true do
        if getgenv().WBhook and getgenv().AF and not getgenv().intervalLock and WebHook and WebHook ~= "" then
            getgenv().intervalLock = true
            SendAUTOFARMInfo(Ftime, totalGoldBlock, totalGoldGained, GoldPerHour)
            task.wait(interval)
            getgenv().intervalLock = false
        end
        task.wait(1)
    end
end)()

-- Initialize the clock for stats
task.spawn(initClockUpdate)
