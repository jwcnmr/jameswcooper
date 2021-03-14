Public Class Form1
    Private Sub Addbutton_Click(sender As Object, e As EventArgs) Handles Addbutton.Click
        Dim crb As RadioButton, tx As String, rb As RadioButton, rx As String

        'get the voice part text and shorten it
        crb = GetRadio(VoiceBox)
        tx = crb.Text.Substring(0, 3)

        'get the role name
        rb = GetRadio(RoleBox)
        rx = rb.Text.Substring(0, 3)

        'add to listbox
        Namelist.Items.Add(tx + " " + rx + " -- " + namebox.Text)
        namebox.Text = ""
    End Sub

    Private Sub Clearbutton_Click(sender As Object, e As EventArgs) Handles Clearbutton.Click
        namebox.Text = ""
        Namelist.Items.Clear()

    End Sub

    Private Function GetRadio(rbox As GroupBox)
        Return rbox.Controls.OfType(Of RadioButton)().FirstOrDefault(Function(radioButton) radioButton.Checked)
    End Function

End Class
