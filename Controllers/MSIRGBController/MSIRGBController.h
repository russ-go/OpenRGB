/*-----------------------------------------*\
|  MSIRGBController.h                       |
|                                           |
|  Definitions and types for MSI-RGB        |
|  lighting controller                      |
|                                           |
|  Logic adapted from:                      |
|     https://github.com/nagisa/msi-rgb     |
|                                           |
|  Adam Honse (CalcProgrammer1) 2/11/2020   |
\*-----------------------------------------*/

#include <string>

#pragma once

#define MSI_SIO_LOGDEV_RGB      0x12

enum
{
    MSI_SIO_RGB_REG_ENABLE      = 0xE0,
    MSI_SIO_RGB_REG_RED_1_0     = 0xF0,
    MSI_SIO_RGB_REG_RED_3_2     = 0xF1,
    MSI_SIO_RGB_REG_RED_5_4     = 0xF2,
    MSI_SIO_RGB_REG_RED_7_6     = 0xF3,
    MSI_SIO_RGB_REG_GREEN_1_0   = 0xF4,
    MSI_SIO_RGB_REG_GREEN_3_2   = 0xF5,
    MSI_SIO_RGB_REG_GREEN_5_4   = 0xF6,
    MSI_SIO_RGB_REG_GREEN_7_6   = 0xF7,
    MSI_SIO_RGB_REG_BLUE_1_0    = 0xF8,
    MSI_SIO_RGB_REG_BLUE_3_2    = 0xF9,
    MSI_SIO_RGB_REG_BLUE_5_4    = 0xFA,
    MSI_SIO_RGB_REG_BLUE_7_6    = 0xFB,
};

#define MSI_SIO_RGB_ENABLE_MASK 0xE0

class MSIRGBController
{
public:
    MSIRGBController(int sioaddr);
    ~MSIRGBController();

    std::string     GetDeviceName();
    std::string     GetDeviceLocation();

    unsigned int    GetMode();
    void            SetMode(unsigned char new_mode, unsigned char new_speed);

    void            SetColor(unsigned char red, unsigned char green, unsigned char blue);
private:
    int     msi_sioaddr;
};