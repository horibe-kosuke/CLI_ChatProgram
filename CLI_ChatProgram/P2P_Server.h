#pragma once
#include "DesignControls.h"
ref class P2P_Server
{
public:
	//! @brief		�R���X�g���N�^
	//! @param dc	�f�U�C���R���g���[��(UI��񂪂���)
	P2P_Server(DesignControls^ dc);

	//! @brief �f�X�g���N�^
	~P2P_Server();

	//! @brief �T�[�o�𗧂Ă鏀��
	void Server_Stand();
private:
	//�f�U�C���R���g���[��(UI��񂪂���)
	DesignControls^ DC;

	//�N���C�A���g����̐ڑ������b�X������
	System::Net::Sockets::TcpListener^ listener;

	//�T�[�o�[IP�A�h���X
	System::Net::IPAddress^ server_ipAddress;

	//�T�[�o�[�p�̃X���b�h
	System::Threading::Thread^ sever_thread;

	//�T�[�o�[�𗧂ĂĂ��Ԃ����ĂĂȂ������m�F����ϐ�
	bool Server_Thread_State = true;

	//�T�[�o�[�̃|�[�g�ԍ�
	int server_port = 1;

	//! @brief �T�[�o�[�𗧂Ă�
	void Server();

	//! @brief �}���`�X���b�h���g���Ă�̂�UI�����S�ɃA�N�Z�X���邽�߂̊֐�
	delegate void stateLabelDelegate(System::Windows::Forms::Label^ label, System::String^ str);
	
	//! @brief			�����`��
	//! @param label	�����`��p�ϐ�
	//! @param str		�`�悳����������
	void stateLabel(System::Windows::Forms::Label^ label, System::String^ str);

	//! @brief �}���`�X���b�h���g���Ă�̂�UI�����S�ɃA�N�Z�X���邽�߂̊֐�
	delegate void ListViewsDelegate(System::Windows::Forms::ListViewItem^ item);

	//! @brief		���X�g�r���[
	//! @param item ���X�g�r���[�̃T�u�A�C�e����ǉ����邽�߂̃A�C�e��
	void ListViews(System::Windows::Forms::ListViewItem^ item);
};

