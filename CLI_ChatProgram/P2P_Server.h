#pragma once
#include "DesignControls.h"
ref class P2P_Server
{
public:
	P2P_Server(DesignControls^ dc);
	~P2P_Server();

	void Server_Stand();
private:
	DesignControls^ DC;

	System::Net::Sockets::TcpListener^ listener;
	System::Net::IPAddress^ server_ipAddress;
	System::Threading::Thread^ sever_thread;

	bool Server_Thread_State = true;
	int server_port = 1;

	void Server();

	delegate void stateLabelDelegate(System::Windows::Forms::Label^ label, System::String^ str);
	void stateLabel(System::Windows::Forms::Label^ label, System::String^ str);

	delegate void ListViewsDelegate(System::Windows::Forms::ListViewItem^ item);
	void ListViews(System::Windows::Forms::ListViewItem^ item);
};

