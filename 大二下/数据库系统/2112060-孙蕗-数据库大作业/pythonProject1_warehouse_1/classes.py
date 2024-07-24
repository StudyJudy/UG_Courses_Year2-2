from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField
from wtforms.validators import DataRequired

class addproduct(FlaskForm):
    Product_id = StringField('product_id: ', validators=[DataRequired()])
    Product_name = StringField('product_name: ', validators=[DataRequired()])
    Product_type_id = StringField('product_type_id: ', validators=[DataRequired()])
    Product_sum = StringField('product_sum: ', validators=[DataRequired()])
    submit = SubmitField('submit', validators=[DataRequired()])

class addproduct_type(FlaskForm):
    Product_type_id = StringField('product_type_id: ', validators=[DataRequired()])
    Product_type_name = StringField('product_type_name: ', validators=[DataRequired()])
    submit = SubmitField('submit', validators=[DataRequired()])

class addwarehouse(FlaskForm):
    Warehouse_id = StringField('warehouse_id: ', validators=[DataRequired()])
    Warehouse_name = StringField('warehouse_name: ', validators=[DataRequired()])
    Warehouse_location = StringField('warehouse_location: ', validators=[DataRequired()])
    submit = SubmitField('submit', validators=[DataRequired()])

class AddOutboundRecords(FlaskForm):
    ID_outbound_ = StringField('outbound_id: ', validators=[DataRequired()])
    ID_manager_out_personnel_ = StringField('manager_id: ', validators=[DataRequired()])
    ID_customer_personnel_ = StringField('customer_id: ', validators=[DataRequired()])
    ID_warehouse_ = StringField('warehouse_id: ', validators=[DataRequired()])
    ID_product_ = StringField('product_id: ', validators=[DataRequired()])
    Sum_outbound_ = StringField('outbound_sum: ', validators=[DataRequired()])
    Date_outbound_ = StringField('outbound_date: ', validators=[DataRequired()])
    submit = SubmitField('submit', validators=[DataRequired()])

class AddInboundRecords(FlaskForm):
    ID_inbound_ = StringField('inbound_id: ', validators=[DataRequired()])
    ID_manager_in_personnel_ = StringField('manager_id: ', validators=[DataRequired()])
    ID_supplier_personnel_ = StringField('supplier_id: ', validators=[DataRequired()])
    ID_warehouse_ = StringField('warehouse_id: ', validators=[DataRequired()])
    ID_product_ = StringField('product_id: ', validators=[DataRequired()])
    Sum_inbound_ = StringField('inbound_sum: ', validators=[DataRequired()])
    Date_inbound_ = StringField('inbound_date: ', validators=[DataRequired()])
    submit = SubmitField('submit', validators=[DataRequired()])

class Deleteproducts(FlaskForm):
    Product_ID=StringField('product_id: ' , validators=[DataRequired()])
    submit = SubmitField('submit', validators=[DataRequired()])

class Manager(FlaskForm):
    Manager_ID=StringField('manager_id: ' , validators=[DataRequired()])
    Manager_Name=StringField('manager_name: ' , validators=[DataRequired()])
    Manager_Tel = StringField('manager_tel: ', validators=[DataRequired()])
    Manager_Password=StringField('manager_password: ' , validators=[DataRequired()])
    submit = SubmitField('submit', validators=[DataRequired()])

class Customer(FlaskForm):
    Customer_ID = StringField('customer_id: ', validators=[DataRequired()])
    Customer_Name = StringField('customer_name: ', validators=[DataRequired()])
    Customer_Tel = StringField('customer_tel: ', validators=[DataRequired()])
    Customer_Location=StringField('customer_location: ' , validators=[DataRequired()])
    Customer_Password = StringField('customer_password: ', validators=[DataRequired()])
    submit = SubmitField('submit', validators=[DataRequired()])

class Supplier(FlaskForm):
    Supplier_ID = StringField('supplier_id: ', validators=[DataRequired()])
    Supplier_Name = StringField('supplier_name: ', validators=[DataRequired()])
    Supplier_Tel = StringField('supplier_Tel: ', validators=[DataRequired()])
    Supplier_Location=StringField('supplier_location: ' , validators=[DataRequired()])
    Supplier_Password = StringField('supplier_password: ', validators=[DataRequired()])
    submit = SubmitField('submit', validators=[DataRequired()])

class View_inbound(FlaskForm):
    View_inbound_warehouse_name = StringField('warehouse_in_name: ', validators=[DataRequired()])
    View_inbound_product_name = StringField('product_in_name: ', validators=[DataRequired()])
    submit = SubmitField('submit', validators=[DataRequired()])

class View_outbound(FlaskForm):
    View_outbound_warehouse_name = StringField('warehouse_out_name: ', validators=[DataRequired()])
    View_outbound_product_name = StringField('product_out_name: ', validators=[DataRequired()])
    submit = SubmitField('submit', validators=[DataRequired()])