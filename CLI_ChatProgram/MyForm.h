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
			//
			//TODO: ここにコンストラクター コードを追加します
			//

			DC = gcnew DesignControls(this);
			InitializeComponent();
			
			P2Pclient=gcnew P2P_Client(DC);
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

	public:TcpListener^ listener;
	private:IPAddress^ server_ipAddress;
	

	private: int server_port = 1;
	

	private: System::Timers::Timer^ timer;


	private: void TimerCallback(System::Object^ sender, System::Timers::ElapsedEventArgs^ e);
	private: void P2P_Server();

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

		P2Pclient->Disconnection();
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
