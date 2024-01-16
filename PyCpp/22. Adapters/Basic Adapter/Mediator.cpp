#include "Mediator.h"

//resets the listboxes and reloads the left box
void Mediator::reset() {
    wxString students[6] = { "Anne Green", "Barry Pye", "Charlie Horse", "Darren Steal",
       "Evan Essent", "Bjorn Stroustrup" };
    listbox->Clear();
    advListBox->Clear();
   
    for (int i = 0; i < 6; i++) {
        listbox->Append(students[i]); 
       // names.push_back(students[i]);
    }
}

//The Mediator mediates listbox and button click events 
    Mediator::Mediator(wxFrame* gframe, wxListBox* glist, wxListBox* advlist) {
        listbox = glist;
        advListBox = advlist;
        frame = gframe;     
        reset();
    }
    
    //left list box click comes here. 
    void Mediator::onListClick(wxCommandEvent& event) {    
        moveButton->Enable();
        restoreButton->Disable();
    }

    //right list box click comes here. 
    void Mediator::advListClick(wxCommandEvent& event) {
       // int index = advListBox->GetSelection();
        moveButton->Disable();
        restoreButton->Enable();
       // advListBox->Refresh();
    }
    
    //copy in button references
    void Mediator::setButtons(MoveButton* mvb, RestoreButton* rsb, ClearButton* clb) {
        restoreButton = rsb;
        moveButton = mvb;
        clearButton = clb;
        restoreButton->Disable();
        moveButton->Disable();
    }

    //clicks on each of 3 buttons
    //move name to right
    void Mediator::moveClick() {
        int index = listbox->GetSelection();
        wxString nm = listbox->GetString(index);
        advListBox->Append(nm); //add name to right
        listbox->Delete(index); //remove name from left
        moveButton->Disable();  //disable until listbox clicked
    }
    //move name to left
    void Mediator::restoreClick() {
        int index = advListBox->GetSelection();
        wxString nm = advListBox->GetString(index);
        advListBox->Delete(index);  //remove from right
        listbox->Append(nm);        //add to left
        restoreButton->Disable();   //disable restore button
    }

    //reset button states and reload list
    void Mediator::clearClick() {
        reset();
    }

