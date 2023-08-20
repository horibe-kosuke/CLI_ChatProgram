#pragma once
#include "DesignControls.h"
ref class P2P_Client
{
public:
	//! @brief									コンストラクタ
	//! @param label							ウィンドウ上に文字描画
	//! @param others_sever_ipAddress_textBox	接続先のIPアドレステキストボックス
	//! @param others_sever_port_textBox 		接続先のポート番号テキストボックス
	P2P_Client(DesignControls^ dc);

	//! @brief デストラクタ
	~P2P_Client();

	//! @brief クライアント接続開始
	void Start();

	//! @brief 接続終了
	void Disconnection();

	//! @brief			現在の接続状況
	//! @return	true	接続できてる
	//! @return	false	接続できてない
	const bool Get_Client_State();

private:
	DesignControls^ DC;

	//接続できてるか調べる変数　true=接続できてる　false=接続できてない
	bool Client_State;			
	
	//接続先のIPアドレス
	System::Net::IPAddress^ others_server_ipAddress;	

	//接続先のポート番号
	int others_sever_port;								

	//! @brief サーバーに接続
	//! サーバーに接続できるとClient_Stateがtrueになります。
	void ConnectToServer();

	//! @brief データーをサーバーに送信
	void SendDataToServer();



};

