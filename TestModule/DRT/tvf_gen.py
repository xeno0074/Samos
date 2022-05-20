import configparser
import random
import string
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
#  TVF GENERATION
###############################################################################
seed_tvf = 719
random.seed(seed_tvf)

columns = ['data', 'id', 'amount', 'txType', 'dateTime', 'tags']

with open("entries.tvf.csv", "w", newline='') as csv_file:
    writer = csv.writer(csv_file, delimiter=',')
    writer.writerow(columns)
    for id in range(max_id):
        entry = []
        entry.append(str.title(''.join(random.choices(string.ascii_lowercase, k=bytes_data))))
        entry.append(id)
        entry.append(random.randint(1, max_amount))
        entry.append(random.choice([1, -1]))
        entry.append(utilities.random_date(min_year_date, max_year_date))
        entry.append(random.choice(values_tags))
        writer.writerow(entry)
