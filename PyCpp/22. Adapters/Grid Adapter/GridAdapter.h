<<<<<<< HEAD
#pragma once
#include "baseincludes.h"
class GridAdapter
{
private:
	wxGrid* grid;
	int curRow;
public:

	GridAdapter(wxGrid* grd);
	void Clear();
	int GetSelection();
	wxString GetString(int index);
	void Append(wxString name);
	void Delete();
	void Refresh();
	void setCurrentRow(int row);
	void onClick(wxGridEvent& event);
	int getSelectedRow();
};

=======
#pragma once
#include "baseincludes.h"
class GridAdapter
{
private:
	wxGrid* grid;
	int curRow;
public:

	GridAdapter(wxGrid* grd);
	void Clear();
	int GetSelection();
	wxString GetString(int index);
	void Append(wxString name);
	void Delete();
	void Refresh();
	void setCurrentRow(int row);
	void onClick(wxGridEvent& event);
	int getSelectedRow();
};

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
