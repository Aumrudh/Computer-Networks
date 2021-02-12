#bitstuffreceiver
File=open('intermediate_message.txt','r')
temp=File.read()
File.close()
#print(temp)
temp1=temp[:8]
#print(temp1)
temp2=temp[-8:]
#print(temp2)
rec_msge=list(temp)
#print(rec_msge)
if(temp1=='01111110' and temp2=='01111110'):
    print("No error")
    t=len(temp)-8
    rec_msge=rec_msge[8:t]
    #print(rec_msge)
    i=0
    flag=0
    print('Receiver Message : ',end='')
    while(i<len(rec_msge)):
        if(rec_msge[i]=='1'):
            flag+=1        
        else:
            flag=0
        print(rec_msge[i],end='')
        if(flag==5):
            flag=0
            i+=1
        i+=1
else:
    print('Error')