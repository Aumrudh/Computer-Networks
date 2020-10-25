MyFile=open('intermediate.txt','r')
newres=MyFile.read()
MyFile.close()
       

print("Received Message")

a=0
z=[]
noone=0
count=0


while a<len(newres):
    count+=1
    if(count%8==0):
        for x in range((a-1),((a-7)-1),-1):         
            if(newres[x]=='1'):
                noone+=1                                  #Checking no of 1's
        if((noone%2==0 and newres[a]=='0') or (noone%2!=0 and newres[a]=='1')):
            noone=0
            count=0
            for x in range((a-7),(a),1):
                z.append(newres[x])                       #Appending message into list
        else:
            print("Error message")
            break
        a+=1
    else:
        a+=1                
           
for i in z:
    print(i,end="")                                       #print message



"""while e<len(z):
    if e%7==0 and e!=0:
        print("\n")
        print(z[e],end="")         
        e+=1
    else:
        print(z[e],end="")
        e+=1
print("l",len(z))"""


