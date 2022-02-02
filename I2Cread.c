#include "mcc_generated_files/mcc.h"
#include "string.h"
#include "stdio.h"
#include "ctype.h"
#include "I2C_header.h"

char address;
char *data;
char len;

void i2c_read (char address, char *data, char len){
    //Start condition
    i2c_start();
    // Send adressen med et 1 for read
    i2c_send( (address <<1) + 1 );
    //Hvis den får et ack forsætter den
    if (SSP2CON2bits.ACKSTAT == 0) {
        //Hvis dataen den får er indenfor det den gerne vil have fortsætter for loopet
        for (int i = 0; i < len; i++) {
            // RCEN fortæller at den gerne vil have noget data
            SSP2CON2bits.RCEN = 1;
            // Den er 1 så længe at den gerne vil have data
            while (SSP2CON2bits.RCEN == 1);
            // Når den har modtaget data gemmer den det i bufferen
            data[i] = SSP2BUF;
            //Når den sidste byte er modtaget giver den et NAC
             if (i == len -1) {
                 SSP2CON2bits.ACKDT = 1;
                 SSP2CON2bits.ACKEN = 1;
                 while(SSP2CON2bits.ACKEN == 1);
            // Ellers fortsætter den med at sende data
            } else {
                SSP2CON2bits.ACKDT = 0; 
                SSP2CON2bits.ACKEN = 1;
                while(SSP2CON2bits.ACKEN == 1);
            }  
        };
    };
    //Giver et nac før stop condition
    SSP2CON2bits.ACKSTAT == 1;
    //Stop condition
    i2c_end();
};
