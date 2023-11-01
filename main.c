/* PRIMERA CLASE_SEGUNDO PROGRAMA
   ------------------------------
   Manejo de Timers
*/

// llamado de librerías y archivos de cabecera
#include <p33ep256mu806.h>
#define  FCY     70000000UL
#include <libpic30.h>
#include "config.h"

// configuración de fusibles
_FWDT(FWDTEN_OFF);                              // perro guardian desactivado
_FOSCSEL(FNOSC_FRC & IESO_OFF);                 // Select Internal FRC at POR
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT); // Enable Clock Switching, Configure POSC in XT mode
_FICD(ICS_PGD1 & JTAGEN_OFF);                   // pines de grabacion en PGED1, PGEC1

// declaración de macros
#define T            0.001
#define Reset()      {__asm__ volatile ("Reset");}

// declaración de funciones e interrupciones
void __attribute__((interrupt, no_auto_psv))  _T1Interrupt(void);
void __attribute__((interrupt, no_auto_psv))  _T3Interrupt(void);

// declaración de variables


// desarrollo de funciones auxiliares
// ----------------------------------
void __attribute__((interrupt, no_auto_psv))  _T1Interrupt(void)
{ // esto ocurre cada 1mseg
  IFS0bits.T1IF = 0;    // borra el flag del timer1
  if (_RB0==1) _LATB1=1;
   else _LATB1=0;
}

void __attribute__((interrupt, no_auto_psv))  _T3Interrupt(void)
{ // esto ocurre cada 2seg
  IFS0bits.T3IF = 0;    // borra el flag del timer3
  _LATE0=_LATE0^1;      // bascule led B1
}

// desarrollo de la función principal
// ----------------------------------
int main (void)
{
  system_clock();
  ANSELB=0x0000;        // PORTB digital
  ANSELD=0x0000;        // PORTD digital
  ANSELE=0x0000;        // PORTE digital
  ANSELG=0x0000;        // PORTG digital
  _TRISB0=1;
  _TRISB1=0;
  _TRISE0=0;
  
  configIOMap();
  configT1();
  configT2();
  configT3();

  
  IEC0bits.T1IE=1;
  IEC0bits.T3IE=1;

  while (1)
  {
  }
}
