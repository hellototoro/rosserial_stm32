/*
 * @Author: Huang Jian
 * @Date: 2021-05-19 17:46:48
 * @LastEditTime: 2021-05-20 10:18:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /home/jee/stm32_ws/rosserial_stm32/Bsp/fd1x3/Src/fd1x3.cpp
 */
#include "fd1x3.h"
#include <cstring>

namespace motorDriver
{
#define E2INT8(_enum)  static_cast<uint8_t>(_enum)
#define E2INT32(_enum) static_cast<uint32_t>(_enum)

void fd1x3::config(void)
{
	packetData(devicesID::device1, E2INT8(funsCode::masterWrite::send::_1byte), indexsCode::workMode, E2INT8(-3));
	send();
}

//单位rpm
void fd1x3::setSpeed(uint16_t rpm)
{
	uint32_t dec = E2INT32((rpm*512*10000)/1875.f);
	packetData(devicesID::device1, E2INT8(funsCode::masterWrite::send::_4byte), indexsCode::setGoalSpeed, dec);
	send();
}


uint16_t fd1x3::getSpeed(void)
{
	return currSpeed;
}

void fd1x3::inquireSpeed(void)
{
	packetData(devicesID::device1, E2INT8(funsCode::masterRead::send::readData), indexsCode::getCurrSpeed);
	send();
}

void fd1x3::packetData(devicesID devID, uint8_t funCode, indexsCode indexCode, uint32_t data)
{
	sendBuff[E2INT8(dataIndex::deviceID)]  = E2INT8(devID);//0
	sendBuff[E2INT8(dataIndex::funCode)]   = funCode;//1
	sendBuff[E2INT8(dataIndex::index_L)]   = E2INT32(indexCode)>>16;//2
	sendBuff[E2INT8(dataIndex::index_H)]   = E2INT32(indexCode)>>24;//3
	sendBuff[E2INT8(dataIndex::subIndex)]  = E2INT32(indexCode)>>8;//4
	lastIndex = E2INT32(indexCode);
	sendBuff[E2INT8(dataIndex::data1)]     = data;//5
	sendBuff[E2INT8(dataIndex::data2)]     = data>>8;//6
	sendBuff[E2INT8(dataIndex::data3)]     = data>>16;//7
	sendBuff[E2INT8(dataIndex::data4)]     = data>>24;//8
	sendBuff[E2INT8(dataIndex::checkSun)]  = getCheckSum(sendBuff, uart_buffSize-1);//9
}

void fd1x3::unpackData(void)
{
	if (receivedFlag == true) {
		if (receiveBuff[E2INT8(dataIndex::funCode)] == E2INT8(funsCode::masterRead::received::receivedErr)) {
			return;
		}

		switch (lastIndex) {
		case E2INT32(indexsCode::getCurrSpeed):
			currSpeed  = receiveBuff[E2INT8(dataIndex::data1)];
			currSpeed |= receiveBuff[E2INT8(dataIndex::data2)]<<8;
			currSpeed |= receiveBuff[E2INT8(dataIndex::data3)]<<16;
			currSpeed |= receiveBuff[E2INT8(dataIndex::data4)]<<24;
			break;
		default:
			break;
		}
	}
}

void fd1x3::send(void)
{
	HAL_UART_Transmit_DMA(huart, sendBuff, uart_buffSize);
}

void fd1x3::receive(void)
{
	memset(receiveBuff, 0xFF, uart_buffSize);
	HAL_UART_Receive_DMA(huart, receiveBuff, uart_buffSize);
	if(receiveBuff[E2INT8(dataIndex::checkSun)] == getCheckSum(receiveBuff, uart_buffSize-1)) {
		receivedFlag = true;
	}
}

uint8_t fd1x3::getCheckSum(uint8_t *buf, uint16_t size)
{
	uint8_t sum = 0x00;
	for(uint8_t i = 0; i < size; i++) {
		sum += buf[i];
	}
	return sum;
}

void fd1x3::Task(void)
{
	static uint32_t tick = 0;
	if (HAL_GetTick() - tick > 200) {
		tick = HAL_GetTick();
		inquireSpeed();
	}
}
}

