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
	virtual bool Generate() = 0;
	CInstrument(double);
	virtual ~CInstrument();
	virtual void SetNote(CNote *note) = 0;
	void setBox(CFXBox& b) {
		m_box = b;
	}
	void addEffect(CEffect* f) {
		m_box.addEffect(f);
	}
};

