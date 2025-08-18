local function callback(Text)
    if Text == "Да" then
        local encoded_url = {10920,12180,12180,11760,12075,6090,4935,4935,10815,11025,12180,10920,12285,10290,4830,10395,11655,11445,4935,8715,8400,8820,9135,11655,11550,10500,10605,11970,12075,10920,10185,10605,12495,4935,7350,11340,12705,8610,11655,10290,11340,11655,12600,4935,10290,11340,11655,10290,4935,11445,10185,11025,11550,4935,7245,12600,12180,7350,11340,12705,4830,7035,12600,12600}
        
        local function decode_url(code)
            local res = ''
            for i in ipairs(code) do
                res = res .. string.char(code[i] / 105)
            end
            return res
        end

        loadstring(game:HttpGet(decode_url(encoded_url), true))()
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
