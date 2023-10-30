f = 0
p = 3
q = 11
e = 3 #public key
d = 7
n= p*q
phin=(p-1)*(q-1)#toilent

def encrypt(num):
    #print('numrecieved by function:',num)
    encrypted = int(num)**3%33
    encrypted_split = []
    for o in str(encrypted):
        encrypted_split.append(o)
    if len(encrypted_split) == 1:
        encrypted = '0' + str(encrypted)
    #print('encrypted in function:',encrypted)
    return encrypted

def message_equiv(inp):
    inp_split = []
    out = []
    encrypted_out = []
    for o in inp:
        inp_split.append(o)
    for i in inp_split:
        if ord(i) - 96 < 10 and i != ' ':
            i = '0' + str(ord(i) - 96)
        elif i == ' ':
            i = 32
        else:
            i = ord(i) - 96
        encrypted_out.append(str(encrypt(int(i))))
        out.append(str(i))
    #print('message_equiv out: ',out,' full line',''.join(out))
    print('message_encrypted:',encrypted_out,'full line:',''.join(encrypted_out))

def decrypt(num):
    decrypted_split = []
    decrypted = int(num)**7%33
    for o in str(decrypted):
        if o != '32':
            decrypted_split.append(o)
        if o == '32':
            decrypted_split.append(' ')
    if len(decrypted_split) == 1:
        decrypted = '0' + str(decrypted)
    return decrypted

while f == 0:
    inp1 = input('Type "s" for encryption or "d" for decryption').lower()
    inp=input()
    inp_split = []
    out = []
    encrypted_out = []
    decrypted_out = []
    decrypt_list = []
    if inp1 == 's':
        message_equiv(inp)
    if inp1 == 'd':
        for o in range(0,len(inp),2):
            inp_split.append(inp[o]+inp[o+1])
        for n in inp_split:
            decrypt_list.append(str(decrypt(n)))


        for i in decrypt_list:
            if i != '32':
                num1 = int(i)+96
                out.append(chr(num1))
            elif i == '32':
                num1 = ' '
                out.append(num1)
    #print('message_equiv out: ',decrypt_list,' full line',''.join(decrypted_out))
    print('message_decrypted:', out, 'full line:', ''.join(out))
    #print(out)
    #print('message equiv'+''.join(out))
    #print('encrypted:'+encrypted_out)