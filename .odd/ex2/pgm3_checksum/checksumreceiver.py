MyFile=open('intermediate.txt','r')
newres=MyFile.read()
MyFile.close()

res=[]
i=0
k=0
newmess=[]
f=[]


for i in newres:
    if(i.isalnum()):                                    #removing special character '[]' from file read
        res.append(i)
        
count=1
newmess=[]
i=0
r=0
l=len(res)

rem=(len(res)//8)
#print(rem)

while i<l:
    if(count%8==0):
        if(r<rem):
             newmess.insert(r,(res[:(i+1)]))
             res=res[(i+1):]                         #dividing message into 8bits
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
            if(newmess[flag][i]=='1' and newmess[flag+1][i]=='1' and borrow==0):                    #Binary adition without using inbuilt function
                h.insert(v,'0')
                borrow=1
                v+=1
                i-=1
            if(newmess[flag][i]=='1' and newmess[flag+1][i]=='1' and borrow==1):
                h.insert(v,'1')
                borrow=1
                v+=1
                i-=1
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

#print("result",str(h))

w=['0','0','0','0','0','0','0','0']
if(w==h):
    print("Recieved Message")
    re=(rem-1)*8
    for i in newres:
        if(i.isalnum()):                            #print recieved message
            f.append(i)
    for i in range(0,re,1):
        print(f[i],end="")
else:
    print("Message corrupted")
