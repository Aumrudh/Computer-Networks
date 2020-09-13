message=input("Enter message:")
res=[str(x) for x in message]

count=1
newmess=[]
li=[]
i=0
r=0
z=0
size=len(res)

if size%8!=0:
    nsize=size+8                           #if size of message less than 7 append 0 at last
    n=nsize%8
    zsize=nsize-n
    additional=zsize-size
    while z<=additional:
         res.insert(0,'0')
         z+=1

#print("List",str(res))

rem=(len(res)/8)
rem=int(rem)
print("rem",rem)

l=len(res)

while i<l:
    if(count%8==0):
        if(r<rem):
             newmess.insert(r,(res[:(i+1)]))
             res=res[(i+1):]
             i=0
             l=len(res)
             r+=1
    else:
        i+=1
    count+=1

flag=0
borrow=0
h=[]
first=0
v=0

i=7
n=7
while flag<rem:
    if(first!=1):    
        while i>=0:
            if(newmess[flag][i]=='0' and newmess[flag+1][i]=='0' and borrow==0):
                h.insert(v,'0')
                borrow=0
                v+=1
                i-=1
            if(newmess[flag][i]=='0' and newmess[flag+1][i]=='0' and borrow==1):
                h.insert(v,'1')
                borrow=0
                v+=1
                i-=1
            if(newmess[flag][i]=='1' and newmess[flag+1][i]=='1' and borrow==0):
                h.insert(v,'0')
                borrow=1
                v+=1
                i-=1
            if(newmess[flag][i]=='1' and newmess[flag+1][i]=='1' and borrow==1):
                h.insert(v,'1')
                borrow=1
                v+=1
                i-=1
                print("111")
            if(newmess[flag][i]=='0' and newmess[flag+1][i]=='1' and borrow==0):
                h.insert(v,'1')
                borrow=0
                v+=1
                i-=1
            if(newmess[flag][i]=='0' and newmess[flag+1][i]=='1' and borrow==1):
                h.insert(v,'0')
                borrow=1
                v+=1
                i-=1
            if(newmess[flag][i]=='1' and newmess[flag+1][i]=='0' and borrow==0):
                h.insert(v,'1')
                borrow=0
                v+=1
                i-=1
            if(newmess[flag][i]=='1' and newmess[flag+1][i]=='0' and borrow==1):
                h.insert(v,'0')
                borrow=1
                v+=1
                i-=1
            first=1
            #i-=1
        h=h[::-1]
       # print(str(h))
        borrow=0
        flag+=2
    else:
        for n in range(7,-1,-1):
            if(newmess[flag][n]=='0' and h[n]=='0' and borrow==0):
                h.pop(n)
                h.insert(n,'0')
                borrow=0
            if(newmess[flag][n]=='0' and h[n]=='0' and borrow==1):
                h.pop(n)
                h.insert(n,'1')
                borrow=0
            if(newmess[flag][n]=='1' and h[n]=='1' and borrow==0):
                h.pop(n)
                h.insert(n,'0')
                borrow=1
            if(newmess[flag][n]=='1' and h[n]=='1' and borrow==1):
                h.pop(n)
                h.insert(n,'1')
                borrow=1
            if(newmess[flag][n]=='0' and h[n]=='1' and borrow==0):
                h.pop(n)
                h.insert(n,'1')
                borrow=0
            if(newmess[flag][n]=='0' and h[n]=='1' and borrow==1):
                h.pop(n)
                h.insert(n,'0')
                borrow=1
            if(newmess[flag][n]=='1' and h[n]=='0' and borrow==0):
                h.pop(n)
                h.insert(n,'1')
                borrow=0
            if(newmess[flag][n]=='1' and h[n]=='0' and borrow==1):
                h.pop(n)
                h.insert(n,'0')
                borrow=1
        #h=h[::-1]
        borrow=0
        flag+=1        

print("result",str(h))

comp=0
twocomp=[]
for i in range(7,-1,-1):
    if(h[i]=='1' and comp==0):
        comp=1
        twocomp.append(h[i])
    elif(h[i]=='1' and comp==1):
        twocomp.append('0')
    elif(h[i]=='0' and comp==1):
        twocomp.append('1')

twocomp=twocomp[::-1]
print("2comp",str(twocomp))
newmess.append(twocomp)
print("intermediate result",str(newmess))
        
        

