#include "P2P_Server.h"

P2P_Server::P2P_Server(DesignControls^ dc)
	:sever_thread(nullptr)
{	
	//デザインコントロールをDCに入れてDCで使えるようにしている
	DC = dc;
}

P2P_Server::~P2P_Server()
{
	//サーバースレッドを使ってたら初期化
	if (sever_thread != nullptr) {
		//クライアントからの接続待ちを停止
		listener->Stop();
		//スレッドを終了するためにfalse
		Server_Thread_State = false;
		//終了
		sever_thread->Join(1000);
	}
}

void P2P_Server::Server_Stand()
{
	//サーバースレッドの状態を確認
	if (sever_thread == nullptr) {
		sever_thread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &P2P_Server::Server));
		sever_thread->Start();
	}
	else {
		//サーバースレッドを使ってたら初期化する
		listener->Stop();
		Server_Thread_State = false;
		if (sever_thread->Join(1000)) {
			sever_thread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &P2P_Server::Server));
			sever_thread->Start();
		}
		else {
			DC->server_state->Text = "サーバーエラー";
		}
	}
}

void P2P_Server::Server()
{
	//サーバーのIPアドレスを取得
	server_ipAddress = System::Net::IPAddress::Parse(DC->server_ipAddress_textBox->Text);
	//サーバーのポート番号取得
	server_port = System::Int32::Parse(DC->server_port_textBox->Text);


	try {
		//安全にUIをアクセスする
		if (DC->server_state->InvokeRequired) {
			stateLabelDelegate^ invoker = (gcnew stateLabelDelegate(this, &P2P_Server::stateLabel));
			DC->server_state->ForeColor = System::Drawing::SystemColors::ControlText.Green;
			DC->server_state->Invoke(invoker, DC->server_state, "サーバー立てました");

		}
		else {
			DC->server_state->ForeColor = System::Drawing::SystemColors::ControlText.Green;
			DC->server_state->Text = "サーバー立てました";
		}



		listener = gcnew System::Net::Sockets::TcpListener(server_ipAddress, server_port);

		
		listener->Start();



		while (Server_Thread_State) {
			System::Net::Sockets::TcpClient^ client;
			System::Net::Sockets::NetworkStream^ stream;
			array<System::Byte>^ buffer = gcnew array<System::Byte>(1024);
			System::String^ message;

			//クライアントの接続待ち
			client = listener->AcceptTcpClient();

			// クライアントのネットワークストリームを取得(送受信するためのもの)
			stream = client->GetStream();

			//受信
			int byteread = stream->Read(buffer, 0, 1024);

			//受信するデータをUTF-8エンコーディングでバイト配列に変換
			message = System::Text::Encoding::UTF8->GetString(buffer, 0, byteread);

			//月/日/時間の取得
			System::DateTime^ dt = gcnew System::DateTime;

			//時間だけ取得
			System::TimeSpan^ s = dt->TimeOfDay;

			//String型に代入
			System::String^ str = s->ToString();

			System::Windows::Forms::ListViewItem^ item = gcnew System::Windows::Forms::ListViewItem(dt->Now.ToString("HH:mm:ss"));

			item->Checked = true;
			//受信した文字をリストビューアイテムに追加
			item->SubItems->Add("受信:" + message);


			//安全にUIをアクセスする
			if (DC->listView1->InvokeRequired) {
				ListViewsDelegate^ invoker = (gcnew ListViewsDelegate(this, &P2P_Server::ListViews));
				DC->listView1->Invoke(invoker, item);

			}
			else {
				DC->listView1->Items->Add(item);
				int count = DC->listView1->Items->Count - 1;
				DC->listView1->EnsureVisible(count);
			}

			//ソケット閉じる
			client->Close();

			//ストリームを閉じる
			stream->Close();
		}

	}
	catch (System::Net::Sockets::SocketException^) {

	}

}

void P2P_Server::stateLabel(System::Windows::Forms::Label^ label, System::String^ str)
{
	//文字描画
	label->Text = DC->server_ipAddress_textBox->Text + str;
}

void P2P_Server::ListViews(System::Windows::Forms::ListViewItem^ item)
{
	//リストビューに追加
	DC->listView1->Items->Add(item);

	//リストビューの最後の行を取得
	int count = DC->listView1->Items->Count - 1;

	//リストビューのスクロール位置を最後に設定
	DC->listView1->EnsureVisible(count);
}
