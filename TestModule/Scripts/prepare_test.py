import os

# CREATE LOGS DIRECTORY
try:
    os.makedirs("LOGS")
except FileExistsError:
    # directory already exists
    for file in os.listdir("LOGS"):
        os.remove("LOGS/" + file)
    pass

print("Test preparation complete..")
