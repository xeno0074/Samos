import configparser
import random
import csv
import utilities

# CREATE OBJECT
config = configparser.ConfigParser()

# READ CONFIG FILE
config.read("TEST_FILES/config.ini")

seed = int(config['Settings']['seed'])
bytes_data = int(config['Entries']['bytes_data'])
max_id = int(config['Entries']['max_id'])
max_amount = int(config['Entries']['max_amount'])
values_txType = config['Entries']['values_txType'].split(' ')
min_year_date = config['Entries']['min_year_date']
max_year_date = config['Entries']['max_year_date']
values_tags = config['Entries']['values_tags'].split(' ')

########################################################################################################################
#  RANDOM ENTRIES GENERATION
########################################################################################################################

random.seed(seed)

with open('TEST_FILES/entries.csv', "w", newline='') as entry_file, open('TEST_FILES/tc01.csv', "w",
                                                                         newline='') as tc01_file:
    entry_writer = csv.writer(entry_file, delimiter=',')
    entry_writer.writerow(['data', 'id', 'amount', 'txType', 'dateTime', 'tags'])

    tc01_writer = csv.writer(tc01_file, delimiter=',')
    tc01_writer.writerow(['total credit', 'total debit'])
    total_credit = 0
    total_debit = 0

    for entry_id in range(max_id):
        tag = random.choice(values_tags)
        entry = [utilities.random_str(random.randint(bytes_data // 4, bytes_data)), entry_id,
                 random.randint(1, max_amount),
                 utilities.get_txType(values_txType, values_tags, tag),
                 utilities.random_date(min_year_date, max_year_date), tag]
        entry_writer.writerow(entry)

        #   GENERATE TC_01 - total credit and total debit with each entry
        total_credit += (entry[3] == utilities.map_txType[1]) * entry[2]
        total_debit += (entry[3] == utilities.map_txType[0]) * entry[2]
        tc01_writer.writerow([total_credit, total_debit])

print('Generated entries in \'TEST_FILES/entries.csv\'..')
