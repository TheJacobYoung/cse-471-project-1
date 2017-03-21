#pragma once
#include "Effect.h"
class CChorus:public CEffect
{
public:
	double* process() {
		double wet[2] = { 0 };
		double out[2] = { 0 };
		double* dry = dry_q->read(0);
		int delayIdx = *m_wrloc - (1102 + (220* sin(2 * PI*0.25*(*m_wrloc)))); //20-30ms
		double* delayed = dry_q->read(delayIdx);
		wet[0] = 0.5*dry[0] + 0.5*delayed[0];
		wet[1] = 0.5*dry[1] + 0.5*delayed[1];
		out[0] = m_wet*wet[0] + m_dry*dry[0];
		out[1] = m_wet*wet[1] + m_dry*dry[1];
		return out;
	}
	CChorus();
	~CChorus();
};

