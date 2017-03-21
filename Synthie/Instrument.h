#pragma once
#include "AudioNode.h"
#include "Note.h"
#include "FXBox.h"
class CInstrument :
	public CAudioNode
{
public:
	CInstrument();
	virtual bool Generate() = 0;
	CInstrument(double);
	virtual ~CInstrument();
	virtual void SetNote(CNote *note) = 0;
};

