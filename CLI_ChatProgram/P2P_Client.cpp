#include "P2P_Client.h"



P2P_Client::P2P_Client()
	: Client_State(false)
	, others_server_ipAddress(nullptr)
	, others_sever_port(1)
{

}

P2P_Client::~P2P_Client()
{
	this->Client_State = false;
	this->others_server_ipAddress = nullptr;
	this->others_sever_port = 1;
}

void P2P_Client::Start()
{
	if (Client_State == true) {
		this->SendDataToServer();
	}
	else {
		this->ConnectToServer();
	}
}

const bool P2P_Client::Get_Client_State()
{
	return Client_State;
}

void P2P_Client::SendDataToServer()
{
	//if (textBox1->Text != "" && Client_State == true) {
	//	DateTime^ dt = gcnew DateTime;
	//	TimeSpan^ s = dt->TimeOfDay;
	//	String^ str = s->ToString();

	//	ListViewItem^ item = gcnew ListViewItem(dt->Now.ToString("HH:mm:ss"));

	//	item->Checked = true;
	//	item->SubItems->Add("送信:" + textBox1->Text);

	//	listView1->Items->Add(item);

	//	int count = listView1->Items->Count - 1;
	//	listView1->EnsureVisible(count);



	//}

	//ソケットを作成
	System::Net::Sockets::TcpClient^ client = gcnew System::Net::Sockets::TcpClient();

	//接続先のサーバーに接続
	client->Connect(others_server_ipAddress, others_sever_port);

	// クライアントのネットワークストリームを取得(送受信するためのもの)
	System::Net::Sockets::NetworkStream^ stream = client->GetStream();

	//送信するデータをUTF-8エンコーディングでバイト配列に変換
	array<System::Byte>^ data = System::Text::Encoding::UTF8->GetBytes("接続しました。");



	//送信
	stream->Write(data, 0, data->Length);

	//ソケットを閉じる
	client->Close();

	// ストリームを閉じる
	stream->Close();
}


void P2P_Client::ConnectToServer()
{
	//文字を赤色にする
	label->ForeColor = System::Drawing::SystemColors::ControlText.Red;
	//ウィンドウ上に描画
	label->Text = "接続中";

	//IPアドレス取得
	others_server_ipAddress = System::Net::IPAddress::Parse(others_sever_ipAddress_textBox->Text);
	//ポート番号取得
	others_sever_port = System::Int32::Parse(others_sever_port_textBox->Text);

	//ソケットを作成
	System::Net::Sockets::TcpClient^ client = gcnew System::Net::Sockets::TcpClient();
	try {
		//接続先のサーバーに接続
		client->Connect(others_server_ipAddress, others_sever_port);

		//文字を緑色にする
		label->ForeColor = System::Drawing::SystemColors::ControlText.Green;
		//ウィンドウ上に描画
		label->Text = "接続しました。";

		// クライアントのネットワークストリームを取得(送受信するためのもの)
		System::Net::Sockets::NetworkStream^ stream = client->GetStream();

		//送信するデータをUTF-8エンコーディングでバイト配列に変換
		array<System::Byte>^ data = System::Text::Encoding::UTF8->GetBytes("接続しました。");

		//送信
		stream->Write(data, 0, data->Length);

		//ソケットを閉じる
		client->Close();

		// ストリームを閉じる
		stream->Close();

		//接続できているからtrue
		Client_State = true;
	}
	catch (System::ArgumentNullException^) {
		//nullptrの場合例外処理

		//ソケットを閉じる
		client->Close();

		//接続できてないからfalse
		Client_State = false;
	}
	catch (System::Net::Sockets::SocketException^)
	{
		//ソケットエラーの場合例外処理

		//ソケットを閉じる
		client->Close();
		//接続できてないからfalse
		Client_State = false;
	}
	catch (System::ObjectDisposedException^) {
		//破棄されたオブジェクトで操作が実行されるとスローされる例外処理

		//ソケットを閉じる
		client->Close();
		//接続できてないからfalse
		Client_State = false;
	}
}