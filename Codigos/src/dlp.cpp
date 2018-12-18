#include "dlp.h"


DLP::DLP()
{
    kI2CBus = 0 ;           // Default I2C bus for Lidar-Lite on Jetson TK1
    error = -1 ;
}


DLP::~DLP()
{
    closeDLP() ;
}



bool DLP::openDLP()
{
    char fileNameBuffer[20];
    //configure(CLOCK_SPEED_400_KHZ);
    sprintf(fileNameBuffer, "/dev/i2c-%d", kI2CBus);
    kI2CFileDescriptor = open(fileNameBuffer, O_RDWR);
    if (kI2CFileDescriptor < 0) {
        // Could not open the file
        error = errno ;
        return false ;
    }
    if (ioctl(kI2CFileDescriptor, I2C_SLAVE, DLPAddress) < 0) {
        // Could not open the device on the bus
        error = errno ;
        return false ;
    }
    return true ;
}


void DLP::closeDLP()
{
    if (kI2CFileDescriptor > 0) {
        close(kI2CFileDescriptor);
        // WARNING - This is not quite right, need to check for error first
        kI2CFileDescriptor = -1 ;
    }
}


// Read the given register on the Lidar-Lite
int DLP::readDLP(int readRegister)
{
    // Do not use i2c_smbus_read_byte_data here ; LidarLite V2 needs STOP between write and read
    int toReturn ;
    toReturn = i2c_smbus_write_byte(kI2CFileDescriptor, readRegister) ;
    if (toReturn < 0) {
        error = errno ;
        toReturn = -1 ;
    }
    toReturn = i2c_smbus_read_byte(kI2CFileDescriptor) ;
    if (toReturn < 0) {
        error = errno ;
        toReturn = -1 ;
    }
    return toReturn ;
}



// Write the the given value to the given register on the Lidar-Lite
int DLP::writeDLP(int writeRegister, int writeValue)
{
    int toReturn = i2c_smbus_write_byte_data(kI2CFileDescriptor, writeRegister, writeValue);
    // Wait a little bit to make sure it settles
    usleep(10000);
    if (toReturn < 0) {
        error = errno ;
        toReturn = -1 ;
    }
    return toReturn ;
}



