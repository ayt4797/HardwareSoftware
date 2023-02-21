a=[]
for i in range (1,255):
    a.append(pow(0xfe,i,255))

b = range(1,283)
print(b)
print(a)

for i in range(1,282):
    if(b[i] not in a):
        print("failure")
        exit(0)

print("success")