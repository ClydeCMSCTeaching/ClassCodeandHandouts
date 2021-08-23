from Point import Point



### reading files

with open('example.txt', 'r') as fin:
    i = 0
    for line in fin:
        print(f"line {i}:", line.strip())
        i += 1

with open("out.txt", 'w') as fout:
    for i in range(0, 10000000, 2):
        fout.write(f"{i}\n")



p1 = Point(1, 2)
p2 = Point(3, 4)

print(p1, p2)
