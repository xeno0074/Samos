import configparser
import os
import argparse

# CREATE INPUT DIRECTORY
try:
    os.makedirs("INPUT_FILES")
except FileExistsError:
    # directory already exists
    pass

# DEFAULT VALUES FOR PARAMETERS
seed = 0
bytes_data = '30'
max_id = '3'
max_amount = '10'
values_txType = '1 0 0'  # 1 == credit, 0 == debit
min_year_date = '2020'
max_year_date = '2030'
values_tags = 'salary shopping rent'

# READ SEED FROM ARGUMENTS
parser = argparse.ArgumentParser()
parser.add_argument('--seed')
parser.add_argument('--bytes_data')
parser.add_argument('--max_id')
parser.add_argument('--max_amount')
parser.add_argument('--values_txType')
parser.add_argument('--min_year_date')
parser.add_argument('--max_year_date')
parser.add_argument('--values_tags')
args = parser.parse_args()
if args.seed:
    seed = args.seed
if args.bytes_data:
    bytes_data = args.bytes_data
if args.max_id:
    max_id = args.max_id
if args.max_amount:
    max_amount = args.max_amount
if args.values_txType:
    values_txType = args.values_txType
if args.min_year_date:
    min_year_date = args.min_year_date
if args.max_year_date:
    max_year_date = args.max_year_date
if args.values_tags:
    values_tags = args.values_tags

# CREATE OBJECT
conf = configparser.ConfigParser()

# ADD SECTION
conf.add_section("Settings")
conf.add_section("Entries")

# ADD KEY-VALUE PAIRS TO SECTION
conf["Settings"] = {
    "seed": seed
}

conf["Entries"] = {
    "bytes_data": bytes_data,
    "max_id": max_id,
    "max_amount": max_amount,
    'values_txType': values_txType,
    "min_year_date": min_year_date,
    "max_year_date": max_year_date,
    "values_tags": values_tags  # mapped to txType
}

# SAVE CONFIG FILE
with open(r"INPUT_FILES/config.ini", 'w') as config_file:
    conf.write(config_file)
    config_file.flush()
    config_file.close()

print("Created config file 'INPUT_FILES/config.ini'..")
