
#include "dpxThreadBase.h"

dpxThreadBase::dpxThreadBase(void (*pFunction)())
{
	m_pFunc = pFunction;
}

dpxThreadBase::~dpxThreadBase()
{
}

void dpxThreadBase::run()
{
	m_pFunc();
}
