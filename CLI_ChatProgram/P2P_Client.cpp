#include "P2P_Client.h"



P2P_Client::P2P_Client(DesignControls^ dc)
	: Client_State(false)
	, others_server_ipAddress(nullptr)
	, others_sever_port(1)
{
	DC=dc;
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
		//接続しているとき
		this->SendDataToServer();
	}
	else {
		//接続してないとき
		this->ConnectToServer();
	}
}

void P2P_Client::Disconnection()
{
	//接続先に接続したときだけ切断する
	if (Client_State == true) {

		//ソケット作成
		System::Net::Sockets::TcpClient^ client = gcnew System::Net::Sockets::TcpClient();

		//接続先のサーバーに接続
		client->Connect(others_server_ipAddress, others_sever_port);

		// クライアントのネットワークストリームを取得(送受信するためのもの)
		System::Net::Sockets::NetworkStream^ stream = client->GetStream();

		//送信するデータをUTF-8エンコーディングでバイト配列に変換
		array<System::Byte>^ data = System::Text::Encoding::UTF8->GetBytes("切断されました。");


		//送信
		stream->Write(data, 0, data->Length);

		//ソケットを閉じる
		client->Close();

		// ストリームを閉じる
		stream->Close();

		//文字の色を青色にする
		DC->state->ForeColor = System::Drawing::SystemColors::ControlText.Blue;
		//ウィンドウ上に文字描画
		DC->state->Text = "切断しました。";

		//接続していないのでfalse
		Client_State = false;
	}
}

const bool P2P_Client::Get_Client_State()
{
	return Client_State;
}

void P2P_Client::SendDataToServer()
{
	if (DC->textBox1->Text != "" && Client_State == true) {
		//月/日/時間の取得
		System::DateTime^ dt = gcnew System::DateTime;

		//時間だけ取得
		System::TimeSpan^ s = dt->TimeOfDay;

		//String型に代入
		System::String^ str = s->ToString();

		//リストビューアイテムに(時:分;秒)を代入
		System::Windows::Forms::ListViewItem^ item = gcnew System::Windows::Forms::ListViewItem(dt->Now.ToString("HH:mm:ss"));

		//アイテムのチェックを設定
		item->Checked = true;

		//リストビューのサブアイテムにテキスト追加
		item->SubItems->Add("送信:" + DC->textBox1->Text);

		//時間を追加
		DC->listView1->Items->Add(item);

		//リストビューの最後の行を取得
		int count = DC->listView1->Items->Count - 1;

		//スクロール位置は最後の位置
		DC->listView1->EnsureVisible(count);


		//ソケットを作成
		System::Net::Sockets::TcpClient^ client = gcnew System::Net::Sockets::TcpClient();

		//接続先のサーバーに接続
		client->Connect(others_server_ipAddress, others_sever_port);

		// クライアントのネットワークストリームを取得(送受信するためのもの)
		System::Net::Sockets::NetworkStream^ stream = client->GetStream();

		//送信するデータをUTF-8エンコーディングでバイト配列に変換
		array<System::Byte>^ data = System::Text::Encoding::UTF8->GetBytes(DC->textBox1->Text);



		//送信
		stream->Write(data, 0, data->Length);

		//ソケットを閉じる
		client->Close();

		// ストリームを閉じる
		stream->Close();

	}


}


void P2P_Client::ConnectToServer()
{
	//文字を赤色にする
	DC->state->ForeColor = System::Drawing::SystemColors::ControlText.Red;
	//ウィンドウ上に描画
	DC->state->Text = "接続中";

	//IPアドレス取得
	others_server_ipAddress = System::Net::IPAddress::Parse(DC->others_server_ipAddress_textBox->Text);
	//ポート番号取得
	others_sever_port = System::Int32::Parse(DC->others_sever_port_textBox->Text);

	//ソケットを作成
	System::Net::Sockets::TcpClient^ client = gcnew System::Net::Sockets::TcpClient();
	try {
		//接続先のサーバーに接続
		client->Connect(others_server_ipAddress, others_sever_port);

		//文字を緑色にする
		DC->state->ForeColor = System::Drawing::SystemColors::ControlText.Green;
		//ウィンドウ上に描画
		DC->state->Text = "接続しました。";

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