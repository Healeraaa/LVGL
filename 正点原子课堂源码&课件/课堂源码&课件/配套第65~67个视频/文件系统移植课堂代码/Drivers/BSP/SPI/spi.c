/**
 ****************************************************************************************************
 * @file        spi.c
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2022-4-20
 * @brief       SPI ��������
 * @license     Copyright (c) 2020-2032, ������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ʵ��ƽ̨:����ԭ�� ������ F429������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
 *
 * �޸�˵��
 * V1.0 20220420
 * ��һ�η���
 *
 ****************************************************************************************************
 */

#include "./BSP/SPI/spi.h"

SPI_HandleTypeDef g_spi5_handle;  /* SPI��� */

/**
 * @brief       SPI�ڳ�ʼ��SPI
 * @note       ģ��ĳ�ʼ�����룬���ó�����ģʽ
 * @retval      �������Ƕ�SPI5�ĳ�ʼ��
 */
void spi5_init(void)
{
    g_spi5_handle.Instance = SPI5_SPI;                               /* SP5 */
    g_spi5_handle.Init.Mode = SPI_MODE_MASTER;                       /* ����SPI����ģʽ������Ϊ��ģʽ */
    g_spi5_handle.Init.Direction = SPI_DIRECTION_2LINES;             /* ����SPI�������˫�������ģʽ:SPI����Ϊ˫��ģʽ */
    g_spi5_handle.Init.DataSize = SPI_DATASIZE_8BIT;                 /* ����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ */
    g_spi5_handle.Init.CLKPolarity = SPI_POLARITY_HIGH;              /* ����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ */
    g_spi5_handle.Init.CLKPhase = SPI_PHASE_2EDGE;                   /* ����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ����� */
    g_spi5_handle.Init.NSS = SPI_NSS_SOFT;                           /* NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ���� */
    g_spi5_handle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;/* ���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ256 */
    g_spi5_handle.Init.FirstBit = SPI_FIRSTBIT_MSB;                  /* ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ */
    g_spi5_handle.Init.TIMode = SPI_TIMODE_DISABLE;                  /* �ر�TIģʽ */
    g_spi5_handle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;  /* �ر�Ӳ��CRCУ�� */
    g_spi5_handle.Init.CRCPolynomial = 7;                            /* CRCֵ����Ķ���ʽ */
    HAL_SPI_Init(&g_spi5_handle);                                    /* ��ʼ�� */
    
    __HAL_SPI_ENABLE(&g_spi5_handle);                                /* ʹ��SPI5 */

    spi5_read_write_byte(0Xff);                                      /* �������� */
}

/**
 * @brief       SPI5�ײ�������ʱ��ʹ�ܣ���������
 * @note        �˺����ᱻHAL_SPI_Init()����
 * @param       hspi:SPI���
 * @retval      ��
 */
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
    GPIO_InitTypeDef gpio_init_struct;

    SPI5_SCK_GPIO_CLK_ENABLE();                           /* SCK��ʱ��ʹ�� */
    SPI5_MISO_GPIO_CLK_ENABLE();                          /* MISO��ʱ��ʹ�� */
    SPI5_MOSI_GPIO_CLK_ENABLE();                          /* MISO��ʱ��ʹ�� */
    SPI5_SPI_CLK_ENABLE();                                /* ʹ��SPI5ʱ�� */
    
    /* PF7,8,9 */
    gpio_init_struct.Pin = SPI5_SCK_GPIO_PIN | SPI5_MISO_GPIO_PIN | SPI5_MOSI_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_AF_PP;              /* ����������� */
    gpio_init_struct.Pull = GPIO_PULLUP;                  /* ���� */
    gpio_init_struct.Speed = GPIO_SPEED_FAST;             /* ���� */
    gpio_init_struct.Alternate = GPIO_AF5_SPI5;           /* ����ΪSPI5 */
    HAL_GPIO_Init(SPI5_SCK_GPIO_PORT, &gpio_init_struct);
}

/**
 * @brief       SPI�ٶ����ú���
 * @param       SPI�ٶ�=fAPB1/��Ƶϵ��
 * @param       SPI_BaudRate_Prescaler:SPI_BAUDRATEPRESCALER_2~SPI_BAUDRATEPRESCALER_2 256
 * @param      fAPB1ʱ��һ��Ϊ45Mhz��
 * @retval     ��
 */
void spi5_set_speed(uint8_t SPI_BaudRatePrescaler)
{
    assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler));  /* �ж���Ч�� */
    __HAL_SPI_DISABLE(&g_spi5_handle);                               /* �ر�SPI */
    g_spi5_handle.Instance->CR1 &= 0XFFC7;                           /* λ3-5���㣬�������ò����� */
    g_spi5_handle.Instance->CR1 |= SPI_BaudRatePrescaler;            /* ����SPI�ٶ� */
    __HAL_SPI_ENABLE(&g_spi5_handle);                                /* ʹ��SPI */
    
}

/**
 * @brief       SPI5 ��дһ���ֽ�
 * @param       TxData:Ҫд����ֽ�
 * @param       ����ֵ:��ȡ�����ֽ�
 * @retval     ��
 */
uint8_t spi5_read_write_byte(uint8_t TxData)
{
    uint8_t Rxdata;

    HAL_SPI_TransmitReceive(&g_spi5_handle, &TxData, &Rxdata, 1, 1000);

    return Rxdata;                      /* �����յ������� */
}
