/*******************************************************************
 *
 **
 *
 *  DESCRIPTION: Atomic Model dtmf
 *
 *  AUTHOR: Boi-Ukeme Joseph
 *
 *  EMAIL: josephboiukeme@cmail.carleton.ca
 *
 *  DATE: 21/10/2017
 *
 *******************************************************************/

#ifndef __DTMF_H
#define __DTMF_H

#include "atomic.h"

class Dtmf : public Atomic
{
public:
	Dtmf( const string &name = "Dtmf" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &dIn;
	const Port &dOut;
	Time decodingTime;
	int decoded;


};
inline
string Dtmf::className() const
{
	return "Dtmf" ;
}

#endif   //__DTMF_H
