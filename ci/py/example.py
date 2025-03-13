#!/usr/bin/env python3

try:
    raise OSError("OSError")
except OSError as err:
    print(err)
else:
    print("return 0;")


try:
    pass
except OSError as err:
    print(err)
else:
    print("no errors")
