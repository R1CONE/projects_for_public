import discord
from discord.ext import commands
import random
import keep_alive

global kapitan1_id, kapitan2_id, list_com1,list_voice1, list_voice2, list_com2, kapitan1, kapitan2, target_channel_id, message, target_channel, kap_name, kap_name2, player1_id, kapitan1_role_names, kapitan2_role_names
global player1_role_names, player2_role_names, player3_role_names, player4_role_names, player5_role_names, player6_role_names, player7_role_names, player8_role_names, player_role_names


player1_id = None
player2_id = None
player3_id = None
player4_id = None
player5_id = None
player6_id = None
player7_id = None



client = discord.Client(intents=discord.Intents.all())

target_channel_id = 1141439369635438722
kap = 1 
kapitan1 = '' 
kapitan2 = ''
voice_channel = ''
members = []

@client.event
async def on_ready():
    print('Бот готов')


@client.event
async def on_voice_state_update(member, before, after):
    global voice_channel
    voice_channel = client.get_channel(1141441569560481802)
    if after.channel and after.channel.id == 1141441569560481802 and after.channel != before.channel:
        if len(after.channel.members) == 10:
            await list_members(after.channel)

async def list_members(voice_channel):
    global kapitan2_id, kapitan1_id, list_com1, list_com2, players, kom, emoji_mapping, emoji, kap_name, kap_name2, player1_id, player1_id, kapitan1_role_names, kapitan2_role_names, player_role_names, list_voice1, list_voice2
    list_com1 = []
    list_com2 = []

    list_voice2 = []
    list_voice1 = []
    
    global kapitan1_id, kapitan2_id
    members = voice_channel.members
    member_names = [member.name for member in members]
    kapitan_players = random.sample(member_names, 2)
    kapitan1 = kapitan_players[0]
    kapitan2 = kapitan_players[1]
    

    for member in members:
        if member.name == kapitan1:
            kapitan1_id = member.id
        elif member.name == kapitan2:
            kapitan2_id = member.id
    

    players = [player for player in member_names if player not in kapitan_players]

    player1 = players[0]
    player2 = players[1]
    player3 = players[2]
    player4 = players[3]
    player5 = players[4]
    player6 = players[5]
    player7 = players[6]
    player8 = players[7]

    for member in members:
        if member.name == player1:
            player1_id = member.id

    for member in members:
        if member.name == player2:
            player2_id = member.id

    for member in members:
        if member.name == player3:
            player3_id = member.id

    for member in members:
        if member.name == player4:
            player4_id = member.id

    for member in members:
        if member.name == player5:
            player5_id = member.id

    for member in members:
        if member.name == player6:
            player6_id = member.id

    for member in members:
        if member.name == player7:
            player7_id = member.id

    for member in members:
        if member.name == player8:
            player8_id = member.id

    roles = [1139941271935385630, 1139941729273905183, 1139942541714784308, 1139942666314985572, 1139942872985124875]

    kapitan1_member = discord.utils.get(members, id=kapitan1_id)
    kapitan2_member = discord.utils.get(members, id=kapitan2_id)
    player1_member = discord.utils.get(members, id=player1_id)
    player2_member = discord.utils.get(members, id=player2_id)
    player3_member = discord.utils.get(members, id=player3_id)
    player4_member = discord.utils.get(members, id=player4_id)
    player5_member = discord.utils.get(members, id=player5_id)
    player6_member = discord.utils.get(members, id=player6_id)
    player7_member = discord.utils.get(members, id=player7_id)
    player8_member = discord.utils.get(members, id=player8_id)


    

    player1_roles = [role for role in player1_member.roles if role.id in roles]
    player2_roles = [role for role in player2_member.roles if role.id in roles]
    player3_roles = [role for role in player3_member.roles if role.id in roles]
    player4_roles = [role for role in player4_member.roles if role.id in roles]
    player5_roles = [role for role in player5_member.roles if role.id in roles]
    player6_roles = [role for role in player6_member.roles if role.id in roles]
    player7_roles = [role for role in player7_member.roles if role.id in roles]
    player8_roles = [role for role in player8_member.roles if role.id in roles]
    kapitan1_roles = [role for role in kapitan1_member.roles if role.id in roles]
    kapitan2_roles = [role for role in kapitan2_member.roles if role.id in roles]
    
    player1_role_names = ", ".join([role.name for role in player1_roles])
    player2_role_names = ", ".join([role.name for role in player2_roles])
    player3_role_names = ", ".join([role.name for role in player3_roles])
    player4_role_names = ", ".join([role.name for role in player4_roles])
    player5_role_names = ", ".join([role.name for role in player5_roles])
    player6_role_names = ", ".join([role.name for role in player6_roles])
    player7_role_names = ", ".join([role.name for role in player7_roles])
    player8_role_names = ", ".join([role.name for role in player8_roles])
    kapitan1_role_names = ", ".join([role.name for role in kapitan1_roles])
    kapitan2_role_names = ", ".join([role.name for role in kapitan2_roles])
    

    player_role_names = [player1_role_names, player2_role_names, player3_role_names, player4_role_names, player5_role_names, player6_role_names, player7_role_names, player8_role_names]
    

    target_channel_id = 1141439369635438722 # Замените это на ID нужного вам канала  
    target_channel = client.get_channel(target_channel_id)

    embed = discord.Embed(title="Добро пожаловать на фейсит", description="Капитаны, пикайте игроков", color=discord.Color.purple())
    embed.set_thumbnail(url='https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTvbwstNLPp77vL3VG5G3H6EVUt705BVF-sEQ&usqp=CAU')
    embed.set_author(name="Dota Faceit")
    embed.add_field(name=f'Капитан 1 - {kapitan1} - {kapitan1_role_names} ', value=f'Игроки команды 1: {list_com1}')
    embed.add_field(name=f'Капитан 2 - {kapitan2} - {kapitan2_role_names}', value=f'Игроки команды 2: {list_com2}')

    kap_name = kapitan1
    kap_name2 = kapitan2

    if players:
        embed.add_field(name='Не пикнутые игроки:', value='\n'.join([f'{i + 1} - {players[i]} - {player_role_names[i]}' for i in range(len(players))]), inline=False)
    else:
        embed.add_field(name='Не пикнутые игроки:', value='Все игроки уже выбраны', inline=False)
    
    embed.set_footer(text="чтобы пикнуть игрока, клацните на эмодзи его номера")
    
    message = await target_channel.send(embed=embed)

    emoji = ['\u0031\uFE0F\u20E3', '\u0032\uFE0F\u20E3', '\u0033\uFE0F\u20E3', '\u0034\uFE0F\u20E3', '\u0035\uFE0F\u20E3', '\u0036\uFE0F\u20E3', '\u0037\uFE0F\u20E3', '\u0038\uFE0F\u20E3']
    
    await message.add_reaction('\u0031\uFE0F\u20E3')
    await message.add_reaction('\u0032\uFE0F\u20E3')
    await message.add_reaction('\u0033\uFE0F\u20E3')
    await message.add_reaction('\u0034\uFE0F\u20E3')
    await message.add_reaction('\u0035\uFE0F\u20E3')
    await message.add_reaction('\u0036\uFE0F\u20E3')
    await message.add_reaction('\u0037\uFE0F\u20E3')
    await message.add_reaction('\u0038\uFE0F\u20E3')

    
    

@client.event
async def on_reaction_add(reaction, user):
    
    global list_voice_1, list_voice_2, kapitan1_id,kapitan2_id,  list_com1, list_com2,kapitan1,kapitan2, target_channel_id, message,target_channel, kapitan1, kapitan2, kap, voice_channel, kap_name, kap_name2, kapitan1_role_names, kapitan2_role_names, list_voice2, list_voice1, voice_channel, voice_channel_id
    kap 
    
    voice_channel = client.get_channel(1141441569560481802)

    
    print(kapitan1, kapitan2)

    if user.id == kapitan1_id:
        if kap == 1:
            if str(reaction) in emoji:
                emoji_index = emoji.index(str(reaction))

                selected_player = players[emoji_index]
                
                if selected_player in list_com2:
                    target_channel = client.get_channel(target_channel_id)
                    await target_channel.send(f'Игрок {selected_player} уже выбран в команду 2')
                else:
                    target_channel_id = 1141439369635438722
                    target_channel = client.get_channel(target_channel_id)
                    await target_channel.send(f'Капитан 1 выбрал игрока {selected_player} в команду 1')
                    if selected_player in players:
                        players.remove(selected_player)
                        
                        selected_player_and_role = selected_player + ' - ' + player_role_names[emoji_index]
                        

                    
                    list_voice1 = []
                    list_com1.append(selected_player_and_role)
                    list_voice1.append(selected_player)
                    
                    
                    new_embed = discord.Embed(title="Выбирает первый капитан", description="Капитаны, пикайте игроков", color=discord.Color.purple())
                    new_embed.set_thumbnail(url='https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTvbwstNLPp77vL3VG5G3H6EVUt705BVF-sEQ&usqp=CAU')
                    new_embed.set_author(name="Dota Faceit")
                    
                    new_embed.add_field(name=f'Капитан 1 - {kap_name}  - {kapitan1_role_names}', value= f'Игроки комманды 1: {list_com1}')
                    new_embed.add_field(name=f'Капитан 2 - {kap_name2} - {kapitan2_role_names}', value= f'Игроки комманды 2: {list_com2}')

                    if players:
                        new_embed.add_field(name='Не пикнутые игроки:', value='\n'.join([f'{i + 1} - {players[i]} - {player_role_names[i]}' for i in range(len(players))]), inline=False)
                    else:
                        new_embed.add_field(name='Готово!', value='Good luck, have fun!', inline=False)
    
                    new_embed.set_footer(text="что бы пикнуть игрока, кажмите на эмодзи его номера")

                    message = await target_channel.send(embed=new_embed)

                    len_play = len(players)

                    reactions_to_add = emoji[:len_play]

                    for reaction in reactions_to_add:
                        await message.add_reaction(reaction)
                        
                    kap = 2
                    
                    
            else:
                target_channel = client.get_channel(target_channel_id)  # Исправление: добавляем получение канала
                await target_channel.send(f'Игрок {selected_player} уже выбран в команду 2')
        elif kap == 2:
            await target_channel.send(f'Сейчас выбирает другой капитан')


    if user.id == kapitan2_id:
        if kap == 2:
            if str(reaction) in emoji:
                emoji_index = emoji.index(str(reaction))

                selected_player = players[emoji_index]
                
                if selected_player in list_com1:
                    target_channel = client.get_channel(target_channel_id)
                    await target_channel.send(f'Игрок {selected_player} уже выбран в команду 1')
                else:
                    target_channel_id = 1141439369635438722
                    target_channel = client.get_channel(target_channel_id)
                    await target_channel.send(f'Капитан 2 выбрал игрока {selected_player} в команду 2')
                    if selected_player in players:
                        players.remove(selected_player)
                        
                    selected_player_and_role = selected_player + ' - ' + player_role_names[emoji_index]

                    
                    list_voice2 = []
                    list_com2.append(selected_player_and_role)
                    list_voice2.append(selected_player)
                    
                    new_embed = discord.Embed(title="Выбирает второй капитан", description="Капитаны, пикайте игроков", color=discord.Color.purple())
                    new_embed.set_thumbnail(url='https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTvbwstNLPp77vL3VG5G3H6EVUt705BVF-sEQ&usqp=CAU')
                    new_embed.set_author(name="Dota Faceit")
                    new_embed.add_field(name=f'Капитан 1 - {kap_name} - {kapitan1_role_names}', value= f'Игроки комманды 1: {list_com1}')
                    new_embed.add_field(name=f'Капитан 2 - {kap_name2} - {kapitan2_role_names}', value= f'Игроки комманды 2: {list_com2}')

                    if players:
                        new_embed.add_field(name='Не пикнутые игроки:', value='\n'.join([f'{i + 1} - {players[i]} - {player_role_names[i]}' for i in range(len(players))]), inline=False)
                    else:
                        new_embed.add_field(name='Не пикнутые игроки:', value='Все игроки уже выбраны', inline=False)
    
                    new_embed.set_footer(text="что бы пикнуть игрока, кажмите на эмодзи его номера")

                    message = await target_channel.send(embed=new_embed)
                    
                    len_play = len(players)

                    reactions_to_add = emoji[:len_play]
                    
                    for reaction in reactions_to_add:
                        await message.add_reaction(reaction)

                    kap = 1

                                        
                    

                    
                    
    
                    
            else:
                target_channel = client.get_channel(1141439369635438722)  # Исправление: добавляем получение канала
                await target_channel.send(f'Игрок {selected_player} уже выбран в команду 1')
        elif kap == 1:
            await target_channel.send(f'Сейчас выбирает другой капитан')

    if len(list_com1) == 4 and len(list_com2) == 4:
        kapitan1_voice_channel_id = 1141441658945282090
        kapitan2_voice_channel_id = 1141441718164672652

        destination_channel = client.get_channel(kapitan1_voice_channel_id)
        destination_channel2 = client.get_channel(kapitan2_voice_channel_id)
        
        cleaned_list1 = [item.split(' ')[0] for item in list_com1]
        cleaned_list2 = [item.split(' ')[0] for item in list_com2]

       

        
        player1 = discord.utils.get(voice_channel.members, name=cleaned_list1[0])
        await player1.move_to(destination_channel)

        player2 = discord.utils.get(voice_channel.members, name=cleaned_list1[1])
        await player2.move_to(destination_channel)

        player3 = discord.utils.get(voice_channel.members, name=cleaned_list1[2])
        await player3.move_to(destination_channel)

        player4 = discord.utils.get(voice_channel.members, name=cleaned_list1[3])
        await player4.move_to(destination_channel)

        
        player5 = discord.utils.get(voice_channel.members, name=cleaned_list2[0])
        await player5.move_to(destination_channel2)

        player6 = discord.utils.get(voice_channel.members, name=cleaned_list2[1])
        await player6.move_to(destination_channel2)

        player7 = discord.utils.get(voice_channel.members, name=cleaned_list2[2])
        await player7.move_to(destination_channel2)

        player8 = discord.utils.get(voice_channel.members, name=cleaned_list2[3])
        await player8.move_to(destination_channel2)
        

        
            


        kapitan2_member = discord.utils.get(voice_channel.members, name=kap_name2)
        if kapitan2_member:
            await kapitan2_member.move_to(destination_channel2)

        kapitan1_member = discord.utils.get(voice_channel.members, name=kap_name)
        if kapitan1_member:
            await kapitan1_member.move_to(destination_channel)



keep_alive.keep_alive() #что бы это работало надо импортировать keep_alive и вызывать его надо под конец кода с 2мя обзацами отступа 



client.run('') #тут ваш токен
