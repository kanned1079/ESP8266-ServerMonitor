#!/bin/bash
cpu_us=`top -bn 1 | grep 'Cpu(s)' | awk -F'[" "%]+' '{print $3}'`
cpu_sy=`top -bn 1 | grep 'Cpu(s)' | awk -F'[" "%]+' '{print $5}'`
mem_sys_used=`free | grep Mem | awk '{print $3}'`
cpu_sum=$(echo "$cpu_us+$cpu_sy"|bc)
mem_sum=$((mem_sys_used/1024))
result=$cpu_sum 
result2=$mem_sum
mosquitto_pub -t "ss" -m "$result   $result2" -h "这里写你的mqtt服务器地址"
