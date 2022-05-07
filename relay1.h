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

#ifndef __RELAY1_H
#define __RELAY1_H

//#include <list>
#include "atomic.h"     // class Atomic

class Relay1 : public Atomic
{
public:
	Relay1( const string &name = "Relay1" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &r1In;
	Port &r1Out;
	Time switchingTime;
	int position;
	//	typedef list<Value> ElementList ;
	//	ElementList elements ;

	//	Time timeLeft;

};	// class Receiver

// ** inline ** //
inline
string Relay1::className() const
{
	return "Relay1" ;
}

#endif   //__RELAY1_H
