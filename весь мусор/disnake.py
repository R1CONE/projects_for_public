@bot.command()
@commands.has_permissions(administrator=True)
async def role_1(ctx):
    author = ctx.message.author 
    server = bot.get_guild('1112412830721900675')
    admin = server.get_role('1133492100961402891')
    await author.add_roles(admin)

import disnake
from datetime import datetime
from disnake.ext import commands
import qrcode

bot = commands.Bot(command_prefix='!', intents=disnake.Intents.all())


class Sell(disnake.ui.View):
    def __init__(self):
        super().__init__(timeout=20.0)

    @disnake.ui.button(label='Продать', style=disnake.ButtonStyle.green)
    async def confirm(self, button: disnake.ui.Button, inter: disnake.CommandInteraction):
        await inter.response.send_message('Вы продали арт')
        self.stop()

    @disnake.ui.button(label='Отказаться', style=disnake.ButtonStyle.red)
    async def cancel(self, button: disnake.ui.Button, inter: disnake.CommandInteraction):
        await inter.response.send_message('Вы отказались продавать арт')
        self.stop()


@bot.event
async def on_ready():
    activity = disnake.Activity(name='очке пальчиком', type=disnake.ActivityType.playing)
    await bot.change_presence(status=disnake.Status.online, activity=activity)
    print('Готово')


@bot.command()
async def hello(ctx):
    author = ctx.author
    server = ctx.guild
    await ctx.send(f'Привет {author.name}, ты раб на сервере {server.name}')


@bot.command()
@commands.has_permissions(administrator=True)
async def role(ctx, custom_role: disnake.Role):
    author = ctx.author
    await author.add_roles(custom_role)


@bot.event
async def on_member_join(member):
    channel = member.guild.system_channel

    emb = disnake.Embed(
        title=f'Привет {member}',
        description="ты бла-бла-бла",
        color=disnake.Colour.dark_purple(),
        timestamp=datetime.now()
    )

    await channel.send(embed=emb)


@bot.command()
async def clear(ctx, amount: int):
    await ctx.channel.purge(limit=amount + 1)


@bot.command()
async def qrc(ctx, code: str):
    await ctx.channel.purge(limit=1)

    img = qrcode.make(code)
    img.save('img/qrcode.png')
    await ctx.send(file=disnake.File(fp='img/qrcode.png'))


@bot.command()
async def sell(ctx, art):
    view = Sell()

    await ctx.send(f'Вы уверены, что хотите продать {art}?', view=view)






bot.run('MTEyMTA4ODgzMzc1MzIwMjc0OA.GqkxqY.eTrgMRE99gDLiBgCuXMLcHwdsUjnd5OF1jBqRM')
