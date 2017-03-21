#pragma once
#include "AudioNode.h"
#include "Note.h"
#include "FXBox.h"
class CInstrument :
	public CAudioNode
{
protected:
	CFXBox m_box;
public:
	CInstrument();
	CInstrument(double);
	virtual ~CInstrument();
	virtual void SetNote(CNote *note) = 0;
};

