import os

# CREATE LOGS DIRECTORY
try:
    os.makedirs("LOGS")
except FileExistsError:
    # directory already exists
    pass
