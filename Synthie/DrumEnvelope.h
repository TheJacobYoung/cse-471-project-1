#pragma once
#include "AudioNode.h"
class CDrumEnvelope :
	public CAudioNode
{
public:
	CDrumEnvelope();
	virtual ~CDrumEnvelope();

	virtual void Start();
	virtual bool Generate();

	void SetAttack(double attack) { m_attack = attack; }
	void SetDecay(double decay) { m_decay = decay; }
	void SetDuration(double dur) { m_duration = dur; }
	void SetRelease(double release) { m_release = release; }
	void SetSustain(double sustain) { m_sustain = sustain; }
	void SetTime(double time) { m_time = time; }
	
	void SetSource(CAudioNode *source) { m_source = source; }
private:
	double m_attack;
	double m_decay;
	double m_duration;
	double m_release;
	double m_sustain;
	double m_time;
	CAudioNode *m_source;
};

