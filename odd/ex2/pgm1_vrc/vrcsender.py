message=input("Enter your message:")
newres=[str(i) for i in message]

i=1
a=0                                      
count=0
noone=0
z=0


size=len(newres)

if size%7!=0:
    nsize=size+7                           #if size of message less than 7 append 0 at last
    n=nsize%7
    zsize=nsize-n
    additional=zsize-size
    while i<=additional:
        newres.insert(len(newres),'0')
        i+=1


while a<len(newres):
    count+=1
    if(newres[a]=='1'):                    #parity check
        noone+=1
    if(count%7==0):
        if(noone%2==0):
            newres.insert(a+1,'0')
            count=0
            noone=0
        else:
            newres.insert(a+1,'1')
            count=0
            noone=0
        a+=2
    else:
        a+=1

"""
while z<len(newres):
    if z%8==0 and z!=0:
        print("\n")
        print(newres[z],end="")         
        z+=1
    else:
        print(newres[z],end="")
        z+=1"""

MyFile=open('intermediate.txt','w')
for element in newres:                    
    MyFile.write(element)                      #File write
MyFile.close();

print("\n Written into intermediate file")


