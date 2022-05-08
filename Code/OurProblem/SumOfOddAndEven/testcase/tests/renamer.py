import os

for i in range(1, 21):
    print(f'{i:02d}', f'{i}.in')
    os.rename(f'{i:02d}', f'{i}.in')
    print(f'{i:02d}.a', f'{i}.out')
    os.rename(f'{i:02d}.a', f'{i}.out')
    #os.rename(f'{i}', f'{i}.in')