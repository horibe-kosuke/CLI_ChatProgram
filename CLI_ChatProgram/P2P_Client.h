#pragma once
#include "DesignControls.h"
ref class P2P_Client
{
public:
	//! @brief									�R���X�g���N�^
	//! @param label							�E�B���h�E��ɕ����`��
	//! @param others_sever_ipAddress_textBox	�ڑ����IP�A�h���X�e�L�X�g�{�b�N�X
	//! @param others_sever_port_textBox 		�ڑ���̃|�[�g�ԍ��e�L�X�g�{�b�N�X
	P2P_Client(DesignControls^ dc);

	//! @brief �f�X�g���N�^
	~P2P_Client();

	//! @brief �N���C�A���g�ڑ��J�n
	void Start();

	//! @brief �ڑ��I��
	void Disconnection();

	//! @brief			���݂̐ڑ���
	//! @return	true	�ڑ��ł��Ă�
	//! @return	false	�ڑ��ł��ĂȂ�
	const bool Get_Client_State();

private:
	DesignControls^ DC;

	//�ڑ��ł��Ă邩���ׂ�ϐ��@true=�ڑ��ł��Ă�@false=�ڑ��ł��ĂȂ�
	bool Client_State;			
	
	//�ڑ����IP�A�h���X
	System::Net::IPAddress^ others_server_ipAddress;	

	//�ڑ���̃|�[�g�ԍ�
	int others_sever_port;								

	//! @brief �T�[�o�[�ɐڑ�
	//! �T�[�o�[�ɐڑ��ł����Client_State��true�ɂȂ�܂��B
	void ConnectToServer();

	//! @brief �f�[�^�[���T�[�o�[�ɑ��M
	void SendDataToServer();



};

