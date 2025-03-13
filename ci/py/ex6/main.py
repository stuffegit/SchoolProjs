#!/usr/bin/env python3

import os

sourcefiles = []
headerdirs = set({})

for root, dirs, files in os.walk('.'):
    for file in files:
        if file.endswith(".c"):
            sourcefiles.append(root+"/"+file)
        elif file.endswith(".h"):
            type(headerdirs)
            headerdirs.add(str(root))
        else:
            pass

print(*sourcefiles)
print(*headerdirs)

os.system("rm -rf ./build")
os.system("mkdir -p build")
for build in sourcefiles:
    os.system(f"gcc -c {build} -I{headerdirs} -o build/{(build[6:])[:-2]}.o")
