/*
 Navicat Premium Data Transfer

 Source Server         : WareHouse_homework
 Source Server Type    : MySQL
 Source Server Version : 80019
 Source Host           : localhost:3306
 Source Schema         : warehouse_1

 Target Server Type    : MySQL
 Target Server Version : 80019
 File Encoding         : 65001

 Date: 27/05/2023 02:09:53
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for customer
-- ----------------------------
DROP TABLE IF EXISTS `customer`;
CREATE TABLE `customer`  (
  `personnel_id` int(0) NOT NULL,
  `customer_location` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `customer_password` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`personnel_id`) USING BTREE,
  INDEX `personnel_id`(`personnel_id`) USING BTREE,
  CONSTRAINT `customer_ibfk_1` FOREIGN KEY (`personnel_id`) REFERENCES `personnel` (`personnel_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of customer
-- ----------------------------
INSERT INTO `customer` VALUES (201, '上海市黄浦区人民广场100号', 'Abcde12345');
INSERT INTO `customer` VALUES (202, '北京市朝阳区建国门外大街1号', '9876543210');
INSERT INTO `customer` VALUES (203, '广东省深圳市福田区华强北路123号', 'P@ssw0rd');
INSERT INTO `customer` VALUES (204, '浙江省杭州市西湖区文一西路456号', 'Qwerty123');
INSERT INTO `customer` VALUES (205, '湖北省武汉市江汉区解放大道789号', 'MyP@ssw0rd');
INSERT INTO `customer` VALUES (206, '四川省成都市锦江区天府广场10号', '123456789a');
INSERT INTO `customer` VALUES (207, '广西壮族自治区南宁市青秀区民族大道246号', 'Password1!');
INSERT INTO `customer` VALUES (208, '山东省青岛市市南区香港中路789号', 'Hello1234');
INSERT INTO `customer` VALUES (209, '江苏省南京市鼓楼区中山路321号', 'Sunshine7');
INSERT INTO `customer` VALUES (210, '河南省郑州市金水区农业路987号', 'Pa$$w0rd');

-- ----------------------------
-- Table structure for inbound
-- ----------------------------
DROP TABLE IF EXISTS `inbound`;
CREATE TABLE `inbound`  (
  `inbound_id` int(0) NOT NULL,
  `manager_in_personnel_id` int(0) NOT NULL,
  `supplier_personnel_id` int(0) NOT NULL,
  `warehouse_id` int(0) NOT NULL,
  `product_id` int(0) NOT NULL,
  `inbound_sum` int(0) NOT NULL,
  `inbound_date` datetime(0) NOT NULL,
  PRIMARY KEY (`inbound_id`) USING BTREE,
  INDEX `manager_in_personnel_id`(`manager_in_personnel_id`) USING BTREE,
  INDEX `supplier_personnel_id`(`supplier_personnel_id`) USING BTREE,
  INDEX `product_id`(`product_id`) USING BTREE,
  INDEX `warehouse_id`(`warehouse_id`) USING BTREE,
  CONSTRAINT `inbound_ibfk_1` FOREIGN KEY (`manager_in_personnel_id`) REFERENCES `manager` (`personnel_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `inbound_ibfk_2` FOREIGN KEY (`supplier_personnel_id`) REFERENCES `supplier` (`personnel_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `inbound_ibfk_4` FOREIGN KEY (`product_id`) REFERENCES `products` (`product_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `inbound_ibfk_5` FOREIGN KEY (`warehouse_id`) REFERENCES `warehouse` (`warehouse_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of inbound
-- ----------------------------
INSERT INTO `inbound` VALUES (701, 102, 305, 602, 517, 40, '2022-02-19 18:32:45');
INSERT INTO `inbound` VALUES (702, 107, 308, 609, 511, 36, '2022-02-03 09:47:16');
INSERT INTO `inbound` VALUES (703, 106, 310, 608, 521, 53, '2021-12-19 15:14:23');
INSERT INTO `inbound` VALUES (704, 109, 306, 607, 503, 29, '2022-03-27 23:51:09');
INSERT INTO `inbound` VALUES (705, 105, 303, 610, 505, 44, '2022-01-05 07:58:37');
INSERT INTO `inbound` VALUES (706, 103, 307, 605, 524, 35, '2021-11-20 12:25:23');
INSERT INTO `inbound` VALUES (707, 104, 304, 603, 514, 55, '2021-12-08 05:16:12');
INSERT INTO `inbound` VALUES (708, 108, 309, 606, 523, 51, '2022-04-17 17:42:58');
INSERT INTO `inbound` VALUES (709, 101, 302, 601, 510, 41, '2022-04-01 03:29:30');
INSERT INTO `inbound` VALUES (710, 110, 301, 604, 501, 25, '2022-01-16 14:21:54');
INSERT INTO `inbound` VALUES (711, 103, 309, 610, 516, 50, '2022-03-03 10:13:21');
INSERT INTO `inbound` VALUES (712, 106, 303, 602, 519, 31, '2022-02-10 18:55:39');
INSERT INTO `inbound` VALUES (713, 104, 307, 607, 506, 57, '2021-11-26 07:34:05');
INSERT INTO `inbound` VALUES (714, 105, 306, 609, 522, 48, '2021-10-24 17:49:27');
INSERT INTO `inbound` VALUES (715, 107, 301, 601, 509, 42, '2022-04-26 08:07:13');
INSERT INTO `inbound` VALUES (716, 109, 310, 604, 513, 26, '2021-10-14 13:45:52');
INSERT INTO `inbound` VALUES (717, 108, 304, 605, 520, 38, '2022-01-29 03:19:44');
INSERT INTO `inbound` VALUES (718, 102, 305, 603, 507, 59, '2022-02-23 20:38:28');
INSERT INTO `inbound` VALUES (719, 101, 310, 606, 515, 34, '2022-01-11 11:09:06');
INSERT INTO `inbound` VALUES (720, 110, 308, 608, 512, 49, '2022-03-22 02:27:49');
INSERT INTO `inbound` VALUES (721, 103, 302, 610, 502, 54, '2022-03-08 14:06:35');
INSERT INTO `inbound` VALUES (722, 108, 309, 607, 525, 31, '2021-11-11 06:28:18');
INSERT INTO `inbound` VALUES (723, 106, 303, 602, 508, 27, '2022-04-13 19:16:57');
INSERT INTO `inbound` VALUES (724, 104, 306, 609, 518, 47, '2021-11-05 16:55:36');
INSERT INTO `inbound` VALUES (725, 103, 307, 603, 504, 30, '2022-01-22 22:43:18');

-- ----------------------------
-- Table structure for manager
-- ----------------------------
DROP TABLE IF EXISTS `manager`;
CREATE TABLE `manager`  (
  `personnel_id` int(0) NOT NULL,
  `manager_password` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`personnel_id`) USING BTREE,
  CONSTRAINT `manager_ibfk_1` FOREIGN KEY (`personnel_id`) REFERENCES `personnel` (`personnel_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of manager
-- ----------------------------
INSERT INTO `manager` VALUES (101, 'qT5fG8hY2');
INSERT INTO `manager` VALUES (102, '7pR9sC2dX');
INSERT INTO `manager` VALUES (103, 'bN6vM1kL4');
INSERT INTO `manager` VALUES (104, '3zX6cV7bN');
INSERT INTO `manager` VALUES (105, 'jK9mN8bH4');
INSERT INTO `manager` VALUES (106, '5fG2hY7jK');
INSERT INTO `manager` VALUES (107, '1qA3sD6fG');
INSERT INTO `manager` VALUES (108, 'mJ5nB9vC2');
INSERT INTO `manager` VALUES (109, 'dF8gH6jK9');
INSERT INTO `manager` VALUES (110, '9iU2oP5lM');

-- ----------------------------
-- Table structure for outbound
-- ----------------------------
DROP TABLE IF EXISTS `outbound`;
CREATE TABLE `outbound`  (
  `outbound_id` int(0) NOT NULL,
  `manager_out_personnel_id` int(0) NOT NULL,
  `customer_personnel_id` int(0) NOT NULL,
  `warehouse_id` int(0) NOT NULL,
  `product_id` int(0) NOT NULL,
  `outbound_sum` int(0) NOT NULL,
  `outbound_date` datetime(0) NOT NULL,
  PRIMARY KEY (`outbound_id`) USING BTREE,
  INDEX `manager_out_personnel_id`(`manager_out_personnel_id`) USING BTREE,
  INDEX `customer_personnel_id`(`customer_personnel_id`) USING BTREE,
  INDEX `warehouse_id`(`warehouse_id`) USING BTREE,
  INDEX `product_id`(`product_id`) USING BTREE,
  CONSTRAINT `outbound_ibfk_1` FOREIGN KEY (`manager_out_personnel_id`) REFERENCES `manager` (`personnel_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `outbound_ibfk_2` FOREIGN KEY (`customer_personnel_id`) REFERENCES `customer` (`personnel_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `outbound_ibfk_3` FOREIGN KEY (`warehouse_id`) REFERENCES `warehouse` (`warehouse_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `outbound_ibfk_4` FOREIGN KEY (`product_id`) REFERENCES `products` (`product_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of outbound
-- ----------------------------
INSERT INTO `outbound` VALUES (801, 104, 206, 607, 506, 6, '2022-01-04 09:23:15');
INSERT INTO `outbound` VALUES (802, 107, 202, 603, 520, 2, '2022-02-18 16:40:59');
INSERT INTO `outbound` VALUES (803, 105, 208, 604, 515, 9, '2022-03-22 11:07:28');
INSERT INTO `outbound` VALUES (804, 103, 209, 606, 503, 3, '2022-04-09 19:55:41');
INSERT INTO `outbound` VALUES (805, 109, 203, 609, 522, 1, '2022-05-12 08:30:10');
INSERT INTO `outbound` VALUES (806, 106, 210, 605, 507, 4, '2022-06-28 14:18:05');
INSERT INTO `outbound` VALUES (807, 101, 205, 602, 523, 3, '2022-07-17 07:52:36');
INSERT INTO `outbound` VALUES (808, 110, 207, 608, 521, 8, '2022-08-29 17:09:47');
INSERT INTO `outbound` VALUES (809, 102, 204, 610, 510, 7, '2022-09-05 10:25:55');
INSERT INTO `outbound` VALUES (810, 108, 201, 601, 513, 5, '2022-10-19 22:47:23');

-- ----------------------------
-- Table structure for personnel
-- ----------------------------
DROP TABLE IF EXISTS `personnel`;
CREATE TABLE `personnel`  (
  `personnel_id` int(0) NOT NULL,
  `personnel_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `personnel_tel` bigint(0) NOT NULL,
  PRIMARY KEY (`personnel_id`) USING BTREE,
  INDEX `personnel_name`(`personnel_name`) USING BTREE,
  INDEX `personnel_tel`(`personnel_tel`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of personnel
-- ----------------------------
INSERT INTO `personnel` VALUES (101, '张伟', 13812345678);
INSERT INTO `personnel` VALUES (102, '王芳', 13698765432);
INSERT INTO `personnel` VALUES (103, '李娜', 13987654321);
INSERT INTO `personnel` VALUES (104, '刘勇', 13765432109);
INSERT INTO `personnel` VALUES (105, '赵敏', 13543210987);
INSERT INTO `personnel` VALUES (106, '陈军', 13876543210);
INSERT INTO `personnel` VALUES (107, '杨洋', 13987654320);
INSERT INTO `personnel` VALUES (108, '黄梅', 13765432108);
INSERT INTO `personnel` VALUES (109, '周静', 13543210986);
INSERT INTO `personnel` VALUES (110, '吴强', 13812345677);
INSERT INTO `personnel` VALUES (201, '蒋雪', 13698765431);
INSERT INTO `personnel` VALUES (202, '许宁', 13987654322);
INSERT INTO `personnel` VALUES (203, '郭艳', 13765432107);
INSERT INTO `personnel` VALUES (204, '马磊', 13543210985);
INSERT INTO `personnel` VALUES (205, '林秀', 13876543209);
INSERT INTO `personnel` VALUES (206, '朱明', 13987654323);
INSERT INTO `personnel` VALUES (207, '郑龙', 13765432106);
INSERT INTO `personnel` VALUES (208, '韩霞', 13543210984);
INSERT INTO `personnel` VALUES (209, '曹华', 13812345676);
INSERT INTO `personnel` VALUES (210, '谢平', 13698765430);
INSERT INTO `personnel` VALUES (301, '梁红', 13987654324);
INSERT INTO `personnel` VALUES (302, '宋刚', 13765432105);
INSERT INTO `personnel` VALUES (303, '邓莉', 13543210983);
INSERT INTO `personnel` VALUES (304, '傅涛', 13876543208);
INSERT INTO `personnel` VALUES (305, '彭慧', 13987654325);
INSERT INTO `personnel` VALUES (306, '袁飞', 13765432104);
INSERT INTO `personnel` VALUES (307, '潘静', 13543210982);
INSERT INTO `personnel` VALUES (308, '董建', 13812345675);
INSERT INTO `personnel` VALUES (309, '罗晶', 13698765429);
INSERT INTO `personnel` VALUES (310, '唐阳', 13987654326);

-- ----------------------------
-- Table structure for product_type
-- ----------------------------
DROP TABLE IF EXISTS `product_type`;
CREATE TABLE `product_type`  (
  `product_type_id` int(0) NOT NULL,
  `product_type_id_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`product_type_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of product_type
-- ----------------------------
INSERT INTO `product_type` VALUES (401, '手表');
INSERT INTO `product_type` VALUES (402, '洗发水');
INSERT INTO `product_type` VALUES (403, '运动鞋');
INSERT INTO `product_type` VALUES (404, '耳机');
INSERT INTO `product_type` VALUES (405, '图书');

-- ----------------------------
-- Table structure for products
-- ----------------------------
DROP TABLE IF EXISTS `products`;
CREATE TABLE `products`  (
  `product_id` int(0) NOT NULL,
  `product_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `product_type_id` int(0) NOT NULL,
  `product_sum` int(0) NOT NULL,
  PRIMARY KEY (`product_id`) USING BTREE,
  INDEX `product_type_id`(`product_type_id`) USING BTREE,
  CONSTRAINT `products_ibfk_1` FOREIGN KEY (`product_type_id`) REFERENCES `product_type` (`product_type_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of products
-- ----------------------------
INSERT INTO `products` VALUES (501, '儿童电话手表', 401, 25);
INSERT INTO `products` VALUES (502, '潮流腕表', 401, 54);
INSERT INTO `products` VALUES (503, '商务男表', 401, 26);
INSERT INTO `products` VALUES (504, '高端女表', 401, 30);
INSERT INTO `products` VALUES (505, '运动智能表', 401, 44);
INSERT INTO `products` VALUES (506, '柔顺护发露', 402, 51);
INSERT INTO `products` VALUES (507, '深层修复洗发水', 402, 55);
INSERT INTO `products` VALUES (508, '滋润营养洗发露', 402, 27);
INSERT INTO `products` VALUES (509, '清爽控油洗发水', 402, 42);
INSERT INTO `products` VALUES (510, '天然植物洗发水', 402, 34);
INSERT INTO `products` VALUES (511, '篮球鞋', 403, 36);
INSERT INTO `products` VALUES (512, '跑步鞋', 403, 49);
INSERT INTO `products` VALUES (513, '休闲运动鞋', 403, 21);
INSERT INTO `products` VALUES (514, '健身训练鞋', 403, 55);
INSERT INTO `products` VALUES (515, '登山鞋', 403, 23);
INSERT INTO `products` VALUES (516, '无线蓝牙耳机', 404, 50);
INSERT INTO `products` VALUES (517, '耳挂式耳机', 404, 40);
INSERT INTO `products` VALUES (518, '耳塞式耳机', 404, 47);
INSERT INTO `products` VALUES (519, '头戴式耳机', 404, 31);
INSERT INTO `products` VALUES (520, '游戏耳机', 404, 36);
INSERT INTO `products` VALUES (521, '文学经典', 405, 45);
INSERT INTO `products` VALUES (522, '科幻小说', 405, 47);
INSERT INTO `products` VALUES (523, '历史传记', 405, 49);
INSERT INTO `products` VALUES (524, '自助成长', 405, 35);
INSERT INTO `products` VALUES (525, '儿童绘本', 405, 31);

-- ----------------------------
-- Table structure for supplier
-- ----------------------------
DROP TABLE IF EXISTS `supplier`;
CREATE TABLE `supplier`  (
  `personnel_id` int(0) NOT NULL,
  `supplier_location` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `supplier_password` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`personnel_id`) USING BTREE,
  INDEX `personnel_id`(`personnel_id`) USING BTREE,
  CONSTRAINT `supplier_ibfk_1` FOREIGN KEY (`personnel_id`) REFERENCES `personnel` (`personnel_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of supplier
-- ----------------------------
INSERT INTO `supplier` VALUES (301, '北京市朝阳区建国门外大街1号', 'abc123xyz');
INSERT INTO `supplier` VALUES (302, '上海市浦东新区世纪大道1000号', 'passw0rd');
INSERT INTO `supplier` VALUES (303, '广东省深圳市福田区华强北路2001号', '987654321');
INSERT INTO `supplier` VALUES (304, '浙江省杭州市西湖区文三路888号', 'qwe!@#123');
INSERT INTO `supplier` VALUES (305, '江苏省南京市玄武区中山路100号', 'letmein1');
INSERT INTO `supplier` VALUES (306, '湖北省武汉市江汉区江汉路50号', 'p@55word');
INSERT INTO `supplier` VALUES (307, '四川省成都市锦江区人民中路100号', 'summer21');
INSERT INTO `supplier` VALUES (308, '山东省青岛市市南区香港中路200号', 'hello1234');
INSERT INTO `supplier` VALUES (309, '河南省郑州市金水区农业路666号', '1qaz2wsx');
INSERT INTO `supplier` VALUES (310, '辽宁省沈阳市和平区中街100号', 'iloveyou!');

-- ----------------------------
-- Table structure for warehouse
-- ----------------------------
DROP TABLE IF EXISTS `warehouse`;
CREATE TABLE `warehouse`  (
  `warehouse_id` int(0) NOT NULL,
  `warehouse_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `warehouse_location` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`warehouse_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of warehouse
-- ----------------------------
INSERT INTO `warehouse` VALUES (601, '金海仓库', '上海市浦东新区金海路123号');
INSERT INTO `warehouse` VALUES (602, '长宁仓库', '上海市长宁区长宁路456号');
INSERT INTO `warehouse` VALUES (603, '天河仓库', '广东省广州市天河区天河北路789号');
INSERT INTO `warehouse` VALUES (604, '玉泉仓库', '北京市西城区玉泉路101号');
INSERT INTO `warehouse` VALUES (605, '桃源仓库', '湖南省长沙市岳麓区桃源南路234号');
INSERT INTO `warehouse` VALUES (606, '翠湖仓库', '浙江省杭州市西湖区翠湖路567号');
INSERT INTO `warehouse` VALUES (607, '大望仓库', '广东省深圳市南山区大望路890号');
INSERT INTO `warehouse` VALUES (608, '青山仓库', '湖北省武汉市青山区青山路111号');
INSERT INTO `warehouse` VALUES (609, '望京仓库', '北京市朝阳区望京街212号');
INSERT INTO `warehouse` VALUES (610, '蓝海仓库', '广东省珠海市蓝海大道345号');

-- ----------------------------
-- View structure for in_order_view
-- ----------------------------
DROP VIEW IF EXISTS `in_order_view`;
CREATE ALGORITHM = UNDEFINED SQL SECURITY DEFINER VIEW `in_order_view` AS select distinct `inbound`.`inbound_id` AS `inbound_id`,`manager_personnel`.`personnel_name` AS `manager_name`,`manager_personnel`.`personnel_tel` AS `manager_tel`,`supplier_personnel`.`personnel_name` AS `supplier_name`,`supplier_personnel`.`personnel_tel` AS `supplier_tel`,`supplier`.`supplier_location` AS `supplier_location`,`warehouse`.`warehouse_name` AS `warehouse_name`,`warehouse`.`warehouse_location` AS `warehouse_location`,`product_type`.`product_type_id_name` AS `product_type_id_name`,`products`.`product_name` AS `product_name`,`inbound`.`inbound_sum` AS `inbound_sum`,`inbound`.`inbound_date` AS `inbound_date` from (((((((`inbound` join `manager` on((`inbound`.`manager_in_personnel_id` = `manager`.`personnel_id`))) join `personnel` `manager_personnel` on((`manager`.`personnel_id` = `manager_personnel`.`personnel_id`))) join `supplier` on((`inbound`.`supplier_personnel_id` = `supplier`.`personnel_id`))) join `personnel` `supplier_personnel` on((`supplier`.`personnel_id` = `supplier_personnel`.`personnel_id`))) join `warehouse` on((`inbound`.`warehouse_id` = `warehouse`.`warehouse_id`))) join `products` on((`inbound`.`product_id` = `products`.`product_id`))) join `product_type` on((`products`.`product_type_id` = `product_type`.`product_type_id`))) order by `inbound`.`inbound_id`;

-- ----------------------------
-- View structure for out_order_view
-- ----------------------------
DROP VIEW IF EXISTS `out_order_view`;
CREATE ALGORITHM = UNDEFINED SQL SECURITY DEFINER VIEW `out_order_view` AS select distinct `outbound`.`outbound_id` AS `outbound_id`,`manager_personnel`.`personnel_name` AS `manager_name`,`manager_personnel`.`personnel_tel` AS `manager_tel`,`customer_personnel`.`personnel_name` AS `customer_name`,`customer_personnel`.`personnel_tel` AS `customer_tel`,`customer`.`customer_location` AS `customer_location`,`warehouse`.`warehouse_name` AS `warehouse_name`,`warehouse`.`warehouse_location` AS `warehouse_location`,`product_type`.`product_type_id_name` AS `product_type_id_name`,`products`.`product_name` AS `product_name`,`outbound`.`outbound_sum` AS `outbound_sum`,`outbound`.`outbound_date` AS `outbound_date` from ((((((((`outbound` join `customer` on((`outbound`.`customer_personnel_id` = `customer`.`personnel_id`))) join `manager` on((`outbound`.`manager_out_personnel_id` = `manager`.`personnel_id`))) join `personnel` `manager_personnel` on((`manager`.`personnel_id` = `manager_personnel`.`personnel_id`))) join `warehouse` on((`outbound`.`warehouse_id` = `warehouse`.`warehouse_id`))) join `products` on((`outbound`.`product_id` = `products`.`product_id`))) join `product_type` on((`products`.`product_type_id` = `product_type`.`product_type_id`))) join `personnel` on((`manager`.`personnel_id` = `manager_personnel`.`personnel_id`))) join `personnel` `customer_personnel` on((`customer`.`personnel_id` = `customer_personnel`.`personnel_id`)));

-- ----------------------------
-- Procedure structure for addProductSum
-- ----------------------------
DROP PROCEDURE IF EXISTS `addProductSum`;
delimiter ;;
CREATE PROCEDURE `addProductSum`(ID_inbound INT,ID_manager_in_personnel INT,ID_supplier_personnel INT,ID_warehouse INT,ID_product INT,Sum_inbound INT,Date_inbound DATETIME)
begin
        declare product_sum_current INT(8);
        set product_sum_current=(select product_sum from products
            where product_id=ID_product);
        insert into inbound(inbound_id,manager_in_personnel_id,supplier_personnel_id,warehouse_id,product_id,inbound_sum,inbound_date)
            values(ID_inbound,ID_manager_in_personnel,ID_supplier_personnel,ID_warehouse,ID_product,Sum_inbound,Date_inbound);
        set product_sum_current=product_sum_current+Sum_inbound;
        update products
        set product_sum=product_sum_current
            where product_id=ID_product;
    end
;;
delimiter ;

-- ----------------------------
-- Procedure structure for delete_product
-- ----------------------------
DROP PROCEDURE IF EXISTS `delete_product`;
delimiter ;;
CREATE PROCEDURE `delete_product`(productid_ INT)
begin
        if exists(select * from products where product_id=productid_ and product_sum >0) then
            signal sqlstate 'HY000' set message_text='请先将该商品全部出库';
		else 
            delete from products where product_id=productid_;
        end if;
    end
;;
delimiter ;

-- ----------------------------
-- Procedure structure for personnel_updating_customer
-- ----------------------------
DROP PROCEDURE IF EXISTS `personnel_updating_customer`;
delimiter ;;
CREATE PROCEDURE `personnel_updating_customer`(ID_personnel INT,name_personnel VARCHAR(20),tel_personnel BIGINT,Location_customer VARCHAR(255),Password_customer VARCHAR(20))
begin
        if ID_personnel>=300 OR ID_personnel<=200 then 
           signal sqlstate 'HY000' set message_text='检查输入信息';
        end if;   

        if exists (select * from personnel where personnel_id=ID_personnel) then
            update personnel set personnel_name=name_personnel where personnel_id=ID_personnel;
            update personnel set personnel_tel=tel_personnel where personnel_id=ID_personnel;
        else insert into personnel(personnel_id,personnel_name,personnel_tel)
                values (ID_personnel,name_personnel,tel_personnel);
        end if;  

         if exists (select * from customer where personnel_id=ID_personnel) then
                update customer set customer_location=Location_customer where personnel_id=ID_personnel;
                update customer set customer_password=Password_customer where personnel_id=ID_personnel;
        else insert into customer(personnel_id,customer_location,customer_password)
                 values(ID_personnel,Location_customer,Password_customer);
        end if;

    end
;;
delimiter ;

-- ----------------------------
-- Procedure structure for personnel_updating_manager
-- ----------------------------
DROP PROCEDURE IF EXISTS `personnel_updating_manager`;
delimiter ;;
CREATE PROCEDURE `personnel_updating_manager`(ID_personnel INT,name_personnel VARCHAR(20),tel_personnel BIGINT,Password_manager VARCHAR(20))
begin
        if ID_personnel>=200 then 
           signal sqlstate 'HY000' set message_text='检查输入信息';
        end if;   

        if exists (select * from personnel where personnel_id=ID_personnel) then
            update personnel set personnel_name=name_personnel where personnel_id=ID_personnel;
            update personnel set personnel_tel=tel_personnel where personnel_id=ID_personnel;
        else insert into personnel(personnel_id,personnel_name,personnel_tel)
                values (ID_personnel,name_personnel,tel_personnel);
        end if;  

        if exists (select * from manager where personnel_id=ID_personnel) then
                update manager set manager_password=Password_manager where personnel_id=ID_personnel;
        else insert into manager(personnel_id,manager_password)
                values(ID_personnel,Password_manager);
        end if;
    end
;;
delimiter ;

-- ----------------------------
-- Procedure structure for personnel_updating_supplier
-- ----------------------------
DROP PROCEDURE IF EXISTS `personnel_updating_supplier`;
delimiter ;;
CREATE PROCEDURE `personnel_updating_supplier`(ID_personnel INT,name_personnel VARCHAR(20),tel_personnel BIGINT,Location_supplier VARCHAR(255),Password_supplier VARCHAR(20))
begin
        if ID_personnel>=400 OR ID_personnel<=300 then 
           signal sqlstate 'HY000' set message_text='检查输入信息';
        end if;   

        if exists (select * from personnel where personnel_id=ID_personnel) then
            update personnel set personnel_name=name_personnel where personnel_id=ID_personnel;
            update personnel set personnel_tel=tel_personnel where personnel_id=ID_personnel;
        else insert into personnel(personnel_id,personnel_name,personnel_tel)
                values (ID_personnel,name_personnel,tel_personnel);
        end if;  

        if exists (select * from supplier where personnel_id=ID_personnel) then
                update supplier set supplier_location=Location_supplier where personnel_id=ID_personnel;
                update supplier set supplier_password=Password_supplier where personnel_id=ID_personnel;
        else insert into supplier(personnel_id,supplier_location,supplier_password)
                values(ID_personnel,Location_supplier,Password_supplier);
        end if;
    end
;;
delimiter ;

-- ----------------------------
-- Procedure structure for subProductSum
-- ----------------------------
DROP PROCEDURE IF EXISTS `subProductSum`;
delimiter ;;
CREATE PROCEDURE `subProductSum`(ID_outbound INT,ID_manager_out_personnel INT,ID_customer_personnel INT,ID_warehouse INT,ID_product INT,Sum_outbound INT,Date_outbound DATETIME)
begin
        declare product_sum_current INT(8);
        declare Product_sum_all INT(8);
        set Product_sum_all=(select product_sum from products where product_id=ID_product);
        set product_sum_current=(select sum(inbound_sum) from inbound where product_id=ID_product and warehouse_id=ID_warehouse);
        IF product_sum_current IS NULL THEN
        SET product_sum_current = 0;
        END IF;
        insert into outbound(outbound_id,manager_out_personnel_id,customer_personnel_id,warehouse_id,product_id,outbound_sum,outbound_date)
            values(ID_outbound,ID_manager_out_personnel,ID_customer_personnel,ID_warehouse,ID_product,Sum_outbound,Date_outbound);
        set Product_sum_all=Product_sum_all-Sum_outbound;
            update products 
            set product_sum=Product_sum_all 
			    where product_id=ID_product; 
    end
;;
delimiter ;

-- ----------------------------
-- Triggers structure for table inbound
-- ----------------------------
DROP TRIGGER IF EXISTS `generate_inbound_records`;
delimiter ;;
CREATE TRIGGER `generate_inbound_records` BEFORE INSERT ON `inbound` FOR EACH ROW BEGIN
    if new.product_id not in (select product_id from products where product_id=new.product_id)
		then 
		signal sqlstate 'HY000' set message_text='请先填写商品表信息';
		end if;
	if new.warehouse_id not in (select warehouse_id from warehouse where warehouse_id=new.warehouse_id)
		then 
		signal sqlstate 'HY000' set message_text='请先填写仓库表信息';
		end if;    
    if new.manager_in_personnel_id not in (select personnel_id from manager where personnel_id=new.manager_in_personnel_id)
		then 
		signal sqlstate 'HY000' set message_text='请先填写管理员表信息';
		end if;        
    if new.supplier_personnel_id not in (select personnel_id from supplier where personnel_id=new.supplier_personnel_id)
		then 
		signal sqlstate 'HY000' set message_text='请先填写供货商表信息';
		end if;      
END
;;
delimiter ;

-- ----------------------------
-- Triggers structure for table outbound
-- ----------------------------
DROP TRIGGER IF EXISTS `generate_outbound_records`;
delimiter ;;
CREATE TRIGGER `generate_outbound_records` BEFORE INSERT ON `outbound` FOR EACH ROW BEGIN
    declare product_sum_current INT(8);
    set product_sum_current=(select sum(inbound_sum) from inbound where product_id=new.product_id and warehouse_id=new.warehouse_id);
    IF product_sum_current IS NULL THEN
        SET product_sum_current = 0;
    END IF;
	if product_sum_current-new.outbound_sum<0 then signal sqlstate 'HY000' set message_text='请检查出库表单信息,该仓库商品库存不满足需求';
	end if;
END
;;
delimiter ;

SET FOREIGN_KEY_CHECKS = 1;
