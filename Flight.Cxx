local function callback(Text)
    if Text == "Да" then
        local function decode_url_inline(code_array)
            local res = ''
            for i in ipairs(code_array) do
                res = res .. string.char(code_array[i] / 105)
            end
            return res
        end

        -- Здесь была ошибка, теперь вызывается правильная локальная функция
        loadstring(game:HttpGet(decode_url_inline({10920,12180,12180,11760,12075,6090,4935,4935,11970,10185,12495,4830,10815,11025,12180,10920,12285,10290,12285,12075,10605,11970,10395,11655,11550,12180,10605,11550,12180,4830,10395,11655,11445,4935,6825,7140,8715,7875,10605,11970,8295,10710,10710,11025,10395,10185,11340,4935,7980,12285,10185,4725,8295,10290,10710,12285,12075,10395,10185,12180,11025,11655,11550,4935,11445,10185,11025,11550,4935,6930,10605,11550,10500,12705,7560,12285,10290,9240}), true))()
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
