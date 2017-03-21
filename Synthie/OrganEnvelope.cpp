#include "stdafx.h"
#include "OrganEnvelope.h"

COrganEnvelope::COrganEnvelope(void)
{
	m_attack = 0.05;
	m_decay = 0.05;
	m_release = 0.01;
	m_duration = 0.1;
	m_source = NULL;
}

COrganEnvelope::~COrganEnvelope(void)
{
}

void COrganEnvelope::Start()
{
	m_time = 0;
}

bool COrganEnvelope::Generate()
{
	//short attack and short decay
	double gain = 1;
	if (m_time < m_attack) // set gain in relation to time related to the attack period
	{
		gain = 2 * (m_time / m_attack);
	}
	else if (m_time > m_attack && m_time < (m_attack + m_decay))
	{
		gain = 2 - ((m_time - m_attack) / m_decay);
	}
	else if (m_time >(m_duration - m_release) && m_time < m_duration)
	{
		double releaseStart = m_duration - m_release;
		gain = 1 - (m_time - releaseStart) / (m_duration - releaseStart);
	}
	else if (m_time >= m_duration) // not good
	{
		m_frame[0] = m_frame[1] = 0;
		return false;
	}

	if (m_source != NULL)
	{
		m_frame[0] = m_source->Frame(0) * gain;
		m_frame[1] = m_source->Frame(1) * gain;
	}

	m_time += GetSamplePeriod();
	return true;
}