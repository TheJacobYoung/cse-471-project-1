//Similar to base

#pragma once
#include "AudioNode.h"

class CAdditiveSynthSoundGenerator :
	public CAudioNode
{
public:
	CAdditiveSynthSoundGenerator();
	virtual ~CAdditiveSynthSoundGenerator();

public:
	virtual void Start();
	virtual bool Generate();

	void SetFreq(double f) { m_freq = f; }
	void SetAmplitude(int i, double a) { m_harmonics[i] = a; }

	//vibrato rate/freq
	void SetVibratoRate(double r) { m_vibRate = r; }
	void SetVibratoFreq(double f) { m_vibFreq = f; }

	void SetDuration(double d) { m_duration = d; }

private:
	double m_duration = 0;
	double m_freq;
	double m_phase = 0;
	double m_harmonics[5] = { 0 };

	double m_vibGeneral = 0;
	double m_vibRate = 0;
	double m_vibFreq = 0;

};

