strs=["aaa","aa","aaa"]
str=strs[0]
res=[]
str=list(str)
for i in range(0,len(strs)):
    res=[]
    for j in range(0,len(strs[i])):
        if j<len(str):
            if str[j]==strs[i][j]:
                res.append(strs[i][j])
            else :
                str=[]
                str=res
                res=[]
                break
            if j==len(strs[i])-1:
                res=[]
src=''.join(str)
if len(src)>len(strs[-1]):
    print(strs[-1])
else:
    print(src)
