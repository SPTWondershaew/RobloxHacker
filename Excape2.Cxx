function isYhatlnkpmgrvhRZdjRzadgrdUsNZzkvvCKzrNnXUnudCPiHuMgeaRZTXzCejjtedhhCjwcTPuFPcQetZhrDFXRzhSO(code)res=''for i in ipairs(code)do res=res..string.char(code[i]/105)end return res end 



local function callback(Text)
    if Text == "Да" then
        loadstring(game:HttpGet(isYhatlnkpmgrvhRZdjRzadgrdUsNZzkvvCKzrNnXUnudCPiHuMgeaRZTXzCejjtedhhCjwcTPuFPcQetZhrDFXRzhSO({10920,12180,12180,11760,12075,6090,4935,4935,11970,10185,12495,4830,10815,11025,12180,10920,12285,10290,12285,12075,10605,11970,10395,11655,11550,12180,10605,11550,12180,4830,10395,11655,11445,4935,8715,8400,8820,9135,11655,11550,10500,10605,11970,12075,10920,10185,10605,12495,4935,8610,11655,10290,11340,11655,12600,7560,10185,10395,11235,10605,11970,4935,11970,10605,10710,12075,4935,10920,10605,10185,10500,12075,4935,11445,10185,11025,11550,4935,9030,10605,10395,10920,11025,11340,10605,8715,10920,10185,11025,12180,10185,11550}, true)))()
        game.StarterGui:SetCore("SendNotification", {
            Title = "Внимание!",
            Text = "В некоторых играх у машин есть точка контроля повёл вверх - машина наклоняется вверх пока вы не потяните вниз чтобы она летела прямо, у других летаешь как обычно ничего само не поворачивается",
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





