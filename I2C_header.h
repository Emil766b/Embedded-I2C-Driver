/* 
 * File:   I2C_header.h
 * Author: alpin
 *
 * Created on 20. august 2021, 10:41
 */

#ifndef I2C_HEADER_H
#define	I2C_HEADER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
//I2C
void i2c_read (char address, char *data, char len);
void i2c_init (void);
void i2c_send (char);
void i2c_start (void);
void i2c_write (char address, char *data, char len);
//void I2C_readfunc (void);
void i2c_end (void);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_HEADER_H */

