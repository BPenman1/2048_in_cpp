#pragma once

#include "wx/wx.h"
#include "cMain.h"
#include "wx/grid.h"

class cApp : public wxApp {
public :
	cApp();
	~cApp();

private:
	cMain* m_frame1 = nullptr;

public:
	virtual bool OnInit();
};

