destination_channel = client.get_channel(1135168139177496626)
                destination_channel2 = client.get_channel(1135168139177496626)

                for player_name in list_com1:
                    player = discord.utils.get(voice_channel.members, name=player_name)

                    if player:
                        await player.move_to(destination_channel)
                        await kapitan1.move_to(destination_channel)

                for player_name in list_com2:
                    player2 = discord.utils.get(voice_channel.members, name=player_name)
                    if player2:
                        await player2.move_to(destination_channel2)
                        await kapitan2.move_to(destination_channel2)
