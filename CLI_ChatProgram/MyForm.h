#pragma once

#include "P2P_Client.h"
#include "DesignControls.h"
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

		MyForm(void)
		{
			DC = gcnew DesignControls(this);
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

	//private: System::Windows::Forms::TextBox^ textBox1;		//サーバーに送る文字
	//private: System::Windows::Forms::Button^ button1;		//
	//private: System::Windows::Forms::Label^ label1;
	//private: System::Windows::Forms::TextBox^ server_ipAddress_textBox;

	//private: System::Windows::Forms::Label^ Port;
	//private: System::Windows::Forms::Label^ label3;
	//private: System::Windows::Forms::TextBox^ others_sever_port_textBox;
	//private: System::Windows::Forms::TextBox^ server_port_textBox;


	//private: System::Windows::Forms::Button^ button_connect;



	//private: System::Windows::Forms::Label^ state;
	//private: System::Windows::Forms::ListView^ listView1;
	//private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	//private: System::Windows::Forms::ColumnHeader^ columnHeader2;

	//private: System::Windows::Forms::Label^ IP_label;	
	//private: System::Windows::Forms::Label^ label2;
	//private: System::Windows::Forms::Button^ button2;
	//private: System::Windows::Forms::TextBox^ others_server_ipAddress_textBox;
	//private: System::Windows::Forms::Button^ server_disconnections_button;
	//private: System::Windows::Forms::Button^ button3;
	//private: System::Windows::Forms::Label^ server_state;








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

			DC->button1->Click += gcnew System::EventHandler(this, &MyForm::Send_button_Click);
			DC->server_ipAddress_textBox->TextChanged += gcnew System::EventHandler(this, &MyForm::server_ipAddress_textBox_TextChanged);
			DC->button_connect->Click += gcnew System::EventHandler(this, &MyForm::button_connect_Click);
			DC->server_disconnections_button->Click += gcnew System::EventHandler(this, &MyForm::server_disconnections_button_Click);
			DC->button3->Click += gcnew System::EventHandler(this, &MyForm::Server_Stand_Click);

			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(378, 260);
			this->Controls->Add(this->DC->server_state);
			this->Controls->Add(this->DC->button3);
			this->Controls->Add(this->DC->server_port_textBox);
			this->Controls->Add(this->DC->others_sever_port_textBox);
			this->Controls->Add(this->DC->label3);
			this->Controls->Add(this->DC->Port);
			this->Controls->Add(this->DC->others_server_ipAddress_textBox);
			this->Controls->Add(this->DC->server_disconnections_button);
			this->Controls->Add(this->DC->label2);
			this->Controls->Add(this->DC->IP_label);
			this->Controls->Add(this->DC->listView1);
			this->Controls->Add(this->DC->state);
			this->Controls->Add(this->DC->button_connect);
			this->Controls->Add(this->DC->server_ipAddress_textBox);
			this->Controls->Add(this->DC->label1);
			this->Controls->Add(this->DC->button1);
			this->Controls->Add(this->DC->textBox1);





			//this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			//this->button1 = (gcnew System::Windows::Forms::Button());
			//this->label1 = (gcnew System::Windows::Forms::Label());
			//this->server_ipAddress_textBox = (gcnew System::Windows::Forms::TextBox());
			//this->button_connect = (gcnew System::Windows::Forms::Button());
			//this->state = (gcnew System::Windows::Forms::Label());
			//this->listView1 = (gcnew System::Windows::Forms::ListView());
			//this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			//this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			//this->IP_label = (gcnew System::Windows::Forms::Label());
			//this->label2 = (gcnew System::Windows::Forms::Label());
			//this->server_disconnections_button = (gcnew System::Windows::Forms::Button());
			//this->others_server_ipAddress_textBox = (gcnew System::Windows::Forms::TextBox());
			//this->Port = (gcnew System::Windows::Forms::Label());
			//this->label3 = (gcnew System::Windows::Forms::Label());
			//this->others_sever_port_textBox = (gcnew System::Windows::Forms::TextBox());
			//this->server_port_textBox = (gcnew System::Windows::Forms::TextBox());
			//this->button3 = (gcnew System::Windows::Forms::Button());
			//this->server_state = (gcnew System::Windows::Forms::Label());
			//this->SuspendLayout();
			//// 
			//// textBox1
			//// 
			//this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
			//	| System::Windows::Forms::AnchorStyles::Right));
			//this->textBox1->Location = System::Drawing::Point(12, 234);
			//this->textBox1->Name = L"textBox1";
			//this->textBox1->Size = System::Drawing::Size(308, 19);
			//this->textBox1->TabIndex = 0;
			//// 
			//// button1
			//// 
			//this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			//this->button1->Location = System::Drawing::Point(325, 230);
			//this->button1->Name = L"button1";
			//this->button1->Size = System::Drawing::Size(47, 23);
			//this->button1->TabIndex = 1;
			//this->button1->Text = L"送信";
			//this->button1->UseVisualStyleBackColor = true;
			//this->button1->Click += gcnew System::EventHandler(this, &MyForm::Send_button_Click);
			//// 
			//// label1
			//// 
			//this->label1->Location = System::Drawing::Point(0, 0);
			//this->label1->Name = L"label1";
			//this->label1->Size = System::Drawing::Size(100, 23);
			//this->label1->TabIndex = 10;
			//// 
			//// server_ipAddress_textBox
			//// 
			//this->server_ipAddress_textBox->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			//this->server_ipAddress_textBox->BackColor = System::Drawing::SystemColors::MenuText;
			//this->server_ipAddress_textBox->ForeColor = System::Drawing::SystemColors::Window;
			//this->server_ipAddress_textBox->Location = System::Drawing::Point(109, 66);
			//this->server_ipAddress_textBox->Name = L"server_ipAddress_textBox";
			//this->server_ipAddress_textBox->Size = System::Drawing::Size(103, 19);
			//this->server_ipAddress_textBox->TabIndex = 3;
			//this->server_ipAddress_textBox->TextChanged += gcnew System::EventHandler(this, &MyForm::server_ipAddress_textBox_TextChanged);
			//// 
			//// button_connect
			//// 
			//this->button_connect->BackColor = System::Drawing::SystemColors::HotTrack;
			//this->button_connect->Font = (gcnew System::Drawing::Font(L"ＭＳ Ｐゴシック", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			//	static_cast<System::Byte>(128)));
			//this->button_connect->Location = System::Drawing::Point(318, 4);
			//this->button_connect->Name = L"button_connect";
			//this->button_connect->Size = System::Drawing::Size(48, 19);
			//this->button_connect->TabIndex = 5;
			//this->button_connect->Text = L"接続";
			//this->button_connect->UseVisualStyleBackColor = false;
			//this->button_connect->Click += gcnew System::EventHandler(this, &MyForm::button_connect_Click);
			//// 
			//// state
			//// 
			//this->state->AutoSize = true;
			//this->state->ForeColor = System::Drawing::Color::Red;
			//this->state->Location = System::Drawing::Point(137, 5);
			//this->state->Name = L"state";
			//this->state->Size = System::Drawing::Size(96, 12);
			//this->state->TabIndex = 6;
			//this->state->Text = L"接続されていません";
			//// 
			//// listView1
			//// 
			//this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			//	| System::Windows::Forms::AnchorStyles::Left)
			//	| System::Windows::Forms::AnchorStyles::Right));
			//this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->columnHeader1, this->columnHeader2 });
			//this->listView1->HideSelection = false;
			//this->listView1->Location = System::Drawing::Point(11, 91);
			//this->listView1->Name = L"listView1";
			//this->listView1->Size = System::Drawing::Size(362, 134);
			//this->listView1->TabIndex = 7;
			//this->listView1->UseCompatibleStateImageBehavior = false;
			//this->listView1->View = System::Windows::Forms::View::Details;
			//// 
			//// columnHeader1
			//// 
			//this->columnHeader1->Text = L"時間";
			//this->columnHeader1->Width = 150;
			//// 
			//// columnHeader2
			//// 
			//this->columnHeader2->Text = L"メッセージ";
			//this->columnHeader2->Width = 1000;
			//// 
			//// IP_label
			//// 
			//this->IP_label->AutoSize = true;
			//this->IP_label->Location = System::Drawing::Point(0, 22);
			//this->IP_label->Name = L"IP_label";
			//this->IP_label->Size = System::Drawing::Size(87, 12);
			//this->IP_label->TabIndex = 9;
			//this->IP_label->Text = L"接続先IPアドレス";
			//this->IP_label->Click += gcnew System::EventHandler(this, &MyForm::IP_label_Click);
			//// 
			//// label2
			//// 
			//this->label2->AutoSize = true;
			//this->label2->Location = System::Drawing::Point(0, 69);
			//this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			//this->label2->Name = L"label2";
			//this->label2->Size = System::Drawing::Size(109, 12);
			//this->label2->TabIndex = 11;
			//this->label2->Text = L"自分のIPアドレス設定";
			//this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			//// 
			//// server_disconnections_button
			//// 
			//this->server_disconnections_button->BackColor = System::Drawing::Color::Red;
			//this->server_disconnections_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			//	static_cast<System::Byte>(128)));
			//this->server_disconnections_button->Location = System::Drawing::Point(318, 35);
			//this->server_disconnections_button->Margin = System::Windows::Forms::Padding(2);
			//this->server_disconnections_button->Name = L"server_disconnections_button";
			//this->server_disconnections_button->Size = System::Drawing::Size(48, 18);
			//this->server_disconnections_button->TabIndex = 12;
			//this->server_disconnections_button->Text = L"切断";
			//this->server_disconnections_button->UseVisualStyleBackColor = false;
			//this->server_disconnections_button->Click += gcnew System::EventHandler(this, &MyForm::server_disconnections_button_Click);
			//// 
			//// others_server_ipAddress_textBox
			//// 
			//this->others_server_ipAddress_textBox->BackColor = System::Drawing::SystemColors::MenuText;
			//this->others_server_ipAddress_textBox->ForeColor = System::Drawing::SystemColors::Window;
			//this->others_server_ipAddress_textBox->Location = System::Drawing::Point(87, 19);
			//this->others_server_ipAddress_textBox->Margin = System::Windows::Forms::Padding(2);
			//this->others_server_ipAddress_textBox->Name = L"others_server_ipAddress_textBox";
			//this->others_server_ipAddress_textBox->Size = System::Drawing::Size(94, 19);
			//this->others_server_ipAddress_textBox->TabIndex = 13;
			//// 
			//// Port
			//// 
			//this->Port->AutoSize = true;
			//this->Port->Location = System::Drawing::Point(186, 22);
			//this->Port->Name = L"Port";
			//this->Port->Size = System::Drawing::Size(26, 12);
			//this->Port->TabIndex = 14;
			//this->Port->Text = L"Port";
			//// 
			//// label3
			//// 
			//this->label3->AutoSize = true;
			//this->label3->Location = System::Drawing::Point(218, 69);
			//this->label3->Name = L"label3";
			//this->label3->Size = System::Drawing::Size(26, 12);
			//this->label3->TabIndex = 15;
			//this->label3->Text = L"Port";
			//// 
			//// others_sever_port_textBox
			//// 
			//this->others_sever_port_textBox->BackColor = System::Drawing::SystemColors::MenuText;
			//this->others_sever_port_textBox->ForeColor = System::Drawing::SystemColors::Window;
			//this->others_sever_port_textBox->Location = System::Drawing::Point(218, 19);
			//this->others_sever_port_textBox->Name = L"others_sever_port_textBox";
			//this->others_sever_port_textBox->Size = System::Drawing::Size(100, 19);
			//this->others_sever_port_textBox->TabIndex = 16;
			//// 
			//// server_port_textBox
			//// 
			//this->server_port_textBox->BackColor = System::Drawing::SystemColors::MenuText;
			//this->server_port_textBox->ForeColor = System::Drawing::SystemColors::Window;
			//this->server_port_textBox->Location = System::Drawing::Point(250, 66);
			//this->server_port_textBox->Name = L"server_port_textBox";
			//this->server_port_textBox->Size = System::Drawing::Size(68, 19);
			//this->server_port_textBox->TabIndex = 17;
			//// 
			//// button3
			//// 
			//this->button3->BackColor = System::Drawing::Color::Green;
			//this->button3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			//	static_cast<System::Byte>(128)));
			//this->button3->ForeColor = System::Drawing::SystemColors::ControlText;
			//this->button3->Location = System::Drawing::Point(318, 66);
			//this->button3->Name = L"button3";
			//this->button3->Size = System::Drawing::Size(48, 19);
			//this->button3->TabIndex = 18;
			//this->button3->Text = L"立てる";
			//this->button3->UseVisualStyleBackColor = false;
			//this->button3->Click += gcnew System::EventHandler(this, &MyForm::Server_Stand_Click);
			//// 
			//// server_state
			//// 
			//this->server_state->AutoSize = true;
			//this->server_state->Location = System::Drawing::Point(139, 48);
			//this->server_state->Name = L"server_state";
			//this->server_state->Size = System::Drawing::Size(93, 12);
			//this->server_state->TabIndex = 19;
			//this->server_state->Text = L"サーバー立てました";
			//// 
			//// MyForm
			//// 
			//this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			//this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			//this->BackColor = System::Drawing::SystemColors::Window;
			//this->ClientSize = System::Drawing::Size(378, 260);
			//this->Controls->Add(this->server_state);
			//this->Controls->Add(this->button3);
			//this->Controls->Add(this->server_port_textBox);
			//this->Controls->Add(this->others_sever_port_textBox);
			//this->Controls->Add(this->label3);
			//this->Controls->Add(this->Port);
			//this->Controls->Add(this->others_server_ipAddress_textBox);
			//this->Controls->Add(this->server_disconnections_button);
			//this->Controls->Add(this->label2);
			//this->Controls->Add(this->IP_label);
			//this->Controls->Add(this->listView1);
			//this->Controls->Add(this->state);
			//this->Controls->Add(this->button_connect);
			//this->Controls->Add(this->server_ipAddress_textBox);
			//this->Controls->Add(this->label1);
			//this->Controls->Add(this->button1);
			//this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//自分が作った変数
	private: P2P_Client^ P2Pclient;
	private: DesignControls^ DC;
	public:	Thread^ sever_thread;
	public: bool Server_Thread_State = true;
	public: bool Client_State = false;
	public:TcpListener^ listener;
	private:IPAddress^ server_ipAddress;
	private:IPAddress^ others_server_ipAddress;

	private: int server_port = 1;
	private: int others_sever_port = 1;

	private: System::Timers::Timer^ timer;


	private: void TimerCallback(System::Object^ sender, System::Timers::ElapsedEventArgs^ e);
	private: void P2P_Server();
	private: void P2P_Client_State();
	private: void P2P_Client_T();
	private: delegate void stateLabelDelegate(System::Windows::Forms::Label^ label, System::String^ str);
	private: void stateLabel(System::Windows::Forms::Label^ label, String^ str);

	private: delegate void ListViewsDelegate(ListViewItem^ item);
	private: void ListViews(ListViewItem^ item);


	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	public: System::Void Send_button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Font = gcnew System::Drawing::Font(System::Drawing::FontFamily::GenericMonospace, 20);
		DC->state->Text = "";
		DC->server_state->Text = "";
		timer = gcnew System::Timers::Timer(1000);
		timer->Elapsed += gcnew System::Timers::ElapsedEventHandler(this, &MyForm::TimerCallback);
		timer->AutoReset = true;	//タイマーを自動リセットに設定
		timer->Enabled = true;	//タイマーを有効にする

		//ホスト名取得
		String^ hostName = Dns::GetHostName();
		//ホスト情報を取得
		IPHostEntry^ hostEntry = Dns::GetHostEntry(hostName);
		for each (IPAddress ^ ip in hostEntry->AddressList)
		{
			//IPアドレスを選択(IPv4)
			if (ip->AddressFamily == System::Net::Sockets::AddressFamily::InterNetwork)
			{
				//IPアドレスをテキストボックスのテキストに入れる
				DC->server_ipAddress_textBox->Text = ip->ToString();
			}
		}

		DC->server_port_textBox->Text = server_port.ToString();
		DC->others_sever_port_textBox->Text = others_sever_port.ToString();
	}


	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_connect_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void IP_label_Click(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void server_ipAddress_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void server_disconnections_button_Click(System::Object^ sender, System::EventArgs^ e) {

		if (Client_State == true) {
			DC->state->ForeColor = SystemColors::ControlText.Blue;
			TcpClient^ client = gcnew TcpClient();
			//接続
			client->Connect(others_server_ipAddress, others_sever_port);
			NetworkStream^ stream = client->GetStream();

			array<Byte>^ data = Encoding::UTF8->GetBytes("切断されました。");


			stream->Write(data, 0, data->Length);

			client->Close();
			stream->Close();
			DC->state->Text = "切断しました。";
			Client_State = false;
		}
	}


	private: System::Void Server_Stand_Click(System::Object^ sender, System::EventArgs^ e) {

		if (sever_thread == nullptr) {
			sever_thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::P2P_Server));
			sever_thread->Start();
		}
		else {
			listener->Stop();
			Server_Thread_State = false;
			if (sever_thread->Join(1000)) {
				sever_thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::P2P_Server));
				sever_thread->Start();
			}
			else {
				DC->server_state->Text = "サーバーエラー";
			}

		}
	}
	};
}
