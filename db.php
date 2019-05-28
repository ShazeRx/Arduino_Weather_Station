#!/usr/bin/php-cli
<?php
$temperatura = $argv[1];
$wilgotnosc = $argv[2];
$czystosc = $argv[3];


$DBServer = '192.168.0.18'; 
$DBUser   = 'root';
$DBPass   = 'admin';
$DBName   = 'sensors';  
$conn = new mysqli($DBServer, $DBUser, $DBPass, $DBName);
// check connection
if ($conn->connect_error) {
  trigger_error('Database connection failed: '  . $conn->connect_error, E_USER_ERROR);
}
$sql="UPDATE sensor_data SET temperatura=$temperatura,wilgotnosc=$wilgotnosc,czystosc=$czystosc WHERE id=1"

?>
