from math import gcd

# print(gcd(2, 3))

mx = 0
for p in range(2, 100):
    cop = 0
    for i in range(1, p):
        if gcd(p, i) == 1:
            cop = cop + 1
    if cop != p-1 and cop > mx:
        print(f"{p} : {cop}")
        mx = cop
    
