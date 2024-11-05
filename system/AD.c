#include "stm32f10x.h"                  // Device header



void AD_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);//开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//调整gpio模式，减少干扰
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//输入口
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_55Cycles5);//配置输入通道，选择模式
	
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;//adc模式(单次)
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//数据对齐
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;//扫描模式是否开启
	ADC_InitStructure.ADC_NbrOfChannel = 1;     //通道数量
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//外部触发（无）
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_Init(ADC1,&ADC_InitStructure);
	
	ADC_Cmd(ADC1,ENABLE);//开启ADC电源
	//复位校准
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);//等到复位校准完成
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1) == SET);
}
uint16_t AD_GetValue(void)
{
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);//开始转换
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC) == RESET);  //等待转换完成
	return ADC_GetConversionValue(ADC1);//返回转换值
	
}
