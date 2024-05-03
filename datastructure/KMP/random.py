import random
num = random.randint(1,50)              # 生成随机个字符串
seed = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
with open("inputdata3.txt",'w') as fwr:
    fwr.write(str(num)+'\n')
    for i in range(num):
        s1 = ""
        s2 = ""
        len1 = random.randint(1,20)
        len2 = random.randint(20,100)
        for j in range(len1):
            s1 += random.choice(seed)
        for k in range(len2):
            s2 += random.choice(seed)
        fwr.write(s1+' '+s2+'\n')
