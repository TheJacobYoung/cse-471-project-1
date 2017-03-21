#pragma once
#include <string>
#include "FXBox.h"
class CNote
{
public:
	CNote();
	virtual ~CNote();
	int Measure() const { return m_measure; }
	double Beat() const { return m_beat; }
	const std::wstring &Instrument() const { return m_instrument; }
	IXMLDOMNode *Node() { return m_node; }
	void XmlLoad(IXMLDOMNode * xml, std::wstring & instrument, CFXBox* box);
	bool operator<(const CNote &b);
	CFXBox* getBox() const { return box_ptr; }

private:
	CFXBox* box_ptr;
	std::wstring m_instrument;
	int m_measure;
	double m_beat;
	CComPtr<IXMLDOMNode> m_node;
};

