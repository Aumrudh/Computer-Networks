#bitstuffsender
sender_msge=input("Enter the sender message : ")
int_msge=list(sender_msge)
#print(int_msge)
i=0
flag=0
int_msge.insert(0,'01111110');
int_msge.insert((len(int_msge)),'01111110');
while(i<len(int_msge)):
    if(int_msge[i]=='1'):
        flag+=1
    else:
        flag=0
    if(flag==5):
        int_msge.insert(i+1, '0')
        flag=0
        i+=1
    i+=1
file=open('intermediate_message.txt','w')
for i in int_msge:
    file.write(i)
file.close();

print("Intermediate Message : ",end="")
file=open('intermediate_message.txt','r')
print(file.read())
file.close()