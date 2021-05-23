/*
 * main.cpp

 *
 *  Created on: 2018/01/17
 *      Author: yoneken
 */
#include <mainpp.h>
#include <ros.h>
#include <std_msgs/String.h>

#include "main.h"
#include "fd1x3.h"

ros::NodeHandle nh;
motorDriver::fd1x3 motor;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
char hello[] = "Hello world!";

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	if (rosserial_huart == huart) {
		nh.getHardware()->flush();
	}
	else if (motorDriver_huart == huart) {
		//motor.receive();
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if (rosserial_huart == huart) {
		nh.getHardware()->reset_rbuf();
	}
	else if (motorDriver_huart == huart) {
		motor.receive();
	}
}

void setup(void)
{
  nh.initNode();
  nh.advertise(chatter);
  motor.config();
  motor.setSpeed(50);
}

void loop(void)
{
  HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);

  str_msg.data = hello;
  chatter.publish(&str_msg);
  nh.spinOnce();

  //motor.Task();
  motor.config();
  HAL_Delay(1000);
}

