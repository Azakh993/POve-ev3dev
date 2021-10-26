/*
Projektmedlemmar har bidragit med följande till programkoden:

Axel Lystam har skrivit funktionerna turn och drop_mail.
Azmeer Akhtar Khawaja har skrivit huvudfunktionen main och allt annat ovanför main.
Daniel Dahlberg har skrivit funktionerna orient_towards_wall, move_towards_wall och orient_towards_wall_2.
Marcus Cangren har skrivit funktionerna move och move_250_cm.
*/

#include <stdio.h>
#include "brick.h"
#include <unistd.h>

#define MOTOR_RIGHT    	OUTB
#define MOTOR_LEFT    	OUTA
#define MOTOR_UP   		OUTC

#define MOTOR_BOTH     	(MOTOR_LEFT | MOTOR_RIGHT)
#define MOTOR_ALL       (MOTOR_BOTH | MOTOR_UP)

#define SENSOR_TOUCH	IN1
#define SENSOR_GYRO		IN2
#define SENSOR_ULTRA	IN3

#define Sleep(msec) usleep((msec) * 1000)


void configure_sensors_and_motors(); //Konfigurerar sensorer och motorer.
void move(int speed_left_motor, int speed_right_motor); // Gör att vänster och höger motorer rör på sig en viss hastighet.
void orient_towards_wall(int rotation_speed); // Hittar och åker vinkelrätt in i närmsta vägg. Backar därefter 30 cm från väggen.
void turn(int degrees_to_rotate_clockwise, int rotation_speed); // Rotererar ett visst antal grader med en viss hastighet.
void move_250_cm(); // Gör att roboten färdas 250 cm.
void move_towards_wall(int rotation_speed); // Gör att roboten åker tills den hittar en vägg inom 30 cm.
void orient_towards_wall_2(int rotation_speed); // Avlastar posten.
void drop_mail(); // Hittar och åker baklänges vinkelrätt in i närmsta vägg.


void main()
{
    brick_init();
    POOL_T ultrasound_sensor = sensor_search(LEGO_EV3_US);
    POOL_T gyro_sensor = sensor_search(LEGO_EV3_GYRO);
    configure_sensors_and_motors();

    //Nollställer gyrosensorn.
    sensor_set_mode(gyro_sensor, LEGO_EV3_GYRO_GYRO_RATE);
    Sleep (500);
    sensor_set_mode(gyro_sensor, LEGO_EV3_GYRO_GYRO_ANG);
    Sleep (500);

    orient_towards_wall(100);
    turn(90, 100);
    brick_uninit();
    move_250_cm();

    //Nollställer gyrosensorn.
    sensor_set_mode(gyro_sensor, LEGO_EV3_GYRO_GYRO_RATE);
    Sleep (500);
    sensor_set_mode(gyro_sensor, LEGO_EV3_GYRO_GYRO_ANG);
    Sleep (500);

    orient_towards_wall_2(100);

    //Nollställer gyrosensorn.
    sensor_set_mode(gyro_sensor, LEGO_EV3_GYRO_GYRO_RATE);
    Sleep (500);
    sensor_set_mode(gyro_sensor, LEGO_EV3_GYRO_GYRO_ANG);
    Sleep (500);

    drop_mail();
    brick_uninit();
}

void configure_sensors_and_motors()
{
    if(!tacho_is_plugged(MOTOR_ALL, TACHO_TYPE__NONE_ ))
    {
        printf("No contact with one or more motor! \n");

        brick_uninit();
    }

    if(!sensor_is_plugged((SENSOR_ULTRA), SENSOR_TYPE__NONE_))
    {
        printf("No contact with Ultrasound sensor! \n");

        brick_uninit();
    }

    if(!sensor_is_plugged((SENSOR_GYRO), SENSOR_TYPE__NONE_))
    {
        printf("No contact with Gyro sensor! \n");

        brick_uninit();
    }
}

void move(int speed_left_motor, int speed_right_motor)
{
    tacho_set_speed_sp(MOTOR_LEFT, speed_left_motor);
    tacho_set_speed_sp(MOTOR_RIGHT, speed_right_motor);
    tacho_run_forever(MOTOR_BOTH);
}

void orient_towards_wall(int rotation_speed)
{
    POOL_T ultrasound_sensor = sensor_search(LEGO_EV3_US);
    POOL_T gyro_sensor = sensor_search(LEGO_EV3_GYRO);

    sensor_set_mode(gyro_sensor, LEGO_EV3_GYRO_GYRO_RATE);
    Sleep (500);
    sensor_set_mode(gyro_sensor, LEGO_EV3_GYRO_GYRO_ANG);
    Sleep (500);

    int shortest_registered_distance = 2550;
    int angle_to_shortest_distance = 0;
    int current_angle, current_distance;



    move(rotation_speed * 1, rotation_speed * -1);
    while(current_angle <= 360)
    {
        current_angle = sensor_get_value(0, gyro_sensor, 0);
        current_distance = sensor_get_value(0, ultrasound_sensor, 0);

        if(current_angle > 330)
        {
          move(rotation_speed / 2, -rotation_speed / 2);
        }
        if (current_distance < shortest_registered_distance)
        {
            shortest_registered_distance = current_distance;
            angle_to_shortest_distance = current_angle;
        }
    }

    tacho_stop(MOTOR_BOTH);

    if(angle_to_shortest_distance < 180)
    {
        move(rotation_speed, -rotation_speed);

        while((current_angle - 360) <= angle_to_shortest_distance)
        {
            current_angle = sensor_get_value(0, gyro_sensor, 0);
        }
    }

    if(angle_to_shortest_distance >= 180)
    {
        move(-rotation_speed, rotation_speed);

        while(current_angle >= angle_to_shortest_distance)
        {
            current_angle = sensor_get_value(0, gyro_sensor, 0);
        }
    }

    move(150, 150);
    Sleep(10000);

    while(sensor_get_value(0, ultrasound_sensor, 0) < 300)
    {
        sensor_get_value(0, ultrasound_sensor, 0);
        move(rotation_speed * -1, rotation_speed * -1);
    }

    tacho_stop(MOTOR_BOTH);
}

void turn(int degrees_to_rotate_clockwise, int rotation_speed)
{
    POOL_T ultrasound_sensor = sensor_search(LEGO_EV3_US);
    POOL_T gyro_sensor = sensor_search(LEGO_EV3_GYRO);
    int correction_factor = 0;

    int current_angle, current_distance;

    current_angle = sensor_get_value(0, gyro_sensor, 0);

    if(degrees_to_rotate_clockwise > 0)
    {
        current_angle = sensor_get_value(0, gyro_sensor, 0);
        move(rotation_speed * 1,rotation_speed * -1);
        while(sensor_get_value(0, gyro_sensor, 0) <= (current_angle + degrees_to_rotate_clockwise - correction_factor))
        {
            sensor_get_value(0, gyro_sensor, 0);
            if(sensor_get_value(0, gyro_sensor, 0) > current_angle + degrees_to_rotate_clockwise - 30)
            {
              move(rotation_speed / 2, -rotation_speed / 2);
            }
        }
    }

    if(degrees_to_rotate_clockwise < 0)
    {
        current_angle = sensor_get_value(0, gyro_sensor, 0);
        move(rotation_speed * -1, rotation_speed * 1);
        while(sensor_get_value(0, gyro_sensor, 0) >= (current_angle + degrees_to_rotate_clockwise + correction_factor))
        {
            sensor_get_value(0, gyro_sensor, 0);
            if(sensor_get_value(0, gyro_sensor, 0) < current_angle + degrees_to_rotate_clockwise + 30)
            {
              move(-rotation_speed / 2, rotation_speed / 2);
            }
        }
    }

    tacho_stop(MOTOR_BOTH);
}

void move_250_cm()
{
    tacho_set_speed_sp( MOTOR_BOTH, tacho_get_max_speed( MOTOR_LEFT, 0 ) * 0.4 );
    tacho_set_position_sp(MOTOR_BOTH, 5116 );
	tacho_run_to_rel_pos(MOTOR_BOTH);
    Sleep(15000);
    tacho_stop(MOTOR_BOTH);
}

void move_towards_wall(int rotation_speed)
{
    POOL_T ultrasound_sensor = sensor_search(LEGO_EV3_US);
    POOL_T gyro_sensor = sensor_search(LEGO_EV3_GYRO);

    int shortest_registered_distance = 2550;
    int angle_to_shortest_distance = 0;
    int current_angle, current_distance;

    while(sensor_get_value(0, ultrasound_sensor,0) > 300)
    {
        sensor_get_value(0, ultrasound_sensor, 0);
        move(rotation_speed * 1, rotation_speed * 1);
    }
    tacho_stop(MOTOR_BOTH);
}

void drop_mail()
{
  tacho_set_speed_sp( MOTOR_UP, (tacho_get_max_speed( MOTOR_UP, 0 ) * 1) );
  tacho_set_position_sp(MOTOR_UP, -100);
  tacho_run_to_rel_pos(MOTOR_UP);
  Sleep(10000);
  tacho_stop(MOTOR_UP);
}

void orient_towards_wall_2(int rotation_speed)
{
    POOL_T ultrasound_sensor = sensor_search(LEGO_EV3_US);
    POOL_T gyro_sensor = sensor_search(LEGO_EV3_GYRO);

    sensor_set_mode(gyro_sensor, LEGO_EV3_GYRO_GYRO_RATE);
    Sleep (500);
    sensor_set_mode(gyro_sensor, LEGO_EV3_GYRO_GYRO_ANG);
    Sleep (500);

    int shortest_registered_distance = 2550;
    int angle_to_shortest_distance = 0;
    int current_angle, current_distance;



    move(rotation_speed * 1, rotation_speed * -1);
    while(current_angle <= 360)
    {
        current_angle = sensor_get_value(0, gyro_sensor, 0);
        current_distance = sensor_get_value(0, ultrasound_sensor, 0);

        if(current_angle > 330)
        {
          move(rotation_speed / 2, -rotation_speed / 2);
        }
        if (current_distance < shortest_registered_distance)
        {
            shortest_registered_distance = current_distance;
            angle_to_shortest_distance = current_angle;
        }
    }

    tacho_stop(MOTOR_BOTH);

    if(angle_to_shortest_distance < 180)
    {
        move(rotation_speed, -rotation_speed);

        while((current_angle - 360) <= angle_to_shortest_distance)
        {
            current_angle = sensor_get_value(0, gyro_sensor, 0);
        }
    }

    if(angle_to_shortest_distance >= 180)
    {
        move(-rotation_speed, rotation_speed);

        while(current_angle >= angle_to_shortest_distance)
        {
            current_angle = sensor_get_value(0, gyro_sensor, 0);
        }
    }

    while(sensor_get_value(0, ultrasound_sensor, 0) < 300)
    {
        sensor_get_value(0, ultrasound_sensor, 0);
        move(rotation_speed * -1, rotation_speed * -1);
    }

   while(sensor_get_value(0, ultrasound_sensor,0) > 300)
    {
        sensor_get_value(0, ultrasound_sensor, 0);
        move(rotation_speed * 1, rotation_speed * 1);
    }

    tacho_stop(MOTOR_BOTH);
}
