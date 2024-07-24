import mysql.connector

try:
    # 连接MySQL数据库
    cnx = mysql.connector.connect(
        host='localhost',
        user='root',
        password='mysqlsystem',
        database='warehouse_1'
    )

    # 打印连接成功信息
    print("成功连接到MySQL数据库")

    # 关闭连接
    cnx.close()

except mysql.connector.Error as err:
    # 打印连接错误信息
    print("连接MySQL数据库时发生错误:", err)
