num=input("Enter your value:")
res=[str(x) for x in str(num)]

for x in range(len(res)):
    if(res[x]=='0'):
        res[x]='01'  #1=01
    elif(res[x]=='1'):
        res[x]='10'

res.insert(0,'00');
res.insert((len(res)),'11');



res=[str(x) for x in res]

MyFile=open('intermediate.txt','w')
for element in res:
    MyFile.write(element)
    #MyFile.write('\n');
MyFile.close();


print("Written into intermediate file")

