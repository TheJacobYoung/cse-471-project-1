#pragma once
#include "Effect.h"
#include "FXBox.h"
class CGate: public CEffect
{
protected:
	double m_threshold;
public:
	double* process() {
		double wet[2] = { 0 };
		double out[2] = { 0 };
		double* dry = dry_q.read(0);
		if (dry[0] < m_threshold) {//attenuate samples below threshold
			wet[0] = 0.1*dry[0];
			wet[1] = 0.1*dry[1];
		}
		out[0] = m_wet*wet[0] + m_dry*dry[0];
		out[1] = m_wet*wet[1] + m_dry*dry[1];
		return out;
	}
	CGate() { m_threshold = 32767.; };
	CGate(double threshold) { m_threshold = threshold; }
	~CGate();
};

