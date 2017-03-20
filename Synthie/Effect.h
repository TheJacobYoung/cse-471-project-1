#pragma once
#define PI 3.14159
class CEffect
{
	
	friend class CFXBox;
protected:
	CFXBox& m_box;
	double m_wet;
	double m_dry;
	void setBox(CFXBox& b) { m_box = b; }
public:
	virtual double* process() = 0;
	CEffect();
	virtual void setWeight(double w) {
		(w > 1.0) ? m_wet = 1.0 : m_wet = w;
		m_dry = 1.0 - m_wet;
	}
	virtual ~CEffect();
};

