import string
import random

def randStr(chars = string.ascii_letters+string.digits, N = 10):
    return "".join(random.choice(chars) for _ in range(N))

# gen1 1000 1000 10000
# gen2 100000 100000 10000
# gen3 100000 100000 1000000
case_sz = 20
filename = "gen1"
with open(filename+".txt", "w") as file:
    # file.write(filename+" 5 7 3 LoveWin > $\n")
    for _ in range(case_sz):
        # N, M, dmg_wei respectively
        file.write(filename+" 1000 1000 10000 " + randStr() + " > $ \n")