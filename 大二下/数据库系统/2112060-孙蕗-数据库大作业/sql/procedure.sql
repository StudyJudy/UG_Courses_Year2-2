drop procedure if exists subProductSum ;
create procedure subProductSum (ID_outbound INT,ID_manager_out_personnel INT,ID_customer_personnel INT,ID_warehouse INT,ID_product INT,Sum_outbound INT,Date_outbound INTEGER)
    begin
        declare product_sum INT(8);
        set product_sum=(select product_sum_current from products
            where product_id=ID_product);
        insert into outbound(outbound_id,manager_out_personnel_id,customer_personnel_id,warehouse_id,product_id,outbound_sum,outbound_date)
            values(ID_outbound,ID_manager_out_personnel,ID_customer_personnel,ID_warehouse,ID_product,Sum_outbound,Date_outbound);
        if (product_sum-Sum_outbound <0) then
            signal sqlstate 'HY000' set message_text='请重新检查出库信息';
        else set product_sum=product_sum-Sum_outbound;
            update products set product_sum_current=product_sum where product_id=ID_product;   
        end if;     
    end;

drop procedure if exists addProductSum ;
create procedure addProductSum (ID_inbound INT,ID_manager_in_personnel INT,ID_supplier_personnel INT,ID_warehouse INT,ID_product INT,Sum_inbound INT,Date_inbound INTEGER)
    begin
        declare product_sum INT(8);
        set product_sum=(select product_sum_current from products
            where product_id=ID_product);
        insert into inbound(inbound_id,manager_in_personnel_id,supplier_personnel_id,warehouse_id,product_id,inbound_sum,inbound_date)
            values(ID_inbound,ID_manager_in_personnel,ID_supplier_personnel,ID_warehouse,ID_product,Sum_inbound,Date_inbound);
        set product_sum=product_sum+Sum_outbound;
        update products
        set product_sum_current=product_sum
            where product_id=ID_product;
    end;

drop procedure if exists delete_product;
create procedure delete_product(productid_ INT)
    begin
        if exists(select * from products where product_sum >0) then
            signal sqlstate 'HY000' set message_text='请先将该商品全部出库';
            else delete from products where product_id=productid_;
        end if;
    end;

drop procedure if exists personnel_updating_cn;
create procedure personnel_updating_cn(ID_personnel INT,name_personnel VARCHAR(20),tel_personnel BIGINT,Password_manager VARCHAR(20),Location_customer VARCHAR(255),Password_customer VARCHAR(20),Location_supplier VARCHAR(255),Password_supplier VARCHAR(20))
    begin
        if ID_personnel>=400 then 
           signal sqlstate 'HY000' set message_text='检查输入信息';
        end if;   

        if exists (select * from personnel where personnel_id=ID_personnel) then
            update personnel set personnel_name=name_personnel where personnel_id=ID_personnel;
            update personnel set peronnel_tel=tel_personnel where personnel_id=ID_personnel;
        else insert into personnel(personnel_id,personnel_name,personnel_tel)
                values (ID_personnel,name_personnel,tel_personnel);
        end if;  

        if exists (select * from manager where personnel_id=ID_personnel) then
                update manager set manager_password=Password_manager where personnel_id=ID_personnel;
        else insert into manager(personnel_id,manager_password)
                values(ID_personnel,Password_manager);
        end if;

        if exists (select * from customer where personnel_id=ID_personnel) then
                update customer set customer_location=Location_customer where personnel_id=ID_personnel;
                update customer set customer_password=Password_customer where personnel_id=ID_personnel;
        else insert into customer(personnel_id,customer_location,customer_password)
                 values(ID_personnel,Location_customer,Password_customer);
        end if;

        if exists (select * from supplier where supplier_id=ID_personnel) then
                update supplier set supplier_location=Location_supplier where personnel_id=ID_personnel;
                update supplier set supplier_password=Password_supplier where personnel_id=ID_personnel;
        else insert into supplier(personnel_id,supplier_location,supplier_password)
                values(ID_personnel,Location_supplier,Password_supplier);
        end if;
    end;