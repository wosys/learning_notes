# Python数据库操作（1）
---
Python 定义了一套操作数据库的 API 接口，任何数据库要连接到Python，只需要提供符合 Python 标准的数据库驱动即可。
## SQLite：
SQLite 是一种嵌入式数据库，它的数据库就是一个文件。Python 内置了 SQLite3，所以，在 Python 中使用 SQLite，不需要安装任何东西，直接使用。
  
#### 数据库文件的创建：
```
import sqlite # 导入SQLite驱动
conn = sqlite3.connect('test.db') # 连接到SQLite数据库，数据库文件是test.db，如果不存在就在当前目录自动创建
cursor = conn.cursor() # 创建一个Cursor
cursor.execute('create table user (id varchar(20) primary key, name varchar(20))') # 执行一条 SQL 语句，创建 user 表 
cursor.execute('insert into user (id, name) values (\'01\', \'zhangsan\')') # 继续执行一条 SQL 语句，插入一条记录
cursor.execute('insert into user (id, name) values (\'02\', \'lisi\')') # 再插入一条记录
cursor.close() # 关闭 Cursor 
conn.commit() # 提交事务 
conn.close() # 关闭 Connection
```
#### 查询记录：
```
import sqlite 
conn = sqlite3.connect('test.db') 
cursor = conn.cursor()
cursor.execute('select * from user where id=?', '1') 
values = cursor.fetchall() # 通过 featchall()可以拿到结果集。结果集是一个列表，每个元素都是一个字典，对应一行记录。 
print(values)
cursor.close()
conn.close()
```

    [('1', 'zhangsan')] # 获得的查询结果集

#### 小结：
SQLite 支持常见的标准 SQL 语句以及几种常见的数据类型。
在 Python 中操作数据库时，要先导入数据库对应的驱动，然后通过Connection 对象和 Cursor 对象操作数据。 
要确保打开的 Connection 对象和 Cursor 对象最后要被关闭，否则，资源就会泄露。最直接的就是调用close()方法，也可以用异常处理，try:...except:...finally:...
***
***参考资料***：
[1]《廖雪峰的python3》 https://github.com/michaelliao/learn-python3
[2]SQLite官网  www.sqlite.org/
