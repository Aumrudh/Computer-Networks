file=open('a.txt','r')
temp=file.read()
file.close()

red_msge=list(temp)
red_msge=red_msge[::-1]
length=len(temp)-1

redundant_bits=1
parity=[]
flag=0

while pow(2,redundant_bits)>=(length+redundant_bits+1):
    redundant_bits+=1

p=0
a=''
for i in range(1,redundant_bits+1):
    x=pow(2,p)
    r=1
    j=x
    while(j<=length):
        k=j
        while(k<j+x and k<=length):
            parity.insert(r,red_msge[k])
            r+=1
            k+=1
        j=j+(x*2)
    z=0
    for y in range(0,r-1):
        if(parity[y]=='1'):
            z+=1
    if(z%2==0):
        a+='0'
    else:
        a+='1'
    parity.clear()
    p+=1
a=a[::-1]
par=int(a,2)
#print(a)
#print(par)
if(par==0):
 	#print("No error")
    print(red_msge)
    print('No Error :' ,''.join(red_msge))
else:
    print("Error at : ",par, "patching the data...")
    print('Error data',''.join(red_msge))
    if red_msge[par]=='0':
        red_msge[par]='1'
    else:
        red_msge[par]='0'    
    print('Correct data',''.join(red_msge))