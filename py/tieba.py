#-- coding: utf-8 --
#��ȡ�����ذٶ����ɵ�html�ļ�
#���ߣ�����IPC
#------------------------------------------------
 
import string #����ģ��
from urllib2 import urlopen  #����urllib2���е�ģ��
 
#---------------------------------
#���庯��  
def paqutieba(url,x,y):     
    for j in range(x, y+1):  #ѭ���ӿ�ʼҳ�浽�յ�ҳ��
        Name = string.zfill(j,5) + '.html'  #string.zfill��1,5�� �ļ���Ч��00001.
        print '�������ص�' + str(j) + '����ҳ���ݣ�������洢Ϊ' + Name + '......'  #���ص�ʱ���ӡ
        l = open(Name,'w+')  #��д�������ֵ������l
        k = urlopen(url + str(j)).read()   #����urlopenģ��ץȡ��ҳ���ݲ��鿴����ֵ������k
        l.write(k)  #��k����д��
        l.close()  #�ر�
#---------------------------------���û�����---------------
url = str(raw_input(u'���������ɵĵ�ַ��ȥ��?pn=��������֣�\n��ʽ:https://tieba.baidu.com/p/xxxxxxxxx?pn= \n>>>'))  
x = int(raw_input(u'�����뿪ʼ��ҳ����\n'))  
y = int(raw_input(u'�������յ��ҳ����\n'))  
 
paqutieba(url,x,y)  #���ú���