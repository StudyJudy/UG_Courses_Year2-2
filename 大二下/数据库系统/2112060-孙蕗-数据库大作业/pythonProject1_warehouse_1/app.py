from flask import Flask, render_template
from flask_bootstrap import Bootstrap
from flask_nav import Nav
from flask_nav.elements import *
from classes import *
from sql_func import *
#这页''里的都是在app里定义的
nav = Nav()
nav.register_element('top', Navbar(
    u'仓库管理系统',
    View(u'主页', 'index'),
    Subgroup(u'个人信息',
             View(u'管理员', 'Add_Mn'),  # 第二对引号内为函数命
             Separator(),
             View(u'供货商', 'Add_S'),
             Separator(),
             View(u'客户', 'Add_C')),
    Subgroup(u'商品',
             View (u'商品类型添加','Add_Product_type'),
             Separator(),
             View(u'商品添加', 'Add_Product'),
             Separator(),
             View(u'商品删除', 'Delete_Products')),
    View(u'仓库添加', 'Add_Warehouse'),
    Subgroup(u'出入库信息查询',
             View(u'入库信息查询', 'ViewInbound'),
             Separator(),
             View(u'出库信息查询', 'ViewOutbound')),
    Subgroup(u'出入库表信息添加',
             View(u'入库表', 'Add_Inbound_Records'),
             Separator(),
             View(u'出库表', 'Add_Outbound_Records')),
))

app = Flask(__name__)
app.secret_key = 'mysqlsystem'
Bootstrap(app)
nav.init_app(app)


@app.route('/')
def index():
    return render_template('index.html')

@app.route('/Add_Product_type/', methods=['Get', 'Post'])
def Add_Product_type():
    form = addproduct_type()
    if form.validate_on_submit():
        Product_type_id = form.data['Product_type_id']
        Product_type_name = form.data['Product_type_name']
        temp = add_product_type(Product_type_id,Product_type_name)
        return temp
    return render_template('form.html', form=form)

@app.route('/Add_Product/', methods=['Get', 'Post'])
def Add_Product():
    form = addproduct()
    if form.validate_on_submit():
        Product_id = form.data['Product_id']
        Product_name = form.data['Product_name']
        Product_type_id = form.data['Product_type_id']
        Product_sum = form.data['Product_sum']
        temp = add_product(Product_id, Product_name, Product_type_id, Product_sum)
        return temp
    return render_template('form.html', form=form)

@app.route('/Add_Warehouse/', methods=['Get', 'Post'])
def Add_Warehouse():
    form = addwarehouse()
    if form.validate_on_submit():
        Warehouse_id = form.data['Warehouse_id']
        Warehouse_name = form.data['Warehouse_name']
        Warehouse_location = form.data['Warehouse_location']
        temp = add_warehouse(Warehouse_id, Warehouse_name,Warehouse_location)
        return temp
    return render_template('form.html', form=form)


@app.route('/Delete_Products/', methods=['Get', 'Post'])
def Delete_Products():
    form = Deleteproducts()
    if form.validate_on_submit():
        Product_ID = form.data['Product_ID']
        temp = delete_products(Product_ID)
        return temp
    return render_template('form.html', form=form)

@app.route('/Add_Inbound_Records/', methods=['Get', 'Post'])
def Add_Inbound_Records():
    form = AddInboundRecords()
    if form.validate_on_submit():
        ID_inbound_ = form.data['ID_inbound_']
        ID_manager_in_personnel_ = form.data['ID_manager_in_personnel_']
        ID_supplier_personnel_ = form.data['ID_supplier_personnel_']
        ID_warehouse_ = form.data['ID_warehouse_']
        ID_product_ = form.data['ID_product_']
        Sum_inbound_=form.data['Sum_inbound_']
        Date_inbound_ = form.data['Date_inbound_']
        temp = add_inbound_records_func(ID_inbound_ , ID_manager_in_personnel_ , ID_supplier_personnel_ , ID_warehouse_ ,  ID_product_ , Sum_inbound_ , Date_inbound_)
        return temp
    return render_template('form.html', form=form)

@app.route('/Add_Outbound_Records/', methods=['Get', 'Post'])
def Add_Outbound_Records():
    form = AddOutboundRecords()
    if form.validate_on_submit():
        ID_outbound_ = form.data['ID_outbound_']
        ID_manager_out_personnel_ = form.data['ID_manager_out_personnel_']
        ID_customer_personnel_ = form.data['ID_customer_personnel_']
        ID_warehouse_ = form.data['ID_warehouse_']
        ID_product_ = form.data['ID_product_']
        Sum_outbound_=form.data['Sum_outbound_']
        Date_outbound_ = form.data['Date_outbound_']
        temp = add_outbound_records_func(ID_outbound_, ID_manager_out_personnel_ , ID_customer_personnel_ , ID_warehouse_ ,  ID_product_ , Sum_outbound_ , Date_outbound_)
        return temp
    return render_template('form.html', form=form)

@app.route('/Add_M/', methods=['Get', 'Post'])
def Add_M():
    form = Manager()
    if form.validate_on_submit():
        Manager_ID = form.data['Manager_ID']
        Manager_Name = form.data['Manager_Name']
        Manager_Tel = form.data['Manager_Tel']
        Manager_Password = form.data['Manager_Password']
        return add_Manager(Manager_ID, Manager_Name, Manager_Tel,Manager_Password)
    return render_template('form.html', form=form)

@app.route('/Add_Mn/', methods=['Get', 'Post'])
def Add_Mn():
    form = Manager()
    if form.validate_on_submit():
        Manager_ID = form.data['Manager_ID']
        Manager_Name = form.data['Manager_Name']
        Manager_Tel = form.data['Manager_Tel']
        Manager_Password = form.data['Manager_Password']
        return add_Manager(Manager_ID, Manager_Name, Manager_Tel,Manager_Password)
    return render_template('form.html', form=form)

@app.route('/Add_C/', methods=['Get', 'Post'])
def Add_C():
    form = Customer()
    if form.validate_on_submit():
        Customer_ID = form.data['Customer_ID']
        Customer_Name = form.data['Customer_Name']
        Customer_Tel = form.data['Customer_Tel']
        Customer_Location = form.data['Customer_Location']
        Customer_Password = form.data['Customer_Password']
        return add_Customer(Customer_ID, Customer_Name, Customer_Tel,Customer_Location,Customer_Password)
    return render_template('form.html', form=form)

@app.route('/Add_S/', methods=['Get', 'Post'])
def Add_S():
    form = Supplier()
    if form.validate_on_submit():
        Supplier_ID = form.data['Supplier_ID']
        Supplier_Name = form.data['Supplier_Name']
        Supplier_Tel = form.data['Supplier_Tel']
        Supplier_Location = form.data['Supplier_Location']
        Supplier_Password = form.data['Supplier_Password']
        return add_Supplier(Supplier_ID, Supplier_Name, Supplier_Tel,Supplier_Location,Supplier_Password)
    return render_template('form.html', form=form)

@app.route('/ViewInbound/', methods=['Get', 'Post'])
def ViewInbound():
    form = View_inbound()
    if form.validate_on_submit():
        View_inbound_warehouse_name = form.data['View_inbound_warehouse_name']
        View_inbound_product_name = form.data['View_inbound_product_name']
        temp =  View_Inbound(View_inbound_warehouse_name, View_inbound_product_name)
        return temp
    return render_template('form.html', form=form)

@app.route('/ViewOutbound/', methods=['Get', 'Post'])
def ViewOutbound():
    form = View_outbound()
    if form.validate_on_submit():
        View_outbound_warehouse_name = form.data['View_outbound_warehouse_name']
        View_outbound_product_name = form.data['View_outbound_product_name']
        temp =  View_Outbound(View_outbound_warehouse_name, View_outbound_product_name)
        return temp
    return render_template('form.html', form=form)






if __name__ == '__main__':
    app.run()