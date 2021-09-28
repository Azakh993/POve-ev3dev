#include <stdio.h>
#include "brick.h"
#include <unistd.h>

#define Sleep( msec ) usleep(( msec ) * 1000 ) /*Definerar sleep där Sleep(1000)= 1 sekund*/

#define MOTOR_RIGHT    	OUTA
#define MOTOR_LEFT    	OUTB
#define MOTOR_C    		OUTC
#define MOTOR_D    		OUTD
#define SENSOR_TOUCH	IN1
#define SENSOR_GYRO		IN2
#define SENSOR_3		IN3
#define SENSOR_4		IN4

#define MOTOR_BOTH     	( MOTOR_LEFT | MOTOR_RIGHT )

POOL_T touchSensor; 
int TouchReturnValue = 0;



int max_hastighet;

POOL_T gyroSensor;
int gyroValue0 = 0;
int gyroValue1 = 0;

//void ang_reset();

int main( void )
{  
	sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG); //Du MÅSTE sätta rätt mode först innan du "nollställer"
	Sleep(1000);
	sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_RATE); //Nollställer Vinkelvärdet
	Sleep(1000);
	sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
	Sleep(1000);

	if ( !brick_init()) return ( 1 ); /*Instansierar klossen och tillåter remote-connection*/
	printf( "*** ( EV3 ) Hello! ***\n" );
	Sleep(2000);

	if(!sensor_is_plugged((SENSOR_TOUCH|SENSOR_GYRO), SENSOR_TYPE__NONE_)) {
		printf("Stoppa in sensorer i port 1 och 2\n");
		brick_uninit();
		return(0);
	}
	if ( tacho_is_plugged( MOTOR_BOTH, TACHO_TYPE__NONE_ )) {  /* TACHO_TYPE__NONE_ = Alla typer av motorer */
        max_hastighet = tacho_get_max_speed( MOTOR_LEFT, 0 );	/* Kollar maxhastigheten som motorn kan ha */
        tacho_reset( MOTOR_BOTH );
    } else {
        printf( "Anslut vänster motor i port A,\n"
        "Anslut höger motor i port B.\n"
        );
      	brick_uninit();
        return ( 0 );  /* Stänger av sig om motorer ej är inkopplade */
    }
	/*Registrerar en sensor på sensor variabeln*/
	touchSensor = sensor_search( LEGO_EV3_TOUCH ); //
	gyroSensor = sensor_search(LEGO_EV3_GYRO);
	
	/*Man kan antingen använda "Brick" bibliotekets förbyggda modes*/
	touch_set_mode_touch(touchSensor);
	
	/*eller kolla i sensor.h filen på vilka modes som finns för alla olika sensorer*/
	sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
	

	  // Sätter hastigheten på båda motorerna till 50% av maxhastigheten
	/* Om man vill köra bakåt anger man negativ hastighet, till exempel max_hastighet * (-0.5) */
	
	
	
	while(!TouchReturnValue){
		/*Vissa modes kan ha fler utdata, notera första parametern i sensor_get_value */

		tacho_set_speed_sp( MOTOR_RIGHT, max_hastighet * 0.05 );
		tacho_set_speed_sp( MOTOR_LEFT, max_hastighet *-0.05 );

		TouchReturnValue = sensor_get_value(0, touchSensor, 0);

		gyroValue0 = sensor_get_value(0, gyroSensor, 0); 
		printf("Gyro0: %d \n", gyroValue0);
		Sleep(1000);
		sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_RATE); //Nollställer Vinkelvärdet
		Sleep(1000);
		sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
		Sleep(1000);
		

		while(!(gyroValue0==360)){
			TouchReturnValue = sensor_get_value(0, touchSensor, 0);

			gyroValue0 = sensor_get_value(0, gyroSensor, 0);
			
			tacho_run_forever(MOTOR_BOTH);

			printf("Gyro0: %d \n", gyroValue0 );
			
			if(gyroValue0==360){
				tacho_stop( MOTOR_BOTH );
				
			}
			if(gyroValue0>2000 || gyroValue0<-2000){
				tacho_stop( MOTOR_BOTH );
			}
		}
		
		sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_RATE); //Nollställer Vinkelvärdet
		Sleep(1000);
		sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
		Sleep(1000);

		tacho_set_speed_sp( MOTOR_RIGHT, max_hastighet * -0.05 );
		tacho_set_speed_sp( MOTOR_LEFT, max_hastighet * 0.05 );

		while(!(gyroValue0==-90)){
			TouchReturnValue = sensor_get_value(0, touchSensor, 0);

			gyroValue0 = sensor_get_value(0, gyroSensor, 0);
			
			tacho_run_forever(MOTOR_BOTH);

			printf("Gyro0: %d \n", gyroValue0 );
			
			if(gyroValue0==-90){
				tacho_stop( MOTOR_BOTH);
				
			}
			if(gyroValue0>2000 || gyroValue0<-2000){
				tacho_stop( MOTOR_BOTH );
			}
		}

		tacho_stop(MOTOR_BOTH);

		
		Sleep(1000);

	}//Så länge touch sensorn inte är intryckt kommer while loopen köras
	

	brick_uninit();
	printf( "dying...\n" );
    return ( 0 );
}
/*int ang_reset(){
	sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_RATE); //Nollställer Vinkelvärdet
	Sleep(1000);
	sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
	Sleep(1000);
}*/


