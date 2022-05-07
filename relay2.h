/*******************************************************************
*
*  DESCRIPTION: Atomic Model Receiver
*
*  AUTHOR: Joseph Boi-Ukeme
*
*  EMAIL:josephboiukeme@cmail.carleton.ca
*
*  DATE: 23/10/2017
*
*******************************************************************/

#ifndef __RELAY2_H
#define __RELAY2_H

//#include <list>
#include "atomic.h"     // class Atomic

class Relay2 : public Atomic
{
public:
	Relay2( const string &name = "Relay2" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &r2In;
	Port &r2Out;
	Time switchingTime;
	int position;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class Receiver

// ** inline ** //
inline
string Relay2::className() const
{
	return "Relay2" ;
}

#endif   //__RELAY2_H
