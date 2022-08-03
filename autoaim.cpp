#include "main.h"

using namespace pros;



void get_target(float target_x, float target_y)
{  
  //calculate the difference between target and robot                                              
  float deltaY = target_y - y_pos_global;                     
  float deltaX = target_x - x_pos_global;

  //get the angle where the target is located and convert it
  int target_angle = atan2(deltaX,deltaY) * 180 / drive_pi;


  //convert for preference to my program
  if (target_angle<0){
    
    target_angle= 360 + target_angle;
    
  }
  
  
  //use my PD to get that target
  PID_get_Angle(target_angle);

  //lcd::print(6, "desired ang:%d", target_angle);
}

void autoaim()
{
  //on the left button, robot turn to target
  if(maincontroller.get_digital(E_CONTROLLER_DIGITAL_L1))
  {
    lcd::print(5, "works");
    get_target(0.01,0.01);
  }


}