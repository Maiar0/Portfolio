inp1 = input()
inp=input()
inp_split = []
out = []
if inp1 == 's':
    for o in inp:
        inp_split.append(o)
    for i in inp_split:
        if ord(i)-96 < 10:
            i = '0'+str(ord(i)-96)
        else:
            i = ord(i)-96
        out.append(i)
else:
    for o in range(0,len(inp),2):
        inp_split.append(inp[o]+inp[o+1])
        #inp_split.append(inp[o+1])
    for i in inp_split:
        num1 = int(i)+96
        out.append(chr(num1))

print(out)
input()