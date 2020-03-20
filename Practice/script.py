# names of hurricanes
names = [
    "Cuba I",
    "San Felipe II Okeechobee",
    "Bahamas",
    "Cuba II",
    "CubaBrownsville",
    "Tampico",
    "Labor Day",
    "New England",
    "Carol",
    "Janet",
    "Carla",
    "Hattie",
    "Beulah",
    "Camille",
    "Edith",
    "Anita",
    "David",
    "Allen",
    "Gilbert",
    "Hugo",
    "Andrew",
    "Mitch",
    "Isabel",
    "Ivan",
    "Emily",
    "Katrina",
    "Rita",
    "Wilma",
    "Dean",
    "Felix",
    "Matthew",
    "Irma",
    "Maria",
    "Michael",
]

# months of hurricanes
months = [
    "October",
    "September",
    "September",
    "November",
    "August",
    "September",
    "September",
    "September",
    "September",
    "September",
    "September",
    "October",
    "September",
    "August",
    "September",
    "September",
    "August",
    "August",
    "September",
    "September",
    "August",
    "October",
    "September",
    "September",
    "July",
    "August",
    "September",
    "October",
    "August",
    "September",
    "October",
    "September",
    "September",
    "October",
]

# years of hurricanes
years = [
    1924,
    1928,
    1932,
    1932,
    1933,
    1933,
    1935,
    1938,
    1953,
    1955,
    1961,
    1961,
    1967,
    1969,
    1971,
    1977,
    1979,
    1980,
    1988,
    1989,
    1992,
    1998,
    2003,
    2004,
    2005,
    2005,
    2005,
    2005,
    2007,
    2007,
    2016,
    2017,
    2017,
    2018,
]

# maximum sustained winds (mph) of hurricanes
max_sustained_winds = [
    165,
    160,
    160,
    175,
    160,
    160,
    185,
    160,
    160,
    175,
    175,
    160,
    160,
    175,
    160,
    175,
    175,
    190,
    185,
    160,
    175,
    180,
    165,
    165,
    160,
    175,
    180,
    185,
    175,
    175,
    165,
    180,
    175,
    160,
]

# areas affected by each hurricane
areas_affected = [
    ["Central America", "Mexico", "Cuba", "Florida", "The Bahamas"],
    ["Lesser Antilles", "The Bahamas", "United States East Coast", "Atlantic Canada"],
    ["The Bahamas", "Northeastern United States"],
    ["Lesser Antilles", "Jamaica", "Cayman Islands", "Cuba", "The Bahamas", "Bermuda"],
    ["The Bahamas", "Cuba", "Florida", "Texas", "Tamaulipas"],
    ["Jamaica", "Yucatn Peninsula"],
    ["The Bahamas", "Florida", "Georgia", "The Carolinas", "Virginia"],
    ["Southeastern United States", "Northeastern United States", "Southwestern Quebec"],
    ["Bermuda", "New England", "Atlantic Canada"],
    ["Lesser Antilles", "Central America"],
    ["Texas", "Louisiana", "Midwestern United States"],
    ["Central America"],
    ["The Caribbean", "Mexico", "Texas"],
    ["Cuba", "United States Gulf Coast"],
    ["The Caribbean", "Central America", "Mexico", "United States Gulf Coast"],
    ["Mexico"],
    ["The Caribbean", "United States East coast"],
    ["The Caribbean", "Yucatn Peninsula", "Mexico", "South Texas"],
    ["Jamaica", "Venezuela", "Central America", "Hispaniola", "Mexico"],
    ["The Caribbean", "United States East Coast"],
    ["The Bahamas", "Florida", "United States Gulf Coast"],
    ["Central America", "Yucatn Peninsula", "South Florida"],
    ["Greater Antilles", "Bahamas", "Eastern United States", "Ontario"],
    ["The Caribbean", "Venezuela", "United States Gulf Coast"],
    ["Windward Islands", "Jamaica", "Mexico", "Texas"],
    ["Bahamas", "United States Gulf Coast"],
    ["Cuba", "United States Gulf Coast"],
    ["Greater Antilles", "Central America", "Florida"],
    ["The Caribbean", "Central America"],
    ["Nicaragua", "Honduras"],
    [
        "Antilles",
        "Venezuela",
        "Colombia",
        "United States East Coast",
        "Atlantic Canada",
    ],
    [
        "Cape Verde",
        "The Caribbean",
        "British Virgin Islands",
        "U.S. Virgin Islands",
        "Cuba",
        "Florida",
    ],
    [
        "Lesser Antilles",
        "Virgin Islands",
        "Puerto Rico",
        "Dominican Republic",
        "Turks and Caicos Islands",
    ],
    ["Central America", "United States Gulf Coast (especially Florida Panhandle)"],
]

# damages (USD($)) of hurricanes
damages = [
    "Damages not recorded",
    "100M",
    "Damages not recorded",
    "40M",
    "27.9M",
    "5M",
    "Damages not recorded",
    "306M",
    "2M",
    "65.8M",
    "326M",
    "60.3M",
    "208M",
    "1.42B",
    "25.4M",
    "Damages not recorded",
    "1.54B",
    "1.24B",
    "7.1B",
    "10B",
    "26.5B",
    "6.2B",
    "5.37B",
    "23.3B",
    "1.01B",
    "125B",
    "12B",
    "29.4B",
    "1.76B",
    "720M",
    "15.1B",
    "64.8B",
    "91.6B",
    "25.1B",
]

# deaths for each hurricane
deaths = [
    90,
    4000,
    16,
    3103,
    179,
    184,
    408,
    682,
    5,
    1023,
    43,
    319,
    688,
    259,
    37,
    11,
    2068,
    269,
    318,
    107,
    65,
    19325,
    51,
    124,
    17,
    1836,
    125,
    87,
    45,
    133,
    603,
    138,
    3057,
    74,
]

# write your update damages function here:


def update_damage(old_damage):
    new_damage = []
    con = {"M": 1000000, "B": 1000000000}
    for damage in old_damage:
        if damage == "Damages not recorded":
            new_damage.append("Damages not recorded")
        else:
            len_dam = len(damage) - 1
            new_damage.append(
                float(damage[0:len_dam]) * float(con.get(damage[len_dam]))
            )
    return new_damage


# write your construct hurricane dictionary function here:


def make_dict(name, month, year, Max_Sustained_Wind, Areas_Affected, Damage, Death):
    hold = dict()
    for i in range(0, len(name)):
        temp = dict(
            Name=name[i],
            Month=months[i],
            Year=years[i],
            Max_Sustained_Wind=max_sustained_winds[i],
            Areas_Affected=areas_affected[i],
            Damage=Damage[i],
            Death=deaths[i],
        )
        hold[name[i]] = temp
    return hold


# write your construct hurricane by year dictionary function here:


def year_dict(name_dict):
    hold = dict()
    for data in name_dict.keys():
        if name_dict[data]["Year"] in hold:
            hold[name_dict[data]["Year"]].append(name_dict[data])
        else:
            hold[name_dict[data]["Year"]] = [name_dict[data]]
    sorted(hold.keys())
    return hold


# write your count affected areas function here:
def count_affected_areas(areas):
    areas_num = dict()
    for area in areas:
        for locations in area:
            if locations not in areas_num:
                areas_num[locations] = 1
            else:
                areas_num[locations] += 1
    return areas_num


# write your find most affected area function here:


def most_freq_area():
    hold = count_affected_areas(areas_affected)
    max = 0
    for data in hold:
        if hold[data] >= max:
            name = data
            max = hold[data]
    return {name: max}


# write your greatest number of deaths function here:


def most_deaths(name_dict):
    max_deaths = 0
    for data in name_dict:
        if name_dict[data]["Death"] >= max_deaths:
            name = data
            max_deaths = name_dict[data]["Death"]
    return {name: max_deaths}


# write your catgeorize by mortality function here:


def mortality_rate(hurricane_data):
    hold = {0: [], 1: [], 2: [], 3: [], 4: [], 5: []}
    for data in hurricane_data:
        if hurricane_data[data]["Death"] >= 10000:
            hold[5].append(hurricane_data[data])
        elif (
            hurricane_data[data]["Death"] < 10000
            and hurricane_data[data]["Death"] >= 1000
        ):
            hold[4].append(hurricane_data[data])
        elif (
            hurricane_data[data]["Death"] < 1000
            and hurricane_data[data]["Death"] >= 500
        ):
            hold[3].append(hurricane_data[data])
        elif (
            hurricane_data[data]["Death"] < 500 and hurricane_data[data]["Death"] >= 100
        ):
            hold[2].append(hurricane_data[data])
        elif hurricane_data[data]["Death"] < 100 and hurricane_data[data]["Death"] != 0:
            hold[1].append(hurricane_data[data])
        else:
            hold[0].append(hurricane_data[data])
    return hold


# write your greatest damage function here:


def most_damamge(hurricane_data):
    max = 0
    for data in hurricane_data:
        if hurricane_data[data]["Damage"] == "Damages not recorded":
            pass
        elif hurricane_data[data]["Damage"] >= max:
            max = hurricane_data[data]["Damage"]
            name = data
    return {name: max}


# write your catgeorize by damage function here:
def damage_list(hurricane_data):
    hold = {
        0: [],
        1: [],
        2: [],
        3: [],
        4: [],
    }
    damage_scale = {0: 0, 1: 100000000, 2: 1000000000, 3: 10000000000, 4: 50000000000}
    for data in hurricane_data:

        if hurricane_data[data]["Damage"] == "Damages not recorded":
            hold[0].append(hurricane_data[data])
        elif hurricane_data[data]["Damage"] >= damage_scale[4]:
            hold[4].append(hurricane_data[data])
        elif (
            hurricane_data[data]["Damage"] < damage_scale[4]
            and hurricane_data[data]["Damage"] >= damage_scale[3]
        ):
            hold[3].append(hurricane_data[data])
        elif (
            hurricane_data[data]["Damage"] < damage_scale[3]
            and hurricane_data[data]["Damage"] >= damage_scale[2]
        ):
            hold[2].append(hurricane_data[data])
        elif (
            hurricane_data[data]["Damage"] < damage_scale[2]
            and hurricane_data[data]["Damage"] >= damage_scale[1]
        ):
            hold[1].append(hurricane_data[data])
    return hold

# what month had the most hurrican

def month_list(hurricane_data):
    hold = dict()
    for data in hurricane_data:
        month = hurricane_data[data]['Month']
        if month not in hold:
            hold[month] = 1
        else:
            hold[month] += 1
    return hold