import configparser

# CREATE OBJECT
conf = configparser.ConfigParser()

# ADD SECTION
conf.add_section("Entries")

# ADD KEY-VALUE PAIRS TO SECTION
conf["Entries"] = {
    "bytes_data": "10",
    "max_id": "400",
    "max_amount": "100000",
    "min_year_date": "2020",
    "max_year_date": "2030",
    "values_tags": "salary shopping rent"
}

# SAVE CONFIG FILE
with open(r"config.ini", 'w') as config_file:
    conf.write(config_file)
    config_file.flush()
    config_file.close()
print("Created config file 'config.ini'")

import entries_gen
