message=input("Enter message:")
res=[str(x) for x in message]

count=1
newmess=[]
i=0
r=0
z=0
size=len(res)

if size%7!=0:
    nsize=size+7                           #if size of message less than 7 append 0 at first
    n=nsize%7
    zsize=nsize-n
    additional=zsize-size
    while z<=additional:
         res.insert(0,'0')
         z+=1

#print("List",str(res))

rem=(len(res)/7)
rem=int(rem)
print("rem",rem)

l=len(res)

while i<l:
    if(count%7==0):
        if(r<rem):
             newmess.insert(r,(res[:(i+1)]))     #Dividing message into 7 bits
             res=res[(i+1):]
             i=0
             l=len(res)
             r+=1
    else:
        i+=1
    count+=1

#print("List",str(newmess))
k=0
coun=0
o=[]
for i in range(0,7,1):
    while k<rem:
        if(newmess[k][i]=='1'):
            #print("k",k)                      #parity check
            coun+=1
        k+=1
    if(coun%2==0):
        #print("coun",coun)
        o.insert(i,'0')                        #inserting parity bit
        coun=0
        k=0
    else:
        o.insert(i,'1')
        coun=0
        k=0

newmess.append(o)
newmess=str(newmess)


MyFile=open('intermediate.txt','w')
for element in newmess:                    
    MyFile.write(element)                      #File write
MyFile.close();

print("\n Written into intermediate file")
            
