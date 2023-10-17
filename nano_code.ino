
#include <Servo.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Servo Esc1, Esc2,ser1,ser2;
Adafruit_MPU6050 mpu;
int s1=90,s2=90,e1=90,e2=90;
int f=0,b=0,r=0,l=0,s=0,a=0,u=0,d=0,h=0,m=0;
int gyro_x, gyro_y, gyro_z;
long gyro_x_cal, gyro_y_cal, gyro_z_cal;
float angle_pitch, angle_roll,angle_yawn;

void setup() {

 Serial.println("Adafruit MPU6050 test!");
 Serial.begin(115200);
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  for (int a = 0; a < 2000 ; a++)
  {
    gyro_x=g.gyro.x;
    gyro_y=g.gyro.y;
    gyro_z=g.gyro.z;
    gyro_x_cal += gyro_x;                                              //Add the gyro x-axis offset to the gyro_x_cal variable
    gyro_y_cal += gyro_y;                                              //Add the gyro y-axis offset to the gyro_y_cal variable
    gyro_z_cal += gyro_z;                                              //Add the gyro z-axis offset to the gyro_z_cal variable
    delay(3);                                                          //Delay 3us to simulate the 250Hz program loop
  }
  gyro_x_cal /= 2000;                                                  //Divide the gyro_x_cal variable by 2000 to get the avarage offset
  gyro_y_cal /= 2000;                                                  //Divide the gyro_y_cal variable by 2000 to get the avarage offset
  gyro_z_cal /= 2000;     
  
  Esc1.attach(5,1000,2000);
  Esc2.attach(6,1000,2000);
  ser1.attach(9);
  ser2.attach(10);
  ser1.write(s1);
  ser2.write(s2);

}

void loop() {

  sensors_event_t a1, g, temp;
  mpu.getEvent(&a1, &g, &temp);
   
  gyro_x=g.gyro.x;
  gyro_y=g.gyro.y;
  gyro_z=g.gyro.z;

  gyro_x -= gyro_x_cal;                                                //Subtract the offset calibration value from the raw gyro_x value
  gyro_y -= gyro_y_cal;                                                //Subtract the offset calibration value from the raw gyro_y value
  gyro_z -= gyro_z_cal; 
 
  angle_pitch += gyro_x * 0.0000611;                                   //Calculate the traveled pitch angle and add this to the angle_pitch variable
  angle_roll += gyro_y * 0.0000611;
  angle_yawn += gyro_z * 0.0000611;
   
   if (analogRead(A0)>1000)
   {
     delay(30);
     if(analogRead(A0)>1000)
     {
      if(b==1)
      {
        normal();
      }
      else
      {
        forward();
      }
     }
     else{
        if(f==1){
          normal();
        }
        else
        {
          backward();
        }
     }
   }
   if (analogRead(A1)>1000)
   {
     delay(30);
     if(analogRead(A1)>1000)
     {
      if(l==1)
      {
        normal();
      }
      else
      {
        right();
      }
     }
     else{
        if(r==1){
          normal();
        }
        else
        {
          left();
        }
     }
   }
   if (analogRead(A2)>1000)
   {
     delay(30);
     if(analogRead(A2)>1000)
     {
      if(d==1)
      {
        normal();
      }
      else
      {
        up();
      }
     }
     else{
        if(u==1){
          normal();
        }
        else
        {
          down();
        }
     }
   }
   if (analogRead(A3)>1000)
   {
     delay(30);
     if(analogRead(A3)>1000)
     {
      if(h==1)
      {
        normal();
      }
      else
      {
        manual();
      }
     }
     else{
        if(m==1){
          normal();
        }
        else
        {
          hover();
        }
     }
   }
   if (analogRead(A6)>1000)
   {
     delay(30);
     if(analogRead(A6)>1000)
     {
      if(a==1)
      {
        normal();
      }
      else
      {
        stop();
      }
     }
     else{
        if(s==1){
          normal();
        }
        else
        {
          auton();
        }
     }
   }
     
}
void normal()
{

}
void stop()
{

}
void auton()
{
   //we'll see
}
void manual(){

}
void up()
{
   Esc1.write(e1=e1+1);
   Esc2.write(e2=e2+1);
}
void down(){
  Esc1.write(e1=e1-1);
   Esc2.write(e2=e2-1);

}
 void hover()
 {
       
       Esc1.write(e1);
       Esc2.write(e2);

      sensors_event_t a1, g, temp;
  mpu.getEvent(&a1, &g, &temp);
      //under progress
      gyro_x=g.gyro.x;
      gyro_y=g.gyro.y;
      gyro_z=g.gyro.z;

      gyro_x -= gyro_x_cal;                                                //Subtract the offset calibration value from the raw gyro_x value
      gyro_y -= gyro_y_cal;                                                //Subtract the offset calibration value from the raw gyro_y value
      gyro_z -= gyro_z_cal; 
 
      angle_pitch += gyro_x * 0.0000611;                                   //Calculate the traveled pitch angle and add this to the angle_pitch variable
      angle_roll += gyro_y * 0.0000611;
      angle_yawn += gyro_z * 0.0000611; 

      //pitch control
      if(angle_pitch >= 1)
      {
        ser1.write(s1+1);
      }
      else if(angle_pitch <= -1)
      {
        ser1.write(s1-1);
      }

      //roll control
      if (angle_roll >=1)
      {
        Esc1.write(e1+1);
      }
      if (angle_roll <= -1)
      {
        Esc2.write(e2-1);
      }

 }
 void forward()
 {
  ser1.write(45); // dummy values
  ser2.write(45);
  f=1;
     
 }
 void backward()
 {
  ser1.write(135);// dummy values
  ser2.write(135);
  b=1;

 }
 void right()
 {
  Esc1.write(e1=e1+45); // dummy values
  r=1;

 }
 void left()
 {
  Esc2.write(e2=e2+45); // dummy values
  l=1;

 }

