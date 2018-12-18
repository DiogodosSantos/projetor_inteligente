// testando i2c

#ifndef DLP_H
#define DLP_H

#include <cstddef>
#include <linux/i2c-dev.h>
//#include <i2c/smbus.h>
#include <sys/ioctl.h>
#include <cstdlib>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>



#define DLPAddress	0x1a
#define GPIO_func	0x44
#define PWMsetup	0x41
#define PWMenable	0x40
#define ProgramMode	0x30
#define InputSelection	0x00
#define InternalPattern	0x0a


class DLP
{
public:
    unsigned char kI2CBus ;         // I2C bus of the Lidar-Lite
    int kI2CFileDescriptor ;        // File Descriptor to the Lidar-Lite
    int error ;
    DLP();
    ~DLP() ;
    bool openDLP() ;                   // Open the I2C bus to the Lidar-Lite
    void closeDLP();                   // Close the I2C bus to the Lidar-Lite
    int writeDLP(int writeRegister,int writeValue) ;
    int readDLP(int readRegister) ;
};

#endif
