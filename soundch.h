/*******************************************************************
*  DESCRIPTION: Atomic Model soundch
*
*  AUTHOR: Joseph Boi-Ukeme 
*
*  EMAIL: josephboiukeme@cmail.carleton.ca
*
*  DATE: 21/10/2017
*
*******************************************************************/

#ifndef __SOUNDCH_H
#define __SOUNDCH_H

//#include <list>
#include "atomic.h"     // class Atomic

class Soundch : public Atomic
{
public:
	Soundch( const string &name = "Soundch" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &scIn;
	Port &scOut;
	Time recordingTime;
	int record;
	int heat_on, heat_off, fridge_on, fridge_off, lighting_on, lighting_off;
	//std::string echo;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class Soundch

// ** inline ** // 
inline
string Soundch::className() const
{
	return "Soundch" ;
}

#endif   //__SOUNDCH_H
