#include "StdAfx.h"
#include "OrganWave.h"
#include <cmath>

COrganWave::COrganWave(void)
{
	m_time = 0;
	m_vibratoFreq = 0;
	m_vibratoMag = 0;
	m_leslieRadius = 0;
	m_leslieAttackTime = 0;
	m_leslieReleaseTime = 0;
	m_leslie_phase = 0;
	m_leslieStartFreq = 0;
	m_amp = 1.0;
	m_drawbars.resize(9, 0.0);
	m_drawbars[0] = 8.0;
	m_harmonics.resize(9, 0);
	m_harmonics[0] = 1;
	m_harmonics[1] = 3;
	m_harmonics[2] = 2;
	m_harmonics[3] = 4;
	m_harmonics[4] = 6;
	m_harmonics[5] = 8;
	m_harmonics[6] = 10;
	m_harmonics[7] = 12;
	m_harmonics[8] = 16;
}

COrganWave::~COrganWave(void)
{
}

void COrganWave::Start()
{
	m_phase = 0;
	m_vibrato_phase = 0;
}

bool COrganWave::Generate()
{
	double vibMag = (m_vibratoMag / 100.0) * m_freq;
	double sample = 0;

	for (int i = 0; i < 9; i++) {
		sample += m_drawbars[i] * sin(m_phase * m_harmonics[i]);
	}

	double leslieDiff = (1 + (m_leslieRadius * (cos(m_leslie_phase) / 340.3)));
	double vibratoDiff = vibMag * sin(m_vibrato_phase);

	sample = sample * m_amp;

	m_frame[1] = m_frame[0] = sample;
	m_phase += 2 * PI * ((m_freq + vibratoDiff) * leslieDiff) * GetSamplePeriod();
	m_vibrato_phase += 2 * PI * m_vibratoFreq * GetSamplePeriod();

	double leslieAttackPoint = m_leslieAttackTime * GetSampleRate();
	double leslieReleasePoint = m_duration - (m_leslieReleaseTime * GetSampleRate());

	if ((m_time < leslieAttackPoint) && m_leslieChanged) {
		m_leslie_phase += 2 * PI * (m_leslieStartFreq + ((m_leslieFreq - m_leslieStartFreq) * (m_time / leslieAttackPoint))) * GetSamplePeriod();
	}
	else if (m_time > leslieReleasePoint) {
		m_leslie_phase += 2 * PI * (m_leslieEndFreq + ((m_leslieFreq - m_leslieEndFreq) * (1 - ((m_time - leslieReleasePoint) / (m_duration - leslieReleasePoint))))) * GetSamplePeriod();
		m_leslieStartFreq = m_leslieEndFreq;
	}
	else {
		m_leslie_phase += 2 * PI * m_leslieFreq * GetSamplePeriod();
	}

	m_time++;

	return true;
}