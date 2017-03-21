//Similar to envelope

#include "stdafx.h"
#include "AdditiveFinalSound.h"


CAdditiveFinalSound::CAdditiveFinalSound()
{
	m_duration = 0.1;
	m_attack = 0.05;
	m_release = 0.05;
	m_decay = 1;
	m_sustain = 1;
	m_fadeIn = 1;
	m_fadeOut = 1;
}


CAdditiveFinalSound::~CAdditiveFinalSound()
{
}


void CAdditiveFinalSound::Start()
{
	m_source->SetSampleRate(GetSampleRate());
	m_source->Start();
	m_time = 0;
}

bool CAdditiveFinalSound::Generate()
{
	// Tell the component to generate an audio sample
	m_source->Generate();

	if (m_fadeIn != 1 || m_fadeOut != 1)
	{
		int checker = 1;
	}

	// Read the component's sample and make it our resulting frame.
	// Attack phase
	if (m_time <  m_attack)
	{
		m_frame[0] = m_source->Frame(0) * (m_time / m_attack) * m_fadeIn;
		m_frame[1] = m_source->Frame(1) * (m_time / m_attack) * m_fadeIn;
	}
	
	//Decay phase
	else if (m_time > m_attack && m_time < m_decay && m_time < m_duration - m_release)
	{
		m_frame[0] = m_source->Frame(0) * (m_duration - m_time) / m_decay;
		m_frame[1] = m_source->Frame(1) * (m_duration - m_time) / m_decay;
	}

	// Release phase
	else if (m_time > m_duration - m_release)
	{
		m_frame[0] = m_source->Frame(0) * ((m_duration - m_time) / m_release) * m_fadeOut;
		m_frame[1] = m_source->Frame(1) * ((m_duration - m_time) / m_release) * m_fadeOut;
	}

	// Middle phase
	// Used for sustaining
	else
	{
		m_frame[0] = m_source->Frame(0);
		m_frame[1] = m_source->Frame(1);
	}

	// Update time
	m_time += GetSamplePeriod();

	// We return true until the time reaches the duration.
	return m_time < m_duration;
}
