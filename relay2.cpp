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
#include "relay2.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
 * Function Name: Relay2
 * Description:
 ********************************************************************/
Relay2::Relay2( const string &name )
: Atomic( name )
, r2In( addInputPort( "r2In" ) )
, r2Out( addOutputPort( "r2Out" ) )
, switchingTime( 0, 0, 0, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "switching" ) ) ;

	if( time != "" )
		switchingTime = time ;
}

/*******************************************************************
 * Function Name: initFunction

 ********************************************************************/
Model &Relay2::initFunction()
{
	this-> passivate();
	return *this ;
}

/*******************************************************************
 * Function Name: externalFunction
 * Description:
 ********************************************************************/
Model &Relay2::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == r2In )
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
Model &Relay2::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
 * Function Name: outputFunction
 * Description:
 ********************************************************************/
Model &Relay2::outputFunction( const InternalMessage &msg )
{

	(position % 2 == 0) ? sendOutput(msg.time(), r2Out, 0) :  sendOutput(msg.time(), r2Out, 1);

	return *this ;
}
