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

#ifndef __RELAY3_H
#define __RELAY3_H

//#include <list>
#include "atomic.h"     // class Atomic

class Relay3 : public Atomic
{
public:
	Relay3( const string &name = "Relay3" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &r3In;
	Port &r3Out;
	Time switchingTime;
	int position;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class Receiver

// ** inline ** //
inline
string Relay3::className() const
{
	return "Relay3" ;
}

#endif   //__RELAY3_H
