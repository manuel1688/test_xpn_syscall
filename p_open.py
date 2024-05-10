
from ctypes import *
import sys


# get filename
if (len(sys.argv) < 2):
    print("")
    print("Usage:")
    print(" * ./main_preload.py <file name>")
    print("")
    print("Examples:")
    print(" ./main_preload.py /tmp/expand/P1/demo.txt")
    print(" ./main_preload.py /tmp/demo.txt")
    print("")
    sys.exit()

fname = sys.argv[1]

# write and read buffer
try:
    print("fname: " + fname)
    f = open(fname, "w", encoding="utf-8")
    f.close()
except IOError as e:
    print(e)
    sys.exit()
except:
    print("open failed !")
    sys.exit()

