from sys import stdin

S = stdin.readline().rstrip()

for char in S:
    char_ascii = ord(char)
    position_sum = sum(map(int, list(str(char_ascii))))

    print(char * position_sum)
