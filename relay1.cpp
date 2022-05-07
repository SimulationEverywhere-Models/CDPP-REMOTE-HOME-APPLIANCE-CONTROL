/*******************************************************************
 *
 *  DESCRIPTION: Atomic Model Relay1
 *
 *  AUTHOR: Joseph Boi-Ukeme
 *
 *  EMAIL: josephboiukeme@cmail.carleton.ca
 *
 *  DATE: 23/10/2017
 *
 *******************************************************************/

/** include files **/
#include "relay1.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
 * Function Name: Relay1
 * Description:
 ********************************************************************/
Relay1::Relay1( const string &name )
: Atomic( name )
, r1In( addInputPort( "r1In" ) )
, r1Out( addOutputPort( "r1Out" ) )
, switchingTime( 0, 0, 0, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "switching" ) ) ;

	if( time != "" )
		switchingTime = time ;
}

/*******************************************************************
 * Function Name: initFunction

 ********************************************************************/
Model &Relay1::initFunction()
{
	this-> passivate();
	return *this ;
}

/*******************************************************************
 * Function Name: externalFunction
 * Description:
 ********************************************************************/
Model &Relay1::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == r1In )
	{
		position = static_cast < int > (msg.value());
		holdIn( active, switchingTime );
	}
	return *this;
}

/*******************************************************************
 * Function Name: internalFunction
 * Description:
 ********************************************************************/
Model &Relay1::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
 * Function Name: outputFunction
 * Description:
 ********************************************************************/
Model &Relay1::outputFunction( const InternalMessage &msg )
{
	(position % 2 == 0) ? sendOutput(msg.time(), r1Out, 0) :  sendOutput(msg.time(), r1Out, 1);
	return *this ;
}
