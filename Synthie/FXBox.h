#pragma once
#ifndef CFXBOX_H
#define CFBOX_H
#include <algorithm>
#include "Effect.h"
using std::swap;
class CFXBox
{
private:
	CircularBuffer m_rawDelay;
	CircularBuffer m_processedDelay;
	void push_raw_frame(double* frame) {
		m_rawDelay.write(frame);
	}
	void push_processed_frame(double* frame) {
		m_processedDelay.write(frame);
	}
	
protected:
	vector<CEffect*> m_effects;
	long m_buffersize = 44100;
public:
	void addEffect(CEffect* f) { m_effects.push_back(f);
		f->setWetQ(&(this->m_processedDelay));
                f->setDryQ(&(this->m_rawDelay));
                f->setWrloc(getWrloc());
	}
	void setEffects(vector<CEffect*> v) {
		m_effects = v;
	}
	void processEffects(double* frame) {
		push_raw_frame(frame);
		double out[2];
		out[0] = 0.;
		out[1] = 0.;
		for (vector<CEffect*>::iterator it = m_effects.begin(); it != m_effects.end(); it++) {
			double* processed;
			processed = (*it)->process();
			out[0] += processed[0]/(double)m_effects.size();//weight balanced over number of effects
			out[1] += processed[1]/(double)m_effects.size();
			clamp(out[0]);
			clamp(out[1]);
			free(processed);
		}
		push_processed_frame(out);
		free(out);
	}
	double* read_raw_frame(int delay) {
		return m_rawDelay.read(delay);
	}
	double* read_raw_frame() {
		return m_rawDelay.read(0);
	}

	void clamp(double& sample) {
		if (sample >= 65536) { sample = 65535.; }
		if (sample <= -65536) { sample = -65535.; }
	}

	double* read_processed_frame(int delay) {
		return m_processedDelay.read(delay);
	}
	int* getWrloc() const { return m_rawDelay.getWrloc(); }
	CFXBox() {
		m_rawDelay = CircularBuffer();
		m_processedDelay = CircularBuffer();
	};
	virtual ~CFXBox() {};
	//CFXBox& operator=(CFXBox& other) {
	//	if (this != &other) {
	//		m_buffersize = other.m_buffersize;
	//		m_effects = other.m_effects;
	//		m_processedDelay = other.m_processedDelay;
	//		m_rawDelay = other.m_rawDelay;
	//	}
	//	return *this;
	//}
};
#endif //CFXBox.h

