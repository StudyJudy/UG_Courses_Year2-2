<?php
$conn=mysql_connect("localhost","root","123456");
mysql_select_db("testDB");
$topic=$_POST['topic'];
$content=$POST['content'];
$SQLStr = "insert into news(topic,content) values('$topic','$content')";
echo $SQLStr;
$result=mysql_query($SQLStr);
//关闭连接
mysql_close($conn);
if ($result)
{
    ?>
    <script>
    alert("insert success");
    window.location.href="sys.php";
    </script>
    <?php 
}
else{
    ?>
    <script>
    alert("insert failed");
    history.back();
    </script>
    <?php
}
?>
