/*******************************************************************
 *
 *  DESCRIPTION: Atomic Model Dtmf
 *
 *  AUTHOR: Boi-Ukeme Joseph
 *
 *  EMAIL: josephboiukeme@cmail.carleton.ca
 *
 *  DATE: 21/10/2017
 *
 *******************************************************************/

/** include files **/
#include "dtmf.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
 * Function Name: Dtmf
 * Description:
 ********************************************************************/
Dtmf::Dtmf( const string &name )
: Atomic( name )
, dIn( addInputPort( "dIn" ) )
, dOut( addOutputPort( "dOut" ) )
, decodingTime( 0, 0, 1, 0 )

{
	string time( MainSimulator::Instance().getParameter( description(), "decoding" ) ) ;

	if( time != "" )
		decodingTime = time ;//
}

/*******************************************************************
 * Function Name: initFunction
 ********************************************************************/
Model &Dtmf::initFunction()
{
	this-> passivate();
	decoded= 0;
	return *this ;
}

/*******************************************************************
 * Function Name: externalFunction
 * Description:
 ********************************************************************/
Model &Dtmf::externalFunction( const ExternalMessage &msg )
{
	if( (msg.port() == dIn)&& this->state() == passive )

	{	
		decoded = static_cast < int > (msg.value());

		holdIn(active, decodingTime );

	}

	else if( msg.port() == dIn  && this->state() == active)
	{	





	}

	return *this;
}

/*******************************************************************
 * Function Name: internalFunction
 * Description:
 ********************************************************************/
Model &Dtmf::internalFunction( const InternalMessage & )
{	
	passivate();
	return *this ;

}

/*******************************************************************
 * Function Name: outputFunction
 * Description:
 ********************************************************************/
Model &Dtmf::outputFunction( const InternalMessage &msg )
{
	sendOutput(msg.time(), dOut, decoded/10) ;





	return *this ;

}
