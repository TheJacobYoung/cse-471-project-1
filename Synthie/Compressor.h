#pragma once
#include "Effect.h"
class CCompressor :public CEffect
{
private:
	double m_threshold;
public:
	double* process() {
		double wet[2] = { 0 };
		double out[2] = { 0 };
		double* dry = m_box.read_raw_frame();
		if (dry[0] > m_threshold) {//attenuate samples above threshold
			wet[0] = m_threshold+0.1*dry[0];
			wet[1] = m_threshold+0.1*dry[1];
		}
		out[0] = m_wet*wet[0] + m_dry*dry[0];
		out[1] = m_wet*wet[1] + m_dry*dry[1];
		return out;
	}
	CCompressor();
	CCompressor(double threshold) {
		m_threshold = threshold;
	}
	~CCompressor();
};

