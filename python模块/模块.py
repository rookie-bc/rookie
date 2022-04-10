import my_add
a=10
b=20
c=my_add.add_me(a,b)
print(c)

print()
my_add.print_me(3)


import my_add as ad        #使用as将模块名改写成其他的
a=2
b=4
c=ad.add_me(a,b)
print(c)


#from my_add import *       #使用*将模块中所有代码复制过来，
                            #并且可以不用使用.来引用代码
