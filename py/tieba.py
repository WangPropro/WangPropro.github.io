#-- coding: utf-8 --
#爬取并下载百度贴吧的html文件
#作者：秦王IPC
#------------------------------------------------
 
import string #调用模块
from urllib2 import urlopen  #调用urllib2库中的模块
 
#---------------------------------
#定义函数  
def paqutieba(url,x,y):     
    for j in range(x, y+1):  #循环从开始页面到终点页面
        Name = string.zfill(j,5) + '.html'  #string.zfill（1,5） 文件名效果00001.
        print '正在下载第' + str(j) + '个网页内容，并将其存储为' + Name + '......'  #下载的时候打印
        l = open(Name,'w+')  #将写入操作赋值给变量l
        k = urlopen(url + str(j)).read()   #调用urlopen模块抓取网页内容并查看并赋值给变量k
        l.write(k)  #将k内容写入
        l.close()  #关闭
#---------------------------------与用户交互---------------
url = str(raw_input(u'请输入贴吧的地址，去掉?pn=后面的数字：\n格式:https://tieba.baidu.com/p/xxxxxxxxx?pn= \n>>>'))  
x = int(raw_input(u'请输入开始的页数：\n'))  
y = int(raw_input(u'请输入终点的页数：\n'))  
 
paqutieba(url,x,y)  #调用函数