#pragma once
#include <vector>
#include "Organ.h"
#include "InstrumentFactory.h"

class COrganFactory:public InstrumentFactory
{
public:
	COrganFactory();
	virtual ~COrganFactory();

	COrgan *COrganFactory::CreateOrgan(double bpm);
	void COrganFactory::SetNote(CNote *note);
	void SetFactoryDrawbars(int drawbarNum);

private:
	double m_amp;

	double m_vibratoFreq;
	double m_vibratoMag;

	bool m_leslieChanged;
	double m_leslieFreq;
	double m_leslieStartFreq;
	double m_leslieEndFreq;
	double m_leslieRadius;
	double m_leslieAttackTime;
	double m_leslieReleaseTime;

	int m_drawbarNum;
	vector<double> m_drawbars;

	vector<int> m_harmonics;
};

