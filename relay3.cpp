/*******************************************************************
 *
 *  DESCRIPTION: Atomic Model Relay3
 *
 *  AUTHOR: Joseph Boi-Ukeme
 *
 *  EMAIL: josephboiukeme@cmail.carleton.ca
 *
 *  DATE: 23/10/2017
 *
 *******************************************************************/

/** include files **/
#include "relay3.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
 * Function Name: Relay3
 * Description:
 ********************************************************************/
Relay3::Relay3( const string &name )
: Atomic( name )
, r3In( addInputPort( "r3In" ) )
, r3Out( addOutputPort( "r3Out" ) )
, switchingTime( 0, 0, 0, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "switching" ) ) ;

	if( time != "" )
		switchingTime = time ;
}

/*******************************************************************
 * Function Name: initFunction

 ********************************************************************/
Model &Relay3::initFunction()
{
	this-> passivate();
	return *this ;
}

/*******************************************************************
 * Function Name: externalFunction
 * Description:
 ********************************************************************/
Model &Relay3::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == r3In )
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
Model &Relay3::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
 * Function Name: outputFunction
 * Description:
 ********************************************************************/
Model &Relay3::outputFunction( const InternalMessage &msg )
{
	(position % 2 == 0) ? sendOutput(msg.time(), r3Out, 0) :  sendOutput(msg.time(), r3Out, 1);
	return *this ;
}
