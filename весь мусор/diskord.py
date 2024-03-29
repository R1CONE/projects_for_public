
from discord.ext import commands
import discord
import asyncio
 
client = commands.Bot(command_prefix='-', intents = discord.Intents.all(), case_insensitive=True) 
bot.remove_command("help")
 
 
@bot.event
async def on_ready():
    print('Бот запущен')
 
 
@bot.command()
async def sum(ctx, x: int, y: int):
    await ctx.send(x+y)
 
 
@bot.command()
async def clear(ctx, count: int):
    await ctx.channel.purge(limit=count+1)
    await ctx.send(f"Было удаленно {count} сообщений")
 
 
@bot.command()
async def help(ctx):
    await ctx.send("Я подсказка")
 
 
@bot.command()
async def ban(ctx, member: discord.Member = None, time = None, *, reason: str = None):
    async def unb(member):
        users = await ctx.guild.bans()
        for ban_user in users:
            if ban_user.user == member:
                await ctx.guild.unban(ban_user.user)
 
    if member:
        if time: 
            time_letter = time[-1:] 
            time_numbers = int(time[:-1]) 
 
            def t(time_letter): 
                if time_letter == 's':
                    return 1
                if time_letter == 'm':
                    return 60
                if time_letter == 'h':
                    return 60*60
                if time_letter == 'd':
                    return 60*60*24
            if reason:
                await member.ban(reason=reason)
                await ctx.send(embed=discord.Embed(description=f'Пользователь {member.mention} был забанен \nВремя: {time} \nПричина: {reason}' ))
 
                await asyncio.sleep(time_numbers*t(time_letter))
 
                await unb(member)
                await ctx.send(f'Польнзователь {member.mention} разбанен')
            else:
                await member.ban()
                await ctx.send(embed=discord.Embed(description=f'Пользователь {member.mention} был забанен \nВремя: {time}'))
 
                await asyncio.sleep(time_numbers*t(time_letter))
 
                await unb(member)
                await ctx.send(f'Польнзователь {member.mention} разбанен')
        else:
            await member.ban()
            await ctx.send(embed=discord.Embed(description=f'Пользователь {member.mention} был забанен'))
    else: 
        await ctx.send('Введите имя пользователя')
 
 
@bot.command()
async def unban(ctx, id_: int = None):
    if id_:
        banned_users = await ctx.guild.bans()
        member_full = bot.get_user(id=id_)
        for ban in banned_users:
            if ban.user == member_full:
                await ctx.guild.unban(ban.user)
        await ctx.send('Пользователь разбанен')
    else:
        await ctx.send('Введите айди')
 
 
@bot.command()
async def kick(ctx, member: discord.Member = None, *, reason:str =None):
    if member:
        if reason:
            await member.kick(reason=reason)
            await ctx.send(embed=discord.Embed(description=f'Пользователь {member.mention} был кикнут \nПричина: {reason}' ))
        else:
            await member.kick()
            await ctx.send(embed=discord.Embed(description=f'Пользователь {member.mention} был кикнут'))
    else: 
        await ctx.send('Введите имя пользователя')
 

bot.run('MTEyMTA4ODgzMzc1MzIwMjc0OA.GiC9xm.0_AUa55dfC_k5OYrnW8-Cgq7pEA-NVujCrjOdQ')



async def join (ctx):
    global voice
    channel = ctx.message.author.voice.channel
    voice = get(client.voice.clients, guild = ctx.guild)

    if voice and voice.is_connected():
        await voice.move_to(channe)
    else:
        voice = await channel.connect()
        await ctx.send('Я ебал')

async def leave (ctx):
    
    channel = ctx.message.author.voice.channel
    voice = get(client.voice.clients, guild = ctx.guild)

    if voice and voice.is_connected():
        await voice.disconnect
    else:
        voice = await connect.channel()
        await ctx.send('Я ебал')



emb = discord.Embed(title='Your title', colour=discord.Colour.purple(), url='https://time.is/ru/Kazakhstan')
    
    emb.set_author(name=client.user.name, icon_url=client.user.avatar)

    emb.set_footer(text=ctx.author.name, icon_url=ctx.author.avatar_url)

    # Replace these URLs with the URLs of the images you want to use
    emb.set_image(url='https://example.com/image_url.jpg')
    emb.set_thumbnail(url='https://example.com/thumbnail_url.jpg')

    now_date = datetime.datetime.now()
    emb.add_field(name='Time', value=now_date)

    await ctx.send(embed=emb)
