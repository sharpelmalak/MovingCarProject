/*
 * motor.h
 *
 * Created: 4/10/2023 4:13:09 PM
 *  Author: Alaa Hisham
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#define	MOTOR_1L_PORT			DIO_PORT_A
#define MOTOR_1L_PIN1			DIO_PIN_0
#define MOTOR_1L_PIN2			DIO_PIN_1

#define	MOTOR_2L_PORT			DIO_PORT_A
#define MOTOR_2L_PIN1			DIO_PIN_2
#define MOTOR_2L_PIN2			DIO_PIN_3

#define	MOTOR_1R_PORT			DIO_PORT_B
#define MOTOR_1R_PIN1			DIO_PIN_0
#define MOTOR_1R_PIN2			DIO_PIN_1

#define	MOTOR_2R_PORT			DIO_PORT_B
#define MOTOR_2R_PIN1			DIO_PIN_2
#define MOTOR_2R_PIN2			DIO_PIN_3

typedef enum
{
	MOTOR_CW,			// Clock-Wise
	MOTOR_CCW   		// Counter Clock-Wise
}en_MotorDirection_t;

typedef struct
{
	en_DIOPort_t Port;
	en_DIOPin_t Pin1;
	en_DIOPin_t Pin2;
	en_MotorDirection_t Dir;
}st_Motor_t;

typedef enum
{
	MOTOR_OK,
	MOTOR_ERROR	
}en_MotorError_t;

/*======================== Function Prototypes ========================*/

/**
 * \brief initialize motor pins
 * 
 * \param pst_a_Motor reference to desired motor
 * 
 * \return en_MotorError_t
 */
en_MotorError_t DCM_Init(st_Motor_t *pst_a_Motor);

/**
 * \brief Function to start the given motor
 * 
 * \param pst_a_Motor reference to desired motor
 * 
 * \return en_MotorError_t
 */
en_MotorError_t DCM_Start(st_Motor_t *pst_a_Motor);


/**
 * \brief Function to stop the given motor
 * 
 * \param pst_a_Motor reference to desired motor
 * 
 * \return en_MotorError_t
 */
en_MotorError_t DCM_Stop(st_Motor_t *pst_a_Motor);

#endif /* MOTOR_H_ */