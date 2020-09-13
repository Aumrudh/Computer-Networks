#charactercountreceiver
File=open('intermediate_message.txt','r')
temp=File.read()
File.close()
t1=len(temp)
i=0
l=[]
flag=0
while(i<t1):  
    if(temp[i].isnumeric()):
        x=temp[:i]
        tx=str(len(x))
        if(tx==temp[i]): 
            #print("No error")
            l.append((temp[:i]+' '))
        elif tx!=temp[i]:
            print("error")
            flag=1
            break
        temp=temp[i+1:]
        t1=len(temp) 
        i=0        
    i+=1
if flag==0:
    for i in l:
        print(i,end='')   