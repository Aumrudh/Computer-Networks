MyFile=open('intermediate.txt','r')
newres=MyFile.read()
MyFile.close()

res=[]
i=0
k=0
newmess=[]
f=[]


for i in newres:
    if(i.isalnum()):                              #removing special character '[]' from file read
        res.append(i)
        
count=1
newmess=[]
i=0
r=0
l=len(res)

rem=(len(res)/7)
rem=int(rem)
print(rem)

while i<l:
    if(count%7==0):
        if(r<rem):
             newmess.insert(r,(res[:(i+1)]))       #dividing message into 7bits
             res=res[(i+1):]
             i=0
             l=len(res)
             r+=1
    else:
        i+=1
    count+=1

k=0
coun=0
o=[]
i=0
for i in range(0,7,1):
    while k<rem:
        if(newmess[k][i]=='1'):                    #parity check
            coun+=1
        k+=1
    if(coun%2==0):
        o.insert(i,'0')
        coun=0                           
        k=0
    else:
        o.insert(i,'1')
        coun=0
        k=0

h=['0','0','0','0','0','0','0']
if(h==o):
    print("Message received")
    re=((rem-1)*7)
    for i in newres:                         #print recieved message
        if(i.isalnum()):
            f.append(i)
    for i in range(0,re,1):
        print(f[i],end="")
else:
    print("corrupted")
