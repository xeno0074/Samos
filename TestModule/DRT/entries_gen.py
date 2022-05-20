import configparser
import random
import csv
import utilities

# CREATE OBJECT
config = configparser.ConfigParser()

# READ CONFIG FILE
config.read("config.ini")
print("Read config file 'config.ini'")

bytes_data = int(config['Entries']['bytes_data'])
max_id = int(config['Entries']['max_id'])
max_amount = int(config['Entries']['max_amount'])
min_year_date = int(config['Entries']['min_year_date'])
max_year_date = int(config['Entries']['max_year_date'])
values_tags = config['Entries']['values_tags'].split(' ')

###############################################################################
#  RANDOM ENTRIES GENERATION
###############################################################################
seed = 44
random.seed(seed)

columns = ['data', 'id', 'amount', 'txType', 'dateTime', 'tags']

with open("entries.csv", "w", newline='') as csv_file:
    writer = csv.writer(csv_file, delimiter=',')
    writer.writerow(columns)
    for entry_id in range(max_id):
        entry = [utilities.random_str(bytes_data), entry_id, random.randint(1, max_amount),
                 random.choice(['credit', 'debit']), utilities.random_date(min_year_date, max_year_date),
                 random.choice(values_tags)]
        writer.writerow(entry)
