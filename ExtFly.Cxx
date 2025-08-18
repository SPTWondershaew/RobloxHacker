local main = Instance.new("ScreenGui")
local Frame = Instance.new("Frame")
local up = Instance.new("TextButton")
local down = Instance.new("TextButton")
local onof = Instance.new("TextButton")
local TextLabel = Instance.new("TextLabel")
local plus = Instance.new("TextButton")
local speed_label = Instance.new("TextLabel") -- Переименовал speed на speed_label, чтобы не конфликтовать с локальной speed
local mine = Instance.new("TextButton")
local closebutton = Instance.new("TextButton")
local mini = Instance.new("TextButton")
local mini2 = Instance.new("TextButton")

main.Name = "main"
main.Parent = game.Players.LocalPlayer:WaitForChild("PlayerGui")
main.ZIndexBehavior = Enum.ZIndexBehavior.Sibling
main.ResetOnSpawn = false

Frame.Parent = main
Frame.BackgroundColor3 = Color3.fromRGB(0, 255, 0)
Frame.BorderColor3 = Color3.fromRGB(255, 0, 0)
Frame.Position = UDim2.new(0.100320168, 0, 0.379746825, 0)
Frame.Size = UDim2.new(0, 190, 0, 57)

up.Name = "up"
up.Parent = Frame
up.BackgroundColor3 = Color3.fromRGB(255, 0, 255)
up.Size = UDim2.new(0, 44, 0, 28)
up.Font = Enum.Font.SourceSans
up.Text = "Вверх"
up.TextColor3 = Color3.fromRGB(0, 0, 0)
up.TextSize = 15.000

down.Name = "down"
down.Parent = Frame
down.BackgroundColor3 = Color3.fromRGB(255, 242, 37)
down.Position = UDim2.new(0, 0, 0.491228074, 0)
down.Size = UDim2.new(0, 44, 0, 28)
down.Font = Enum.Font.SourceSans
down.Text = "Вниз"
down.TextColor3 = Color3.fromRGB(0, 0, 0)
down.TextSize = 15.000

onof.Name = "onof"
onof.Parent = Frame
onof.BackgroundColor3 = Color3.fromRGB(219, 0, 255)
onof.Position = UDim2.new(0.702823281, 0, 0.491228074, 0)
onof.Size = UDim2.new(0, 56, 0, 28)
onof.Font = Enum.Font.SourceSans
onof.Text = "Взлететь"
onof.TextColor3 = Color3.fromRGB(0, 0, 0)
onof.TextSize = 16.000

TextLabel.Parent = Frame
TextLabel.BackgroundColor3 = Color3.fromRGB(0, 0, 255)
TextLabel.Position = UDim2.new(0.469327301, 0, 0, 0)
TextLabel.Size = UDim2.new(0, 100, 0, 28)
TextLabel.Font = Enum.Font.SourceSans
TextLabel.Text = "5 минут полёт нормальный"
TextLabel.TextColor3 = Color3.fromRGB(0, 0, 0)
TextLabel.TextScaled = true
TextLabel.TextSize = 16.000
TextLabel.TextWrapped = true

plus.Name = "up"
plus.Parent = Frame
plus.BackgroundColor3 = Color3.fromRGB(0, 255, 0)
plus.Position = UDim2.new(0.231578946, 0, 0, 0)
plus.Size = UDim2.new(0, 45, 0, 28)
plus.Font = Enum.Font.SourceSans
plus.Text = "Добавить"
plus.TextColor3 = Color3.fromRGB(0, 0, 0)
plus.TextScaled = true
plus.TextSize = 15.000
plus.TextWrapped = true

speed_label.Name = "speed" -- Используем переименованную переменную
speed_label.Parent = Frame
speed_label.BackgroundColor3 = Color3.fromRGB(102, 254, 255)
speed_label.Position = UDim2.new(0.468421042, 0, 0.491228074, 0)
speed_label.Size = UDim2.new(0, 44, 0, 28)
speed_label.Font = Enum.Font.SourceSans
speed_label.Text = "1"
speed_label.TextColor3 = Color3.fromRGB(0, 0, 0)
speed_label.TextScaled = true
speed_label.TextSize = 15.000
speed_label.TextWrapped = true

mine.Name = "mine"
mine.Parent = Frame
mine.BackgroundColor3 = Color3.fromRGB(255, 0, 0)
mine.Position = UDim2.new(0.231578946, 0, 0.491228074, 0)
mine.Size = UDim2.new(0, 45, 0, 29)
mine.Font = Enum.Font.SourceSans
mine.Text = "Уменьшить"
mine.TextColor3 = Color3.fromRGB(0, 0, 0)
mine.TextScaled = true
mine.TextSize = 15.000
mine.TextWrapped = true

closebutton.Name = "Close"
closebutton.Parent = Frame -- Parent Frame, а не main.Frame
closebutton.BackgroundColor3 = Color3.fromRGB(225, 0, 0)
closebutton.Font = Enum.Font.SourceSans -- Enum.Font.SourceSans вместо "SourceSans"
closebutton.Size = UDim2.new(0, 45, 0, 28)
closebutton.Text = "X"
closebutton.TextSize = 30
closebutton.Position =  UDim2.new(0, 0, -1, 27)

mini.Name = "minimize"
mini.Parent = Frame -- Parent Frame, а не main.Frame
mini.BackgroundColor3 = Color3.fromRGB(255, 168, 67)
mini.Font = Enum.Font.SourceSans -- Enum.Font.SourceSans
mini.Size = UDim2.new(0, 45, 0, 28)
mini.Text = "Скрыть"
mini.TextSize = 15.000
mini.Position = UDim2.new(0, 44, -1, 27)

mini2.Name = "minimize2"
mini2.Parent = Frame -- Parent Frame, а не main.Frame
mini2.BackgroundColor3 = Color3.fromRGB(255, 168, 67)
mini2.Font = Enum.Font.SourceSans -- Enum.Font.SourceSans
mini2.Size = UDim2.new(0, 45, 0, 28)
mini2.Text = "Открыть"
mini2.TextSize = 15.000
mini2.Position = UDim2.new(0, 44, -1, 57)
mini2.Visible = false

local current_speed = 1 -- Переименовал speeds на current_speed
local is_flying = false -- Переименовал nowe на is_flying для ясности
local is_moving_up = false
local is_moving_down = false
local fly_thread = nil -- Для управления основным циклом полета

local Players = game:GetService("Players")
local RunService = game:GetService("RunService")
local StarterGui = game:GetService("StarterGui")

local LocalPlayer = Players.LocalPlayer

StarterGui:SetCore("SendNotification", { 
 Title = "Привет) Разработчик шайтан машины: ";
 Text = "Kill666you_0 - Im_DrHacker (telegram)";
 Icon = "rbxthumb://type=Asset&id=5107182114&w=150&h=150"; -- Запятая здесь
    Duration = 5 -- Исправлено: теперь это часть таблицы
})

Frame.Active = true
Frame.Draggable = true

-- Функция для включения/выключения всех состояний Humanoid
local function set_humanoid_states(humanoid, enabled)
    local states = {
        Enum.HumanoidStateType.Climbing, Enum.HumanoidStateType.FallingDown, Enum.HumanoidStateType.Flying,
        Enum.HumanoidStateType.Freefall, Enum.HumanoidStateType.GettingUp, Enum.HumanoidStateType.Jumping,
        Enum.HumanoidStateType.Landed, Enum.HumanoidStateType.Physics, Enum.HumanoidStateType.PlatformStanding,
        Enum.HumanoidStateType.Ragdoll, Enum.HumanoidStateType.Running, Enum.HumanoidStateType.RunningNoPhysics,
        Enum.HumanoidStateType.Seated, Enum.HumanoidStateType.StrafingNoPhysics, Enum.HumanoidStateType.Swimming
    }
    for _, state in ipairs(states) do
        humanoid:SetStateEnabled(state, enabled)
    end
end

-- Функция для основного цикла полета
local function start_fly_loop(character, humanoid, target_part)
    local bg = Instance.new("BodyGyro")
    bg.P = 9e4
    bg.maxTorque = Vector3.new(9e9, 9e9, 9e9)
    bg.cframe = target_part.CFrame
    bg.Parent = target_part

    local bv = Instance.new("BodyVelocity")
    bv.velocity = Vector3.new(0,0.1,0)
    bv.maxForce = Vector3.new(9e9, 9e9, 9e9)
    bv.Parent = target_part

    humanoid.PlatformStand = true
    character.Animate.Disabled = true -- Отключение анимаций здесь

    local max_speed_val = 50 * current_speed -- Скорость полета зависит от current_speed
    local current_fly_speed = 0
    local ctrl = {f = 0, b = 0, l = 0, r = 0}
    local lastctrl = {f = 0, b = 0, l = 0, r = 0}

    -- Обновляем ctrl на основе пользовательского ввода
    local function on_input_changed(inputObject, gameProcessedEvent)
        if gameProcessedEvent then return end
        if inputObject.UserInputType == Enum.UserInputType.Keyboard then
            local key = inputObject.KeyCode
            if key == Enum.KeyCode.W then ctrl.f = (inputObject.InputState == Enum.InputState.Begin and 1) or 0 end
            if key == Enum.KeyCode.S then ctrl.b = (inputObject.InputState == Enum.InputState.Begin and -1) or 0 end
            if key == Enum.KeyCode.A then ctrl.l = (inputObject.InputState == Enum.InputState.Begin and -1) or 0 end
            if key == Enum.KeyCode.D then ctrl.r = (inputObject.InputState == Enum.InputState.Begin and 1) or 0 end
        end
    end

    local input_conn = game:GetService("UserInputService").InputChanged:Connect(on_input_changed)
    local input_began_conn = game:GetService("UserInputService").InputBegan:Connect(on_input_changed)
    local input_ended_conn = game:GetService("UserInputService").InputEnded:Connect(on_input_changed)

    while is_flying and character.Parent and humanoid.Health > 0 do -- Условия выхода из цикла
        RunService.RenderStepped:Wait()

        if ctrl.l + ctrl.r ~= 0 or ctrl.f + ctrl.b ~= 0 then
            current_fly_speed = current_fly_speed + .5 + (current_fly_speed / max_speed_val)
            if current_fly_speed > max_speed_val then
                current_fly_speed = max_speed_val
            end
        elseif not (ctrl.l + ctrl.r ~= 0 or ctrl.f + ctrl.b ~= 0) and current_fly_speed ~= 0 then
            current_fly_speed = current_fly_speed - 1
            if current_fly_speed < 0 then
                current_fly_speed = 0
            end
        end

        local current_cframe = game.Workspace.CurrentCamera.CoordinateFramelocal target_velocity
        if (ctrl.l + ctrl.r) ~= 0 or (ctrl.f + ctrl.b) ~= 0 then
            target_velocity = ((current_cframe.lookVector * (ctrl.f + ctrl.b)) + ((current_cframe * CFrame.new(ctrl.l + ctrl.r, (ctrl.f + ctrl.b) * .2, 0)).p - current_cframe.p)) * current_fly_speed
            lastctrl = {f = ctrl.f, b = ctrl.b, l = ctrl.l, r = ctrl.r}
        elseif (lastctrl.l + lastctrl.r) ~= 0 or (lastctrl.f + lastctrl.b) ~= 0 and current_fly_speed ~= 0 then
             target_velocity = ((current_cframe.lookVector * (lastctrl.f+lastctrl.b)) + ((current_cframe * CFrame.new(lastctrl.l+lastctrl.r,(lastctrl.f+lastctrl.b)*.2,0).p) - current_cframe.p))*current_fly_speed
        else
            target_velocity = Vector3.new(0,0,0)
        end
        
        bv.velocity = target_velocity

        bg.cframe = current_cframe * CFrame.Angles(-math.rad((ctrl.f+ctrl.b)*50*current_fly_speed/max_speed_val),0,0)
    end

    -- Очистка после выхода из цикла полета
    input_conn:Disconnect()
    input_began_conn:Disconnect()
    input_ended_conn:Disconnect()

    bg:Destroy()
    bv:Destroy()
    humanoid.PlatformStand = false
    character.Animate.Disabled = false

    set_humanoid_states(humanoid, true) -- Включить все состояния обратно
    humanoid:ChangeState(Enum.HumanoidStateType.Running) -- Вернуть обычное состояние

    if fly_thread then
        fly_thread = nil
    end
end

onof.MouseButton1Down:Connect(function()
    local character = LocalPlayer.Character
    local humanoid = character and character:FindFirstChildWhichIsA("Humanoid")

    if not character or not humanoid then return end

    if is_flying then -- Если уже летим, выключаем
        is_flying = false
        onof.Text = "Взлететь"
    else -- Если не летим, включаем
        is_flying = true
        onof.Text = "Приземлиться"
        set_humanoid_states(humanoid, false) -- Отключить все состояния
        humanoid:ChangeState(Enum.HumanoidStateType.Swimming) -- Или другое подходящее состояние для "полета"

        local target_part = (humanoid.RigType == Enum.HumanoidRigType.R6 and character:FindFirstChild("Torso")) or
                            (humanoid.RigType == Enum.HumanoidRigType.R15 and character:FindFirstChild("UpperTorso"))

        if target_part then
            -- Запускаем основной цикл полета в новом потоке
            fly_thread = coroutine.wrap(function()
                start_fly_loop(character, humanoid, target_part)
            end)()
        end
    end
end)

local up_move_conn = nil
local down_move_conn = nil

-- Исправленная логика для кнопок вверх/вниз
up.MouseButton1Down:Connect(function()
    is_moving_up = true
    if up_move_conn == nil then
        up_move_conn = RunService.Stepped:Connect(function()
            if is_moving_up and LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart") then
                LocalPlayer.Character.HumanoidRootPart.CFrame = LocalPlayer.Character.HumanoidRootPart.CFrame * CFrame.new(0, 1, 0)
            else
                up_move_conn:Disconnect()
                up_move_conn = nil
            end
        end)
    end
end)

up.MouseButton1Up:Connect(function() -- Отпускание кнопки
    is_moving_up = false
end)

up.MouseLeave:Connect(function() -- Уход мыши с кнопки (если кнопка не была отпущена)
    is_moving_up = false
end)


down.MouseButton1Down:Connect(function()
    is_moving_down = true
    if down_move_conn == nil then
        down_move_conn = RunService.Stepped:Connect(function()
            if is_moving_down and LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart") then
                LocalPlayer.Character.HumanoidRootPart.CFrame = LocalPlayer.Character.HumanoidRootPart.CFrame * CFrame.new(0, -1, 0)
            else
                down_move_conn:Disconnect()
                down_move_conn = nil
            end
        end)
    end
end)

down.MouseButton1Up:Connect(function() -- Отпускание кнопки
    is_moving_down = false
end)

down.MouseLeave:Connect(function() -- Уход мыши с кнопки
    is_moving_down = false
end)LocalPlayer.CharacterAdded:Connect(function(char)
    is_flying = false -- Сбрасываем статус полета при смерти/респавне
    if fly_thread then
        coroutine.yield(fly_thread) -- Попытка остановить предыдущий поток (не всегда надежно)
        fly_thread = nil
    end
    -- Кнопка "Взлететь" должна быть активна
    onof.Text = "Взлететь"
    -- Эти строки в CharacterAdded уже не так критичны, т.к. fly_loop их сбросит
    -- wait(0.7) -- лучше использовать task.wait()
    -- char:FindFirstChildOfClass("Humanoid").PlatformStand = false
    -- char:FindFirstChild("Animate").Disabled = false
end)


plus.MouseButton1Down:Connect(function()
    current_speed = current_speed + 1
    speed_label.Text = tostring(current_speed) -- Обновляем текст лейбла

    if is_flying and fly_thread then -- Если летим и есть активный поток полета
        -- Перезапускаем полет, чтобы применить новую скорость
        is_flying = false -- Останавливаем текущий полет
        -- Дожидаемся завершения старого потока или принудительно останавливаем (если это возможно через эксплойт)
        -- Затем снова включаем
        task.wait(0.1) -- Небольшая пауза для завершения старого потока
        is_flying = true
        local character = LocalPlayer.Character
        local humanoid = character and character:FindFirstChildWhichIsA("Humanoid")
        local target_part = (humanoid.RigType == Enum.HumanoidRigType.R6 and character:FindFirstChild("Torso")) or
                            (humanoid.RigType == Enum.HumanoidRigType.R15 and character:FindFirstChild("UpperTorso"))
        if target_part then
            fly_thread = coroutine.wrap(function()
                start_fly_loop(character, humanoid, target_part)
            end)()
        end
    end
end)

mine.MouseButton1Down:Connect(function()
    if current_speed == 1 then
        speed_label.Text = 'cannot be less than 1'
        task.wait(1) -- Используем task.wait()
        speed_label.Text = tostring(current_speed)
    else
        current_speed = current_speed - 1
        speed_label.Text = tostring(current_speed)

        if is_flying and fly_thread then -- Если летим и есть активный поток полета
            is_flying = false -- Останавливаем текущий полет
            task.wait(0.1)
            is_flying = true
            local character = LocalPlayer.Character
            local humanoid = character and character:FindFirstChildWhichIsA("Humanoid")
            local target_part = (humanoid.RigType == Enum.HumanoidRigType.R6 and character:FindFirstChild("Torso")) or
                                (humanoid.RigType == Enum.HumanoidRigType.R15 and character:FindFirstChild("UpperTorso"))
            if target_part then
                fly_thread = coroutine.wrap(function()
                    start_fly_loop(character, humanoid, target_part)
                end)()
            end
        end
    end
end)

closebutton.MouseButton1Click:Connect(function()
    if is_flying then -- Выключаем полет перед закрытием
        is_flying = false
        -- Дополнительно: можно подождать завершения fly_thread или принудительно его остановить
    end
    main:Destroy()
end)

mini.MouseButton1Click:Connect(function()
    up.Visible = false
    down.Visible = false
    onof.Visible = false
    plus.Visible = false
    speed_label.Visible = false
    mine.Visible = false
    mini.Visible = false
    mini2.Visible = true
    Frame.BackgroundTransparency = 1
    closebutton.Position =  UDim2.new(0, 0, 0, 0) -- Позиция относительно родителя Frame
    closebutton.Size = UDim2.new(0, 45, 0, 28)
    mini2.Position = UDim2.new(0, 44, 0, 0) -- Позиция относительно родителя Frame
end)

mini2.MouseButton1Click:Connect(function()
    up.Visible = true
    down.Visible = true
    onof.Visible = true
    plus.Visible = true
    speed_label.Visible = true
    mine.Visible = true
    mini.Visible = true
    mini2.Visible = false
    Frame.BackgroundTransparency = 0
    closebutton.Position =  UDim2.new(0, 0, 0, 0) -- Вернуть исходную позицию
    mini.Position = UDim2.new(0, 44, 0, 0) -- Вернуть исходную позицию
end)
