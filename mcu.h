/*******************************************************************
*
*  DESCRIPTION: Atomic Model mcu
*
*  AUTHOR: Joseph Boi-Ukeme
*
*  EMAIL: josephboiukeme@cmail.carleton.ca
*
*  DATE: 21/10/2017
*
*******************************************************************/

#ifndef __MCU_H
#define __MCU_H

#include "atomic.h"     // class Atomic


/** forward declarations **/
//class Distribution ;

class mcu : public Atomic
{
public:
	mcu( const string &name = "mcu" );					//Default constructor
		virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &mcuIn;
	Port &m1Out;
	Port &m2Out;
	Port &m3Out;
	Port &m4Out;
	Time controlTime;
	
	int controlled;
	

};	// class mcu

// ** inline ** // 
inline
string mcu::className() const
{
	return "mcu" ;
}

#endif   //__MCU_H
