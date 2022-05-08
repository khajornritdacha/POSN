import os

for id in range(1, 9):
    # bin = before of input file
    # bout = before of output file
    bin_name = f"{id:02d}"
    bout_name = f"{id:02d}.a"
    # print(bin_name)
    # print(bout_name)

    ain_name = f"{id}.in"
    aout_name = f"{id}.sol"

    # print(ain_name)
    # print(aout_name)

    os.rename(bin_name, ain_name)
    os.rename(bout_name, aout_name)
