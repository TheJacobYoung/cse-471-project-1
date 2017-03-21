//Similar to base

#include "stdafx.h"
#include "AdditiveSynthSoundGenerator.h"


CAdditiveSynthSoundGenerator::CAdditiveSynthSoundGenerator()
{
	for (int i = 0; i < 5; i++)
	{
		m_harmonics[i] = 0;
	}
}


CAdditiveSynthSoundGenerator::~CAdditiveSynthSoundGenerator()
{
}

void CAdditiveSynthSoundGenerator::Start()
{
	m_phase = 0;
	m_vibGeneral = 0;
}

bool CAdditiveSynthSoundGenerator::Generate()
{
	double sample = 0;

	for (int i = 0; i<5; i++)
	{
		//various harmonics(amplitudes?) and the vibrato sinusoid
		sample += m_harmonics[i] * sin(m_phase * (i + 1) + sin(m_vibGeneral));

		if (sample < SHORT_MIN)
		{
			sample = SHORT_MIN;
		}

		else if (sample > SHORT_MAX)
		{
			sample = SHORT_MAX;
		}
	}

	m_frame[1] = m_frame[0] = sample;

	m_vibGeneral += 2 * PI * m_vibRate * GetSamplePeriod();
	m_phase += 2 * PI * (m_freq + m_vibFreq * sin(m_vibGeneral)) * GetSamplePeriod();

	return true;
}