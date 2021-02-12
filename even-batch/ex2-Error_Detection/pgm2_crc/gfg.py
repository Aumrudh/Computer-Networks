def xor(temp_divisor,temp_divident):
    l=[]
    for i in range(1,len(temp_divident)):
        if(temp_divisor[i]==temp_divident[i]):
            l.append('0')
        else:
            l.append('1')
    return ''.join(l)
msge=input("Enter your message : ")
key=input("Enter the key value : ")
divident=msge+('0'*(len(key)-1))
flag=len(key)
divisor=key
temp=divident[:flag]
while flag<len(divident):
    if(temp[0]=='0'):
        temp=xor('0'*flag,temp)+divident[flag]        
    else:
        temp=xor(divisor,temp)+divident[flag]
    flag+=1
if(temp[0] == '0'):
    temp = xor('0'*flag, temp)
else: 
    temp = xor(divisor, temp)
rem=temp
msge=msge+rem
print(msge)