//Created this to avoid changing the CAR class too much
//Similar to envelope

#pragma once
#include "AudioNode.h"
#include "AR.h" //No idea if I need this
class CAdditiveFinalSound : public CAR

{
public:
	CAdditiveFinalSound();
	virtual ~CAdditiveFinalSound();

public:
	void SetSource(CAudioNode* const &source) { m_source = source; }
	void SetDuration(double d) { m_duration = d; }
	void SetAttack(double a) { m_attack = a; }
	void SetRelease(double r) { m_release = r; }
	void SetDecay(double d) { m_decay = d; }
	void SetSustain(double s) { m_sustain = s; }
	virtual void Start();
	virtual bool Generate();

	void SetFadeIn(double f) { m_fadeIn = f; }
	void SetFadeOut(double f) { m_fadeOut = f; }

private:
	double m_duration;
	double m_time;
	double m_attack;
	double m_release;
	double m_decay;
	double m_sustain;

	CAudioNode* m_source;

	double m_fadeIn;
	double m_fadeOut;
};

