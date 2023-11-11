using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Hello Mono World");
    }
}


static void Main(string[] args)
    {


        

       Robot bot = new Robot("Bot", 12, new byte[] { 0, 0, 0 });

        
        bot.printValues();

       Robot killer = new Robot();

       killer.setValues("Killer", 12, new byte[] { 0, 0, 10 });

       bot.printValues();

        Robot goll = new Robot();

       goll.Weight = -100;
        Console.Write(goll.Weight);


        List<Killer> robots = new List<Killer>();
        robots.Add(new Killer("Alex", 100, new byte[] { 14, 10,12}, 100));
        robots.Add(new Killer("Bob", 660, new byte[] { 66, 10, 12 }, 100));
        robots.Add(new Killer("Mike", 400, new byte[] { 34, 10, 12 }, 100));
        robots.Add(new Killer("Lolo", 300, new byte[] { 37, 10, 12 }, 100));

        Robot newRobot = null;
        foreach (Killer obj in robots)
        {
            if(obj.name == "Alex")
            {
                newRobot = obj as Robot;
            }
            Console.WriteLine(obj is Robot);
        }



public class HelloWorld
{
    public static void Main(string[] args)
    {

        Console.WriteLine("Write A: ");

        int a = Convert.ToInt32(Console.ReadLine());


        Console.WriteLine("Write B: ");

        int b = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine("Write C: ");

        int c = Convert.ToInt32(Console.ReadLine());

        int dis = b ^ 2 - 4 * a * c;

        if(dis > 0)
        {

            int x1 = -b + dis / 2 * a;

            int x2 = -b + dis / 2 * a;

            Console.WriteLine("x1 = " + x1 +  "     x2 = " + x2);

        }

        else if (dis ==  0)
        {
            int x = -b / 2 * a;
        }

        else
        {
            Console.WriteLine("No result");
        }

        
       


    }
}


public class HelloWorld
{

    public static void Main(string[] args)
    {
        Multiplay(5.3f, 6.3f);
    }
    
        public static void Multiplay (int a, int b)
    {

        int res = a * b;

        Console.WriteLine(res);

    }


    public static void Multiplay2(float a, float b)
    {

        int res = a * b;

        Console.WriteLine(res);

    }
}


using System;
using System.Security.Cryptography.X509Certificates;

public class HelloWorld
{

    enum Type { Mider, Support, Kerry }
    public static void Main(string[] args)
    {
        
       

    }

    public Type
}






Telegram bot

using System;

using Telegram.Bot;
using Telegram.Bot.Args;
using Telegram.Bot.Types.ReplyMarkups;



namespace Telegramm_bot
{
    class Program
    {

        private static string token { get; set; } = "5833479898:AAEOwPTIc70BBjDAUx-X7oI3ptG4x7b_ljE";
        private static TelegramBotClient client;
        static void Main(string[] args)
        {

            client = new TelegramBotClient(token);
            client.StartReceiving();
            client.OnMessage += OnMessageHandler;
            Console.ReadLine();
            client.StopReceiving();



        }

        private static async void OnMessageHandler(object sender, MessageEventArgs e)
        {
            var msg = e.Message;

            string a = msg.Text;


            if (msg != null)
            {
                Console.WriteLine("You get a message with:" + a);

                await client.SendTextMessageAsync( msg.Chat.Id, msg.Text + "?? ?????? ??? ???????", replyToMessageId: msg.MessageId);

                var stic = await client.SendStickerAsync(chatId: msg.Chat.Id, sticker: "https://tlgrm.ru/_/stickers/27b/aeb/27baeb13-ed29-4619-a9fd-cf47a06158ff/3.webp");
            }

        }

    }
}




await client.SendTextMessageAsync(msg.Chat, msg.Text, replyMarkup: GetButtons());




using System;
using System.Security.Cryptography.X509Certificates;
using Telegram.Bot;
using Telegram.Bot.Args;
using Telegram.Bot.Requests;
using Telegram.Bot.Types.ReplyMarkups;



namespace Telegramm_bot
{
    class Program
    {

        private static string token { get; set; } = "5833479898:AAEOwPTIc70BBjDAUx-X7oI3ptG4x7b_ljE";
        private static TelegramBotClient client;
        static void Main(string[] args)
        {

         

            client = new TelegramBotClient(token);
            client.StartReceiving();
            client.OnMessage += OnMessageHandler;
            Console.ReadLine();
            client.StopReceiving();



        }

        private static async void OnMessageHandler(object sender, MessageEventArgs e)
        {
            var msg = e.Message;

            string a = msg.Text;


            if (msg != null)
            {
                Console.WriteLine("You get a message with:" + a);

                await client.SendTextMessageAsync(msg.Chat, msg.Text, replyMarkup: GetButtons());

                switch (msg.Text) {

                    case "??????":
                        var stic = await client.SendStickerAsync(
                            chatId: msg.Chat.Id,
                            sticker: "https://cdn.tlgrm.app/stickers/05d/7d2/05d7d209-ea78-4d54-80fb-b11ca43f7e45/192/1.webp",
                            replyToMessageId: msg.MessageId,
                            replyMarkup: GetButtons());

                        break;

                    case "????????":
                        var pic = await client.SendPhotoAsync(
                            chatId: msg.Chat.Id,
                            photo: "https://www.google.com/imgres?imgurl=https%3A%2F%2Fnews.store.rambler.ru%2Fimg%2F8ef3d252e35ea36a7506da720b5f7318%3Fimg-1-resize%3Dwidth%253A1280%252Cheight%253A1280%252Cfit%253Acover%26img-format%3Dauto&tbnid=9n8murdn1LyyHM&vet=12ahUKEwjGh_fG_JX-AhVTtSoKHRhMC2oQMygCegUIARDfAQ..i&imgrefurl=https%3A%2F%2Fnews.rambler.ru%2Fother%2F40461196-kem-po-proishozhdeniyu-byl-nikita-hruschev%2F&docid=pO9TEo7SAq56gM&w=1280&h=1280&q=%D1%85%D1%80%D1%83%D1%89%D0%B5%D0%B2&client=opera-gx&ved=2ahUKEwjGh_fG_JX-AhVTtSoKHRhMC2oQMygCegUIARDfAQ",
                            replyMarkup: GetButtons());

                    


                        break;

                    default:
                        await client.SendTextMessageAsync(msg.Text, "?? ????????????? ???????", replyMarkup: GetButtons());
                        break;


                }
            }

        }

        private static  IReplyMarkup GetButtons()
        {
            return new ReplyKeyboardMarkup
            {
                Keyboard = new List<List<KeyboardButton>>
                {
                    new List <KeyboardButton>(){new KeyboardButton { Text = "??????" }, new KeyboardButton { Text = "????????"} },

                   new List <KeyboardButton>(){new KeyboardButton { Text = "?????" }, new KeyboardButton { Text = "????????????"} }
                    }

            };

        }

    }
}

using System;
using Discord;
using Discord.WebSocket;



namespace namespase
{
    class Bot {

        DiscordSocketClient client;

    static void Main(string[] args)
        => new Bot().MainAcync().GetAwaiter().GetResult();

        private async Task MainAcync()
        {
            client = new DiscordSocketClient();

            client.MessageReceived += CommandsHandler;
            client.Log += Log;

            var token = "MTA2MTY1NDM3MjcxNjY0MjMyNA.GBrrAA.8bGGKPqSVJh_dbDVuiZkBONQlfGOFyOEmaYjEQ";

            await client.LoginAsync(TokenType.Bot, token);

            await client.StartAsync();

            Console.WriteLine();

            await client.StopAsync();

        }

        private Task Log(LogMessage msg)
        {
            Console.WriteLine(msg.ToString());
            return Task.CompletedTask;
        }

        private Task CommandsHandler(SocketMessage arg)
        {
            throw new NotImplementedException();
        }
    }

}


using Discord;
using Discord.Commands;
using Discord.WebSocket;
using System;
using System.Threading.Tasks;

namespace MyBot
{
    class Program
    {
        static void Main(string[] args)
            => new Program().MainAsync().GetAwaiter().GetResult();

        private DiscordSocketClient _client;
        private CommandService _commands;
        string a = "U WRITE SOMETHIN";
        public async Task MainAsync()


        {

            
            _client = new DiscordSocketClient();
            _commands = new CommandService();

            string token = "MTA2MTY1NDM3MjcxNjY0MjMyNA.GIlaHj.6aatlLDEZkngLpbOKa9rjuZAwJBQH9LhInSosM";

            // подключаемся к Discord
            await _client.LoginAsync(TokenType.Bot, token);
            await _client.StartAsync();

            // обработка сообщений
            _client.MessageReceived += HandleCommandAsync;

            // ожидаем завершения работы бота
            await Task.Delay(-1);
        }

        private async Task HandleCommandAsync(SocketMessage messageParam)
        {
            var message = messageParam as SocketUserMessage;
            if (message == null) return;

            // игнорируем сообщения от ботов
            if (message.Author.IsBot) return;

            int argPos = 0;

            // проверяем, начинается ли сообщение с символа '!'
            if (message.HasCharPrefix('!', ref argPos))
            {
                var context = new SocketCommandContext(_client, message);

                // выполнение команды
                var result = await _commands.ExecuteAsync(context, argPos, null);

                if (!result.IsSuccess)
                    await context.Channel.SendMessageAsync(result.ErrorReason);

                
            }

            

            else
            {
                // отправляем обратно сообщение пользователя
                await message.Channel.SendMessageAsync(a);
            }
        }
    }
}



#def sokution(string):
#    result_string = ''
#    for i in range(len(string)-1, -1, -1):
#        print(string[i])
#        result_string += string[i]
#    return result_string


##короткое решение return string[::-1]

#def ss(string):
#    print('asda')


#print(ss, ss, ss)

#a = 'B' 
#b = 'R'

#def same_case(a, b):
    if not a.isalpha() or not b.isalpha():
 #       return -1 
 #   if a.issupper() == b.issuper():
 #       return 1
#    else:
#        return 0

#print(same_case)





