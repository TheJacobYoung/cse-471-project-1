#pragma once
#include "Effect.h"
class CChorus:public CEffect
{
public:
	double* process() {
		double wet[2] = { 0 };
		double out[2] = { 0 };
		double* dry = m_box.read_raw_frame();
		int loc = m_box.getWrloc();
		int delayIdx = loc - (1102 + (220* sin(2 * PI*0.25*loc))); //20-30ms
		double* delayed = m_box.read_raw_frame(delayIdx);
		wet[0] = 0.5*dry[0] + 0.5*delayed[0];
		wet[1] = 0.5*dry[1] + 0.5*delayed[1];
		out[0] = m_wet*wet[0] + m_dry*dry[0];
		out[1] = m_wet*wet[1] + m_dry*dry[1];
		return out;
	}
	CChorus();
	~CChorus();
};

