//M.Cangren 20-40, 97-->
//Fortsättning av A.Lystam
//Vi måste ta reda på källan till huvudkoden för "exempelmotorTouch2...."

#include <stdio.h>
#include <brick.h>
#include <unistd.h>

#define Sleep( msec ) usleep(( msec ) * 1000 ) /* Definerar sleep, Sleep(1000)= 1 sekund */

#define MOTOR_L    	    OUTA
#define MOTOR_R    	    OUTB
#define MOTOR_C    	    OUTC
#define MOTOR_D    		OUTD
#define SENSOR_TOUCH	IN1
#define GYRO     		IN2
#define SENSOR_3		IN3
#define PHOTO		    IN4
#define MOTOR_BOTH     	( MOTOR_L | MOTOR_R ) /* Bitvis ELLER ger att båda motorerna styrs samtidigt */

void turn_L(); //svänger 90 grader v. 
void turn_R(); //svänger 90 grader h. 
void fwd_m( float m ); //kör framåt x meter
void rev_m( float m );  //backar x meter. 
void fwd_250cm(); //kör framåt 250cm,
void rev_250cm();  //backar.
void reset_gyro(); //nolställer gyrot genom att "toggla" mellan modes. 
void find_wall(); //Hitta väggen
void fwd_until_UL( int ); //kör tills ultraljudet = distans.
void rev_until_UL( int ); 
void release_book();
void tighten();
//int get_bar(); 

int max_speed_L; 
int max_rampUP_L; 
int max_rampDN_L;        /* variablar för max hastighet, ramp up/_L på motorn */
int gyro_ang;
int wheel_count; 
int max_speed_C; 
int max_rampUP_C; 
int max_rampDN_C; 

POOL_T gyroSensor;
//int color; 

POOL_T touchSensor; 
int TouchReturnValue = 0;

int main( void )
{  
    
    //Definierar variabler för sensorer, letar efter de och sätter dess modes
    touchSensor = sensor_search( LEGO_EV3_TOUCH );
    touch_set_mode_touch(touchSensor);

    gyroSensor = sensor_search(LEGO_EV3_GYRO);
    sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);

    reset_gyro();

	if ( !brick_init()) return ( 1 ); /* Initialiserar EV3-klossen  ej grupp 10*/
	printf( "*** ( POve ) Petter Olof Viktor Erik, redo att lämna post! ***\n" );
	Sleep( 2000 );

    if(!sensor_is_plugged((SENSOR_TOUCH|GYRO), SENSOR_TYPE__NONE_)) {
        printf("Stoppa in sensorer i port 1 och 2\n");
        brick_uninit();
        return(0);
    }
	
	if ( tacho_is_plugged( MOTOR_BOTH, TACHO_TYPE__NONE_ )) {  /* TACHO_TYPE__NONE_ = Alla typer av motorer */
        
        max_speed_L = tacho_get_max_speed( MOTOR_L, 0 );	    // Kollar maxhastigheten som motorn kan ha * M.C 45-49
        max_rampUP_L = tacho_get_ramp_up_sp( MOTOR_L, 0);      
        max_rampDN_L = tacho_get_ramp_down_sp( MOTOR_L, 0);
        max_speed_C = tacho_get_max_speed( MOTOR_C, 0 );
        max_rampUP_C = tacho_get_ramp_up_sp( MOTOR_C, 0);      
        max_rampDN_C = tacho_get_ramp_down_sp( MOTOR_C, 0);   
        printf("Max-SPD-L: %d Max-SPD-C: %d Ramp-UP: %d Ramp-DN: %d\n", max_speed_L, max_speed_C, max_rampUP_L, max_rampDN_L);  
        tacho_reset( MOTOR_BOTH );
        printf("Max-SPD-L: %d Max-SPD-C: %d Ramp-UP: %d Ramp-DN: %d\n", max_speed_L, max_speed_C, max_rampUP_L, max_rampDN_L); //för att se vad som händer med tacho_reset.  
    } else {
        printf( "Anslut vänster motor i port A,\n" //51-57 ej grp 10 
        "Anslut höger motor i port B.\n"
        );
      	brick_uninit();
        return ( 0 );  /* Stänger av sig om motorer ej är inkopplade */
    }


    //Här händer det grejer
    tacho_set_speed_sp( MOTOR_BOTH, max_speed_L * 0.2 ); 

    tacho_set_speed_sp( MOTOR_C, max_speed_C * 0.1 );
    tighten();

    //fwd_m( 2.5 );
    turn_L();
    //Sleep( 5000 );
    //rev_m( 3 );
    turn_R();
    
    tacho_set_speed_sp( MOTOR_C, max_speed_C * -0.1 );
    release_book();


	Sleep( 5000 ); //sleepfunktion medans något körs. annars kommer nästa med detssamma.  

    //funktion som ska röra arm, ange minus ett för ena hållet. 
    //funktion som ska röra arm, ange minus ett för uppåt. 
    
       
	brick_uninit();
	printf( "Petter Ove skjuter ned...\n" );
    return ( 0 );

    //Här är den färdig

}

void fwd_m( float m){
    tacho_set_speed_sp( MOTOR_BOTH, max_speed_L * 0.2 );
    tacho_set_ramp_up_sp( MOTOR_BOTH, max_rampUP_L * 0.01 );
    tacho_set_ramp_up_sp( MOTOR_BOTH, max_rampDN_L * 0.01 );
    tacho_set_position_sp(MOTOR_BOTH, ( 2047 * m ));
	tacho_run_to_rel_pos(MOTOR_BOTH);
	Sleep( 5000*m ); /*sleepfunktion medans något körs. annars kommer nästa med detssamma.  */
}

void rev_m( float m){
    tacho_set_speed_sp( MOTOR_BOTH, max_speed_L * 0.2 );
    tacho_set_ramp_up_sp( MOTOR_BOTH, max_rampUP_L * 0.01 );
    tacho_set_ramp_up_sp( MOTOR_BOTH, max_rampDN_L * 0.01 );
    tacho_set_position_sp(MOTOR_BOTH, ( 2047 * m ));
	tacho_run_to_rel_pos(MOTOR_BOTH);
	Sleep( 5000*m ); /*sleepfunktion medans något körs. annars kommer nästa med detssamma.  */
}
/*
void fwd_250cm(){
    tacho_set_speed_sp( MOTOR_BOTH, max_speed_L * 0.2 );
    tacho_set_ramp_up_sp( MOTOR_BOTH, max_rampUP_L * 0.01 ); //viktigt---ska det vara minus på rampfarter när hjulet backar. 
    tacho_set_ramp_up_sp( MOTOR_BOTH, max_rampDN_L * 0.01 );
    tacho_set_position_sp(MOTOR_BOTH, 5116 ); 
	tacho_run_to_rel_pos(MOTOR_BOTH);
    Sleep( 20000 ); //kolla hur lång tid som behövs för att åka 250cm. 
}

void rev_250cm(){
    tacho_set_speed_sp( MOTOR_BOTH, max_speed_L * -0.2 );
    tacho_set_ramp_up_sp( MOTOR_BOTH, max_rampUP_L * 0.01 ); //viktigt---ska det vara minus på rampfarter när hjulet backar. 
    tacho_set_ramp_up_sp( MOTOR_BOTH, max_rampDN_L * 0.01 );
    tacho_set_position_sp(MOTOR_BOTH, 5116 ); //ska det stå minus? även om farten är minus? 
	tacho_run_to_rel_pos(MOTOR_BOTH);
    Sleep( 20000 ); //kolla hur lång tid som behövs för att åka 250cm.
}
*/
void turn_L(){

    sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
    Sleep(500);
    sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_RATE); //Nollställer Vinkelvärdet
    Sleep(500);
    sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
    Sleep(500);

    tacho_set_speed_sp( MOTOR_L, max_speed_L * -0.02);
    tacho_set_speed_sp( MOTOR_R, max_speed_L * 0.02);

    gyro_ang = sensor_get_value(0,gyroSensor,0);

    while ( gyro_ang !=-90 )
    {
        
        gyro_ang = sensor_get_value(0, gyroSensor, 0);
        printf("%d",gyro_ang);

        tacho_run_forever( MOTOR_BOTH ); 

        if(gyro_ang==-90){
            tacho_stop( MOTOR_BOTH );
                
        }
        if(gyro_ang>1000 || gyro_ang<-1000){
            tacho_stop( MOTOR_BOTH );
        }
    }
    
}

void turn_R(){
    
    sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
    Sleep(500);
    sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_RATE); //Nollställer Vinkelvärdet
    Sleep(500);
    sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
    Sleep(500);

    tacho_set_speed_sp( MOTOR_L, max_speed_L * 0.02);
    tacho_set_speed_sp( MOTOR_R, max_speed_L * -0.02);

    gyro_ang = sensor_get_value(0,gyroSensor,0);

    while ( gyro_ang !=90 )
    {

        gyro_ang = sensor_get_value(0, gyroSensor, 0);
        printf("%d",gyro_ang);

        tacho_run_forever( MOTOR_BOTH ); 

        if(gyro_ang==90){
            tacho_stop( MOTOR_BOTH );
                
        }
        if(gyro_ang>1000 || gyro_ang<-1000){
            tacho_stop( MOTOR_BOTH );
        }
    }
}







void reset_gyro(){ //Kanske inte funkar
    sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
    Sleep(500);
    sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_RATE); //Nollställer Vinkelvärdet
    Sleep(500);
    sensor_set_mode(gyroSensor, LEGO_EV3_GYRO_GYRO_ANG);
    Sleep(500);
}

void fwd_until_UL( int dist ){
    while (1)
    {
        tacho_set_speed_sp(MOTOR_BOTH, max_speed_L * 0.02 );
        tacho_run_forever(MOTOR_BOTH);
    }
}
void rev_until_UL( int dist ){
    while (1)
    {
        tacho_set_speed_sp(MOTOR_BOTH, max_speed_L * -0.02 );
        tacho_run_forever(MOTOR_BOTH);
        Sleep( 10000 ); 
    }
}

void release_book(){
    
    tacho_set_ramp_up_sp( MOTOR_C, max_rampUP_C * 0.01 );
    tacho_set_ramp_down_sp( MOTOR_C, max_rampDN_C * 0.01 );
    
    tacho_run_forever(MOTOR_C);
    //tacho_set_position_sp( MOTOR_C, 10 );
    //tacho_run_to_rel_pos( MOTOR_C );
    Sleep(1800); 
    tacho_stop( MOTOR_C );
}

void tighten(){
    
    tacho_set_ramp_up_sp( MOTOR_C, max_rampUP_C * 0.01 );
    tacho_set_ramp_down_sp( MOTOR_C, max_rampDN_C * 0.01 );
    
    tacho_run_forever(MOTOR_C);
    //tacho_set_position_sp( MOTOR_C, 10 );
    //tacho_run_to_rel_pos( MOTOR_C );
    Sleep(3000); 
    tacho_stop( MOTOR_C );
}



 

/*int get_bar(){
    sensor_get_bin_data( PHOTO ); 
}*/
