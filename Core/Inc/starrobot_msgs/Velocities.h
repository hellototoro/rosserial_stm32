#ifndef _ROS_starrobot_msgs_Velocities_h
#define _ROS_starrobot_msgs_Velocities_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace starrobot_msgs
{

  class Velocities : public ros::Msg
  {
    public:
      typedef float _linear_x_type;
      _linear_x_type linear_x;
      typedef float _linear_y_type;
      _linear_y_type linear_y;
      typedef float _angular_z_type;
      _angular_z_type angular_z;
      typedef float _encoder_motor1_type;
      _encoder_motor1_type encoder_motor1;
      typedef float _encoder_motor2_type;
      _encoder_motor2_type encoder_motor2;
      typedef float _encoder_motor3_type;
      _encoder_motor3_type encoder_motor3;
      typedef float _encoder_motor4_type;
      _encoder_motor4_type encoder_motor4;

    Velocities():
      linear_x(0),
      linear_y(0),
      angular_z(0),
      encoder_motor1(0),
      encoder_motor2(0),
      encoder_motor3(0),
      encoder_motor4(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_linear_x;
      u_linear_x.real = this->linear_x;
      *(outbuffer + offset + 0) = (u_linear_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linear_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linear_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linear_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->linear_x);
      union {
        float real;
        uint32_t base;
      } u_linear_y;
      u_linear_y.real = this->linear_y;
      *(outbuffer + offset + 0) = (u_linear_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linear_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linear_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linear_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->linear_y);
      union {
        float real;
        uint32_t base;
      } u_angular_z;
      u_angular_z.real = this->angular_z;
      *(outbuffer + offset + 0) = (u_angular_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angular_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angular_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angular_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angular_z);
      union {
        float real;
        uint32_t base;
      } u_encoder_motor1;
      u_encoder_motor1.real = this->encoder_motor1;
      *(outbuffer + offset + 0) = (u_encoder_motor1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_encoder_motor1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_encoder_motor1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_encoder_motor1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->encoder_motor1);
      union {
        float real;
        uint32_t base;
      } u_encoder_motor2;
      u_encoder_motor2.real = this->encoder_motor2;
      *(outbuffer + offset + 0) = (u_encoder_motor2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_encoder_motor2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_encoder_motor2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_encoder_motor2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->encoder_motor2);
      union {
        float real;
        uint32_t base;
      } u_encoder_motor3;
      u_encoder_motor3.real = this->encoder_motor3;
      *(outbuffer + offset + 0) = (u_encoder_motor3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_encoder_motor3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_encoder_motor3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_encoder_motor3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->encoder_motor3);
      union {
        float real;
        uint32_t base;
      } u_encoder_motor4;
      u_encoder_motor4.real = this->encoder_motor4;
      *(outbuffer + offset + 0) = (u_encoder_motor4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_encoder_motor4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_encoder_motor4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_encoder_motor4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->encoder_motor4);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_linear_x;
      u_linear_x.base = 0;
      u_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linear_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->linear_x = u_linear_x.real;
      offset += sizeof(this->linear_x);
      union {
        float real;
        uint32_t base;
      } u_linear_y;
      u_linear_y.base = 0;
      u_linear_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linear_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linear_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linear_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->linear_y = u_linear_y.real;
      offset += sizeof(this->linear_y);
      union {
        float real;
        uint32_t base;
      } u_angular_z;
      u_angular_z.base = 0;
      u_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angular_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angular_z = u_angular_z.real;
      offset += sizeof(this->angular_z);
      union {
        float real;
        uint32_t base;
      } u_encoder_motor1;
      u_encoder_motor1.base = 0;
      u_encoder_motor1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_encoder_motor1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_encoder_motor1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_encoder_motor1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->encoder_motor1 = u_encoder_motor1.real;
      offset += sizeof(this->encoder_motor1);
      union {
        float real;
        uint32_t base;
      } u_encoder_motor2;
      u_encoder_motor2.base = 0;
      u_encoder_motor2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_encoder_motor2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_encoder_motor2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_encoder_motor2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->encoder_motor2 = u_encoder_motor2.real;
      offset += sizeof(this->encoder_motor2);
      union {
        float real;
        uint32_t base;
      } u_encoder_motor3;
      u_encoder_motor3.base = 0;
      u_encoder_motor3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_encoder_motor3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_encoder_motor3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_encoder_motor3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->encoder_motor3 = u_encoder_motor3.real;
      offset += sizeof(this->encoder_motor3);
      union {
        float real;
        uint32_t base;
      } u_encoder_motor4;
      u_encoder_motor4.base = 0;
      u_encoder_motor4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_encoder_motor4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_encoder_motor4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_encoder_motor4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->encoder_motor4 = u_encoder_motor4.real;
      offset += sizeof(this->encoder_motor4);
     return offset;
    }

    virtual const char * getType() override { return "starrobot_msgs/Velocities"; };
    virtual const char * getMD5() override { return "8329a852890c99a68e7e5321005869e9"; };

  };

}
#endif
