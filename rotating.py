lis1=input().split()
shift=int(input())
print(len(lis1))

for i in range(0,shift):
    temp=lis1[0]

    for j in range(0,len(lis1)-1):
        lis1[j]=lis1[j+1]
    lis1[len(lis1)-1]=temp 

print(lis1)