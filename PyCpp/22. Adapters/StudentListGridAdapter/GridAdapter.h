#pragma once
#include "baseincludes.h"
#include "Student.h"
using std::vector;

class GridAdapter
{
private:
	wxGrid* grid;
	int curRow;
	vector<Student*> students;
public:

	GridAdapter(wxGrid* grd);
	void Clear();
	int GetSelection();
	wxString GetString(int index);
	void Append(Student* st);
	void append(Student* st);
	void Delete();
	void Refresh();
	void setCurrentRow(int row);
	void onClick(wxGridEvent& event);
	Student* getSelected();
	int getSelectedRow();
	void redraw();
	void reset();
	void remove(int index);
};

