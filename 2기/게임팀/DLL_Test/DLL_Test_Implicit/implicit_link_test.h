#pragma once

/** ��ó����(�Ʒ����� CREATEDLL_EXPORTS)�� ���� �Ǿ� �ִٸ� �Լ��� export��
* ���� �Ǿ� ���� �ʴٸ� import�� ����
*/
#ifdef CREATEDLL_EXPORTS
#define Dll_Test_DLL_DECLSPEC __declspec(dllexport)
#else
#define Dll_Test_DLL_DECLSPEC __declspec(dllimport)
#endif

#include <windows.h>
/**
* extern "C" --> c++���� �Լ��� �ۼ��� �߻��ϴ� ���� �ͱ۸�(�Լ��� �̸��� ������ �ٸ��� �����ϴ� �۾�)�� 
* �߻��� ����� ��ŷ�� �Ұ����ϹǷ� �߻����� �ʵ��� C�� ������ �ǵ��� �ϴ� �κ�
*/
extern "C"  Dll_Test_DLL_DECLSPEC  void draw_rac(HWND hWnd, LPARAM lParam);
