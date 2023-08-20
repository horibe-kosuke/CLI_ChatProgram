#pragma once
#include "DesignControls.h"
ref class P2P_Server
{
public:
	//! @brief		コンストラクタ
	//! @param dc	デザインコントロール(UI情報がある)
	P2P_Server(DesignControls^ dc);

	//! @brief デストラクタ
	~P2P_Server();

	//! @brief サーバを立てる準備
	void Server_Stand();
private:
	//デザインコントロール(UI情報がある)
	DesignControls^ DC;

	//クライアントからの接続をリッスンする
	System::Net::Sockets::TcpListener^ listener;

	//サーバーIPアドレス
	System::Net::IPAddress^ server_ipAddress;

	//サーバー用のスレッド
	System::Threading::Thread^ sever_thread;

	//サーバーを立ててる状態か立ててないかを確認する変数
	bool Server_Thread_State = true;

	//サーバーのポート番号
	int server_port = 1;

	//! @brief サーバーを立てる
	void Server();

	//! @brief マルチスレッドを使ってるのでUIを安全にアクセスするための関数
	delegate void stateLabelDelegate(System::Windows::Forms::Label^ label, System::String^ str);
	
	//! @brief			文字描画
	//! @param label	文字描画用変数
	//! @param str		描画させたい文字
	void stateLabel(System::Windows::Forms::Label^ label, System::String^ str);

	//! @brief マルチスレッドを使ってるのでUIを安全にアクセスするための関数
	delegate void ListViewsDelegate(System::Windows::Forms::ListViewItem^ item);

	//! @brief		リストビュー
	//! @param item リストビューのサブアイテムを追加するためのアイテム
	void ListViews(System::Windows::Forms::ListViewItem^ item);
};

