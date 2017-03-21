#pragma once
#include "Effect.h"
class InstrumentFactory
{
protected:
	vector<CEffect*> m_fx;
public:
	InstrumentFactory();
	~InstrumentFactory();
};

