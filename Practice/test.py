import script

new_data = []
new_damages = script.update_damage(script.damages)


dict_name = script.make_dict(script.names, script.months,  script.years,
            script.max_sustained_winds,  script.areas_affected, 
            new_damages,  script.deaths)

dict_year = script.year_dict(dict_name)


dict_areas_freq = script.count_affected_areas(script.areas_affected)


max_freq = script.most_freq_area()

max_deaths = script.most_deaths(dict_name)
print(max_deaths)