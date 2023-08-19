#include "DesignControls.h"

DesignControls::DesignControls(System::Windows::Forms::Form^ parentForm)
{
	this->textBox1 = (gcnew System::Windows::Forms::TextBox());
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->server_ipAddress_textBox = (gcnew System::Windows::Forms::TextBox());
	this->button_connect = (gcnew System::Windows::Forms::Button());
	this->state = (gcnew System::Windows::Forms::Label());
	this->listView1 = (gcnew System::Windows::Forms::ListView());
	this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
	this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
	this->IP_label = (gcnew System::Windows::Forms::Label());
	this->label2 = (gcnew System::Windows::Forms::Label());
	this->server_disconnections_button = (gcnew System::Windows::Forms::Button());
	this->others_server_ipAddress_textBox = (gcnew System::Windows::Forms::TextBox());
	this->Port = (gcnew System::Windows::Forms::Label());
	this->label3 = (gcnew System::Windows::Forms::Label());
	this->others_sever_port_textBox = (gcnew System::Windows::Forms::TextBox());
	this->server_port_textBox = (gcnew System::Windows::Forms::TextBox());
	this->button3 = (gcnew System::Windows::Forms::Button());
	this->server_state = (gcnew System::Windows::Forms::Label());
	parentForm->SuspendLayout();
	// 
	// textBox1
	// 
	this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->textBox1->Location = System::Drawing::Point(12, 234);
	this->textBox1->Name = L"textBox1";
	this->textBox1->Size = System::Drawing::Size(308, 19);
	this->textBox1->TabIndex = 0;
	// 
	// button1
	// 
	this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
	this->button1->Location = System::Drawing::Point(325, 230);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(47, 23);
	this->button1->TabIndex = 1;
	this->button1->Text = L"送信";
	this->button1->UseVisualStyleBackColor = true;
	// 
	// label1
	// 
	this->label1->Location = System::Drawing::Point(0, 0);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(100, 23);
	this->label1->TabIndex = 10;
	// 
	// server_ipAddress_textBox
	// 
	this->server_ipAddress_textBox->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
	this->server_ipAddress_textBox->BackColor = System::Drawing::SystemColors::MenuText;
	this->server_ipAddress_textBox->ForeColor = System::Drawing::SystemColors::Window;
	this->server_ipAddress_textBox->Location = System::Drawing::Point(109, 66);
	this->server_ipAddress_textBox->Name = L"server_ipAddress_textBox";
	this->server_ipAddress_textBox->Size = System::Drawing::Size(103, 19);
	this->server_ipAddress_textBox->TabIndex = 3;

	// 
	// button_connect
	// 
	this->button_connect->BackColor = System::Drawing::SystemColors::HotTrack;
	this->button_connect->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(128)));
	this->button_connect->Location = System::Drawing::Point(318, 4);
	this->button_connect->Name = L"button_connect";
	this->button_connect->Size = System::Drawing::Size(48, 19);
	this->button_connect->TabIndex = 5;
	this->button_connect->Text = L"接続";
	this->button_connect->UseVisualStyleBackColor = false;
	// 
	// state
	// 
	this->state->AutoSize = true;
	this->state->ForeColor = System::Drawing::Color::Red;
	this->state->Location = System::Drawing::Point(137, 5);
	this->state->Name = L"state";
	this->state->Size = System::Drawing::Size(96, 12);
	this->state->TabIndex = 6;
	this->state->Text = L"接続されていません";
	// 
	// listView1
	// 
	this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
		| System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->columnHeader1, this->columnHeader2 });
	this->listView1->HideSelection = false;
	this->listView1->Location = System::Drawing::Point(11, 91);
	this->listView1->Name = L"listView1";
	this->listView1->Size = System::Drawing::Size(362, 134);
	this->listView1->TabIndex = 7;
	this->listView1->UseCompatibleStateImageBehavior = false;
	this->listView1->View = System::Windows::Forms::View::Details;
	// 
	// columnHeader1
	// 
	this->columnHeader1->Text = L"時間";
	this->columnHeader1->Width = 150;
	// 
	// columnHeader2
	// 
	this->columnHeader2->Text = L"メッセージ";
	this->columnHeader2->Width = 1000;
	// 
	// IP_label
	// 
	this->IP_label->AutoSize = true;
	this->IP_label->Location = System::Drawing::Point(0, 22);
	this->IP_label->Name = L"IP_label";
	this->IP_label->Size = System::Drawing::Size(87, 12);
	this->IP_label->TabIndex = 9;
	this->IP_label->Text = L"接続先IPアドレス";
	// 
	// label2
	// 
	this->label2->AutoSize = true;
	this->label2->Location = System::Drawing::Point(0, 69);
	this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
	this->label2->Name = L"label2";
	this->label2->Size = System::Drawing::Size(109, 12);
	this->label2->TabIndex = 11;
	this->label2->Text = L"自分のIPアドレス設定";
	// 
	// server_disconnections_button
	// 
	this->server_disconnections_button->BackColor = System::Drawing::Color::Red;
	this->server_disconnections_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(128)));
	this->server_disconnections_button->Location = System::Drawing::Point(318, 35);
	this->server_disconnections_button->Margin = System::Windows::Forms::Padding(2);
	this->server_disconnections_button->Name = L"server_disconnections_button";
	this->server_disconnections_button->Size = System::Drawing::Size(48, 18);
	this->server_disconnections_button->TabIndex = 12;
	this->server_disconnections_button->Text = L"切断";
	this->server_disconnections_button->UseVisualStyleBackColor = false;
	
	// 
	// others_server_ipAddress_textBox
	// 
	this->others_server_ipAddress_textBox->BackColor = System::Drawing::SystemColors::MenuText;
	this->others_server_ipAddress_textBox->ForeColor = System::Drawing::SystemColors::Window;
	this->others_server_ipAddress_textBox->Location = System::Drawing::Point(87, 19);
	this->others_server_ipAddress_textBox->Margin = System::Windows::Forms::Padding(2);
	this->others_server_ipAddress_textBox->Name = L"others_server_ipAddress_textBox";
	this->others_server_ipAddress_textBox->Size = System::Drawing::Size(94, 19);
	this->others_server_ipAddress_textBox->TabIndex = 13;
	// 
	// Port
	// 
	this->Port->AutoSize = true;
	this->Port->Location = System::Drawing::Point(186, 22);
	this->Port->Name = L"Port";
	this->Port->Size = System::Drawing::Size(26, 12);
	this->Port->TabIndex = 14;
	this->Port->Text = L"Port";
	// 
	// label3
	// 
	this->label3->AutoSize = true;
	this->label3->Location = System::Drawing::Point(218, 69);
	this->label3->Name = L"label3";
	this->label3->Size = System::Drawing::Size(26, 12);
	this->label3->TabIndex = 15;
	this->label3->Text = L"Port";
	// 
	// others_sever_port_textBox
	// 
	this->others_sever_port_textBox->BackColor = System::Drawing::SystemColors::MenuText;
	this->others_sever_port_textBox->ForeColor = System::Drawing::SystemColors::Window;
	this->others_sever_port_textBox->Location = System::Drawing::Point(218, 19);
	this->others_sever_port_textBox->Name = L"others_sever_port_textBox";
	this->others_sever_port_textBox->Size = System::Drawing::Size(100, 19);
	this->others_sever_port_textBox->TabIndex = 16;
	// 
	// server_port_textBox
	// 
	this->server_port_textBox->BackColor = System::Drawing::SystemColors::MenuText;
	this->server_port_textBox->ForeColor = System::Drawing::SystemColors::Window;
	this->server_port_textBox->Location = System::Drawing::Point(250, 66);
	this->server_port_textBox->Name = L"server_port_textBox";
	this->server_port_textBox->Size = System::Drawing::Size(68, 19);
	this->server_port_textBox->TabIndex = 17;
	// 
	// button3
	// 
	this->button3->BackColor = System::Drawing::Color::Green;
	this->button3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(128)));
	this->button3->ForeColor = System::Drawing::SystemColors::ControlText;
	this->button3->Location = System::Drawing::Point(318, 66);
	this->button3->Name = L"button3";
	this->button3->Size = System::Drawing::Size(48, 19);
	this->button3->TabIndex = 18;
	this->button3->Text = L"立てる";
	this->button3->UseVisualStyleBackColor = false;
	
	// 
	// server_state
	// 
	this->server_state->AutoSize = true;
	this->server_state->Location = System::Drawing::Point(139, 48);
	this->server_state->Name = L"server_state";
	this->server_state->Size = System::Drawing::Size(93, 12);
	this->server_state->TabIndex = 19;
	this->server_state->Text = L"サーバー立てました";
	
}

DesignControls::~DesignControls()
{
    
}
