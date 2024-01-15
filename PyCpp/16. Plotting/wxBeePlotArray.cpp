#include <wx/wx.h>
#include <wx/gdicmn.h>
#include <vector>
using std::vector;

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class LinePlot : public wxFrame
{
    const int WIDTH = 300; 
    const int HEIGHT = 250;
    const int BHEIGHT = HEIGHT - 25;  //allows for title bar
    const int DATASIZE = 11;
    double xscale; double yscale;
    int xedge; int yedge;
    int xmin;  int ymin;
    int xmax;  int ymax;
    int width; int height; int bheight;
public:
    LinePlot(const wxString& title);
    void OnPaint(wxPaintEvent& event);  //the paint event handler
    int calcx(double xval);
    int calcy(double yval);
    void findBounds(vector <wxPoint*> p);  
    vector <wxPoint*> createData();
    wxPoint* createData1();
    void findBounds1(wxPoint* pt);
    wxPoint* pt;
    

};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    //create the Frame here
    LinePlot* line = new LinePlot(wxT("Line plot"));
    line->Show(true);
    return true;
}

//frame constructor
LinePlot::LinePlot(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition)
{
    SetBackgroundColour(0xefefef);
    SetSize(WIDTH, HEIGHT);         //set window size
    
    //paint event is called to redraw window
    this->Connect(wxEVT_PAINT, wxPaintEventHandler(LinePlot::OnPaint));
    this->Centre();
}
  
wxPoint* LinePlot::createData1() {
    wxPoint pt[11];
    int sz1 = sizeof(pt);
    int i = 0;
    pt[i++] = wxPoint(7, 32);
    pt[i++] = wxPoint(8, 35);
    pt[i++] = wxPoint(9, 29);
    pt[i++] = wxPoint(10, 34);
    pt[i++] = wxPoint(11, 30);
    pt[i++] = wxPoint(12, 22);
    pt[i++] = wxPoint(13, 32);
    pt[i++] = wxPoint(14, 24);
    pt[i++] = wxPoint(15, 23);
    pt[i++] = wxPoint(16, 28);
    pt[i++] = wxPoint(17, 21);
  
    findBounds1(pt);
    for (int i = 0; i < DATASIZE; i++) {
        pt[i].x = int(calcx(pt[i].x));
        pt[i].y = int(calcy(pt[i].y));
    }
    
    return pt;
}

/*
vector <wxPoint*> LinePlot::createData() {
    vector <wxPoint*> points;
    // create vector of x,y point coordinates
    points.push_back(new wxPoint(7, 32));
    points.push_back(new wxPoint(8, 35));
    points.push_back(new wxPoint(9, 29));
    points.push_back(new wxPoint(10, 34));
    points.push_back(new wxPoint(11, 30));
    points.push_back(new wxPoint(12, 22));
    points.push_back(new wxPoint(13, 32));
    points.push_back(new wxPoint(14, 24));
    points.push_back(new wxPoint(15, 23));
    points.push_back(new wxPoint(16, 28));
    points.push_back(new wxPoint(17, 21));
    findBounds(points);
    return points;

 }
 */
int LinePlot::calcx(double xval) {
    int newx = (xval - xmin) * xscale + xedge;
    return newx;
}
// ***Note that this shows the way to put (0,0) at the lower left
// instead of the upper left ***
int LinePlot::calcy(double yval) {
    int newy = bheight*0.8-(yval - ymin) * yscale + yedge;
   // int newy =  (yval-ymin) * yscale + yedge;  //incorrect - zero at top instead of bottom
    return newy;
}


/*void LinePlot::findBounds(vector <wxPoint*> points) {
    //find x and y max and min
    xmin = 10000; ymin = 10000; ymax = 0; xmax = 0;
    for (int i = 0; i < points.size(); i++) {
        
        int y = points[i]->y;
        int x = points[i]->x;
        if (xmin > x) xmin = x;
        if (xmax < x) xmax = x;
        if (ymin > y) ymin = y;
        if (ymax < y) ymax = y;
    }
}*/
void LinePlot::findBounds1(wxPoint* pts) {
    //find x and y max and min
    xmin = 10000; ymin = 10000; ymax = 0; xmax = 0;
    for (int i = 0; i < DATASIZE; i++) {

        int y = pts[i].y;
        int x = pts[i].x;
        if (xmin > x) xmin = x;
        if (xmax < x) xmax = x;
        if (ymin > y) ymin = y;
        if (ymax < y) ymax = y;
    }
    xscale = float(width * 0.8) / float(xmax - xmin);
    yscale = float(bheight * 0.8) / float(ymax - ymin);
    xedge = width * .05;
    yedge = height * .05;
}

//all the work happens in the Paint event
void LinePlot::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);
    wxSize sz = this->GetSize();
    width = sz.GetWidth();
    height = sz.GetHeight();
    bheight = height - 25;            // title bar
  
    dc.SetBrush(*wxBLACK_BRUSH);      //fill color   
    wxPoint* pts = createData1();
    
    // draw lines between points and add marker circles  
    dc.DrawLines(DATASIZE, pts);  
   
    for (int i = 0; i <DATASIZE; i++) {
        //and 3 pixel circle at each point       
        dc.DrawCircle(pts[i], 3);
    }
    
}
