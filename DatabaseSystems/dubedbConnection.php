<?php
$server = "localhost";
$user = "root";
$password = "";

$db = "dubedb";
$con=mysqli_connect($server, $user, $password, $db);
if(mysqli_connect_errno()){
	echo "Unable to connect: " . mysgli_connect_error();
}

$Customer_id = $_GET['Customer_id'];
$Customer_fname = $_GET['Customer_fname'];
$Customer_mname = $_GET['Customer_mname'];
$Customer_lname = $_GET['Customer_lname'];
$Customer_gender = $_GET['Customer_gender'];
$Customer_street = $_GET['Customer_street'];
$Customer_city = $_GET['Customer_city'];
$Customer_state = $_GET['Customer_state'];
$Customer_zip = $_GET['Customer_zip'];
$Customer_phone = $_GET['Customer_phone'];
$Customer_email = $_GET['Customer_email'];
$Ad_id = $_GET['Ad_id'];
$Reservation_id = $_GET['Reservation_id'];
$Start_date = $_GET['Start_date'];
$Stop_date = $_GET['Stop_date'];
$Number_in_party = $_GET['Number_in_party'];
$Res_equip_quantity = $_GET['Res_equip_quantity'];
$Estimate = $_GET['Estimate'];
$Paid_amount = $_GET['Paid_amount'];
$Employee_id = $_GET['Employee_id'];

echo "$Customer_id, $Customer_fname, $Customer_mname";



mysqli_query($con, "INSERT INTO customer (Customer_id, Customer_fname, Customer_mname, Customer_lname, Customer_gender, Customer_street, Customer_city, Customer_state, Customer_zip, Customer_phone, Customer_email, Ad_id) 
VALUES ('$Customer_id', '$Customer_fname', '$Customer_mname', '$Customer_lname', '$Customer_gender', '$Customer_street', '$Customer_city', '$Customer_state', '$Customer_zip', '$Customer_phone', '$Customer_email', $Ad_id)");


mysqli_query($con, "INSERT INTO reservation (Reservation_id, Start_date, Stop_date, Number_in_party, Res_equip_quantity, Estimate, Paid_amount, Customer_id, Ad_id, Employee_id) 
VALUES ('$Reservation_id', '$Start_date', '$Stop_date', '$Number_in_party', '$Res_equip_quantity', '$Estimate', '$Paid_amount', '$Customer_id', '$Ad_id', '$Employee_id')");


mysqli_close($con);

?>