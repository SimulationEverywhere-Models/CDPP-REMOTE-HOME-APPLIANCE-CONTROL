/*******************************************************************
 *
 *  DESCRIPTION: Atomic Model soundch
 *
 *  AUTHOR: Joseph Boi-Ukeme
 *
 *  EMAIL: josephboiukeme@cmail.carleton.ca
 *
 *  DATE: 21/10/2017
 *
 *******************************************************************/

/** include files **/
#include "soundch.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
 * Function Name: soundch
 * Description:
 ********************************************************************/
Soundch::Soundch( const string &name )
: Atomic( name )
, scIn( addInputPort( "scIn" ) )
, scOut( addOutputPort( "scOut" ) )
, recordingTime( 0, 0, 10, 0 )

{	record = 0;
string time( MainSimulator::Instance().getParameter( description(), "recording" ) ) ;

if( time != "" )
	recordingTime = time ;
}

/*******************************************************************
 * Function Name: initFunction
 ********************************************************************/
Model &Soundch::initFunction()
{
	this-> passivate();
	return *this ;
}

/*******************************************************************
 * Function Name: externalFunction
 * Description:
 ********************************************************************/
Model &Soundch::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == scIn  && this->state() == passive)
	{	
		record  = static_cast < int > (msg.value());
		if(record == 1){heat_on = record;}
		if(record == 2){heat_off = record;}
		if(record == 3){fridge_on = record;}
		if(record == 4){fridge_off = record;}
		if(record == 5){lighting_on = record;}
		if(record == 6){lighting_off = record;}
		holdIn(active, recordingTime );
	}
	else if( msg.port() == scIn  && this->state() == active)
	{	



	}

	return *this;
}

/*******************************************************************
 * Function Name: internalFunction
 * Description:
 ********************************************************************/
Model &Soundch::internalFunction( const InternalMessage & )
{	
	passivate();
	return *this ;
}

/*******************************************************************
 * Function Name: outputFunction
 * Description:
 ********************************************************************/
Model &Soundch::outputFunction( const InternalMessage &msg )
{	if ((record == 1))
{
	sendOutput( msg.time(), scOut, heat_on );
}
else if ((record == 2))
{
	sendOutput( msg.time(), scOut, heat_off );
}
else if ((record == 3))
{
	sendOutput( msg.time(), scOut, fridge_on );
}
else if ((record == 4))
{
	sendOutput( msg.time(), scOut, fridge_off );
}
else if ((record == 5))
{
	sendOutput( msg.time(), scOut, lighting_on );
}
else if ((record == 6))
{
	sendOutput( msg.time(), scOut, lighting_off );
}





return *this ;
}
