import configparser
import random
import csv
import utilities

# CREATE OBJECT
config = configparser.ConfigParser()

# READ CONFIG FILE
config.read("INPUT_FILES/config.ini")
print("Read config file 'INPUT_FILES/config.ini'..")

seed = int(config['Settings']['seed'])
bytes_data = int(config['Entries']['bytes_data'])
max_id = int(config['Entries']['max_id'])
max_amount = int(config['Entries']['max_amount'])
values_txType = config['Entries']['values_txType'].split(' ')
min_year_date = config['Entries']['min_year_date']
max_year_date = config['Entries']['max_year_date']
values_tags = config['Entries']['values_tags'].split(' ')

###############################################################################
#  RANDOM ENTRIES GENERATION
###############################################################################
columns = ['data', 'id', 'amount', 'txType', 'dateTime', 'tags']

random.seed(seed)

with open('INPUT_FILES/entries.csv', "w", newline='') as csv_file:
    writer = csv.writer(csv_file, delimiter=',')
    writer.writerow(columns)
    for entry_id in range(max_id):
        tag = random.choice(values_tags)
        entry = [utilities.random_str(random.randint(bytes_data // 4, bytes_data)), (max_id - entry_id),
                 random.randint(1, max_amount),
                 utilities.get_txType(values_txType, values_tags, tag),
                 utilities.random_date(min_year_date, max_year_date), tag]
        writer.writerow(entry)

print('Generated entries in \'INPUT_FILES/entries.csv\'..')
