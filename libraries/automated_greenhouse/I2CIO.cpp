/*
  FILE:           I2CIO.cpp
  DEVELOPED BY:   Kang'alia Isaac Nyamu
                  The University of Nairobi
                  School of Computng and Informatics
                  P15/1325/2011
  PURPOSE:        For control of the I2C serial adapter for the 1602 LCD
  LICENCE:        GPL v3 (http://www.gnu.org/licenses/gpl.html)
  PROJECT:        IV YR PROJECT: The Automated Greenhouse (Temperature and Humidity Control)
*/
#if (ARDUINO <  100)
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#include <inttypes.h>

#include <Wire.h>
// #include <../Wire/Wire.h>
#include "I2CIO.h"

// CLASS VARIABLES
// ---------------------------------------------------------------------------


// CONSTRUCTOR
// ---------------------------------------------------------------------------
I2CIO::I2CIO ( )
{
   _i2cAddr     = 0x0;
   _dirMask     = 0xFF;    // mark all as INPUTs
   _shadow      = 0x0;     // no values set
   _initialised = false;
}

// PUBLIC METHODS
// ---------------------------------------------------------------------------

//
// begin
int I2CIO::begin (  uint8_t i2cAddr )
{
   _i2cAddr = i2cAddr;
   
   Wire.begin ( );
      
   _initialised = Wire.requestFrom ( _i2cAddr, (uint8_t)1 );

#if (ARDUINO <  100)
   _shadow = Wire.receive ();
#else
   _shadow = Wire.read (); // Remove the byte read don't need it.
#endif
   
   return ( _initialised );
}

//
// pinMode
void I2CIO::pinMode ( uint8_t pin, uint8_t dir )
{
   if ( _initialised )
   {
      if ( OUTPUT == dir )
      {
         _dirMask &= ~( 1 << pin );
      }
      else 
      {
         _dirMask |= ( 1 << pin );
      }
   }
}

//
// portMode
void I2CIO::portMode ( uint8_t dir )
{
   
   if ( _initialised )
   {
      if ( dir == INPUT )
      {
         _dirMask = 0xFF;
      }
      else
      {
         _dirMask = 0x00;
      }
   }
}

//
// read
uint8_t I2CIO::read ( void )
{
   uint8_t retVal = 0;
   
   if ( _initialised )
   {
      Wire.requestFrom ( _i2cAddr, (uint8_t)1 );
#if (ARDUINO <  100)
      retVal = ( _dirMask & Wire.receive ( ) );
#else
      retVal = ( _dirMask & Wire.read ( ) );
#endif      
      
   }
   return ( retVal );
}

//
// write
int I2CIO::write ( uint8_t value )
{
   int status = 0;
   
   if ( _initialised )
   {
      // Only write HIGH the values of the ports that have been initialised as
      // outputs updating the output shadow of the device
      _shadow = ( value & ~(_dirMask) );
   
      Wire.beginTransmission ( _i2cAddr );
#if (ARDUINO <  100)
      Wire.send ( _shadow );
#else
      Wire.write ( _shadow );
#endif  
      status = Wire.endTransmission ();
   }
   return ( (status == 0) );
}

//
// digitalRead
uint8_t I2CIO::digitalRead ( uint8_t pin )
{
   uint8_t pinVal = 0;
   
   // Check if initialised and that the pin is within range of the device
   // -------------------------------------------------------------------
   if ( ( _initialised ) && ( pin <= 7 ) )
   {
      // Remove the values which are not inputs and get the value of the pin
      pinVal = this->read() & _dirMask;
      pinVal = ( pinVal >> pin ) & 0x01; // Get the pin value
   }
   return (pinVal);
}

//
// digitalWrite
int I2CIO::digitalWrite ( uint8_t pin, uint8_t level )
{
   uint8_t writeVal;
   int status = 0;
   
   // Check if initialised and that the pin is within range of the device
   // -------------------------------------------------------------------
   if ( ( _initialised ) && ( pin <= 7 ) )
   {
      // Only write to HIGH the port if the port has been configured as
      // an OUTPUT pin. Add the new state of the pin to the shadow
      writeVal = ( 1 << pin ) & ~_dirMask;
      if ( level == HIGH )
      {
         _shadow |= writeVal;
                                                      
      }
      else 
      {
         _shadow &= ~writeVal;
      }
      status = this->write ( _shadow );
   }
   return ( status );
}

//
// PRIVATE METHODS
// ---------------------------------------------------------------------------
