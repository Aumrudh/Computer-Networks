msge=input("Enter your message : ")
key=input("Enter the key value : ")
divident=msge+('0'*(len(key)-1))
flag=len(key)
divisor=key
temp=divident[:flag]
while flag<len(divident):
    if(temp[0]=='0'):
        temp_divisor='0'*flag
        temp_divident=temp
        l=[]
        for i in range(1,len(temp_divident)):
            if(temp_divisor[i]==temp_divident[i]):
                l.append('0')
            else:
                l.append('1')
        rem=''.join(l)
        temp=rem+divident[flag]
    else:
        temp_divisor=divisor
        temp_divident=temp
        l=[]
        for i in range(1,len(temp_divident)):
            if(temp_divisor[i]==temp_divident[i]):
                l.append('0')
            else:
                l.append('1')
        rem=''.join(l)
        temp=rem+divident[flag]
    flag+=1
if(temp[0] == '0'):
    temp_divisor='0'*flag
    temp_divident=temp
    l=[]
    for i in range(1,len(temp_divident)):
        if(temp_divisor[i]==temp_divident[i]):
            l.append('0')
        else:
            l.append('1')
    rem=''.join(l)
else: 
    temp_divisor=divisor
    temp_divident=temp
    l=[]
    for i in range(1,len(temp_divident)):
        if(temp_divisor[i]==temp_divident[i]):
            l.append('0')
        else:
            l.append('1')
    rem=''.join(l)
msge=msge+rem+'k'+key
print("Intermediate message : ",msge)
file=open('intermediate_message.txt','w')
file.write(msge)
file.close()