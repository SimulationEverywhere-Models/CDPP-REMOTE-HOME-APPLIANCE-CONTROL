/*******************************************************************
 *
 *  DESCRIPTION: Atomic Model Gsm
 *
 *  AUTHOR: Boi-Ukeme Joseph
 *
 *  EMAIL: josephboiukeme@cmail.carleton.ca
 *
 *  DATE: 21/10/2017
 *
 *******************************************************************/

#ifndef __GSM_H
#define __GSM_H


#include "atomic.h"     // class Atomic

class Gsm : public Atomic
{
public:
	Gsm( const string &name = "Gsm" );					//Default constructor
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &callIn;
	Port &gsmOut;
	Time receivingTime;
	int received;
	//int y;
	//	typedef list<Value> ElementList ;
	//	ElementList elements ;

	//	Time timeLeft;

};	// class Gsm

// ** inline ** // 
inline
string Gsm::className() const
{
	return "Gsm" ;
}

#endif   //__Gsm_H
