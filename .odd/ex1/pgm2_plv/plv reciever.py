MyFile=open('intermediate.txt','r')
newres=MyFile.read()
MyFile.close()

print("Received Message")
if(newres[0]!='0' or newres[1]!='0'):
   print("Start of text error")
elif(newres[len(newres)-1]!='1' and newres[len(newres)-2]!='1'):
    print("End of text error")
else:
    a=[]
    for x in range(2,(len(newres)-2),2):
        if(newres[x]=='1' and newres[x+1]=='0'):
            a.append(1)
        elif(newres[x]=='0' and newres[x+1]=='1'):
            a.append(0)
    else:
        for i in a:
            print(i,end='')