MyFile=open('intermediate.txt','r')
newres=MyFile.read()
MyFile.close()       
print("Received Message")
z=[]
a=len(newres)-3
x=3
k=0

if(newres[0]!='s' or newres[1]!='t' or newres[2]!='x'):
   print("Start of text error")
elif(newres[len(newres)-1]!='x' or newres[len(newres)-2]!='t' or newres[len(newres)-3]!='e'):
   print("End of text error") 
else:
       while x<a:
               if(newres[x]=='d' and newres[x+1]=='l' and newres[x+2]=='e'):
                  if((newres[x+3]=='d' or newres[x+3]=='e') and (newres[x+3]=='l' or newres[x+3]=='t') and (newres[x+3]=='e' or newres[x+3]=='x')):
                       z.insert(k,newres[x])
                       z.insert(k+1,newres[x+1])
                       z.insert(k+2,newres[x+2])
                       k+=3
                       x+=6
                  else:
                      print("DLE error")
                      break

               else:
                    z.insert(k,newres[x])
                    k+=1
                    x+=1
for i in z:
    print(i,end="")