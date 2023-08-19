#pragma once
ref class DesignControls
{
public:
	DesignControls();
	DesignControls(System::Windows::Forms::Form^ parentForm);
	~DesignControls();


	System::Windows::Forms::TextBox^ textBox1;		//サーバーに送る文字
	System::Windows::Forms::Button^ button1;		//
	System::Windows::Forms::Label^ label1;
	System::Windows::Forms::TextBox^ server_ipAddress_textBox;

	System::Windows::Forms::Label^ Port;
	System::Windows::Forms::Label^ label3;
	System::Windows::Forms::TextBox^ others_sever_port_textBox;
	System::Windows::Forms::TextBox^ server_port_textBox;


	System::Windows::Forms::Button^ button_connect;



	System::Windows::Forms::Label^ state;
	System::Windows::Forms::ListView^ listView1;
	System::Windows::Forms::ColumnHeader^ columnHeader1;
	System::Windows::Forms::ColumnHeader^ columnHeader2;

	System::Windows::Forms::Label^ IP_label;
	System::Windows::Forms::Label^ label2;
	System::Windows::Forms::Button^ button2;
	System::Windows::Forms::TextBox^ others_server_ipAddress_textBox;
	System::Windows::Forms::Button^ server_disconnections_button;
	System::Windows::Forms::Button^ button3;
	System::Windows::Forms::Label^ server_state;

};

