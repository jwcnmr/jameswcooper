<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.VoiceBox = New System.Windows.Forms.GroupBox()
        Me.BasButton = New System.Windows.Forms.RadioButton()
        Me.tenButton = New System.Windows.Forms.RadioButton()
        Me.altButton = New System.Windows.Forms.RadioButton()
        Me.sopButton = New System.Windows.Forms.RadioButton()
        Me.RoleBox = New System.Windows.Forms.GroupBox()
        Me.btChorus = New System.Windows.Forms.RadioButton()
        Me.btMinor = New System.Windows.Forms.RadioButton()
        Me.byPrinc = New System.Windows.Forms.RadioButton()
        Me.Namelist = New System.Windows.Forms.ListBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.namebox = New System.Windows.Forms.TextBox()
        Me.Addbutton = New System.Windows.Forms.Button()
        Me.Clearbutton = New System.Windows.Forms.Button()
        Me.VoiceBox.SuspendLayout()
        Me.RoleBox.SuspendLayout()
        Me.SuspendLayout()
        '
        'VoiceBox
        '
        Me.VoiceBox.Controls.Add(Me.BasButton)
        Me.VoiceBox.Controls.Add(Me.tenButton)
        Me.VoiceBox.Controls.Add(Me.altButton)
        Me.VoiceBox.Controls.Add(Me.sopButton)
        Me.VoiceBox.Location = New System.Drawing.Point(35, 12)
        Me.VoiceBox.Name = "VoiceBox"
        Me.VoiceBox.Size = New System.Drawing.Size(97, 135)
        Me.VoiceBox.TabIndex = 0
        Me.VoiceBox.TabStop = False
        Me.VoiceBox.Text = "Voices"
        '
        'BasButton
        '
        Me.BasButton.AutoSize = True
        Me.BasButton.Location = New System.Drawing.Point(7, 101)
        Me.BasButton.Name = "BasButton"
        Me.BasButton.Size = New System.Drawing.Size(48, 19)
        Me.BasButton.TabIndex = 3
        Me.BasButton.TabStop = True
        Me.BasButton.Text = "Bass"
        Me.BasButton.UseVisualStyleBackColor = True
        '
        'tenButton
        '
        Me.tenButton.AutoSize = True
        Me.tenButton.Location = New System.Drawing.Point(7, 75)
        Me.tenButton.Name = "tenButton"
        Me.tenButton.Size = New System.Drawing.Size(54, 19)
        Me.tenButton.TabIndex = 2
        Me.tenButton.TabStop = True
        Me.tenButton.Text = "Tenor"
        Me.tenButton.UseVisualStyleBackColor = True
        '
        'altButton
        '
        Me.altButton.AutoSize = True
        Me.altButton.Location = New System.Drawing.Point(7, 49)
        Me.altButton.Name = "altButton"
        Me.altButton.Size = New System.Drawing.Size(47, 19)
        Me.altButton.TabIndex = 1
        Me.altButton.TabStop = True
        Me.altButton.Text = "Alto"
        Me.altButton.UseVisualStyleBackColor = True
        '
        'sopButton
        '
        Me.sopButton.AutoSize = True
        Me.sopButton.Checked = True
        Me.sopButton.Location = New System.Drawing.Point(7, 23)
        Me.sopButton.Name = "sopButton"
        Me.sopButton.Size = New System.Drawing.Size(69, 19)
        Me.sopButton.TabIndex = 0
        Me.sopButton.TabStop = True
        Me.sopButton.Text = "Soprano"
        Me.sopButton.UseVisualStyleBackColor = True
        '
        'RoleBox
        '
        Me.RoleBox.Controls.Add(Me.btChorus)
        Me.RoleBox.Controls.Add(Me.btMinor)
        Me.RoleBox.Controls.Add(Me.byPrinc)
        Me.RoleBox.Location = New System.Drawing.Point(167, 12)
        Me.RoleBox.Name = "RoleBox"
        Me.RoleBox.Size = New System.Drawing.Size(133, 120)
        Me.RoleBox.TabIndex = 1
        Me.RoleBox.TabStop = False
        Me.RoleBox.Text = "Roles"
        '
        'btChorus
        '
        Me.btChorus.AutoSize = True
        Me.btChorus.Location = New System.Drawing.Point(7, 75)
        Me.btChorus.Name = "btChorus"
        Me.btChorus.Size = New System.Drawing.Size(63, 19)
        Me.btChorus.TabIndex = 2
        Me.btChorus.TabStop = True
        Me.btChorus.Text = "Chorus"
        Me.btChorus.UseVisualStyleBackColor = True
        '
        'btMinor
        '
        Me.btMinor.AutoSize = True
        Me.btMinor.Location = New System.Drawing.Point(7, 48)
        Me.btMinor.Name = "btMinor"
        Me.btMinor.Size = New System.Drawing.Size(82, 19)
        Me.btMinor.TabIndex = 1
        Me.btMinor.TabStop = True
        Me.btMinor.Text = "Minor lead"
        Me.btMinor.UseVisualStyleBackColor = True
        '
        'byPrinc
        '
        Me.byPrinc.AutoSize = True
        Me.byPrinc.Checked = True
        Me.byPrinc.Location = New System.Drawing.Point(7, 23)
        Me.byPrinc.Name = "byPrinc"
        Me.byPrinc.Size = New System.Drawing.Size(71, 19)
        Me.byPrinc.TabIndex = 0
        Me.byPrinc.TabStop = True
        Me.byPrinc.Text = "Princioal"
        Me.byPrinc.UseVisualStyleBackColor = True
        '
        'Namelist
        '
        Me.Namelist.FormattingEnabled = True
        Me.Namelist.ItemHeight = 15
        Me.Namelist.Location = New System.Drawing.Point(323, 22)
        Me.Namelist.Name = "Namelist"
        Me.Namelist.Size = New System.Drawing.Size(120, 109)
        Me.Namelist.TabIndex = 2
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.ForeColor = System.Drawing.Color.CornflowerBlue
        Me.Label1.Location = New System.Drawing.Point(42, 175)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(39, 15)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "Name"
        '
        'namebox
        '
        Me.namebox.Location = New System.Drawing.Point(104, 172)
        Me.namebox.Name = "namebox"
        Me.namebox.Size = New System.Drawing.Size(180, 23)
        Me.namebox.TabIndex = 4
        '
        'Addbutton
        '
        Me.Addbutton.Location = New System.Drawing.Point(104, 220)
        Me.Addbutton.Name = "Addbutton"
        Me.Addbutton.Size = New System.Drawing.Size(75, 23)
        Me.Addbutton.TabIndex = 5
        Me.Addbutton.Text = "Add"
        Me.Addbutton.UseVisualStyleBackColor = True
        '
        'Clearbutton
        '
        Me.Clearbutton.Location = New System.Drawing.Point(209, 220)
        Me.Clearbutton.Name = "Clearbutton"
        Me.Clearbutton.Size = New System.Drawing.Size(75, 23)
        Me.Clearbutton.TabIndex = 6
        Me.Clearbutton.Text = "Clear"
        Me.Clearbutton.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 15.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(456, 314)
        Me.Controls.Add(Me.Clearbutton)
        Me.Controls.Add(Me.Addbutton)
        Me.Controls.Add(Me.namebox)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.Namelist)
        Me.Controls.Add(Me.RoleBox)
        Me.Controls.Add(Me.VoiceBox)
        Me.Name = "Form1"
        Me.Text = "Casting list"
        Me.VoiceBox.ResumeLayout(False)
        Me.VoiceBox.PerformLayout()
        Me.RoleBox.ResumeLayout(False)
        Me.RoleBox.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents VoiceBox As GroupBox
    Friend WithEvents BasButton As RadioButton
    Friend WithEvents tenButton As RadioButton
    Friend WithEvents altButton As RadioButton
    Friend WithEvents sopButton As RadioButton
    Friend WithEvents RoleBox As GroupBox
    Friend WithEvents btChorus As RadioButton
    Friend WithEvents btMinor As RadioButton
    Friend WithEvents byPrinc As RadioButton
    Friend WithEvents Namelist As ListBox
    Friend WithEvents Label1 As Label
    Friend WithEvents namebox As TextBox
    Friend WithEvents Addbutton As Button
    Friend WithEvents Clearbutton As Button
End Class
