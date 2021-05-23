/*
 * @Author: Huang Jian
 * @Date: 2021-05-19 17:46:48
 * @LastEditTime: 2021-05-20 10:18:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /home/jee/stm32_ws/rosserial_stm32/Bsp/fd1x3/Inc/fd1x3.h
 */
#ifndef __FD1X3_H
#define __FD1X3_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

extern UART_HandleTypeDef *motorDriver_huart;

namespace motorDriver
{
enum class dataIndex {
	deviceID = 0,
	funCode,
	index_L,
	index_H,
	subIndex,
	data1,
	data2,
	data3,
	data4,
	checkSun
};

enum class devicesID {//多机联级时使用
	device1 = 1,
	device2
};

namespace funsCode {
	namespace masterWrite {
		enum class send {
			_1byte = 0x2f,
			_2byte = 0x2b,
			_4byte = 0x23
		};
		enum class received {
			sendOK 	= 0x60,
			sendErr = 0x80
		};
	}
	namespace masterRead {
		enum class send {
			readData = 0x40
		};
		enum class received {
			_1byte 		= 0x4f,
			_2byte 		= 0x4b,
			_4byte 		= 0x43,
			receivedErr = 0x80
		};
	}
}

enum class indexsCode : uint32_t {
	controlCode         = 0x60400010,
	workMode            = 0x60600008,
	originMode          = 0x60980008,
	originTurnSpeed     = 0x60990120,
	originSignalSpeed   = 0x60990220,
	goalPosition        = 0x607A0020,
	trapeSpeed          = 0x60810020,
	trapeAcceleration   = 0x60830020,
	trapeDeceleration   = 0x60840020,
	setGoalSpeed        = 0x60FF0020,
	getCurrSpeed        = 0x606C0020
};

class fd1x3 {
private:
	UART_HandleTypeDef * huart;
	constexpr static uint16_t uart_buffSize { 10 };
	uint8_t sendBuff[uart_buffSize];
	uint8_t receiveBuff[uart_buffSize];
	bool receivedFlag;
	uint32_t lastIndex;
	uint32_t currSpeed;

public:
	fd1x3():
		huart { motorDriver_huart }, receivedFlag { false }, currSpeed { 0 } {
	}
	void config(void);
	void setSpeed(uint16_t rpm);
	uint16_t getSpeed(void);
	void receive(void);
	void Task(void);


private:
	void packetData(devicesID devID, uint8_t funCode, indexsCode indexCode, uint32_t data = 0x0);
	void unpackData(void);
	void send(void);
	uint8_t getCheckSum(uint8_t *buf, uint16_t size);
	void inquireSpeed(void);

};
}

#endif

