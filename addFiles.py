# taskkill /F /IM main.exe

# g++ code/src/main.cpp code/src/setup.cpp -o Build/main.exe

# pause

# very thrown together script for auto assembling build file

import os

files = os.listdir("code/src")
strings = ["taskkill /F /IM main.exe\n","","pause"]

strings[1] += "g++ -Wall "

for n in files:
    strings[1] += "code/src/"+ n + " "

strings[1] += "-o Build/main.exe \n"

try:
    os.remove("buildMain.bat")
except Exception as IOError:
    print("No file named buildMain.bat")

with open("buildMain.bat","w") as file:
    for items in strings:
        file.write(items)
