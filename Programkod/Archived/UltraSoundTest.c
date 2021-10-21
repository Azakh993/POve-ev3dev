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
#define SENSOR_US		IN3
#define SENSOR_4		IN4

#define MOTOR_BOTH     	( MOTOR_LEFT | MOTOR_RIGHT ) /* Bitvis ELLER ger att båda motorerna styrs samtidigt */

int max_hastighet;         /* variabel för max hastighet på motorn */

POOL_T ultrasoundSensor;
int PCD1 = 2551;
int PCD2 = 2551;
int PCD3 = 2551;
int PCD4 = 2551; // 1) PCD står för Potentially Closest Distance. 2) Variablerna måste vara större än ultraljudssensorns största möjliga utdata för att while-looparna från rad 90 till 143 ska kunna aktiveras.
int ClosestDistance1, ClosestDistance2 = 0;
int PotentialDegrees1, PotentialDegrees2, PotentialDegrees3, PotentialDegrees4 = 0;
int Degrees1, Degrees2 = 0;
int DistanceDif1, DistanceDif2 = 0;
int usValue = 0;

POOL_T gyroSensor;
int gyroValue0 = 0;

POOL_T touchSensor;
int TouchReturnValue = 0;

int main( void )
{

	if ( !brick_init()) return ( 1 ); /*Instansierar klossen och tillåter remote-connection*/
	printf( "*** ( EV3 ) Hello! ***\n" );
	Sleep(2000);

// Nedan konfigureras ultraljuds- och gyrosensorn
	if(!sensor_is_plugged((SENSOR_US | SENSOR_GYRO), SENSOR_TYPE__NONE_)) {
		printf("Anslut gyro- och ultraljudssensorn i port 2 respektive 3\n");
		brick_uninit();
		return(0);
	}

	/*Registrerar två sensorer*/
	ultrasoundSensor = sensor_search( LEGO_EV3_US );
	gyroSensor = sensor_search(LEGO_EV3_GYRO);

	/*Anger läge för sensorn*/
	sensor_set_mode(ultrasoundSensor, LEGO_EV3_US_US_DIST_CM);
	sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);

// Nedan konfigureras tacho-motorn
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

// Nedan återställs gyrosensorns värden till 0 genom att byta till ett annat läge och sedan tillbaka till ursprungsläget
	gyroValue0 = sensor_get_value(0, gyroSensor, 0);
	printf("Gyro0: %d \n", gyroValue0);
	Sleep(1000);
	sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_RATE);
	printf("Gyro0: %d \n", gyroValue0);
	Sleep(1000);
	sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
	Sleep(1000);
	printf("Gyro0: %d \n", gyroValue0);
	Sleep(1000);

/* Nedanstående if-sats hittar de två närmsta väggarna till roboten.

Villkor för att if-satsen ska aktiveras:
När roboten är som högst 2,5 meter från ett föremål aktiveras if-satsen.

If-satsens funktionalitet:
Rotera ett varv och lagra avstånden inklusive vinklarna till den närmsta väggen och väggen tvärs emot */
	if(sensor_get_value(0, ultrasoundSensor, 0) < 2500)
	{
		// Nedan anges motorhastigheten
		tacho_set_speed_sp( MOTOR_LEFT, max_hastighet * 0.05 );  // Sätter hastigheten för vänster motorer till 50% av maxhastigheten
		tacho_set_speed_sp( MOTOR_RIGHT, max_hastighet * (-0.05)); //Sätter hastigheten för höger motor till 50% av maxhastigheten
		tacho_run_forever(  MOTOR_BOTH ); // Startar motorerna

		while(gyroValue0 > -90) //Rotera 90 grader och lagra avståndet & vinkeln till närmsta föremål inom kvadrant #1
		{
			usValue = sensor_get_value(0, ultrasoundSensor, 0); // Lagrar ultraljudssensorns utdata i variabeln usValue
			gyroValue0 = sensor_get_value(0, gyroSensor, 0); // Lagrar gyrosensorns utdata i variabeln gyroValue0

			if(PCD1 > usValue)
			{
				PCD1 = usValue;
				PotentialDegrees1 = gyroValue0;
			}
		}

		while(gyroValue0 > -180) // Rotera ytterligare 90 grader och lagra avståndet & vinkeln till närmsta föremål inom kvadrant #2
		{
			usValue = sensor_get_value(0, ultrasoundSensor, 0); // Lagrar ultraljudssensorns utdata i variabeln usValue
			gyroValue0 = sensor_get_value(0, gyroSensor, 0); // Lagrar gyrosensorns utdata i variabeln gyroValue0

			if(PCD2 > usValue)
			{
				PCD2 = usValue;
				PotentialDegrees2 = gyroValue0;
			}
		}

		while(gyroValue0 > -270) // Rotera ytterligare 90 grader och lagra avståndet & vinkeln till närmsta föremål inom kvadrant #3
		{
			usValue = sensor_get_value(0, ultrasoundSensor, 0); // Lagrar ultraljudssensorns utdata i variabeln usValue
			gyroValue0 = sensor_get_value(0, gyroSensor, 0); // Lagrar gyrosensorns utdata i variabeln gyroValue0

			if(PCD3 > usValue)
			{
				PCD3 = usValue;
				PotentialDegrees3 = gyroValue0;
			}
		}

		while(gyroValue0 > -360) // Rotera ytterligare 90 grader och lagra avståndet & vinkeln till närmsta föremål inom kvadrant #4
		{
			usValue = sensor_get_value(0, ultrasoundSensor, 0); // Lagrar ultraljudssensorns utdata i variabeln usValue
			gyroValue0 = sensor_get_value(0, gyroSensor, 0); // Lagrar gyrosensorns utdata i variabeln gyroValue0

			if(PCD4 > usValue)
			{
				PCD4 = usValue;
				PotentialDegrees4 = gyroValue0;
			}
		}

		tacho_stop (MOTOR_BOTH);
		Sleep(2000);

		/* Nedanstående if-sats avgör vilken av de fyra kvadranterna som innehåller det närmsta avståndet.
		Om kvadrant #1 innehåller det närmsta avståndet, tilldelas variablerna ClosestDistance1 och ClosestDistance2 värdena av det närmsta avståndet i kvadrant #1 och dess motstående kvadrant #3.
		Om kvadrant #2 eller #4  innehåller det närmsta avståndet, tilldelas variablerna ClosestDistance1 och ClosestDistance2 värdena av det närmsta avståndet i kvadrant #2 och dess motstående kvadrant #4.*/
		if(PCD1 <= PCD2 && PCD1 <= PCD4)
		{
			ClosestDistance1 = PCD1;
			ClosestDistance2 = PCD3;
			Degrees1 = PotentialDegrees1;
			Degrees2 = PotentialDegrees3;
		}
		else
		{
			ClosestDistance1 = PCD2;
			ClosestDistance2 = PCD4;
			Degrees1 = PotentialDegrees2;
			Degrees2 = PotentialDegrees4;
		}

		// Återställer värdena av PCD-variablerna till 2551 så att if-satsen på rad 90 kan köras igen.
		PCD1 = 2551;
		PCD2 = 2551;
		PCD3 = 2551;
		PCD4 = 2551;

		// Inverterar motorhastigheten för vänster och höger motor
		tacho_set_speed_sp( MOTOR_LEFT, max_hastighet * (-0.05) );
		tacho_set_speed_sp( MOTOR_RIGHT, max_hastighet * 0.05 );
		tacho_run_forever(  MOTOR_BOTH );

		//Låter roboten rotera tillbaka från dess aktuella vinkel, -360 grader, till det närmsta avståndet som registrerades för variabeln ClosestDistance2.
		while(gyroValue0 < (-360) - ((-360) - Degrees2))
		{
			gyroValue0 = sensor_get_value(0, gyroSensor, 0);
		}

		tacho_stop (MOTOR_BOTH);

 }
		Sleep(2000);

		DistanceDif1 = ClosestDistance1 - ClosestDistance2; // Definierar avståndsskillnaden mellan ClosestDistance1 och ClosestDistance2 för de fall ClosestDistance1 är större än ClosestDistance2.
		DistanceDif2 = ClosestDistance2 - ClosestDistance1; // Definierar avståndsskillnaden mellan ClosestDistance1 och ClosestDistance2 för de fall ClosestDistance2 är större än ClosestDistance1.
				if(ClosestDistance1 > ClosestDistance2)
				{
					tacho_set_speed_sp( MOTOR_BOTH, max_hastighet * (-0.05) );
					tacho_run_forever( MOTOR_BOTH );
					Sleep(DistanceDif1 * 37); // Roboten färdas bakåt så många centimeter som krävs för att avståndet till varje vägg ska bli lika. Faktorn 37 är så många millisekunder roboten behöver "sova" för att färdas en centimeter.
					usValue = sensor_get_value(0, ultrasoundSensor, 0); //Faktorn 37 är så många millisekunder roboten behöver "sova" för att färdas en centimeter.
					ClosestDistance1 -= DistanceDif1; // Jämnställer ClosestDistance1 med ClosestDistance2.
					ClosestDistance2 += DistanceDif1; // Jämnställer ClosestDistance2 med ClosestDistance1.
				}

				if(ClosestDistance2 > ClosestDistance1)
				{
					tacho_set_speed_sp( MOTOR_BOTH, max_hastighet * 0.05 );
					tacho_run_forever( MOTOR_BOTH );
					Sleep(DistanceDif2 * 37); //Roboten färdas framåt så många centimeter som krävs för att avståndet till varje vägg ska bli lika. Faktorn 37 är så många millisekunder roboten behöver "sova" för att färdas en centimeter.
					usValue = sensor_get_value(0, ultrasoundSensor, 0);
					ClosestDistance1 += DistanceDif2; // Jämnställer ClosestDistance1 med ClosestDistance2.
					ClosestDistance2 -= DistanceDif2; // Jämnställer ClosestDistance2 med ClosestDistance1.
				}

				tacho_stop (MOTOR_BOTH);

				// Återställer gyrosensorns värden till 0 genom att byta till ett annat läge och sedan tillbaka till ursprungsläget.
				sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_RATE);
				Sleep(500);
				sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
				Sleep(500);
				gyroValue0 = 0;
				usValue = 0;

		sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_RATE);
		Sleep(1000);
		sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
		Sleep(1000);

	brick_uninit();
	printf( "dying...\n" );
    return ( 0 );

}
