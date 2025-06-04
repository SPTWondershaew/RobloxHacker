-- Kill Aura Script (LocalScript)

-- Services
local Players = game:GetService("Players")
local UserInputService = game:GetService("UserInputService")
local RunService = game:GetService("RunService")

-- Configuration
local TOGGLE_KEY = Enum.KeyCode.V -- Клавиша для включения/выключения киллауры
local AURA_RANGE = 20 -- Радиус действия киллауры (в стад-единицах)
local DAMAGE_AMOUNT = 10 -- Количество урона, наносимого за удар
local ATTACK_DELAY = 0.5 -- Задержка между ударами (в секундах)

-- Variables
local LocalPlayer = Players.LocalPlayer
local Character = LocalPlayer.Character or LocalPlayer.CharacterAdded:Wait()
local Humanoid = Character:WaitForChild("Humanoid")
local HumanoidRootPart = Character:WaitForChild("HumanoidRootPart")

local isAuraActive = false
local lastAttackTime = 0

local function findNearestTarget()
    if not HumanoidRootPart then return nil end
    local closestTarget = nil
    local shortestDistance = AURA_RANGE + 1

    for _, player in ipairs(Players:GetPlayers()) do
        if player == LocalPlayer then continue end
        local targetCharacter = player.Character
        if targetCharacter and targetCharacter:FindFirstChildOfClass("Humanoid") then
            local targetHumanoid = targetCharacter:FindFirstChildOfClass("Humanoid")
            local targetRootPart = targetCharacter:FindFirstChild("HumanoidRootPart")
            if targetHumanoid and targetHumanoid.Health > 0 and targetRootPart then
                local distance = (HumanoidRootPart.Position - targetRootPart.Position).Magnitude
                if distance <= AURA_RANGE and distance < shortestDistance then
                    shortestDistance = distance
                    closestTarget = targetHumanoid
                end
            end
        end
    end
    return closestTarget
end

local function attackTarget(targetHumanoid)
    if targetHumanoid and targetHumanoid.Health > 0 then
        targetHumanoid:TakeDamage(DAMAGE_AMOUNT)
    end
end

local function toggleAura()
    isAuraActive = not isAuraActive
end

UserInputService.InputBegan:Connect(function(input, gameProcessedEvent)
    if gameProcessedEvent then return end
    if input.KeyCode == TOGGLE_KEY then
        toggleAura()
    end
end)

RunService.RenderStepped:Connect(function()
    if isAuraActive then
        local currentTime = tick()
        if currentTime - lastAttackTime >= ATTACK_DELAY then
            local target = findNearestTarget()
            if target then
                attackTarget(target)
                lastAttackTime = currentTime
            end
        end
    end
end)

LocalPlayer.CharacterAdded:Connect(function(newCharacter)
    if isAuraActive then
        isAuraActive = false
    end
    Character = newCharacter
    Humanoid = newCharacter:WaitForChild("Humanoid")
    HumanoidRootPart = newCharacter:WaitForChild("HumanoidRootPart")
    lastAttackTime = 0
end)
