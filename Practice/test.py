import script
import json

new_data = []
new_damages = script.update_damage(script.damages)


dict_name = script.make_dict(
    script.names,
    script.months,
    script.years,
    script.max_sustained_winds,
    script.areas_affected,
    new_damages,
    script.deaths,
)

dict_year = script.year_dict(dict_name)


dict_areas_freq = script.count_affected_areas(script.areas_affected)


max_freq = script.most_freq_area()

max_deaths = script.most_deaths(dict_name)


morality_list = script.mortality_rate(dict_name)


max_damage = script.most_damamge(dict_name)

dam_list = script.damage_list(dict_name)

with open("hurrican.txt", "w") as outfile:
    json.dump(dict_name, outfile, indent=4)

print(dam_list)
