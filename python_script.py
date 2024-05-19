import random
f=open("myfile.txt",'w')
for i in range(1,100):
    number = random.randint(1,500)
    f.write(str(number)+'\n')
f.close()
k = open("myfile.txt",'r')
for i in k.readlines():
    print(i)
