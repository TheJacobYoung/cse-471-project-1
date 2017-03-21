#pragma once
#include "Effect.h"
class CCompressor :public CEffect
{
private:
	double m_threshold;
public:
	double* process() {
		double wet[2] = { 0 };
		double* out = (double*)malloc(sizeof(double)*2);
		double* dry = dry_q->read(0);
		if (dry[0] > m_threshold) {//attenuate samples above threshold
			wet[0] = m_threshold+0.1*dry[0];
			wet[1] = m_threshold+0.1*dry[1];
		}
		out[0] = m_wet*wet[0] + m_dry*dry[0];
		out[1] = m_wet*wet[1] + m_dry*dry[1];
		return out;
	}
	CCompressor(){m_threshold = 32767;};
	CCompressor(double threshold) {
		m_threshold = threshold;
	}
	~CCompressor() {};
};

