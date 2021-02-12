File=open('intermediate_message.txt','r')
temp=File.read()
File.close()
i=0
while i<len(temp):
    if temp[i].isalpha():
        divident=temp[:i]
        key=temp[i+1:]
    i+=1
#print(temp1)
#print(key)
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
print("rem",rem)
if(rem=='000'):
    print("No Error")
else:
    print("Error")