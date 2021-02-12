import re
import sys
import logging
msge=input("Enter the message : ")
if re.findall("[^0-1]", msge):
    logging.error("Error, input contains other than 0 and 1's")  
    sys.exit(1)
length=len(msge)
redundant_bits=1
while((length+redundant_bits+1)>=(pow(2,redundant_bits))): 
    redundant_bits+=1
new_len=length+redundant_bits
j=0
k=1
red_message=[]
for i in range(1,new_len+1):
    if(i==2**j):                                    
        red_message.append('0')
        j+=1
    else:
        red_message.append(msge[-1*k])
        k+=1
red_message=list(red_message)
print('After adding redundant bit as 0 :',''.join(red_message))
red_message.insert(0,' ')

p=0
parity=[]
i=1
for i in range(1,redundant_bits+1):
    x=pow(2,p)
    r=1
    j=x
    while(j<=new_len):
        k=j
        while(k<j+x and k<=new_len):
            parity.insert(r,red_message[k])
            r+=1
            k+=1
        j=j+(x*2)    
    z=0
    for y in range(1,r-1):
        if(parity[y]=='1'):
            z+=1
    if(z%2==0):
        red_message[x]='0'
    else:
        red_message[x]='1'
    parity.clear()
    p+=1


red_message=red_message[::-1]
print("Hammingcode : ",end='')
for i in red_message:
    print(i,end="")

file=open('a.txt','w')             
file.write(''.join(red_message))                     
file.close();