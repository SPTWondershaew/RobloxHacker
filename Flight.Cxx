local function callback(Text)
    if Text == "Да" then
        loadstring(game:HttpGet("https://raw.githubusercontent.com/SPTWondershaew/FlyRoblox/main/ExtFly.Cxx", true))()
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
