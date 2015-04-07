/*
  FILE:           twi.h
  DEVELOPED BY:   Kang'alia Isaac Nyamu
                  The University of Nairobi
                  School of Computng and Informatics
                  P15/1325/2011
  PURPOSE:        This file is a utility that will be used by the Wire library
  LICENCE:        GPL v3 (http://www.gnu.org/licenses/gpl.html)
  PROJECT:        IV YR PROJECT: The Automated Greenhouse (Temperature and Humidity Control)
*/

#ifndef twi_h
#define twi_h

  #include <inttypes.h>

  //#define ATMEGA8

  #ifndef TWI_FREQ
  #define TWI_FREQ 100000L
  #endif

  #ifndef TWI_BUFFER_LENGTH
  #define TWI_BUFFER_LENGTH 32
  #endif

  #define TWI_READY 0
  #define TWI_MRX   1
  #define TWI_MTX   2
  #define TWI_SRX   3
  #define TWI_STX   4
  
  void twi_init(void);
  void twi_setAddress(uint8_t);
  uint8_t twi_readFrom(uint8_t, uint8_t*, uint8_t, uint8_t);
  uint8_t twi_writeTo(uint8_t, uint8_t*, uint8_t, uint8_t, uint8_t);
  uint8_t twi_transmit(const uint8_t*, uint8_t);
  void twi_attachSlaveRxEvent( void (*)(uint8_t*, int) );
  void twi_attachSlaveTxEvent( void (*)(void) );
  void twi_reply(uint8_t);
  void twi_stop(void);
  void twi_releaseBus(void);

#endif

