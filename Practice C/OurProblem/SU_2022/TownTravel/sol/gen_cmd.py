import string
import random

def randStr(chars = string.ascii_letters+string.digits, N = 10):
    return "".join(random.choice(chars) for _ in range(N))

case_sz = 20
filename = "gen"
with open(filename+".txt", "w") as file:
    for _ in range(case_sz):
        # N, M, dmg_wei respectively
        file.write(filename+" 400 500 5" + randStr() + " > $ \n")