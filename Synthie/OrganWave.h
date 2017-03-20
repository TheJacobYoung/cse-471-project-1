#pragma once
#include "AudioNode.h"
#include <vector>

using namespace std;

class COrganWave :
	public CAudioNode
{
public:
	COrganWave(void);
	~COrganWave(void);

	virtual void Start();
	virtual bool Generate();

	void SetLeslieAttackTime(double lesattack) { m_leslieAttackTime = lesattack; }
	void SetLeslieStartFreq(double lesstart) { m_leslieStartFreq = lesstart; }
	void SetLeslieEndFreq(double lesend) { m_leslieEndFreq = lesend; }
	void SetLeslieReleaseTime(double lesrelease) { m_leslieReleaseTime = lesrelease; }
	void SetLeslieFreq(double lesfreq) { m_leslieFreq = lesfreq; }
	void SetLeslieChanged(bool leschanged) { m_leslieChanged = leschanged; }
	void SetLeslieRadius(double lesrad) { m_leslieRadius = lesrad; }
	void SetVibratoMag(double vmag) { m_vibratoMag = vmag; }
	void SetVibratoFreq(double vfreq) { m_vibratoFreq = vfreq; }
	void SetFreq(double f) { m_freq = f; }
	void SetDuration(double d) { m_duration = d * GetSampleRate(); }
	void SetAmplitude(double a) { m_amp = a; }
	void SetDrawbars(vector<double> drawbars) { m_drawbars = drawbars; }


private:
	double m_time;
	double m_freq;
	double m_duration;
	double m_phase;
	double m_amp;

	double m_vibrato_phase;
	double m_vibratoFreq;
	double m_vibratoMag;

	bool m_leslieChanged;
	double m_leslie_phase;
	double m_leslieFreq;
	double m_leslieStartFreq;
	double m_leslieEndFreq;
	double m_leslieRadius;
	double m_leslieAttackTime;
	double m_leslieReleaseTime;

	vector<double> m_drawbars;
	vector<int> m_harmonics;

};