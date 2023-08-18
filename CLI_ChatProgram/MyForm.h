#pragma once

namespace CLIChatProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;
	using namespace System::Threading;
	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		//自分が作った変数
		Thread^ sever_thread;
		Thread^ client_thread;
		bool Thread_State = true;
		TcpListener^ listener;
		IPAddress^ server_ipAddress = IPAddress::Parse("127.0.0.1");
		IPAddress^ others_server_ipAddress;




		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ textBox1;		//サーバーに送る文字
	private: System::Windows::Forms::Button^ button1;		//
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ server_ipAddress_textBox;




	private: System::Windows::Forms::Button^ button_connect;



	private: System::Windows::Forms::Label^ state;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ IP_label;	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ others_server_ipAddress_textBox;
	private: System::Windows::Forms::Button^ server_ipAddress_button;






	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->IP_label = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->server_ipAddress_button = (gcnew System::Windows::Forms::Button());
			this->others_server_ipAddress_textBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(16, 292);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(295, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(319, 288);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(63, 29);
			this->button1->TabIndex = 1;
			this->button1->Text = L"送信";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(133, 29);
			this->label1->TabIndex = 10;
			// 
			// server_ipAddress_textBox
			// 
			this->server_ipAddress_textBox->Location = System::Drawing::Point(116, 65);
			this->server_ipAddress_textBox->Margin = System::Windows::Forms::Padding(4);
			this->server_ipAddress_textBox->Name = L"server_ipAddress_textBox";
			this->server_ipAddress_textBox->Size = System::Drawing::Size(195, 22);
			this->server_ipAddress_textBox->TabIndex = 3;
			// 
			// button_connect
			// 
			this->button_connect->Location = System::Drawing::Point(318, 33);
			this->button_connect->Margin = System::Windows::Forms::Padding(4);
			this->button_connect->Name = L"button_connect";
			this->button_connect->Size = System::Drawing::Size(64, 24);
			this->button_connect->TabIndex = 5;
			this->button_connect->Text = L"接続";
			this->button_connect->UseVisualStyleBackColor = true;
			this->button_connect->Click += gcnew System::EventHandler(this, &MyForm::button_connect_Click);
			// 
			// state
			// 
			this->state->AutoSize = true;
			this->state->ForeColor = System::Drawing::Color::Red;
			this->state->Location = System::Drawing::Point(141, 14);
			this->state->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->state->Name = L"state";
			this->state->Size = System::Drawing::Size(120, 15);
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
			this->listView1->Location = System::Drawing::Point(15, 96);
			this->listView1->Margin = System::Windows::Forms::Padding(4);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(366, 184);
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
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"HOST", L"CLIENT" });
			this->comboBox1->Location = System::Drawing::Point(32, 10);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(64, 23);
			this->comboBox1->TabIndex = 8;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// IP_label
			// 
			this->IP_label->AutoSize = true;
			this->IP_label->Location = System::Drawing::Point(4, 36);
			this->IP_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->IP_label->Name = L"IP_label";
			this->IP_label->Size = System::Drawing::Size(109, 15);
			this->IP_label->TabIndex = 9;
			this->IP_label->Text = L"接続先IPアドレス";
			this->IP_label->Click += gcnew System::EventHandler(this, &MyForm::IP_label_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 15);
			this->label2->TabIndex = 11;
			this->label2->Text = L"IPアドレス設定";
			// 
			// server_ipAddress_button
			// 
			this->server_ipAddress_button->Location = System::Drawing::Point(317, 64);
			this->server_ipAddress_button->Name = L"server_ipAddress_button";
			this->server_ipAddress_button->Size = System::Drawing::Size(64, 23);
			this->server_ipAddress_button->TabIndex = 12;
			this->server_ipAddress_button->Text = L"決定";
			this->server_ipAddress_button->UseVisualStyleBackColor = true;
			this->server_ipAddress_button->Click += gcnew System::EventHandler(this, &MyForm::server_ipAddress_button_Click);
			// 
			// others_server_ipAddress_textBox
			// 
			this->others_server_ipAddress_textBox->Location = System::Drawing::Point(116, 36);
			this->others_server_ipAddress_textBox->Name = L"others_server_ipAddress_textBox";
			this->others_server_ipAddress_textBox->Size = System::Drawing::Size(195, 22);
			this->others_server_ipAddress_textBox->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(390, 325);
			this->Controls->Add(this->others_server_ipAddress_textBox);
			this->Controls->Add(this->server_ipAddress_button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->IP_label);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->state);
			this->Controls->Add(this->button_connect);
			this->Controls->Add(this->server_ipAddress_textBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: void P2P_Server();
	private: void P2P_Client();

	private: delegate void stateLabelDelegate(System::String^ str);
	private: void stateLabel(String^ str);

	private: delegate void ListViewsDelegate(ListViewItem^ item);
	private:void ListViews(ListViewItem^ item);


	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Font = gcnew System::Drawing::Font(System::Drawing::FontFamily::GenericMonospace, 20);
		comboBox1->SelectedIndex = 0;
		state->Text = "";

	}


	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_connect_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void IP_label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void server_ipAddress_button_Click(System::Object^ sender, System::EventArgs^ e) {
		server_ipAddress = IPAddress::Parse(server_ipAddress_textBox->Text);
	}
	};
}
