/*******************************************************************
 *
 *  DESCRIPTION: Atomic Model gsm
 *
 *  AUTHOR: Boi-Ukeme Joseph
 *
 *  EMAIL: josephboiukeme@cmail.carleton.ca
 *
 *  DATE: 21/10/2017
 *
 *******************************************************************/

/** include files **/
#include "gsm.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
 * Function Name: gsm
 * Description:
 ********************************************************************/
Gsm::Gsm( const string &name )
: Atomic( name )
, callIn( addInputPort( "callIn" ) )
, gsmOut( addOutputPort( "gsmOut" ) )
, receivingTime( 0, 0, 2, 0 )

{
	string time( MainSimulator::Instance().getParameter( description(), "receiving" ) ) ;

	if( time != "" )
		receivingTime = time ;
}

/*******************************************************************
 * Function Name: initFunction
 * Description: Resetea la lista
 * Precondition: El tiempo del proximo evento interno es Infinito
 ********************************************************************/
Model &Gsm::initFunction()
{
	this-> passivate();
	received= 0;
	return *this ;
}

/*******************************************************************
 * Function Name: externalFunction
 * Description:
 ********************************************************************/
Model &Gsm::externalFunction( const ExternalMessage &msg )
{
	if( (msg.port() == callIn) && (this->state() == passive))
	{
		int array[] = {10,20,30,40,50,60};
		for(int i = 0; i<6; i++)
		{
			received = static_cast < int > (msg.value());

			if (received == array [i])

				holdIn(active, receivingTime );
		}
	}
	else if( (msg.port() == callIn)  && (this->state() == active))
	{	

	}
	return *this;
}

/*******************************************************************
 * Function Name: internalFunction
 * Description:
 ********************************************************************/
Model &Gsm::internalFunction( const InternalMessage & )
{	
	passivate();
	return *this ;

}

/*******************************************************************
 * Function Name: outputFunction
 * Description:
 ********************************************************************/
Model &Gsm::outputFunction( const InternalMessage &msg )
{
	sendOutput(msg.time(), gsmOut, received) ;


	return *this ;

}
