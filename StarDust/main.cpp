//変数はキャメルケースで書くこと
#include <Windows.h>
#include "main.h"
#include "DirectX.h"
#include "game1-1.h"
#include "input.h"
#include "texture.h"
#include "scene.h"


//エントリーポイント
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウクラスの登録
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	RegisterClass(&wc);

	//ウィンドウスタイルの作成
	DWORD windowStyle = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
	//ウィンドウサイズの矩形を作成
	RECT windowRect = { 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };
	//ウィンドウスタイルに合わせて矩形を調整する
	AdjustWindowRect(&windowRect, windowStyle, FALSE);

	//調整された矩形からウィンドウサイズを再作成する
	int windowWidth = windowRect.right - windowRect.left;
	int windowHeight = windowRect.bottom - windowRect.top;

	//デスクトップの解像度を取得
	int desktopWidth = GetSystemMetrics(SM_CXSCREEN);
	int desktopHeight = GetSystemMetrics(SM_CYSCREEN);

	//ウィンドウの位置（左上）をデスクトップのどこに移動させれば
	//中央に表示されるかを計算する
	//（※デスクトップの外に出ていきそうであれば左上の隅にセットする）
	int windowX = max((desktopWidth - windowWidth) / 2, 0);
	int windowY = max((desktopHeight - windowHeight) / 2, 0);

	//ウィンドウの作成
	HWND gameWindow = CreateWindow(
		CLASS_NAME,			//Windowsに登録する名前
		WINDOW_CAPTION,		//タイトルに表示する文字列
		windowStyle,		//ウィンドウのスタイル
		windowX,			//X位置中心点
		windowY,			//Y位置中心点
		windowWidth,		//横幅 width
		windowHeight,		//高さ height
		NULL,				//親ウィンドウの指定（HWND）
		NULL,				//メニューのハンドル
		hInstance,			//インスタンスのハンドル
		NULL				//追加の拡張領域（特に使わないのでNULLを指定）
	);
	//ウィンドウが作成できたかチェックする
	if (gameWindow == NULL) {
		return 0;
	}

	//作成したウィンドウを画面に表示する
	ShowWindow(gameWindow, nCmdShow);
	//ウィンドウ内の更新
	UpdateWindow(gameWindow);

	//ウィンドウのバックバッファ初期化
	Initialize(gameWindow);
	Keyboard_Initialize(hInstance, gameWindow);

	InitScene(SCENE_GAME1_1);

	//メッセージループ
	MSG msg = {};
	while (WM_QUIT != msg.message)
	{
		//Windowsからメッセージが来た場合はメッセージを処理する
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			//ゲームの処理をここに書いていく
			UpdateMain(gameWindow);

			DrawMain();


		}
	}

	//シーンの終了処理
	UninitScene();
	Keyboard_Finalize();
	UninitTexture();

	return (int)msg.wParam;
}

//windowのイベントを処理する関数
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN://キーが押されたメッセージ
		if (wParam == VK_ESCAPE)
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);//WM_CLOSEメッセージを自分に送る
		}
		break;

	case WM_LBUTTONUP:
		//マウス左ボタン離した
		return 0;


	case WM_CLOSE:// ウィンドウを閉じるメッセージ
		if (MessageBox(hWnd, "終了してよろしいですか？", "確認",
			MB_OKCANCEL | MB_DEFBUTTON2) == IDOK)
		{
			DestroyWindow(hWnd); //指定のウィンドウにWM_DESTROYを送る
		}
		return 0;

	case WM_DESTROY: //ウィンドウ破棄メッセージ
		PostQuitMessage(0); // WM_QUITメッセージを送る
		return 0;
	}

	//その他のメッセージはWindowsに任せる
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

	// 画面のクリア
	pDevice->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_RGBA(100, 80, 200, 255),
		1.0f,
		0);

	// 描画の開始
	pDevice->BeginScene();

	// ゲームの描画処理
	DrawScene();

	// 描画の終了
	pDevice->EndScene();

	// バックバッファをフリップ
	pDevice->Present(
		NULL,
		NULL,
		NULL,
		NULL
	);
}