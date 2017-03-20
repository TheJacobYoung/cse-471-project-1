#pragma once
#include "Effect.h"
class CFlange :
	public CEffect
{
public:
	double* process() {
		double wet[2] = { 0 };
		double out[2] = { 0 };
		double* dry = m_box.read_raw_frame();
		int loc = m_box.getWrloc();
		int delayIdx = loc - (330+ (110*sin(2 * PI*0.25*loc))); //5-10 ms
		double* delayed = m_box.read_raw_frame(delayIdx);
		wet[0] = 0.5*dry[0] + 0.5*delayed[0];
		wet[1] = 0.5*dry[1] + 0.5*delayed[1];
		out[0] = m_wet*wet[0]+m_dry*dry[0];
		out[1] = m_wet*wet[1]+m_dry*dry[1];
		return out;
	}
	CFlange() { setWeight(1); };
	CFlange(int wetWeight) { setWeight(wetWeight); }
	virtual ~CFlange();
};

