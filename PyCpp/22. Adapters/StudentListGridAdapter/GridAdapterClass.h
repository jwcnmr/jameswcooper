#pragma once
#include "baseincludes.h"
#include "wx/window.h"
#include "wx/windowid.h"
#include "Student.h"

class GridAdapterClass :
    public wxGrid
{
private:	
	int curRow;
	vector<Student*> students;
public:
	GridAdapterClass(wxWindow* parent, wxWindowID id, const wxPoint& pos=wxDefaultPosition, const wxSize& size = wxDefaultSize);
	void Clear();
	int GetSelection();
	wxString GetString(int index);
	void Append(Student* st);
	void append(Student* st);
	void Delete();
	
	void setCurrentRow(int row);
	void onClick(wxGridEvent& event);
	Student* getSelected();
	int getSelectedRow();
	void redraw();
	void reset();
	void remove(int index);

};

