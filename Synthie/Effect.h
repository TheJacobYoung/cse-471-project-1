#pragma once

#include "stdafx.h"
#include "CircularBuffer.h"
#define PI 3.14159
class CEffect
{
    friend class CFXBox;
protected:
    int* m_wrloc;
    CircularBuffer* wet_q;
    CircularBuffer* dry_q;
    double m_wet;
    double m_dry;
    void setWetQ(CircularBuffer* b) { wet_q = b; }
    void setDryQ(CircularBuffer* b) { dry_q = b; }
public:
    void setWrloc(int* w){
        m_wrloc = w;
    }
    virtual double* process() = 0;
    virtual void setWeight(double w) {
            (w > 1.0) ? m_wet = 1.0 : m_wet = w;
            m_dry = 1.0 - m_wet;
    }
	CEffect() {}
	virtual ~CEffect() { delete m_wrloc;
	delete wet_q;
	delete dry_q;
	}
};

