#charactercountsender
sender_msge=input("Enter the sender message : ")
msge=sender_msge.split(sep=' ')
int_msge=[]
for i in msge:
    length=len(i)
    int_msge.append(i+str(length))

file=open('intermediate_message.txt','w')
for i in int_msge:
    file.write(i)
file.close();

print("Intermediate Message : ",end="")
file=open('intermediate_message.txt','r')
print(file.read())
file.close()