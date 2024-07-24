import pymysql
import mysql.connector
import traceback
from flask import render_template

def add_product(Product_id, Product_name, Product_type_id, Product_sum):
    conn = mysql.connector.connect(
        host="localhost",
        port=3306,
        user="root",
        password="mysqlsystem",
        database="warehouse_1",
        charset="utf8mb4"
    )
    cursor = conn.cursor()
    sql = "insert into products(product_id,product_name,product_type_id,product_sum) VALUES (%s,%s,%s,%s);"
    str_ = ''
    try:
        # 执行SQL语句
        cursor.execute(sql, [Product_id, Product_name, Product_type_id, Product_sum])
        # 提交事务
        conn.commit()

        str_ = 'Success'
    except Exception as e:
        # 有异常，回滚事务
        print('traceback.format_exc():\n%s' % traceback.format_exc())
        conn.rollback()
        str_ = str(e)

    cursor.close()
    conn.close()
    return str_

def add_product_type(Product_type_id, Product_type_name):
    conn = mysql.connector.connect(
        host="localhost",
        port=3306,
        user="root",
        password="mysqlsystem",
        database="warehouse_1",
        charset="utf8mb4"
    )
    cursor = conn.cursor()
    sql = "insert into product_type(product_type_id,product_type_id_name) VALUES (%s, %s);"
    str_ = ''
    try:
        # 执行SQL语句
        cursor.execute(sql, [Product_type_id, Product_type_name])
        # 提交事务
        conn.commit()

        str_ = 'Success'
    except Exception as e:
        # 有异常，回滚事务
        print('traceback.format_exc():\n%s' % traceback.format_exc())
        conn.rollback()
        str_ = str(e)

    cursor.close()
    conn.close()
    return str_

def add_warehouse(Warehouse_id, Warehouse_name,Warehouse_location):
    conn = mysql.connector.connect(
        host="localhost",
        port=3306,
        user="root",
        password="mysqlsystem",
        database="warehouse_1",
        charset="utf8mb4"
    )
    cursor = conn.cursor()
    sql = "insert into warehouse(warehouse_id,warehouse_name,warehouse_location) VALUES (%s,%s,%s);"
    str_ = ''
    try:
        # 执行SQL语句
        cursor.execute(sql, [Warehouse_id, Warehouse_name,Warehouse_location])
        # 提交事务
        conn.commit()

        str_ = 'Success'
    except Exception as e:
        # 有异常，回滚事务
        print('traceback.format_exc():\n%s' % traceback.format_exc())
        conn.rollback()
        str_ = str(e)

    cursor.close()
    conn.close()
    return str_

def add_outbound_records_func(ID_outbound_, ID_manager_out_personnel_ , ID_customer_personnel_ , ID_warehouse_ ,  ID_product_ , Sum_outbound_ , Date_outbound_):
    conn = mysql.connector.connect(
        host="localhost",
        port=3306,
        user="root",
        password="mysqlsystem",
        database="warehouse_1",
        charset="utf8mb4"
    )
    cursor = conn.cursor()
    sql = "call subProductSum(%s,%s,%s,%s,%s,%s,%s);"
    str_ = ''
    try:
        # 执行SQL语句
        cursor.execute(sql, [ID_outbound_ , ID_manager_out_personnel_ , ID_customer_personnel_ , ID_warehouse_ , ID_product_ , Sum_outbound_ , Date_outbound_])
        # 提交事务
        conn.commit()
        str_ = 'Success'

    except Exception as e:
        # 有异常，回滚事务
        print('traceback.format_exc():\n%s' % traceback.format_exc())
        conn.rollback()
        str_ = str(e)
    cursor.close()
    conn.close()
    return str_

def add_inbound_records_func(ID_inbound_ , ID_manager_in_personnel_ , ID_supplier_personnel_ , ID_warehouse_ ,  ID_product_ , Sum_inbound_ , Date_inbound_):
    conn = mysql.connector.connect(
        host="localhost",
        port=3306,
        user="root",
        password="mysqlsystem",
        database="warehouse_1",
        charset="utf8mb4"
    )
    cursor = conn.cursor()
    sql = "call addProductSum(%s,%s,%s,%s,%s,%s,%s);"
    str_ = ' '
    try:
        # 执行SQL语句
        cursor.execute(sql, [ID_inbound_, ID_manager_in_personnel_, ID_supplier_personnel_ , ID_warehouse_ , ID_product_ , Sum_inbound_ , Date_inbound_])
        # 提交事务
        conn.commit()
        str_ = 'Success'

    except Exception as e:
        # 有异常，回滚事务
        print('traceback.format_exc():\n%s' % traceback.format_exc())
        conn.rollback()
        str_ = str(e)

    cursor.close()
    conn.close()
    return str_

def delete_products(Product_ID):
    conn =mysql.connector.connect(
        host="localhost",
        port=3306,
        user="root",
        password="mysqlsystem",
        database="warehouse_1",
        charset="utf8mb4"
    )
    cursor = conn.cursor()
    sql = "call delete_product(%s);"
    try:
        cursor.execute(sql, [Product_ID])
        # 运行成功，提交事务
        conn.commit()
        str_ = 'Success'

    except Exception as e:
        # 有异常，回滚事务
        print('traceback.format_exc():\n%s' % traceback.format_exc())
        conn.rollback()
        str_ = str(e)

    cursor.close()
    conn.close()
    return str_

def add_Manager(Manager_ID, Manager_Name, Manager_Tel,Manager_Password):
    conn = mysql.connector.connect(
        host="localhost",
        port=3306,
        user="root",
        password="mysqlsystem",
        database="warehouse_1",
        charset="utf8mb4"
    )
    cursor = conn.cursor()
    sql = "call personnel_updating_manager(%s,%s,%s,%s);"
    str_ = ''
    try:
        cursor.execute(sql, [Manager_ID, Manager_Name, Manager_Tel,Manager_Password])
        conn.commit()
        str_ = 'Success'
    except Exception as e:
        # 有异常，回滚事务
        print('traceback.format_exc():\n%s' % traceback.format_exc())
        conn.rollback()
        str_ = str(e)
    cursor.close()
    conn.close()
    return str_

def add_Customer(Customer_ID, Customer_Name, Customer_Tel,Customer_Location,Customer_Password):
    conn = mysql.connector.connect(
        host="localhost",
        port=3306,
        user="root",
        password="mysqlsystem",
        database="warehouse_1",
        charset="utf8mb4"
    )
    cursor = conn.cursor()
    sql = "call personnel_updating_customer(%s,%s,%s,%s,%s);"
    str_ = ''
    try:
        cursor.execute(sql, [Customer_ID, Customer_Name, Customer_Tel,Customer_Location,Customer_Password])
        conn.commit()
        str_ = 'Success'
    except Exception as e:
        # 有异常，回滚事务
        print('traceback.format_exc():\n%s' % traceback.format_exc())
        conn.rollback()
        str_ = str(e)
    cursor.close()
    conn.close()
    return str_

def add_Supplier(Supplier_ID, Supplier_Name, Supplier_Tel,Supplier_Location,Supplier_Password):
    conn = mysql.connector.connect(
        host="localhost",
        port=3306,
        user="root",
        password="mysqlsystem",
        database="warehouse_1",
        charset="utf8mb4"
    )
    cursor = conn.cursor()
    sql = "call personnel_updating_supplier(%s,%s,%s,%s,%s);"
    str_ = ''
    try:
        cursor.execute(sql, [Supplier_ID, Supplier_Name, Supplier_Tel,Supplier_Location,Supplier_Password])
        conn.commit()
        str_ = 'Success'
    except Exception as e:
        # 有异常，回滚事务
        print('traceback.format_exc():\n%s' % traceback.format_exc())
        conn.rollback()
        str_ = str(e)
    cursor.close()
    conn.close()
    return str_

def View_Inbound(View_inbound_warehouse_name, View_inbound_product_name):
    conn = mysql.connector.connect(
        host="localhost",
        port=3306,
        user="root",
        password="mysqlsystem",
        database="warehouse_1",
        charset="utf8mb4"
    )
    cursor = conn.cursor()

    sql = "select *\
            from in_order_view\
            where warehouse_name=%s and product_name=%s;"
    try:

        cursor.execute(sql, [View_inbound_warehouse_name, View_inbound_product_name])
        rs = cursor.fetchall()
        return render_template('selectformin.html', rs=rs)
    except Exception as e:
        print('traceback.format_exc():\n%s' % traceback.format_exc())
        conn.rollback()
        str_ = str(e)
        return str_

def View_Outbound(View_outbound_warehouse_name, View_outbound_product_name):
    conn = mysql.connector.connect(
        host="localhost",
        port=3306,
        user="root",
        password="mysqlsystem",
        database="warehouse_1",
        charset="utf8mb4"
    )
    cursor = conn.cursor()

    sql = "select *\
            from out_order_view\
            where warehouse_name=%s and product_name=%s;"
    try:

        cursor.execute(sql, [View_outbound_warehouse_name, View_outbound_product_name])
        rs = cursor.fetchall()
        return render_template('selectformout.html', rs=rs)
    except Exception as e:
        print('traceback.format_exc():\n%s' % traceback.format_exc())
        conn.rollback()
        str_ = str(e)
        return str_