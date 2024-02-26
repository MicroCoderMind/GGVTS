#include <xc.h>

void delay(void)
{
    T1CON = 0X10;
    TMR1L = 0;
    TMR1H = 0;
    T1CONbits.TMR1ON = 1;
    while(PIR1bits.TMR1IF == 0);
    PIR1bits.TMR1IF = 0;
    T1CONbits.TMR1ON = 0; 
}

void spi_init()
{
    SSPCON = 0X30;
    SSPSTAT = 0X00;
    TRISBbits.TRISB0 = 0;
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC4 = 1;
    TRISCbits.TRISC5 = 0;
}

unsigned char spi_read()
{
    unsigned char result;
    while(PIR1bits.SSPIF == 0);
    result = SSPBUF;
    return result;
}
void main(void) {
    unsigned char temp_value;
    spi_init();
    while(1)
    {
        PORTBbits.RB0 = 0;
        SSPBUF = 0X55;
        temp_value = spi_read();
        PORTBbits.RB0 = 1;
        delay();    
    }
    return;
}
