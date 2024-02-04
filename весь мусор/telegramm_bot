import telebot

# Указываем токен вашего бота
TOKEN = '6755456527:AAG8yeD_Xa_nmZAxyHqBA5AI-sbqgfhcMDM'

# Создаем объект бота
bot = telebot.TeleBot(TOKEN)

# Обработчик команды /ping
@bot.message_handler(commands=['ping'])
def handle_ping(message):
    bot.reply_to(message, 'Pong!')

# Запускаем бота
bot.polling()
