/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "oled.h"
#include <stdlib.h>
#include "stdio.h"
#include "time.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

uint8_t right=1,left=0,up=0,down=0,start=0;
uint16_t speed=200;

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  HAL_Delay(20);
  OLED_Init();
  uint16_t i=0;
  uint16_t score=0;
  uint16_t death=0;
  char message[50];
  char SCORE[5];
  uint16_t x_location[50]={0};
  uint16_t y_location[50]={0};
  uint8_t bodylength=4 ,body_length=4 ;
  
  uint8_t food_x=0;
  uint8_t food_y=0;
  uint8_t first_x=5;
  uint8_t first_y=13;
  uint8_t last_x=5;
  uint8_t last_y=22;
  
  x_location[0]=5;
  y_location[0]=13;
  x_location[1]=5;
  y_location[1]=16;
  x_location[2]=5;
  y_location[2]=19;
  x_location[3]=5;
  y_location[3]=22;
  
  
  food_x=(rand()%40)*3+5;
  food_y=(rand()%16)*3+13;
  while(1)
  {
    OLED_NewFrame();
    OLED_DrawImage(0,0,&OLED_GameBeginImg,OLED_COLOR_NORMAL);
    OLED_PrintASCIIString(52, 0, "Greedy", &afont24x12 , OLED_COLOR_NORMAL );
    OLED_PrintASCIIString(64, 32, "snake", &afont24x12 , OLED_COLOR_NORMAL );
    if(start==1)
    {
      break;
    }
    OLED_ShowFrame();
    
  }
  
  
  

  
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    OLED_NewFrame();
    
    for(i=0;i<bodylength;i++)
    {
      OLED_snake_body(x_location[i] ,y_location[i] ,OLED_COLOR_NORMAL);
    }
    sprintf(message,"SCORE : %d",score);
    OLED_PrintASCIIString(6, 0, message, &afont8x6 , OLED_COLOR_NORMAL );
    OLED_DrawRectangle(1, 9, 125, 53, OLED_COLOR_NORMAL);
    OLED_DrawRectangle(2, 10, 123, 51, OLED_COLOR_NORMAL);
    OLED_DrawRectangle(3, 11, 121, 49, OLED_COLOR_NORMAL);
    
    if(right==1&&start==1)
    {
      HAL_Delay(3);
      if(right==1&&start==1)
      {
        OLED_snake_food( food_x , food_y ,OLED_COLOR_NORMAL);
        
        if((first_x>=food_x)&&(first_x<=food_x+1)&&(first_y>=food_y)&&(first_y<=food_y+1))
					{
						OLED_snake_food(food_x,food_y,OLED_COLOR_REVERSED);//上一次的清白
						food_x=(rand()%40)*3+5;
            food_y=(rand()%16)*3+13;
						while((first_x>=food_x)&&(first_x<=food_x+1)&&(first_y>=food_y)&&(first_y<=food_y+1))
						{
							food_x=(rand()%40)*3+5;
              food_y=(rand()%16)*3+13;
						}
						OLED_snake_food(food_x,food_y,OLED_COLOR_NORMAL);//食物
						body_length++;
            score++;
					}
          
          
        first_x+=3;
					if(first_x==125)
          {
						first_x=5;
          }            
					last_x=x_location[bodylength-1];
					last_y=y_location[bodylength-1];
					for(i=0;i<bodylength;i++)
					{
						if(i==bodylength-1)
						{
							x_location[0]=first_x;
							y_location[0]=first_y;
						}
						else
						{
							x_location[bodylength-1-i]=x_location[bodylength-1-i-1];
							y_location[bodylength-1-i]=y_location[bodylength-1-i-1];
						}
					}
          
          HAL_Delay(speed);

					for(i=0;i<bodylength;i++)
					{
						OLED_snake_body(x_location[i] ,y_location[i] ,OLED_COLOR_NORMAL);
						if(i==body_length-1)
            {
              OLED_snake_body(last_x ,last_y ,OLED_COLOR_REVERSED);
            }
					}
          if(bodylength<body_length)
          {
            bodylength++;
            x_location[bodylength-1]=last_x;
						y_location[bodylength-1]=last_y;
          }
	
					
      }
    }
    if(left==1&&start==1)
    {
      HAL_Delay(3);
      if(left==1&&start==1)
      {
        OLED_snake_food( food_x , food_y ,OLED_COLOR_NORMAL);
        
        if((first_x>=food_x)&&(first_x<=food_x+1)&&(first_y>=food_y)&&(first_y<=food_y+1))
					{
						OLED_snake_food(food_x,food_y,OLED_COLOR_REVERSED);//上一次的清白
						food_x=(rand()%40)*3+5;
            food_y=(rand()%16)*3+13;
						while((first_x>=food_x)&&(first_x<=food_x+1)&&(first_y>=food_y)&&(first_y<=food_y+1))
						{
							food_x=(rand()%40)*3+5;
              food_y=(rand()%16)*3+13;
						}
						OLED_snake_food(food_x,food_y,OLED_COLOR_NORMAL);//食物
						body_length++;
            score++;
					}
          
          
        first_x-=3;
					if(first_x==2)
          {
						first_x=122;
          }            
					last_x=x_location[bodylength-1];
					last_y=y_location[bodylength-1];
					for(i=0;i<bodylength;i++)
					{
						if(i==bodylength-1)
						{
							x_location[0]=first_x;
							y_location[0]=first_y;
						}
						else
						{
							x_location[bodylength-1-i]=x_location[bodylength-1-i-1];
							y_location[bodylength-1-i]=y_location[bodylength-1-i-1];
						}
					}
          
          HAL_Delay(speed);

					for(i=0;i<bodylength;i++)
					{
						OLED_snake_body(x_location[i] ,y_location[i] ,OLED_COLOR_NORMAL);
						if(i==body_length-1)
            {
              OLED_snake_body(last_x ,last_y ,OLED_COLOR_REVERSED);
            }
					}
          if(bodylength<body_length)
          {
            bodylength++;
            x_location[bodylength-1]=last_x;
						y_location[bodylength-1]=last_y;
          }
	
					
      }
    }
    if(up==1&&start==1)
    {
      HAL_Delay(3);
      if(up==1&&start==1)
      {
        OLED_snake_food( food_x , food_y ,OLED_COLOR_NORMAL);
        
        if((first_x>=food_x)&&(first_x<=food_x+1)&&(first_y>=food_y)&&(first_y<=food_y+1))
					{
						OLED_snake_food(food_x,food_y,OLED_COLOR_REVERSED);//上一次的清白
						food_x=(rand()%40)*3+5;
            food_y=(rand()%16)*3+13;
						while((first_x>=food_x)&&(first_x<=food_x+1)&&(first_y>=food_y)&&(first_y<=food_y+1))
						{
							food_x=(rand()%40)*3+5;
              food_y=(rand()%16)*3+13;
						}
						OLED_snake_food(food_x,food_y,OLED_COLOR_NORMAL);//食物
						body_length++;
            score++;
					}
          
          
        first_y-=3;
					if(first_y==10)
          {
						first_y=58;
          }            
					last_x=x_location[bodylength-1];
					last_y=y_location[bodylength-1];
					for(i=0;i<bodylength;i++)
					{
						if(i==bodylength-1)
						{
							x_location[0]=first_x;
							y_location[0]=first_y;
						}
						else
						{
							x_location[bodylength-1-i]=x_location[bodylength-1-i-1];
							y_location[bodylength-1-i]=y_location[bodylength-1-i-1];
						}
					}
          
          HAL_Delay(speed);

					for(i=0;i<bodylength;i++)
					{
						OLED_snake_body(x_location[i] ,y_location[i] ,OLED_COLOR_NORMAL);
						if(i==body_length-1)
            {
              OLED_snake_body(last_x ,last_y ,OLED_COLOR_REVERSED);
            }
					}
          if(bodylength<body_length)
          {
            bodylength++;
            x_location[bodylength-1]=last_x;
						y_location[bodylength-1]=last_y;
          }
	
					
      }
    }
    if(down==1&&start==1)
    {
      HAL_Delay(3);
      if(down==1&&start==1)
      {
        OLED_snake_food( food_x , food_y ,OLED_COLOR_NORMAL);
        
        if((first_x>=food_x)&&(first_x<=food_x+1)&&(first_y>=food_y)&&(first_y<=food_y+1))
					{
						OLED_snake_food(food_x,food_y,OLED_COLOR_REVERSED);//上一次的清白
						food_x=(rand()%40)*3+5;
            food_y=(rand()%16)*3+13;
						while((first_x>=food_x)&&(first_x<=food_x+1)&&(first_y>=food_y)&&(first_y<=food_y+1))
						{
							food_x=(rand()%40)*3+5;
              food_y=(rand()%16)*3+13;
						}
						OLED_snake_food(food_x,food_y,OLED_COLOR_NORMAL);//食物
						body_length++;
            score++;
					}
          
          
        first_y+=3;
					if(first_y==61)
          {
						first_y=13;
          }            
					last_x=x_location[bodylength-1];
					last_y=y_location[bodylength-1];
					for(i=0;i<bodylength;i++)
					{
						if(i==bodylength-1)
						{
							x_location[0]=first_x;
							y_location[0]=first_y;
						}
						else
						{
							x_location[bodylength-1-i]=x_location[bodylength-1-i-1];
							y_location[bodylength-1-i]=y_location[bodylength-1-i-1];
						}
					}
          
          HAL_Delay(speed);

					for(i=0;i<bodylength;i++)
					{
						OLED_snake_body(x_location[i] ,y_location[i] ,OLED_COLOR_NORMAL);
						if(i==body_length-1)
            {
              OLED_snake_body(last_x ,last_y ,OLED_COLOR_REVERSED);
            }
					}
          if(bodylength<body_length)
          {
            bodylength++;
            x_location[bodylength-1]=last_x;
						y_location[bodylength-1]=last_y;
          }
	
					
      }
    }
    for(i=1;i<bodylength;i++)
    {
      if(first_x==x_location[i]&&first_y==y_location[i])
      {
        death++;
        break;
      }
    }
    if(death==1)
    {
      break;
    }
    OLED_ShowFrame();
    
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  OLED_NewFrame();
  OLED_DrawImage(0,0,&OLED_GameBeginImg,OLED_COLOR_NORMAL);
  OLED_PrintASCIIString(64, 0, "SCORE", &afont24x12 , OLED_COLOR_NORMAL );
  sprintf(SCORE,"%d",score);
  OLED_PrintASCIIString(88, 32, SCORE, &afont24x12 , OLED_COLOR_NORMAL );
  OLED_ShowFrame();
  HAL_Delay(5000);
  OLED_NewFrame();
  OLED_DrawImage(0,0,&OLED_GameOverImg,OLED_COLOR_NORMAL);
  OLED_ShowFrame();
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
