#include "IFS_US1881.h"
namespace IcarusLib{

IFS_US1881::IFS_US1881(unsigned magnets) :
	magnets(magnets)
{
}

void IFS_US1881::setPort(const unsigned &value){
	pin = value;
}

void IFS_US1881::getChangeState(){
}

unsigned IFS_US1881::getRPM(){
}

void IFS_US1881::calculateRPM(){

}

}