//�ϐ��̓L�������P�[�X�ŏ�������
#include <Windows.h>
#include "main.h"
#include "DirectX.h"
#include "game1-1.h"
#include "input.h"
#include "texture.h"
#include "scene.h"


//�G���g���[�|�C���g
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�N���X�̓o�^
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	RegisterClass(&wc);

	//�E�B���h�E�X�^�C���̍쐬
	DWORD windowStyle = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
	//�E�B���h�E�T�C�Y�̋�`���쐬
	RECT windowRect = { 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };
	//�E�B���h�E�X�^�C���ɍ��킹�ċ�`�𒲐�����
	AdjustWindowRect(&windowRect, windowStyle, FALSE);

	//�������ꂽ��`����E�B���h�E�T�C�Y���č쐬����
	int windowWidth = windowRect.right - windowRect.left;
	int windowHeight = windowRect.bottom - windowRect.top;

	//�f�X�N�g�b�v�̉𑜓x���擾
	int desktopWidth = GetSystemMetrics(SM_CXSCREEN);
	int desktopHeight = GetSystemMetrics(SM_CYSCREEN);

	//�E�B���h�E�̈ʒu�i����j���f�X�N�g�b�v�̂ǂ��Ɉړ��������
	//�����ɕ\������邩���v�Z����
	//�i���f�X�N�g�b�v�̊O�ɏo�Ă��������ł���΍���̋��ɃZ�b�g����j
	int windowX = max((desktopWidth - windowWidth) / 2, 0);
	int windowY = max((desktopHeight - windowHeight) / 2, 0);

	//�E�B���h�E�̍쐬
	HWND gameWindow = CreateWindow(
		CLASS_NAME,			//Windows�ɓo�^���閼�O
		WINDOW_CAPTION,		//�^�C�g���ɕ\�����镶����
		windowStyle,		//�E�B���h�E�̃X�^�C��
		windowX,			//X�ʒu���S�_
		windowY,			//Y�ʒu���S�_
		windowWidth,		//���� width
		windowHeight,		//���� height
		NULL,				//�e�E�B���h�E�̎w��iHWND�j
		NULL,				//���j���[�̃n���h��
		hInstance,			//�C���X�^���X�̃n���h��
		NULL				//�ǉ��̊g���̈�i���Ɏg��Ȃ��̂�NULL���w��j
	);
	//�E�B���h�E���쐬�ł������`�F�b�N����
	if (gameWindow == NULL) {
		return 0;
	}

	//�쐬�����E�B���h�E����ʂɕ\������
	ShowWindow(gameWindow, nCmdShow);
	//�E�B���h�E���̍X�V
	UpdateWindow(gameWindow);

	//�E�B���h�E�̃o�b�N�o�b�t�@������
	Initialize(gameWindow);
	Keyboard_Initialize(hInstance, gameWindow);

	InitScene(SCENE_GAME1_1);

	//���b�Z�[�W���[�v
	MSG msg = {};
	while (WM_QUIT != msg.message)
	{
		//Windows���烁�b�Z�[�W�������ꍇ�̓��b�Z�[�W����������
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			//�Q�[���̏����������ɏ����Ă���
			UpdateMain(gameWindow);

			DrawMain();


		}
	}

	//�V�[���̏I������
	UninitScene();
	Keyboard_Finalize();
	UninitTexture();

	return (int)msg.wParam;
}

//window�̃C�x���g����������֐�
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN://�L�[�������ꂽ���b�Z�[�W
		if (wParam == VK_ESCAPE)
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);//WM_CLOSE���b�Z�[�W�������ɑ���
		}
		break;

	case WM_LBUTTONUP:
		//�}�E�X���{�^��������
		return 0;


	case WM_CLOSE:// �E�B���h�E����郁�b�Z�[�W
		if (MessageBox(hWnd, "�I�����Ă�낵���ł����H", "�m�F",
			MB_OKCANCEL | MB_DEFBUTTON2) == IDOK)
		{
			DestroyWindow(hWnd); //�w��̃E�B���h�E��WM_DESTROY�𑗂�
		}
		return 0;

	case WM_DESTROY: //�E�B���h�E�j�����b�Z�[�W
		PostQuitMessage(0); // WM_QUIT���b�Z�[�W�𑗂�
		return 0;
	}

	//���̑��̃��b�Z�[�W��Windows�ɔC����
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


void UpdateMain(HWND hWnd)
{
	Keyboard_Update();

	UpdateScene();
}


void DrawMain(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	// ��ʂ̃N���A
	pDevice->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_RGBA(100, 80, 200, 255),
		1.0f,
		0);

	// �`��̊J�n
	pDevice->BeginScene();

	// �Q�[���̕`�揈��
	DrawScene();

	// �`��̏I��
	pDevice->EndScene();

	// �o�b�N�o�b�t�@���t���b�v
	pDevice->Present(
		NULL,
		NULL,
		NULL,
		NULL
	);
}