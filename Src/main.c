/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "adc.h"
#include "i2c.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
//#include "ssd1306.h"
//#include "fonts.h"
#include "fsm.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
extern	SSD1306_t SSD1306;
volatile	uint32_t	key_scan,key_scan_1,key_counter;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void HAL_SYSTICK_Callback(void)
{
	key_counter++;
	key_scan_1 = (GPIOA->IDR & 0xF8);
	key_scan = (key_scan_1 >> 3);
	key_scan ^= 0x1F;
}
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */


//мои переменные
int elem_prog=1; // выбор элемента для программирования (всего 8 элементов от 1 до 8)
int kol_elem_prog=0; // показатель конкретного элемента для програмирования
int oborot = 0; // переменная, которая считает количесво оборотов
int next_oborot=1;//переменная которая определяем номер следующего оборота
int a_i=0; //- переменная счетчик для проверки записанного элемента массива
int mega = 0;// переменная, которая считает количество мегациклов(один мегацикл - это полностью программа), ведется обратный отсчет, при 0 вызывается функция стоп
int prev_side = 0; // переменная, которая указывает датчик какой стороны сработал прошлый раз, нужна для того, чтобы избежать ошибок при срабатывании дважды подряд датчика с одной стороны
uint16_t prog_oborot = 123;//переменная для программирования количества оборотов в мегацикле
uint16_t cv_1[20]={1,2,3,4,5,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//массив включений первого цвета
uint16_t cv_2[20]={2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//массив включений второго цвета
uint16_t cv_3[20]={3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//массив включений третьего цвета
uint16_t cv_4[20]={4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//массив включений четвертого цвета
uint16_t pered_val[20]={5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//массив включений переднего валика
uint16_t zad_val[20]={6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//массив включений заднего валика
uint16_t stop_mass[20]={7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//массив остановок



//мои дефайны для управления соленоидами (включение/выключение пинов)
#define CV1_DEF_ON HAL_GPIO_WritePin(GPIOB, CV1_SOLENOID_Pin, GPIO_PIN_SET); // !!!нужно записать конкретный порт и вывод!!!
#define CV1_DEF_OFF HAL_GPIO_WritePin(GPIOB, CV1_SOLENOID_Pin, GPIO_PIN_RESET); // !!!нужно записать конкретный порт и вывод!!!

#define CV2_DEF_ON HAL_GPIO_WritePin(GPIOB, CV2_SOLENOID_Pin, GPIO_PIN_SET); // !!!нужно записать конкретный порт и вывод!!!
#define CV2_DEF_OFF HAL_GPIO_WritePin(GPIOB, CV2_SOLENOID_Pin, GPIO_PIN_RESET); // !!!нужно записать конкретный порт и вывод!!!

#define CV3_DEF_ON HAL_GPIO_WritePin(GPIOB, CV3_SOLENOID_Pin, GPIO_PIN_SET); // !!!нужно записать конкретный порт и вывод!!!
#define CV3_DEF_OFF HAL_GPIO_WritePin(GPIOB, CV3_SOLENOID_Pin, GPIO_PIN_RESET); // !!!нужно записать конкретный порт и вывод!!!

#define CV4_DEF_ON HAL_GPIO_WritePin(GPIOB, CV4_SOLENOID_Pin, GPIO_PIN_SET); // !!!нужно записать конкретный порт и вывод!!!
#define CV4_DEF_OFF HAL_GPIO_WritePin(GPIOB, CV4_SOLENOID_Pin, GPIO_PIN_RESET); // !!!нужно записать конкретный порт и вывод!!!

#define PERED_VAL_DEF_ON HAL_GPIO_WritePin(GPIOA, VAL_PERED_SOLENOID_Pin, GPIO_PIN_SET); // !!!нужно записать конкретный порт и вывод!!!
#define PERED_VAL_DEF_OFF HAL_GPIO_WritePin(GPIOA, VAL_PERED_SOLENOID_Pin, GPIO_PIN_RESET); // !!!нужно записать конкретный порт и вывод!!!

#define ZAD_VAL_DEF_ON HAL_GPIO_WritePin(GPIOA, VAL_ZAD_SOLENOID_Pin, GPIO_PIN_SET); // !!!нужно записать конкретный порт и вывод!!!
#define ZAD_VAL_DEF_OFF HAL_GPIO_WritePin(GPIOA, VAL_ZAD_SOLENOID_Pin, GPIO_PIN_RESET); // !!!нужно записать конкретный порт и вывод!!!


//мои функции тут

void stop_fun(void){//функция остановки
	HAL_GPIO_WritePin(GPIOA,STOP_RELE_Pin, GPIO_PIN_SET);// высокий потенциал на включение реле "в разрыв" линии стоп
	HAL_Delay(200); //0,2 секунды для срабатывания стопа, если мало, то добавить
	HAL_GPIO_WritePin(GPIOA,STOP_RELE_Pin, GPIO_PIN_RESET);//выключаем реле
	//можно добавить еще надпись на экран
}

void left_side(void){//функция срабатывания датчика левой стороны
	// с левой стороны должны включаться и выключаться соленоиды управления цветниками
	if (prev_side<2){//если перед этим не срабатывала правая сторона (2) или это начало цикла(0), а предыдущая сторона была левая (1)
		return;		//то выходим и ничего не делаем
	}
	prev_side=1;//отмечаем, что предудущая сторона была левая
	if (oborot<prog_oborot){//если количество оборотов меньше чем запрограммированный размер мегацикла
		next_oborot= oborot+1; //то следующий оборот будет текущий оборот+1
	}
	else {// если текущий оборот равет количеству запрограммированных оборотов
		next_oborot= 1; //то следующий оборот будет 1
	}
	//***************** сначала выключаем все соленоиды цветников
	CV1_DEF_OFF;// дефайн выключения первого цветника
	CV2_DEF_OFF;// дефайн выключения второго цветника
	CV3_DEF_OFF;// дефайн выключения третьего цветника
	CV4_DEF_OFF;// дефайн выключения четвертого цветника

	//теперь проверяем если следующий оборот (next_oborot) содержит переключение цветов, то включаем солениод соответствующего цвета
	a_i=0;//сбрасываем счетчик элементов массива
	for (a_i=0; a_i<20; a_i++){
		if(cv_1[a_i]==next_oborot){//если значение текущего элемента массива равно следующему оборону
			CV1_DEF_ON;	//то включаем первый цвет
		}
		if(cv_2[a_i]==next_oborot){//если значение текущего элемента массива равно следующему оборону
			CV2_DEF_ON;	//то включаем второй цвет
		}
		if(cv_3[a_i]==next_oborot){//если значение текущего элемента массива равно следующему оборону
			CV3_DEF_ON;	//то включаем третий цвет
		}
		if(cv_4[a_i]==next_oborot){//если значение текущего элемента массива равно следующему оборону
			CV4_DEF_ON;	//то включаем четвертый цвет
		}
	}
	a_i=0;//сбрасываем счетчик элементов массива
}
void right_side(void){//функция срабатывания датчика правой стороны
	// с правой стороны должны включаться и выключаться соленоиды управления клиньями, стоп, считаться циклы и мегациклы
		if (prev_side==2){//если перед этим срабатывала правая сторона
			return;		//то выходим и ничего не делаем
		}
		if (oborot==prog_oborot && next_oborot==1){//если прошлый оборот, который пока еще равен oborot, равен количеству оборотов в мегацикле, а следующий оборот уже равен 1
			mega=mega-1; // то уменьшаем значение количества мегациклов на 1
		}
		if (mega==0){ //если после этого как мы уменьшили мегу она равно 0 - то вызываем функцию стоп и выходим из функции
		stop_fun();
		return;//выходим и ничего не делаем дальше
		}
		prev_side=2;//отмечаем, что предудущая сторона была левая, только после того как проверили мегу
		oborot=next_oborot; // устанавливаем текуший оборот, если это старт, то next_oborot будет 1
		//***************** сначала выключаем все соленоиды управления клиньями
		PERED_VAL_DEF_OFF;// дефайн выключения соленоида переднего валика
		ZAD_VAL_DEF_OFF;// дефайн выключения соленоида заднего валика
		//теперь проверяем если текущий оборот (oborot) содержит валики, то включаем солениод соответствующего валика
		//а также, если текущий оборот содержит стоп, то вызываем функцию стоп
		a_i=0;//сбрасываем счетчик элементов массива
		for (a_i=0; a_i<20; a_i++){
			if(pered_val[a_i]==oborot){//если значение текущего элемента массива равно текущему оборону
				PERED_VAL_DEF_ON;	//то включаем передний валик
			}
			if(zad_val[a_i]==oborot){//если значение текущего элемента массива равно текущему оборону
				ZAD_VAL_DEF_ON;	//то включаем задний валик
			}
			if(stop_mass[a_i]==oborot){//если значение текущего элемента массива равно текущему оборону
				stop_fun();	//то вызываем функцию стоп
			}
		}
		a_i=0;//сбрасываем счетчик элементов массива
}

void sbros(void){//функция нажатия кнопки сброс в положении программирования
	elem_prog=1; // выбор элемента для программирования (всего 8 элементов от 1 до 8)
	kol_elem_prog=0; // показатель конкретного элемента для програмирования
	oborot = 0; // переменная, которая считает количесво оборотов
	mega = 0;// переменная, которая считает количество мегациклов(один мегацикл - это полностью программа), ведется обратный отсчет, при 0 вызывается функция стоп
	prev_side = 0; // переменная, которая указывает датчик какой стороны сработал прошлый раз, нужна для того, чтобы избежать ошибок при срабатывании дважды подряд датчика с одной стороны
	prog_oborot = 0;//переменная - запрограммированное количество оборотов
	next_oborot = 1;//переменная - следующий оборот
	int sbros_i=0;
	for (sbros_i=0; sbros_i<20; sbros_i++){
		   cv_1[sbros_i]=0;
		   cv_2[sbros_i]=0;
		   cv_3[sbros_i]=0;
		   cv_4[sbros_i]=0;
		   pered_val[sbros_i]=0;
		   zad_val[sbros_i]=0;
		   stop_mass[sbros_i]=0;
	}
}


void ok_prog_fun(void){//функция нажатия кнопки ок  в режиме программирования
	if (elem_prog==1){//1 - это общее количество циклов в мегацикле
		if (kol_elem_prog>0){// только если количество оборотов в цикле больше 0
			prog_oborot=kol_elem_prog;//устанавливаем общее количество оборотов в мегацикле
			kol_elem_prog=0;//обнуляем счетчик количества элементов
		}
	}
	else if(elem_prog==2){//2- для цветника№1
		if (kol_elem_prog>0){
			a_i=0; //- переменная счетчик для проверки записанного элемента массива
			while (cv_1[a_i]>0){//как только элемент массива равен 0 - останавливаем цикл и на этот элемент массива записываем
				a_i++;
			}
			cv_1[a_i]=kol_elem_prog;
			kol_elem_prog=0;//обнуляем счетчик количества элементов
			a_i=0;// обнуляем счетчик проверки записанного элемента массива
		}
	}
	else if(elem_prog==3){//3- для цветника№2
		if (kol_elem_prog>0){
			a_i=0; //- переменная счетчик для проверки записанного элемента массива
			while (cv_2[a_i]>0){//как только элемент массива равен 0 - останавливаем цикл и на этот элемент массива записываем
				a_i++;
			}
			cv_2[a_i]=kol_elem_prog;
			kol_elem_prog=0;//обнуляем счетчик количества элементов
			a_i=0;// обнуляем счетчик проверки записанного элемента массива
		}
	}
	else if(elem_prog==4){//4- для цветника№3
		if (kol_elem_prog>0){
			a_i=0; //- переменная счетчик для проверки записанного элемента массива
			while (cv_3[a_i]>0){//как только элемент массива равен 0 - останавливаем цикл и на этот элемент массива записываем
				a_i++;
			}
			cv_3[a_i]=kol_elem_prog;
			kol_elem_prog=0;//обнуляем счетчик количества элементов
			a_i=0;// обнуляем счетчик проверки записанного элемента массива
		}
	}
	else if(elem_prog==5){//5- для цветника№4
		if (kol_elem_prog>0){
			a_i=0; //- переменная счетчик для проверки записанного элемента массива
			while (cv_4[a_i]>0){//как только элемент массива равен 0 - останавливаем цикл и на этот элемент массива записываем
				a_i++;
			}
			cv_4[a_i]=kol_elem_prog;
			kol_elem_prog=0;//обнуляем счетчик количества элементов
			a_i=0;// обнуляем счетчик проверки записанного элемента массива
		}
	}
	else if(elem_prog==6){//6- для переднего валика
		if (kol_elem_prog>0){
			a_i=0; //- переменная счетчик для проверки записанного элемента массива
			while (pered_val[a_i]>0){//как только элемент массива равен 0 - останавливаем цикл и на этот элемент массива записываем
				a_i++;
			}
			pered_val[a_i]=kol_elem_prog;
			kol_elem_prog=0;//обнуляем счетчик количества элементов
			a_i=0;// обнуляем счетчик проверки записанного элемента массива
		}
	}
	else if(elem_prog==7){//7- для заднего валика
		if (kol_elem_prog>0){
			a_i=0; //- переменная счетчик для проверки записанного элемента массива
			while (zad_val[a_i]>0){//как только элемент массива равен 0 - останавливаем цикл и на этот элемент массива записываем
				a_i++;
			}
			zad_val[a_i]=kol_elem_prog;
			kol_elem_prog=0;//обнуляем счетчик количества элементов
			a_i=0;// обнуляем счетчик проверки записанного элемента массива
		}
	}
	else if(elem_prog==8){//8- для остановки
		if (kol_elem_prog>0){
			a_i=0; //- переменная счетчик для проверки записанного элемента массива
			while (stop_mass[a_i]>0){//как только элемент массива равен 0 - останавливаем цикл и на этот элемент массива записываем
				a_i++;
			}
			stop_mass[a_i]=kol_elem_prog;
			kol_elem_prog=0;//обнуляем счетчик количества элементов
			a_i=0;// обнуляем счетчик проверки записанного элемента массива
		}
	}

}


/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_I2C1_Init();

  /* USER CODE BEGIN 2 */

	
  ssd1306_Init();
  HAL_Delay(100);
  ssd1306_Fill(White);
  ssd1306_UpdateScreen();

  HAL_Delay(100);
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString("012345678901234567",Font_7x10,Black, Inversion);
  ssd1306_UpdateScreen();	
  HAL_Delay(100);	
  ssd1306_SetCursor(1,13);
  ssd1306_WriteString("012345678901234567",Font_7x10,Black, NoInversion);
  ssd1306_UpdateScreen();	

  ssd1306_UpdateScreen();
	
	HAL_Delay(100);

  ssd1306_Fill(White);
  ssd1306_UpdateScreen();
	

  ssd1306_SetCursor(1,20);
  ssd1306_WriteString("   SETUP",Font_11x18,Black, NoInversion);
  ssd1306_UpdateScreen();	
	HAL_Delay(100);
	FSM_Init ();
  ssd1306_UpdateScreen();	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		
		switch(key_scan)
		{
			case 1:
				FSM_press_down();
			break;
			
			case 2:
				FSM_press_up();
			break;
			
			case 4:
				FSM_press_rigth();
			break;
			
			case 8:
				FSM_press_left();
			break;
			
			case 0x10:
				FSM_press_ok();
			break;			
			
			default:
				break;				
		}		
		HAL_Delay(200);
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
/*		
if (HAL_GPIO_ReadPin(GPIOB, KNOP_DOWN_VYBOR_Pin))
	{		
		
	}
 
		
	  	  if (HAL_GPIO_ReadPin(GPIOB, PEREKLUCHATEL_PROG_RABOTA_Pin)){// если нажат переключатель в положение программирование - то выполняется все что должно быть для программирования + нажата кнопка стоп
	  		  ///код для программирования тут
	  		  if(HAL_GPIO_ReadPin(GPIOB, KNOP_SBROS_Pin)){// нажатие на кнопку сброс
	  			sbros();//запуск функции нажатия на кропку сброс
	  					//тут должны также обнуляться все массивы
	  		  }
	  		  //здесь еще добавить управление энкодерами:
	  		  // 1-й энкодер - выбор элемента для изменения и записи (от 1 до 8)
	  		  // если энкодер меньше 1, то устанавливаем все равно 1
	  		  // если энкодер больше 8, то устанавливаем все равно 8
	  		  // при каждом движении энкодера обнуляется показатель kol_elem_prog
	  		  // 2-й энкодер - изменение конкретного показателя
	  		  // если энкодер меньше 0, то устанавливаем все равно 0
	  		  // если prog_oborot больше 0 и энкодер больше prog_oborot, то устанавливаем количество равное prog_oborot

	  		  //вывод на экран 8 показателей, тот который сейчас активен - подсвечивается
	  		  // отдельно вывод значения kol_elem_prog
	  		  // за название  показателя ":" и вывод значения
	  		  // там где массивы - вывод значений через зяпятую (последних трех значений и общее количество)
	  	  }

	  	  if (!HAL_GPIO_ReadPin(GPIOB, PEREKLUCHATEL_PROG_RABOTA_Pin)){//если нажат переключатель в положение основная программа - то выполняется все что должно быть для основной программы
	  		  ///код для основной программы тут
	  		  if(HAL_GPIO_ReadPin(GPIOB, DATCHIK_LEFT_Pin)){// срабатывание датчика левой стороны
	  			left_side();//запуск функции левой стороны
	  		  }
	  		  if(HAL_GPIO_ReadPin(GPIOB, DATCHIK_RIGHT_Pin)){// срабатывание датчика левой стороны
	  			right_side();//запуск функции правой стороны
	  		  }

	  		  //здесь еще добавить управление энкодерами:
	  		  // 1-й энкодер - изменение количества мегациклов
	  		  // изменяется только если prog_oborot>0
	  		  // если мешьне 0 - то устанавливаем 0

	  		  // 2-й энкодер - изменение next_oborot
	  		  // изменяется только если prog_oborot>0
	  		  // если энкодер = 0, то устанавливаем значение prog_oborot
	  		  // если значение энкодера больше prog_oborot, то устанавливаем 1

	  		  //вывод на экран:
	  		   	  //-количество мегациклов
	  		   	  //-текущий цикл
	  		   	  //-циклов в мегацикле
	  		   	  //-направление движения каретки
	  		   	  //-срабатывание функции стоп
	  		  //
	  	  }
*/
  }
	
	
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV4;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
