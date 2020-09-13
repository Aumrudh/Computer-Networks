msge=input("Enter the message : ")
list_msge=list(msge)
rem=len(msge)%7
rem_digit=0
if rem!=0:
    rem_digit=7-rem
for i in range(0,rem_digit):
    list_msge.insert(0,'0')
print(list_msge)
temp=''
for i in list_msge:
    temp+=i
#print(temp)
l=[]
t=len(temp)
i=0
while i<t:
    a=temp[:7]
    a=list(a)
    temp=temp[7:]
    t=len(temp)
    l.append(a)
#print("Sender Message : ",end=' ')    
#print(l,end='\n')
lis=[]
sum=''
for i in range(0,7):
    for j in range(len(l)):
        sum+=l[j][i]
    setBits = [ones for ones in sum if ones=='1']
    s=len(setBits) 
    if s%2==0:
        s='0'
    else:
        s='1'
    lis.append(s)
    sum=''
#print("Column Parity : ",lis) 
l.append(lis)
#print("Column Parity Appended To list: ",l)  

for i in range(len(l)):
    setBits = [ones for ones in l[i] if ones=='1']
    #print(setBits)
    s=len(setBits)
    if s%2==0:
        s='0'
    else:
        s='1'
    s=list(s)
    #print(s)
    l[i]=l[i]+s
#print('Row Parity Added')
print("Intermediate Message: ",end=' ') 
#print(l,end='\n')
for line in l:
        print("".join(line),end='')
file=open('intermediate_message.txt','w')
#file.write(str(l))
for line in l:
        file.write("".join(line))
file.close()