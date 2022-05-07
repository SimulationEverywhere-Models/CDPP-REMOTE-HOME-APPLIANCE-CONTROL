/*******************************************************************
 *
 *  DESCRIPTION: Atomic Model mcu
 *
 *  AUTHOR: Joseph Boi-Ukeme
 *
 *  EMAIL: josephboiukeme@cmail.carleton.ca
 *
 *  DATE: 21/10/2017
 *
 *******************************************************************/

/** include files **/
#include "mcu.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
 * Function Name: mcu
 * Description:
 ********************************************************************/
mcu::mcu( const string &name )
: Atomic( name )
, mcuIn( addInputPort( "mcuIn" ) )
, m1Out( addOutputPort( "m1Out" ) )
, m2Out( addOutputPort( "m2Out" ) )
, m3Out( addOutputPort( "m3Out" ) )
, m4Out( addOutputPort( "m4Out" ) )
, controlTime( 0, 0, 5, 0 )

{	controlled = 0;
string time( MainSimulator::Instance().getParameter( description(), "control" ) ) ;

if( time != "" )
	controlTime = time ;
}

/*******************************************************************
 * Function Name: initFunction
 ********************************************************************/
Model &mcu::initFunction()
{
	this-> passivate();
	return *this ;
}

/*******************************************************************
 * Function Name: externalFunction
 * Description:
 ********************************************************************/
Model &mcu::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == mcuIn  && this->state() == passive)
	{	
		controlled = static_cast < int > (msg.value());
		holdIn(active, controlTime );
	}
	else if( msg.port() == mcuIn  && this->state() == active)
	{	



	}

	return *this;
}

/*******************************************************************
 * Function Name: internalFunction
 * Description:
 ********************************************************************/
Model &mcu::internalFunction( const InternalMessage & )
{	
	passivate();
	return *this ;
}

/*******************************************************************
 * Function Name: outputFunction
 * Description:
 ********************************************************************/
Model &mcu::outputFunction( const InternalMessage &msg )
{
	if (controlled <= 6)
	{
	sendOutput( msg.time(), m4Out, controlled );
	}

	if ((controlled == 1) || (controlled == 2))
	{
		sendOutput( msg.time(), m1Out, controlled );

	}
	if ((controlled == 3) || (controlled == 4))
	{
		sendOutput( msg.time(), m2Out, controlled );

	}
	if ((controlled == 5) || (controlled == 6))
	{
		sendOutput( msg.time(), m3Out, controlled );

	}


	return *this ;
}
