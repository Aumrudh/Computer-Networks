num=input("Enter your message:")
res=[str(x) for x in str(num)]

res.insert(0,'s')
res.insert(1,'t')
res.insert(2,'x')

a=len(res)
x=3

while x<=a:
    if(res[x]=='d' and res[x+1]=='l' and res[x+2]=='e'):
        g=x-1
        res.insert((g+1),'d')
        res.insert((g+2),'l')
        res.insert((g+3),'e')
        x+=6;

    elif(res[x]=='e' and res[x+1]=='t' and res[x+2]=='x'):
        h=x-1
        res.insert((h+1),'d')
        res.insert((h+2),'l')
        res.insert((h+3),'e')
        x+=6;
    else:
        x+=1;

res.insert((len(res)),'e')
res.insert((len(res)+1),'t')
res.insert((len(res)+2),'x')

for z in res:
    print(z,end="")

MyFile=open('intermediate.txt','w')
for element in res:
    MyFile.write(element)
MyFile.close();

print("\n Written into intermediate file")
