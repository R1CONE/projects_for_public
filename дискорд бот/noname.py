import disnake
from disnake.ext import commands
from disnake.ui import View

intents = disnake.Intents.all()

bot = commands.Bot(command_prefix='/', intents=intents, test_guilds=[1134449858351210518])

@bot.event
async def on_ready():
    print('Бот готов')

@bot.command()
async def sum(ctx, x: int, y: int):
    print(x + y)


@bot.command()
async def games(ctx):
    view = View(timeout=None)
    view.add_item(SelectGames())
    embed = disnake.Embed(color=0x2F3136)
    embed.set_author(name="Game roles:")
    embed.description = "Under this post, you can choose your role by clicking on the appropriate"
    embed.set_image(url="https://i.imgur.com/QzB7q9J.png")
    await ctx.send(embed=embed, view=view)

class SelectGames(disnake.ui.Select):
    def __init__(self):
        options = [
            disnake.SelectOption(label="Керри(poz 1)", value="1139941271935385630"),
            disnake.SelectOption(label="Мидер(poz 2)", value="1139941729273905183"),
            disnake.SelectOption(label="Оффлейнер(poz 3)", value="1139942541714784308"),
            disnake.SelectOption(label="Роумер(poz 4)", value="1139942666314985572"),
            disnake.SelectOption(label="Саппорт(poz 5)", value="1139942872985124875")]
        super().__init__(placeholder="Select a position", options=options, custom_id="pos", min_values=1, max_values=5)

    async def callback(self, interaction: disnake.MessageInteraction):
        await interaction.response.defer()
        all_roles = {1139941271935385630, 1139941729273905183, 1139942541714784308, 1139942666314985572,1139942872985124875}
        to_remove = []
        to_add = []

        if not interaction.values:
            for role_id in all_roles:
                role = interaction.guild.get_role(role_id)
                to_remove.append(role)

            await interaction.author.remove_roles(*to_remove, reason="Removed all roles")
        else:
            chosen_roles = {int(value) for value in interaction.values}
            ids_to_remove = all_roles - chosen_roles

            for role_id in ids_to_remove:
                role = interaction.guild.get_role(role_id)
                to_remove.append(role)

            for role_id in chosen_roles:
                role = interaction.guild.get_role(role_id)
                to_add.append(role)

            await interaction.author.remove_roles(*to_remove, reason="Removed roles")
            await interaction.author.add_roles(*to_add, reason="Added roles")

@bot.event
async def on_connect():
    # Добавление view к сообщению с указанным ID
    message_id = 1144005624611471380
    view = View(timeout=None)
    view.add_item(SelectGames())
    bot.add_view(view, message_id=message_id)


    


bot.run('MTE1MzMzMzA2MTkzNzgwNzQ3MA.Gu6AGZ.d6OJ1yyOoTiKVHGBwGdDbuc1MoVuVmBmL_gT7o')
