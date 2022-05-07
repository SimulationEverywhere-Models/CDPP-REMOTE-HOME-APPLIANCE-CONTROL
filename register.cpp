/*******************************************************************
 *
 *  DESCRIPTION: Simulator::registerNewAtomics()
 *
 *  AUTHOR: Joseph Boi-Ukeme
 *
 *  STUDENT#: 101053347
 *
 *  EMAIL: josephboiukeme@cmail.carleton.ca
 *
 *  DATE: 23/10/2017
 *
 *******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "gsm.h"        // class gsm
#include "mcu.h"        // class mcu
#include "dtmf.h"        // class Dtmf
#include "soundch.h"        // class Soundch
#include "relay1.h"        // class relay1
#include "relay2.h"        // class relay2
#include "relay3.h"        // class relay3


void MainSimulator::registerNewAtomics()
{

	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Dtmf>(), "Dtmf" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Soundch>(), "Soundch" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<mcu>(), "mcu" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Gsm>(), "Gsm" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Relay1>(), "Relay1" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Relay2>(), "Relay2" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Relay3>(), "Relay3" ) ;

}

