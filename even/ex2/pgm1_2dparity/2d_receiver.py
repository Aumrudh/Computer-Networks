File=open('intermediate_message.txt','r')
temp=File.read()
File.close()
#print(len(temp))
rem=len(temp)%8
flag=0
if rem==0:
    flag=1
if flag==1:
    #print("No error in nos of bits")
    l=[]
    t=len(temp)
    i=0
    while i<t:
        a=temp[:8]
        a=list(a)
        temp=temp[8:]
        t=len(temp)
        l.append(a)
    #print("Sender Message : ",end=' ')    
    #print(l,end='\n')
    lis=[]
    sum=''
    col_parity=''
    for i in range(0,8):
        for j in range(len(l)):
            sum+=l[j][i]
        setBits = [ones for ones in sum if ones=='1']
        s=len(setBits) 
        if s%2==0:
            s='0'
        else:
            s='1'
        #lis.append(s)
        col_parity+=s
        sum=''
    print("Column Parity : ",col_parity)  
    #for i in lis:
    #    col_parity+=i
    #print(col_parity)
    #l.append(lis)
    #print("Column Parity Appended To list: ",end=' ')   
    #print(l,end='\n')
    rl=''
    for i in range(len(l)):
        setBits = [ones for ones in l[i] if ones=='1']
        #print(setBits)
        s=len(setBits)
        if s%2==0:
            s='0'
        else:
            s='1'
        rl+=s
        #s=list(s)        
        #l[i]=l[i]+s
    #print(len(l))
    print("Row parity : ",rl)
    row_parity_final=''
    for i in range(0,len(l)):
        row_parity_final+='0'
    #print(row_parity_final)
    if(row_parity_final==rl) and col_parity=='00000000':
        print("No error in Message")
    else:
        print("Transmission Error")
else:
    print("Error in no of bits")