from glob import glob
import os
paths = glob("tc_convert/*")
newname = []
for i in paths:
    fname = i.lstrip('tc_convert\\')
    if fname[-1] == 'a':
        fname = fname.rstrip('.a')
        os.rename(i, 'tc_convert\\' + str(int(fname)) + '.sol')
    else:
        os.rename(i, 'tc_convert\\' + str(int(fname)) + '.in')